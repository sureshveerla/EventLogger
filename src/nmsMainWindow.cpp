#include "nmsMainWindow.h"
#include <any>

nmsMainWindow::nmsMainWindow(QString strCFGFilePath, QObject *pcParent)
    : QObject(pcParent),m_pcDB(NULL),m_pcKavachHandler(NULL),m_pcReceivedData(NULL),
    m_strLastPkt("Not Received"),m_strFaultMsg("\0"),
    m_bStnHlthSts(false),m_strCfgFilePath(strCFGFilePath),m_strSMSpwd("\0"),
    m_pcKMS(nullptr),
    m_pcPingThread(nullptr),
    m_pcPingTimer(nullptr),
    m_pcReplayTimer(nullptr),
    m_bNMSOffline(false),
    m_bNMSAppDown(false),
    m_pcVCTimer(nullptr),
    m_pcVCSock(nullptr),m_pcFaultpkt(nullptr)
{
    InitCFGFile();
    Init();
    InitUDP();
    InitDB();
    InitnmsDBConnections();
    ComputeEVLAppCRC();
    InitLogFile();
    InitKavachParsePkt();
    InitNMSForwarder();
    InitGSMRelay();
    InitNMSPingThread();
    InitVCHeartbeat();
}

nmsMainWindow::~nmsMainWindow()
{

}

void nmsMainWindow::Init()
{

}

void nmsMainWindow::ProcessFieldInputmessage(QHostAddress senderIP, QByteArray datagram)
{
    QString strIP = senderIP.toString();
    QString strIPAddr = strIP.section("::ffff:",1,1);

    qDebug() << "Name...." << strIPAddr;

    QString strStationName = m_ipToStationMap.value(strIPAddr, nullptr);
    qDebug() << "Name....????" << strIPAddr << strStationName;


    m_strLastPkt = NULL;
    m_strLastPkt = "S -> FIP";

    if (datagram.size() < sizeof(stPacketHeader))
    {
        qWarning() << "Datagram too small for header";
        return;
    }
    stPacketHeader stPktHdr;
    memcpy(&stPktHdr, datagram.constData(), sizeof(stPacketHeader));

    stPktHdr.usStartFrame = qFromBigEndian(stPktHdr.usStartFrame);
    stPktHdr.usMsgLength  = qFromBigEndian(stPktHdr.usMsgLength);
    stPktHdr.usStatKavachID = qFromBigEndian(stPktHdr.usStatKavachID);
    stPktHdr.usNMSID      = qFromBigEndian(stPktHdr.usNMSID);

    int offset = sizeof(stPacketHeader);

    if (datagram.size() < offset + 2)
    {
        qWarning() << "Payload too short to read relay count.";
        return;
    }

    quint16 relayCount = qFromBigEndian<quint16>(reinterpret_cast<const uchar *>(datagram.constData() + offset));
    offset += 2;
    int relayBytes = (relayCount + 7) / 8;

    if (datagram.size() < offset + relayBytes)
    {
        qWarning() << "Incomplete Relay Status Image. Needed:" << relayBytes << ", got:" << datagram.size() - 2;
        return;
    }

    const uint8_t *relayImage = reinterpret_cast<const uint8_t *>(datagram.constData() + offset);
    offset += relayBytes;

    // --------------------------- CRC32 ---------------------------
    if (datagram.size() < offset + 4) {
        qWarning() << "Datagram missing CRC32";
        return;
    }

    uint32_t recvCRC = qFromBigEndian<uint32_t>(reinterpret_cast<const uchar*>(datagram.constData() + offset));


    // Print each relay
    QTextStream write(&m_pcStationLogFile);

    write << "---- Field Input Packet Received:------ " << "\n"
          << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << " ----\n";

    for (int i = 0; i < relayCount; ++i)
    {
        int byteIndex = i / 8;
        int bitIndex = i % 8;
        bool isPickup = (relayImage[byteIndex] >> bitIndex) & 0x01;

        qDebug() << "Relay" << i << ":" << (isPickup ? "Pickup" : "Drop");

        write << "  Relay" << i << ":" << (isPickup ? "Pickup" : "Drop") << "\n";
    }
    write << "----------------------------------------------------------\n";

    write.flush();

    for (int byteIndex = 0; byteIndex < relayBytes; ++byteIndex)
    {
        quint8 relayByte = relayImage[byteIndex];
        int baseBitIndex = byteIndex * 8;

    }

    QByteArray relayByteArray(reinterpret_cast<const char*>(relayImage), relayBytes);
    emit SigInsertDBFieldInputStatus(stPktHdr,relayCount,relayByteArray,recvCRC);
}

void nmsMainWindow::InitCFGFile()
{
    m_ocCfgSettings = new QSettings(m_strCfgFilePath,QSettings::IniFormat);

    for (const QString &group : m_ocCfgSettings->childGroups())
    {
        m_ocCfgSettings->beginGroup(group);

        QString ip   = m_ocCfgSettings->value("IP").toString();
        QString name = m_ocCfgSettings->value("Name").toString();
        QString port = m_ocCfgSettings->value("Port").toString();

        if (!ip.isEmpty() && !name.isEmpty())
        {
            m_ipToStationMap[ip] = name;
            qDebug() << "Loaded station:" << ip << "->" << name << "Port : "<<port;
        }

        m_ocCfgSettings->endGroup();
    }
}

void nmsMainWindow::ProcessFieldEventMessage(QByteArray datagram)
{
    m_strLastPkt = NULL;
    m_strLastPkt = "S -> Field Event Data";

    if (datagram.size() < sizeof(stFieldEventData))
    {
        qWarning() << "Datagram too small for header";
        return;
    }
    stFieldEventData stFldEvntData;
    memcpy(&stFldEvntData, datagram.constData(), sizeof(stFieldEventData));

    stFldEvntData.usStartFrame = qFromBigEndian(stFldEvntData.usStartFrame);
    stFldEvntData.usMsgLength  = qFromBigEndian(stFldEvntData.usMsgLength);
    stFldEvntData.usStatKavachID = qFromBigEndian(stFldEvntData.usStatKavachID);
    stFldEvntData.usNMSID      = qFromBigEndian(stFldEvntData.usNMSID);

    emit SigInsertDBFieldInputEventData(stFldEvntData);
}

void nmsMainWindow::ProcessAccessAuthorityPacket(QByteArray datagram)
{

    const int headerSize = sizeof(stAccessRequestPkt);
    const int footerSize = 4;           // 4 bytes CRC
    const int requiredBits = 208;       // Total bits required for decoding fields
    const int requiredBytes = (requiredBits + 4) / 8;  // ceil(194 / 8) = 25 bytes
    const int minPacketSize = headerSize + requiredBytes + footerSize;

    const int AddEmrgBits = 104;
    const int AddEmrgBytes = (AddEmrgBits + 4) / 8;
    const int AddEmrgPacketSize = headerSize + AddEmrgBytes + footerSize;

    if ((datagram.size() < headerSize + footerSize))
    {
        qWarning() << "[Schematic] Datagram too short. Received:" << datagram.size()
        << "Expected minimum:" << minPacketSize;
        return;
    }

    memcpy(&m_stHeader, datagram.constData(), sizeof(m_stHeader));
    m_stHeader.usStartFrame = qFromBigEndian(m_stHeader.usStartFrame);
    m_stHeader.usMsgLength  = qFromBigEndian(m_stHeader.usMsgLength);
    m_stHeader.usStatKavachID = qFromBigEndian(m_stHeader.usStatKavachID);
    m_stHeader.usNMSID      = qFromBigEndian(m_stHeader.usNMSID);

    int offset = sizeof(stAccessRequestPkt);
    int remaining = datagram.size() - offset;
    if (remaining < (4))
    {
        qWarning() << "Packet too short for footer";
        return;
    }

    int txBufferLen = remaining - (4);  // subtract footer

    QByteArray txBuffer = datagram.mid(offset, txBufferLen);
    offset += txBufferLen;

    QVector<bool> bits;
    for (const auto &byte : txBuffer)
    {
        quint8 ubyte = static_cast<quint8>(byte);
        for (int b = 7; b >= 0; --b)
            bits.append((ubyte >> b) & 0x01);
    }

    uint32_t crc = qFromBigEndian<uint32_t>(reinterpret_cast<const uchar *>(datagram.constData() + offset));

    int idx = 0;

    uint32_t pkt_type             = ExtractBits(bits, idx, 4);

    uint32_t pkt_length = 0, frame_num = 0, uiSrc_Stn_ILC_IBS_ID = 0,
        uiSrc_STn_ILC_IBS_Ver =0,uiStn_ILC_IBS_Loc = 0,
        uiDest_Loco_ID = 0, uiAlotUpLinkFreq = 0, uiAlotDownLinkFreq = 0,
        uiAlotTDMA_Timeslots = 0, uiStnRndNum = 0,
        uiStn_TDMA = 0,uiMACCode =0, uiGen_SOS_Call = 0, uiPktCRC = 0;

    if(pkt_type == enmAccessAuthorityPkt)
    {
        m_strLastPkt = NULL;
        m_strLastPkt = "S -> Auth";
        pkt_length           = ExtractBits(bits, idx, 7);
        frame_num            = ExtractBits(bits, idx, 17);
        uiSrc_Stn_ILC_IBS_ID  = ExtractBits(bits, idx, 16);
        uiSrc_STn_ILC_IBS_Ver  = ExtractBits(bits, idx, 3);
        uiStn_ILC_IBS_Loc         = ExtractBits(bits, idx, 23);
        uiDest_Loco_ID         = ExtractBits(bits, idx, 20);
        uiAlotUpLinkFreq          = ExtractBits(bits, idx, 12);
        uiAlotDownLinkFreq       = ExtractBits(bits, idx, 12);
        uiAlotTDMA_Timeslots     = ExtractBits(bits, idx, 7);
        uiStnRndNum            = ExtractBits(bits, idx, 16);
        uiStn_TDMA = ExtractBits(bits, idx, 7);
        uiMACCode        = ExtractBits(bits, idx, 32);
        uiPktCRC         = ExtractBits(bits, idx, 32);

        emit SigAccessAuthorityPktInsertintoDB(m_stHeader,pkt_type,pkt_length,frame_num,
                                               uiSrc_Stn_ILC_IBS_ID,uiSrc_STn_ILC_IBS_Ver,
                                               uiStn_ILC_IBS_Loc,uiDest_Loco_ID,uiAlotUpLinkFreq,
                                               uiAlotDownLinkFreq,uiAlotTDMA_Timeslots,
                                               uiStnRndNum,uiStn_TDMA,uiMACCode,uiPktCRC,crc);
    }
    else if(pkt_type == enmAdditionalEmergencyPkt)
    {
        m_strLastPkt = "S -> AddEmrgPkt";

        qDebug() << "Emergency" << enmAdditionalEmergencyPkt;

        pkt_length           = ExtractBits(bits, idx, 7);
        frame_num            = ExtractBits(bits, idx, 17);
        uiSrc_Stn_ILC_IBS_ID  = ExtractBits(bits, idx, 16);
        uiSrc_STn_ILC_IBS_Ver  = ExtractBits(bits, idx, 3);
        uiStn_ILC_IBS_Loc         = ExtractBits(bits, idx, 23);
        uiGen_SOS_Call         = ExtractBits(bits,idx, 1);

        emit SigAdditionalEmergencyPktInsertintoDB(m_stHeader,pkt_type,pkt_length,frame_num,
                                                   uiSrc_Stn_ILC_IBS_ID,uiSrc_STn_ILC_IBS_Ver,
                                                   uiStn_ILC_IBS_Loc,uiGen_SOS_Call,crc);
    }
    else if(pkt_type = enmStnToOnBoardRegPkt)
    {
        m_strLastPkt = "S -> StnRegPkt";

        int payloadLen = datagram.size() - (headerSize + footerSize);

        QByteArray payload = QByteArray::fromRawData(datagram.constData() + headerSize, payloadLen);

        // Example: read payload bytes one by one
        for (int i = 0; i < payload.size(); ++i) {
            quint8 byte = static_cast<quint8>(payload[i]);
            qDebug().nospace() << "Byte[" << i << "]=" << QString::number(byte, 16).rightJustified(2, '0');
        }
        m_pcKavachParseData->parseIncomingPacket(payload);

        uint32_t uicrc = qFromBigEndian<uint32_t>(reinterpret_cast<const uchar *>(datagram.constData() + offset));
        m_uicrc = uicrc;
    }

    if (m_pcStationLogFile.isOpen())
    {
        QTextStream write(&m_pcStationLogFile);

        write << "---- Authority Packet Received:------ " << "\n";

        write << "  StartFrame: " << QString("0x%1").arg(m_stHeader.usStartFrame, 4, 16, QChar('0')).toUpper()<< "\n"
              << "  MsgType: " << QString("0x%1").arg(m_stHeader.ucMsgType, 2, 16, QChar('0')).toUpper()<< "\n"
              << "  MsgLength: " << m_stHeader.usMsgLength<< "\n"
              << "  MsgSeq:" << m_stHeader.usMsgSeq<< "\n"
              << "  KavachID: " << m_stHeader.usStatKavachID<< "\n"
              << "  NMSID: " << m_stHeader.usNMSID << "\n"
              << "  version   : " << m_stHeader.ucVersion << "\n"
              << "  Date: " << m_stHeader.ucDate << "\n"
              << "  Time: " << m_stHeader.ucTime << "\n"
              << "  Nma Active Radio: " << m_stHeader.ucRadioType << "\n"
              << "  SOF_tx_Byte1: " << m_stHeader.ucSOF1 << "\n"
              << "  SOF_tx_Byte2: " << m_stHeader.ucSOF2 << "\n"

              << "  pkt_type: " << pkt_type<< "\n"
              << "  pkt_length: " << pkt_length<< "\n"
              << "  frame_num: " << frame_num<< "\n"
              << "  uiSrc_Stn_ILC_IBS_ID: " << uiSrc_Stn_ILC_IBS_ID<< "\n"
              << "  uiSrc_STn_ILC_IBS_Ver: " << uiSrc_STn_ILC_IBS_Ver<< "\n"
              << "  uiStn_ILC_IBS_Loc: " << uiStn_ILC_IBS_Loc<< "\n"
              << "  uiDest_Loco_ID: " << uiDest_Loco_ID<< "\n"
              << "  uiAlotUpLinkFreq: " << uiAlotUpLinkFreq<< "\n"
              << "  uiAlotDownLinkFreq: " << uiAlotDownLinkFreq<< "\n"
              << "  uiAlotTDMA_Timeslots: " << uiAlotTDMA_Timeslots << "\n"
              << "  uiStnRndNum: " << uiStnRndNum<< "\n"
              << "  uiStn_TDMA: " << uiStn_TDMA<< "\n"
              << "  uiMACCode:" <<uiMACCode<< "\n"
              << "  CRC: " << crc << "\n";

        write << "----------------------------------------------------------\n";

        write.flush();   // ensures it’s written immediately
    }
    else
    {
        qWarning() << "Station log file not open!";
    }

}

void nmsMainWindow::ProcessStationFaultPkt(QByteArray datagram)
{
    qDebug() << "================================================";
    qDebug() << "[FaultPkt] RX:"
             << datagram.toHex(' ').toUpper();

    quint16 startFrame =
        (static_cast<quint16>(
             static_cast<quint8>(datagram[0])) << 8) |
        static_cast<quint16>(
            static_cast<quint8>(datagram[1]));

    // Message Sequence
    quint16 msgSeq =
        (static_cast<quint16>(static_cast<quint8>(datagram[5])) << 8) |
        static_cast<quint16>(static_cast<quint8>(datagram[6]));

    // KAVACH ID - 3 bytes
    quint32 kavachID =
        (static_cast<quint32>(static_cast<quint8>(datagram[7])) << 16) |
        (static_cast<quint32>(static_cast<quint8>(datagram[8])) << 8) |
        static_cast<quint32>(static_cast<quint8>(datagram[9]));

    // NMS ID
    quint16 nmsID =
        (static_cast<quint16>(static_cast<quint8>(datagram[10])) << 8) |
        static_cast<quint16>(static_cast<quint8>(datagram[11]));

    // KAVACH Type
    quint8 kavachType =
        static_cast<quint8>(datagram[19]);

    // Total Faults
    quint8 totalFaults =
        static_cast<quint8>(datagram[20]);

    qDebug() << "[FaultPkt] MsgSeq:"
             << msgSeq;

    qDebug() << "[FaultPkt] KAVACH ID:"
             << QString("0x%1")
                    .arg(kavachID, 6, 16, QChar('0'))
                    .toUpper();

    qDebug() << "[FaultPkt] NMS ID:"
             << QString("0x%1")
                    .arg(nmsID, 4, 16, QChar('0'))
                    .toUpper();

    qDebug() << "[FaultPkt] KavachType:"
             << QString("0x%1")
                    .arg(kavachType, 2, 16, QChar('0'))
                    .toUpper();

    qDebug() << "[FaultPkt] TotalFaults:"
             << totalFaults;

    //======================================================================
    // Create / update packet structure
    //======================================================================

    delete m_pcFaultpkt;
    m_pcFaultpkt = new stStationFaults();

    memset(m_pcFaultpkt, 0, sizeof(stStationFaults));

    // Copy received packet into structure
    memcpy(m_pcFaultpkt,
           datagram.constData(),
           qMin(datagram.size(),
                static_cast<int>(sizeof(stStationFaults))));

    // Store correctly parsed values
    m_pcFaultpkt->usMsgSeq = msgSeq;
    m_pcFaultpkt->ucKavachSubsysID = kavachID;
    m_pcFaultpkt->usNMSID = nmsID;
    m_pcFaultpkt->ucKavachType = kavachType;
    m_pcFaultpkt->ucTotalFaultsCode = totalFaults;

    //======================================================================
    // Fault lists for DB
    //======================================================================

    QStringList strLstFaultPrompt;
    QStringList strLstFaultType;
    QStringList strLstFaultCode;
    QStringList strLstModule;

    //======================================================================
    // Parse the received fault data
    //======================================================================

    const int faultStart = 21;
    const int crcSize = 4;
    const int faultDataEnd = datagram.size() - crcSize;

    const int faultEntrySize = 4;

    for (int i = 0;
         i < totalFaults &&
         (faultStart + (i * faultEntrySize) + faultEntrySize) <= faultDataEnd;
         ++i)
    {
        int offset =
            faultStart + (i * faultEntrySize);

        quint32 faultValue =
            (static_cast<quint32>(
                 static_cast<quint8>(datagram[offset])) << 24) |
            (static_cast<quint32>(
                 static_cast<quint8>(datagram[offset + 1])) << 16) |
            (static_cast<quint32>(
                 static_cast<quint8>(datagram[offset + 2])) << 8) |
            static_cast<quint32>(
                static_cast<quint8>(datagram[offset + 3]));

        qDebug() << "[FaultPkt] Fault[" << i << "]:"
                 << QString("0x%1")
                        .arg(faultValue, 8, 16, QChar('0'))
                        .toUpper();

        strLstModule.append("0x00");
        strLstFaultType.append("0x00");

        strLstFaultCode.append(
            QString("0x%1")
                .arg(faultValue, 8, 16, QChar('0'))
                .toUpper());

        strLstFaultPrompt.append(
            QString("Fault 0x%1")
                .arg(faultValue, 8, 16, QChar('0'))
                .toUpper());
    }

    //======================================================================
    // ACK
    //======================================================================

    qDebug() << "[FaultAck] Preparing ACK"
             << "Seq:" << msgSeq
             << "NMSID:" << nmsID
             << "KavachID:" << kavachID
             << "KavachType:"
             << QString("0x%1")
                    .arg(kavachType, 2, 16, QChar('0'))
                    .toUpper();

    SendFaultPktAck(
        QHostAddress(m_strStnSenderIP),
        m_usStnSenderPort,
        msgSeq,
        nmsID,
        kavachID,
        kavachType,startFrame
        );

    qDebug() << "[FaultAck] SendFaultPktAck() completed";

    //======================================================================
    // DB
    //======================================================================

    emit SigStnFaultPktInserttoDB(
        m_pcFaultpkt,
        strLstModule,
        strLstFaultType,
        strLstFaultCode,
        strLstFaultPrompt);

    qDebug() << "[FaultPkt] Database signal emitted";

    //======================================================================
    // Completed
    //======================================================================

    qDebug() << "[FaultPkt] Processing completed";
    qDebug() << "================================================";
}

