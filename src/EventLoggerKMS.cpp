/*******************************************************************************
 * File    : EventLoggerKMS.cpp
 * Purpose : KMS Communication Gateway — ELU Implementation
 *
 * ICD Reference: Section D — Key Management System (KMS) Communication; Port 4447
 *
 * RESPONSIBILITIES OF ELU (this file):
 *   1. Receive raw 0x90/0x92/0x94 KMS packets from VC via UDP port 4447.
 *   2. Forward them unchanged to KMS via GSM/GPRS modem.
 *   3. Receive 0x91/0x93/0x95 responses from KMS via GSM.
 *   4. Forward them unchanged to VC via UDP within 2000ms.
 *   5. Intercept OTP from SMS, build 0x96 packet, send to VC within 2000ms.
 *   6. Detect communication failures, build 0x97, send to VC.
 *   7. Perform up to 3 UDP/SMS-level retries (NOT protocol retries).
 *   8. Report signal quality, trigger channel changeover on failure (ICD §D.11).
 *
 * NOTE: The ELU does NOT parse or modify KMS payload content.
 *       All KMS protocol handling (session, retry at protocol level, validation)
 *       is entirely the Vital Controller's responsibility.
 *
 * Author  : SaNa Software
 * Date    : 2026
 ******************************************************************************/

#include "EventLoggerKMS.h"
#include <QDebug>
#include <QRegularExpression>
#include <QThread>

// ============================================================
//  Constructor / Destructor
// ============================================================

EventLoggerKMS::EventLoggerKMS(QObject *parent)
    : QObject(parent),
    m_pGSMSerial(nullptr),
    m_pCSQTimer(nullptr),
    m_ucKavachUnitType(KMS_UNIT_STATIONARY),
    m_bUsingChanA(true),
    m_vcLastPort(KMS_UDP_PORT),
    m_bInitDone(false)
{
    memset(m_ucKavachUnitID, 0, sizeof(m_ucKavachUnitID));

    // Default channel configs (overridden by Init())
    m_chanA.strLocalIP = "192.168.10.10";
    m_chanA.usPort     = KMS_UDP_PORT;
    m_chanA.ucSimID    = KMS_SIM_PRIMARY;
    m_chanA.bActive    = true;

    m_chanB.strLocalIP = "192.168.10.11";
    m_chanB.usPort     = KMS_UDP_PORT;
    m_chanB.ucSimID    = KMS_SIM_SECONDARY;
    m_chanB.bActive    = false;

    // Periodic CSQ poll every 30 seconds
    m_pCSQTimer = new QTimer(this);
    connect(m_pCSQTimer, &QTimer::timeout,
            this, &EventLoggerKMS::SlotPollCSQ);
}

EventLoggerKMS::~EventLoggerKMS()
{
    if (m_pCSQTimer) m_pCSQTimer->stop();
    if (m_pGSMSerial && m_pGSMSerial->isOpen())
        m_pGSMSerial->close();
}

// ============================================================
//  Init
// ============================================================

bool EventLoggerKMS::Init(const KMSChannelConfig &chanA,
                          const KMSChannelConfig &chanB,
                          const QString          &gsmPort,
                          qint32                  gsmBaud)
{
    m_chanA       = chanA;
    m_chanB       = chanB;
    m_bUsingChanA = true;

    // =========================================================
    // Create UDP socket to talk to KMS Server
    // =========================================================
    m_pKmsUdpSocket = new QUdpSocket(this);

    if (!m_pKmsUdpSocket->bind(
            QHostAddress::AnyIPv4,
            0,   // OS picks ephemeral port
            QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint))
    {
        qCritical() << "[KMS] UDP bind failed:"
                    << m_pKmsUdpSocket->errorString();
        return false;
    }

    qInfo() << "[KMS] UDP socket bound — port:"
            << m_pKmsUdpSocket->localPort();

    // =========================================================
    // Receive responses FROM KMS Server (0x91/0x93/0x95)
    // =========================================================
    connect(m_pKmsUdpSocket,
            &QUdpSocket::readyRead,
            this,
            [this]()
            {
                while (m_pKmsUdpSocket->hasPendingDatagrams())
                {
                    QByteArray data;
                    data.resize(static_cast<int>(
                        m_pKmsUdpSocket->pendingDatagramSize()));

                    QHostAddress sender;
                    quint16 senderPort = 0;

                    m_pKmsUdpSocket->readDatagram(
                        data.data(), data.size(),
                        &sender, &senderPort);

                    qDebug() << "\n================================";
                    qDebug() << "[KMS RX FROM KMS SERVER]";
                    qDebug() << "FROM  :" << sender.toString()
                             << ":" << senderPort;
                    qDebug() << "SIZE  :" << data.size();
                    qDebug() << "HEX   :" << data.toHex(' ').toUpper();
                    qDebug() << "================================";

                    if (data.size() < 3 ||
                        static_cast<uint8_t>(data[0]) != KMS_SOF1 ||
                        static_cast<uint8_t>(data[1]) != KMS_SOF2)
                    {
                        qWarning() << "[KMS] Bad SOF from KMS server — dropping";
                        continue;
                    }

                    quint8 msgType = static_cast<quint8>(data[2]);

                    qDebug() << "[KMS] MsgType from server:"
                             << Qt::hex << msgType;

                    switch (msgType)
                    {
                    case KMS_MSG_IDENTIFICATION_ACK:   // 0x91
                    {
                        qInfo() << "[KMS] 0x91 ACK received from KMS";

                        quint8 ackStatus = (data.size() >= 16)
                                               ? static_cast<quint8>(data[15])
                                               : 0;

                        qInfo() << "[KMS] Ack Status:"
                                << Qt::hex << ackStatus;

                        // Forward to VC first
                        ForwardToVC(data);

                        // Arm OTP polling only if KMS confirmed OTP sent
                        if (ackStatus == 0x01 && !m_bWaitingForOTP)
                        {
                            m_bWaitingForOTP = true;
                            m_otpWatchTimer.start();
                            m_pOTPPollTimer->start(2000);
                            qInfo() << "[KMS] OTP poll ARMED";
                        }
                        break;
                    }

                    case KMS_MSG_AUTH_KEY:          // 0x93
                    case KMS_MSG_AUTH_KEY_STATUS:   // 0x95
                        qInfo() << "[KMS] Forwarding"
                                << Qt::hex << msgType
                                << "to VC";
                        ForwardToVC(data);
                        break;

                    default:
                        qWarning() << "[KMS] Unknown MsgType from KMS server:"

                                   << Qt::hex << msgType;
                        break;
                    }
                }
            });

    // =========================================================
    // OTP Poll Timer
    // =========================================================
    m_pOTPPollTimer = new QTimer(this);
    connect(m_pOTPPollTimer, &QTimer::timeout,
            this, [this]()
            {
                if (!m_bWaitingForOTP)
                {
                    m_pOTPPollTimer->stop();
                    return;
                }

                if (m_otpWatchTimer.elapsed() > 60000)
                {
                    qWarning() << "[KMS] OTP timeout 60s";
                    m_bWaitingForOTP = false;
                    m_pOTPPollTimer->stop();
                    ReportFailureToVC(KMS_FAIL_SMS_OTP, 0);
                    return;
                }

                SlotReadLatestSMS();
            });

    // =========================================================
    // GSM Modem
    // =========================================================
    if (!InitGSMModem(gsmPort, gsmBaud))
    {
        qCritical() << "[KMS] GSM modem init failed";
        return false;
    }

    // =========================================================
    // CSQ Timer — start AFTER modem ready
    // =========================================================
    connect(m_pCSQTimer, &QTimer::timeout,
            this, &EventLoggerKMS::SlotPollCSQ,
            Qt::UniqueConnection);

    m_pCSQTimer->start(30000);

    m_bInitDone = true;

    qInfo() << "[KMS] Init complete — ELU-A:"
            << chanA.strLocalIP
            << "| KMS Server:"
            << chanA.strKMSServerIP
            << ":" << chanA.usKMSServerPort;

    return true;
}
// ============================================================
//  SlotReadLatestSMS
//
//  Called every 2s by m_pOTPPollTimer after 0x91 ACK.
//  Polls AT+CMGL="REC UNREAD" for fresh OTP SMS.
//  Disarms itself after first successful OTP extraction.
//  Reports failure to VC if 60s timeout exceeded.
//
//  ICD §D.8.3 — OTP received via SMS, build 0x96, send to VC.
// ============================================================

