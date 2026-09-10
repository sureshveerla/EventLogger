#include "include/nmsUDPServer.h"

nmsUDPServer::nmsUDPServer(QString strCfgFilePath, QObject *pcParent)
    :QObject(pcParent),m_ocaddressList(NULL),m_strCfgFilPath(strCfgFilePath),
    m_pcKMS(nullptr), m_pcKMSSocket(nullptr)
{
    Init();
    m_pcClntSock = new QUdpSocket();

    m_pcKavachPktHndlr = new KavachPktHandler;
    m_pcKavachPktHndlr->start();
    connect(m_pcKavachPktHndlr,SIGNAL(SigStationConnStatus()),this,SLOT(StationConnStatus()));

    InitKMS(); // ICD §D — KMS gateway on port 4447
}

nmsUDPServer::~nmsUDPServer()
{
    if (m_pcKavachPktHndlr)
    {
        m_pcKavachPktHndlr->quit();
        m_pcKavachPktHndlr->wait();
        delete m_pcKavachPktHndlr;
    }
    qDeleteAll(m_lstSockets);
    m_lstSockets.clear();
    delete m_pcClntSock;

    // KMS cleanup
    if (m_pcKMSSocket) { m_pcKMSSocket->close(); delete m_pcKMSSocket; }
}

bool nmsUDPServer::SendPacketViaGSM(const QByteArray &datagram)
{
    if (!m_pcKMS)
    {
        qCritical() << "[GSM Relay] m_pcKMS is NULL";
        return false;
    }

    return m_pcKMS->SendUDPViaGSM(
        datagram,
        m_strGSMRelayIP,
        m_usGSMRelayPort);
}

void nmsUDPServer::Init()
{
    QSettings ocSettings(m_strCfgFilPath, QSettings::IniFormat);

    QList<quint16> portSet;

    // ------------------------------------------------
    // SNTP Port
    // ------------------------------------------------
    portSet.append(123);

    // ------------------------------------------------
    // LOCO PORT
    // ------------------------------------------------
    quint16 locoPort =
        ocSettings.value("Loco/Port", 0).toUInt();

    if(locoPort > 0)
    {
        portSet.append(locoPort);

        qDebug() << "[CONFIG] Loco Port:"
                 << locoPort;
    }

    // ------------------------------------------------
    // NMS PORT
    // ------------------------------------------------
    quint16 nmsPort =
        ocSettings.value("NMS/NMS_Port", 0).toUInt();

    if(nmsPort > 0)
    {
        portSet.append(nmsPort);

        qDebug() << "[CONFIG] NMS Port:"
                 << nmsPort;
    }

    // ------------------------------------------------
    // STATION PORTS
    // ------------------------------------------------
    QStringList groups = ocSettings.childGroups();

    for(const QString &group : groups)
    {
        // Only Station groups
        if(!group.startsWith("Station"))
            continue;

        ocSettings.beginGroup(group);

        quint16 port =
            ocSettings.value("Port", 0).toUInt();

        QString name =
            ocSettings.value("Name", "Unknown").toString();

        QString ip =
            ocSettings.value("IP", "").toString();

        qDebug() << "[CONFIG]"
                 << group
                 << "| Name:" << name
                 << "| IP:" << ip
                 << "| Port:" << port;

        if(port > 0)
        {
            if(!portSet.contains(port))
            {
                portSet.append(port);
            }
        }

        ocSettings.endGroup();
    }

    // ------------------------------------------------
    // CREATE UDP SOCKETS
    // ------------------------------------------------
    for(quint16 port : portSet)
    {
        QUdpSocket *pcsocket =
            new QUdpSocket(this);

        bool bBind =
            pcsocket->bind(QHostAddress::AnyIPv4,
                           port,
                           QUdpSocket::ReuseAddressHint |
                               QUdpSocket::ShareAddress);

        if(bBind)
        {
            connect(pcsocket,
                    &QUdpSocket::readyRead,
                    this,
                    [this, pcsocket]()
                    {
                        SlotOnReadyRead(pcsocket);
                    });

            m_lstSockets.append(pcsocket);

            qDebug() << "[UDP] Listening On Port:"
                     << port;
        }
        else
        {
            qDebug() << "[UDP] Bind Failed Port:"
                     << port
                     << pcsocket->errorString();

            delete pcsocket;
        }
    }

}