void nmsMainWindow::ProcessStationHealthPkt(QByteArray datagram)
{
    if (datagram.size() < sizeof(stStationHealthPkt))
    {
        qWarning() << "Invalid Station Health Packet: size =" << datagram.size();
        return;
    }

    stStationHealthPkt stStnHlthPktHdr;
    memcpy(&stStnHlthPktHdr, datagram.constData(), sizeof(stStationHealthPkt));

    stStnHlthPktHdr.usStartFrame     = qFromBigEndian(stStnHlthPktHdr.usStartFrame);
    stStnHlthPktHdr.usMsgLength      = qFromBigEndian(stStnHlthPktHdr.usMsgLength);
    stStnHlthPktHdr.usStatKavachID   = qFromBigEndian(stStnHlthPktHdr.usStatKavachID);
    stStnHlthPktHdr.usNMSID          = qFromBigEndian(stStnHlthPktHdr.usNMSID);

    QStringList strlstEventID;
    QStringList strlstEventData;

    qDebug() << "Event Count" << stStnHlthPktHdr.ucEventCnt;
    uint16_t eventID = 0;
    int index = sizeof(stStationHealthPkt);  // start after header
    for (uint8_t i = 0; i < stStnHlthPktHdr.ucEventCnt; ++i)
    {
        if (index + 2 > datagram.size()) break; // safety

        // Event ID (2 bytes)
        eventID = qFromBigEndian(*reinterpret_cast<const uint16_t*>(datagram.constData() + index));
        index += 2;

        QString strEvntID = GetStnHlthEventName(eventID);
        strlstEventID.append(QString::number(eventID));

        uint32_t eventData = 0;

        // Determine event data length based on ID
        if ((eventID == 21)||(eventID == 23)||(eventID == 38)||(eventID == 39)||
            (eventID == 40)||(eventID == 41)||(eventID == 42)||(eventID == 45))
        {
            // 2-byte data
            if (index + 2 <= datagram.size())
            {
                eventData = qFromBigEndian(*reinterpret_cast<const uint16_t*>(datagram.constData() + index));
                index += 2;
            }
            strlstEventData.append(QString::number(eventData));
        }
        else if ((eventID == 43)||(eventID == 44))
        {
            // 4-byte data
            if (index + 4 <= datagram.size())
            {
                // eventData = qFromBigEndian(*reinterpret_cast<const uint32_t*>(datagram.constData() + index));
                uint8_t status = static_cast<uint8_t>(datagram[index]);

                // Bytes 1-3 = locoID
                uint32_t locoID = (static_cast<uint32_t>(datagram[index + 1]) << 16) |
                                  (static_cast<uint32_t>(datagram[index + 2]) << 8)  |
                                  static_cast<uint32_t>(datagram[index + 3]);

                QString combinedStr = QString("%1,%2").arg(status).arg(locoID);

                eventData = (static_cast<uint32_t>(status) << 24) | locoID;
                strlstEventData.append(QString::number(eventData));

                index += 4;
            }
        }
        else if(eventID >= 200 && eventID <= 255)
        {
            if (index + 2 <= datagram.size())
            {
                eventData = qFromBigEndian<quint16>(
                    reinterpret_cast<const uchar*>(datagram.constData() + index));
                qDebug() << "RIU Event HEX:"
                         << QString("0x%1")
                                .arg(eventData, 4, 16, QChar('0'))
                                .toUpper() << eventData;
                QString strRIUEvntData = GetRIUEventData(eventData,stStnHlthPktHdr.usStatKavachID);
                strlstEventData.append(strRIUEvntData);
                index += 2;
            }
        }
        else
        {
            // 1-byte data
            if (index + 1 <= datagram.size())
            {
                eventData = static_cast<uint8_t>(datagram.at(index));

                index += 1;
            }
            strlstEventData.append(QString::number(eventData));
        }
    }

    QString strEventID = QStringList(strlstEventID).join(","); // example in Qt
    QString strEventData = QStringList(strlstEventData).join(",");


    qDebug() << "Event Data" << QString::number(eventID) << strEventData;

    uint32_t crcReceived = 0;
    if (datagram.size() >= 4)
    {
        crcReceived = qFromBigEndian(*reinterpret_cast<const quint32*>(datagram.constData() + datagram.size() - 4));
    }
    if(stStnHlthPktHdr.ucEventCnt != 0)
    {
        emit SigInsertDBStationhealthPkt(stStnHlthPktHdr,strlstEventID,strlstEventData,crcReceived);

        qDebug() << "Station Health" << stStnHlthPktHdr.ucEventCnt << strlstEventID << strlstEventData;
    }

}

void nmsMainWindow::ProcessTSRMSMessagePkt(QByteArray datagram)
{
    memcpy(&m_stPktHdr, datagram.constData(), sizeof(stPacketHeader));

    int offset = sizeof(stPacketHeader);

    if (datagram.size() < offset + 2)
    {
        qWarning() << "Payload too short to read relay count.";
        return;
    }

    uint32_t recvCRC = qFromBigEndian<uint32_t>(reinterpret_cast<const uchar*>(datagram.constData() + offset));

}

void nmsMainWindow::ProcessOnBoardHealthPkt(QByteArray datagram)
{
    if (datagram.size() < sizeof(stOnBoardHealthPkt))
    {
        qWarning() << "Invalid OnBoard Health Packet: size =" << datagram.size();
        return;
    }

    stOnBoardHealthPkt stOnBrdHlthPktHdr;
    memcpy(&stOnBrdHlthPktHdr, datagram.constData(), sizeof(stOnBoardHealthPkt));

    stOnBrdHlthPktHdr.usStartFrame     = qFromBigEndian(stOnBrdHlthPktHdr.usStartFrame);
    stOnBrdHlthPktHdr.usMsgLength      = qFromBigEndian(stOnBrdHlthPktHdr.usMsgLength);
    stOnBrdHlthPktHdr.usNMSID          = qFromBigEndian(stOnBrdHlthPktHdr.usNMSID);

    QStringList strlstEventID;
    QStringList strlstEventData;

    int index = sizeof(stOnBoardHealthPkt);  // start after header

    for (uint8_t i = 0; i < stOnBrdHlthPktHdr.ucEventCnt; ++i)
    {
        if (index + 2 > datagram.size()) break; // safety

        // Event ID (2 bytes)
        uint16_t eventID = qFromBigEndian(*reinterpret_cast<const uint16_t*>(datagram.constData() + index));
        index += 2;

        QString strEvntID = GetOnBoardHlthEvntName(eventID);
        strlstEventID.append(strEvntID);

        uint32_t eventData = 0;

        // Determine event data length based on ID
        if ((eventID == 17)||(eventID == 27)||(eventID == 28)||(eventID == 33)||
            (eventID == 34)||(eventID == 35)||(eventID == 36)||(eventID == 37)||
            (eventID == 38)||(eventID == 55)||(eventID == 56))
        {
            // 2-byte data
            if (index + 2 <= datagram.size())
            {
                eventData = qFromBigEndian(*reinterpret_cast<const uint16_t*>(datagram.constData() + index));
                index += 2;
            }
        }
        else if ((eventID == 39)||(eventID == 40) || (eventID == 48)||(eventID == 57))
        {
            // 4-byte data
            if (index + 4 <= datagram.size())
            {
                eventData = qFromBigEndian(*reinterpret_cast<const uint32_t*>(datagram.constData() + index));
                index += 4;
            }
        }
        else if ((eventID == 46)||(eventID == 47))
        {
            // 3-byte data
            if (index + 3 <= datagram.size())
            {
                eventData  = (static_cast<uint32_t>(datagram[index]) << 16)
                |        (static_cast<uint32_t>(datagram[index + 1]) << 8)
                    |    (static_cast<uint32_t>(datagram[index + 2]));
                // eventData = qFromBigEndian(*reinterpret_cast<const uint32_t*>(datagram.constData() + index));
                index += 3;
            }
        }
        else
        {
            // 1-byte data
            if (index + 1 <= datagram.size())
            {
                eventData = static_cast<uint8_t>(datagram.at(index));
                index += 1;
            }
        }

        strlstEventData.append(QString::number(eventData));
        qDebug() << "EventID:" << eventID << "Data:" << eventData;
    }

    QString strEventID = QStringList(strlstEventID).join(","); // example in Qt
    QString strEventData = QStringList(strlstEventData).join(",");

    uint32_t crcReceived = 0;
    if (datagram.size() >= 4)
    {
        crcReceived = qFromBigEndian(*reinterpret_cast<const quint32*>(datagram.constData() + datagram.size() - 4));
    }
    if(stOnBrdHlthPktHdr.ucEventCnt != 0)
    {
        emit SigInsertDBOnBoardhealthPkt(stOnBrdHlthPktHdr,strEventID,strEventData,crcReceived);
    }
}

void nmsMainWindow::ProcessLocoRSSIMessagePkt(QByteArray datagram)
{
    if (datagram.size() < sizeof(stLocoRSSIMsg))
    {
        qWarning() << "Invalid Loco RSSI message Packet: size =" << datagram.size();
        return;
    }

    stLocoRSSIMsg stLocoRSSI;
    memcpy(&stLocoRSSI, datagram.constData(), sizeof(stLocoRSSIMsg));

    stLocoRSSI.usStartFrame     = qFromBigEndian(stLocoRSSI.usStartFrame);
    stLocoRSSI.usMsgLength      = qFromBigEndian(stLocoRSSI.usMsgLength);
    stLocoRSSI.usNMSID          = qFromBigEndian(stLocoRSSI.usNMSID);

    emit SigInsertDBLocoRSSIMessage(stLocoRSSI);
}

void nmsMainWindow::ProcessStationRSSIMessagePkt(QByteArray datagram)
{
    if (datagram.size() < sizeof(stStationRSSIMsg))
    {
        qWarning() << "Invalid Station RSSI message Packet: size =" << datagram.size();
        return;
    }

    stStationRSSIMsg stStnRSSIMsg;
    memcpy(&stStnRSSIMsg, datagram.constData(), sizeof(stLocoRSSIMsg));

    stStnRSSIMsg.usStartFrame     = qFromBigEndian(stStnRSSIMsg.usStartFrame);
    stStnRSSIMsg.usMsgLength      = qFromBigEndian(stStnRSSIMsg.usMsgLength);
    stStnRSSIMsg.usStatKavachID   = qFromBigEndian(stStnRSSIMsg.usStatKavachID);
    stStnRSSIMsg.usNMSID          = qFromBigEndian(stStnRSSIMsg.usNMSID);

    emit SigInsertDBStationRSSIMessage(stStnRSSIMsg);
}

void nmsMainWindow::ProcessStationKavachSysSts(QByteArray datagram)
{
    if (datagram.size() < sizeof(stStationaryKavachSysInfo))
    {
        qWarning() << "Invalid Station System Status Packet: size =" << datagram.size();
        return;
    }

    stStationaryKavachSysInfo stStnKvchSysStsMsg;
    memcpy(&stStnKvchSysStsMsg, datagram.constData(), sizeof(stStationaryKavachSysInfo));

    stStnKvchSysStsMsg.usStartFrame     = qFromBigEndian(stStnKvchSysStsMsg.usStartFrame);
    stStnKvchSysStsMsg.usMsgLength      = qFromBigEndian(stStnKvchSysStsMsg.usMsgLength);
    stStnKvchSysStsMsg.usStationKavachID   = qFromBigEndian(stStnKvchSysStsMsg.usStationKavachID);
    stStnKvchSysStsMsg.usNMSID          = qFromBigEndian(stStnKvchSysStsMsg.usNMSID);

    emit SigInsertDBStationKavachSysSts(stStnKvchSysStsMsg);
}

void nmsMainWindow::ProcessOnBoardEventMsg(QByteArray datagram)
{
    if (datagram.size() < sizeof(stOnboardKavachEventMsg))
    {
        qWarning() << "Invalid Loco OnBoard Event message Packet: size =" << datagram.size();
        return;
    }

    stOnboardKavachEventMsg stLocoOnBoardEventMsg;
    memcpy(&stLocoOnBoardEventMsg, datagram.constData(), sizeof(stOnboardKavachEventMsg));

    stLocoOnBoardEventMsg.usStartFrame     = qFromBigEndian(stLocoOnBoardEventMsg.usStartFrame);
    stLocoOnBoardEventMsg.usMsgLength      = qFromBigEndian(stLocoOnBoardEventMsg.usMsgLength);
    stLocoOnBoardEventMsg.usNMSID          = qFromBigEndian(stLocoOnBoardEventMsg.usNMSID);

    emit SigInsertDBOnBoardEventMessage(stLocoOnBoardEventMsg);
}

void nmsMainWindow::ProcessOnBoardBrakeEventMsg(QByteArray datagram)
{
    if (datagram.size() < sizeof(stOnboardKavachBrakeEventMsg))
    {
        qWarning() << "Invalid Loco OnBoard Brake Event message Packet: size =" << datagram.size();
        return;
    }

    stOnboardKavachBrakeEventMsg stOnBoardBrakeEventMsg;
    memcpy(&stOnBoardBrakeEventMsg, datagram.constData(), sizeof(stOnboardKavachBrakeEventMsg));

    stOnBoardBrakeEventMsg.usStartFrame     = qFromBigEndian(stOnBoardBrakeEventMsg.usStartFrame);
    stOnBoardBrakeEventMsg.usMsgLength      = qFromBigEndian(stOnBoardBrakeEventMsg.usMsgLength);
    stOnBoardBrakeEventMsg.usNMSID          = qFromBigEndian(stOnBoardBrakeEventMsg.usNMSID);

    emit SigInsertDBOnBoardBrakeEventMsg(stOnBoardBrakeEventMsg);
}

void nmsMainWindow::ProcessOnBoardHealthStsMsg(QByteArray datagram)
{
    if (datagram.size() < sizeof(stOnboardKavachBOKSHealthMsg))
    {
        qWarning() << "Invalid Loco OnBoard Health Status message Packet: size =" << datagram.size();
        return;
    }

    stOnboardKavachBOKSHealthMsg stOnBoardSystemHealthMsg;
    memcpy(&stOnBoardSystemHealthMsg, datagram.constData(), sizeof(stOnboardKavachBOKSHealthMsg));

    stOnBoardSystemHealthMsg.usStartFrame     = qFromBigEndian(stOnBoardSystemHealthMsg.usStartFrame);
    stOnBoardSystemHealthMsg.usMsgLength      = qFromBigEndian(stOnBoardSystemHealthMsg.usMsgLength);
    stOnBoardSystemHealthMsg.usNMSID          = qFromBigEndian(stOnBoardSystemHealthMsg.usNMSID);

    emit SigInsertDBOnBoardSystemHealthMsg(stOnBoardSystemHealthMsg);
}
void nmsMainWindow::ProcessS2SPackets(QByteArray datagram)
{
    if (datagram.size() < sizeof(stPacketHeader))
    {
        qWarning() << "Invalid Station to Station Packet: size =" << datagram.size();
        return;
    }

    stPacketHeader stPktHdr;
    memcpy(&stPktHdr, datagram.constData(), sizeof(stPacketHeader));

    stPktHdr.usStartFrame     = qFromBigEndian(stPktHdr.usStartFrame);
    stPktHdr.usMsgLength      = qFromBigEndian(stPktHdr.usMsgLength);
    stPktHdr.usStatKavachID   = qFromBigEndian(stPktHdr.usStatKavachID);
    stPktHdr.usNMSID          = qFromBigEndian(stPktHdr.usNMSID);

    int payloadOffset = sizeof(stPacketHeader);
    if (datagram.size() < payloadOffset + 2)
    {
        qWarning() << "Invalid payload size";
        return;
    }

    // Get the message type from payload (2 bytes at position 1–2 of sub-packet)
    uint16_t msgType;
    memcpy(&msgType, datagram.constData() + payloadOffset + 1, sizeof(uint16_t));
    msgType = qFromBigEndian(msgType);

    // ====== Now branch based on message type ======
    switch (msgType)
    {
    case 0x0101:  // PDI Version Check
    {
        parsePDIVersionCheckPacket(stPktHdr,datagram,payloadOffset);
    }break;
    case 0x0102:
    {
        parsePDIVersionCheckMsgPacket(stPktHdr,datagram,payloadOffset);
    }break;
    case 0x0103:
    {
        parseHeartBeatPacket(stPktHdr,datagram,payloadOffset);
    }break;
    case 0x0104:
    {
        parseTrainHandOverReqPacket(stPktHdr,datagram,payloadOffset);
    }break;
    case 0x0105:
    {
        parseTrainRRIMsgPacket(stPktHdr,datagram,payloadOffset);
    }break;
    case 0x0106:
    {
        parseTrainTakenOverMsgPacket(stPktHdr,datagram,payloadOffset);
    }break;
    case 0x0107:
    {
        parseTrainHandOverCancellationMsgPacket(stPktHdr,datagram,payloadOffset);
    }break;
    case 0x0108:
    {
        parseTrainLengthInformationPacket(stPktHdr,datagram,payloadOffset);
    }break;
    case 0x0109:
    {
        parseTrainLengthInformationAck(stPktHdr,datagram,payloadOffset);
    }break;
    case 0x010A:
    {
        parseTSLRouteReqPacket(stPktHdr,datagram,payloadOffset);
    }break;
    case 0x010B:
    {
        parseTSLInformationPacket(stPktHdr,datagram,payloadOffset);
    }break;
    case 0x010C:
    {
        parseFieldElementStatusReqPacket(stPktHdr,datagram,payloadOffset);
    }break;
    case 0x010D:
    {

    }break;
    case 0x010E:
    {
        parseTrainHandOverCancellationAck(stPktHdr,datagram,payloadOffset);
    }break;
    }
}

void nmsMainWindow::InitGSMRelay()
{
    m_ocCfgSettings->beginGroup("GSM");
    m_strRelayIP  = m_ocCfgSettings->value("RelayIP",   "122.175.49.55").toString();
    m_usRelayPort = static_cast<quint16>(
        m_ocCfgSettings->value("RelayPort", 5000).toInt());
    m_ocCfgSettings->endGroup();

    // Persistent relay socket — reused for every packet
    m_pcRelaySocket = new QUdpSocket(this);
    m_pcRelaySocket->bind(QHostAddress::AnyIPv4, 0);

    // Heartbeat timer — keeps CGNAT hole open every 25 seconds
    m_pcHeartbeatTimer = new QTimer(this);
    connect(m_pcHeartbeatTimer, &QTimer::timeout,
            this, &nmsMainWindow::SendHeartbeat);
    m_pcHeartbeatTimer->start(25000);

    // Send first heartbeat immediately on startup
    SendHeartbeat();

    qInfo() << "[GSM Relay] Initialised. Relay:"
            << m_strRelayIP << ":" << m_usRelayPort;
}

