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
 * BOOT-TIME CHANGES (vs. previous revision)
 *   - No fixed sleeps in modem bring-up (was ~3.7 s of msleep).
 *   - AT sync polls with a short timeout; if the modem is not up yet the
 *     bring-up retries from the event loop instead of blocking Init().
 *   - PDP activation / SMS purge are no longer part of Init(); the data
 *     session is brought up from the health poll once the network is
 *     registered (rate-limited), or lazily by EnsureGPRSActive().
 *   - SendATCommand returns as soon as the final result code arrives
 *     (no extra 30 ms DTR sleep, no 50 ms drain wait per command).
 *   - ForwardToKMS no longer blocks the main thread for up to 180 s: it
 *     is a timer-driven session, so the 0xA2 heartbeat keeps flowing.
 *   - Logging: hex dumps / per-AT traces are compiled out (KMS_VERBOSE).
 *
 * Author  : SaNa Software
 * Date    : 2026
 ******************************************************************************/

#include "EventLoggerKMS.h"
#include <QDebug>
#include <QRegularExpression>
#include <QThread>
#include <QStringList>

// ============================================================
//  Local constants / helpers
// ============================================================

namespace
{
// APN — Jio. Change here if the SIM operator changes.
const char *const KMS_APN = "jionet";

constexpr int AT_SYNC_TIMEOUT_MS   = 400;    // "AT" probe during bring-up
constexpr int AT_CFG_TIMEOUT_MS    = 1000;   // simple config commands
constexpr int AT_PURGE_TIMEOUT_MS  = 2000;   // AT+CMGD (SIM storage)
constexpr int AT_QUERY_TIMEOUT_MS  = 1000;   // CPIN?/CREG?/CSQ ...
constexpr int AT_PDP_TIMEOUT_MS    = 8000;   // AT+CGACT=1,1
constexpr int AT_SOCKET_TIMEOUT_MS = 3000;   // USOCR
constexpr int AT_SEND_TIMEOUT_MS   = 5000;   // USOST
constexpr int AT_CLOSE_TIMEOUT_MS  = 1500;   // USOCL
constexpr int PDP_RETRY_INTERVAL_MS = 20000; // health-poll PDP retries

constexpr int SESSION_POLL_MS      = 300;    // Phase 1: UDP reply polling
constexpr int SESSION_OTP_POLL_MS  = 500;    // Phase 2: OTP SMS polling
constexpr int PHASE1_TIMEOUT_MS    = 120000; // no UDP reply from KMS
constexpr int PHASE2_TIMEOUT_MS    = 60000;  // no OTP SMS after 0x91

// True when the modem has sent the final result code of a command.
bool AtResponseComplete(const QByteArray &r)
{
    const QByteArray t = r.trimmed();
    if (t.endsWith("OK") || t.endsWith('>'))
        return true;
    if (t.contains("ERROR"))          // ERROR / +CME ERROR: n / +CMS ERROR: n
        return r.endsWith('\n');
    return false;
}

// Body of a +CMGR response (first line that is not the header / OK).
QString ExtractCmgrBody(const QString &cmgr)
{
    const QStringList lines = cmgr.split('\n', Qt::SkipEmptyParts);
    for (const QString &line : lines)
    {
        const QString t = line.trimmed();
        if (t.isEmpty() || t.startsWith("+CMGR") || t == "OK")
            continue;
        return t;
    }
    return QString();
}

// Latest (highest index) unread SMS whose body mentions "OTP".
bool FindOtpInCmgl(const QString &resp, QString &bodyOut, int &idxOut)
{
    static const QRegularExpression idxRe(R"(\+CMGL:\s*(\d+))");

    bodyOut.clear();
    idxOut = -1;

    const QStringList lines = resp.split('\n', Qt::SkipEmptyParts);

    for (int i = 0; i < lines.size(); ++i)
    {
        const QString line = lines[i].trimmed();
        if (!line.startsWith("+CMGL:"))
            continue;

        const QRegularExpressionMatch m = idxRe.match(line);
        const int idx = m.hasMatch() ? m.captured(1).toInt() : -1;

        QString body;
        for (int j = i + 1; j < lines.size(); ++j)
        {
            const QString cand = lines[j].trimmed();
            if (cand.isEmpty() || cand == "OK")
                continue;
            body = cand;
            break;
        }

        if (body.isEmpty() || !body.contains("OTP", Qt::CaseInsensitive))
            continue;

        if (idx > idxOut)
        {
            idxOut   = idx;
            bodyOut  = body;
        }
    }

    return !bodyOut.isEmpty();
}
}

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

    // Periodic GSM health poll (SIM/network/signal) — started when modem is ready
    m_pCSQTimer = new QTimer(this);
    connect(m_pCSQTimer, &QTimer::timeout,
            this, &EventLoggerKMS::SlotPollCSQ);

    // LED blink timer — only running while GSM health is in fault state.
    m_pLedBlinkTimer = new QTimer(this);
    connect(m_pLedBlinkTimer, &QTimer::timeout,
            this, &EventLoggerKMS::SlotBlinkGSMLed);

    // OTP poll timer (armed after a 0x91 ACK that announces an OTP SMS)
    m_pOTPPollTimer = new QTimer(this);
    connect(m_pOTPPollTimer, &QTimer::timeout,
            this, [this]()
            {
                if (!m_bWaitingForOTP)
                {
                    m_pOTPPollTimer->stop();
                    return;
                }

                if (m_otpWatchTimer.elapsed() > PHASE2_TIMEOUT_MS)
                {
                    qWarning() << "[KMS] OTP timeout 60s";
                    m_bWaitingForOTP = false;
                    m_pOTPPollTimer->stop();
                    ReportFailureToVC(KMS_FAIL_SMS_OTP, 0);
                    return;
                }

                SlotReadLatestSMS();
            });

    // Drives the non-blocking VC->KMS transaction
    m_pSessionTimer = new QTimer(this);
    connect(m_pSessionTimer, &QTimer::timeout,
            this, &EventLoggerKMS::SlotSessionStep);
}

EventLoggerKMS::~EventLoggerKMS()
{
    if (m_pCSQTimer) m_pCSQTimer->stop();
    if (m_pLedBlinkTimer) m_pLedBlinkTimer->stop();
    if (m_pSessionTimer) m_pSessionTimer->stop();
    if (m_pGSMSerial && m_pGSMSerial->isOpen())
        m_pGSMSerial->close();
}