void EventLoggerKMS::SlotReadLatestSMS()
{
    // =========================================================
    // Guard: must be waiting for OTP
    // =========================================================
    if (!m_bWaitingForOTP)
    {
        m_pOTPPollTimer->stop();
        return;
    }

    // =========================================================
    // Guard: serial must be open
    // =========================================================
    if (!m_pGSMSerial || !m_pGSMSerial->isOpen())
    {
        qWarning() << "[KMS] SlotReadLatestSMS: GSM serial not open";
        return;
    }

    // =========================================================
    // Timeout guard — 60 seconds max wait for OTP SMS
    // =========================================================
    qint64 elapsed = m_otpWatchTimer.elapsed();

    qDebug() << "[KMS] SlotReadLatestSMS: elapsed="
             << elapsed << "ms";

    if (elapsed > 60000)
    {
        qWarning() << "[KMS] OTP wait TIMEOUT (60s) — giving up";

        // Disarm
        m_bWaitingForOTP = false;
        m_pOTPPollTimer->stop();

        // Report failure to VC
        ReportFailureToVC(KMS_FAIL_SMS_OTP, 0);
        return;
    }

    // =========================================================
    // Poll: AT+CMGL="REC UNREAD"
    // Only unread SMS — never reprocesses old ones
    // =========================================================
    qInfo() << "[KMS] Polling AT+CMGL=\"REC UNREAD\" for OTP SMS...";

    QString resp = SendATCommand("AT+CMGL=\"REC UNREAD\"", 5000);

    qDebug() << "[KMS] CMGL UNREAD response:" << resp;

    // =========================================================
    // No unread SMS yet — will retry on next timer tick
    // =========================================================
    if (!resp.contains("+CMGL:"))
    {
        qInfo() << "[KMS] No unread SMS yet"
                << "— retrying in 2s"
                << "| elapsed:" << elapsed << "ms";
        return;
    }

    // =========================================================
    // Parse all +CMGL entries
    // Keep the one with the HIGHEST index (most recent SMS)
    // =========================================================
    QStringList lines = resp.split('\n');

    QString latestBody;
    int     latestIdx = -1;

    for (int i = 0; i < lines.size(); i++)
    {
        QString line = lines[i].trimmed();

        if (!line.startsWith("+CMGL:"))
            continue;

        // ── Extract message index ──────────────────────────
        // Format: +CMGL: <idx>,"REC UNREAD","<sender>",,"<ts>"
        QRegularExpression idxRe("\\+CMGL:\\s*(\\d+)");
        QRegularExpressionMatch mIdx = idxRe.match(line);
        int idx = mIdx.hasMatch() ? mIdx.captured(1).toInt() : -1;

        qDebug() << "[KMS] CMGL entry idx=" << idx
                 << "line:" << line;

        // ── Next non-empty line = SMS body ─────────────────
        QString body;
        for (int j = i + 1; j < lines.size(); j++)
        {
            QString candidate = lines[j].trimmed();
            if (!candidate.isEmpty())
            {
                body = candidate;
                break;
            }
        }

        if (body.isEmpty())
        {
            qWarning() << "[KMS] CMGL idx=" << idx
                       << "has empty body — skipping";
            continue;
        }

        qDebug() << "[KMS] SMS body [" << idx << "]:" << body;

        // ── Only consider lines that contain OTP keyword ───
        if (!body.contains("OTP", Qt::CaseInsensitive))
        {
            qDebug() << "[KMS] Body has no OTP keyword — skipping";
            continue;
        }

        // ── Keep latest (highest index = most recent) ──────
        if (idx > latestIdx)
        {
            latestIdx  = idx;
            latestBody = body;
        }
    }

    // =========================================================
    // No OTP body found in unread SMS
    // =========================================================
    if (latestBody.isEmpty())
    {
        qWarning() << "[KMS] Unread SMS found but no OTP content"
                   << "— retrying in 2s";
        return;
    }

    // =========================================================
    // DISARM before processing — prevents double-fire
    // if ProcessOTPSms takes time or triggers another poll
    // =========================================================
    m_bWaitingForOTP = false;
    m_pOTPPollTimer->stop();

    qInfo() << "[KMS] OTP SMS found at index" << latestIdx
            << "| Body:" << latestBody;

    // =========================================================
    // Extract OTP and build 0x96 packet → forward to VC
    // =========================================================
    ProcessOTPSms(latestBody);

    // =========================================================
    // Delete ALL SMS after extraction — keep SIM storage clean
    // Prevents stale OTPs appearing in next session
    // AT+CMGD=1,4 — delete all messages (flag 4 = all types)
    // =========================================================
    QString delResp = SendATCommand("AT+CMGD=1,4", 2000);

    if (delResp.contains("OK"))
    {
        qInfo() << "[KMS] All SMS deleted after OTP extraction ✅";
    }
    else
    {
        qWarning() << "[KMS] SMS delete failed:" << delResp;
    }
}

// ============================================================
//  Set ELU Identity
// ============================================================

void EventLoggerKMS::SetKavachUnitInfo(quint8 ucUnitType, const quint8 ucUnitID[3])
{
    m_ucKavachUnitType = ucUnitType;
    memcpy(m_ucKavachUnitID, ucUnitID, 3);

    qDebug() << "[KMS] Unit info set: type ="
             << Qt::hex << ucUnitType
             << "ID =" << QByteArray(reinterpret_cast<const char*>(ucUnitID), 3).toHex().toUpper();
}

// ============================================================
//  Active Channel Helper
// ============================================================

KMSChannelConfig &EventLoggerKMS::ActiveChannel()
{
    return m_bUsingChanA ? m_chanA : m_chanB;
}

void EventLoggerKMS::SwitchChannel()
{
    m_bUsingChanA = !m_bUsingChanA;
    quint8 newSim = ActiveChannel().ucSimID;

    qWarning() << "[KMS] Channel changeover →"
               << (m_bUsingChanA ? "ELU-A (Primary)" : "ELU-B (Standby)")
               << "SIM:" << Qt::hex << newSim;

    emit SigChannelChangeover(newSim);
}

// ============================================================
//  GSM Modem Initialization
// ============================================================

