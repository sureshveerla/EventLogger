#ifndef NMSDBQUERYS_H
#define NMSDBQUERYS_H

#include "nmsQtInc.h"
#include "nmsDB.h"
#include "nmsStructs.h"
#include "nmsDefines.h"

class nmsDBQuerys : public QObject
{
    Q_OBJECT

public:

    explicit nmsDBQuerys(NMSDB * pcDB,
                          QObject *pcParent = nullptr);

    bool Exec (QSqlQuery *&pcQry, const QString strSqlStmt);

    QString GetStationFirmName(uint32_t uiID);
    QString GetLocoFirmName(uint32_t uiID);
    QString GetMobileNumberForName(QString strFirmName);
    QString GetFaultDescription(uint16_t usFaultCode);

    quint64 getLastPktId();


public slots:

    void SlotInsertSMSNumbers(QString strUName, QString strMobNo, bool bStatus);
    void SlotFetchSMSNumbers();
    void SlotDeleteSMSNumber(QString strMobNo);
    void SlotUpdateSMSNumber (QString strName,QString strMobNo,bool bstatus);
    void SlotUpdateSMSNumber (QList<QList<QString>> lstvalues);

    void SlotFaultPktInserttoDB(stKavachtoNMS *pstKavachtoNMS,QString strFaultsCode,QString strFaultMsg);

    void SlotStnFaultPktInserttoDB(stStationFaults *pstStnFaults, QStringList strLstModuleID,
                                   QStringList strLstFaultCodeTyp, QStringList strFaultsCode, QStringList strFaultMsg);

    void SlotStationInfo();

    void SlotLocoInfo();

    void SlotPrvPromptInfo();

    void SlotFaultMsginserttoDB(QString strMsgType,QString strTimestamp,
                                QList<uint16_t> faultByteArray,QString strFirmNam,uint32_t uiID);

    void SlotStnFaultMsginserttoDB(QString strMsgType,QString strTimestamp,
                                  uint16_t usFaultCode,QString strFirmNam,uint32_t uiID);
    void SlotSMSFaultMsginserttoDB(QString strMsgType,QString strTimestamp,
                                   QList<uint16_t> faultByteArray,QString strFirmnamID); // temporary

    void SlotSMSStnFaultMsginserttoDB(QString strMsgType,QString strTimestamp,
                                     uint16_t usFaultCOde,QString strFirmNamID); // temporary


    void SlotAccessReqInsertintoDB(stAccessRequestPkt stheader,uint32_t uiPktType,uint32_t uiPktLen,uint32_t uiFrmNo,
                                  uint32_t uiSrcLocoID,uint32_t uiSrcLocoVer,uint32_t uiAbsLoco_Loc,uint32_t uiTrainLen,uint32_t uiTrainSpd,
                                  uint32_t uiMovMntDir,uint32_t uiEmergencySts,uint32_t uiLocoMode,uint32_t uiApprStID,uint32_t uiLastRfidTag,
                                  uint32_t uitinNo,uint32_t uiLongitude,uint32_t uiLatitude,uint32_t uiLocoRandmrl,
                                  uint32_t uiMACCode,uint32_t uiPktCRC, uint8_t ucMASecCnt,uint16_t usRouteID,uint32_t uiCRC);

    void SlotLocoRegularInsertintoDB(stAccessRequestPkt stheader,uint32_t uiPktType,uint32_t uiPktLen,uint32_t uiFrmNo,
                                    uint32_t uiSrcLocoID,uint32_t uiSrcLocoVer,uint32_t uiAbsLoco_Loc,
                                    uint32_t uidoubtover,uint32_t uidoubtunder,uint32_t uitrainint,
                                    uint32_t uiTrainLen,uint32_t uiTrainSpd,uint32_t uiMovMntDir,
                                    uint32_t uiEmergencySts,uint32_t uiLocoMode,uint32_t uiLastRfidTag,
                                    uint32_t uiTagDup,uint32_t uitagLinkInfo,uint32_t uitinNo,
                                    uint32_t uiBrkApply,uint32_t uinewMAReply,uint32_t uiLastRefProfNo,
                                    uint32_t uiSigOV,uint32_t uiInfoAck,uint32_t uiSpare,QString strLocoHlthSts,
                                    uint32_t uiMACCode,uint32_t uiPktCRC,uint8_t ucMASecCnt,
                                     uint16_t usRouteID,uint32_t uiCRC);