QString nmsMainWindow::GetRIUEventData(uint32_t usEvntCode, uint16_t usStnID)
{
    qDebug()<< "EventData " << usEvntCode;
    QString strEvntName = NULL;
    switch(usEvntCode)
    {
    case 0x0000:
    {
        strEvntName = QString("%1:RIU_1 CPU Module Power is not ok").arg(usStnID);
    }break;
    case 0x0001:
    {
        strEvntName = QString("%1:RIU_1 CPU Module Temperature is not ok").arg(usStnID);
    }break;
    case 0x0002:
    {
        strEvntName = QString("%1:RIU_1 IO Module Power is not ok").arg(usStnID);
    }break;
    case 0x0003:
    {
        strEvntName = QString("%1:RIU_1 IO Module Temperature is not ok").arg(usStnID);
    }break;
    case 0x0004:
    {
        strEvntName = QString("%1:RIU_2 CPU Module is not ok").arg(usStnID);
    }break;
    case 0x0005:
    {
        strEvntName = QString("%1:RIU_2 CPU Module Temperature is not ok").arg(usStnID);
    }break;
    case 0x0006:
    {
        strEvntName = QString("%1:RIU_2 IO Module Power is not ok").arg(usStnID);
    }break;
    case 0x0007:
    {
        strEvntName = QString("%1:RIU_2 IO Module Temperature is not ok").arg(usStnID);
    }break;
    case 0x0008:
    {
        strEvntName = QString("%1:RIU_3 CPU Module is not ok").arg(usStnID);
    }break;
    case 0x0009:
    {
        strEvntName = QString("%1:RIU_3 CPU Module Temperature is not ok").arg(usStnID);
    }break;
    case 0x000A:
    {
        strEvntName = QString("%1:RIU_3 IO Module Power is not ok").arg(usStnID);
    }break;
    case 0x000B:
    {
        strEvntName = QString("%1:RIU_3 IO Module Temperature is not ok").arg(usStnID);
    }break;
    case 0x000C:
    {
        strEvntName = QString("%1:RIU_4 CPU Module is not ok").arg(usStnID);
    }break;
    case 0x000D:
    {
        strEvntName = QString("%1:RIU_4 CPU Module Temperature is not ok").arg(usStnID);
    }break;
    case 0x000E:
    {
        strEvntName = QString("%1:RIU_4 IO Module Power is not ok").arg(usStnID);
    }break;
    case 0x000F:
    {
        strEvntName = QString("%1:RIU_4 IO Module Temperature is not ok").arg(usStnID);
    }break;
    case 0x0010:
    {
        strEvntName = QString("%1:RIU_5 CPU Module is not ok").arg(usStnID);
    }break;
    case 0x0011:
    {
        strEvntName = QString("%1:RIU_5 CPU Module Temperature is not ok").arg(usStnID);
    }break;
    case 0x0012:
    {
        strEvntName = QString("%1:RIU_5 IO Module Power is not ok").arg(usStnID);
    }break;
    case 0x0013:
    {
        strEvntName = QString("%1:RIU_5 IO Module Temperature is not ok").arg(usStnID);
    }break;
    case 0x0014:
    {
        strEvntName = QString("%1:RIU_6 CPU Module is not ok").arg(usStnID);
    }break;
    case 0x0015:
    {
        strEvntName = QString("%1:RIU_6 CPU Module Temperature is not ok").arg(usStnID);
    }break;
    case 0x0016:
    {
        strEvntName = QString("%1:RIU_6 IO Module Power is not ok").arg(usStnID);
    }break;
    case 0x0017:
    {
        strEvntName = QString("%1:RIU_6 IO Module Temperature is not ok").arg(usStnID);
    }break;
    }
    return strEvntName;
}
void nmsMainWindow::InitUDP()
{
    nmsUDPServer *pcUdpServer = new nmsUDPServer(m_strCfgFilePath);

    EventLogger *m_pcDataloggps = new EventLogger();


    connect(pcUdpServer->m_pcKavachPktHndlr, SIGNAL(SigNewFaultPacket(QHostAddress, quint16,QByteArray)),
            this, SLOT(SlotNewFaultPacket(QHostAddress, quint16,QByteArray)));

    connect(pcUdpServer->m_pcKavachPktHndlr,SIGNAL(SigPreviousFaultInfo()),
            this,SLOT(SlotPreviousFaultInfo()));

    connect(this,SIGNAL(SigSendAckNMStoKavach(QHostAddress, quint16,stNMStoKavach*)),
            pcUdpServer,SLOT(SlotSendAckEventLoggertoKavach(QHostAddress, quint16,stNMStoKavach*)));

    connect(m_pcDataloggps, SIGNAL(gpsUTCReady(QDateTime)),
            pcUdpServer, SLOT(SlotUpdateGPSTime(QDateTime)));

    connect(m_pcDataloggps, &EventLogger::gpsUTCReady, this, &nmsMainWindow::OnGPSUTCReady);
    connect(m_pcDataloggps, &EventLogger::gpsSpeedReady, this, &nmsMainWindow::OnGPSSpeedReady);
    connect(m_pcDataloggps, &EventLogger::gpsFixStatusReady, this, &nmsMainWindow::OnGPSFixStatusReady);

    // Wire GPS position for 0x28 packet building
    connect(m_pcDataloggps, SIGNAL(gpsPositionReady(double,double,bool)),
            this,           SLOT(SlotGPSPosition(double,double,bool)));

    connect(pcUdpServer, SIGNAL(SigStationDisConnected(QString,bool)),this,SLOT(SlotStationconnStatus(QString,bool)));

    connect(pcUdpServer,SIGNAL(SigConnected(QString,bool)),this,SLOT(SlotStationconnStatus(QString,bool)));

    //  m_pcDataloggps->startGPS();
    QThread *pcThread = new QThread ();
    m_pcDataloggps->moveToThread(pcThread);
    pcThread->start();

    // ── KMS connections (ICD §D) ──────────────────────────────
    // nmsUDPServer::InitKMS() has already created EventLoggerKMS, bound
    // port 4447, and wired the UDP ↔ GSM transport internally.
    // Here we grab the pointer and connect the diagnostic/log signals.
    if (pcUdpServer->m_pcKMS)
    {
        m_pcKMS = pcUdpServer->m_pcKMS;
        InitKMSConnections();
    }
    else
    {
        qCritical() << "[MainWindow] KMS not initialised — check Config.cfg [KMS] and GSM port";
    }
}

void nmsMainWindow::InitDB()
{
    m_ocCfgSettings->beginGroup("Database");

    QString strDBip        = m_ocCfgSettings->value("DB_IP").toString();
    QString strDBPort      = m_ocCfgSettings->value("DB_Port").toString();
    QString strDBName      = m_ocCfgSettings->value("DB_Name").toString();
    QString strDBUsrName   = m_ocCfgSettings->value("DB_Username").toString();
    QString strDBPassword  = m_ocCfgSettings->value("DB_Password").toString();

    m_ocCfgSettings->endGroup();

    qDebug() << strDBip << strDBPort << strDBName << strDBUsrName;

    m_pcDB = new NMSDB (strDBip,strDBPort.toInt(), strDBName,
                       strDBUsrName, strDBPassword,this);

    m_pcDB->Connect();

    if(m_pcDB->IsConnected())
    {
        qDebug() << "Database Connected Successfully";
    }
    else
    {
        qDebug() << "Database Connection Failed";
    }

    m_pcDB->start();
}

void nmsMainWindow::InitLogFile()
{

    QString logDirPath = "/NMS/Logs";

    QDir dir(logDirPath);
    if (!dir.exists()) {
        if (!dir.mkpath(".")) {
            qDebug() << "Failed to create log directory:" << logDirPath;
            return;
        }
    }

    m_pcLocoLogFile.setFileName(dir.filePath("LocoReceivedData.txt"));
    m_pcStationLogFile.setFileName(dir.filePath("StationReceivedData.txt"));

    if (!m_pcLocoLogFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Failed to open log file:";
    }

    if (!m_pcStationLogFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Failed to open log file:";
    }

}

void nmsMainWindow::SlotStationNameAndID(QStringList strLstStationID, QStringList strLstStationNames,
                                         QString strDateTime,bool bStationSts)
{
    m_strLstStationID = strLstStationID;
    m_strLstStationNames = strLstStationNames;

    m_bStationSts = bStationSts;

    m_strDtTime = strDateTime;
}

QString nmsMainWindow::getStationCode(QString &strstationName)
{
    QStringList strLstName = strstationName.split(" ", Qt::SkipEmptyParts);
    QString strcode;
    for (const QString &strword : strLstName)
    {
        strcode.append(strword.at(0).toUpper());
    }
    return strcode;
}

void nmsMainWindow::InitKavachParsePkt()
{
    m_pcKavachParseData = new KAVACH_PARSEPACKET(this);

    connect(m_pcKavachParseData, SIGNAL(SigStationRegHeader(StationRegularHeader)),
            this,SLOT(SlotStationRegHeader(StationRegularHeader)));

    connect(this, SIGNAL(SigInsertDBStationRegHeader(stAccessRequestPkt ,StationRegularHeader)),
            m_pcDBQuery,SLOT(SlotInsertDBStationRegHeader(stAccessRequestPkt,StationRegularHeader)));

    connect(m_pcKavachParseData, SIGNAL(SigInsertDBStnRegMASubPkt(MovementAuthorityPkt)),
            m_pcDBQuery,SLOT(SlotInsertDBStnRegMASubPkt(MovementAuthorityPkt)));

    connect(m_pcKavachParseData, SIGNAL(SigInsertDBStnRegSSPSubPkt(StaticSpeedProfilePkt)),
            m_pcDBQuery,SLOT(SlotInsertDBStnRegSSPSubPkt(StaticSpeedProfilePkt)));

    connect(m_pcKavachParseData, SIGNAL(SigInsertDBStnRegGradientSubPkt(GradientProfilePkt)),
            m_pcDBQuery,SLOT(SlotInsertDBStnRegGradientSubPkt(GradientProfilePkt)));

    connect(m_pcKavachParseData, SIGNAL(SigInsertDBStnRegLCGateSubPkt(LCGateProfilePkt)),
            m_pcDBQuery,SLOT(SlotInsertDBStnRegLCGateSubPkt(LCGateProfilePkt)));

    connect(m_pcKavachParseData,SIGNAL(SigInsertDBStnRegTurnoutSpeedSubPkt(TurnoutSpeedProfilePkt)),
            m_pcDBQuery,SLOT(SlotInsertDBStnRegTurnoutSpeedSubPkt(TurnoutSpeedProfilePkt)));

    connect(m_pcKavachParseData, SIGNAL(SigInsertDBStnRegTagLinkingInfoSubPkt(TagLinkingInfoPkt)),
            m_pcDBQuery,SLOT(SlotInsertDBStnRegTagLinkingInfoSubPkt(TagLinkingInfoPkt)));

    connect(m_pcKavachParseData, SIGNAL(SigInsertDBStnRegTrackCondDataSubPkt(TrackConditionPkt)),
            m_pcDBQuery,SLOT(SlotInsertDBStnRegTrackCondDataSubPkt(TrackConditionPkt)));

    connect(m_pcKavachParseData, SIGNAL(SigInsertDBStnRegTSRSubPkt(TempSpeedRestrictionPkt)),
            m_pcDBQuery,SLOT(SlotInsertDBStnRegTSRSubPkt(TempSpeedRestrictionPkt)));
}

QString nmsMainWindow::GetFaultsCodeDescription(uint16_t usFaultCode)
{
    QString strFaultMsg = NULL;
    switch (usFaultCode)
    {
    case 1: strFaultMsg = FAULT_CODE_01; break;
    case 2: strFaultMsg = FAULT_CODE_02; break;
    case 3: strFaultMsg = FAULT_CODE_03; break;
    case 4: strFaultMsg = FAULT_CODE_04; break;
    case 5: strFaultMsg = FAULT_CODE_05; break;
    case 6: strFaultMsg = FAULT_CODE_06; break;
    case 7: strFaultMsg = FAULT_CODE_07; break;
    case 8: strFaultMsg = FAULT_CODE_08; break;
    case 9: strFaultMsg = FAULT_CODE_09; break;
    case 10: strFaultMsg = FAULT_CODE_10; break;
    case 11: strFaultMsg = FAULT_CODE_11; break;
    case 12: strFaultMsg = FAULT_CODE_12; break;
    case 13: strFaultMsg = FAULT_CODE_13; break;
    case 14: strFaultMsg = FAULT_CODE_14; break;
    case 15: strFaultMsg = FAULT_CODE_15; break;
    case 16: strFaultMsg = FAULT_CODE_16; break;
    case 17: strFaultMsg = FAULT_CODE_17; break;
    case 18: strFaultMsg = FAULT_CODE_18; break;
    case 19: strFaultMsg = FAULT_CODE_19; break;
    case 20: strFaultMsg = FAULT_CODE_20; break;
    case 21: strFaultMsg = FAULT_CODE_21; break;
    case 22: strFaultMsg = FAULT_CODE_22; break;
    case 23: strFaultMsg = FAULT_CODE_23; break;
    case 24: strFaultMsg = FAULT_CODE_24; break;
    default: strFaultMsg = "Unknown Fault"; break;
    }
    return strFaultMsg;
}

QString nmsMainWindow::GetOnBoardHlthEvntName(uint16_t usEvntID)
{
    QString strEvntName = NULL;
    switch(usEvntID)
    {

    case 1: strEvntName = "Radio-1 Health"; break;
    case 2: strEvntName = "Radio-2 Health"; break;
    case 3: strEvntName = "Radio-1 Input Supply"; break;
    case 4: strEvntName = "Radio-2 Input Supply"; break;
    case 5: strEvntName = "Radio-1 Temperature"; break;
    case 6: strEvntName = "Radio-2 Temperature"; break;
    case 7: strEvntName = "Radio-1 PA Temperature"; break;
    case 8: strEvntName = "Radio-2 PA Temperature"; break;
    case 9: strEvntName = "Radio-1 PA Supply Voltage"; break;
    case 10: strEvntName = "Radio-2 PA Supply Voltage"; break;
    case 11: strEvntName = "Radio-1 Tx PA Current"; break;
    case 12: strEvntName = "Radio-2 Tx PA Current"; break;
    case 13: strEvntName = "Radio-1 Reverse Power"; break;
    case 14: strEvntName = "Radio-2 Reverse Power"; break;
    case 15: strEvntName = "Radio-1 Forward Power"; break;
    case 16: strEvntName = "Radio-2 Forward Power"; break;
    case 17: strEvntName = "Stationary Regular Packet Time offset"; break;
    case 18: strEvntName = "Active GPS Number"; break;
    case 19: strEvntName = "GPS-1 View Status"; break;
    case 20: strEvntName = "GPS-2 View Status"; break;
    case 21: strEvntName = "GPS-1 Seconds"; break;
    case 22: strEvntName = "GPS-2 Seconds"; break;
    case 23: strEvntName = "GPS-1 Satellites in view"; break;
    case 24: strEvntName = "GPS-1 CNO(Max)"; break;
    case 25: strEvntName = "GPS-2 Satellites in view"; break;
    case 26: strEvntName = "GPS-2 CNO(Max)"; break;
    case 27: strEvntName = "GPS-1 Link Status"; break;
    case 28: strEvntName = "GPS-2 Link Status"; break;
    case 29: strEvntName = "GSM-1 RSSI"; break;
    case 30: strEvntName = "GSM-2 RSSI"; break;
    case 31: strEvntName = "Current Running Key"; break;
    case 32: strEvntName = "Remaining Number of Keys"; break;
    case 33: strEvntName = "Session Key Checksum"; break;
    case 34: strEvntName = "DMI-1 Link Status"; break;
    case 35: strEvntName = "DMI-2 Link Status"; break;
    case 36: strEvntName = "RFID Reader-1 Link Status"; break;
    case 37: strEvntName = "RFID Reader-2 Link Status"; break;
    case 38: strEvntName = "Duplicate Missing RFID Tag"; break;
    case 39: strEvntName = "Missing linked RFID Tag"; break;
    case 40: strEvntName = "Computed TLM Sts"; break;
    case 41: strEvntName = "Train Configuration change"; break;
    case 42: strEvntName = "Bootup Sequence error"; break;
    case 43: strEvntName = "Selected Train formation"; break;
    case 44: strEvntName = "Selected Cab"; break;
    case 45: strEvntName = "Brake application reason"; break;
    case 46: strEvntName = "Station General SoS"; break;
    case 47: strEvntName = "Station Loco Specific SoS"; break;
    case 48: strEvntName = "Collision Detection"; break;
    case 49: strEvntName = "Loco Self SoS"; break;
    case 50: strEvntName = "KAVACH Connection"; break;
    case 51: strEvntName = "BIU Isolated"; break;
    case 52: strEvntName = "EB ByPassed"; break;
    case 53: strEvntName = "KAVACH Territory"; break;
    case 54: strEvntName = "Brake Interface Error"; break;
    case 55: strEvntName = "OnBoard KAVACH Modules Health"; break;
    case 56: strEvntName = "Conflict Route RFID"; break;
    case 57: strEvntName = "Train configuration data checksum"; break;
    default: strEvntName = "Unknown Event ID"; break;
    }
    return strEvntName;

}

QString nmsMainWindow::GetStnHlthEventName(uint16_t usEvntID)
{

    QString strEvntName = NULL;
    switch(usEvntID)
    {
    case 1: strEvntName = "System Temperature"; break;
    case 2: strEvntName = "Active Radio Number"; break;
    case 3: strEvntName = "Radio-1 Health"; break;
    case 4: strEvntName = "Radio-2 Health"; break;
    case 5: strEvntName = "Radio-1 Input Supply"; break;
    case 6: strEvntName = "Radio-2 Input Supply"; break;
    case 7: strEvntName = "Radio-1 Temperature"; break;
    case 8: strEvntName = "Radio-2 Temperature"; break;
    case 9: strEvntName = "Radio-1 PA Temperature"; break;
    case 10: strEvntName = "Radio-2 PA Temperature"; break;
    case 11: strEvntName = "Radio-1 PA Supply Voltage"; break;
    case 12: strEvntName = "Radio-2 PA Supply Voltage"; break;
    case 13: strEvntName = "Radio-1 Tx PA Current"; break;
    case 14: strEvntName = "Radio-2 Tx PA Current"; break;
    case 15: strEvntName = "Radio-1 Reverse Power"; break;
    case 16: strEvntName = "Radio-2 Reverse Power"; break;
    case 17: strEvntName = "Radio-1 Forward Power"; break;
    case 18: strEvntName = "Radio-2 Forward Power"; break;
    case 19: strEvntName = "Current Running Key"; break;
    case 20: strEvntName = "Remaining Number of Keys"; break;
    case 21: strEvntName = "Session Key Checksum"; break;
    case 22: strEvntName = "Allocated Time slot for new Loco"; break;
    case 23: strEvntName = "New Loco Regular packet received time offset"; break;
    case 24: strEvntName = "Loco Count"; break;
    case 25: strEvntName = "Radio-1 Rx Packet Count"; break;
    case 26: strEvntName = "Radio-2 Rx Packet Count"; break;
    case 27: strEvntName = "Active GPS Number"; break;
    case 28: strEvntName = "GPS-1 View"; break;
    case 29: strEvntName = "GPS-2 View"; break;
    case 30: strEvntName = "GPS-1 Seconds"; break;
    case 31: strEvntName = "GPS-2 Seconds"; break;
    case 32: strEvntName = "GPS-1 Satellites in view"; break;
    case 33: strEvntName = "GPS-1 CNO(Max)"; break;
    case 34: strEvntName = "GPS-2 Satellites in view"; break;
    case 35: strEvntName = "GPS-2 CNO(Max)"; break;
    case 36: strEvntName = "GSM-1 RSSI"; break;
    case 37: strEvntName = "GSM-2 RSSI"; break;
    case 38: strEvntName = "Missing RFID"; break;
    case 39: strEvntName = "Invalid RFID"; break;
    case 40: strEvntName = "Conflict Route RFID"; break;
    case 41: strEvntName = "Conflicting TIN"; break;
    case 42: strEvntName = "Missing TIN"; break;
    case 43: strEvntName = "Loco Specific SoS"; break;
    case 44: strEvntName = "Train Exit mode"; break;
    case 45: strEvntName = "Station modules health"; break;
    default: strEvntName = "Unknown Event ID"; break;
    }
    return strEvntName;
}

void nmsMainWindow::parsePDIVersionCheckPacket(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset)
{
    if (byArrdatagram.size() < payloadOffset + sizeof(stPDIVerCheckCmdPkt))
    {
        qWarning() << "Invalid PDI Version Check packet size";
        return;
    }

    stPDIVerCheckCmdPkt stPDIVerchkPkt;
    memcpy(&stPDIVerchkPkt, byArrdatagram.constData() + payloadOffset, sizeof(stPDIVerCheckCmdPkt));

    // Convert endian for relevant fields
    stPDIVerchkPkt.usMsgTyp   = qFromBigEndian(stPDIVerchkPkt.usMsgTyp);
    stPDIVerchkPkt.usMsgLen = qFromBigEndian(stPDIVerchkPkt.usMsgLen);
    stPDIVerchkPkt.usRandomNum  = qFromBigEndian(stPDIVerchkPkt.usRandomNum);

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
    {
        strSenderId.append(QString("%1 ").arg(stPDIVerchkPkt.ucSenderID[i], 2, 16, QLatin1Char('0')));
    }
    for (int i = 0; i < 20; ++i)
    {
        strReceiverId.append(QString("%1 ").arg(stPDIVerchkPkt.ucReceiverID[i], 2, 16, QLatin1Char('0')));
    }
    emit SigInsertDBS2SPDIVerCmd(stPktHdr,stPDIVerchkPkt);
}