bool EventLoggerKMS::InitGSMModem(const QString &portName,
                                  qint32 baudRate)
{
    m_pGSMSerial = new QSerialPort(this);

    m_pGSMSerial->setPortName(portName);
    m_pGSMSerial->setBaudRate(baudRate);
    m_pGSMSerial->setDataBits(QSerialPort::Data8);
    m_pGSMSerial->setParity(QSerialPort::NoParity);
    m_pGSMSerial->setStopBits(QSerialPort::OneStop);

    // IMPORTANT for Toradex UART
    m_pGSMSerial->setFlowControl(
        QSerialPort::NoFlowControl);

    if (!m_pGSMSerial->open(QIODevice::ReadWrite))
    {
        qCritical()
        << "[KMS] GSM open FAILED on"
        << portName
        << ":"
        << m_pGSMSerial->errorString();

        return false;
    }

    // Assert DTR / RTS
    m_pGSMSerial->setDataTerminalReady(true);
    m_pGSMSerial->setRequestToSend(true);

    QThread::msleep(300);

    qInfo()
        << "[KMS] GSM Port OPENED:"
        << portName
        << "@"
        << baudRate;

    qInfo()
        << "[KMS] DTR=HIGH RTS=HIGH";

    // ---------------------------------------------------
    // Connect readyRead AFTER open
    // ---------------------------------------------------
    connect(m_pGSMSerial,
            &QSerialPort::readyRead,
            this,
            &EventLoggerKMS::SlotHandleGSMData);

    // Stabilise modem
    QThread::msleep(1500);

    m_pGSMSerial->clear(
        QSerialPort::AllDirections);

    // ---------------------------------------------------
    // Wake modem
    // ---------------------------------------------------
    bool modemOK = false;

    for (int retry = 0;
         retry < 3;
         retry++)
    {
        QString resp =
            SendATCommand("AT", 3000);

        qDebug()
            << "[KMS] AT response:"
            << resp;

        if (resp.contains("OK"))
        {
            modemOK = true;
            break;
        }

        qWarning()
            << "[KMS] AT retry"
            << retry + 1
            << "failed";

        QThread::msleep(500);
    }

    if (!modemOK)
    {
        qCritical()
        << "[KMS] GSM NOT RESPONDING";

        m_pGSMSerial->close();
        return false;
    }

    // ---------------------------------------------------
    // Basic modem config
    // ---------------------------------------------------
    SendATCommand("ATE0", 2000);
    QThread::msleep(200);

    // SMS text mode
    QString cmgf =
        SendATCommand(
            "AT+CMGF=1",
            2000);

    if (!cmgf.contains("OK"))
    {
        qWarning()
        << "[KMS] Failed to enable SMS text mode";
    }

    QThread::msleep(200);

    // ---------------------------------------------------
    // SMS indication
    // ---------------------------------------------------
    QString cnmi =
        SendATCommand(
            "AT+CNMI=2,2,0,0,0",
            3000);

    if (!cnmi.contains("OK"))
    {
        qWarning()
        << "[KMS] CNMI 2,2 failed "
        << "trying fallback";

        cnmi =
            SendATCommand(
                "AT+CNMI=1,1,0,0,0",
                3000);

        if (!cnmi.contains("OK"))
        {
            qWarning()
            << "[KMS] CNMI setup FAILED ⚠";
        }
    }

    QThread::msleep(200);

    // ===================================================
    // IMPORTANT: Enable UDP unsolicited indication
    //
    // Enables:
    // +UUSORD: <socket>,<len>
    //
    // This tells us KMS reply arrived
    // ===================================================
    QString udconf =
        SendATCommand(
            "AT+UDCONF=1,1",
            3000);

    qInfo()
        << "[KMS] UDCONF:"
        << udconf;

    if (!udconf.contains("OK"))
    {
        qWarning()
        << "[KMS] UDCONF failed "
        << "(continuing anyway)";
    }

    QThread::msleep(200);

    // ===================================================
    // Setup PDP / GPRS
    // ===================================================
    qInfo()
        << "[KMS] Setting up PDP context...";

    QString cops =
        SendATCommand(
            "AT+COPS?",
            3000);

    qDebug()
        << "[KMS] Operator:"
        << cops;

    // ---------------------------------------------------
    // APN
    //
    // Jio      = jionet
    // Airtel   = airtelgprs.com
    // BSNL     = bsnlnet
    // Vodafone = www
    // ---------------------------------------------------
    QString apn = "jionet";

    QString cgdcont =
        SendATCommand(
            QString(
                "AT+CGDCONT=1,\"IP\",\"%1\"")
                .arg(apn),
            3000);

    if (!cgdcont.contains("OK"))
    {
        qWarning()
        << "[KMS] Failed to set APN:"
        << apn;
    }

    QThread::msleep(300);

    QString cgact =
        SendATCommand(
            "AT+CGACT=1,1",
            10000);

    if (cgact.contains("ERROR"))
    {
        qWarning()
        << "[KMS] PDP activation ERROR "
        << "(may already be active)";
    }
    else
    {
        qInfo()
        << "[KMS] PDP activation:"
        << cgact;
    }

    QThread::msleep(1000);

    QString verify =
        SendATCommand(
            "AT+CGACT?",
            3000);

    qInfo()
        << "[KMS] GPRS status:"
        << verify;

    if (!verify.contains("1,1"))
    {
        qWarning()
        << "[KMS] PDP Context NOT ACTIVE ⚠";
    }
    else
    {
        qInfo()
        << "[KMS] PDP Context ACTIVE ✅";
    }

    // ---------------------------------------------------
    // Delete stale SMS
    // ---------------------------------------------------
    QString del =
        SendATCommand(
            "AT+CMGD=1,4",
            3000);

    qInfo()
        << "[KMS] Startup SMS purge:"
        << (del.contains("OK")
                ? "OK ✅"
                : "FAILED ⚠");

    // ---------------------------------------------------
    // Final status
    // ---------------------------------------------------
    qInfo()
        << "\n===================================";

    qInfo()
        << "[KMS] GSM MODEM READY ✅";

    qInfo()
        << "[KMS] Port:"
        << portName;

    qInfo()
        << "[KMS] Baud:"
        << baudRate;

    qInfo()
        << "[KMS] APN:"
        << apn;

    qInfo()
        << "===================================\n";

    return true;
}

QString EventLoggerKMS::SendATCommand(const QString &cmd, int timeoutMs)
{
    // ============================================================
    // Validate GSM serial port
    // ============================================================
    if (!m_pGSMSerial)
    {
        qWarning() << "[KMS AT] Serial object is NULL";
        return QString();
    }

    if (!m_pGSMSerial->isOpen())
    {
        qWarning() << "[KMS AT] GSM Serial not open for cmd:"
                   << cmd;
        return QString();
    }

    // ============================================================
    // Debug: Print thread information
    // This is important for checking VC heartbeat blocking.
    // ============================================================
    qInfo() << "[KMS AT] Thread:"
            << QThread::currentThreadId();

    qInfo() << "[KMS AT] Command:"
            << cmd;

    // ============================================================
    // Disable asynchronous readyRead temporarily
    //
    // SlotHandleGSMData() must not read the same bytes while
    // this function is waiting synchronously for the response.
    // ============================================================
    disconnect(m_pGSMSerial,
               &QSerialPort::readyRead,
               this,
               &EventLoggerKMS::SlotHandleGSMData);

    // ============================================================
    // Make sure readyRead is restored when leaving this function
    // ============================================================
    auto reconnectReadyRead = [this]()
    {
        if (!m_pGSMSerial)
            return;

        connect(m_pGSMSerial,
                &QSerialPort::readyRead,
                this,
                &EventLoggerKMS::SlotHandleGSMData,
                Qt::UniqueConnection);
    };

    // ============================================================
    // Clear stale RX data
    // ============================================================
    m_pGSMSerial->readAll();

    // ============================================================
    // Assert DTR
    // ============================================================
    if (!m_pGSMSerial->setDataTerminalReady(true))
    {
        qWarning() << "[KMS AT] Failed to set DTR";
    }

    QThread::msleep(30);

    // ============================================================
    // Build AT command
    // ============================================================
    QByteArray cmdBytes = cmd.toUtf8();
    cmdBytes.append('\r');

    qDebug() << "[KMS AT TX]"
             << cmd;

    // ============================================================
    // Write command
    // ============================================================
    qint64 written = m_pGSMSerial->write(cmdBytes);

    if (written < 0)
    {
        qWarning() << "[KMS AT] Write failed:"
                   << m_pGSMSerial->errorString();

        reconnectReadyRead();
        return QString();
    }

    // ============================================================
    // Handle partial write
    // ============================================================
    if (written != cmdBytes.size())
    {
        qWarning() << "[KMS AT] Partial write:"
                   << written
                   << "/"
                   << cmdBytes.size();

        if (!m_pGSMSerial->waitForBytesWritten(500))
        {
            qWarning() << "[KMS AT] First write did not complete:"
                       << m_pGSMSerial->errorString();

            reconnectReadyRead();
            return QString();
        }

        qint64 remaining =
            m_pGSMSerial->write(
                cmdBytes.constData() + written,
                cmdBytes.size() - written);

        if (remaining <= 0)
        {
            qWarning() << "[KMS AT] Remaining write failed:"
                       << m_pGSMSerial->errorString();

            reconnectReadyRead();
            return QString();
        }
    }

    // ============================================================
    // Wait until command is written
    // ============================================================
    if (!m_pGSMSerial->waitForBytesWritten(500))
    {
        qWarning() << "[KMS AT] waitForBytesWritten failed:"
                   << m_pGSMSerial->errorString();

        reconnectReadyRead();
        return QString();
    }

    // ============================================================
    // Read modem response
    // ============================================================
    QByteArray response;

    QElapsedTimer timer;
    timer.start();

    while (timer.elapsed() < timeoutMs)
    {
        // --------------------------------------------------------
        // Wait for incoming modem data
        // --------------------------------------------------------
        if (m_pGSMSerial->waitForReadyRead(200))
        {
            QByteArray data =
                m_pGSMSerial->readAll();

            if (!data.isEmpty())
            {
                response.append(data);

                qDebug() << "[KMS AT RX CHUNK]"
                         << data.toHex(' ').toUpper();
            }

            // ----------------------------------------------------
            // Read any additional bytes already waiting
            // ----------------------------------------------------
            while (m_pGSMSerial->waitForReadyRead(50))
            {
                QByteArray moreData =
                    m_pGSMSerial->readAll();

                if (moreData.isEmpty())
                    break;

                response.append(moreData);

                qDebug() << "[KMS AT RX MORE]"
                         << moreData.toHex(' ').toUpper();
            }

            // ----------------------------------------------------
            // Normal AT command completion
            // ----------------------------------------------------
            if (response.contains("\r\nOK\r\n") ||
                response.contains("\nOK\n")     ||
                response.contains("ERROR")      ||
                response.contains(">"))
            {
                break;
            }
        }
    }

    // ============================================================
    // Convert response to QString
    // ============================================================
    QString result =
        QString::fromLatin1(response).trimmed();

    // ============================================================
    // Print final response
    // ============================================================
    qDebug() << "[KMS AT RX]"
             << result;

    // ============================================================
    // Timeout / empty response
    // ============================================================
    if (result.isEmpty())
    {
        qWarning() << "[KMS AT] No response for cmd:"
                   << cmd
                   << "timeout:"
                   << timeoutMs
                   << "ms";
    }

    // ============================================================
    // Restore asynchronous readyRead handler
    // ============================================================
    reconnectReadyRead();

    return result;
}


