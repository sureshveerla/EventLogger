#ifndef NMSMAINWINDOW_H
#define NMSMAINWINDOW_H

#include "nmsUDPServer.h"
#include "nmsDB.h"
#include "nmsDBQuerys.h"
#include "kavachpkthandler.h"
#include <arpa/inet.h>
#include "KAVACH_PARSEPACKET.h"
#include "EventLoggerGPS.h"
#include "EventLoggerKMS.h"      // ICD §D — KMS gateway
#include <QThread>
#include <QTimer>
#include <QProcess>
#include <QUdpSocket>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlError>

QT_BEGIN_NAMESPACE
namespace Ui {
class nmsMainWindow;
}
QT_END_NAMESPACE

class nmsMainWindow : public QObject
{
    Q_OBJECT

public:
    explicit nmsMainWindow(QString strCFGFilePath,QObject *pcParent = nullptr);
    virtual ~nmsMainWindow();

    void ProcessFieldInputmessage(QHostAddress senderIP, QByteArray datagram);
    void ProcessFieldEventMessage(QByteArray datagram);
    void ProcessAccessAuthorityPacket(QByteArray datagram);
    void ProcessStationFaultPkt(QByteArray datagram);
    void ProcessStationHealthPkt(QByteArray datagram);
    void ProcessTSRMSMessagePkt(QByteArray datagram);
    void ProcessOnBoardHealthPkt(QByteArray datagram);
    void ProcessLocoRSSIMessagePkt(QByteArray datagram);
    void ProcessStationRSSIMessagePkt(QByteArray datagram);
    void ProcessStationKavachSysSts(QByteArray datagram);
    void ProcessOnBoardEventMsg(QByteArray datagram);
    void ProcessOnBoardBrakeEventMsg(QByteArray datagram);
    void ProcessOnBoardHealthStsMsg(QByteArray datagram);
    void ProcessS2SPackets(QByteArray datagram);

    void InitGSMRelay();


private slots:

    void SlotNewFaultPacket(QHostAddress senderIP, quint16 senderPort,QByteArray datagram);
    void SlotPreviousFaultInfo();
    void SlottabChanged(int index);
    void SlotUpadateSchematic(QHostAddress senderIP, quint16 senderPort,QByteArray datagram);
    void SlotStationNameAndID(QStringList strLstStationID, QStringList strLstStationNames, QString strDateTime, bool bStationSts);
    void SlotStationRegHeader(StationRegularHeader stStnRglrHPkt);
    void SlotStationconnStatus(QString strHostAddr, bool bStatus);

    // ── KMS Slots (ICD §D) ────────────────────────────────────
    void SlotKMSChannelChangeover(quint8 newSimID);
    void SlotKMSPacketReceived(quint8 msgType, QByteArray packet);
    void SlotKMSPacketSent(quint8 msgType, QByteArray packet);

    // ── NMS Ping / Replay ─────────────────────────────────────
    // Fired every 5 s by m_pcPingTimer (runs in m_pcPingThread).
    void SlotDoPing();

    // Fired by m_pcReplayTimer to send one buffered packet at a time.
    void SlotSendNextReplayPacket();

    // Fired by m_pcVCTimer — builds and sends 0x28 + 0xA2 to VC on port 4446.
    void SlotVCHeartbeat();

    // Called when GPS parses a new position fix.
    void SlotGPSPosition(double dLat, double dLon, bool bValid);

    void SendHeartbeat();

signals:

    void SigSendAckNMStoKavach(QHostAddress senderIP, quint16 senderPort,stNMStoKavach *pstAck);
    void SigFaultPktInserttoDB(stKavachtoNMS *pstKavachtoNMS,QString strFaultsCode,QString strFaultMsg);
    void SigStnFaultPktInserttoDB(stStationFaults *pstStnFaults,QStringList strLstModuleID,
                                  QStringList strLstFaultCodeTyp,QStringList strFaultsCode,QStringList strFaultMsg);
    void SigStationInfo();
    void SigLocoInfo();
    void SigFaultMsginserttoDB(QString strMsgType,QString strTimestamp,
                               QList<uint16_t> faultByteArray,QString strFirmNam,uint32_t uiID);
    void SigStnFaultMsginserttoDB(QString strMsgType,QString strTimestamp,
                                  uint16_t usFaultCode,QString strFirmNam,uint32_t uiID);
    void SigSMSFaultMsginserttoDB(QString strMsgType,QString strTimestamp,
                                  QList<uint16_t> faultByteArray,QString strFirmNamID);
    void SigSMSStnFaultMsginserttoDB(QString strMsgType,QString strTimestamp,
                                     uint16_t usFaultCOde,QString strFirmNamID);
    void SigSendSMS(uint32_t uiID, QString message);
    void SigSendFaultmessage(QString strMsgType,QString strTimeStamp,QString strFirmid,QString strFaultMsg);
    void SigAccessReqInsertintoDB(stAccessRequestPkt stheader,uint32_t uiPktType,uint32_t uiPktLen,uint32_t uiFrmNo,
                                  uint32_t uiSrcLocoID,uint32_t uiSrcLocoVer,uint32_t uiAbsLoco_Loc,uint32_t uiTrainLen,uint32_t uiTrainSpd,
                                  uint32_t uiMovMntDir,uint32_t uiEmergencySts,uint32_t uiLocoMode,uint32_t uiApprStID,uint32_t uiLastRfidTag,
                                  uint32_t uitinNo,uint32_t uiLongitude,uint32_t uiLatitude,uint32_t uiLocoRandmrl,
                                  uint32_t uiMACCode,uint32_t uiPktCRC,uint8_t ucMASecCnt,uint16_t usRouteID,uint32_t uiCRC);
    void SigLocoRegularInsertintoDB(stAccessRequestPkt stheader,uint32_t uiPktType,uint32_t uiPktLen,uint32_t uiFrmNo,
                                    uint32_t uiSrcLocoID,uint32_t uiSrcLocoVer,uint32_t uiAbsLoco_Loc,
                                    uint32_t uidoubtover,uint32_t uidoubtunder,uint32_t uitrainint,
                                    uint32_t uiTrainLen,uint32_t uiTrainSpd,uint32_t uiMovMntDir,
                                    uint32_t uiEmergencySts,uint32_t uiLocoMode,uint32_t uiLastRfidTag,
                                    uint32_t uiTagDup,uint32_t uitagLinkInfo,uint32_t uitinNo,
                                    uint32_t uiBrkApply,uint32_t uinewMAReply,uint32_t uiLastRefProfNo,
                                    uint32_t uiSigOV,uint32_t uiInfoAck,uint32_t uiSpare,QString strLocoHlthSts,
                                    uint32_t uiMACCode,uint32_t uiPktCRC,
                                    uint8_t ucMASecCnt,uint16_t usRouteID,uint32_t uiCRC);
    void SigAccessAuthorityPktInsertintoDB(stAccessRequestPkt stheader,uint32_t uiPktType,uint32_t uiPktLen,
                                           uint32_t uiFrmNo,uint32_t uiSrcStnILCIBS_ID,
                                           uint32_t uiSRCStnILCIBS_ver,uint32_t uiStnILCIBS_Loc,
                                           uint32_t uiDestLoco_ID,uint32_t uiAlotUpLnk_Freq,
                                           uint32_t uiAlotDnLnk_Freq,uint32_t uiAlotTDMA_Timeslots,
                                           uint32_t uiStnRndNum_RS,uint32_t uiStnTDMA,
                                           uint32_t uiMAC_Code,uint32_t uiPktCrc,uint32_t uiCRC);
    void SigAdditionalEmergencyPktInsertintoDB(stAccessRequestPkt stheader,uint32_t uiPktType,uint32_t uiPktLen,
                                               uint32_t uiFrmNo,uint32_t uiSrcStnILCIBS_ID,
                                               uint32_t uiSRCStnILCIBS_ver,uint32_t uiStnILCIBS_Loc,
                                               uint32_t uiGenSoSCall,uint32_t uiCRC);
    void SigInsertDBStationRegHeader(stAccessRequestPkt stHeader,StationRegularHeader stStnRglrHPkt);
    void SigInsertDBStationhealthPkt(stStationHealthPkt stStnHlthPkt,QStringList strEvntID,
                                     QStringList strEvntData,uint32_t uiCrc);
    void SigInsertDBOnBoardhealthPkt(stOnBoardHealthPkt stOnBrdHlthPkt,QString strEvntID,
                                     QString strEvntData,uint32_t uiCrc);
    void SigInsertDBS2SPDIVerCmd(stPacketHeader stPktHdr,stPDIVerCheckCmdPkt stPDIVerCmd);
    void SigInsertDBS2SPDIVerMsg(stPacketHeader stPktHdr,stPDIVerCheckMsgPkt stPDIVerMsg);
    void SigInsertDBS2SHeartBeat(stPacketHeader stPktHdr,stHeartBeatPkt stHeartBeat);
    void SigInsertDBS2STrainHandOverReq(stPacketHeader stPktHdr,stTrainHandOverReqPkt stTrnHndOveReq);
    void SigInsertDBS2STrainTakenOverMsg(stPacketHeader stPktHdr,stTrainTakenOverPkt stTrnTknOveMsg);
    void SigInsertDBS2STrainHandOverCancellationReq(stPacketHeader stPktHdr,stTrainHandOverCancellationPkt stTrnHndOvrCnclPkt);
    void SigInsertDBS2STrainLengthInformationReq(stPacketHeader stPktHdr,stTrainLengthInfoPkt stTrnLenInfoPkt);
    void SigInsertDBS2SLengthInformationAck(stPacketHeader stPktHdr,stTrainLengthInfoAck stTrnLenInfoAck);
    void SigInsertDBS2STSLRouteRequest(stPacketHeader stPktHdr,stTSLReqPkt stTSLRouteReq);
    void SigInsertDBS2STSLAuthorityInformationPkt(stPacketHeader stPktHdr,stTSLInformationPkt stTSLInfoPkt);
    void SigInsertDBS2SFieldElementsStatusReq(stPacketHeader stPktHdr,stFieldElementsStatusReqPkt stFldElementStsReq);
    void SigInsertDBS2STrainHandoverCancellationAck(stPacketHeader stPktHdr,stTrainHandOverCancellationAckPkt stTrnHndOvrCnclAck);
    void SigInsertDBLocoRSSIMessage(stLocoRSSIMsg stLocoRSSI);
    void SigInsertDBStationRSSIMessage(stStationRSSIMsg stStnRSSI);
    void SigInsertDBStationKavachSysSts(stStationaryKavachSysInfo stStnKavchSysSts);
    void SigInsertDBOnBoardEventMessage(stOnboardKavachEventMsg stOnBoardEventMsg);
    void SigInsertDBOnBoardBrakeEventMsg(stOnboardKavachBrakeEventMsg stOnBoardBrakeEvntMsg);
    void SigInsertDBOnBoardSystemHealthMsg(stOnboardKavachBOKSHealthMsg stOnBoardSysHealth);
    void SigInsertDBFieldInputStatus(stPacketHeader stPktHdr,uint16_t usRelayCnt,QByteArray byArrRelayImage,uint32_t uiCRC);
    void SigInsertDBFieldInputEventData(stFieldEventData stFldEvntData);
    void SigShowAllStations();
    void SigStationisConnected(QString strStationName,bool bstatus);


private:

    stKavachtoNMS *m_pstKavachtoNMS;
    NMSDB *m_pcDB;
    KavachPktHandler *m_pcKavachHandler;
    QByteArray  m_pcReceivedData;
    QPoint m_dragStartPos;
    nmsDBQuerys *m_pcDBQuery;
    stAccessRequestPkt m_stHeader;
    stPacketHeader m_stPktHdr;
    stStationFaults *m_pcFaultpkt;
    QFile m_pcLocoLogFile,m_pcStationLogFile;
    uint32_t ExtractBits(const QVector<bool> &bits, int &index, int bitCount);
    int m_currentViewIndex = 0;
    QWidget *m_pStationTablePage;
    QWidget *m_pLayoutPage;
    QStringList m_strLstStationID,m_strLstStationNames;
    bool m_bStationSts,m_bStnHlthSts;
    QString m_strDtTime,m_strLastPkt,m_strStnName;
    KAVACH_PARSEPACKET *m_pcKavachParseData;
    uint32_t m_uicrc;
    QString m_strFaultMsg;
    uint16_t m_usSeqNum = 0;
    QString m_strCfgFilePath;
    EventLoggerKMS *m_pcKMS;
    QString m_strSMSpwd,m_strRmtPwd;
    QSettings *m_ocCfgSettings;
    QString m_strLanIP, m_strInternetIP;
    QMap<QString, QString> m_ipToStationMap;
    QMap<QString, QString> m_ipToStationPortMap;

    // ── NMS UDP socket ────────────────────────────────────────
    QUdpSocket *m_pcNMSSocket;
    QString     m_strNMSIP;
    quint16     m_usNMSPort;

    QString    m_strStnSenderIP;
    quint16    m_usStnSenderPort;

    QUdpSocket  *m_pcRelaySocket;
    QTimer      *m_pcHeartbeatTimer;
    QString      m_strRelayIP;
    quint16      m_usRelayPort;

    // ── NMS Ping (runs in m_pcPingThread) ────────────────────
    // A QTimer in a separate thread fires SlotDoPing() every 5 s.
    // All ping logic lives in this class — no extra class needed.
    QThread    *m_pcPingThread;   // thread the ping timer lives in
    QTimer     *m_pcPingTimer;    // 5-second interval ping timer

    bool        m_bNMSOffline;        // true while NMS IP unreachable (ping fails)
    QDateTime   m_dtOfflineStart;     // first failure timestamp

    // True when ping succeeds but NMS application port is not responding.
    // ForwardToNMS() sends only priority types: 0x11 0x12 0x13 0x14 0x19
    bool        m_bNMSAppDown;

    // ── Replay state (also runs in m_pcPingThread) ────────────
    // After NMS comes back, m_pcReplayTimer ticks through
    // m_lstReplayPackets one packet per tick (50 ms) so the NMS
    // socket (on the main thread) is not flooded.
    QTimer              *m_pcReplayTimer;
    QList<QByteArray>    m_lstReplayPackets;  // loaded from DB on recovery