void nmsMainWindow::parsePDIVersionCheckMsgPacket(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset)
{
    if (byArrdatagram.size() < payloadOffset + sizeof(stPDIVerCheckMsgPkt))
    {
        qWarning() << "Invalid PDI Version Check packet size";
        return;
    }

    stPDIVerCheckMsgPkt stPDIVerchkPkt;
    memcpy(&stPDIVerchkPkt, byArrdatagram.constData() + payloadOffset, sizeof(stPDIVerCheckMsgPkt));

    // Convert endian for relevant fields
    stPDIVerchkPkt.usMsgTyp   = qFromBigEndian(stPDIVerchkPkt.usMsgTyp);
    stPDIVerchkPkt.usMsgLen = qFromBigEndian(stPDIVerchkPkt.usMsgLen);
    stPDIVerchkPkt.usSecondaryStnRandomNum  = qFromBigEndian(stPDIVerchkPkt.usSecondaryStnRandomNum);

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
    {
        strSenderId.append(QString("%1 ").arg(stPDIVerchkPkt.ucSenderID[i], 2, 16, QLatin1Char('0')));
    }
    for (int i = 0; i < 20; ++i)
    {
        strReceiverId.append(QString("%1 ").arg(stPDIVerchkPkt.ucReceiverID[i], 2, 16, QLatin1Char('0')));
    }
    emit SigInsertDBS2SPDIVerMsg(stPktHdr,stPDIVerchkPkt);
}

void nmsMainWindow::parseHeartBeatPacket(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset)
{
    if (byArrdatagram.size() < payloadOffset + sizeof(stHeartBeatPkt))
    {
        qWarning() << "Invalid PDI Version Check packet size";
        return;
    }

    stHeartBeatPkt stHeartBeat;
    memcpy(&stHeartBeat, byArrdatagram.constData() + payloadOffset, sizeof(stHeartBeatPkt));

    // Convert endian for relevant fields
    stHeartBeat.usMsgTyp   = qFromBigEndian(stHeartBeat.usMsgTyp);
    stHeartBeat.usMsgLen = qFromBigEndian(stHeartBeat.usMsgLen);

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
    {
        strSenderId.append(QString("%1 ").arg(stHeartBeat.ucSenderID[i], 2, 16, QLatin1Char('0')));
    }
    for (int i = 0; i < 20; ++i)
    {
        strReceiverId.append(QString("%1 ").arg(stHeartBeat.ucReceiverID[i], 2, 16, QLatin1Char('0')));
    }
    emit SigInsertDBS2SHeartBeat(stPktHdr,stHeartBeat);

}



void nmsMainWindow::parseTrainHandOverReqPacket(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset)
{
    if (byArrdatagram.size() < payloadOffset + sizeof(stHeartBeatPkt))
    {
        qWarning() << "Invalid Heart Beat packet size";
        return;
    }

    stTrainHandOverReqPkt stTrainHandOverReq;
    memcpy(&stTrainHandOverReq, byArrdatagram.constData() + payloadOffset, sizeof(stHeartBeatPkt));

    // Convert endian for relevant fields
    stTrainHandOverReq.usMsgTyp   = qFromBigEndian(stTrainHandOverReq.usMsgTyp);
    stTrainHandOverReq.usMsgLen = qFromBigEndian(stTrainHandOverReq.usMsgLen);

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
    {
        strSenderId.append(QString("%1 ").arg(stTrainHandOverReq.ucSenderID[i], 2, 16, QLatin1Char('0')));
    }
    for (int i = 0; i < 20; ++i)
    {
        strReceiverId.append(QString("%1 ").arg(stTrainHandOverReq.ucReceiverID[i], 2, 16, QLatin1Char('0')));
    }
    emit SigInsertDBS2STrainHandOverReq(stPktHdr,stTrainHandOverReq);

}

void nmsMainWindow::parseTrainRRIMsgPacket(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset)
{
    qDebug() << "\n--- Parsing Train RRI Message (0x0105) ---";

    const int headerSize = sizeof(stTrainRRIPkt);
    const int footerSize = 4; // CRC or MAC

    if (byArrdatagram.size() < payloadOffset + headerSize + footerSize)
    {
        qWarning() << "Invalid Train RRI message size:" << byArrdatagram.size();
        return;
    }

    // 1️⃣ Parse fixed RRI header
    stTrainRRIPkt stRRIMsgHdr;
    memcpy(&stRRIMsgHdr, byArrdatagram.constData() + payloadOffset, headerSize);

    stRRIMsgHdr.usMsgTyp   = qFromBigEndian(stRRIMsgHdr.usMsgTyp);
    stRRIMsgHdr.usMsgLen   = qFromBigEndian(stRRIMsgHdr.usMsgLen);
    stRRIMsgHdr.usMsgSeq   = qFromBigEndian(stRRIMsgHdr.usMsgSeq);
    stRRIMsgHdr.usRFIDTag  = qFromBigEndian(stRRIMsgHdr.usRFIDTag);

    QString strSenderID   = QByteArray(reinterpret_cast<const char*>(stRRIMsgHdr.ucSenderID), 20).toHex(' ');
    QString strReceiverID = QByteArray(reinterpret_cast<const char*>(stRRIMsgHdr.ucReceiverID), 20).toHex(' ');

    qDebug() << "MsgType:" << QString("0x%1").arg(stRRIMsgHdr.usMsgTyp, 4, 16, QLatin1Char('0')).toUpper()
             << "Len:" << stRRIMsgHdr.usMsgLen
             << "Seq:" << stRRIMsgHdr.usMsgSeq
             << "RFID:" << stRRIMsgHdr.usRFIDTag;
    qDebug() << "SenderID:" << strSenderID;
    qDebug() << "ReceiverID:" << strReceiverID;

    // 2️⃣ Extract payload (excluding CRC/MAC)
    int payloadStart = payloadOffset + headerSize;
    int totalMsgLen  = stRRIMsgHdr.usMsgLen; // Message length includes payload + MAC
    int payloadLen   = totalMsgLen - headerSize - footerSize;

    if (payloadStart + payloadLen + footerSize > byArrdatagram.size())
    {
        qWarning() << "Truncated Train RRI message";
        return;
    }

    QByteArray payload = byArrdatagram.mid(payloadStart, payloadLen);
    QByteArray macBytes = byArrdatagram.mid(payloadStart + payloadLen, footerSize);

    qDebug() << "Payload length:" << payload.size();
    qDebug() << "MAC (CRC) bytes:" << macBytes.toHex(' ');

    // 3️⃣ Print payload bytes
    for (int i = 0; i < payload.size(); ++i)
    {
        quint8 byte = static_cast<quint8>(payload[i]);
        qDebug().nospace() << "Payload[" << i << "]=" << QString::number(byte, 16).rightJustified(2, '0');
    }

    // 4️⃣ If payload contains nested “payload inside payload”
    //     (e.g., subpackets for static speed, gradient, TSR, etc.)
    // int subOffset = 0;
    // while (subOffset + 4 <= payload.size())
    // {
    //     quint8 pktType  = static_cast<quint8>(payload[subOffset]);
    //     quint8 pktCount = static_cast<quint8>(payload[subOffset + 1]);
    //     quint16 pktLen  = qFromBigEndian<quint16>(reinterpret_cast<const uchar*>(payload.constData() + subOffset + 2));

    //     if (pktLen == 0 || subOffset + pktLen > payload.size())
    //         break;

    //     QByteArray subPkt = payload.mid(subOffset, pktLen);

    //     qDebug() << "  ↳ SubPkt Type:" << QString("0x%1").arg(pktType, 2, 16, QLatin1Char('0')).toUpper()
    //              << "Count:" << pktCount
    //              << "Length:" << pktLen;

    //     // Process subpacket
    //     // m_pcKavachParseData->parseIncomingPacket(subPkt);

    //     subOffset += pktLen;
    // }

    // 5️⃣ Pass complete payload for deeper parsing (if required)
    m_pcKavachParseData->parseIncomingPacket(payload);

    // 6️⃣ Extract CRC/MAC (footer)
    uint32_t uicrc = qFromBigEndian<uint32_t>(reinterpret_cast<const uchar*>(macBytes.constData()));
    m_uicrc = uicrc;
    qDebug() << "Extracted CRC/MAC:" << QString("0x%1").arg(m_uicrc, 8, 16, QLatin1Char('0')).toUpper();

    qDebug() << "--- End of Train RRI Message ---\n";
}

void nmsMainWindow::parseTrainTakenOverMsgPacket(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset)
{
    if (byArrdatagram.size() < payloadOffset + sizeof(stTrainTakenOverPkt))
    {
        qWarning() << "Invalid Heart Beat packet size";
        return;
    }

    stTrainTakenOverPkt stTrainTakenOverMsg;
    memcpy(&stTrainTakenOverMsg, byArrdatagram.constData() + payloadOffset, sizeof(stTrainTakenOverPkt));

    // Convert endian for relevant fields
    stTrainTakenOverMsg.usMsgTyp   = qFromBigEndian(stTrainTakenOverMsg.usMsgTyp);
    stTrainTakenOverMsg.usMsgLen = qFromBigEndian(stTrainTakenOverMsg.usMsgLen);

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
    {
        strSenderId.append(QString("%1 ").arg(stTrainTakenOverMsg.ucSenderID[i], 2, 16, QLatin1Char('0')));
    }
    for (int i = 0; i < 20; ++i)
    {
        strReceiverId.append(QString("%1 ").arg(stTrainTakenOverMsg.ucReceiverID[i], 2, 16, QLatin1Char('0')));
    }
    emit SigInsertDBS2STrainTakenOverMsg(stPktHdr,stTrainTakenOverMsg);

}

void nmsMainWindow::parseTrainHandOverCancellationMsgPacket(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset)
{
    if (byArrdatagram.size() < payloadOffset + sizeof(stTrainHandOverCancellationPkt))
    {
        qWarning() << "Invalid Heart Beat packet size";
        return;
    }

    stTrainHandOverCancellationPkt stTrainHandOverCancellationMsg;
    memcpy(&stTrainHandOverCancellationMsg, byArrdatagram.constData() + payloadOffset, sizeof(stTrainHandOverCancellationPkt));

    // Convert endian for relevant fields
    stTrainHandOverCancellationMsg.usMsgTyp   = qFromBigEndian(stTrainHandOverCancellationMsg.usMsgTyp);
    stTrainHandOverCancellationMsg.usMsgLen = qFromBigEndian(stTrainHandOverCancellationMsg.usMsgLen);

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
    {
        strSenderId.append(QString("%1 ").arg(stTrainHandOverCancellationMsg.ucSenderID[i], 2, 16, QLatin1Char('0')));
    }
    for (int i = 0; i < 20; ++i)
    {
        strReceiverId.append(QString("%1 ").arg(stTrainHandOverCancellationMsg.ucReceiverID[i], 2, 16, QLatin1Char('0')));
    }
    emit SigInsertDBS2STrainHandOverCancellationReq(stPktHdr,stTrainHandOverCancellationMsg);
}

void nmsMainWindow::parseTrainLengthInformationPacket(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset)
{
    if (byArrdatagram.size() < payloadOffset + sizeof(stTrainLengthInfoPkt))
    {
        qWarning() << "Invalid Heart Beat packet size";
        return;
    }

    stTrainLengthInfoPkt stTrainLenInfoPkt;
    memcpy(&stTrainLenInfoPkt, byArrdatagram.constData() + payloadOffset, sizeof(stTrainLengthInfoPkt));

    // Convert endian for relevant fields
    stTrainLenInfoPkt.usMsgTyp   = qFromBigEndian(stTrainLenInfoPkt.usMsgTyp);
    stTrainLenInfoPkt.usMsgLen = qFromBigEndian(stTrainLenInfoPkt.usMsgLen);

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
    {
        strSenderId.append(QString("%1 ").arg(stTrainLenInfoPkt.ucSenderID[i], 2, 16, QLatin1Char('0')));
    }
    for (int i = 0; i < 20; ++i)
    {
        strReceiverId.append(QString("%1 ").arg(stTrainLenInfoPkt.ucReceiverID[i], 2, 16, QLatin1Char('0')));
    }
    emit SigInsertDBS2STrainLengthInformationReq(stPktHdr,stTrainLenInfoPkt);

}

void nmsMainWindow::parseTrainLengthInformationAck(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset)
{
    if (byArrdatagram.size() < payloadOffset + sizeof(stTrainLengthInfoAck))
    {
        qWarning() << "Invalid Heart Beat packet size";
        return;
    }

    stTrainLengthInfoAck stTrainLenInfoAck;
    memcpy(&stTrainLenInfoAck, byArrdatagram.constData() + payloadOffset, sizeof(stTrainLengthInfoAck));

    // Convert endian for relevant fields
    stTrainLenInfoAck.usMsgTyp   = qFromBigEndian(stTrainLenInfoAck.usMsgTyp);
    stTrainLenInfoAck.usMsgLen = qFromBigEndian(stTrainLenInfoAck.usMsgLen);

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
    {
        strSenderId.append(QString("%1 ").arg(stTrainLenInfoAck.ucSenderID[i], 2, 16, QLatin1Char('0')));
    }
    for (int i = 0; i < 20; ++i)
    {
        strReceiverId.append(QString("%1 ").arg(stTrainLenInfoAck.ucReceiverID[i], 2, 16, QLatin1Char('0')));
    }
    emit SigInsertDBS2SLengthInformationAck(stPktHdr,stTrainLenInfoAck);

}

void nmsMainWindow::parseTSLRouteReqPacket(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset)
{
    if (byArrdatagram.size() < payloadOffset + sizeof(stTSLReqPkt))
    {
        qWarning() << "Invalid Heart Beat packet size";
        return;
    }

    stTSLReqPkt stTSLRouteReq;
    memcpy(&stTSLRouteReq, byArrdatagram.constData() + payloadOffset, sizeof(stTSLReqPkt));

    // Convert endian for relevant fields
    stTSLRouteReq.usMsgTyp   = qFromBigEndian(stTSLRouteReq.usMsgTyp);
    stTSLRouteReq.usMsgLen = qFromBigEndian(stTSLRouteReq.usMsgLen);

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
    {
        strSenderId.append(QString("%1 ").arg(stTSLRouteReq.ucSenderID[i], 2, 16, QLatin1Char('0')));
    }
    for (int i = 0; i < 20; ++i)
    {
        strReceiverId.append(QString("%1 ").arg(stTSLRouteReq.ucReceiverID[i], 2, 16, QLatin1Char('0')));
    }
    emit SigInsertDBS2STSLRouteRequest(stPktHdr,stTSLRouteReq);
}

void nmsMainWindow::parseTSLInformationPacket(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset)
{
    if (byArrdatagram.size() < payloadOffset + sizeof(stTSLInformationPkt))
    {
        qWarning() << "Invalid Heart Beat packet size";
        return;
    }

    stTSLInformationPkt stTSLInfo;
    memcpy(&stTSLInfo, byArrdatagram.constData() + payloadOffset, sizeof(stTSLInformationPkt));

    // Convert endian for relevant fields
    stTSLInfo.usMsgTyp   = qFromBigEndian(stTSLInfo.usMsgTyp);
    stTSLInfo.usMsgLen = qFromBigEndian(stTSLInfo.usMsgLen);

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
    {
        strSenderId.append(QString("%1 ").arg(stTSLInfo.ucSenderID[i], 2, 16, QLatin1Char('0')));
    }
    for (int i = 0; i < 20; ++i)
    {
        strReceiverId.append(QString("%1 ").arg(stTSLInfo.ucReceiverID[i], 2, 16, QLatin1Char('0')));
    }
    emit SigInsertDBS2STSLAuthorityInformationPkt(stPktHdr,stTSLInfo);
}

void nmsMainWindow::parseFieldElementStatusReqPacket(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset)
{
    if (byArrdatagram.size() < payloadOffset + sizeof(stFieldElementsStatusReqPkt))
    {
        qWarning() << "Invalid Heart Beat packet size";
        return;
    }

    stFieldElementsStatusReqPkt stFieldstsReq;
    memcpy(&stFieldstsReq, byArrdatagram.constData() + payloadOffset, sizeof(stFieldElementsStatusReqPkt));

    // Convert endian for relevant fields
    stFieldstsReq.usMsgTyp   = qFromBigEndian(stFieldstsReq.usMsgTyp);
    stFieldstsReq.usMsgLen = qFromBigEndian(stFieldstsReq.usMsgLen);

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
    {
        strSenderId.append(QString("%1 ").arg(stFieldstsReq.ucSenderID[i], 2, 16, QLatin1Char('0')));
    }
    for (int i = 0; i < 20; ++i)
    {
        strReceiverId.append(QString("%1 ").arg(stFieldstsReq.ucReceiverID[i], 2, 16, QLatin1Char('0')));
    }
    emit SigInsertDBS2SFieldElementsStatusReq(stPktHdr,stFieldstsReq);
}

void nmsMainWindow::parseTrainHandOverCancellationAck(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset)
{
    if (byArrdatagram.size() < payloadOffset + sizeof(stTrainHandOverCancellationAckPkt))
    {
        qWarning() << "Invalid Heart Beat packet size";
        return;
    }

    stTrainHandOverCancellationAckPkt stTrainHandOverCancelAck;
    memcpy(&stTrainHandOverCancelAck, byArrdatagram.constData() + payloadOffset, sizeof(stTrainHandOverCancellationAckPkt));

    // Convert endian for relevant fields
    stTrainHandOverCancelAck.usMsgTyp   = qFromBigEndian(stTrainHandOverCancelAck.usMsgTyp);
    stTrainHandOverCancelAck.usMsgLen = qFromBigEndian(stTrainHandOverCancelAck.usMsgLen);

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
    {
        strSenderId.append(QString("%1 ").arg(stTrainHandOverCancelAck.ucSenderID[i], 2, 16, QLatin1Char('0')));
    }
    for (int i = 0; i < 20; ++i)
    {
        strReceiverId.append(QString("%1 ").arg(stTrainHandOverCancelAck.ucReceiverID[i], 2, 16, QLatin1Char('0')));
    }
    emit SigInsertDBS2STrainHandoverCancellationAck(stPktHdr,stTrainHandOverCancelAck);
}

void nmsMainWindow::SlotStationRegHeader(StationRegularHeader stStnRglrHPkt)
{

    quint64 lastId = m_pcDBQuery->SlotInsertDBStationRegHeader(m_stHeader, stStnRglrHPkt);

    qDebug() << "Last inserted Pkt_Id =" << lastId;
}

void nmsMainWindow::SlotStationconnStatus(QString strHostAddr, bool bStatus)
{
    QString strStationName = m_ipToStationMap.value(strHostAddr);

    emit SigStationisConnected(strStationName,bStatus);

    qDebug() << "Connection Status........" << bStatus <<strStationName << strHostAddr ;
}