void nmsUDPServer::StationConnStatus()
{
    QDateTime now = QDateTime::currentDateTime();

    for (auto it = m_lastPacketTime.begin(); it != m_lastPacketTime.end(); ++it)
    {
        if (it.value().msecsTo(now) > 5000)
        {
            emit SigStationDisConnected(it.key(), false);
            qDebug() << "Station disconnected:" << it.key();

            it.value() = now; // optional: avoid repeat emits
        }
    }
}

// void nmsUDPServer::SendSNTPResponse(QUdpSocket *socket,
//                                     const QHostAddress &clientAddr,
//                                     quint16 clientPort,
//                                     const QByteArray &request)
// {
//     qDebug() << "[NTP] SendSNTPResponse called";
//     qDebug() << "[NTP] m_gpsDateTime valid:" << m_gpsDateTime.isValid()
//              << "value:" << m_gpsDateTime;

//     QByteArray response(48, 0);
//     response[0] = 0x24;
//     response[1] = 1;
//     response[2] = request[2];
//     response[3] = -6;

//     if (request.size() >= 48) {
//         for (int i = 0; i < 8; i++)
//             response[24 + i] = request[40 + i];
//     }

//     QDateTime gpsTime = m_gpsDateTime.isValid()
//                             ? m_gpsDateTime
//                             : QDateTime::currentDateTimeUtc();

//     quint64 unixSec = gpsTime.toSecsSinceEpoch();
//     quint64 ntpTime = unixSec + 2208988800ULL;

//     qDebug() << "[NTP] Unix seconds:" << unixSec
//              << "NTP seconds:" << ntpTime
//              << "Expected year:" << QDateTime::fromSecsSinceEpoch(unixSec).date().year();

//     for (int i = 0; i < 8; i++)
//         response[32 + i] = (ntpTime >> (56 - i * 8)) & 0xFF;

//     for (int i = 0; i < 8; i++)
//         response[40 + i] = (ntpTime >> (56 - i * 8)) & 0xFF;

//     socket->writeDatagram(response, clientAddr, clientPort);
//     qDebug() << "[NTP] Response sent to" << clientAddr;
// }

void nmsUDPServer::SendSNTPResponse(QUdpSocket *socket,
                                    const QHostAddress &clientAddr,
                                    quint16 clientPort,
                                    const QByteArray &request)
{
    QByteArray response(48, 0);

    response[0] = 0x1C;   // NTP server response
    response[1] = m_gpsDateTime.isValid() ? 1 : 2;
    response[2] = request[2];
    response[3] = -20;

    // Copy originate timestamp
    if (request.size() >= 48) {
        memcpy(response.data() + 24, request.data() + 40, 8);
    }

    QDateTime gpsTime = m_gpsDateTime.isValid()
                            ? m_gpsDateTime
                            : QDateTime::currentDateTimeUtc();

    quint64 unixSec = gpsTime.toSecsSinceEpoch();
    quint64 ntpTime = unixSec + 2208988800ULL;

    quint32 seconds = static_cast<quint32>(ntpTime);
    quint32 fraction = static_cast<quint32>((gpsTime.time().msec() / 1000.0) * 0xFFFFFFFF);

    // Receive timestamp (optional, same as transmit here)
    response[32] = (seconds >> 24) & 0xFF;
    response[33] = (seconds >> 16) & 0xFF;
    response[34] = (seconds >> 8) & 0xFF;
    response[35] = seconds & 0xFF;

    response[36] = (fraction >> 24) & 0xFF;
    response[37] = (fraction >> 16) & 0xFF;
    response[38] = (fraction >> 8) & 0xFF;
    response[39] = fraction & 0xFF;

    // Transmit timestamp
    memcpy(response.data() + 40, response.data() + 32, 8);

    socket->writeDatagram(response, clientAddr, clientPort);
}