// ============================================================
//  Init
//
//  Returns quickly: opens sockets + the serial port and schedules the
//  modem bring-up on the event loop. "true" means the port is open;
//  modem readiness is reported by the "[KMS] GSM modem ready" log line
//  and by IsModemReady() / GetGSMStatus().
// ============================================================

bool EventLoggerKMS::Init(const KMSChannelConfig &chanA,
                          const KMSChannelConfig &chanB,
                          const QString          &gsmPort,
                          qint32                  gsmBaud)
{
    m_initClock.start();

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

                    if (data.size() < 3 ||
                        static_cast<uint8_t>(data[0]) != KMS_SOF1 ||
                        static_cast<uint8_t>(data[1]) != KMS_SOF2)
                    {
                        qWarning() << "[KMS] Bad SOF from KMS server — dropping";
                        continue;
                    }

                    const quint8 msgType = static_cast<quint8>(data[2]);

                    switch (msgType)
                    {
                    case KMS_MSG_IDENTIFICATION_ACK:   // 0x91
                    {
                        const quint8 ackStatus = (data.size() >= 16)
                        ? static_cast<quint8>(data[15])
                        : 0;

                        qInfo() << "[KMS] 0x91 ACK from KMS, status ="
                                << QString::number(ackStatus, 16);

                        // Forward to VC first
                        ForwardToVC(data);

                        // Arm OTP polling only if KMS confirmed OTP sent
                        if (ackStatus == 0x01 && !m_bWaitingForOTP)
                        {
                            m_bWaitingForOTP = true;
                            m_otpWatchTimer.start();
                            m_pOTPPollTimer->start(2000);
                        }
                        break;
                    }

                    case KMS_MSG_AUTH_KEY:          // 0x93
                    case KMS_MSG_AUTH_KEY_STATUS:   // 0x95
                        ForwardToVC(data);
                        break;

                    default:
                        qWarning() << "[KMS] Unknown MsgType from KMS server:"
                                   << QString::number(msgType, 16);
                        break;
                    }
                }
            });

    // =========================================================
    // GSM serial port — open only. AT bring-up runs from the event loop.
    // =========================================================
    m_pGSMSerial = new QSerialPort(this);

    m_pGSMSerial->setPortName(gsmPort);
    m_pGSMSerial->setBaudRate(gsmBaud);
    m_pGSMSerial->setDataBits(QSerialPort::Data8);
    m_pGSMSerial->setParity(QSerialPort::NoParity);
    m_pGSMSerial->setStopBits(QSerialPort::OneStop);
    m_pGSMSerial->setFlowControl(QSerialPort::NoFlowControl);   // Toradex UART

    if (!m_pGSMSerial->open(QIODevice::ReadWrite))
    {
        qCritical() << "[KMS] GSM open FAILED on" << gsmPort << ":"
                    << m_pGSMSerial->errorString();
        return false;
    }

    m_pGSMSerial->setDataTerminalReady(true);
    m_pGSMSerial->setRequestToSend(true);
    m_pGSMSerial->clear(QSerialPort::AllDirections);

    connect(m_pGSMSerial, &QSerialPort::readyRead,
            this, &EventLoggerKMS::SlotHandleGSMData);

    qInfo() << "[KMS] GSM port opened:" << gsmPort << "@" << gsmBaud
            << "— modem bring-up scheduled";

    // Runs right after the caller (StartKMS) finishes wiring signals.
    QTimer::singleShot(0, this, &EventLoggerKMS::SlotModemBringUp);

    return true;
}

// ============================================================
//  SlotModemBringUp
//
//  1. AT sync — one short probe; if the modem is still booting this
//     slot re-arms itself every second (event loop stays responsive).
//  2. Fast config (echo off, SMS text mode, URC config, APN, SMS purge).
//  3. Start health poll. PDP activation is done by the health poll /
//     EnsureGPRSActive() so a missing network never blocks start-up.
// ============================================================

void EventLoggerKMS::SlotModemBringUp()
{
    if (m_bModemReady || !m_pGSMSerial || !m_pGSMSerial->isOpen())
        return;

    // ── 1. Sync ──────────────────────────────────────────────
    if (!SendATCommand("AT", AT_SYNC_TIMEOUT_MS).contains("OK"))
    {
        ++m_iSyncFails;

        if (m_iSyncFails == 10 || (m_iSyncFails % 60) == 0)
            qWarning() << "[KMS] GSM modem not answering AT —"
                       << m_iSyncFails << "tries, still retrying";

        QTimer::singleShot(1000, this, &EventLoggerKMS::SlotModemBringUp);
        return;
    }

    // ── 2. Config ────────────────────────────────────────────
    SendATCommand("ATE0", AT_CFG_TIMEOUT_MS);

    if (!SendATCommand("AT+CMGF=1", AT_CFG_TIMEOUT_MS).contains("OK"))
        qWarning() << "[KMS] Failed to enable SMS text mode";

    if (!SendATCommand("AT+CNMI=2,2,0,0,0", AT_CFG_TIMEOUT_MS).contains("OK"))
    {
        if (!SendATCommand("AT+CNMI=1,1,0,0,0", AT_CFG_TIMEOUT_MS).contains("OK"))
            qWarning() << "[KMS] CNMI setup FAILED";
    }

    // +UUSORD unsolicited indication for UDP data
    if (!SendATCommand("AT+UDCONF=1,1", AT_CFG_TIMEOUT_MS).contains("OK"))
        qWarning() << "[KMS] UDCONF failed (continuing)";

    if (!SendATCommand(QString("AT+CGDCONT=1,\"IP\",\"%1\"").arg(KMS_APN),
                       AT_CFG_TIMEOUT_MS).contains("OK"))
        qWarning() << "[KMS] Failed to set APN:" << KMS_APN;

    // Purge stale SMS so an old OTP can never be picked up
    if (!SendATCommand("AT+CMGD=1,4", AT_PURGE_TIMEOUT_MS).contains("OK"))
        qWarning() << "[KMS] Startup SMS purge failed";

    // ── 3. Ready ─────────────────────────────────────────────
    m_bModemReady = true;
    m_bInitDone   = true;

    CommandGSMLed(false);   // blink until first health check completes

    // GPRS first (runs on the next loop iteration, so the heartbeat and
    // other timers are not starved), then the first health check.
    QTimer::singleShot(0, this, &EventLoggerKMS::SlotInitialGPRS);

    m_pCSQTimer->start(KMS_HEALTH_POLL_INTERVAL_MS);
    QTimer::singleShot(300, this, &EventLoggerKMS::SlotPollCSQ);   // first check now

    qInfo() << "[KMS] GSM modem ready —" << m_initClock.elapsed()
            << "ms after Init";
}