void nmsMainWindow::SlotNewFaultPacket(QHostAddress senderIP, quint16 senderPort, QByteArray datagram)
{


    m_strStnSenderIP = senderIP.toString();
    m_usStnSenderPort = senderPort;

    qDebug() << "Sender IP and Port of New Fault :"<<m_strStnSenderIP<<m_usStnSenderPort;


    quint8 ucMsgTyp = static_cast<quint8>(datagram[2]);


    if(ucMsgTyp == 0x00)
    {
        qDebug()<<" Invalid Message Type : ";
    }

    else if (ucMsgTyp == 0x18)                 // OnBoard Packet
    {
        qInfo() << "[GSM Relay] 0x18 OnBoard packet received"
                << "SIZE:" << datagram.size()
                << "HEX:" << datagram.toHex(' ').toUpper();

        qInfo() << "[GSM Relay] m_pcKMS pointer:"
                << static_cast<void *>(m_pcKMS);

        if (m_pcKMS == nullptr)
        {
            qCritical() << "[GSM Relay] ERROR: m_pcKMS is NULL";
        }
        else
        {
            qInfo() << "[GSM Relay] Calling SendUDPViaGSM()";

            bool sent = m_pcKMS->SendUDPViaGSM(
                datagram,
                m_strRelayIP,
                m_usRelayPort);

            qInfo() << "[GSM Relay] SendUDPViaGSM returned:"
                    << sent;
        }


       // SendAckNMStoSKavach(senderIP, senderPort);

        ProcessOnBoardHealthPkt(datagram);
    }

    else if(ucMsgTyp == 0x17)
    {
        ForwardToNMS(datagram);
       // SendAckNMStoSKavach(senderIP, senderPort);
        ProcessStationHealthPkt(datagram);
    }
    else if (ucMsgTyp == 0x19)
    {
        // qInfo() << "[GSM Relay] 0x19 OnBoard Fault Packet received"
        //         << "SIZE:" << datagram.size()
        //         << "HEX:" << datagram.toHex(' ').toUpper();

        // qInfo() << "[GSM Relay] m_pcKMS pointer:"
        //         << static_cast<void *>(m_pcKMS);

        // if (m_pcKMS == nullptr)
        // {
        //     qCritical() << "[GSM Relay] ERROR: m_pcKMS is NULL";
        // }
        // else
        // {
        //     qInfo() << "[GSM Relay] Calling SendUDPViaGSM()";

        //     bool sent = m_pcKMS->SendUDPViaGSM(
        //         datagram,
        //         m_strRelayIP,
        //         m_usRelayPort);

        //     qInfo() << "[GSM Relay] SendUDPViaGSM returned:"
        //             << sent;
        // }

        // IMPORTANT:
        // Process packet FIRST.
        // ACK will be generated inside ProcessStationFaultPkt()
        // only after all validations are successful.
        ForwardToNMS(datagram);
        ProcessStationFaultPkt(datagram);
    }

    else if(ucMsgTyp == 0x13)
    {
        ForwardToNMS(datagram);
      //  SendAckNMStoSKavach(senderIP,senderPort);
        ProcessTSRMSMessagePkt(datagram);
    }
    else if(ucMsgTyp == 0x20)
    {

        qInfo() << "[GSM Relay] 0x20 OnBoard packet received"
                << "SIZE:" << datagram.size()
                << "HEX:" << datagram.toHex(' ').toUpper();

        qInfo() << "[GSM Relay] m_pcKMS pointer:"
                << static_cast<void *>(m_pcKMS);

        if (m_pcKMS == nullptr)
        {
            qCritical() << "[GSM Relay] ERROR: m_pcKMS is NULL";
        }
        else
        {
            qInfo() << "[GSM Relay] Calling SendUDPViaGSM()";

            bool sent = m_pcKMS->SendUDPViaGSM(
                datagram,
                m_strRelayIP,
                m_usRelayPort);

            qInfo() << "[GSM Relay] SendUDPViaGSM returned:"
                    << sent;
        }
       // SendAckNMStoKavach(senderIP, senderPort);
        ProcessLocoRSSIMessagePkt(datagram);

    }

    else if(ucMsgTyp == 0x1D)
    {
      //  SendAckNMStoKavach(senderIP, senderPort);
        ProcessOnBoardEventMsg(datagram);

    }
    else if(ucMsgTyp == 0x1E)
    {
      //  SendAckNMStoKavach(senderIP, senderPort);
        ProcessOnBoardBrakeEventMsg(datagram);

    }
    else if(ucMsgTyp == 0x22)
    {
    //   SendAckNMStoKavach(senderIP, senderPort);
       ProcessOnBoardHealthStsMsg(datagram);

    }

    else if(ucMsgTyp == 0x21)
    {
        ForwardToNMS(datagram);
     //   SendAckNMStoKavach(senderIP, senderPort);
        ProcessStationRSSIMessagePkt(datagram);
    }

    else if(ucMsgTyp == 0x1A)
    {
    //    SendAckNMStoKavach(senderIP, senderPort);
        ProcessStationKavachSysSts(datagram);
    }

    else if(ucMsgTyp == 0x11)
    {
        ForwardToNMS(datagram);
    //    SendAckNMStoKavach(senderIP, senderPort);
        ProcessAccessAuthorityPacket(datagram);
        qDebug()<<"Send Ack IP  and Port : "<<senderIP<<senderPort;

        QString strData = NULL;
        for (char byte : datagram)
        {
            strData.append(QString::asprintf("%02X", static_cast<unsigned char>(byte)));
        }
        QTextStream write(&m_pcStationLogFile);
        write << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << " - "
              << strData << "\n";
    }
    else if(ucMsgTyp == 0x12)
    {
        ForwardToNMS(datagram);
    //    SendAckNMStoKavach(senderIP,senderPort);
        SlotUpadateSchematic(senderIP,senderPort,datagram);

    }
    else if (ucMsgTyp == 0x14)
    {
        ForwardToNMS(datagram);
    //    SendAckNMStoKavach(senderIP, senderPort);
        ProcessS2SPackets(datagram);

    }
    else if (ucMsgTyp == 0x15)
    {
        ForwardToNMS(datagram);
     //   SendAckNMStoKavach(senderIP, senderPort);
        ProcessFieldInputmessage(senderIP,datagram);
    }
    else if (ucMsgTyp == 0x16)
    {
        ForwardToNMS(datagram);
     //   SendAckNMStoKavach(senderIP, senderPort);
        ProcessFieldEventMessage(datagram);
    }
}

void nmsMainWindow::SlotPreviousFaultInfo()
{
    m_pcDBQuery->SlotPrvPromptInfo();
}

void nmsMainWindow::SlottabChanged(int index)
{
    if (index == 0)
    {
        m_pcDBQuery->SlotPrvPromptInfo();
    }
    else if(index==1)
    {
        m_pcDBQuery->SlotStationInfo();
    }
    else
    {
        m_pcDBQuery->SlotLocoInfo();
    }
}

void nmsMainWindow::SlotUpadateSchematic(QHostAddress senderIP, quint16 senderPort, QByteArray datagram)
{
    QString strIP = senderIP.toString();
    QString strIPAddr = strIP.section("::ffff:",1,1);


    QString strStationName = m_ipToStationMap.value(strIPAddr, nullptr);

    const int headerSize = sizeof(stAccessRequestPkt);
    const int footerSize = 7;           // 1 byte MA count + 2 bytes Route ID + 4 bytes CRC
    const int requiredBits = 194;       // Total bits required for decoding fields
    const int requiredBytes = (requiredBits + 7) / 8;  // ceil(194 / 8) = 25 bytes
    const int minPacketSize = headerSize + requiredBytes + footerSize;

    if (datagram.size() < minPacketSize)
    {
        qWarning() << "[Schematic] Datagram too short. Received:" << datagram.size()
        << "Expected minimum:" << minPacketSize;
        return;
    }
    memcpy(&m_stHeader, datagram.constData(), sizeof(m_stHeader));

    m_stHeader.usStartFrame = qFromBigEndian(m_stHeader.usStartFrame);
    m_stHeader.usMsgLength  = qFromBigEndian(m_stHeader.usMsgLength);
    m_stHeader.usStatKavachID = qFromBigEndian(m_stHeader.usStatKavachID);
    m_stHeader.usNMSID      = qFromBigEndian(m_stHeader.usNMSID);

    int offset = sizeof(stAccessRequestPkt);
    int remaining = datagram.size() - offset;
    if (remaining < (1 + 2 + 4))
    {
        qWarning() << "Packet too short for footer";
        return;
    }

    int txBufferLen = remaining - (1 + 2 + 4);  // subtract footer

    QByteArray txBuffer = datagram.mid(offset, txBufferLen);
    offset += txBufferLen;

    if (txBuffer.size() < requiredBytes)
    {
        qWarning() << "[Schematic] txBuffer too short. Size:" << txBuffer.size()
        << "Expected at least:" << requiredBytes;
        return;
    }
    QVector<bool> bits;
    for (const auto &byte : txBuffer)
    {
        quint8 ubyte = static_cast<quint8>(byte);
        for (int b = 7; b >= 0; --b)
            bits.append((ubyte >> b) & 0x01);
    }
    if (bits.size() < requiredBits)
    {
        qWarning() << "[Schematic] Not enough bits to decode. Got:" << bits.size()
        << "Expected:" << requiredBits;
        return;
    }

    // Then read footer
    quint8 maSectionCount = static_cast<quint8>(datagram[offset]);
    quint16 routeId = qFromBigEndian<quint16>(reinterpret_cast<const uchar *>(datagram.constData() + offset + 1));
    uint32_t crc = qFromBigEndian<uint32_t>(reinterpret_cast<const uchar *>(datagram.constData() + offset + 3));

    int idx = 0;
    QString strLocoMode = NULL,
        strEmrgSts = NULL ,
        strFirmname = NULL,
        strMsgType  = NULL;
    uint32_t pkt_type             = ExtractBits(bits, idx, 4);

    uint32_t pkt_length = 0, frame_num = 0, source_loco_id = 0, source_loco_version =0,abs_loco_loc = 0,
        uil_doubtover = 0, uil_doubtunder = 0, uitrain_int = 0,train_length = 0, train_speed = 0,
        move_memnt_dir = 0,emergency_status =0, loco_mode = 0, approaching_station_id = 0,
        last_rfid_tag = 0, uiTag_dup = 0, uiTagLinkInfo = 0,tin_no = 0,uiBreakApplyd = 0,
        uiNewmaReply = 0,uiLastRefProfNo = 0,uiSigOV = 0,uiInfoAck =0,uiSpare =0,uiLocoHlthSts = 0,
        longitude = 0,latitude =0,loco_random_rl =0,uiMACCode = 0,uiPktCRC = 0;

    if(pkt_type == 0xD)
    {
        m_strLastPkt = "L -> AccReq";

        pkt_length           = ExtractBits(bits, idx, 7);
        frame_num            = ExtractBits(bits, idx, 17);
        source_loco_id       = ExtractBits(bits, idx, 20);
        source_loco_version  = ExtractBits(bits, idx, 3);
        abs_loco_loc         = ExtractBits(bits, idx, 23);
        train_length         = ExtractBits(bits, idx, 11);
        train_speed          = ExtractBits(bits, idx, 9);
        move_memnt_dir       = ExtractBits(bits, idx, 2);
        emergency_status     = ExtractBits(bits, idx, 3);
        loco_mode            = ExtractBits(bits, idx, 4);
        approaching_station_id = ExtractBits(bits, idx, 16);
        last_rfid_tag        = ExtractBits(bits, idx, 10);
        tin_no               = ExtractBits(bits, idx, 8);
        longitude            = ExtractBits(bits, idx, 21);
        latitude             = ExtractBits(bits, idx, 20);
        loco_random_rl       = ExtractBits(bits, idx, 16);
        uiMACCode            = ExtractBits(bits, idx, 32);
        uiPktCRC             = ExtractBits(bits, idx, 32);

        // strLocoMode =GetLocoMode(loco_mode);
        // strEmrgSts = GetEmergencyStatus(emergency_status);
        if(abs_loco_loc != 0)                                                // TEMPORARY ADD REMOVE LATER
        {
            emit SigAccessReqInsertintoDB(m_stHeader,pkt_type,pkt_length,frame_num,source_loco_id,source_loco_version,
                                          abs_loco_loc,train_length,train_speed,move_memnt_dir,emergency_status,
                                          loco_mode,approaching_station_id,last_rfid_tag,tin_no,longitude,latitude,
                                          loco_random_rl,uiMACCode,uiPktCRC,maSectionCount,routeId,crc);
        }
        QTextStream write(&m_pcLocoLogFile);

        write << "---- Packet Received: " <<"\n";
        // << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << " ----\n";

        write << "  StartFrame: " << QString("0x%1").arg(m_stHeader.usStartFrame, 4, 16, QChar('0')).toUpper() << "\n"
              << "  MsgType: " << QString("0x%1").arg(m_stHeader.ucMsgType, 2, 16, QChar('0')).toUpper() << "\n"
              << "  MsgLength: " << m_stHeader.usMsgLength << "\n"
              << "  KavachID: " << m_stHeader.usStatKavachID << "\n"
              << "  NMSID: " << m_stHeader.usNMSID << "\n"
              << "  version   : " << m_stHeader.ucVersion << "\n"
              << "  Date: " << m_stHeader.ucDate << "\n"
              << "  Time: " << m_stHeader.ucTime << "\n"
              << "  Nma Active Radio: " << m_stHeader.ucRadioType << "\n"
              << "  SOF_tx_Byte1: " << m_stHeader.ucSOF1 << "\n"
              << "  SOF_tx_Byte2: " << m_stHeader.ucSOF2 << "\n"
              << "  pkt_type: " << pkt_type << "\n"
              << "  pkt_length: " << pkt_length << "\n"
              << "  frame_num: " << frame_num << "\n"
              << "  source_loco_id: " << source_loco_id << "\n"
              << "  abs_loco_loc: " << abs_loco_loc << "\n"
              << "  train_length: " << train_length << "\n"
              << "  train_speed: " << train_speed << "\n"
              << "  move_dir: " << move_memnt_dir << "\n"
              << "  LocoMode: " << strLocoMode << "\n"
              << "  Emergency: " << strEmrgSts << "\n"
              << "  MA Count: " << (int)maSectionCount << "\n"
              << "  RouteID: " << routeId<< "\n"
              << "  CRC: " << crc << "\n";

        write << "----------------------------------------------------------\n";

        write.flush();   // ensures it’s written immediately
    }
    else
    {
        m_strLastPkt = "L -> LocoReg";

        pkt_length           = ExtractBits(bits, idx, 7);
        frame_num            = ExtractBits(bits, idx, 17);
        source_loco_id       = ExtractBits(bits, idx, 20);
        source_loco_version  = ExtractBits(bits, idx, 3);
        abs_loco_loc         = ExtractBits(bits, idx, 23);

        uil_doubtover        = ExtractBits(bits, idx, 9);
        uil_doubtunder       = ExtractBits(bits, idx, 9);
        uitrain_int          = ExtractBits(bits, idx, 2);
        train_length         = ExtractBits(bits, idx, 11);
        train_speed          = ExtractBits(bits, idx, 9);
        move_memnt_dir       = ExtractBits(bits, idx, 2);
        emergency_status     = ExtractBits(bits, idx, 3);
        loco_mode            = ExtractBits(bits, idx, 4);
        last_rfid_tag        = ExtractBits(bits, idx, 10);
        uiTag_dup            = ExtractBits(bits, idx, 1);
        uiTagLinkInfo        = ExtractBits(bits, idx, 3);
        tin_no               = ExtractBits(bits, idx, 9);

        uiBreakApplyd        = ExtractBits(bits, idx, 3);
        uiNewmaReply         = ExtractBits(bits, idx, 2);
        uiLastRefProfNo      = ExtractBits(bits, idx, 4);
        uiSigOV              = ExtractBits(bits, idx, 1);
        uiInfoAck            = ExtractBits(bits, idx, 4);
        uiSpare              = ExtractBits(bits, idx, 2);
        // uiLocoHlthSts        = ExtractBits(bits, idx, 6);
        uint8_t ucLocoHlthSts = ExtractBits(bits, idx, 6);  // 6-bit health from frame
        static uint32_t locoHealthWord = 0;                  // server-side, full 24-bit health

        uint8_t last3 = frame_num & 0x7;  // get last 3 bits of frame_num
        int groupIndex = -1;
        if (last3 == 0b001)
        {
            groupIndex = 0;
        }
        else if (last3 == 0b011)
        {
            groupIndex = 1;
        }
        else if (last3 == 0b101)
        {
            groupIndex = 2;
        }
        else if (last3 == 0b111)
        {
            groupIndex = 3;
        }
        QStringList strlstFaultsMsg;
        QList<uint16_t> lstFaultsCode;

        if (groupIndex >= 0)
        {
            // insert new 6-bit group into 24-bit word
            locoHealthWord &= ~(0x3F << (groupIndex * 6)); // clear old bits
            locoHealthWord |= (ucLocoHlthSts & 0x3F) << (groupIndex * 6);

            // Only show **current group** faults
            for (int bit = 0; bit < 6; ++bit)
            {
                if ((ucLocoHlthSts >> bit) & 0x01)
                {
                    int faultIndex = groupIndex * 6 + bit;  // global fault number
                    lstFaultsCode.append(faultIndex+1);
                    QString desc = GetFaultsCodeDescription(faultIndex + 1);
                    strlstFaultsMsg.append(desc);
                    qDebug() << "Active Fault (current group only)" << (faultIndex + 1) << ":" << desc;
                }
            }
        }
        else
        {
            qDebug() << "frame_num:" << frame_num
                     << "last3:" << QString::number(last3, 2).rightJustified(3, '0')
                     << "no group selected";
        }
        // optional debug

        strMsgType = "Prompts";

        QString timestamp = QDateTime::currentDateTime().toString("dd-MMM-yy hh:mm:ss");
        strFirmname = m_pcDBQuery->GetLocoFirmName(source_loco_id);

        QString strFaultsDesc = strlstFaultsMsg.join(",");

        QString mobileNumber = m_pcDBQuery->GetMobileNumberForName(strFirmname);

        if(!strFaultsDesc.isEmpty())
        {
            emit SigFaultMsginserttoDB(strMsgType,timestamp,lstFaultsCode,strFirmname,source_loco_id);

            QString strFirmID = strFirmname + ":" + QString::number(source_loco_id);


            emit SigSendFaultmessage(strMsgType,timestamp,strFirmID,strFaultsDesc);
            strMsgType = "SMS";
            emit SigSMSFaultMsginserttoDB(strMsgType,timestamp, lstFaultsCode,strFirmID);

            if(m_strFaultMsg != strFaultsDesc)
            {
                m_strFaultMsg = "\0";
                m_strFaultMsg.append(strFaultsDesc);
                SendSMS(mobileNumber,strFaultsDesc);
            }
        }
        else
        {
            strFaultsDesc = "No Fault";
        }

        // strLocoMode =GetLocoMode(loco_mode);
        // strEmrgSts = GetEmergencyStatus(emergency_status);
        if(abs_loco_loc != 0)
        {
            emit SigLocoRegularInsertintoDB(m_stHeader,pkt_type,pkt_length,frame_num,source_loco_id,source_loco_version,
                                            abs_loco_loc,uil_doubtover,uil_doubtunder,uitrain_int,train_length,
                                            train_speed,move_memnt_dir,emergency_status,
                                            loco_mode,last_rfid_tag,uiTag_dup,uiTagLinkInfo,tin_no,
                                            uiBreakApplyd,uiNewmaReply,uiLastRefProfNo,uiSigOV,uiInfoAck,
                                            uiSpare,strFaultsDesc,uiMACCode,uiPktCRC,maSectionCount,routeId,crc);
        }
    }

    int tin = tin_no;        // Extracted from UDP/Kavach packet
    double absLocMeters = abs_loco_loc;

}

uint32_t nmsMainWindow::ExtractBits(const QVector<bool> &bits, int &index, int bitCount)
{
    if (index + bitCount > bits.size()) {
        qCritical() << "[ExtractBits] Out of range! Requested:" << (index + bitCount)
        << "Available:" << bits.size();
        return 0; // Or throw or handle error
    }

    uint32_t result = 0;
    for (int i = 0; i < bitCount; ++i)
    {
        result <<= 1;
        result |= bits[index++];
    }
    return result;
}

void nmsMainWindow::ComputeEVLAppCRC()
{
    QString exePath = QCoreApplication::applicationFilePath();
    QFile f(exePath);
    if (!f.open(QIODevice::ReadOnly))
    {
        qWarning() << "ComputeEVLAppCRC: failed to open" << exePath << f.errorString();
        m_uiEVLAppCRC = 0;
        return;
    }

    QByteArray data = f.readAll();
    f.close();

    m_uiEVLAppCRC = CalcCRC32(data);
    qDebug() << "EVL Application CRC32:" << Qt::hex << m_uiEVLAppCRC
             << "computed over" << data.size() << "bytes from" << exePath;
}