QDateTime nmsUDPServer::GetGPSTime()
{
    if (!m_gpsDateTime.isValid())
    {
        qDebug() << "GPS not ready - not sending SNTP";
        return QDateTime::currentDateTimeUtc();  // fallback
    }

    return m_gpsDateTime;
}

void nmsUDPServer::SlotUpdateGPSTime(const QDateTime &gpsTime)
{
    qDebug() << "[NTP] Received gpsTime:" << gpsTime
             << "TimeSpec:" << gpsTime.timeSpec()
             << "isValid:" << gpsTime.isValid();

    m_gpsDateTime = gpsTime.toTimeZone(QTimeZone("Asia/Kolkata"));

    qDebug() << "[NTP] Stored m_gpsDateTime (UTC):" << m_gpsDateTime
             << "isValid:" << m_gpsDateTime.isValid()
             << "Unix secs:" << m_gpsDateTime.toSecsSinceEpoch();
}

void nmsUDPServer::SlotOnReadyRead(QUdpSocket *pcsocket)
{
    while (pcsocket->hasPendingDatagrams())
    {
        QByteArray   datagram;
        QHostAddress sender;
        quint16      senderPort;

        datagram.resize(pcsocket->pendingDatagramSize());
        qint64 bytesRead = pcsocket->readDatagram(
            datagram.data(), datagram.size(),
            &sender, &senderPort);

        if (bytesRead <= 0)
            return;

        // ── SNTP ─────────────────────────────────────────────
        if (datagram.size() == 48)
        {
            SendSNTPResponse(pcsocket, sender, senderPort, datagram);
            continue;
        }

        // ── KMS port 4447 → route to KMS handler ONLY ────────
        if (pcsocket->localPort() == 4447)
        {
            qDebug() << "[KMS] RX from VC"
                     << sender.toString()
                     << ":" << senderPort
                     << "size:" << datagram.size()
                     << "data:" << datagram.toHex().toUpper();

            if (m_pcKMS)
                m_pcKMS->SlotHandleUDPFromVC(
                    datagram, sender, senderPort);
            continue;   // ← do NOT fall through to Kavach handler
        }

        // ── All other ports → normal Kavach handling ─────────
        QString senderIp = sender.toString();
        m_lastPacketTime[senderIp] = QDateTime::currentDateTime();
        m_strSenderIP  = senderIp;
        m_usSenderPort = senderPort;

        m_pcKavachPktHndlr->enqueuePacket(
            sender, m_usSenderPort, datagram);

        emit SigConnected(m_strSenderIP, true);

        qDebug() << "Received Packet Rx:"
                 << datagram.toHex().toUpper()
                 << m_strSenderIP << senderPort;
    }
}


// void nmsUDPServer::SlotSendAckNMStoKavach(QByteArray byteArr)
// {
//     QHostAddress stationIP(m_strSenderIP);

//     qint64 sent = m_pcClntSock->writeDatagram(
//         byteArr,
//         stationIP,
//         m_usSenderPort);

//     if(sent == -1)
//     {
//         qDebug() << "UDP Send Failed:" << m_pcClntSock->errorString();
//     }
//     else
//     {
//         qDebug() << "UDP Sent to"
//                  << stationIP
//                  << ":" << m_usSenderPort
//                  << "Size:" << sent
//                  << "Data:" << byteArr.toHex().toUpper();
//     }
// }