// ============================================================
//  SlotInitialGPRS
//
//  Brings the GPRS data session up as soon as the modem is ready, so
//  on-board packets can be sent immediately. A cheap registration
//  check comes first, so an unregistered modem never blocks the main
//  thread inside AT+CGACT. Retries every second (up to ~60 s); after
//  that the health poll keeps trying every PDP_RETRY_INTERVAL_MS.
// ============================================================

void EventLoggerKMS::SlotInitialGPRS()
{
    if (!m_bModemReady)
        return;

    const int kMaxTries = 60;

    if (!CheckNetworkRegistered())
    {
        if (++m_iGprsInitTries < kMaxTries)
            QTimer::singleShot(1000, this, &EventLoggerKMS::SlotInitialGPRS);
        else
            qWarning() << "[KMS] Network not registered after"
                       << kMaxTries << "s — health poll will keep trying";
        return;
    }

    if (EnsureGPRSActive())
    {
        qInfo() << "[KMS] GPRS up —" << m_initClock.elapsed()
            << "ms after Init";
        return;
    }

    if (++m_iGprsInitTries < kMaxTries)
        QTimer::singleShot(1000, this, &EventLoggerKMS::SlotInitialGPRS);
    else
        qWarning() << "[KMS] GPRS activation failed after"
                   << kMaxTries << "tries — health poll will keep trying";
}

// ============================================================
//  SlotReadLatestSMS
//
//  Called every 2s by m_pOTPPollTimer after 0x91 ACK.
//  Polls AT+CMGL="REC UNREAD" for fresh OTP SMS.
//  Disarms itself after first successful OTP extraction.
//
//  ICD §D.8.3 — OTP received via SMS, build 0x96, send to VC.
// ============================================================

void EventLoggerKMS::SlotReadLatestSMS()
{
    if (!m_bWaitingForOTP)
    {
        m_pOTPPollTimer->stop();
        return;
    }

    if (!IsModemReady())
        return;

    if (m_otpWatchTimer.elapsed() > PHASE2_TIMEOUT_MS)
    {
        qWarning() << "[KMS] OTP wait TIMEOUT (60s) — giving up";
        m_bWaitingForOTP = false;
        m_pOTPPollTimer->stop();
        ReportFailureToVC(KMS_FAIL_SMS_OTP, 0);
        return;
    }

    const QString resp = SendATCommand("AT+CMGL=\"REC UNREAD\"", 3000);

    QString latestBody;
    int     latestIdx = -1;

    if (!FindOtpInCmgl(resp, latestBody, latestIdx))
        return;   // nothing yet — retry on next tick

    // DISARM before processing — prevents double-fire
    m_bWaitingForOTP = false;
    m_pOTPPollTimer->stop();

    qInfo() << "[KMS] OTP SMS found at index" << latestIdx;

    ProcessOTPSms(latestBody);

    // Delete ALL SMS after extraction — keep SIM storage clean
    if (!SendATCommand("AT+CMGD=1,4", AT_PURGE_TIMEOUT_MS).contains("OK"))
        qWarning() << "[KMS] SMS delete failed";
}

// ============================================================
//  Set ELU Identity
// ============================================================

void EventLoggerKMS::SetKavachUnitInfo(quint8 ucUnitType, const quint8 ucUnitID[3])
{
    m_ucKavachUnitType = ucUnitType;
    memcpy(m_ucKavachUnitID, ucUnitID, 3);
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
    const quint8 newSim = ActiveChannel().ucSimID;

    qWarning() << "[KMS] Channel changeover →"
               << (m_bUsingChanA ? "ELU-A (Primary)" : "ELU-B (Standby)")
               << "SIM:" << QString::number(newSim, 16);

    emit SigChannelChangeover(newSim);
}

// ============================================================
//  GSM Modem Initialization (kept for header compatibility)
//
//  The real work is in SlotModemBringUp(); this simply reports
//  whether the modem is ready.
// ============================================================

bool EventLoggerKMS::InitGSMModem(const QString &, qint32)
{
    return m_bModemReady;
}

// ============================================================
//  SendATCommand
//
//  Blocking send/receive of one AT command. Returns as soon as the
//  final result code (OK / ERROR / '>') has arrived — no fixed waits.
//  Must only be called from the thread that owns the serial port.
// ============================================================

QString EventLoggerKMS::SendATCommand(const QString &cmd, int timeoutMs)
{
    if (!m_pGSMSerial || !m_pGSMSerial->isOpen())
    {
        qWarning() << "[KMS] GSM Serial not open for cmd:" << cmd;
        return QString();
    }

    // SlotHandleGSMData must NOT consume bytes while we do a blocking
    // read, otherwise the AT response is stolen.
    disconnect(m_pGSMSerial, &QSerialPort::readyRead,
               this, &EventLoggerKMS::SlotHandleGSMData);

    m_pGSMSerial->setDataTerminalReady(true);

    const QByteArray cmdBytes = cmd.toUtf8() + "\r";

    KMS_DBG << "[KMS AT TX]" << cmd;

    // Discard stale RX bytes before sending
    m_pGSMSerial->readAll();

    qint64 written = m_pGSMSerial->write(cmdBytes);
    if (written != cmdBytes.size())
    {
        m_pGSMSerial->flush();
        written = m_pGSMSerial->write(cmdBytes);
    }

    if (written <= 0)
    {
        qWarning() << "[KMS] AT write FAILED:" << m_pGSMSerial->errorString();
        connect(m_pGSMSerial, &QSerialPort::readyRead,
                this, &EventLoggerKMS::SlotHandleGSMData);
        return QString();
    }

    m_pGSMSerial->waitForBytesWritten(500);

    QByteArray    response;
    QElapsedTimer timer;
    timer.start();

    while (timer.elapsed() < timeoutMs)
    {
        const int wait = static_cast<int>(
            qMin<qint64>(100, timeoutMs - timer.elapsed()));

        if (wait <= 0)
            break;

        if (!m_pGSMSerial->waitForReadyRead(wait))
            continue;

        response += m_pGSMSerial->readAll();

        if (AtResponseComplete(response))
            break;
    }

    const QString result = QString::fromLatin1(response).trimmed();

    KMS_DBG << "[KMS AT RX]" << result;

    if (result.isEmpty())
    {
        // Log the first miss and then only every 20th, so a missing
        // modem cannot flood the journal.
        if ((m_iAtNoRespCnt++ % 20) == 0)
            qWarning() << "[KMS] No response for cmd:" << cmd;
    }
    else
    {
        m_iAtNoRespCnt = 0;
    }

    connect(m_pGSMSerial, &QSerialPort::readyRead,
            this, &EventLoggerKMS::SlotHandleGSMData);

    return result;
}