    // ── Private helpers ───────────────────────────────────────
    // ── VC periodic send (0x28 + 0xA2) on UDP port 4446 ─────
    QTimer     *m_pcVCTimer;        // interval from Config.cfg [VC]/Interval_ms
    QUdpSocket *m_pcVCSock;         // dedicated socket for port 4446

    QString    m_strVCIP;           // VC_IP from [KMS] section in Config.cfg
    quint16    m_usVCPort = 4446;   // fixed per ICD §2

    quint16    m_usSeq0x28 = 0;     // incrementing sequence for 0x28
    quint16    m_usSeq0xA2 = 0;     // incrementing sequence for 0xA2

    // ELU Sender ID: 0x0002=ELU-A, 0x0003=ELU-B (from Config.cfg [VC]/ELU_ID)
    quint16    m_usELUSenderID  = 0x0002;
    quint16    m_usVCReceiverID = 0x0001; // Vital Controller fixed per ICD
    quint8     m_ucELUChannelID = 0x01;   // 0x01=ELU-A, 0x02=ELU-B

    // Last GPS position (updated by SlotGPSPosition)
    double     m_dLastLat  = 0.0;
    double     m_dLastLon  = 0.0;
    bool       m_bGNSSValid = false;
    bool       m_bPPSValid  = false;

    // Packet builders — no new class; all logic inline in nmsMainWindow.cpp
    QByteArray Build0x28Packet();
    QByteArray Build0xA2Packet();
    quint32    CalcCRC32(const QByteArray &data);

    // Encodes lat/lon per ICD §2.3 bit layout
    static quint32 EncodeLatLon(double decDeg, int degBits, int minBits, int secBits);

    void InitVCHeartbeat();   // called from constructor

    void Init();
    void InitKMSConnections();
    void InitUDP();
    void InitDB();
    void InitLogFile();
    void InitnmsDBConnections();
    void InitNMSForwarder();
    void InitNMSPingThread();          // NEW — starts ping thread

    // Returns true if the NMS application is accepting UDP on m_usNMSPort.
    // Sends a 1-byte probe and checks for ICMP port-unreachable.
    bool ProbeNMSApp();

    // Returns true if datagram with msg_type ucType should be sent
    // when the NMS app is down (ping OK but app not responding).
    static bool IsPriorityPacket(quint8 ucType);

    // Insert raw datagram into nms_packet_log table (called by ForwardToNMS)
    void InsertPacketLog(const QByteArray &datagram);

    // Fetch raw datagrams from nms_packet_log between two timestamps
    QList<QByteArray> FetchPacketLog(const QDateTime &from,
                                     const QDateTime &to);

    QString GetRIUEventData(uint32_t usEvntCode, uint16_t usStnID);

    void ForwardToNMS(QByteArray datagram);

    void ForwardViaGSM(const QByteArray &datagram);

    bool SendViaNMSGSM(const QByteArray &datagram);

    void SendAckNMStoKavach(QHostAddress senderIP, quint16 senderPort);
    void SendAckNMStoSKavach(QHostAddress senderIP, quint16 senderPort);
    void SendAckNMStoSKavachFaults(QHostAddress senderIP, quint16 senderPort);
    void SendSMS(QString mobileNumber, QString message);
    QString GetFaultsCodeDescription(uint16_t usFaultCode);
    QString GetOnBoardHlthEvntName(uint16_t usEvntID);
    QString GetStnHlthEventName(uint16_t usEvntID);
    QString GetLocoMode(uint8_t ucLocoMode);
    QString GetEmergencyStatus(uint8_t ucEmergSts);
    QString getStationCode(QString &strstationName);
    void InitKavachParsePkt();
    void InitNMSForwarder_internal();
    void parsePDIVersionCheckPacket(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset);
    void parsePDIVersionCheckMsgPacket(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset);
    void parseHeartBeatPacket(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset);
    void parseTrainHandOverReqPacket(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset);
    void parseTrainRRIMsgPacket(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset);
    void parseTrainTakenOverMsgPacket(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset);
    void parseTrainHandOverCancellationMsgPacket(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset);
    void parseTrainLengthInformationPacket(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset);
    void parseTrainLengthInformationAck(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset);
    void parseTSLRouteReqPacket(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset);
    void parseTSLInformationPacket(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset);
    void parseFieldElementStatusReqPacket(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset);
    void parseTrainHandOverCancellationAck(stPacketHeader stPktHdr, QByteArray &byArrdatagram, int payloadOffset);


    void InitCFGFile();
    void SlotUpadateSchematic_internal();
};

#endif // NMSMAINWINDOW_H