void nmsUDPServer::SlotSendAckEventLoggertoKavach(QHostAddress senderIP, quint16 senderPort,stNMStoKavach *pstAck)
{

    qDebug()<<" Acknowledgement Sent to T "<<senderIP<<senderPort;
    QByteArray byteArr(reinterpret_cast<const char*>(pstAck), sizeof(stNMStoKavach));
    m_pcClntSock->writeDatagram(byteArr, senderIP, senderPort);
    qDebug() << "Tx Data:" << byteArr.toHex(' ').toUpper() << senderIP << senderPort;
}


// ============================================================
//  InitKMS  —  ICD §D: KMS Gateway Initialization
//
//  Reads [KMS] from Config.cfg, creates EventLoggerKMS,
//  binds port 4447 socket (0.0.0.0 — all interfaces),
//  wires:
//    KMS socket readyRead    → EventLoggerKMS::SlotHandleUDPFromVC
//    EventLoggerKMS::SigSendToVC → SlotKMSSendToVC
// ============================================================
void nmsUDPServer::InitKMS()
{
    QSettings cfg(m_strCfgFilPath, QSettings::IniFormat);

    qInfo() << "========================================";
    qInfo() << "[KMS] InitKMS() STARTED";
    qInfo() << "[KMS] Config file:" << m_strCfgFilPath;
    qInfo() << "========================================";

    // ── ELU channel IPs (reference, ICD §D.5) ───────────────
    QString eluAIP = cfg.value("KMS/ELU_A_IP").toString();
    QString eluBIP = cfg.value("KMS/ELU_B_IP").toString();
    QString vcIP   = cfg.value("KMS/VC_IP").toString();

    quint16 vcPort = static_cast<quint16>(
        cfg.value("KMS/VC_PORT", 0).toUInt());

    qDebug() << "[KMS] VC IP   :" << vcIP;
    qDebug() << "[KMS] VC Port :" << vcPort;

    if (eluAIP.isEmpty() ||
        eluBIP.isEmpty() ||
        vcIP.isEmpty() ||
        vcPort == 0)
    {
        qCritical()
        << "[KMS] Config.cfg missing required [KMS] entries:"
        << "ELU_A_IP, ELU_B_IP, VC_IP, VC_PORT";

        return;
    }

    // ── RDSO confirmed KMS Server destination ───────────────
    QString kmsServerIP =
        cfg.value("KMS/KMS_SERVER_IP").toString();

    quint16 kmsServerPort =
        static_cast<quint16>(
            cfg.value("KMS/KMS_SERVER_PORT", 0).toUInt());

    qDebug() << "[KMS] KMS Server:"
             << kmsServerIP
             << ":"
             << kmsServerPort;

    if (kmsServerIP.isEmpty() ||
        kmsServerPort == 0)
    {
        qCritical()
        << "[KMS] Config.cfg missing required [KMS] entries:"
        << "KMS_SERVER_IP, KMS_SERVER_PORT";

        return;
    }

    // ── GSM modem ────────────────────────────────────────────
    QString gsmPort =
        cfg.value("KMS/GSM_Port").toString();

    int gsmBaud =
        cfg.value("KMS/GSM_Baud", 0).toInt();

    qDebug() << "[KMS] GSM Port:"
             << gsmPort;

    qDebug() << "[KMS] GSM Baud:"
             << gsmBaud;

    if (gsmPort.isEmpty() ||
        gsmBaud == 0)
    {
        qCritical()
        << "[KMS] Config.cfg missing required [KMS] entries:"
        << "GSM_Port, GSM_Baud";

        return;
    }

    // ── GSM Relay destination ───────────────────────────────
    //
    // This is the Windows public IP + UDP port.
    //
    // EventLogger:
    //     /dev/ttyS2
    //          ↓
    //     LARA-R6801
    //          ↓
    //     GSM/GPRS
    //          ↓
    //     Windows Relay
    //
    m_strGSMRelayIP =
        cfg.value("GSM/RelayIP").toString();

    m_usGSMRelayPort =
        static_cast<quint16>(
            cfg.value("GSM/RelayPort", 0).toUInt());

    qInfo() << "[GSM Relay] Destination:"
            << m_strGSMRelayIP
            << ":"
            << m_usGSMRelayPort;

    if (m_strGSMRelayIP.isEmpty() ||
        m_usGSMRelayPort == 0)
    {
        qCritical()
        << "[GSM Relay] Missing GSM/RelayIP or GSM/RelayPort";

        return;
    }

    // ── KAVACH unit identity ─────────────────────────────────
    bool ok = false;

    quint8 unitType =
        static_cast<quint8>(
            cfg.value("KMS/KAVACH_Unit_Type", "0x11")
                .toString()
                .toUInt(&ok, 16));

    QByteArray idBytes =
        QByteArray::fromHex(
            cfg.value("KMS/KAVACH_Unit_ID", "000001")
                .toString()
                .toLatin1());

    while (idBytes.size() < 3)
        idBytes.prepend('\0');

    quint8 unitID[3];

    memcpy(unitID,
           idBytes.constData(),
           3);

    // ── Build channel A configuration ───────────────────────
    KMSChannelConfig chanA;

    chanA.strLocalIP =
        eluAIP;

    chanA.strVCIP =
        vcIP;

    chanA.usPort =
        vcPort;

    chanA.strKMSServerIP =
        kmsServerIP;

    chanA.usKMSServerPort =
        kmsServerPort;

    chanA.ucSimID =
        KMS_SIM_PRIMARY;

    chanA.bActive =
        true;

    // ── Build channel B configuration ───────────────────────
    KMSChannelConfig chanB;

    chanB.strLocalIP =
        eluBIP;

    chanB.strVCIP =
        vcIP;

    chanB.usPort =
        vcPort;

    chanB.strKMSServerIP =
        kmsServerIP;

    chanB.usKMSServerPort =
        kmsServerPort;

    chanB.ucSimID =
        KMS_SIM_SECONDARY;

    chanB.bActive =
        false;

    // ── Create EventLoggerKMS ────────────────────────────────
    qInfo() << "[KMS] All configuration checks passed";
    qInfo() << "[KMS] Creating EventLoggerKMS...";

    m_pcKMS =
        new EventLoggerKMS(this);

    if (!m_pcKMS)
    {
        qCritical()
        << "[KMS] FAILED to create EventLoggerKMS";

        return;
    }

    qInfo() << "[KMS] EventLoggerKMS created:"
            << static_cast<void *>(m_pcKMS);

    // ── Configure KAVACH identity ───────────────────────────
    m_pcKMS->SetKavachUnitInfo(
        unitType,
        unitID);

    // ── Initialize GSM/KMS module ───────────────────────────
    qInfo() << "[KMS] Initializing EventLoggerKMS...";
    qInfo() << "[KMS] GSM:"
            << gsmPort
            << "@"
            << gsmBaud;

    m_pcKMS->Init(
        chanA,
        chanB,
        gsmPort,
        gsmBaud);

    qInfo() << "[KMS] EventLoggerKMS initialization complete";

    // ── Bind UDP socket to 0.0.0.0:vcPort ───────────────────
    m_pcKMSSocket =
        new QUdpSocket(this);

    if (!m_pcKMSSocket->bind(
            QHostAddress::Any,
            vcPort,
            QUdpSocket::ShareAddress |
                QUdpSocket::ReuseAddressHint))
    {
        qCritical()
        << "[KMS] Vital Controller FAILED to bind port"
        << vcPort
        << "-"
        << m_pcKMSSocket->errorString();

        return;
    }

    qInfo()
        << "[KMS] Vital Controller UDP socket bound on port"
        << vcPort;

    qInfo()
        << "[KMS] KMS Server configured:"
        << kmsServerIP
        << ":"
        << kmsServerPort;

    // ── RECEIVE: VC → ELU ───────────────────────────────────
    connect(
        m_pcKMSSocket,
        &QUdpSocket::readyRead,
        this,
        [this]()
        {
            while (m_pcKMSSocket->hasPendingDatagrams())
            {
                QByteArray dg;

                QHostAddress senderAddr;
                quint16 senderPort = 0;

                dg.resize(
                    static_cast<int>(
                        m_pcKMSSocket->pendingDatagramSize()));

                m_pcKMSSocket->readDatagram(
                    dg.data(),
                    dg.size(),
                    &senderAddr,
                    &senderPort);

                qDebug()
                    << "[KMS] RX from VC"
                    << senderAddr.toString()
                    << ":"
                    << senderPort
                    << "size:"
                    << dg.size()
                    << "data:"
                    << dg.toHex().toUpper();

                if (m_pcKMS)
                {
                    m_pcKMS->SlotHandleUDPFromVC(
                        dg,
                        senderAddr,
                        senderPort);
                }
                else
                {
                    qCritical()
                    << "[KMS] m_pcKMS is NULL while receiving VC packet";
                }
            }
        });

    // ── SEND: ELU → VC ──────────────────────────────────────
    connect(
        m_pcKMS,
        &EventLoggerKMS::SigSendToVC,
        this,
        &nmsUDPServer::SlotKMSSendToVC);

    qInfo()
        << "[KMS] Init complete"
        << "| ELU-A:" << eluAIP
        << "| ELU-B:" << eluBIP
        << "| VC:" << vcIP << ":" << vcPort
        << "| KMS Server:" << kmsServerIP << ":" << kmsServerPort
        << "| GSM Relay:" << m_strGSMRelayIP << ":" << m_usGSMRelayPort;

    qInfo()
        << "[KMS] FINAL m_pcKMS:"
        << static_cast<void *>(m_pcKMS);

    qInfo() << "========================================";
    qInfo() << "[KMS] InitKMS() FINISHED";
    qInfo() << "========================================";
}