// ============================================================
//  SendUDPViaGSM — relay of arbitrary packets through the modem
// ============================================================

bool EventLoggerKMS::SendUDPViaGSM(const QByteArray &rawPacket,
                                   const QString &destIP,
                                   quint16 destPort)
{
    if (!IsModemReady())
    {
        qWarning() << "[GSM Relay] modem not ready — packet dropped";
        return false;
    }

    KMS_DBG << "[GSM Relay] DEST:" << destIP << ":" << destPort
            << "SIZE:" << rawPacket.size()
            << "HEX:" << rawPacket.toHex(' ').toUpper();

    if (!EnsureGPRSActive())
    {
        qWarning() << "[GSM Relay] GPRS is not active";
        return false;
    }

    const QString response = SendATCommand("AT+USOCR=17", AT_SOCKET_TIMEOUT_MS);

    static const QRegularExpression re(R"(\+USOCR:\s*(\d+))");
    const QRegularExpressionMatch match = re.match(response);

    if (!match.hasMatch())
    {
        qWarning() << "[GSM Relay] UDP socket creation failed:" << response;
        return false;
    }

    const int socketHandle = match.captured(1).toInt();

    const QString cmd =
        QString("AT+USOST=%1,\"%2\",%3,%4,\"%5\"")
            .arg(socketHandle)
            .arg(destIP)
            .arg(destPort)
            .arg(rawPacket.size())
            .arg(QString::fromLatin1(rawPacket.toHex()).toUpper());

    const QString txResponse = SendATCommand(cmd, AT_SEND_TIMEOUT_MS);

    const bool success = txResponse.contains("+USOST");

    if (!success)
        qWarning() << "[GSM Relay] UDP transmission FAILED, size"
                   << rawPacket.size();

    SendATCommand(QString("AT+USOCL=%1").arg(socketHandle),
                  AT_CLOSE_TIMEOUT_MS);

    return success;
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

    const bool ok = (recvCRC == calcCRCBE);
    if (!ok)
        qWarning() << "[KMS] CRC mismatch recv=" << QString::number(recvCRC, 16)
                   << "calc=" << QString::number(calcCRCBE, 16);
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
//  ELU forwards the raw packet unchanged to KMS via GSM/GPRS and
//  remembers the sender for reverse forwarding.
// ============================================================

void EventLoggerKMS::SlotHandleUDPFromVC(QByteArray    datagram,
                                         QHostAddress  senderIP,
                                         quint16       senderPort)
{
    // Remember VC address for sending packets back
    m_vcLastAddr = senderIP;
    m_vcLastPort = senderPort;

    KMS_DBG << "[KMS] UDP from VC:" << senderIP.toString()
            << "port:" << senderPort
            << "size:" << datagram.size()
            << "data:" << datagram.toHex().toUpper();

    const quint8 msgType = GetKMSMsgType(datagram);

    switch (msgType)
    {
    case KMS_MSG_IDENTIFICATION:    // 0x90
    case KMS_MSG_AUTH_KEY_REQ:      // 0x92
    case KMS_MSG_AUTH_QUERY:        // 0x94
        emit SigKMSPacketReceived(msgType, datagram);
        ForwardToKMS(datagram, msgType);
        break;

    default:
        qWarning() << "[KMS] Unexpected MsgType from VC:"
                   << QString::number(msgType, 16) << "— dropping";
        break;
    }
}

// ============================================================
//  Forward Raw KMS Packet to KMS via GSM/GPRS
//
//  ICD §D.2: ELU shall transport packets transparently — NO modification.
//
//  Sends the packet, then hands over to m_pSessionTimer which polls for
//  the UDP reply (Phase 1) and, if KMS announces an OTP, the OTP SMS
//  (Phase 2). Each poll step is a single short AT command, so the Qt
//  event loop — and with it the 0xA2 heartbeat — keeps running.
// ============================================================

void EventLoggerKMS::ForwardToKMS(
    const QByteArray &rawPacket,
    quint8 msgType)
{
    if (!IsModemReady())
    {
        qWarning() << "[KMS] GSM not ready — cannot forward"
                   << QString::number(msgType, 16);
        ReportFailureToVC(KMS_FAIL_MODEM_GSM, 0);
        return;
    }

    // A new request replaces any transaction still waiting for a reply
    // (the VC retries at protocol level).
    if (m_sess.active)
    {
        qWarning() << "[KMS] New request while a session is active — closing previous";
        AbortSession();
    }

    const QString kmsIP   = ActiveChannel().strKMSServerIP;
    const quint16 kmsPort = ActiveChannel().usKMSServerPort;

    // 0xA2 Field 16 reports the state of the most recent KMS transaction.
    m_bKMSCommunicationOk = false;

    qInfo() << "[KMS] VC → KMS msg" << QString::number(msgType, 16)
            << "size" << rawPacket.size()
            << "dest" << kmsIP << ":" << kmsPort;

    KMS_DBG << "[KMS] HEX:" << rawPacket.toHex(' ').toUpper();

    if (!EnsureGPRSActive())
    {
        qWarning() << "[KMS] GPRS unavailable";
        ReportFailureToVC(KMS_FAIL_GPRS_NETWORK, 0);
        return;
    }

    // ── Create modem UDP socket ──────────────────────────────
    const QString usocrResp = SendATCommand("AT+USOCR=17", AT_SOCKET_TIMEOUT_MS);

    static const QRegularExpression reSocket(R"(\+USOCR:\s*(\d+))");
    const QRegularExpressionMatch socketMatch = reSocket.match(usocrResp);

    if (!socketMatch.hasMatch())
    {
        qWarning() << "[KMS] Socket create FAILED:" << usocrResp;
        ReportFailureToVC(KMS_FAIL_GPRS_NETWORK, 0);
        return;
    }

    const int socketHandle = socketMatch.captured(1).toInt();

    // ── Send UDP packet via AT+USOST ─────────────────────────
    const QString sendCmd = QString("AT+USOST=%1,\"%2\",%3,%4,\"%5\"")
                                .arg(socketHandle)
                                .arg(kmsIP)
                                .arg(kmsPort)
                                .arg(rawPacket.size())
                                .arg(QString::fromLatin1(rawPacket.toHex()).toUpper());

    const QString sendResp = SendATCommand(sendCmd, AT_SEND_TIMEOUT_MS);

    if (!sendResp.contains("+USOST"))
    {
        qWarning() << "[KMS] UDP send failed:" << sendResp;
        ReportFailureToVC(KMS_FAIL_GPRS_NETWORK, 0);
        SendATCommand(QString("AT+USOCL=%1").arg(socketHandle),
                      AT_CLOSE_TIMEOUT_MS);
        return;
    }

    // ── Hand over to the session timer ───────────────────────
    m_sess              = KmsSession();
    m_sess.active       = true;
    m_sess.socketHandle = socketHandle;
    m_sess.msgType      = msgType;
    m_sess.raw          = rawPacket;
    m_sess.total.start();

    m_pSessionTimer->start(SESSION_POLL_MS);
}

// ============================================================
//  SlotSessionStep — one poll step of the active KMS transaction
// ============================================================

void EventLoggerKMS::SlotSessionStep()
{
    if (!m_sess.active)
    {
        m_pSessionTimer->stop();
        return;
    }

    // ── Phase 1: wait for 0x91 / 0x93 / 0x95 ─────────────────
    if (!m_sess.gotUDPReply)
    {
        if (m_sess.total.elapsed() > PHASE1_TIMEOUT_MS)
        {
            qWarning() << "[KMS] Phase1: no UDP reply in 120 s";
            ReportFailureToVC(KMS_FAIL_NO_KMS_RESPONSE, 0);
            FinishSession();
            return;
        }

        const QString pollResp = SendATCommand(
            QString("AT+USORF=%1,1024").arg(m_sess.socketHandle), 1500);

        KMS_DBG << "[KMS] USORF:" << pollResp;

        static const QRegularExpression reData(
            "\\+USORF:\\s*(\\d+),\"([^\"]+)\",(\\d+),(\\d+),\"([0-9A-Fa-f]+)\"");
        const QRegularExpressionMatch match = reData.match(pollResp);

        if (!match.hasMatch() || match.captured(4).toInt() <= 0)
            return;   // nothing yet

        HandleKmsReply(QByteArray::fromHex(match.captured(5).toLatin1()));

        if (!m_sess.gotUDPReply)
            return;   // unknown message type — keep polling

        if (!m_sess.otpExpected)
        {
            FinishSession();
            return;
        }

        // Enter Phase 2
        m_sess.otp.start();
        m_pSessionTimer->start(SESSION_OTP_POLL_MS);
        qInfo() << "[KMS] OTP expected via SMS — waiting up to 60 s";
        return;
    }

    // ── Phase 2: wait for the OTP SMS ────────────────────────
    if (m_sess.otpExpected && !m_sess.gotOTP)
    {
        if (m_sess.otp.elapsed() > PHASE2_TIMEOUT_MS)
        {
            qWarning() << "[KMS] Phase2: OTP SMS not received in 60 s";
            ReportFailureToVC(KMS_FAIL_SMS_OTP, 0);
            FinishSession();
            return;
        }

        PollOtpSms();

        if (m_sess.gotOTP)
            FinishSession();

        return;
    }

    FinishSession();
}

// ============================================================
//  HandleKmsReply — 0x91 / 0x93 / 0x95 read from the modem socket
// ============================================================

void EventLoggerKMS::HandleKmsReply(const QByteArray &response)
{
    if (response.size() < 3)
        return;

    const quint8 respType = static_cast<quint8>(response[2]);

    switch (respType)
    {
    case KMS_MSG_IDENTIFICATION_ACK:   // 0x91
    {
        m_bKMSCommunicationOk = true;
        ForwardToVC(response);
        emit SigKMSPacketReceived(respType, response);
        m_sess.gotUDPReply = true;

        // ICD §D.8.3: byte[15] = 0x01 means an OTP SMS is on its way
        const quint8 ackStatus = (response.size() >= 16)
                                     ? static_cast<quint8>(response[15])
                                     : 0x00;

        m_sess.otpExpected = (ackStatus == KMS_ACK_OTP_SENT);

        qInfo() << "[KMS] 0x91 ACK from KMS, status ="
                << QString::number(ackStatus, 16);
        break;
    }

    case KMS_MSG_AUTH_KEY:           // 0x93
    case KMS_MSG_AUTH_KEY_STATUS:    // 0x95
        qInfo() << "[KMS] KMS → VC msg" << QString::number(respType, 16);
        m_bKMSCommunicationOk = true;
        ForwardToVC(response);
        emit SigKMSPacketReceived(respType, response);
        m_sess.gotUDPReply = true;
        m_sess.otpExpected = false;   // 0x93/0x95 never carry an OTP
        break;

    default:
        qWarning() << "[KMS] Unknown MsgType from KMS:"
                   << QString::number(respType, 16);
        break;
    }
}

// ============================================================
//  PollOtpSms — one AT+CMGL poll for the OTP SMS (Phase 2)
// ============================================================

void EventLoggerKMS::PollOtpSms()
{
    const QString cmgl = SendATCommand("AT+CMGL=\"REC UNREAD\"", 3000);

    QString body;
    int     idx = -1;

    if (!FindOtpInCmgl(cmgl, body, idx))
        return;

    qInfo() << "[KMS] OTP SMS found, idx" << idx;

    ProcessOTPSms(body);
    m_sess.gotOTP = true;

    if (!SendATCommand("AT+CMGD=1,4", AT_PURGE_TIMEOUT_MS).contains("OK"))
        qWarning() << "[KMS] SMS delete failed";
}

// ============================================================
//  Session end helpers
// ============================================================

void EventLoggerKMS::AbortSession()
{
    m_pSessionTimer->stop();

    if (!m_sess.active)
        return;

    const int handle = m_sess.socketHandle;
    m_sess.active = false;

    SendATCommand(QString("AT+USOCL=%1").arg(handle), AT_CLOSE_TIMEOUT_MS);
}

void EventLoggerKMS::FinishSession()
{
    m_pSessionTimer->stop();

    if (!m_sess.active)
        return;

    const int        handle  = m_sess.socketHandle;
    const quint8     type    = m_sess.msgType;
    const QByteArray raw     = m_sess.raw;

    qInfo() << "[KMS] Session done:"
            << "reply =" << m_sess.gotUDPReply
            << "| otp expected =" << m_sess.otpExpected
            << "| otp received =" << m_sess.gotOTP;

    m_sess.active = false;

    SendATCommand(QString("AT+USOCL=%1").arg(handle), AT_CLOSE_TIMEOUT_MS);

    emit SigKMSPacketSent(type, raw);
}

// ============================================================
//  Forward Raw KMS Packet from KMS to VC via UDP
//
//  ICD §D.9: ELU shall forward within 2000ms of reception.
//  ICD §D.2: Payload transported transparently — NO modification.
// ============================================================

void EventLoggerKMS::ForwardToVC(const QByteArray &rawPacket)
{
    const quint8 msgType = GetKMSMsgType(rawPacket);

    emit SigSendToVC(rawPacket, m_vcLastAddr, m_vcLastPort);
    emit SigKMSPacketSent(msgType, rawPacket);
}

// ============================================================
//  SLOT: GSM Serial Data Received (asynchronous, between AT commands)
//
//  Case A: Raw KMS GPRS packet (0x91/0x93/0x95) → forward to VC.
//  Case B: SMS indication (+CMTI) → read SMS, extract OTP, send 0x96.
// ============================================================

void EventLoggerKMS::SlotHandleGSMData()
{
    if (!m_pGSMSerial)
        return;

    const QByteArray rx = m_pGSMSerial->readAll();

    if (rx.isEmpty())
        return;

    KMS_DBG << "[KMS RAW RX]" << rx;

    m_gsmBuffer.append(rx);

    // =====================================================
    // CASE A : KMS Binary Packet
    // =====================================================
    while (m_gsmBuffer.size() >= 7)
    {
        int sofIdx = -1;

        for (int i = 0; i < m_gsmBuffer.size() - 1; i++)
        {
            if (static_cast<uint8_t>(m_gsmBuffer[i])     == KMS_SOF1 &&
                static_cast<uint8_t>(m_gsmBuffer[i + 1]) == KMS_SOF2)
            {
                sofIdx = i;
                break;
            }
        }

        if (sofIdx < 0)
            break;

        if (sofIdx > 0)
            m_gsmBuffer.remove(0, sofIdx);

        if (m_gsmBuffer.size() < 5)
            break;

        const quint16 msgLen =
            (static_cast<quint16>(static_cast<uint8_t>(m_gsmBuffer[3])) << 8) |
            static_cast<quint16>(static_cast<uint8_t>(m_gsmBuffer[4]));

        const int totalLen = 2 + 1 + 2 + msgLen;

        if (m_gsmBuffer.size() < totalLen)
            break;

        const QByteArray packet = m_gsmBuffer.left(totalLen);
        m_gsmBuffer.remove(0, totalLen);

        const quint8 msgType = GetKMSMsgType(packet);

        switch (msgType)
        {
        case KMS_MSG_IDENTIFICATION_ACK:
        case KMS_MSG_AUTH_KEY:
        case KMS_MSG_AUTH_KEY_STATUS:
        {
            qInfo() << "[KMS] KMS → VC msg" << QString::number(msgType, 16)
                    << "size" << packet.size();

            m_bKMSCommunicationOk = true;
            emit SigKMSPacketReceived(msgType, packet);

            ForwardToVC(packet);

            // Start OTP wait on 0x91 ACK
            if (msgType == KMS_MSG_IDENTIFICATION_ACK)
            {
                m_bWaitingForOTP = true;
                m_otpWatchTimer.start();

                if (m_pOTPPollTimer)
                    m_pOTPPollTimer->start(2000);
            }

            break;
        }

        default:
            qWarning() << "[KMS] Unknown MsgType:" << QString::number(msgType, 16);
            break;
        }
    }

    // =====================================================
    // CASE B : SMS INDICATION (+CMTI)   e.g.  +CMTI: "ME",0
    // =====================================================
    static const QRegularExpression reCmti(R"(\+CMTI:\s*"[^"]+",(\d+))");

    while (true)
    {
        const QString bufferStr = QString::fromLatin1(m_gsmBuffer);

        const QRegularExpressionMatch match = reCmti.match(bufferStr);

        if (!match.hasMatch())
            break;

        const int smsIndex = match.captured(1).toInt();

        // Remove processed indication
        const int removePos = bufferStr.indexOf("+CMTI:");
        const int endLine   = bufferStr.indexOf('\n', removePos);

        if (removePos >= 0 && endLine > removePos)
            m_gsmBuffer.remove(removePos, endLine - removePos + 1);
        else
            m_gsmBuffer.clear();   // incomplete line — avoid spinning

        const QString smsText = ExtractCmgrBody(
            SendATCommand(QString("AT+CMGR=%1").arg(smsIndex), 3000));

        if (!smsText.isEmpty())
            ProcessOTPSms(smsText);
        else
            qWarning() << "[KMS] SMS body empty, idx" << smsIndex;

        SendATCommand(QString("AT+CMGD=%1").arg(smsIndex), AT_PURGE_TIMEOUT_MS);
    }

    // Keep the buffer bounded (URC text without a SOF would otherwise
    // accumulate forever).
    if (m_gsmBuffer.size() > 2048)
        m_gsmBuffer = m_gsmBuffer.right(512);
}

// ============================================================
//  Process OTP from SMS
//
//  ICD §D.8.3 — 0x96 OTP Message:
//    ELU builds this from the SMS content and sends to VC.
// ============================================================

void EventLoggerKMS::ProcessOTPSms(const QString &smsText)
{
    QString otp;
    quint8  simID = KMS_SIM_PRIMARY;

    if (!ExtractOTPFromSMS(smsText, otp, simID))
    {
        qWarning() << "[KMS] OTP extraction FAILED, SMS:" << smsText;
        ReportFailureToVC(KMS_FAIL_SMS_OTP, 0);
        return;
    }

    otp = otp.trimmed();

    const QByteArray otpPacket = BuildOTPPacket(m_ucKavachUnitType,
                                                m_ucKavachUnitID,
                                                simID,
                                                otp);

    // Send OTP to VC immediately (< 2000ms requirement)
    ForwardToVC(otpPacket);

    qInfo() << "[KMS] OTP → VC sent, SIM" << QString::number(simID, 16);

    // Stop OTP wait state
    m_bWaitingForOTP = false;

    if (m_pOTPPollTimer)
        m_pOTPPollTimer->stop();
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

    const int crcStart = pkt.size();  // CRC covers from here

    // Message Type
    pkt.append(static_cast<char>(KMS_MSG_OTP));  // 0x96

    // Message Length: Date(3)+Time(3)+UnitType(1)+UnitID(3)+SIM(1)+OTP(4)+CRC(4) = 19
    const quint16 msgLenBE = qToBigEndian<quint16>(19);
    pkt.append(reinterpret_cast<const char*>(&msgLenBE), 2);

    // Date: YY/MM/DD, Time: HH/MM/SS (IST)
    const QDateTime now = QDateTime::currentDateTime();
    pkt.append(static_cast<char>(now.date().year() % 100));
    pkt.append(static_cast<char>(now.date().month()));
    pkt.append(static_cast<char>(now.date().day()));
    pkt.append(static_cast<char>(now.time().hour()));
    pkt.append(static_cast<char>(now.time().minute()));
    pkt.append(static_cast<char>(now.time().second()));

    pkt.append(static_cast<char>(ucKavachUnitType));
    pkt.append(reinterpret_cast<const char*>(ucKavachUnitID), 3);
    pkt.append(static_cast<char>(ucSIMID));

    // OTP — 4 bytes, alphanumeric, pad with 0x00 if shorter
    QByteArray otpBytes = strOTP.toLatin1().left(4);
    while (otpBytes.size() < 4)
        otpBytes.append('\0');
    pkt.append(otpBytes);

    AppendCRC32(pkt, crcStart);

    KMS_DBG << "[KMS] Built 0x96 OTP packet:" << pkt.toHex().toUpper();
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

    const int crcStart = pkt.size();

    pkt.append(static_cast<char>(KMS_MSG_COMM_FAILURE));  // 0x97

    // Message Length: Date(3)+Time(3)+UnitType(1)+UnitID(3)+SIM(1)+FailCode(1)+Retry(1)+CRC(4) = 17
    const quint16 msgLenBE = qToBigEndian<quint16>(17);
    pkt.append(reinterpret_cast<const char*>(&msgLenBE), 2);

    const QDateTime now = QDateTime::currentDateTime();
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

    KMS_DBG << "[KMS] Built 0x97 failure packet: code ="
            << QString::number(ucFailureCode, 16)
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
    const quint8 simID = ActiveChannel().ucSimID;

    qWarning() << "[KMS] 0x97 failure code" << QString::number(failureCode, 16)
               << "→ VC";

    const QByteArray failPacket = BuildCommFailurePacket(m_ucKavachUnitType,
                                                         m_ucKavachUnitID,
                                                         simID,
                                                         failureCode,
                                                         retryCount);
    ForwardToVC(failPacket);

    // ICD §D.11: On communication failure, VC initiates channel changeover.
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
    static const QRegularExpression otpRe(
        "[A-Z0-9]+:([A-Za-z0-9]{4})(?:\\s|$)",
        QRegularExpression::CaseInsensitiveOption);

    QRegularExpressionMatch match = otpRe.match(smsText);

    if (!match.hasMatch())
    {
        // Fallback: "OTP: XXXX"
        static const QRegularExpression fallbackRe(
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

    const QString lower = smsText.toLower();
    simIDOut = (lower.contains("sim2") || lower.contains("secondary"))
                   ? KMS_SIM_SECONDARY
                   : KMS_SIM_PRIMARY;

    return true;
}

// ============================================================
//  GPRS / PDP helpers
// ============================================================

bool EventLoggerKMS::IsPDPActive()
{
    return SendATCommand("AT+CGACT?", 1500).contains("+CGACT: 1,1");
}

bool EventLoggerKMS::EnsureGPRSActive()
{
    if (IsPDPActive())
        return true;

    qInfo() << "[KMS] Activating GPRS...";

    SendATCommand(QString("AT+CGDCONT=1,\"IP\",\"%1\"").arg(KMS_APN),
                  AT_CFG_TIMEOUT_MS);

    const QString resp = SendATCommand("AT+CGACT=1,1", AT_PDP_TIMEOUT_MS);

    if (!resp.contains("OK"))
    {
        qWarning() << "[KMS] GPRS activation FAILED:" << resp;
        return false;
    }

    // Confirm the session is really up (replaces the old fixed 2 s sleep:
    // normally the first query already succeeds).
    for (int i = 0; i < 5; ++i)
    {
        if (IsPDPActive())
        {
            qInfo() << "[KMS] GPRS active";
            return true;
        }
        QThread::msleep(200);
    }

    qWarning() << "[KMS] GPRS activation reported OK but session not active";
    return false;
}

// ============================================================
//  CSQ Signal Strength
// ============================================================

int EventLoggerKMS::QueryCSQ()
{
    const QString resp = SendATCommand("AT+CSQ", AT_QUERY_TIMEOUT_MS);

    static const QRegularExpression re("\\+CSQ:\\s*(\\d+),");
    const QRegularExpressionMatch match = re.match(resp);

    if (!match.hasMatch())
    {
        KMS_DBG << "[KMS][CSQ] parse failed, resp:" << resp;
        return -1;
    }

    return match.captured(1).toInt();   // 99 = no signal / antenna missing
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

// ============================================================
//  SlotPollCSQ — periodic GSM health (SIM / network / signal / data)
//
//  Also brings the data session (PDP) up once the network is
//  registered, rate-limited to one attempt per PDP_RETRY_INTERVAL_MS.
// ============================================================

void EventLoggerKMS::SlotPollCSQ()
{
    if (!m_bModemReady)
        return;

    // --- SIM ---
    m_bGSMSimOk = CheckSIMReady();

    if (!m_bGSMSimOk)
    {
        m_bGSMNetworkOk  = false;
        m_bGSMSignalOk   = false;
        m_bGSMRegistered = false;
        m_ucGSMStatus    = 0;

        if (m_iLastHealthKey != 0)
        {
            m_iLastHealthKey = 0;
            qWarning() << "[KMS][HEALTH] FAULT — SIM not ready / not inserted";
        }

        EvaluateAndUpdateGSMLed();
        return;
    }

    // --- Network ---
    m_bGSMNetworkOk  = CheckNetworkRegistered();
    m_bGSMRegistered = m_bGSMNetworkOk;

    // --- Signal ---
    const int csq = QueryCSQ();
    m_iLastCSQ = csq;
    const KMSSignalQuality quality = ClassifyCSQ(csq);

    m_bGSMSignalOk = (quality == KMSSignalQuality::Excellent ||
                      quality == KMSSignalQuality::Good      ||
                      quality == KMSSignalQuality::OK);

    // --- ICD 0xA2 field: 0 = Not ready, 1 = Registered, 2 = Data active ---
    if (!m_bGSMNetworkOk)
    {
        m_ucGSMStatus = 0;
    }
    else if (!m_bGSMSignalOk)
    {
        m_ucGSMStatus = 1;
    }
    else
    {
        bool dataUp = IsPDPActive();

        if (!dataUp &&
            (!m_bPdpTried || m_pdpClock.elapsed() >= PDP_RETRY_INTERVAL_MS))
        {
            m_bPdpTried = true;
            m_pdpClock.restart();
            dataUp = EnsureGPRSActive();
        }

        m_ucGSMStatus = dataUp ? 2 : 1;
    }

    // One log line, only when something changed
    const int healthKey = 0x100
                          | (m_bGSMNetworkOk ? 1 : 0)
                          | (m_bGSMSignalOk  ? 2 : 0)
                          | (m_ucGSMStatus << 2);

    if (healthKey != m_iLastHealthKey)
    {
        m_iLastHealthKey = healthKey;

        qInfo() << "[KMS][HEALTH] SIM: OK"
                << "| NETWORK:" << (m_bGSMNetworkOk ? "OK" : "FAIL")
                << "| SIGNAL:" << (m_bGSMSignalOk ? "OK" : "FAIL")
                << "| CSQ:" << csq << "(" << SignalQualityString(quality) << ")"
                << "| DATA:" << (m_ucGSMStatus == 2 ? "ACTIVE" : "DOWN");
    }

    emit SigCSQUpdated(csq, quality);

    // 0x97 to VC on bad signal — unchanged behaviour
    if (quality == KMSSignalQuality::Marginal ||
        quality == KMSSignalQuality::Unreachable ||
        quality == KMSSignalQuality::Unknown)
    {
        const QByteArray failPkt = BuildCommFailurePacket(m_ucKavachUnitType,
                                                          m_ucKavachUnitID,
                                                          ActiveChannel().ucSimID,
                                                          KMS_FAIL_SIGNAL_THRESHOLD,
                                                          0);
        ForwardToVC(failPkt);
    }

    EvaluateAndUpdateGSMLed();
}

bool EventLoggerKMS::CheckSIMReady()
{
    const QString resp = SendATCommand("AT+CPIN?", AT_QUERY_TIMEOUT_MS);
    return resp.contains("+CPIN: READY");
}

// ============================================================
//  GSM network registration check (CREG, then CGREG / CEREG)
// ============================================================

bool EventLoggerKMS::CheckNetworkRegistered()
{
    static const char *const cmds[] = { "AT+CREG?", "AT+CGREG?", "AT+CEREG?" };

    for (const char *cmd : cmds)
    {
        const QString resp = SendATCommand(cmd, AT_QUERY_TIMEOUT_MS);
        if (resp.contains(",1") || resp.contains(",5"))
            return true;
    }

    return false;
}

// ============================================================
//  CommandGSMLed
//
//  ACTIVE (good)  -> GPIO16 held steady HIGH  : AT+UGPIOC=16,0,1
//  FAULT  (bad)   -> GPIO16 blinked in software by toggling
//                     AT+UGPIOC=16,0,1 / AT+UGPIOC=16,0,0 on a timer.
//
//  Only acts on an actual state change.
// ============================================================
void EventLoggerKMS::CommandGSMLed(bool bActive)
{
    const GsmLedState want = bActive ? GsmLedState::Active
                                     : GsmLedState::Blinking;

    if (want == m_eGSMLedState)
        return;   // already in that state, nothing to do

    if (bActive)
    {
        if (m_pLedBlinkTimer && m_pLedBlinkTimer->isActive())
            m_pLedBlinkTimer->stop();

        m_bLedBlinkPinHigh = true;
        SendATCommand("AT+UGPIOC=16,0,1", 1000);
        qInfo() << "[KMS] GSM LED -> ACTIVE";
    }
    else
    {
        m_bLedBlinkPinHigh = false;
        if (m_pLedBlinkTimer)
            m_pLedBlinkTimer->start(KMS_LED_BLINK_INTERVAL_MS);

        qInfo() << "[KMS] GSM LED -> BLINK (fault)";
    }

    m_eGSMLedState = want;
}

// ============================================================
//  SlotBlinkGSMLed
//
//  Fires every KMS_LED_BLINK_INTERVAL_MS while m_eGSMLedState is
//  Blinking. Toggles GPIO16 High/Low via AT+UGPIOC.
// ============================================================
void EventLoggerKMS::SlotBlinkGSMLed()
{
    if (m_eGSMLedState != GsmLedState::Blinking)
    {
        if (m_pLedBlinkTimer)
            m_pLedBlinkTimer->stop();
        return;
    }

    // Nothing to toggle until the modem has finished bring-up
    if (!m_bModemReady)
        return;

    m_bLedBlinkPinHigh = !m_bLedBlinkPinHigh;

    SendATCommand(m_bLedBlinkPinHigh ? "AT+UGPIOC=16,0,1"
                                     : "AT+UGPIOC=16,0,0", 500);
}

// ============================================================
//  EvaluateAndUpdateGSMLed
//
//  LED is ACTIVE (steady HIGH) only when SIM + Network + Signal
//  are all OK. Any one failing -> BLINK (software toggle).
// ============================================================
void EventLoggerKMS::EvaluateAndUpdateGSMLed()
{
    m_bGSMOverallOk =
        m_bGSMSimOk &&
        m_bGSMNetworkOk &&
        m_bGSMSignalOk;

    emit SigGSMHealthStatus(m_bGSMOverallOk);

    CommandGSMLed(m_bGSMOverallOk);
}