// ============================================================
//  CRC32 Utilities
// ============================================================

// Append CRC32 computed over data[crcStartOffset .. end] to data
void EventLoggerKMS::AppendCRC32(QByteArray &data, int crcStartOffset)
{
    if (crcStartOffset >= data.size()) return;

    const uint8_t *buf = reinterpret_cast<const uint8_t*>(data.constData())
                         + crcStartOffset;
    uint32_t len = static_cast<uint32_t>(data.size() - crcStartOffset);
    uint32_t crc = CalculateCRC32(len, buf);
    uint32_t crcBE = qToBigEndian(crc);
    data.append(reinterpret_cast<const char*>(&crcBE), 4);
}

// Static: validate CRC of a packet
// crcStartOffset: byte where CRC computation begins (after SOF)
bool EventLoggerKMS::ValidateCRC32(const QByteArray &packet, int crcStartOffset)
{
    // Need at least crcStartOffset bytes + 1 byte data + 4 bytes CRC
    if (packet.size() < crcStartOffset + 5) return false;

    int dataLen = packet.size() - crcStartOffset - 4;  // exclude CRC bytes at end
    if (dataLen <= 0) return false;

    const uint8_t *buf = reinterpret_cast<const uint8_t*>(packet.constData())
                         + crcStartOffset;
    uint32_t calcCRC   = CalculateCRC32(static_cast<uint32_t>(dataLen), buf);
    uint32_t calcCRCBE = qToBigEndian(calcCRC);

    const uint8_t *crcPtr = reinterpret_cast<const uint8_t*>(packet.constData())
                            + packet.size() - 4;
    uint32_t recvCRC = (static_cast<uint32_t>(crcPtr[0]) << 24) |
                       (static_cast<uint32_t>(crcPtr[1]) << 16) |
                       (static_cast<uint32_t>(crcPtr[2]) <<  8) |
                       static_cast<uint32_t>(crcPtr[3]);

    bool ok = (recvCRC == calcCRCBE);
    if (!ok)
        qWarning() << "[KMS] CRC mismatch recv=" << Qt::hex << recvCRC
                   << "calc=" << calcCRCBE;
    return ok;
}

quint32 EventLoggerKMS::ComputeCRC32(const QByteArray &data, int startOffset, int length)
{
    if (startOffset + length > data.size()) return 0;
    const uint8_t *buf = reinterpret_cast<const uint8_t*>(data.constData()) + startOffset;
    return CalculateCRC32(static_cast<uint32_t>(length), buf);
}

// ============================================================
//  KMS Packet Validation (SOF check only — CRC checked separately)
// ============================================================

bool EventLoggerKMS::IsValidKMSPacket(const QByteArray &packet)
{
    // Minimum: SOF(2) + MsgType(1) + MsgLen(2) + Date(3) + Time(3) + CRC(4) = 15
    if (packet.size() < 15) return false;

    if (static_cast<uint8_t>(packet[0]) != KMS_SOF1 ||
        static_cast<uint8_t>(packet[1]) != KMS_SOF2)
    {
        qWarning() << "[KMS] Bad SOF:" << packet.left(4).toHex().toUpper();
        return false;
    }

    // CRC validation: ICD specifies CRC from MsgType (index 2) to last field before CRC
    // CRC covers from byte[2] to byte[size-5]
    return ValidateCRC32(packet, 2);
}

quint8 EventLoggerKMS::GetKMSMsgType(const QByteArray &packet)
{
    if (packet.size() < 3) return 0x00;
    return static_cast<uint8_t>(packet[2]);
}

// ============================================================
//  SLOT: Inbound UDP from Vital Controller
//
//  ICD §D.1–D.4: VC sends raw 0x90/0x92/0x94 to ELU's UDP port 4447.
//  ELU must:
//    1. Validate packet (SOF + CRC).
//    2. Forward the raw packet unchanged to KMS via GSM/GPRS.
//    3. Perform up to 3 retries on write failure.
//    4. Record sender IP for reverse forwarding.
// ============================================================

void EventLoggerKMS::SlotHandleUDPFromVC(QByteArray    datagram,
                                         QHostAddress  senderIP,
                                         quint16       senderPort)
{
    // Remember VC address for sending packets back
    m_vcLastAddr = senderIP;
    m_vcLastPort = senderPort;

    qDebug() << "[KMS] UDP from VC:" << senderIP.toString()
             << "port:" << senderPort
             << "size:" << datagram.size()
             << "data:" << datagram.toHex().toUpper();

    // if (!IsValidKMSPacket(datagram))
    // {
    //     qWarning() << "[KMS] SlotHandleUDPFromVC: Invalid packet — dropping";
    //     return;
    // }

    quint8 msgType = GetKMSMsgType(datagram);

    switch (msgType)
    {
    case KMS_MSG_IDENTIFICATION:    // 0x90
    case KMS_MSG_AUTH_KEY_REQ:      // 0x92
    case KMS_MSG_AUTH_QUERY:        // 0x94
        emit SigKMSPacketReceived(msgType, datagram);
        ForwardToKMS(datagram, msgType);
        break;

    default:
        qWarning() << "[KMS] SlotHandleUDPFromVC: Unexpected MsgType from VC:"
                   << Qt::hex << msgType << "— dropping";
        break;
    }
}