void nmsMainWindow::InitnmsDBConnections()
{


    m_pcDBQuery = new nmsDBQuerys(m_pcDB);

    connect(this, SIGNAL(SigFaultPktInserttoDB(stKavachtoNMS*,QString,QString)),
            m_pcDBQuery,SLOT(SlotFaultPktInserttoDB(stKavachtoNMS*,QString,QString)));

    connect (this, SIGNAL(SigStnFaultPktInserttoDB(stStationFaults*,QStringList,
                                                  QStringList,QStringList,QStringList)),
            m_pcDBQuery,SLOT(SlotStnFaultPktInserttoDB(stStationFaults*,QStringList,
                                                      QStringList,QStringList,QStringList)));

    connect(this,SIGNAL(SigStationInfo()),m_pcDBQuery,SLOT(SlotStationInfo()));

    connect(this,SIGNAL(SigFaultMsginserttoDB(QString,QString,QList<uint16_t>,QString,uint32_t)),
            m_pcDBQuery,SLOT(SlotFaultMsginserttoDB(QString,QString,QList<uint16_t>,QString,uint32_t)));

    connect(this,SIGNAL(SigStnFaultMsginserttoDB(QString,QString,uint16_t,QString,uint32_t)),
            m_pcDBQuery,SLOT(SlotStnFaultMsginserttoDB(QString,QString,uint16_t,QString,uint32_t)));

    connect(this,SIGNAL(SigSMSFaultMsginserttoDB(QString,QString,QList<uint16_t>,QString)),
            m_pcDBQuery,SLOT(SlotSMSFaultMsginserttoDB(QString,QString,QList<uint16_t>,QString))); // temporary

    connect(this,SIGNAL(SigSMSStnFaultMsginserttoDB(QString,QString,uint16_t,QString)),
            m_pcDBQuery,SLOT(SlotSMSStnFaultMsginserttoDB(QString,QString,uint16_t,QString))); // temporary

    connect(this, SIGNAL(SigAccessReqInsertintoDB(stAccessRequestPkt,uint32_t,uint32_t,uint32_t,
                                                  uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,
                                                  uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,
                                                  uint32_t,uint32_t,uint32_t,uint32_t,
                                                  uint32_t,uint32_t,uint8_t,uint16_t,uint32_t)),
            m_pcDBQuery,SLOT(SlotAccessReqInsertintoDB(stAccessRequestPkt,uint32_t,uint32_t,uint32_t,
                                           uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,
                                           uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,
                                           uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,
                                           uint32_t,uint8_t,uint16_t,uint32_t)));



    connect(this, SIGNAL(SigLocoRegularInsertintoDB(stAccessRequestPkt,uint32_t,uint32_t,uint32_t,
                                                    uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,
                                                    uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,
                                                    uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,
                                                    uint32_t,uint32_t,uint32_t,QString,uint32_t,uint32_t,
                                                    uint8_t,uint16_t,uint32_t)),
            m_pcDBQuery,SLOT(SlotLocoRegularInsertintoDB(stAccessRequestPkt,uint32_t,uint32_t,uint32_t,
                                             uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,
                                             uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,
                                             uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,
                                             uint32_t,uint32_t,uint32_t,QString,uint32_t,uint32_t,
                                             uint8_t,uint16_t,uint32_t)));

    connect(this,SIGNAL(SigAccessAuthorityPktInsertintoDB(stAccessRequestPkt,uint32_t,uint32_t,
                                                           uint32_t,uint32_t,uint32_t,uint32_t,
                                                           uint32_t ,uint32_t ,uint32_t ,uint32_t ,
                                                           uint32_t ,uint32_t ,uint32_t ,uint32_t,uint32_t)),
            m_pcDBQuery,SLOT(SlotAccessAuthorityPktInsertintoDB(stAccessRequestPkt,uint32_t,uint32_t,
                                                    uint32_t,uint32_t,uint32_t,uint32_t,
                                                    uint32_t ,uint32_t ,uint32_t ,uint32_t ,
                                                    uint32_t ,uint32_t ,uint32_t ,uint32_t,uint32_t)));

    connect(this,SIGNAL(SigAdditionalEmergencyPktInsertintoDB(stAccessRequestPkt ,uint32_t ,uint32_t ,
                                                               uint32_t ,uint32_t ,uint32_t ,uint32_t ,
                                                               uint32_t ,uint32_t)),
            m_pcDBQuery,SLOT(SlotAdditionalEmergencyPktInsertintoDB(stAccessRequestPkt ,uint32_t ,uint32_t,
                                                        uint32_t ,uint32_t ,uint32_t ,uint32_t ,
                                                        uint32_t ,uint32_t )));

    connect(this, SIGNAL(SigInsertDBStationhealthPkt(stStationHealthPkt,QStringList,QStringList,uint32_t)),
            m_pcDBQuery,SLOT(SlotInsertDBStationhealthPkt(stStationHealthPkt,QStringList,QStringList,uint32_t)));

    connect(this, SIGNAL(SigInsertDBOnBoardhealthPkt(stOnBoardHealthPkt,QString,QString,uint32_t)),
            m_pcDBQuery,SLOT(SlotInsertDBOnBoardhealthPkt(stOnBoardHealthPkt,QString,QString,uint32_t)));



    connect (this,SIGNAL(SigInsertDBS2SPDIVerCmd(stPacketHeader,stPDIVerCheckCmdPkt)),
            m_pcDBQuery,SLOT(SlotInsertDBS2SPDIVerCmd(stPacketHeader,stPDIVerCheckCmdPkt)));

    connect (this,SIGNAL(SigInsertDBS2SPDIVerMsg(stPacketHeader,stPDIVerCheckMsgPkt)),
            m_pcDBQuery,SLOT(SlotInsertDBS2SPDIVerMsg(stPacketHeader,stPDIVerCheckMsgPkt)));

    connect (this,SIGNAL(SigInsertDBS2SHeartBeat(stPacketHeader,stHeartBeatPkt)),
            m_pcDBQuery,SLOT(SlotInsertDBS2SHeartBeat(stPacketHeader,stHeartBeatPkt)));

    connect (this,SIGNAL(SigInsertDBS2STrainHandOverReq(stPacketHeader,stTrainHandOverReqPkt)),
            m_pcDBQuery,SLOT(SlotInsertDBS2STrainHandOverReq(stPacketHeader,stTrainHandOverReqPkt)));

    connect (this,SIGNAL(SigInsertDBS2STrainTakenOverMsg(stPacketHeader,stTrainTakenOverPkt)),
            m_pcDBQuery,SLOT(SlotInsertDBS2STrainTakenOverMsg(stPacketHeader,stTrainTakenOverPkt)));


    connect (this,SIGNAL(SigInsertDBS2STrainHandOverCancellationReq(stPacketHeader,stTrainHandOverCancellationPkt)),
            m_pcDBQuery,SLOT(SlotInsertDBS2STrainHandOverCancellationReq(stPacketHeader,stTrainHandOverCancellationPkt)));

    connect (this,SIGNAL(SigInsertDBS2STrainLengthInformationReq(stPacketHeader,stTrainLengthInfoPkt)),
            m_pcDBQuery,SLOT(SlotInsertDBS2STrainLengthInformationReq(stPacketHeader,stTrainLengthInfoPkt)));

    connect (this,SIGNAL(SigInsertDBS2SLengthInformationAck(stPacketHeader,stTrainLengthInfoAck)),
            m_pcDBQuery,SLOT(SlotInsertDBS2SLengthInformationAck(stPacketHeader,stTrainLengthInfoAck)));

    connect (this,SIGNAL(SigInsertDBS2STSLRouteRequest(stPacketHeader,stTSLReqPkt)),
            m_pcDBQuery,SLOT(SlotInsertDBS2STSLRouteRequest(stPacketHeader,stTSLReqPkt)));

    connect (this,SIGNAL(SigInsertDBS2STSLAuthorityInformationPkt(stPacketHeader,stTSLInformationPkt)),
            m_pcDBQuery,SLOT(SlotInsertDBS2STSLAuthorityInformationPkt(stPacketHeader,stTSLInformationPkt)));

    connect (this,SIGNAL(SigInsertDBS2SFieldElementsStatusReq(stPacketHeader,stFieldElementsStatusReqPkt)),
            m_pcDBQuery,SLOT(SlotInsertDBS2SFieldElementsStatusReq(stPacketHeader,stFieldElementsStatusReqPkt)));

    connect (this,SIGNAL(SigInsertDBS2STrainHandoverCancellationAck(stPacketHeader,stTrainHandOverCancellationAckPkt)),
            m_pcDBQuery,SLOT(SlotInsertDBS2STrainHandoverCancellationAck(stPacketHeader,stTrainHandOverCancellationAckPkt)));


    connect(this, SIGNAL(SigInsertDBLocoRSSIMessage(stLocoRSSIMsg)),
            m_pcDBQuery,SLOT(SlotInsertDBLocoRSSIMessage(stLocoRSSIMsg)));

    connect(this, SIGNAL(SigInsertDBOnBoardEventMessage(stOnboardKavachEventMsg)),   //On-Board Event Message
            m_pcDBQuery,SLOT(SlotInsertDBOnBoardEventMsg(stOnboardKavachEventMsg)));

    connect(this, SIGNAL(SigInsertDBOnBoardBrakeEventMsg(stOnboardKavachBrakeEventMsg)),   //On-Board Brake Event Message
            m_pcDBQuery,SLOT(SlotInsertDBOnBoardBrakeEventMsg(stOnboardKavachBrakeEventMsg)));

    connect(this, SIGNAL(SigInsertDBOnBoardSystemHealthMsg(stOnboardKavachBOKSHealthMsg)),   //On-Board Health System Status Message
            m_pcDBQuery,SLOT(SlotInsertDBOnboardBOKSHealthMsg(stOnboardKavachBOKSHealthMsg)));

    connect(this, SIGNAL(SigInsertDBStationRSSIMessage(stStationRSSIMsg)),
            m_pcDBQuery,SLOT(SlotInsertDBStationRSSIMessage(stStationRSSIMsg)));

    connect(this, SIGNAL(SigInsertDBStationKavachSysSts(stStationaryKavachSysInfo)),   //SKavchSys
            m_pcDBQuery,SLOT(SlotInsertDBStatioKavachSysSts(stStationaryKavachSysInfo)));

    connect(this,SIGNAL(SigInsertDBFieldInputStatus(stPacketHeader,uint16_t,QByteArray,uint32_t)),
            m_pcDBQuery, SLOT(SlotInsertDBFieldInputStatus(stPacketHeader,uint16_t,QByteArray,uint32_t)));

    connect (this,SIGNAL(SigInsertDBFieldInputEventData(stFieldEventData)),
            m_pcDBQuery,SLOT(SlotInsertDBFieldInputEventData(stFieldEventData)));

}

void nmsMainWindow::InitNMSForwarder()
{
    m_strNMSIP  = m_ocCfgSettings->value("NMS/NMS_IP").toString();
    m_usNMSPort = static_cast<quint16>(
        m_ocCfgSettings->value("NMS/NMS_Port").toInt());

    m_pcNMSSocket = new QUdpSocket(this);

    qDebug() << "[NMS Forwarder] Will forward packets to"
             << m_strNMSIP << "port:" << m_usNMSPort;
}

// ── IsPriorityPacket ─────────────────────────────────────────────────────
//  Returns true for the five packet types that must still be forwarded
//  to the NMS even when the NMS application is not connected (but the
//  IP is reachable via ping).
//
//  0x11  Station Regular Packet
//  0x12  Loco Regular Packet
//  0x13  TSR/MS Message
//  0x14  Station-to-Station
//  0x19  Station Fault Packet
// ─────────────────────────────────────────────────────────────────────────
bool nmsMainWindow::IsPriorityPacket(quint8 ucType)
{
    switch (ucType)
    {
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x19:
        return true;
    default:
        return false;
    }
}

// ── ProbeNMSApp ───────────────────────────────────────────────────────────
//  Sends a single 1-byte UDP probe to the NMS IP:Port.
//  If the NMS application is running it will silently discard the probe.
//  If the port is closed the OS returns ICMP port-unreachable, which Qt
//  surfaces as QAbstractSocket::ConnectionRefusedError on the next
//  read/write attempt.
//
//  We use a temporary bound socket so we can detect the error:
//    1. bind to any local port
//    2. send 1 probe byte to NMS port
//    3. wait up to 300 ms for an error (ICMP back) or timeout
//    4. timeout → app is up (no ICMP back = port is open)
//       error   → app is down (ICMP port-unreachable received)
// ─────────────────────────────────────────────────────────────────────────
bool nmsMainWindow::ProbeNMSApp()
{
    QUdpSocket probe;

    // Bind on any free port
    if (!probe.bind(QHostAddress::Any, 0))
    {
        qWarning() << "[ProbeNMS] bind failed:" << probe.errorString();
        return false;   // assume down
    }

    // Send 1-byte probe
    QByteArray probeByte(1, 0x00);
    probe.writeDatagram(probeByte, QHostAddress(m_strNMSIP), m_usNMSPort);

    // Wait up to 300 ms
    // If the NMS port is closed the kernel sends back ICMP port-unreachable.
    // waitForReadyRead() returns false on error too — check error explicitly.
    bool anyActivity = probe.waitForReadyRead(300);

    if (!anyActivity)
    {
        QAbstractSocket::SocketError err = probe.error();

        if (err == QAbstractSocket::ConnectionRefusedError)
        {
            // ICMP port-unreachable received — NMS app is NOT running
            qDebug() << "[ProbeNMS] NMS application is DOWN (port refused)";
            return false;
        }

        // Timeout with no error — NMS app accepted the probe silently → UP
        qDebug() << "[ProbeNMS] NMS application is UP (probe timeout = port open)";
        return true;
    }

    // Got data back — NMS is up (it sent something)
    qDebug() << "[ProbeNMS] NMS application is UP (data received)";
    return true;
}

// ── ForwardToNMS ─────────────────────────────────────────────────────────
//
//  Three states:
//
//  1. m_bNMSOffline == true  (ping fails)
//     → Log to DB only. Do NOT send anything.
//       (replay happens when ping recovers)
//
//  2. m_bNMSAppDown == true  (ping OK, NMS app not responding)
//     → Send ONLY priority packet types: 0x11 0x12 0x13 0x14 0x19
//     → All other types are silently dropped (still logged to DB).
//
//  3. Both false  (NMS fully up)
//     → Send all packets immediately.
// ─────────────────────────────────────────────────────────────────────────
void nmsMainWindow::ForwardToNMS(QByteArray datagram)
{
    // ── LAN path: direct to local NMS ────────────────────────
    qint64 sent = m_pcNMSSocket->writeDatagram(
        datagram,
        QHostAddress(m_strNMSIP),
        m_usNMSPort);

    if (sent == -1)
        qWarning() << "[NMS Forwarder] LAN send FAILED:"
                   << m_pcNMSSocket->errorString();
    else
        qDebug() << "[NMS Forwarder] LAN forwarded to NMS"
                 << m_strNMSIP << ":" << m_usNMSPort
                 << "size:" << sent;

    // ── GSM path: via relay server ────────────────────────────

}

void nmsMainWindow::ForwardViaGSM(const QByteArray &datagram)
{
    if (!m_pcRelaySocket)
    {
        qWarning() << "[GSM Relay] Socket not initialised";
        return;
    }

    qint64 sent = m_pcRelaySocket->writeDatagram(
        datagram,
        QHostAddress(m_strRelayIP),
        m_usRelayPort);

    if (sent == -1)
        qWarning() << "[GSM Relay] Send FAILED:" << m_pcRelaySocket->errorString();
    else
        qDebug() << "[GSM Relay] Forwarded via relay"
                 << m_strRelayIP << ":" << m_usRelayPort
                 << "bytes:" << sent;
}

void nmsMainWindow::SendAckNMStoKavach(QHostAddress senderIP, quint16 senderPort)
{
    QString strIP = senderIP.toString();
    QString strIPAddr = strIP.section("::ffff:",1,1);
    qDebug()<<" Tx Ack IP and Port : "<<senderIP<<senderPort;
    // QString strPort = m_ipToStationPortMap.value(strIPAddr,nullptr);

    stNMStoKavach *pstAck = new stNMStoKavach;
    memset(pstAck,0,sizeof(stNMStoKavach));

    pstAck->usStartFrame = m_stHeader.usStartFrame;  // Little endian format (if needed)

    pstAck->ucMsgType = 0x1F;

    pstAck->usmsgLength = 0;
    pstAck->usMsgSeq = m_stHeader.usMsgSeq;//m_usSeqNum++;
    pstAck->usNMSSystemID = m_stHeader.usNMSID;

    quint16 usKavachID = m_stHeader.usStatKavachID;

    quint16 usSKavID = qToBigEndian(usKavachID);

    pstAck->ucKavachSubsysID[0] = 0x00;
    pstAck->ucKavachSubsysID[1] = (usSKavID >> 8) & 0xFF;
    pstAck->ucKavachSubsysID[2] = usSKavID & 0xFF;

    pstAck->ucKavachType = m_stHeader.ucMsgType;  // Adjust based on your logic/UI

    quint16 msgLength = sizeof(stNMStoKavach) - 2;
    quint16 usMshLen = qToBigEndian(msgLength);
    pstAck->usmsgLength = usMshLen;

    const quint8* pData = reinterpret_cast<const quint8*>(pstAck);
    const quint8* pCrcStart = pData + 2;

    uint32_t crcLength = msgLength - 4;

    quint32 crc = CalculateCRC32(crcLength, pCrcStart);

    quint32 crcBE = qToBigEndian(crc);
    memcpy(&pstAck->uiCRC, &crcBE, sizeof(crcBE));

    qDebug()<<" Tx Ack IP and Port1 : "<<senderIP<<senderPort;
    emit SigSendAckNMStoKavach(senderIP, senderPort,pstAck);

}

void nmsMainWindow::SendAckNMStoSKavach(QHostAddress senderIP, quint16 senderPort)
{
    QString strIP = senderIP.toString();
    QString strIPAddr = strIP.section("::ffff:",1,1);
    QString strPort = QString::number(senderPort);

    stNMStoKavach *pstAck = new stNMStoKavach;
    memset(pstAck,0,sizeof(stNMStoKavach));

    pstAck->usStartFrame = m_stPktHdr.usStartFrame;  // Little endian format (if needed)

    pstAck->ucMsgType = 0x1F;

    pstAck->usmsgLength = 0;
    pstAck->usMsgSeq = m_stPktHdr.usMsgSeq;//m_usSeqNum++;
    pstAck->usNMSSystemID = m_stPktHdr.usNMSID;

    // QString strKAVSubSystemID =

    quint16 usKavachID = m_stPktHdr.usStatKavachID;

    quint16 usSKavID = qToBigEndian(usKavachID);

    pstAck->ucKavachSubsysID[0] = 0x00;
    pstAck->ucKavachSubsysID[1] = (usSKavID >> 8) & 0xFF;
    pstAck->ucKavachSubsysID[2] = usSKavID & 0xFF;

    if(m_stPktHdr.ucMsgType == 13)
    {
        pstAck->ucKavachType = 33;
    }
    else
    {
        pstAck->ucKavachType = m_stPktHdr.ucMsgType;  // Adjust based on your logic/UI
    }

    quint16 msgLength = sizeof(stNMStoKavach) - 2;
    quint16 usMshLen = qToBigEndian(msgLength);
    pstAck->usmsgLength = usMshLen;

    const quint8* pData = reinterpret_cast<const quint8*>(pstAck);
    const quint8* pCrcStart = pData + 2;

    uint32_t crcLength = msgLength - 4;

    quint32 crc = CalculateCRC32(crcLength, pCrcStart);

    quint32 crcBE = qToBigEndian(crc);
    memcpy(&pstAck->uiCRC, &crcBE, sizeof(crcBE));

    emit SigSendAckNMStoKavach(senderIP, strPort.toUInt(),pstAck);
}


void nmsMainWindow::SendAckNMStoSKavachFaults(QHostAddress senderIP, quint16 senderPort)
{
    qDebug()<<" Sending Ack to the Ip and Port :  "<<senderIP<<senderPort;
    // QString strIP = senderIP.toString();
    // QString strIPAddr = strIP.section("::ffff:",1,1);
    // quint16 strPort = senderPort;

    stNMStoKavach *pstAck = new stNMStoKavach;
    memset(pstAck,0,sizeof(stNMStoKavach));

    pstAck->usStartFrame = m_pcFaultpkt->usStartFrame;  // Little endian format (if needed)

    pstAck->ucMsgType = 0x1F;

    pstAck->usmsgLength = 0;
    pstAck->usMsgSeq = m_pcFaultpkt->usMsgSeq;//m_usSeqNum++;

    qDebug ()<<"Sequence Number for 0x19 Fault Packet : "<<pstAck->usMsgSeq;

    pstAck->usNMSSystemID = m_pcFaultpkt->usNMSID;

   // memcpy(pstAck->ucKavachSubsysID,m_pcFaultpkt->ucKavachSubsysID, 2);
    pstAck->ucKavachType = m_pcFaultpkt->ucMsgType;  // Adjust based on your logic/UI

    quint16 msgLength = sizeof(stNMStoKavach) - 2;
    quint16 usMshLen = qToBigEndian(msgLength);
    pstAck->usmsgLength = usMshLen;

    const quint8* pData = reinterpret_cast<const quint8*>(pstAck);
    const quint8* pCrcStart = pData + 2;

    uint32_t crcLength = msgLength - 4;

    quint32 crc = CalculateCRC32(crcLength, pCrcStart);

    quint32 crcBE = qToBigEndian(crc);
    memcpy(&pstAck->uiCRC, &crcBE, sizeof(crcBE));

    emit SigSendAckNMStoKavach(senderIP, senderPort,pstAck);

}