    void SlotAccessAuthorityPktInsertintoDB(stAccessRequestPkt stheader, uint32_t uiPktType, uint32_t uiPktLen,
                                            uint32_t uiFrmNo, uint32_t uiSrcStnILCIBS_ID,
                                            uint32_t uiSRCStnILCIBS_ver, uint32_t uiStnILCIBS_Loc,
                                            uint32_t uiDestLoco_ID, uint32_t uiAlotUpLnk_Freq,
                                            uint32_t uiAlotDnLnk_Freq, uint32_t uiAlotTDMA_Timeslots,
                                            uint32_t uiStnRndNum_RS, uint32_t uiStnTDMA,
                                            uint32_t uiMAC_Code, uint32_t uiPktCrc, uint32_t uiCRC);

    void SlotAdditionalEmergencyPktInsertintoDB(stAccessRequestPkt stheader,uint32_t uiPktType,uint32_t uiPktLen,
                                               uint32_t uiFrmNo,uint32_t uiSrcStnILCIBS_ID,
                                               uint32_t uiSRCStnILCIBS_ver,uint32_t uiStnILCIBS_Loc,
                                               uint32_t uiGenSoSCall,uint32_t uiCRC);

    void SlotInsertDBStnRegMASubPkt(MovementAuthorityPkt stMAPkt);
    void SlotInsertDBStnRegSSPSubPkt(StaticSpeedProfilePkt stSSPPkt);
    void SlotInsertDBStnRegGradientSubPkt(GradientProfilePkt stGradprofPkt);
    void SlotInsertDBStnRegLCGateSubPkt(LCGateProfilePkt stLCGatePkt);
    void SlotInsertDBStnRegTurnoutSpeedSubPkt(TurnoutSpeedProfilePkt stTSPPkt);
    void SlotInsertDBStnRegTagLinkingInfoSubPkt(TagLinkingInfoPkt stTagLinkInfPkt);
    void SlotInsertDBStnRegTrackCondDataSubPkt(TrackConditionPkt stTrackCondDataPkt);
    void SlotInsertDBStnRegTSRSubPkt(TempSpeedRestrictionPkt stTSRPkt);

    quint64 SlotInsertDBStationRegHeader(stAccessRequestPkt stHeader,StationRegularHeader stStnRglrHPkt);

    void SlotInsertDBStationhealthPkt(stStationHealthPkt stStnHlthPkt,QStringList strEvntID,
                                      QStringList strEvntData,uint32_t uiCrc);

    void SlotInsertDBOnBoardhealthPkt(stOnBoardHealthPkt stOnBrdHlthPkt,QString strEvntID,
                                      QString strEvntData,uint32_t uiCrc);

    void SlotInsertDBS2SPDIVerCmd(stPacketHeader stPktHdr,stPDIVerCheckCmdPkt stPDIVerCmd);
    void SlotInsertDBS2SPDIVerMsg(stPacketHeader stPktHdr,stPDIVerCheckMsgPkt stPDIVerMsg);
    void SlotInsertDBS2SHeartBeat(stPacketHeader stPktHdr,stHeartBeatPkt stHeartBeat);
    void SlotInsertDBS2STrainHandOverReq(stPacketHeader stPktHdr,stTrainHandOverReqPkt stTrnHndOveReq);
    void SlotInsertDBS2STrainTakenOverMsg(stPacketHeader stPktHdr,stTrainTakenOverPkt stTrnTknOveMsg);
    void SlotInsertDBS2STrainHandOverCancellationReq(stPacketHeader stPktHdr,stTrainHandOverCancellationPkt stTrnHndOvrCnclPkt);
    void SlotInsertDBS2STrainLengthInformationReq(stPacketHeader stPktHdr,stTrainLengthInfoPkt stTrnLenInfoPkt);
    void SlotInsertDBS2SLengthInformationAck(stPacketHeader stPktHdr,stTrainLengthInfoAck stTrnLenInfoAck);
    void SlotInsertDBS2STSLRouteRequest(stPacketHeader stPktHdr,stTSLReqPkt stTSLRouteReq);
    void SlotInsertDBS2STSLAuthorityInformationPkt(stPacketHeader stPktHdr,stTSLInformationPkt stTSLInfoPkt);
    void SlotInsertDBS2SFieldElementsStatusReq(stPacketHeader stPktHdr,stFieldElementsStatusReqPkt stFldElementStsReq);
    void SlotInsertDBS2STrainHandoverCancellationAck(stPacketHeader stPktHdr,stTrainHandOverCancellationAckPkt stTrnHndOvrCnclAck);