// ============================================================
//  SlotKMSSendToVC  —  ICD §D.9 (forward to VC within 2000ms)
// ============================================================
void nmsUDPServer::SlotKMSSendToVC(QByteArray   packet,
                                   QHostAddress vcAddr,
                                   quint16      vcPort)
{
    qDebug()<< "Vital Computer Ip and Port : " << vcAddr << vcPort;


    if (!m_pcKMSSocket) return;

    if (vcAddr.isNull() || vcAddr == QHostAddress::Any)
    {
        QSettings cfg(m_strCfgFilPath, QSettings::IniFormat);
        QString vcIPStr = cfg.value("KMS/VC_IP").toString();
        quint16 vcPortCfg = static_cast<quint16>(cfg.value("KMS/VC_PORT", 0).toUInt());
        if (vcIPStr.isEmpty() || vcPortCfg == 0)
        {
            qCritical() << "[KMS] SlotKMSSendToVC: VC_IP/VC_PORT not set in Config.cfg — dropping packet";
            return;
        }
        vcAddr = QHostAddress(vcIPStr);
        vcPort = vcPortCfg;
    }

    quint8  msgType = (packet.size() >= 3) ? static_cast<quint8>(packet[2]) : 0;
    qint64  sent    = m_pcKMSSocket->writeDatagram(packet, vcAddr, vcPort);

    if (sent < 0)
        qCritical() << "[KMS] TX FAILED MsgType:" << Qt::hex << msgType
                    << "to VC" << vcAddr.toString() << ":" << vcPort
                    << m_pcKMSSocket->errorString();
    else
        qInfo()    << "[KMS] TX OK MsgType:" << Qt::hex << msgType
                << "size:" << sent
                << "to VC" << vcAddr.toString() << ":" << vcPort;

    qDebug()<< "Vital Computer Ip and Port : " << vcAddr << vcPort;
}