// ============================================================
//  SendFaultPktAck  —  Builds & sends the 0x1F ACK for a
//  received Fault Code Packet (Station 0x19 / Onboard 0x19),
//  per ICD field layout:
//
//    [0-1]   SOF                0xBBBB
//    [2]     Message Type       0x1F
//    [3-4]   Message Length     MsgType..CRC inclusive (=15)
//    [5-6]   Message Sequence   last received Kavach seq num
//    [7-8]   NMS System ID
//    [9-11]  Onboard/Station KAVACH ID  (3 bytes, 1-65535)
//    [12]    KAVACH Subsystem Type      (0x11 / 0x22 / 0x33)
//    [13-16] CRC32 (CCITT 0x04C11DB7), computed over
//            bytes[2..12] — SOF is excluded from CRC
//
//  usKavachID / ucKavachSubsysType must come straight from the
//  fault packet that is being acknowledged (m_pcFaultpkt), so
//  the ACK always reflects who it's actually acking.
// ============================================================
void nmsMainWindow::SendFaultPktAck(QHostAddress senderIP,
                                    quint16 senderPort,
                                    quint16 usMsgSeq,
                                    quint16 usNMSID,
                                    quint32 uiKavachID,
                                    quint8 ucKavachSubsysType,
                                    quint16 usStartFrame)
{
    stNMStoKavach *pstAck = new stNMStoKavach;
    memset(pstAck, 0, sizeof(stNMStoKavach));

    // Use received packet Start Frame
    pstAck->usStartFrame = usStartFrame;

    pstAck->ucMsgType = 0x1F;

    pstAck->usMsgSeq = qToBigEndian(usMsgSeq);

    pstAck->usNMSSystemID = qToBigEndian(usNMSID);

    pstAck->ucKavachSubsysID[0] =
        (uiKavachID >> 16) & 0xFF;

    pstAck->ucKavachSubsysID[1] =
        (uiKavachID >> 8) & 0xFF;

    pstAck->ucKavachSubsysID[2] =
        uiKavachID & 0xFF;

    pstAck->ucKavachType = ucKavachSubsysType;

    quint16 msgLength = sizeof(stNMStoKavach) - 2;

    pstAck->usmsgLength = qToBigEndian(msgLength);

    const quint8 *pData =
        reinterpret_cast<const quint8 *>(pstAck);

    const quint8 *pCrcStart = pData + 2;

    quint32 crcLength = msgLength - 4;

    quint32 crc = CalculateCRC32(crcLength, pCrcStart);

    quint32 crcBE = qToBigEndian(crc);

    memcpy(&pstAck->uiCRC,
           &crcBE,
           sizeof(crcBE));

    qDebug() << "[FaultAck 0x1F]"
             << "StartFrame:"
             << QString("0x%1")
                    .arg(usStartFrame, 4, 16, QChar('0'))
                    .toUpper()
             << "Seq:" << usMsgSeq
             << "NMSID:" << usNMSID
             << "KavachID:" << uiKavachID
             << "SubsysType:"
             << QString("0x%1")
                    .arg(ucKavachSubsysType, 2, 16, QChar('0'))
                    .toUpper();

    qDebug() << "Tx Data:"
             << QByteArray(
                    reinterpret_cast<const char *>(pstAck),
                    sizeof(stNMStoKavach))
                    .toHex(' ')
                    .toUpper();

    emit SigSendAckNMStoKavach(
        senderIP,
        senderPort,
        pstAck);
}

void nmsMainWindow::SendSMS(QString mobileNumber, QString message)
{
    QString accountSID = "AC6f470c854ad28ad273a8648dcf65b038";
    QString authToken = "01a0fe419814c1439b92aeac3edfd045";
    QString from = "+18557747918";

    QNetworkAccessManager *manager = new QNetworkAccessManager();

    QUrl url("https://api.twilio.com/2010-04-01/Accounts/" + accountSID + "/Messages.json");
    QNetworkRequest request(url);

    QString credentials = accountSID + ":" + authToken;
    QByteArray base64Token = credentials.toUtf8().toBase64();
    request.setRawHeader("Authorization", "Basic " + base64Token);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery postData;
    postData.addQueryItem("To", mobileNumber);           // e.g., "+919876543210"
    postData.addQueryItem("From", from);
    postData.addQueryItem("Body", message);

    QNetworkReply *reply = manager->post(request, postData.toString(QUrl::FullyEncoded).toUtf8());

    QObject::connect(reply, &QNetworkReply::finished, [reply,manager]() {
        if (reply->error() == QNetworkReply::NoError)
        {
            qDebug() << "✅ Twilio SMS sent successfully:" << reply->readAll();
        }
        else
        {
            qDebug() << "❌ Twilio SMS failed:" << reply->errorString();
            qDebug() << reply->readAll();
        }
        reply->deleteLater();
    });
}

QString nmsMainWindow::GetLocoMode(uint8_t ucLocoMode)
{
    QString strLocoModeType = NULL;
    switch(ucLocoMode)
    {
    case 0:strLocoModeType = "None";break;
    case 1:strLocoModeType = "Stand By";break;
    case 2:strLocoModeType = "Staff Responsible Mode";break;
    case 3:strLocoModeType = "Limited Supervision";break;
    case 4:strLocoModeType = "Full Supervision";break;
    case 5:strLocoModeType = "Override";break;
    case 6:strLocoModeType = "On Sight";break;
    case 7:strLocoModeType = "Trip";break;
    case 8:strLocoModeType = "Post Trip";break;
    case 9:strLocoModeType = "Reverse";break;
    case 10:strLocoModeType = "Shunt";break;
    case 11:strLocoModeType = "Non Leading";break;
    case 12:strLocoModeType = "System Failure";break;
    case 13:strLocoModeType = "Isolation";break;
    default: strLocoModeType = "UnKnown";break;
    }
    return strLocoModeType;
}

QString nmsMainWindow::GetEmergencyStatus(uint8_t ucEmergSts)
{
    QString strEmrgSts = NULL;
    switch(ucEmergSts)
    {
    case 0:strEmrgSts = "No Emergency";break;
    case 1:strEmrgSts = "Side Collision";break;
    case 2:strEmrgSts = "SoS";break;
    case 3:strEmrgSts = "Roll Back Detected";break;
    case 4:strEmrgSts = "Head On Collision";break;
    case 5:strEmrgSts = "Rear End Collision";break;
    case 6:strEmrgSts = "Parting SoS";break;
    case 7:strEmrgSts = "Spare";break;
    default: strEmrgSts = "UnKnown";break;
    }
    return strEmrgSts;
}

// ============================================================
//  InitKMSConnections  —  ICD §D
//
//  Connects nmsMainWindow's diagnostic slots to EventLoggerKMS.
//  The actual transport wiring (UDP ↔ GSM modem) is done inside
//  nmsUDPServer::InitKMS().  This method only adds the slots
//  that the main window needs for logging and channel changeover.
//
//  Called from InitUDP() once m_pcKMS is valid.
// ============================================================
void nmsMainWindow::InitKMSConnections()
{
    if (!m_pcKMS) return;

    // ICD §D.11 — channel changeover notification
    connect(m_pcKMS, &EventLoggerKMS::SigChannelChangeover,
            this,    &nmsMainWindow::SlotKMSChannelChangeover);

    // Packet logging (RX from VC or KMS, TX to VC or KMS)
    connect(m_pcKMS, &EventLoggerKMS::SigKMSPacketReceived,
            this,    &nmsMainWindow::SlotKMSPacketReceived);

    connect(m_pcKMS, &EventLoggerKMS::SigKMSPacketSent,
            this,    &nmsMainWindow::SlotKMSPacketSent);

    qInfo() << "[MainWindow] KMS diagnostic connections wired";
}

// ============================================================
//  SlotKMSChannelChangeover  —  ICD §D.11
//
//  Called when ELU switches between ELU-A (SIM-1) and ELU-B (SIM-2)
//  after a communication failure reported via 0x97.
// ============================================================
void nmsMainWindow::SlotKMSChannelChangeover(quint8 newSimID)
{
    QString ch = (newSimID == KMS_SIM_PRIMARY) ? "ELU-A (Primary/SIM-1)"
                                               : "ELU-B (Standby/SIM-2)";
    qWarning() << "[KMS] Channel changeover → active:" << ch;

    if (m_pcStationLogFile.isOpen())
    {
        QTextStream ts(&m_pcStationLogFile);
        ts << "[KMS CHANNEL CHANGEOVER] "
           << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")
           << " -> " << ch << "\n";
        ts.flush();
    }
}

// ============================================================
//  SlotKMSPacketReceived  —  log every inbound KMS packet
// ============================================================
void nmsMainWindow::SlotKMSPacketReceived(quint8 msgType, QByteArray packet)
{
    static const QMap<quint8,QString> names = {
        {0x90,"Identification(VC->KMS)"}, {0x91,"ID-Ack(KMS->VC)"},
        {0x92,"AuthKeyReq(VC->KMS)"},     {0x93,"AuthKey(KMS->VC)"},
        {0x94,"AuthQuery(VC->KMS)"},      {0x95,"AuthKeyStatus(KMS->VC)"},
        {0x96,"OTP(ELU->VC)"},            {0x97,"CommFailure(ELU->VC)"}
    };
    qInfo() << "Recived KMS Packet : " << names.value(msgType, QString("0x%1").arg(msgType,2,16,QChar('0')).toUpper())
            << "size:" << packet.size()
            << "hex:" << packet.toHex().toUpper();

    if (m_pcStationLogFile.isOpen())
    {
        QTextStream ts(&m_pcStationLogFile);
        ts << "[KMS RX] " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")
           << " Type:0x" << QString::number(msgType,16).toUpper()
           << " Size:" << packet.size()
           << " Data:" << packet.toHex().toUpper() << "\n";
        ts.flush();
    }
}