    void SlotInsertDBLocoRSSIMessage(stLocoRSSIMsg stLocoRSSI);
    void SlotInsertDBStationRSSIMessage(stStationRSSIMsg stStnRSSI);
    void SlotInsertDBStatioKavachSysSts(stStationaryKavachSysInfo stStnKavchSysSts); //station system status

    void SlotInsertDBOnBoardEventMsg(stOnboardKavachEventMsg stOnBoardEvntMsg);  //onboard event
    void SlotInsertDBOnBoardBrakeEventMsg(stOnboardKavachBrakeEventMsg stOnBoardBrakeEvntMsg); //onboard Brake
    void SlotInsertDBOnboardBOKSHealthMsg(stOnboardKavachBOKSHealthMsg stOnBoardSysHealth); //onboard sys health

    void SlotInsertDBFieldInputStatus(stPacketHeader stPktHdr,uint16_t usRelayCnt,QByteArray byArrRelayImage,uint32_t uiCRC);
    void SlotInsertDBFieldInputEventData(stFieldEventData stFldEvntData);

    void SlotInserttoDBFieldStatus(QString strFieldId,uint8_t ucStatus);

   /********* insert Remote users **********/

    void SlotInsertRemoteUser(QString strName,QString strUName,QString strPwd,bool bStatus);

    void SlotFetchRemoteUsers();

    void SlotDeleteRemoteUser(QString strUserID);

    void SlotUpdateRemoteUser(QList<QList<QString>> lstvalues);



signals:

    void SigDBSMSnumbersResults(uint8_t ucColCount,uint16_t usRowCount,
                                QStringList strlstFldNames,QStringList strlstRowValues);

    void SigDBRemoteUserResults(uint8_t ucColCount,uint16_t usRowCount,
                                QStringList strlstFldNames,QStringList strlstRowValues);
    void SigDBStationInfo(uint8_t ucColCount,uint16_t usRowCount,
                          QStringList strlstFldNames,QStringList strlstRowValues);

    void SigDBLocoInfo(uint8_t ucColCount,uint16_t usRowCount,
                          QStringList strlstFldNames,QStringList strlstRowValues);

    void SigDBfaultmsgInfo(uint8_t ucColCount,uint16_t usRowCount,
                       QStringList strlstFldNames,QStringList strlstRowValues);

    void SigDBSMSFaultsinfo(uint8_t ucColCount,uint16_t usRowCount,
                            QStringList strlstFldNames,QList<QStringList> strlstRowValues);

private:

    NMSDB *m_pcDB;

    quint32 m_uiStationID;

    QString m_strFirmName;

    uint64_t m_ulPktId;

    void InsertHBLFaultMsg(QString strMsgType, QString strTimestamp,QString strFaultCode,
                           QString strFirmNam,uint32_t uiID,QString strFaultMsg);
    void InsertMEDHAFaultMsg(QString strMsgType, QString strTimestamp,uint16_t usFaultCode,
                             QString strFirmNam,uint32_t uiID,QString strFaultMsg);

    void InsertSMSHBLFaultMsg(QString strMsgType, QString strTimestamp, QString strFaultCode,
                              QString strFirmnamid, QString strFaultMsg);

    void InsertSMSMEDHAFaultMsg(QString strMsgType, QString strTimestamp,uint16_t usFaultCode,
                                QString strFirmnamid,QString strFaultMsg);

    QString GetDestLocoSoS(SoSEmergencyCondition enmSoS);
    QString GetTrainSectionType(SectionType enmTrnSecTyp);
    QString GetSignalAspects(SIG_ASPECTS enmSigAsp);
    QString GetAuthorityType(AUTH_TYPE enmAuthType);
    QString GetSubPktType(enmSubPktType enmSubPktTyp);
    QString GetLocoMode(uint8_t ucLocoMode);
    QString GetEmergencyStatus(uint8_t ucEmergSts);
    QString GetFrameTime(uint32_t uiFrmNo);
    QString GetModeDescription(quint16 usMode);
    QString GetEventStatusDescription(quint8 ucStatus);
    QString GetAckStatusDescription(quint8 ucAckStatus);
    QString GetIncidentDescription(quint16 usIncidentID);
    QString GetBrakeTypeDescription(quint8 ucBrakeType);
    QString GetDirectionDescription(quint8 ucDirection);
    QString GetBrakeEventStatusDescription(quint8 ucStatus);
    QString GetBrakeAckStatusDescription(quint8 ucAckStatus);
    QString GetBrakeCauseDescription(quint16 usCauseID);

    void EnsureGradientColumns(int count);
};

#endif // NMSDBQUERYS_H