// ============================================================
//  Forward Raw KMS Packet to KMS via GSM/GPRS
//
//  ICD §D.2: ELU shall transport packets transparently — NO modification.
//  ICD §D.10: ELU may retry up to 3 times at communication level.
// ============================================================
void EventLoggerKMS::ForwardToKMS(
    const QByteArray &rawPacket,
    quint8 msgType)
{
    if (!m_pGSMSerial || !m_pGSMSerial->isOpen())
    {
        qCritical() << "[KMS] GSM not open";
        ReportFailureToVC(KMS_FAIL_MODEM_GSM, 0);
        return;
    }

    QString kmsIP   = ActiveChannel().strKMSServerIP;
    quint16 kmsPort = ActiveChannel().usKMSServerPort;

    qInfo() << "\n================================";
    qInfo() << "[KMS FORWARD TO KMS SERVER]";
    qInfo() << "MSG TYPE :" << Qt::hex << msgType;
    qInfo() << "DEST IP  :" << kmsIP;
    qInfo() << "DEST PORT:" << kmsPort;
    qInfo() << "SIZE     :" << rawPacket.size();
    qInfo() << "HEX      :" << rawPacket.toHex(' ').toUpper();
    qInfo() << "================================";

    // ── Ensure GPRS active ────────────────────────────────────
    if (!EnsureGPRSActive())
    {
        qCritical() << "[KMS] GPRS unavailable";
        ReportFailureToVC(KMS_FAIL_GPRS_NETWORK, 0);
        return;
    }

    // ── Create UDP socket ─────────────────────────────────────
    QString usocrResp = SendATCommand("AT+USOCR=17", 5000);
    qDebug() << "[KMS] USOCR:" << usocrResp;

    QRegularExpression reSocket(R"(\+USOCR:\s*(\d+))");
    QRegularExpressionMatch socketMatch = reSocket.match(usocrResp);

    if (!socketMatch.hasMatch())
    {
        qCritical() << "[KMS] Socket create FAILED:" << usocrResp;
        ReportFailureToVC(KMS_FAIL_GPRS_NETWORK, 0);
        return;
    }

    int socketHandle = socketMatch.captured(1).toInt();
    qInfo() << "[KMS] Socket handle:" << socketHandle;

    // ── Send UDP packet via AT+USOST ──────────────────────────
    QString hexData = QString::fromLatin1(rawPacket.toHex()).toUpper();
    QString sendCmd = QString("AT+USOST=%1,\"%2\",%3,%4,\"%5\"")
                          .arg(socketHandle)
                          .arg(kmsIP)
                          .arg(kmsPort)
                          .arg(rawPacket.size())
                          .arg(hexData);

    qDebug() << "[KMS] USOST cmd:" << sendCmd;
    QString sendResp = SendATCommand(sendCmd, 10000);
    qDebug() << "[KMS] USOST resp:" << sendResp;

    if (!sendResp.contains("+USOST"))
    {
        qCritical() << "[KMS] UDP send failed:" << sendResp;
        ReportFailureToVC(KMS_FAIL_GPRS_NETWORK, 0);
        SendATCommand(QString("AT+USOCL=%1").arg(socketHandle), 3000);
        return;
    }

    qInfo() << "[KMS] UDP packet transmitted ✅";

    // ── Phase 1: Wait for 0x91/0x93/0x95 via UDP ─────────────
    // ── Phase 2: If 0x91 with OTP flag, wait for OTP SMS ─────
    // Socket stays open through BOTH phases

    QElapsedTimer timer;
    timer.start();

    bool gotUDPReply  = false;   // 0x91/0x93/0x95 received
    bool otpExpected  = false;   // KMS confirmed OTP will come via SMS
    bool gotOTP       = false;   // OTP SMS received and processed

    QElapsedTimer otpTimer;

    // Phase 1 timeout: 120s for UDP reply
    // Phase 2 timeout: 60s for OTP SMS after 0x91
    const int PHASE1_TIMEOUT_MS = 120000;
    const int PHASE2_TIMEOUT_MS = 60000;

    while (true)
    {
        // ── Timeout checks ────────────────────────────────────
        if (!gotUDPReply && timer.elapsed() > PHASE1_TIMEOUT_MS)
        {
            qWarning() << "[KMS] Phase1: No UDP reply in 120s";
            ReportFailureToVC(KMS_FAIL_NO_KMS_RESPONSE, 0);
            break;
        }

        if (gotUDPReply && otpExpected && !gotOTP
            && otpTimer.elapsed() > PHASE2_TIMEOUT_MS)
        {
            qWarning() << "[KMS] Phase2: OTP SMS not received in 60s";
            ReportFailureToVC(KMS_FAIL_SMS_OTP, 0);
            break;
        }

        // ── If we got reply and OTP not expected — done ───────
        if (gotUDPReply && !otpExpected)
            break;

        // ── If we got reply and OTP received — done ───────────
        if (gotUDPReply && otpExpected && gotOTP)
            break;

        QThread::msleep(500);

        // ═════════════════════════════════════════════════════
        // PHASE 1: Poll UDP socket for KMS response (0x91/0x93/0x95)
        // Only poll until we have the UDP reply
        // ═════════════════════════════════════════════════════
        if (!gotUDPReply)
        {
            QString pollResp = SendATCommand(
                QString("AT+USORF=%1,1024").arg(socketHandle), 3000);
            qDebug() << "[KMS] USORF:" << pollResp;

            QRegularExpression reData(
                "\\+USORF:\\s*(\\d+),\"([^\"]+)\",(\\d+),(\\d+),\"([0-9A-Fa-f]+)\"");
            QRegularExpressionMatch match = reData.match(pollResp);

            if (match.hasMatch())
            {
                int rxLen = match.captured(4).toInt();
                if (rxLen > 0)
                {
                    QByteArray response =
                        QByteArray::fromHex(match.captured(5).toLatin1());

                    qInfo() << "[KMS] UDP RX:" << response.toHex(' ').toUpper();

                    if (response.size() >= 3)
                    {
                        quint8 respType = static_cast<quint8>(response[2]);
                        qInfo() << "[KMS] Response MsgType:" << Qt::hex << respType;

                        switch (respType)
                        {
                        case KMS_MSG_IDENTIFICATION_ACK:   // 0x91
                        {
                            qInfo() << "[KMS] 0x91 ACK received ✅";

                            // Forward to VC immediately
                            ForwardToVC(response);
                            emit SigKMSPacketReceived(respType, response);
                            gotUDPReply = true;

                            // Check if KMS confirmed OTP will be sent via SMS
                            // ICD §D.8.3: byte[15] = 0x01 means OTP is being sent
                            quint8 ackStatus = (response.size() >= 16)
                                                   ? static_cast<quint8>(response[15])
                                                   : 0x00;

                            qInfo() << "[KMS] 0x91 AckStatus:" << Qt::hex << ackStatus;

                            if (ackStatus == 0x01)
                            {
                                // OTP will arrive via SMS — enter Phase 2
                                otpExpected = true;
                                otpTimer.start();
                                qInfo() << "[KMS] OTP expected via SMS — entering Phase 2 (60s wait)";
                            }
                            else
                            {
                                // No OTP expected — session complete
                                otpExpected = false;
                                qInfo() << "[KMS] No OTP expected — session complete";
                            }
                            break;
                        }

                        case KMS_MSG_AUTH_KEY:           // 0x93
                        case KMS_MSG_AUTH_KEY_STATUS:    // 0x95
                        {
                            qInfo() << "[KMS] Forwarding"
                                    << Qt::hex << respType << "to VC ✅";
                            ForwardToVC(response);
                            emit SigKMSPacketReceived(respType, response);
                            gotUDPReply = true;
                            otpExpected = false;  // 0x93/0x95 never have OTP
                            break;
                        }

                        default:
                        {
                            qWarning() << "[KMS] Unknown MsgType from KMS:"
                                       << Qt::hex << respType;
                            break;
                        }
                        }
                    }
                }
            }
        }

        // ═════════════════════════════════════════════════════
        // PHASE 2: Poll for OTP SMS
        // Runs AFTER 0x91 received, while socket is still open
        // Two methods: AT+CMGL (poll) + AT+USOER (+CMTI detection)
        // ═════════════════════════════════════════════════════
        if (gotUDPReply && otpExpected && !gotOTP)
        {
            qDebug() << "[KMS] Phase2: polling for OTP SMS"
                     << "| elapsed:" << otpTimer.elapsed() << "ms";

            // ── Method 1: Check for +CMTI via AT+USOER ───────
            // AT+USOER can surface unsolicited +CMTI indications
            // that arrived while we were in blocking AT mode
            QString usoerResp = SendATCommand("AT+USOER", 2000);
            qDebug() << "[KMS] USOER:" << usoerResp;

            if (usoerResp.contains("+CMTI"))
            {
                qInfo() << "[KMS] +CMTI detected in USOER response";

                QRegularExpression reCmti(R"(\+CMTI:\s*"[^"]+",(\d+))");
                QRegularExpressionMatch cmtiMatch = reCmti.match(usoerResp);

                if (cmtiMatch.hasMatch())
                {
                    int smsIndex = cmtiMatch.captured(1).toInt();
                    qInfo() << "[KMS] Reading SMS at index:" << smsIndex;

                    QString smsResp = SendATCommand(
                        QString("AT+CMGR=%1").arg(smsIndex), 5000);
                    qInfo() << "[KMS] SMS RAW:" << smsResp;

                    // Extract SMS body from AT+CMGR response
                    // Format:
                    // +CMGR: "REC READ","<sender>",,"<timestamp>"
                    // <SMS body text>
                    // OK
                    QString smsBody;
                    QStringList cmgrLines = smsResp.split('\n', Qt::SkipEmptyParts);
                    for (int i = 0; i < cmgrLines.size(); i++)
                    {
                        QString line = cmgrLines[i].trimmed();
                        if (line.startsWith("+CMGR"))
                            continue;
                        if (line == "OK" || line.isEmpty())
                            continue;
                        smsBody = line;
                        break;
                    }

                    if (!smsBody.isEmpty())
                    {
                        qInfo() << "[KMS] SMS body from CMGR:" << smsBody;
                        ProcessOTPSms(smsBody);
                        gotOTP = true;
                    }
                    else
                    {
                        qWarning() << "[KMS] CMGR body empty — will retry via CMGL";
                    }

                    // Delete SMS after reading
                    QString delResp = SendATCommand(
                        QString("AT+CMGD=%1").arg(smsIndex), 3000);
                    qInfo() << "[KMS] SMS deleted (CMGR path):" << delResp;
                }
            }

            // ── Method 2: Poll AT+CMGL="REC UNREAD" ──────────
            // Direct poll — doesn't rely on +CMTI being surfaced
            // Runs every iteration regardless of Method 1 result
            if (!gotOTP)
            {
                QString cmglResp = SendATCommand(
                    "AT+CMGL=\"REC UNREAD\"", 5000);
                qDebug() << "[KMS] CMGL UNREAD:" << cmglResp;

                if (cmglResp.contains("+CMGL:"))
                {
                    // Find the SMS entry with highest index (most recent)
                    QStringList lines = cmglResp.split('\n', Qt::SkipEmptyParts);
                    QString latestBody;
                    int     latestIdx = -1;

                    for (int i = 0; i < lines.size(); i++)
                    {
                        QString line = lines[i].trimmed();
                        if (!line.startsWith("+CMGL:"))
                            continue;

                        // Extract index from +CMGL: <idx>,...
                        QRegularExpression idxRe(R"(\+CMGL:\s*(\d+))");
                        QRegularExpressionMatch idxMatch = idxRe.match(line);
                        int idx = idxMatch.hasMatch()
                                      ? idxMatch.captured(1).toInt()
                                      : -1;

                        // Next non-empty line = SMS body
                        QString body;
                        for (int j = i + 1; j < lines.size(); j++)
                        {
                            QString candidate = lines[j].trimmed();
                            if (candidate.isEmpty() || candidate == "OK")
                                continue;
                            body = candidate;
                            break;
                        }

                        qDebug() << "[KMS] CMGL entry idx=" << idx
                                 << "body:" << body;

                        if (body.isEmpty())
                            continue;

                        // Must contain OTP keyword
                        if (!body.contains("OTP", Qt::CaseInsensitive))
                        {
                            qDebug() << "[KMS] CMGL body has no OTP keyword — skip";
                            continue;
                        }

                        if (idx > latestIdx)
                        {
                            latestIdx  = idx;
                            latestBody = body;
                        }
                    }

                    if (!latestBody.isEmpty())
                    {
                        qInfo() << "[KMS] OTP SMS found via CMGL idx="
                                << latestIdx
                                << "body:" << latestBody;

                        // ── Process OTP — full flow ───────────
                        ProcessOTPSms(latestBody);
                        gotOTP = true;

                        // Delete ALL SMS after extraction
                        QString delResp = SendATCommand("AT+CMGD=1,4", 3000);
                        qInfo() << "[KMS] All SMS deleted (CMGL path):"
                                << (delResp.contains("OK") ? "OK ✅" : "FAILED ⚠");
                    }
                    else
                    {
                        qDebug() << "[KMS] CMGL: unread SMS found but no OTP content yet"
                                 << "— will retry";
                    }
                }
                else
                {
                    qDebug() << "[KMS] CMGL: no unread SMS yet"
                             << "| OTP wait elapsed:" << otpTimer.elapsed() << "ms";
                }
            }
        }

    } // end while(true)

    // ── Close socket — only reaches here after both phases done ─
    QString closeResp = SendATCommand(
        QString("AT+USOCL=%1").arg(socketHandle), 3000);
    qInfo() << "[KMS] Socket closed:" << closeResp;

    // ── Final status log ──────────────────────────────────────
    qInfo() << "[KMS] ForwardToKMS complete:"
            << "UDP reply=" << gotUDPReply
            << "OTP expected=" << otpExpected
            << "OTP received=" << gotOTP;

    emit SigKMSPacketSent(msgType, rawPacket);
}

bool EventLoggerKMS::SendUDPViaGSM(const QByteArray &rawPacket, const QString &destIP, quint16 destPort)
{
    if (!m_pGSMSerial || !m_pGSMSerial->isOpen())
    {
        qCritical() << "[GSM UDP] GSM serial not open";
        return false;
    }

    if (!EnsureGPRSActive())
    {
        qCritical() << "[GSM UDP] GPRS unavailable";
        return false;
    }

    // Create UDP socket
    QString usocrResp = SendATCommand("AT+USOCR=17", 5000);

    QRegularExpression reSocket(R"(\+USOCR:\s*(\d+))");
    QRegularExpressionMatch socketMatch =
        reSocket.match(usocrResp);

    if (!socketMatch.hasMatch())
    {
        qCritical() << "[GSM UDP] Socket create FAILED:"
                    << usocrResp;
        return false;
    }

    int socketHandle = socketMatch.captured(1).toInt();

    QString hexData =
        QString::fromLatin1(rawPacket.toHex()).toUpper();

    QString sendCmd =
        QString("AT+USOST=%1,\"%2\",%3,%4,\"%5\"")
            .arg(socketHandle)
            .arg(destIP)
            .arg(destPort)
            .arg(rawPacket.size())
            .arg(hexData);

    qInfo() << "[GSM UDP] Sending:"
            << rawPacket.size()
            << "bytes to"
            << destIP << ":" << destPort;

    qDebug() << "[GSM UDP] USOST:"
             << sendCmd;

    QString sendResp =
        SendATCommand(sendCmd, 10000);

    qDebug() << "[GSM UDP] USOST response:"
             << sendResp;

    bool success = sendResp.contains("+USOST");

    if (success)
    {
        qInfo() << "[GSM UDP] Packet transmitted ✅";
    }
    else
    {
        qCritical() << "[GSM UDP] Packet transmission FAILED";
    }

    // Close socket
    SendATCommand(
        QString("AT+USOCL=%1").arg(socketHandle),
        3000);

    return success;
}

// ============================================================
//  Forward Raw KMS Packet from KMS to VC via UDP
//
//  ICD §D.9: ELU shall forward within 2000ms of reception.
//  ICD §D.2: Payload transported transparently — NO modification.
// ============================================================

void EventLoggerKMS::ForwardToVC(const QByteArray &rawPacket)
{
    quint8 msgType = GetKMSMsgType(rawPacket);

    qInfo() << "[KMS] → VC MsgType:" << Qt::hex << msgType
            << "size:" << rawPacket.size();

    emit SigSendToVC(rawPacket, m_vcLastAddr, m_vcLastPort);
    emit SigKMSPacketSent(msgType, rawPacket);
}

// ============================================================
//  SLOT: GSM Serial Data Received
//
//  TWO cases per ICD:
//  Case A: Raw KMS GPRS packet (0x91/0x93/0x95)
//    → Validate → forward unchanged to VC within 2000ms
//
//  Case B: OTP received via SMS (+CMT unsolicited notification)
//    → Extract OTP → Build 0x96 → Send to VC within 2000ms
// ============================================================

void EventLoggerKMS::SlotHandleGSMData()
{
    if (!m_pGSMSerial)
        return;

    QByteArray rx =
        m_pGSMSerial->readAll();

    if (rx.isEmpty())
        return;

    qDebug()
        << "[KMS RAW RX]"
        << rx;

    m_gsmBuffer.append(rx);

    // =====================================================
    // CASE A : KMS Binary Packet
    // =====================================================
    while (m_gsmBuffer.size() >= 7)
    {
        int sofIdx = -1;

        for (int i = 0;
             i < m_gsmBuffer.size() - 1;
             i++)
        {
            if (static_cast<uint8_t>(
                    m_gsmBuffer[i])
                    == KMS_SOF1 &&
                static_cast<uint8_t>(
                    m_gsmBuffer[i + 1])
                    == KMS_SOF2)
            {
                sofIdx = i;
                break;
            }
        }

        if (sofIdx < 0)
            break;

        if (sofIdx > 0)
        {
            qDebug()
            << "[KMS] Discarding"
            << sofIdx
            << "bytes before SOF";

            m_gsmBuffer.remove(
                0,
                sofIdx);
        }

        if (m_gsmBuffer.size() < 5)
            break;

        quint16 msgLen =
            (static_cast<quint16>(
                 static_cast<uint8_t>(
                     m_gsmBuffer[3]))
             << 8)
            |
            static_cast<quint16>(
                static_cast<uint8_t>(
                    m_gsmBuffer[4]));

        int totalLen =
            2 + 1 + 2 + msgLen;

        if (m_gsmBuffer.size() <
            totalLen)
        {
            break;
        }

        QByteArray packet =
            m_gsmBuffer.left(
                totalLen);

        m_gsmBuffer.remove(
            0,
            totalLen);

        quint8 msgType =
            GetKMSMsgType(packet);

        switch (msgType)
        {
        case KMS_MSG_IDENTIFICATION_ACK:
        case KMS_MSG_AUTH_KEY:
        case KMS_MSG_AUTH_KEY_STATUS:
        {
            qInfo()
            << "[KMS] ← KMS MsgType:"
            << Qt::hex
            << msgType
            << "size:"
            << packet.size();

            emit SigKMSPacketReceived(msgType,packet);

            ForwardToVC(packet);

            // Start OTP wait on 0x91 ACK
            if (msgType ==
                KMS_MSG_IDENTIFICATION_ACK)
            {
                qInfo()
                << "[KMS] Waiting for OTP SMS...";

                m_bWaitingForOTP = true;

                m_otpWatchTimer.start();

                if (m_pOTPPollTimer)
                {
                    m_pOTPPollTimer
                        ->start(2000);
                }
            }

            break;
        }

        default:
        {
            qWarning()
            << "[KMS] Unknown MsgType:"
            << Qt::hex
            << msgType;

            break;
        }
        }
    }

    // =====================================================
    // CASE B : SMS INDICATION (+CMTI)
    // Example:
    // +CMTI: "ME",0
    // =====================================================
    while (true)
    {
        QString bufferStr =
            QString::fromLatin1(
                m_gsmBuffer);

        QRegularExpression reCmti(
            R"(\+CMTI:\s*"[^"]+",(\d+))");

        auto match =
            reCmti.match(
                bufferStr);

        if (!match.hasMatch())
            break;

        int smsIndex =
            match.captured(1)
                .toInt();

        qInfo()
            << "[KMS] SMS indication index:"
            << smsIndex;

        // Remove processed indication
        int removePos =
            bufferStr.indexOf(
                "+CMTI:");

        int endLine =
            bufferStr.indexOf(
                '\n',
                removePos);

        if (removePos >= 0 &&
            endLine > removePos)
        {
            m_gsmBuffer.remove(
                removePos,
                endLine -
                    removePos + 1);
        }

        // ====================================
        // Read SMS
        // ====================================
        QString cmgrResp =
            SendATCommand(
                QString(
                    "AT+CMGR=%1")
                    .arg(smsIndex),
                5000);

        qDebug()
            << "[KMS] CMGR Response:"
            << cmgrResp;

        QStringList lines =
            cmgrResp.split(
                '\n',
                Qt::SkipEmptyParts);

        QString smsText;

        for (const QString &line
             : lines)
        {
            QString t =
                line.trimmed();

            if (t.startsWith(
                    "+CMGR"))
            {
                continue;
            }

            if (t == "OK")
                continue;

            if (t.isEmpty())
                continue;

            smsText = t;
            break;
        }

        if (!smsText.isEmpty())
        {
            qInfo()
            << "[KMS] SMS Text:"
            << smsText;

            ProcessOTPSms(
                smsText);
        }
        else
        {
            qWarning()
            << "[KMS] SMS body empty";
        }

        // ====================================
        // Delete SMS
        // ====================================
        QString delResp =
            SendATCommand(
                QString(
                    "AT+CMGD=%1")
                    .arg(smsIndex),
                3000);

        qInfo()
            << "[KMS] SMS delete:"
            << delResp;
    }
}

// ============================================================
//  Process OTP from SMS
//
//  ICD §D.8.3 — 0x96 OTP Message:
//    ELU builds this from the SMS content and sends to VC.
// ============================================================

void EventLoggerKMS::ProcessOTPSms(
    const QString &smsText)
{
    qInfo()
    << "\n================================";
    qInfo()
        << "[KMS] PROCESS OTP SMS";
    qInfo()
        << "RAW SMS:"
        << smsText;
    qInfo()
        << "================================";

    QString otp;
    quint8 simID =
        KMS_SIM_PRIMARY;

    // ---------------------------------------
    // Extract OTP from SMS
    // ---------------------------------------
    bool ok =
        ExtractOTPFromSMS(
            smsText,
            otp,
            simID);

    if (!ok)
    {
        qWarning()
        << "[KMS] OTP extraction FAILED";

        qWarning()
            << "[KMS] SMS Content:"
            << smsText;

        ReportFailureToVC(
            KMS_FAIL_SMS_OTP,
            0);

        return;
    }

    otp = otp.trimmed();

    qInfo()
        << "[KMS] OTP extracted:"
        << otp;

    qInfo()
        << "[KMS] SIM ID:"
        << Qt::hex
        << simID;

    // ---------------------------------------
    // Build OTP packet (0x96)
    // ---------------------------------------
    QByteArray otpPacket =
        BuildOTPPacket(
            m_ucKavachUnitType,
            m_ucKavachUnitID,
            simID,
            otp);

    qInfo()
        << "[KMS] OTP Packet:"
        << otpPacket
               .toHex(' ')
               .toUpper();

    // ---------------------------------------
    // Send OTP to VC immediately
    // (< 2000ms requirement)
    // ---------------------------------------
    ForwardToVC(otpPacket);

    qInfo()
        << "[KMS] OTP → VC sent ✅";

    // ---------------------------------------
    // Stop OTP wait state
    // ---------------------------------------
    m_bWaitingForOTP =
        false;

    if (m_pOTPPollTimer)
    {
        m_pOTPPollTimer->stop();
    }

    qInfo()
        << "[KMS] OTP polling stopped";

    qInfo()
        << "================================\n";
}

// ============================================================
//  Build 0x96 OTP Packet
//
//  ICD §D.8.3 — 0x96 OTP Received:
//  Field          Bytes   Notes
//  ─────────────────────────────────────────────────────────
//  Start of Frame    2    0xA5, 0xC3
//  Message Type      1    0x96
//  Message Length    2    Bytes from Date to CRC (inclusive)
//  Date              3    YY/MM/DD in Hex (IST)
//  Time              3    HH/MM/SS in Hex (IST)
//  Type of KAVACH    1    0x11/0x22/0x33
//  KAVACH Unit ID    3    Unit ID in Hex
//  SIM ID            1    0x01/0x02
//  OTP               4    4-char alphanumeric
//  CRC-32            4    From Message Type to OTP (SOF excluded)
// ============================================================

QByteArray EventLoggerKMS::BuildOTPPacket(quint8        ucKavachUnitType,
                                          const quint8  ucKavachUnitID[3],
                                          quint8        ucSIMID,
                                          const QString &strOTP)
{
    QByteArray pkt;

    // SOF — NOT included in CRC
    pkt.append(static_cast<char>(KMS_SOF1));
    pkt.append(static_cast<char>(KMS_SOF2));

    int crcStart = pkt.size();  // CRC covers from here

    // Message Type
    pkt.append(static_cast<char>(KMS_MSG_OTP));  // 0x96

    // Message Length: Date(3)+Time(3)+UnitType(1)+UnitID(3)+SIM(1)+OTP(4)+CRC(4) = 19
    quint16 msgLen   = 19;
    quint16 msgLenBE = qToBigEndian(msgLen);
    pkt.append(reinterpret_cast<const char*>(&msgLenBE), 2);

    // Date: YY/MM/DD in Hex (IST) — per ICD §D.8.3
    QDateTime now = QDateTime::currentDateTime();
    pkt.append(static_cast<char>(now.date().year() % 100));
    pkt.append(static_cast<char>(now.date().month()));
    pkt.append(static_cast<char>(now.date().day()));

    // Time: HH/MM/SS in Hex (IST)
    pkt.append(static_cast<char>(now.time().hour()));
    pkt.append(static_cast<char>(now.time().minute()));
    pkt.append(static_cast<char>(now.time().second()));

    // KAVACH Unit Type
    pkt.append(static_cast<char>(ucKavachUnitType));

    // KAVACH Unit ID (3 bytes)
    pkt.append(reinterpret_cast<const char*>(ucKavachUnitID), 3);

    // SIM ID
    pkt.append(static_cast<char>(ucSIMID));

    // OTP — 4 bytes, alphanumeric, pad with 0x00 if shorter
    QByteArray otpBytes = strOTP.toLatin1().left(4);
    while (otpBytes.size() < 4)
        otpBytes.append('\0');
    pkt.append(otpBytes);

    // CRC32 from MsgType (index crcStart) to end of OTP
    AppendCRC32(pkt, crcStart);

    qDebug() << "[KMS] Built 0x96 OTP packet:" << pkt.toHex().toUpper();
    return pkt;
}

// ============================================================
//  Build 0x97 KMS Communication Failure Packet
//
//  ICD §D.8.8 — 0x97 KMS Communication Failure:
//  Field              Bytes   Notes
//  ────────────────────────────────────────────────────────
//  Start of Frame        2    0xA5, 0xC3
//  Message Type          1    0x97
//  Message Length        2    Bytes from Date to CRC inclusive
//  Date                  3    YY/MM/DD in Hex (IST)
//  Time                  3    HH/MM/SS in Hex (IST)
//  Type of KAVACH Unit   1    0x11/0x22/0x33
//  KAVACH Unit ID        3    ID in Hex
//  SIM ID                1    0x01/0x02
//  Failure Reason Code   1    See ICD §D.8.8
//  Retry Count           1    Number of ELU retry attempts (0–3)
//  CRC-32                4    From MsgType to Retry Count (SOF excluded)
// ============================================================

QByteArray EventLoggerKMS::BuildCommFailurePacket(quint8        ucKavachUnitType,
                                                  const quint8  ucKavachUnitID[3],
                                                  quint8        ucSIMID,
                                                  quint8        ucFailureCode,
                                                  quint8        ucRetryCount)
{
    QByteArray pkt;

    // SOF — NOT in CRC
    pkt.append(static_cast<char>(KMS_SOF1));
    pkt.append(static_cast<char>(KMS_SOF2));

    int crcStart = pkt.size();

    // Message Type
    pkt.append(static_cast<char>(KMS_MSG_COMM_FAILURE));  // 0x97

    // Message Length: Date(3)+Time(3)+UnitType(1)+UnitID(3)+SIM(1)+FailCode(1)+Retry(1)+CRC(4) = 17
    quint16 msgLen   = 17;
    quint16 msgLenBE = qToBigEndian(msgLen);
    pkt.append(reinterpret_cast<const char*>(&msgLenBE), 2);

    QDateTime now = QDateTime::currentDateTime();
    pkt.append(static_cast<char>(now.date().year() % 100));
    pkt.append(static_cast<char>(now.date().month()));
    pkt.append(static_cast<char>(now.date().day()));
    pkt.append(static_cast<char>(now.time().hour()));
    pkt.append(static_cast<char>(now.time().minute()));
    pkt.append(static_cast<char>(now.time().second()));

    pkt.append(static_cast<char>(ucKavachUnitType));
    pkt.append(reinterpret_cast<const char*>(ucKavachUnitID), 3);
    pkt.append(static_cast<char>(ucSIMID));
    pkt.append(static_cast<char>(ucFailureCode));
    pkt.append(static_cast<char>(ucRetryCount));

    AppendCRC32(pkt, crcStart);

    qDebug() << "[KMS] Built 0x97 failure packet: code ="
             << Qt::hex << ucFailureCode
             << "retries =" << ucRetryCount
             << pkt.toHex().toUpper();
    return pkt;
}

// ============================================================
//  Report Failure to VC
//
//  Internal helper: builds 0x97 and sends to VC.
//  Also checks if channel changeover is needed (ICD §D.11).
// ============================================================

void EventLoggerKMS::ReportFailureToVC(quint8 failureCode, quint8 retryCount)
{
    quint8 simID = ActiveChannel().ucSimID;

    QByteArray failPacket = BuildCommFailurePacket(m_ucKavachUnitType,
                                                   m_ucKavachUnitID,
                                                   simID,
                                                   failureCode,
                                                   retryCount);
    ForwardToVC(failPacket);

    // ICD §D.11: On communication failure, VC initiates channel changeover.
    // ELU triggers the switch so the standby channel becomes active for
    // subsequent transmissions — VC decides based on 0x97 it receives.
    if (failureCode == KMS_FAIL_MODEM_GSM       ||
        failureCode == KMS_FAIL_SIM_REG          ||
        failureCode == KMS_FAIL_SIGNAL_THRESHOLD  ||
        failureCode == KMS_FAIL_GPRS_NETWORK      ||
        failureCode == KMS_FAIL_NO_KMS_RESPONSE)
    {
        SwitchChannel();
    }
}

// ============================================================
//  Extract OTP from SMS Text
//
//  ICD §D.8.3: OTP is 4-character alphanumeric, received via SMS.
//  SIM is inferred from SMS content (SIM2/secondary keyword).
// ============================================================

bool EventLoggerKMS::ExtractOTPFromSMS(const QString &smsText,
                                       QString        &otpOut,
                                       quint8         &simIDOut)
{
    // Pattern 1: "S50046:Hume" — colon + 4 alphanum (case preserved)
    QRegularExpression otpRe(
        "[A-Z0-9]+:([A-Za-z0-9]{4})(?:\\s|$)",
        QRegularExpression::CaseInsensitiveOption);

    QRegularExpressionMatch match = otpRe.match(smsText);

    if (!match.hasMatch())
    {
        // Fallback: "OTP: XXXX"
        QRegularExpression fallbackRe(
            "OTP\\s*[:=]\\s*([A-Za-z0-9]{4})",
            QRegularExpression::CaseInsensitiveOption);
        match = fallbackRe.match(smsText);

        if (!match.hasMatch())
        {
            qWarning() << "[KMS] OTP not found in SMS:" << smsText;
            return false;
        }
    }

    otpOut = match.captured(1);  // original case preserved

    QString lower = smsText.toLower();
    simIDOut = (lower.contains("sim2") || lower.contains("secondary"))
                   ? KMS_SIM_SECONDARY
                   : KMS_SIM_PRIMARY;

    qInfo() << "[KMS] OTP extracted:"
            << otpOut
            << "SIM:" << Qt::hex << simIDOut;

    return true;
}

bool EventLoggerKMS::EnsureGPRSActive()
{
    QString cgact = SendATCommand("AT+CGACT?", 3000);
    qDebug() << "[KMS] CGACT:" << cgact;

    // Already active
    if (cgact.contains("+CGACT: 1,1"))
    {
        qInfo() << "[KMS] GPRS already active ✅";
        return true;
    }

    // ── Activate PDP context ──────────────────────────────
    qInfo() << "[KMS] Activating GPRS...";

    // Set APN for Jio (change if using different operator)
    SendATCommand("AT+CGDCONT=1,\"IP\",\"jionet\"", 3000);
    QThread::msleep(500);

    QString resp = SendATCommand("AT+CGACT=1,1", 10000);

    if (!resp.contains("OK"))
    {
        qCritical() << "[KMS] GPRS activation FAILED:" << resp;
        return false;
    }

    QThread::msleep(2000);   // wait for data session

    qInfo() << "[KMS] GPRS activated ✅";
    return true;

}

// ============================================================
//  CSQ Signal Strength
// ============================================================

int EventLoggerKMS::QueryCSQ()
{
    QString resp = SendATCommand("AT+CSQ");

    QRegularExpression re("\\+CSQ:\\s*(\\d+),");
    QRegularExpressionMatch match = re.match(resp);
    if (!match.hasMatch())
    {
        qWarning() << "[KMS] CSQ parse failed:" << resp;
        return -1;
    }
    return match.captured(1).toInt();
}

KMSSignalQuality EventLoggerKMS::ClassifyCSQ(int csq)
{
    if (csq < 0)                                               return KMSSignalQuality::Unknown;
    if (csq == KMS_CSQ_UNKNOWN)                               return KMSSignalQuality::Unreachable;
    if (csq == KMS_CSQ_EXCELLENT)                             return KMSSignalQuality::Excellent;
    if (csq >= KMS_CSQ_GOOD_MIN && csq < KMS_CSQ_EXCELLENT)  return KMSSignalQuality::Good;
    if (csq >= KMS_CSQ_OK_MIN   && csq < KMS_CSQ_GOOD_MIN)   return KMSSignalQuality::OK;
    if (csq >= KMS_CSQ_MARGINAL_MIN && csq < KMS_CSQ_OK_MIN) return KMSSignalQuality::Marginal;
    return KMSSignalQuality::Unreachable;
}

QString EventLoggerKMS::SignalQualityString(KMSSignalQuality q)
{
    switch (q)
    {
    case KMSSignalQuality::Excellent:   return "Excellent";
    case KMSSignalQuality::Good:        return "Good";
    case KMSSignalQuality::OK:          return "OK";
    case KMSSignalQuality::Marginal:    return "Marginal";
    case KMSSignalQuality::Unreachable: return "Unreachable";
    default:                            return "Unknown";
    }
}

void EventLoggerKMS::SlotPollCSQ()
{
    int csq = QueryCSQ();
    KMSSignalQuality quality = ClassifyCSQ(csq);

    qDebug() << "[KMS] CSQ:" << csq
             << "Quality:" << SignalQualityString(quality);

    emit SigCSQUpdated(csq, quality);

    // ICD §D.8.8 failure code 0x13: signal below threshold
    if (quality == KMSSignalQuality::Marginal ||
        quality == KMSSignalQuality::Unreachable ||
        quality == KMSSignalQuality::Unknown)
    {
        quint8 simID = ActiveChannel().ucSimID;
        QByteArray failPkt = BuildCommFailurePacket(m_ucKavachUnitType,
                                                    m_ucKavachUnitID,
                                                    simID,
                                                    KMS_FAIL_SIGNAL_THRESHOLD,
                                                    0);
        ForwardToVC(failPkt);
    }
}