// ============================================================
//  SlotKMSPacketSent  —  log every outbound KMS packet
// ============================================================
void nmsMainWindow::SlotKMSPacketSent(quint8 msgType, QByteArray packet)
{
    static const QMap<quint8,QString> names = {
        {0x90,"Identification->KMS"}, {0x91,"ID-Ack->VC"},
        {0x92,"AuthKeyReq->KMS"},     {0x93,"AuthKey->VC"},
        {0x94,"AuthQuery->KMS"},      {0x95,"AuthKeyStatus->VC"},
        {0x96,"OTP->VC"},             {0x97,"CommFailure->VC"}
    };
    qInfo() << "[KMS] TX" << names.value(msgType, QString("0x%1").arg(msgType,2,16,QChar('0')).toUpper())
            << "size:" << packet.size();
}
// ============================================================
//  InsertPacketLog
//
//  Inserts every raw datagram into the nms_packet_log table
//  in the existing PostgreSQL NMSDB.
//
//  Table DDL (run once in PostgreSQL — add to your schema):
//
//    CREATE TABLE IF NOT EXISTS public.nms_packet_log (
//        id          BIGSERIAL    PRIMARY KEY,
//        received_at TIMESTAMP    NOT NULL DEFAULT NOW(),
//        raw_data    BYTEA        NOT NULL
//    );
//    CREATE INDEX IF NOT EXISTS idx_nms_packet_log_time
//        ON public.nms_packet_log(received_at);
//
//  This is the ONLY table needed for offline replay.
//  All other tables (locoregularpacket, faultspacket, …)
//  store parsed fields for display — they are NOT used here.
// ============================================================
void nmsMainWindow::InsertPacketLog(const QByteArray &datagram)
{
    QSqlQuery q(m_pcDB->Get());

    // Use parameterised query so binary data is safe
    q.prepare(
        "INSERT INTO public.nms_packet_log (received_at, raw_data) "
        "VALUES (:ts, :data);");

    q.bindValue(":ts",
                QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

    // Bind raw bytes as BYTEA
    q.bindValue(":data", datagram);

    if (!q.exec())
    {
        qWarning() << "[PacketLog] INSERT failed:" << q.lastError().text();
    }
    else
    {
        qDebug() << "[PacketLog] Logged" << datagram.size()
        << "bytes  msg_type=0x"
        << QString::number(
               static_cast<quint8>(datagram.at(2)), 16)
                .toUpper().rightJustified(2, '0');
    }
}

// ============================================================
//  FetchPacketLog
//
//  Queries nms_packet_log for all raw datagrams received
//  between [from, to].  Called from SlotDoPing() when NMS
//  connectivity is restored.
//
//  Returns datagrams in insertion order (oldest first) so the
//  NMS receives them in the same sequence they were logged.
// ============================================================
QList<QByteArray> nmsMainWindow::FetchPacketLog(const QDateTime &from,
                                                const QDateTime &to)
{
    QList<QByteArray> packets;

    QSqlQuery q(m_pcDB->Get());
    q.prepare(
        "SELECT raw_data "
        "FROM   public.nms_packet_log "
        "WHERE  received_at >= :from "
        "  AND  received_at <= :to "
        "ORDER  BY id ASC;");

    q.bindValue(":from", from.toString("yyyy-MM-dd hh:mm:ss"));
    q.bindValue(":to",   to.toString("yyyy-MM-dd hh:mm:ss"));

    if (!q.exec())
    {
        qWarning() << "[PacketLog] SELECT failed:" << q.lastError().text();
        return packets;
    }

    while (q.next())
        packets.append(q.value(0).toByteArray());

    qInfo() << "[PacketLog] Fetched" << packets.size()
            << "packets for replay"
            << from.toString("yyyy-MM-dd hh:mm:ss")
            << "->"
            << to.toString("yyyy-MM-dd hh:mm:ss");

    return packets;
}

// ============================================================
//  InitNMSPingThread
//
//  Creates a dedicated QThread that owns two QTimers:
//
//    m_pcPingTimer   — fires every 5 s → SlotDoPing()
//    m_pcReplayTimer — fires every 50 ms during replay
//                      → SlotSendNextReplayPacket()
//
//  Both timers and both slots run inside m_pcPingThread so
//  the main thread is never blocked by ping or replay I/O.
//
//  Signal wiring uses Qt::QueuedConnection so cross-thread
//  calls are safe.
// ============================================================
void nmsMainWindow::InitNMSPingThread()
{
    if (m_strNMSIP.isEmpty())
    {
        qCritical() << "[PingThread] NMS_IP not set — ping not started";
        return;
    }

    // ── Create worker thread ───────────────────────────────────
    m_pcPingThread = new QThread(this);

    // ── Ping timer (5 s interval) ─────────────────────────────
    m_pcPingTimer = new QTimer();
    m_pcPingTimer->setInterval(5000);
    m_pcPingTimer->moveToThread(m_pcPingThread);

    // ── Replay timer (50 ms between packets) ─────────────────
    m_pcReplayTimer = new QTimer();
    m_pcReplayTimer->setInterval(10);
    m_pcReplayTimer->moveToThread(m_pcPingThread);

    // Start ping timer when thread starts
    connect(m_pcPingThread, &QThread::started, m_pcPingTimer,
            [this]() { m_pcPingTimer->start(); });

    // Ping timer tick → SlotDoPing (queued: runs in ping thread)
    connect(m_pcPingTimer, &QTimer::timeout,
            this,           &nmsMainWindow::SlotDoPing,
            Qt::QueuedConnection);

    // Replay timer tick → SlotSendNextReplayPacket
    connect(m_pcReplayTimer, &QTimer::timeout,
            this,             &nmsMainWindow::SlotSendNextReplayPacket,
            Qt::QueuedConnection);

    // Clean up timers when thread finishes
    connect(m_pcPingThread, &QThread::finished,
            m_pcPingTimer,  &QObject::deleteLater);
    connect(m_pcPingThread, &QThread::finished,
            m_pcReplayTimer, &QObject::deleteLater);

    m_pcPingThread->start();

    qInfo() << "[PingThread] Started — pinging NMS" << m_strNMSIP
            << "every 1 s";
}

// ============================================================
//  SlotDoPing
//
//  Runs inside m_pcPingThread every 5 seconds.
//
//  State machine:
//
//    ONLINE  ──[ping fails]──►  OFFLINE
//                               record m_dtOfflineStart = now
//
//    OFFLINE ──[ping passes]──► ONLINE
//                               fetch nms_packet_log between
//                               [m_dtOfflineStart, now]
//                               start m_pcReplayTimer to drain
//                               m_lstReplayPackets one by one
//
//  Uses: ping -c 1 -W 1 <ip>
//    -c 1  one ICMP echo request
//    -W 1  1 second wait — tight so the 5 s interval is useful
// ============================================================
void nmsMainWindow::SlotDoPing()
{
    QProcess ping;
    ping.start("ping", QStringList() << "-c" << "1" << "-W" << "1"
                                     << m_strNMSIP);
    ping.waitForFinished(3000);

    bool reachable = (ping.exitCode()   == 0 &&
                      ping.exitStatus() == QProcess::NormalExit);

    if (!reachable)
    {
        // ── NMS is DOWN ──────────────────────────────────────
        if (!m_bNMSOffline)
        {
            // Transition: ONLINE → OFFLINE
            m_bNMSOffline    = true;
            m_dtOfflineStart = QDateTime::currentDateTime();

            qWarning() << "[Ping] NMS OFFLINE since"
                       << m_dtOfflineStart.toString("yyyy-MM-dd hh:mm:ss");
        }
        // else: already offline — keep waiting, nothing to do
    }
    else
    {
        // ── NMS IP is reachable ───────────────────────────────
        if (m_bNMSOffline)
        {
            // Transition: OFFLINE → IP_UP
            m_bNMSOffline    = false;
            QDateTime onlineAt = QDateTime::currentDateTime();

            qInfo() << "[Ping] NMS IP REACHABLE at"
                    << onlineAt.toString("yyyy-MM-dd hh:mm:ss")
                    << " | offline since"
                    << m_dtOfflineStart.toString("yyyy-MM-dd hh:mm:ss");

            // Replay all packets that were logged during the outage.
            m_lstReplayPackets = FetchPacketLog(m_dtOfflineStart, onlineAt);

            if (!m_lstReplayPackets.isEmpty())
            {
                qInfo() << "[Ping] Starting replay of"
                        << m_lstReplayPackets.size() << "packet(s)";
                m_pcReplayTimer->start();
            }
            else
            {
                qInfo() << "[Ping] No packets to replay";
            }

            m_dtOfflineStart = QDateTime();
        }

        // ── Also probe the NMS application port ──────────────
        // Ping only proves the host is alive — the NMS UDP port
        // may still be closed (app not started / crashed).
        // ProbeNMSApp() sends a 1-byte UDP probe and checks for
        // ICMP port-unreachable to determine app status.
        bool bAppUp = ProbeNMSApp();

        if (bAppUp && m_bNMSAppDown)
        {
            // Transition: APP_DOWN → APP_UP
            m_bNMSAppDown = false;
            qInfo() << "[Ping] NMS application is UP — resuming full forwarding";
        }
        else if (!bAppUp && !m_bNMSAppDown)
        {
            // Transition: APP_UP → APP_DOWN
            m_bNMSAppDown = true;
            qWarning() << "[Ping] NMS application is DOWN (IP reachable)"
                       << "— will send only 0x11 0x12 0x13 0x14 0x19";
        }
        // else: state unchanged — no log spam
    }
}

// ============================================================
//  SlotSendNextReplayPacket
//
//  Fires every 50 ms while m_lstReplayPackets is non-empty.
//  Takes the first packet from the list and sends it directly
//  to the NMS socket — same path as a live packet.
//
//  When the list is drained, stops the replay timer.
//
//  50 ms between packets ≈ 20 packets/s — enough to drain a
//  typical outage buffer quickly without flooding the NMS.
//  Adjust m_pcReplayTimer->setInterval() if needed.
// ============================================================
void nmsMainWindow::SlotSendNextReplayPacket()
{
    if (m_lstReplayPackets.isEmpty())
    {
        m_pcReplayTimer->stop();
        qInfo() << "[Replay] All packets sent to NMS";
        return;
    }

    if (!m_pcNMSSocket)
    {
        qWarning() << "[Replay] NMS socket not ready — stopping replay";
        m_pcReplayTimer->stop();
        m_lstReplayPackets.clear();
        return;
    }

    // Take the oldest buffered packet
    QByteArray datagram = m_lstReplayPackets.takeFirst();

    qint64 sent = m_pcNMSSocket->writeDatagram(
        datagram,
        QHostAddress(m_strNMSIP),
        m_usNMSPort);

    if (sent == -1)
        qWarning() << "[Replay] Send FAILED:" << m_pcNMSSocket->errorString();
    else
        qDebug() << "[Replay] Sent" << sent << "bytes to NMS |"
                 << m_lstReplayPackets.size() << "remaining";
}

// ============================================================
//  SlotGPSPosition
//  Connected to EventLogger::gpsPositionReady(double,double,bool).
//  Caches the latest lat/lon and GNSS validity flag so
//  Build0x28Packet() always has fresh data without issuing a
//  serial read at heartbeat time.
// ============================================================
void nmsMainWindow::SlotGPSPosition(double dLat, double dLon, bool bValid)
{
    m_dLastLat   = dLat;
    m_dLastLon   = dLon;
    m_bGNSSValid = bValid;
}

void nmsMainWindow::SendHeartbeat()
{

        if (!m_pcRelaySocket)
            return;

        QByteArray hb = QByteArrayLiteral("HELLO_EVENTLOGGER");

        qint64 sent = m_pcRelaySocket->writeDatagram(
            hb,
            QHostAddress(m_strRelayIP),
            m_usRelayPort);

        if (sent == -1)
            qWarning() << "[GSM Relay] Heartbeat FAILED:"
                       << m_pcRelaySocket->errorString();
        else
            qDebug() << "[GSM Relay] Heartbeat sent ->"
                     << m_strRelayIP << ":" << m_usRelayPort;

}

// ============================================================
//  InitVCHeartbeat
//
//  Reads from Config.cfg:
//    [VC]
//    Interval_ms = 500        ; 0xA2 period, must be ≤ 1000
//    ELU_ID      = 2          ; 2 = ELU-A, 3 = ELU-B
//    Channel_ID  = 1          ; 0x01 = ELU-A, 0x02 = ELU-B
//
//  VC_IP is shared from [KMS] section (already read by InitKMS).
//
//  Creates m_pcVCSock (unbound — we only send, never receive on
//  port 4446 from ELU side) and starts m_pcVCTimer.
// ============================================================
void nmsMainWindow::InitVCHeartbeat()
{
    // ── Read config ───────────────────────────────────────────
    m_ocCfgSettings->beginGroup("KMS");
    m_strVCIP = m_ocCfgSettings->value("VC_IP").toString();
    m_ocCfgSettings->endGroup();

    m_ocCfgSettings->beginGroup("VC");
    int intervalMs = 1000; //m_ocCfgSettings->value("Interval_ms", 500).toInt();
    intervalMs = qBound(100, intervalMs, 1000);  // clamp to ICD max 1000 ms

    int eluID = m_ocCfgSettings->value("ELU_ID", 2).toInt();
    // ICD: ELU-A=0x0002, ELU-B=0x0003
    m_usELUSenderID = (eluID == 3) ? 0x0003 : 0x0002;

    int chanID = m_ocCfgSettings->value("Channel_ID", 1).toInt();
    // ICD: 0x01=ELU-A, 0x02=ELU-B
    m_ucELUChannelID = (chanID == 2) ? 0x02 : 0x01;
    m_ocCfgSettings->endGroup();

    if (m_strVCIP.isEmpty())
    {
        qCritical() << "[VCHeartbeat] VC_IP not set in Config.cfg [KMS] — 0x28/0xA2 not started";
        return;
    }

    // ── Socket ────────────────────────────────────────────────
    // Unbound UDP socket — ELU only sends on port 4446, never listens.
    m_pcVCSock = new QUdpSocket(this);

    // ── Timer ─────────────────────────────────────────────────
    m_pcVCTimer = new QTimer(this);
    m_pcVCTimer->setInterval(intervalMs);

    connect(m_pcVCTimer, &QTimer::timeout,
            this,        &nmsMainWindow::SlotVCHeartbeat);

    m_pcVCTimer->start();

    qInfo() << "[VCHeartbeat] Started — sending 0x28+0xA2 to"
            << m_strVCIP << "port 4446 every" << intervalMs << "ms"
            << "| ELU_ID=0x" << QString::number(m_usELUSenderID,16).toUpper()
            << "Channel=0x" << QString::number(m_ucELUChannelID,16).toUpper();
}

// ============================================================
//  SlotVCHeartbeat
//
//  Called every Interval_ms.
//  Builds and sends 0x28 (GNSS Position) and 0xA2 (Diagnostics)
//  to the VC on UDP port 4446.
//  Both packets use the same socket (m_pcVCSock).
// ============================================================
void nmsMainWindow::SlotVCHeartbeat()
{
    if (!m_pcVCSock)
        return;

    QHostAddress vcAddr(m_strVCIP);

    // ── 0x28 — GNSS Position Message ─────────────────────────
   QByteArray pkt28 = Build0x28Packet();
   m_pcVCSock->writeDatagram(pkt28, vcAddr, m_usVCPort);

   qDebug() << "GNSS Position Sent 0x28 to "
             << "IP:" << vcAddr.toString()
             << "Port:" << m_usVCPort
             << "Size:" << pkt28.size()
             << "Data:" << pkt28.toHex(' ').toUpper();



    // ── 0xA2 — ELU Diagnostics / Heartbeat ───────────────────
    QByteArray pktA2 = Build0xA2Packet();
    m_pcVCSock->writeDatagram(pktA2, vcAddr, m_usVCPort);

    qDebug() << "ELU Diagnostics/HeartBeat 0xA2 to"
             << "IP:" << vcAddr.toString()
             << "Port:" << m_usVCPort
             << "Size:" << pktA2.size()
             << "Data:" << pktA2.toHex(' ').toUpper();
}

// ============================================================
//  EncodeLatLon  — ICD §2.3
//
//  Packs a decimal-degree value into 32 bits:
//    bit 31      : sign (0=positive, 1=negative)
//    bits [30..] : degrees  (degBits wide)
//    next bits   : minutes  (minBits wide)   integer part only
//    next bits   : seconds  (secBits wide)   integer part only
//    remaining   : zero-padded at LSB
//
//  Latitude  (32-bit): sign(1) + deg(8) + min(6) + sec(6) = 21 bits used
//  Longitude (32-bit): sign(1) + deg(9) + min(6) + sec(6) = 22 bits used
// ============================================================
quint32 nmsMainWindow::EncodeLatLon(double decDeg,
                                    int degBits,
                                    int minBits,
                                    int secBits)
{
    bool negative = (decDeg < 0.0);
    double abs_deg = qAbs(decDeg);

    int deg = static_cast<int>(abs_deg);
    double rem_min = (abs_deg - deg) * 60.0;
    int mn  = static_cast<int>(rem_min);
    int sec = static_cast<int>((rem_min - mn) * 60.0);

    // Total bits used = 1(sign) + degBits + minBits + secBits
    // All packed MSB-first; remaining LSBs are 0.
    int shift = degBits + minBits + secBits;   // bits below sign bit

    quint32 result = 0;
    if (negative)
        result |= (1u << (shift));              // sign bit above the data

    result |= (static_cast<quint32>(deg) << (minBits + secBits));
    result |= (static_cast<quint32>(mn)  << secBits);
    result |= (static_cast<quint32>(sec));

    // Shift the whole payload to sit at the MSB of a 32-bit word
    // Total used bits = 1 + degBits + minBits + secBits
    int usedBits = 1 + degBits + minBits + secBits;
    result <<= (32 - usedBits);                 // align to MSB, zero-pad LSB

    return result;
}

// ============================================================
//  CalcCRC32
//
//  CRC-32 over the supplied data buffer.
//  Uses the standard IEEE 802.3 polynomial (0xEDB88320, reflected).
//  Per ICD: SOF (bytes 0-1) are EXCLUDED from the CRC input.
// ============================================================
quint32 nmsMainWindow::CalcCRC32(const QByteArray &data)
{
    quint32 crc = 0xFFFFFFFF;
    for (unsigned char byte : data)
    {
        crc ^= byte;
        for (int i = 0; i < 8; ++i)
            crc = (crc >> 1) ^ (0xEDB88320u & -(crc & 1u));
    }
    return crc ^ 0xFFFFFFFF;
}


void nmsMainWindow::OnGPSUTCReady(QDateTime utcTime)
{
    m_utcDateTime = utcTime;
}

void nmsMainWindow::OnGPSSpeedReady(qint32 speedMMps)
{
    m_iLastGroundSpeed = speedMMps;
}

void nmsMainWindow::OnGPSFixStatusReady(quint8 fixStatus)
{
    m_ucLastFixStatus = fixStatus;
}

// ============================================================
//  Build0x28Packet  — ICD §2.2
//
//  Byte layout (24 bytes total):
//    [0-1]  SOF         0xA5 0xC3
//    [2]    Protocol    0x01
//    [3]    Cmd Type    0x28
//    [4-5]  Msg Length  (bytes from SeqNum to CRC32 inclusive = 18)
//    [6-7]  Seq Num     m_usSeq0x28++ (big-endian)
//    [8-9]  Sender ID   m_usELUSenderID (big-endian)
//    [10-11]Receiver ID m_usVCReceiverID (big-endian)
//    [12]   Channel ID  m_ucELUChannelID
//    [13-16]Latitude    EncodeLatLon(m_dLastLat, 8, 6, 6) big-endian
//    [17-20]Longitude   EncodeLatLon(m_dLastLon, 9, 6, 6) big-endian
//    [21-24]CRC32       CalcCRC32(bytes[2..20]) big-endian
//
//  CRC covers everything after SOF (byte index 2 onwards).
// ============================================================
QByteArray nmsMainWindow::Build0x28Packet()
{
    QByteArray pkt;
    pkt.reserve(44);
    pkt.append(static_cast<char>(0xA5));
    pkt.append(static_cast<char>(0xC3));
    pkt.append(static_cast<char>(0x01));
    pkt.append(static_cast<char>(0x28));

    quint16 msgLen = 38;
    pkt.append(static_cast<char>((msgLen >> 8) & 0xFF));
    pkt.append(static_cast<char>( msgLen       & 0xFF));

    quint16 seq = m_usSeq0x28++;
    pkt.append(static_cast<char>((seq >> 8) & 0xFF));
    pkt.append(static_cast<char>( seq       & 0xFF));
    pkt.append(static_cast<char>((m_usELUSenderID  >> 8) & 0xFF));
    pkt.append(static_cast<char>( m_usELUSenderID        & 0xFF));
    pkt.append(static_cast<char>((m_usVCReceiverID >> 8) & 0xFF));
    pkt.append(static_cast<char>( m_usVCReceiverID       & 0xFF));
    pkt.append(static_cast<char>(m_ucELUChannelID));

    // UTC time — cached from last gpsUTCReady signal
    QDate d = m_utcDateTime.date();
    QTime t = m_utcDateTime.time();
    quint16 utcYear  = static_cast<quint16>(d.year());
    quint8  utcMonth = static_cast<quint8>(d.month());
    quint8  utcDay   = static_cast<quint8>(d.day());
    quint8  utcHour  = static_cast<quint8>(t.hour());
    quint8  utcMin   = static_cast<quint8>(t.minute());
    quint8  utcSec   = static_cast<quint8>(t.second());
    // NOTE: GPRMC time field has whole-second resolution only — ms always 0
    quint16 utcMs    = 0;
    pkt.append(static_cast<char>((utcYear >> 8) & 0xFF));
    pkt.append(static_cast<char>( utcYear       & 0xFF));
    pkt.append(static_cast<char>(utcMonth));
    pkt.append(static_cast<char>(utcDay));
    pkt.append(static_cast<char>(utcHour));
    pkt.append(static_cast<char>(utcMin));
    pkt.append(static_cast<char>(utcSec));
    pkt.append(static_cast<char>((utcMs >> 8) & 0xFF));
    pkt.append(static_cast<char>( utcMs       & 0xFF));

    // GPS Frame Number / TOW — NOT available without UBX binary protocol.
    // Sending 0 as a placeholder; flag this to your ICD reviewer as a
    // known gap on NMEA-only hardware.
    quint32 gpsFrameNum = 0;
    pkt.append(static_cast<char>((gpsFrameNum >> 24) & 0xFF));
    pkt.append(static_cast<char>((gpsFrameNum >> 16) & 0xFF));
    pkt.append(static_cast<char>((gpsFrameNum >>  8) & 0xFF));
    pkt.append(static_cast<char>( gpsFrameNum        & 0xFF));

    quint32 latEnc = EncodeLatLon(m_dLastLat, 8, 6, 6);
    pkt.append(static_cast<char>((latEnc >> 24) & 0xFF));
    pkt.append(static_cast<char>((latEnc >> 16) & 0xFF));
    pkt.append(static_cast<char>((latEnc >>  8) & 0xFF));
    pkt.append(static_cast<char>( latEnc        & 0xFF));

    quint32 lonEnc = EncodeLatLon(m_dLastLon, 9, 6, 6);
    pkt.append(static_cast<char>((lonEnc >> 24) & 0xFF));
    pkt.append(static_cast<char>((lonEnc >> 16) & 0xFF));
    pkt.append(static_cast<char>((lonEnc >>  8) & 0xFF));
    pkt.append(static_cast<char>( lonEnc        & 0xFF));

    // Ground Speed — approximated from GPRMC knots, cached via gpsSpeedReady
    qint32 groundSpeed = m_iLastGroundSpeed;
    pkt.append(static_cast<char>((groundSpeed >> 24) & 0xFF));
    pkt.append(static_cast<char>((groundSpeed >> 16) & 0xFF));
    pkt.append(static_cast<char>((groundSpeed >>  8) & 0xFF));
    pkt.append(static_cast<char>( groundSpeed        & 0xFF));

    // GPS Fix Status — approximated from GPGGA fix quality
    pkt.append(static_cast<char>(m_ucLastFixStatus));

    // GPS Valid Flag
    pkt.append(static_cast<char>(m_bGNSSValid ? 1 : 0));

    quint32 crc = CalcCRC32(pkt.mid(2));
    pkt.append(static_cast<char>((crc >> 24) & 0xFF));
    pkt.append(static_cast<char>((crc >> 16) & 0xFF));
    pkt.append(static_cast<char>((crc >>  8) & 0xFF));
    pkt.append(static_cast<char>( crc        & 0xFF));

    return pkt;  // 44 bytes
}

// ============================================================
//  Build0xA2Packet  — ICD §3.2
//
//  Byte layout (18 bytes total):
//    [0-1]  SOF           0xA5 0xC3
//    [2]    Protocol      0x01
//    [3]    Cmd Type      0xA2
//    [4-5]  Msg Length    bytes from SeqNum to CRC32 inclusive = 12
//    [6-7]  Seq Num       m_usSeq0xA2++
//    [8-9]  Sender ID     m_usELUSenderID
//    [10-11]Receiver ID   m_usVCReceiverID
//    [12]   ELU Channel   m_ucELUChannelID
//    [13]   NMS Comm Sts  0=Fail 1=OK  (m_bNMSOffline || m_bNMSAppDown)
//    [14]   GNSS Status   0=Fail 1=OK  (m_bGNSSValid)
//    [15]   PPS Status    0=Not detected 1=Valid  (m_bPPSValid)
//    [16]   GSM Status    0=Not ready 1=Registered 2=Data active
//    [17]   GSM RSSI      CSQ value from modem (0-31, 99=unknown)
//    [18]   Storage       0=Not OK 1=OK  (disk writable check)
//    [19-22]CRC32         CalcCRC32(bytes[2..18])
// ============================================================
QByteArray nmsMainWindow::Build0xA2Packet()
{
    QByteArray pkt;
    pkt.reserve(30);
    // SOF
    pkt.append(static_cast<char>(0xA5));
    pkt.append(static_cast<char>(0xC3));
    // Protocol + Command Type
    pkt.append(static_cast<char>(0x01));
    pkt.append(static_cast<char>(0xA2));
    // Message Length = SeqNum(2)+SenderID(2)+RecvID(2)+ChanID(1)+
    //                  NMS(1)+GNSS(1)+PPS(1)+GSMSts(1)+RSSI(1)+Storage(1)+
    //                  PowerSupply(1)+KMS(1)+EVLAppCRC(4)+CRC32(4) = 23
    quint16 msgLen = 23;
    pkt.append(static_cast<char>((msgLen >> 8) & 0xFF));
    pkt.append(static_cast<char>( msgLen       & 0xFF));
    quint16 seq = m_usSeq0xA2++;
    pkt.append(static_cast<char>((seq >> 8) & 0xFF));
    pkt.append(static_cast<char>( seq       & 0xFF));
    pkt.append(static_cast<char>((m_usELUSenderID  >> 8) & 0xFF));
    pkt.append(static_cast<char>( m_usELUSenderID        & 0xFF));
    pkt.append(static_cast<char>((m_usVCReceiverID >> 8) & 0xFF));
    pkt.append(static_cast<char>( m_usVCReceiverID       & 0xFF));
    pkt.append(static_cast<char>(m_ucELUChannelID));

    // NMS Communication Status: 1=OK, 0=Fail
    quint8 nmsOK = (!m_bNMSOffline && !m_bNMSAppDown) ? 1 : 0;
    pkt.append(static_cast<char>(nmsOK));
    qDebug() << "NMS Status:" << (nmsOK ? "Reachable" : "NOT Reachable");

    // GNSS Link Status: 1=OK, 0=Fail
    pkt.append(static_cast<char>(m_bGNSSValid ? 1 : 0));

    // PPS Status: 1=Valid, 0=Not detected
    pkt.append(static_cast<char>(m_bPPSValid ? 1 : 0));

    // GSM Status: from KMS cached value (0=Not ready,1=Registered,2=Data active)
    quint8 gsmSts = 0;
    int    gsmCSQ = -1;
    if (m_pcKMS)
    {
        gsmSts = m_pcKMS->GetGSMStatus();
        gsmCSQ = m_pcKMS->GetLastCSQ();
    }
    pkt.append(static_cast<char>(gsmSts));

    // GSM RSSI — raw CSQ value (0-31, 99=unknown). Cast to byte; 255 if -1.
    quint8 rssi = (gsmCSQ >= 0) ? static_cast<quint8>(gsmCSQ) : 0xFF;
    pkt.append(static_cast<char>(rssi));

    // Storage Health: try writing 1 byte to the log directory
    bool storageOK = false;
    {
        QFile probe("/NMS/Logs/.probe");
        if (probe.open(QIODevice::WriteOnly))
        {
            probe.write("1", 1);
            probe.close();
            probe.remove();
            storageOK = true;
        }
    }
    pkt.append(static_cast<char>(storageOK ? 1 : 0));

    // ELU Power Supply Status: 0=Power Fault, 1=Power Healthy
    pkt.append(static_cast<char>(m_bPowerHealthy ? 1 : 0));

    quint8 kmsOK = (m_pcKMS) ? 1 : 0;
    pkt.append(static_cast<char>(kmsOK));



    // EVL Application CRC: CRC32 of the currently running Event Logger
    // application software. Constant per release, changes only when the
    // application software itself changes.
    quint32 evlAppCrc = m_uiEVLAppCRC;
    pkt.append(static_cast<char>((evlAppCrc >> 24) & 0xFF));
    pkt.append(static_cast<char>((evlAppCrc >> 16) & 0xFF));
    pkt.append(static_cast<char>((evlAppCrc >>  8) & 0xFF));
    pkt.append(static_cast<char>( evlAppCrc        & 0xFF));

    // CRC32 over bytes[2..end] (SOF excluded)
    quint32 crc = CalcCRC32(pkt.mid(2));
    pkt.append(static_cast<char>((crc >> 24) & 0xFF));
    pkt.append(static_cast<char>((crc >> 16) & 0xFF));
    pkt.append(static_cast<char>((crc >>  8) & 0xFF));
    pkt.append(static_cast<char>( crc        & 0xFF));

    return pkt;  // 30 bytes
}