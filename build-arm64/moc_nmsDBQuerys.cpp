/****************************************************************************
** Meta object code from reading C++ file 'nmsDBQuerys.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../include/nmsDBQuerys.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nmsDBQuerys.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_nmsDBQuerys_t {
    const uint offsetsAndSize[424];
    char stringdata0[3820];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_nmsDBQuerys_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_nmsDBQuerys_t qt_meta_stringdata_nmsDBQuerys = {
    {
QT_MOC_LITERAL(0, 11), // "nmsDBQuerys"
QT_MOC_LITERAL(12, 22), // "SigDBSMSnumbersResults"
QT_MOC_LITERAL(35, 0), // ""
QT_MOC_LITERAL(36, 7), // "uint8_t"
QT_MOC_LITERAL(44, 10), // "ucColCount"
QT_MOC_LITERAL(55, 8), // "uint16_t"
QT_MOC_LITERAL(64, 10), // "usRowCount"
QT_MOC_LITERAL(75, 14), // "strlstFldNames"
QT_MOC_LITERAL(90, 15), // "strlstRowValues"
QT_MOC_LITERAL(106, 22), // "SigDBRemoteUserResults"
QT_MOC_LITERAL(129, 16), // "SigDBStationInfo"
QT_MOC_LITERAL(146, 13), // "SigDBLocoInfo"
QT_MOC_LITERAL(160, 17), // "SigDBfaultmsgInfo"
QT_MOC_LITERAL(178, 18), // "SigDBSMSFaultsinfo"
QT_MOC_LITERAL(197, 18), // "QList<QStringList>"
QT_MOC_LITERAL(216, 20), // "SlotInsertSMSNumbers"
QT_MOC_LITERAL(237, 8), // "strUName"
QT_MOC_LITERAL(246, 8), // "strMobNo"
QT_MOC_LITERAL(255, 7), // "bStatus"
QT_MOC_LITERAL(263, 19), // "SlotFetchSMSNumbers"
QT_MOC_LITERAL(283, 19), // "SlotDeleteSMSNumber"
QT_MOC_LITERAL(303, 19), // "SlotUpdateSMSNumber"
QT_MOC_LITERAL(323, 7), // "strName"
QT_MOC_LITERAL(331, 7), // "bstatus"
QT_MOC_LITERAL(339, 21), // "QList<QList<QString>>"
QT_MOC_LITERAL(361, 9), // "lstvalues"
QT_MOC_LITERAL(371, 22), // "SlotFaultPktInserttoDB"
QT_MOC_LITERAL(394, 14), // "stKavachtoNMS*"
QT_MOC_LITERAL(409, 14), // "pstKavachtoNMS"
QT_MOC_LITERAL(424, 13), // "strFaultsCode"
QT_MOC_LITERAL(438, 11), // "strFaultMsg"
QT_MOC_LITERAL(450, 25), // "SlotStnFaultPktInserttoDB"
QT_MOC_LITERAL(476, 16), // "stStationFaults*"
QT_MOC_LITERAL(493, 12), // "pstStnFaults"
QT_MOC_LITERAL(506, 15), // "SlotStationInfo"
QT_MOC_LITERAL(522, 12), // "SlotLocoInfo"
QT_MOC_LITERAL(535, 17), // "SlotPrvPromptInfo"
QT_MOC_LITERAL(553, 22), // "SlotFaultMsginserttoDB"
QT_MOC_LITERAL(576, 10), // "strMsgType"
QT_MOC_LITERAL(587, 12), // "strTimestamp"
QT_MOC_LITERAL(600, 15), // "QList<uint16_t>"
QT_MOC_LITERAL(616, 14), // "faultByteArray"
QT_MOC_LITERAL(631, 10), // "strFirmNam"
QT_MOC_LITERAL(642, 8), // "uint32_t"
QT_MOC_LITERAL(651, 4), // "uiID"
QT_MOC_LITERAL(656, 25), // "SlotStnFaultMsginserttoDB"
QT_MOC_LITERAL(682, 11), // "usFaultCode"
QT_MOC_LITERAL(694, 25), // "SlotSMSFaultMsginserttoDB"
QT_MOC_LITERAL(720, 12), // "strFirmnamID"
QT_MOC_LITERAL(733, 28), // "SlotSMSStnFaultMsginserttoDB"
QT_MOC_LITERAL(762, 11), // "usFaultCOde"
QT_MOC_LITERAL(774, 12), // "strFirmNamID"
QT_MOC_LITERAL(787, 25), // "SlotAccessReqInsertintoDB"
QT_MOC_LITERAL(813, 18), // "stAccessRequestPkt"
QT_MOC_LITERAL(832, 8), // "stheader"
QT_MOC_LITERAL(841, 9), // "uiPktType"
QT_MOC_LITERAL(851, 8), // "uiPktLen"
QT_MOC_LITERAL(860, 7), // "uiFrmNo"
QT_MOC_LITERAL(868, 11), // "uiSrcLocoID"
QT_MOC_LITERAL(880, 12), // "uiSrcLocoVer"
QT_MOC_LITERAL(893, 13), // "uiAbsLoco_Loc"
QT_MOC_LITERAL(907, 10), // "uiTrainLen"
QT_MOC_LITERAL(918, 10), // "uiTrainSpd"
QT_MOC_LITERAL(929, 11), // "uiMovMntDir"
QT_MOC_LITERAL(941, 14), // "uiEmergencySts"
QT_MOC_LITERAL(956, 10), // "uiLocoMode"
QT_MOC_LITERAL(967, 10), // "uiApprStID"
QT_MOC_LITERAL(978, 13), // "uiLastRfidTag"
QT_MOC_LITERAL(992, 7), // "uitinNo"
QT_MOC_LITERAL(1000, 11), // "uiLongitude"
QT_MOC_LITERAL(1012, 10), // "uiLatitude"
QT_MOC_LITERAL(1023, 13), // "uiLocoRandmrl"
QT_MOC_LITERAL(1037, 9), // "uiMACCode"
QT_MOC_LITERAL(1047, 8), // "uiPktCRC"
QT_MOC_LITERAL(1056, 10), // "ucMASecCnt"
QT_MOC_LITERAL(1067, 9), // "usRouteID"
QT_MOC_LITERAL(1077, 5), // "uiCRC"
QT_MOC_LITERAL(1083, 27), // "SlotLocoRegularInsertintoDB"
QT_MOC_LITERAL(1111, 11), // "uidoubtover"
QT_MOC_LITERAL(1123, 12), // "uidoubtunder"
QT_MOC_LITERAL(1136, 10), // "uitrainint"
QT_MOC_LITERAL(1147, 8), // "uiTagDup"
QT_MOC_LITERAL(1156, 13), // "uitagLinkInfo"
QT_MOC_LITERAL(1170, 10), // "uiBrkApply"
QT_MOC_LITERAL(1181, 12), // "uinewMAReply"
QT_MOC_LITERAL(1194, 15), // "uiLastRefProfNo"
QT_MOC_LITERAL(1210, 7), // "uiSigOV"
QT_MOC_LITERAL(1218, 9), // "uiInfoAck"
QT_MOC_LITERAL(1228, 7), // "uiSpare"
QT_MOC_LITERAL(1236, 14), // "strLocoHlthSts"
QT_MOC_LITERAL(1251, 34), // "SlotAccessAuthorityPktInserti..."
QT_MOC_LITERAL(1286, 17), // "uiSrcStnILCIBS_ID"
QT_MOC_LITERAL(1304, 18), // "uiSRCStnILCIBS_ver"
QT_MOC_LITERAL(1323, 15), // "uiStnILCIBS_Loc"
QT_MOC_LITERAL(1339, 13), // "uiDestLoco_ID"
QT_MOC_LITERAL(1353, 16), // "uiAlotUpLnk_Freq"
QT_MOC_LITERAL(1370, 16), // "uiAlotDnLnk_Freq"
QT_MOC_LITERAL(1387, 20), // "uiAlotTDMA_Timeslots"
QT_MOC_LITERAL(1408, 14), // "uiStnRndNum_RS"
QT_MOC_LITERAL(1423, 9), // "uiStnTDMA"
QT_MOC_LITERAL(1433, 10), // "uiMAC_Code"
QT_MOC_LITERAL(1444, 8), // "uiPktCrc"
QT_MOC_LITERAL(1453, 38), // "SlotAdditionalEmergencyPktIns..."
QT_MOC_LITERAL(1492, 12), // "uiGenSoSCall"
QT_MOC_LITERAL(1505, 26), // "SlotInsertDBStnRegMASubPkt"
QT_MOC_LITERAL(1532, 20), // "MovementAuthorityPkt"
QT_MOC_LITERAL(1553, 7), // "stMAPkt"
QT_MOC_LITERAL(1561, 27), // "SlotInsertDBStnRegSSPSubPkt"
QT_MOC_LITERAL(1589, 21), // "StaticSpeedProfilePkt"
QT_MOC_LITERAL(1611, 8), // "stSSPPkt"
QT_MOC_LITERAL(1620, 32), // "SlotInsertDBStnRegGradientSubPkt"
QT_MOC_LITERAL(1653, 18), // "GradientProfilePkt"
QT_MOC_LITERAL(1672, 13), // "stGradprofPkt"
QT_MOC_LITERAL(1686, 30), // "SlotInsertDBStnRegLCGateSubPkt"
QT_MOC_LITERAL(1717, 16), // "LCGateProfilePkt"
QT_MOC_LITERAL(1734, 11), // "stLCGatePkt"
QT_MOC_LITERAL(1746, 36), // "SlotInsertDBStnRegTurnoutSpee..."
QT_MOC_LITERAL(1783, 22), // "TurnoutSpeedProfilePkt"
QT_MOC_LITERAL(1806, 8), // "stTSPPkt"
QT_MOC_LITERAL(1815, 38), // "SlotInsertDBStnRegTagLinkingI..."
QT_MOC_LITERAL(1854, 17), // "TagLinkingInfoPkt"
QT_MOC_LITERAL(1872, 15), // "stTagLinkInfPkt"
QT_MOC_LITERAL(1888, 37), // "SlotInsertDBStnRegTrackCondDa..."
QT_MOC_LITERAL(1926, 17), // "TrackConditionPkt"
QT_MOC_LITERAL(1944, 18), // "stTrackCondDataPkt"
QT_MOC_LITERAL(1963, 27), // "SlotInsertDBStnRegTSRSubPkt"
QT_MOC_LITERAL(1991, 23), // "TempSpeedRestrictionPkt"
QT_MOC_LITERAL(2015, 8), // "stTSRPkt"
QT_MOC_LITERAL(2024, 28), // "SlotInsertDBStationRegHeader"
QT_MOC_LITERAL(2053, 8), // "stHeader"
QT_MOC_LITERAL(2062, 20), // "StationRegularHeader"
QT_MOC_LITERAL(2083, 13), // "stStnRglrHPkt"
QT_MOC_LITERAL(2097, 28), // "SlotInsertDBStationhealthPkt"
QT_MOC_LITERAL(2126, 18), // "stStationHealthPkt"
QT_MOC_LITERAL(2145, 12), // "stStnHlthPkt"
QT_MOC_LITERAL(2158, 9), // "strEvntID"
QT_MOC_LITERAL(2168, 11), // "strEvntData"
QT_MOC_LITERAL(2180, 5), // "uiCrc"
QT_MOC_LITERAL(2186, 28), // "SlotInsertDBOnBoardhealthPkt"
QT_MOC_LITERAL(2215, 18), // "stOnBoardHealthPkt"
QT_MOC_LITERAL(2234, 14), // "stOnBrdHlthPkt"
QT_MOC_LITERAL(2249, 24), // "SlotInsertDBS2SPDIVerCmd"
QT_MOC_LITERAL(2274, 14), // "stPacketHeader"
QT_MOC_LITERAL(2289, 8), // "stPktHdr"
QT_MOC_LITERAL(2298, 19), // "stPDIVerCheckCmdPkt"
QT_MOC_LITERAL(2318, 11), // "stPDIVerCmd"
QT_MOC_LITERAL(2330, 24), // "SlotInsertDBS2SPDIVerMsg"
QT_MOC_LITERAL(2355, 19), // "stPDIVerCheckMsgPkt"
QT_MOC_LITERAL(2375, 11), // "stPDIVerMsg"
QT_MOC_LITERAL(2387, 24), // "SlotInsertDBS2SHeartBeat"
QT_MOC_LITERAL(2412, 14), // "stHeartBeatPkt"
QT_MOC_LITERAL(2427, 11), // "stHeartBeat"
QT_MOC_LITERAL(2439, 31), // "SlotInsertDBS2STrainHandOverReq"
QT_MOC_LITERAL(2471, 21), // "stTrainHandOverReqPkt"
QT_MOC_LITERAL(2493, 14), // "stTrnHndOveReq"
QT_MOC_LITERAL(2508, 32), // "SlotInsertDBS2STrainTakenOverMsg"
QT_MOC_LITERAL(2541, 19), // "stTrainTakenOverPkt"
QT_MOC_LITERAL(2561, 14), // "stTrnTknOveMsg"
QT_MOC_LITERAL(2576, 43), // "SlotInsertDBS2STrainHandOverC..."
QT_MOC_LITERAL(2620, 30), // "stTrainHandOverCancellationPkt"
QT_MOC_LITERAL(2651, 18), // "stTrnHndOvrCnclPkt"
QT_MOC_LITERAL(2670, 40), // "SlotInsertDBS2STrainLengthInf..."
QT_MOC_LITERAL(2711, 20), // "stTrainLengthInfoPkt"
QT_MOC_LITERAL(2732, 15), // "stTrnLenInfoPkt"
QT_MOC_LITERAL(2748, 35), // "SlotInsertDBS2SLengthInformat..."
QT_MOC_LITERAL(2784, 20), // "stTrainLengthInfoAck"
QT_MOC_LITERAL(2805, 15), // "stTrnLenInfoAck"
QT_MOC_LITERAL(2821, 30), // "SlotInsertDBS2STSLRouteRequest"
QT_MOC_LITERAL(2852, 11), // "stTSLReqPkt"
QT_MOC_LITERAL(2864, 13), // "stTSLRouteReq"
QT_MOC_LITERAL(2878, 41), // "SlotInsertDBS2STSLAuthorityIn..."
QT_MOC_LITERAL(2920, 19), // "stTSLInformationPkt"
QT_MOC_LITERAL(2940, 12), // "stTSLInfoPkt"
QT_MOC_LITERAL(2953, 37), // "SlotInsertDBS2SFieldElementsS..."
QT_MOC_LITERAL(2991, 27), // "stFieldElementsStatusReqPkt"
QT_MOC_LITERAL(3019, 18), // "stFldElementStsReq"
QT_MOC_LITERAL(3038, 43), // "SlotInsertDBS2STrainHandoverC..."
QT_MOC_LITERAL(3082, 33), // "stTrainHandOverCancellationAc..."
QT_MOC_LITERAL(3116, 18), // "stTrnHndOvrCnclAck"
QT_MOC_LITERAL(3135, 27), // "SlotInsertDBLocoRSSIMessage"
QT_MOC_LITERAL(3163, 13), // "stLocoRSSIMsg"
QT_MOC_LITERAL(3177, 10), // "stLocoRSSI"
QT_MOC_LITERAL(3188, 30), // "SlotInsertDBStationRSSIMessage"
QT_MOC_LITERAL(3219, 16), // "stStationRSSIMsg"
QT_MOC_LITERAL(3236, 9), // "stStnRSSI"
QT_MOC_LITERAL(3246, 30), // "SlotInsertDBStatioKavachSysSts"
QT_MOC_LITERAL(3277, 25), // "stStationaryKavachSysInfo"
QT_MOC_LITERAL(3303, 16), // "stStnKavchSysSts"
QT_MOC_LITERAL(3320, 27), // "SlotInsertDBOnBoardEventMsg"
QT_MOC_LITERAL(3348, 23), // "stOnboardKavachEventMsg"
QT_MOC_LITERAL(3372, 16), // "stOnBoardEvntMsg"
QT_MOC_LITERAL(3389, 32), // "SlotInsertDBOnBoardBrakeEventMsg"
QT_MOC_LITERAL(3422, 28), // "stOnboardKavachBrakeEventMsg"
QT_MOC_LITERAL(3451, 21), // "stOnBoardBrakeEvntMsg"
QT_MOC_LITERAL(3473, 32), // "SlotInsertDBOnboardBOKSHealthMsg"
QT_MOC_LITERAL(3506, 28), // "stOnboardKavachBOKSHealthMsg"
QT_MOC_LITERAL(3535, 18), // "stOnBoardSysHealth"
QT_MOC_LITERAL(3554, 28), // "SlotInsertDBFieldInputStatus"
QT_MOC_LITERAL(3583, 10), // "usRelayCnt"
QT_MOC_LITERAL(3594, 15), // "byArrRelayImage"
QT_MOC_LITERAL(3610, 31), // "SlotInsertDBFieldInputEventData"
QT_MOC_LITERAL(3642, 16), // "stFieldEventData"
QT_MOC_LITERAL(3659, 13), // "stFldEvntData"
QT_MOC_LITERAL(3673, 25), // "SlotInserttoDBFieldStatus"
QT_MOC_LITERAL(3699, 10), // "strFieldId"
QT_MOC_LITERAL(3710, 8), // "ucStatus"
QT_MOC_LITERAL(3719, 20), // "SlotInsertRemoteUser"
QT_MOC_LITERAL(3740, 6), // "strPwd"
QT_MOC_LITERAL(3747, 20), // "SlotFetchRemoteUsers"
QT_MOC_LITERAL(3768, 20), // "SlotDeleteRemoteUser"
QT_MOC_LITERAL(3789, 9), // "strUserID"
QT_MOC_LITERAL(3799, 20) // "SlotUpdateRemoteUser"

    },
    "nmsDBQuerys\0SigDBSMSnumbersResults\0\0"
    "uint8_t\0ucColCount\0uint16_t\0usRowCount\0"
    "strlstFldNames\0strlstRowValues\0"
    "SigDBRemoteUserResults\0SigDBStationInfo\0"
    "SigDBLocoInfo\0SigDBfaultmsgInfo\0"
    "SigDBSMSFaultsinfo\0QList<QStringList>\0"
    "SlotInsertSMSNumbers\0strUName\0strMobNo\0"
    "bStatus\0SlotFetchSMSNumbers\0"
    "SlotDeleteSMSNumber\0SlotUpdateSMSNumber\0"
    "strName\0bstatus\0QList<QList<QString>>\0"
    "lstvalues\0SlotFaultPktInserttoDB\0"
    "stKavachtoNMS*\0pstKavachtoNMS\0"
    "strFaultsCode\0strFaultMsg\0"
    "SlotStnFaultPktInserttoDB\0stStationFaults*\0"
    "pstStnFaults\0SlotStationInfo\0SlotLocoInfo\0"
    "SlotPrvPromptInfo\0SlotFaultMsginserttoDB\0"
    "strMsgType\0strTimestamp\0QList<uint16_t>\0"
    "faultByteArray\0strFirmNam\0uint32_t\0"
    "uiID\0SlotStnFaultMsginserttoDB\0"
    "usFaultCode\0SlotSMSFaultMsginserttoDB\0"
    "strFirmnamID\0SlotSMSStnFaultMsginserttoDB\0"
    "usFaultCOde\0strFirmNamID\0"
    "SlotAccessReqInsertintoDB\0stAccessRequestPkt\0"
    "stheader\0uiPktType\0uiPktLen\0uiFrmNo\0"
    "uiSrcLocoID\0uiSrcLocoVer\0uiAbsLoco_Loc\0"
    "uiTrainLen\0uiTrainSpd\0uiMovMntDir\0"
    "uiEmergencySts\0uiLocoMode\0uiApprStID\0"
    "uiLastRfidTag\0uitinNo\0uiLongitude\0"
    "uiLatitude\0uiLocoRandmrl\0uiMACCode\0"
    "uiPktCRC\0ucMASecCnt\0usRouteID\0uiCRC\0"
    "SlotLocoRegularInsertintoDB\0uidoubtover\0"
    "uidoubtunder\0uitrainint\0uiTagDup\0"
    "uitagLinkInfo\0uiBrkApply\0uinewMAReply\0"
    "uiLastRefProfNo\0uiSigOV\0uiInfoAck\0"
    "uiSpare\0strLocoHlthSts\0"
    "SlotAccessAuthorityPktInsertintoDB\0"
    "uiSrcStnILCIBS_ID\0uiSRCStnILCIBS_ver\0"
    "uiStnILCIBS_Loc\0uiDestLoco_ID\0"
    "uiAlotUpLnk_Freq\0uiAlotDnLnk_Freq\0"
    "uiAlotTDMA_Timeslots\0uiStnRndNum_RS\0"
    "uiStnTDMA\0uiMAC_Code\0uiPktCrc\0"
    "SlotAdditionalEmergencyPktInsertintoDB\0"
    "uiGenSoSCall\0SlotInsertDBStnRegMASubPkt\0"
    "MovementAuthorityPkt\0stMAPkt\0"
    "SlotInsertDBStnRegSSPSubPkt\0"
    "StaticSpeedProfilePkt\0stSSPPkt\0"
    "SlotInsertDBStnRegGradientSubPkt\0"
    "GradientProfilePkt\0stGradprofPkt\0"
    "SlotInsertDBStnRegLCGateSubPkt\0"
    "LCGateProfilePkt\0stLCGatePkt\0"
    "SlotInsertDBStnRegTurnoutSpeedSubPkt\0"
    "TurnoutSpeedProfilePkt\0stTSPPkt\0"
    "SlotInsertDBStnRegTagLinkingInfoSubPkt\0"
    "TagLinkingInfoPkt\0stTagLinkInfPkt\0"
    "SlotInsertDBStnRegTrackCondDataSubPkt\0"
    "TrackConditionPkt\0stTrackCondDataPkt\0"
    "SlotInsertDBStnRegTSRSubPkt\0"
    "TempSpeedRestrictionPkt\0stTSRPkt\0"
    "SlotInsertDBStationRegHeader\0stHeader\0"
    "StationRegularHeader\0stStnRglrHPkt\0"
    "SlotInsertDBStationhealthPkt\0"
    "stStationHealthPkt\0stStnHlthPkt\0"
    "strEvntID\0strEvntData\0uiCrc\0"
    "SlotInsertDBOnBoardhealthPkt\0"
    "stOnBoardHealthPkt\0stOnBrdHlthPkt\0"
    "SlotInsertDBS2SPDIVerCmd\0stPacketHeader\0"
    "stPktHdr\0stPDIVerCheckCmdPkt\0stPDIVerCmd\0"
    "SlotInsertDBS2SPDIVerMsg\0stPDIVerCheckMsgPkt\0"
    "stPDIVerMsg\0SlotInsertDBS2SHeartBeat\0"
    "stHeartBeatPkt\0stHeartBeat\0"
    "SlotInsertDBS2STrainHandOverReq\0"
    "stTrainHandOverReqPkt\0stTrnHndOveReq\0"
    "SlotInsertDBS2STrainTakenOverMsg\0"
    "stTrainTakenOverPkt\0stTrnTknOveMsg\0"
    "SlotInsertDBS2STrainHandOverCancellationReq\0"
    "stTrainHandOverCancellationPkt\0"
    "stTrnHndOvrCnclPkt\0"
    "SlotInsertDBS2STrainLengthInformationReq\0"
    "stTrainLengthInfoPkt\0stTrnLenInfoPkt\0"
    "SlotInsertDBS2SLengthInformationAck\0"
    "stTrainLengthInfoAck\0stTrnLenInfoAck\0"
    "SlotInsertDBS2STSLRouteRequest\0"
    "stTSLReqPkt\0stTSLRouteReq\0"
    "SlotInsertDBS2STSLAuthorityInformationPkt\0"
    "stTSLInformationPkt\0stTSLInfoPkt\0"
    "SlotInsertDBS2SFieldElementsStatusReq\0"
    "stFieldElementsStatusReqPkt\0"
    "stFldElementStsReq\0"
    "SlotInsertDBS2STrainHandoverCancellationAck\0"
    "stTrainHandOverCancellationAckPkt\0"
    "stTrnHndOvrCnclAck\0SlotInsertDBLocoRSSIMessage\0"
    "stLocoRSSIMsg\0stLocoRSSI\0"
    "SlotInsertDBStationRSSIMessage\0"
    "stStationRSSIMsg\0stStnRSSI\0"
    "SlotInsertDBStatioKavachSysSts\0"
    "stStationaryKavachSysInfo\0stStnKavchSysSts\0"
    "SlotInsertDBOnBoardEventMsg\0"
    "stOnboardKavachEventMsg\0stOnBoardEvntMsg\0"
    "SlotInsertDBOnBoardBrakeEventMsg\0"
    "stOnboardKavachBrakeEventMsg\0"
    "stOnBoardBrakeEvntMsg\0"
    "SlotInsertDBOnboardBOKSHealthMsg\0"
    "stOnboardKavachBOKSHealthMsg\0"
    "stOnBoardSysHealth\0SlotInsertDBFieldInputStatus\0"
    "usRelayCnt\0byArrRelayImage\0"
    "SlotInsertDBFieldInputEventData\0"
    "stFieldEventData\0stFldEvntData\0"
    "SlotInserttoDBFieldStatus\0strFieldId\0"
    "ucStatus\0SlotInsertRemoteUser\0strPwd\0"
    "SlotFetchRemoteUsers\0SlotDeleteRemoteUser\0"
    "strUserID\0SlotUpdateRemoteUser"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nmsDBQuerys[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      60,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    4,  374,    2, 0x06,    1 /* Public */,
       9,    4,  383,    2, 0x06,    6 /* Public */,
      10,    4,  392,    2, 0x06,   11 /* Public */,
      11,    4,  401,    2, 0x06,   16 /* Public */,
      12,    4,  410,    2, 0x06,   21 /* Public */,
      13,    4,  419,    2, 0x06,   26 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      15,    3,  428,    2, 0x0a,   31 /* Public */,
      19,    0,  435,    2, 0x0a,   35 /* Public */,
      20,    1,  436,    2, 0x0a,   36 /* Public */,
      21,    3,  439,    2, 0x0a,   38 /* Public */,
      21,    1,  446,    2, 0x0a,   42 /* Public */,
      26,    3,  449,    2, 0x0a,   44 /* Public */,
      31,    3,  456,    2, 0x0a,   48 /* Public */,
      34,    0,  463,    2, 0x0a,   52 /* Public */,
      35,    0,  464,    2, 0x0a,   53 /* Public */,
      36,    0,  465,    2, 0x0a,   54 /* Public */,
      37,    5,  466,    2, 0x0a,   55 /* Public */,
      45,    5,  477,    2, 0x0a,   61 /* Public */,
      47,    4,  488,    2, 0x0a,   67 /* Public */,
      49,    4,  497,    2, 0x0a,   72 /* Public */,
      52,   23,  506,    2, 0x0a,   77 /* Public */,
      77,   31,  553,    2, 0x0a,  101 /* Public */,
      90,   16,  616,    2, 0x0a,  133 /* Public */,
     102,    9,  649,    2, 0x0a,  150 /* Public */,
     104,    1,  668,    2, 0x0a,  160 /* Public */,
     107,    1,  671,    2, 0x0a,  162 /* Public */,
     110,    1,  674,    2, 0x0a,  164 /* Public */,
     113,    1,  677,    2, 0x0a,  166 /* Public */,
     116,    1,  680,    2, 0x0a,  168 /* Public */,
     119,    1,  683,    2, 0x0a,  170 /* Public */,
     122,    1,  686,    2, 0x0a,  172 /* Public */,
     125,    1,  689,    2, 0x0a,  174 /* Public */,
     128,    2,  692,    2, 0x0a,  176 /* Public */,
     132,    4,  697,    2, 0x0a,  179 /* Public */,
     138,    4,  706,    2, 0x0a,  184 /* Public */,
     141,    2,  715,    2, 0x0a,  189 /* Public */,
     146,    2,  720,    2, 0x0a,  192 /* Public */,
     149,    2,  725,    2, 0x0a,  195 /* Public */,
     152,    2,  730,    2, 0x0a,  198 /* Public */,
     155,    2,  735,    2, 0x0a,  201 /* Public */,
     158,    2,  740,    2, 0x0a,  204 /* Public */,
     161,    2,  745,    2, 0x0a,  207 /* Public */,
     164,    2,  750,    2, 0x0a,  210 /* Public */,
     167,    2,  755,    2, 0x0a,  213 /* Public */,
     170,    2,  760,    2, 0x0a,  216 /* Public */,
     173,    2,  765,    2, 0x0a,  219 /* Public */,
     176,    2,  770,    2, 0x0a,  222 /* Public */,
     179,    1,  775,    2, 0x0a,  225 /* Public */,
     182,    1,  778,    2, 0x0a,  227 /* Public */,
     185,    1,  781,    2, 0x0a,  229 /* Public */,
     188,    1,  784,    2, 0x0a,  231 /* Public */,
     191,    1,  787,    2, 0x0a,  233 /* Public */,
     194,    1,  790,    2, 0x0a,  235 /* Public */,
     197,    4,  793,    2, 0x0a,  237 /* Public */,
     200,    1,  802,    2, 0x0a,  242 /* Public */,
     203,    2,  805,    2, 0x0a,  244 /* Public */,
     206,    4,  810,    2, 0x0a,  247 /* Public */,
     208,    0,  819,    2, 0x0a,  252 /* Public */,
     209,    1,  820,    2, 0x0a,  253 /* Public */,
     211,    1,  823,    2, 0x0a,  255 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::QStringList, QMetaType::QStringList,    4,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::QStringList, QMetaType::QStringList,    4,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::QStringList, QMetaType::QStringList,    4,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::QStringList, QMetaType::QStringList,    4,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::QStringList, QMetaType::QStringList,    4,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::QStringList, 0x80000000 | 14,    4,    6,    7,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   16,   17,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   22,   17,   23,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 27, QMetaType::QString, QMetaType::QString,   28,   29,   30,
    QMetaType::Void, 0x80000000 | 32, QMetaType::QString, QMetaType::QString,   33,   29,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 40, QMetaType::QString, 0x80000000 | 43,   38,   39,   41,   42,   44,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 5, QMetaType::QString, 0x80000000 | 43,   38,   39,   46,   42,   44,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 40, QMetaType::QString,   38,   39,   41,   48,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 5, QMetaType::QString,   38,   39,   50,   51,
    QMetaType::Void, 0x80000000 | 53, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 43,   54,   55,   56,   57,   58,   59,   60,   61,   62,   63,   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,
    QMetaType::Void, 0x80000000 | 53, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, QMetaType::QString, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 43,   54,   55,   56,   57,   58,   59,   60,   78,   79,   80,   61,   62,   63,   64,   65,   67,   81,   82,   68,   83,   84,   85,   86,   87,   88,   89,   72,   73,   74,   75,   76,
    QMetaType::Void, 0x80000000 | 53, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43,   54,   55,   56,   57,   91,   92,   93,   94,   95,   96,   97,   98,   99,  100,  101,   76,
    QMetaType::Void, 0x80000000 | 53, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 43,   54,   55,   56,   57,   91,   92,   93,  103,   76,
    QMetaType::Void, 0x80000000 | 105,  106,
    QMetaType::Void, 0x80000000 | 108,  109,
    QMetaType::Void, 0x80000000 | 111,  112,
    QMetaType::Void, 0x80000000 | 114,  115,
    QMetaType::Void, 0x80000000 | 117,  118,
    QMetaType::Void, 0x80000000 | 120,  121,
    QMetaType::Void, 0x80000000 | 123,  124,
    QMetaType::Void, 0x80000000 | 126,  127,
    QMetaType::ULongLong, 0x80000000 | 53, 0x80000000 | 130,  129,  131,
    QMetaType::Void, 0x80000000 | 133, QMetaType::QStringList, QMetaType::QStringList, 0x80000000 | 43,  134,  135,  136,  137,
    QMetaType::Void, 0x80000000 | 139, QMetaType::QString, QMetaType::QString, 0x80000000 | 43,  140,  135,  136,  137,
    QMetaType::Void, 0x80000000 | 142, 0x80000000 | 144,  143,  145,
    QMetaType::Void, 0x80000000 | 142, 0x80000000 | 147,  143,  148,
    QMetaType::Void, 0x80000000 | 142, 0x80000000 | 150,  143,  151,
    QMetaType::Void, 0x80000000 | 142, 0x80000000 | 153,  143,  154,
    QMetaType::Void, 0x80000000 | 142, 0x80000000 | 156,  143,  157,
    QMetaType::Void, 0x80000000 | 142, 0x80000000 | 159,  143,  160,
    QMetaType::Void, 0x80000000 | 142, 0x80000000 | 162,  143,  163,
    QMetaType::Void, 0x80000000 | 142, 0x80000000 | 165,  143,  166,
    QMetaType::Void, 0x80000000 | 142, 0x80000000 | 168,  143,  169,
    QMetaType::Void, 0x80000000 | 142, 0x80000000 | 171,  143,  172,
    QMetaType::Void, 0x80000000 | 142, 0x80000000 | 174,  143,  175,
    QMetaType::Void, 0x80000000 | 142, 0x80000000 | 177,  143,  178,
    QMetaType::Void, 0x80000000 | 180,  181,
    QMetaType::Void, 0x80000000 | 183,  184,
    QMetaType::Void, 0x80000000 | 186,  187,
    QMetaType::Void, 0x80000000 | 189,  190,
    QMetaType::Void, 0x80000000 | 192,  193,
    QMetaType::Void, 0x80000000 | 195,  196,
    QMetaType::Void, 0x80000000 | 142, 0x80000000 | 5, QMetaType::QByteArray, 0x80000000 | 43,  143,  198,  199,   76,
    QMetaType::Void, 0x80000000 | 201,  202,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3,  204,  205,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   22,   16,  207,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  210,
    QMetaType::Void, 0x80000000 | 24,   25,

       0        // eod
};

void nmsDBQuerys::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<nmsDBQuerys *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SigDBSMSnumbersResults((*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[4]))); break;
        case 1: _t->SigDBRemoteUserResults((*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[4]))); break;
        case 2: _t->SigDBStationInfo((*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[4]))); break;
        case 3: _t->SigDBLocoInfo((*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[4]))); break;
        case 4: _t->SigDBfaultmsgInfo((*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[4]))); break;
        case 5: _t->SigDBSMSFaultsinfo((*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QList<QStringList>>>(_a[4]))); break;
        case 6: _t->SlotInsertSMSNumbers((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 7: _t->SlotFetchSMSNumbers(); break;
        case 8: _t->SlotDeleteSMSNumber((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->SlotUpdateSMSNumber((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 10: _t->SlotUpdateSMSNumber((*reinterpret_cast< std::add_pointer_t<QList<QList<QString>>>>(_a[1]))); break;
        case 11: _t->SlotFaultPktInserttoDB((*reinterpret_cast< std::add_pointer_t<stKavachtoNMS*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 12: _t->SlotStnFaultPktInserttoDB((*reinterpret_cast< std::add_pointer_t<stStationFaults*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 13: _t->SlotStationInfo(); break;
        case 14: _t->SlotLocoInfo(); break;
        case 15: _t->SlotPrvPromptInfo(); break;
        case 16: _t->SlotFaultMsginserttoDB((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<uint16_t>>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[5]))); break;
        case 17: _t->SlotStnFaultMsginserttoDB((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[5]))); break;
        case 18: _t->SlotSMSFaultMsginserttoDB((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<uint16_t>>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 19: _t->SlotSMSStnFaultMsginserttoDB((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 20: _t->SlotAccessReqInsertintoDB((*reinterpret_cast< std::add_pointer_t<stAccessRequestPkt>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[13])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[14])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[15])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[16])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[17])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[18])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[19])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[20])),(*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[21])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[22])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[23]))); break;
        case 21: _t->SlotLocoRegularInsertintoDB((*reinterpret_cast< std::add_pointer_t<stAccessRequestPkt>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[13])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[14])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[15])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[16])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[17])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[18])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[19])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[20])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[21])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[22])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[23])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[24])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[25])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[26])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[27])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[28])),(*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[29])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[30])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[31]))); break;
        case 22: _t->SlotAccessAuthorityPktInsertintoDB((*reinterpret_cast< std::add_pointer_t<stAccessRequestPkt>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[13])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[14])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[15])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[16]))); break;
        case 23: _t->SlotAdditionalEmergencyPktInsertintoDB((*reinterpret_cast< std::add_pointer_t<stAccessRequestPkt>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[9]))); break;
        case 24: _t->SlotInsertDBStnRegMASubPkt((*reinterpret_cast< std::add_pointer_t<MovementAuthorityPkt>>(_a[1]))); break;
        case 25: _t->SlotInsertDBStnRegSSPSubPkt((*reinterpret_cast< std::add_pointer_t<StaticSpeedProfilePkt>>(_a[1]))); break;
        case 26: _t->SlotInsertDBStnRegGradientSubPkt((*reinterpret_cast< std::add_pointer_t<GradientProfilePkt>>(_a[1]))); break;
        case 27: _t->SlotInsertDBStnRegLCGateSubPkt((*reinterpret_cast< std::add_pointer_t<LCGateProfilePkt>>(_a[1]))); break;
        case 28: _t->SlotInsertDBStnRegTurnoutSpeedSubPkt((*reinterpret_cast< std::add_pointer_t<TurnoutSpeedProfilePkt>>(_a[1]))); break;
        case 29: _t->SlotInsertDBStnRegTagLinkingInfoSubPkt((*reinterpret_cast< std::add_pointer_t<TagLinkingInfoPkt>>(_a[1]))); break;
        case 30: _t->SlotInsertDBStnRegTrackCondDataSubPkt((*reinterpret_cast< std::add_pointer_t<TrackConditionPkt>>(_a[1]))); break;
        case 31: _t->SlotInsertDBStnRegTSRSubPkt((*reinterpret_cast< std::add_pointer_t<TempSpeedRestrictionPkt>>(_a[1]))); break;
        case 32: { quint64 _r = _t->SlotInsertDBStationRegHeader((*reinterpret_cast< std::add_pointer_t<stAccessRequestPkt>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<StationRegularHeader>>(_a[2])));
            if (_a[0]) *reinterpret_cast< quint64*>(_a[0]) = std::move(_r); }  break;
        case 33: _t->SlotInsertDBStationhealthPkt((*reinterpret_cast< std::add_pointer_t<stStationHealthPkt>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4]))); break;
        case 34: _t->SlotInsertDBOnBoardhealthPkt((*reinterpret_cast< std::add_pointer_t<stOnBoardHealthPkt>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4]))); break;
        case 35: _t->SlotInsertDBS2SPDIVerCmd((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stPDIVerCheckCmdPkt>>(_a[2]))); break;
        case 36: _t->SlotInsertDBS2SPDIVerMsg((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stPDIVerCheckMsgPkt>>(_a[2]))); break;
        case 37: _t->SlotInsertDBS2SHeartBeat((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stHeartBeatPkt>>(_a[2]))); break;
        case 38: _t->SlotInsertDBS2STrainHandOverReq((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTrainHandOverReqPkt>>(_a[2]))); break;
        case 39: _t->SlotInsertDBS2STrainTakenOverMsg((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTrainTakenOverPkt>>(_a[2]))); break;
        case 40: _t->SlotInsertDBS2STrainHandOverCancellationReq((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTrainHandOverCancellationPkt>>(_a[2]))); break;
        case 41: _t->SlotInsertDBS2STrainLengthInformationReq((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTrainLengthInfoPkt>>(_a[2]))); break;
        case 42: _t->SlotInsertDBS2SLengthInformationAck((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTrainLengthInfoAck>>(_a[2]))); break;
        case 43: _t->SlotInsertDBS2STSLRouteRequest((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTSLReqPkt>>(_a[2]))); break;
        case 44: _t->SlotInsertDBS2STSLAuthorityInformationPkt((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTSLInformationPkt>>(_a[2]))); break;
        case 45: _t->SlotInsertDBS2SFieldElementsStatusReq((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stFieldElementsStatusReqPkt>>(_a[2]))); break;
        case 46: _t->SlotInsertDBS2STrainHandoverCancellationAck((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTrainHandOverCancellationAckPkt>>(_a[2]))); break;
        case 47: _t->SlotInsertDBLocoRSSIMessage((*reinterpret_cast< std::add_pointer_t<stLocoRSSIMsg>>(_a[1]))); break;
        case 48: _t->SlotInsertDBStationRSSIMessage((*reinterpret_cast< std::add_pointer_t<stStationRSSIMsg>>(_a[1]))); break;
        case 49: _t->SlotInsertDBStatioKavachSysSts((*reinterpret_cast< std::add_pointer_t<stStationaryKavachSysInfo>>(_a[1]))); break;
        case 50: _t->SlotInsertDBOnBoardEventMsg((*reinterpret_cast< std::add_pointer_t<stOnboardKavachEventMsg>>(_a[1]))); break;
        case 51: _t->SlotInsertDBOnBoardBrakeEventMsg((*reinterpret_cast< std::add_pointer_t<stOnboardKavachBrakeEventMsg>>(_a[1]))); break;
        case 52: _t->SlotInsertDBOnboardBOKSHealthMsg((*reinterpret_cast< std::add_pointer_t<stOnboardKavachBOKSHealthMsg>>(_a[1]))); break;
        case 53: _t->SlotInsertDBFieldInputStatus((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4]))); break;
        case 54: _t->SlotInsertDBFieldInputEventData((*reinterpret_cast< std::add_pointer_t<stFieldEventData>>(_a[1]))); break;
        case 55: _t->SlotInserttoDBFieldStatus((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[2]))); break;
        case 56: _t->SlotInsertRemoteUser((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 57: _t->SlotFetchRemoteUsers(); break;
        case 58: _t->SlotDeleteRemoteUser((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 59: _t->SlotUpdateRemoteUser((*reinterpret_cast< std::add_pointer_t<QList<QList<QString>>>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 3:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QStringList> >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QList<QString>> >(); break;
            }
            break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stAccessRequestPkt >(); break;
            }
            break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stAccessRequestPkt >(); break;
            }
            break;
        case 22:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stAccessRequestPkt >(); break;
            }
            break;
        case 23:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stAccessRequestPkt >(); break;
            }
            break;
        case 32:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stAccessRequestPkt >(); break;
            }
            break;
        case 33:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stStationHealthPkt >(); break;
            }
            break;
        case 34:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stOnBoardHealthPkt >(); break;
            }
            break;
        case 35:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPDIVerCheckCmdPkt >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            }
            break;
        case 36:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPDIVerCheckMsgPkt >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            }
            break;
        case 37:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stHeartBeatPkt >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            }
            break;
        case 38:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTrainHandOverReqPkt >(); break;
            }
            break;
        case 39:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTrainTakenOverPkt >(); break;
            }
            break;
        case 40:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTrainHandOverCancellationPkt >(); break;
            }
            break;
        case 41:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTrainLengthInfoPkt >(); break;
            }
            break;
        case 42:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTrainLengthInfoAck >(); break;
            }
            break;
        case 43:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTSLReqPkt >(); break;
            }
            break;
        case 44:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTSLInformationPkt >(); break;
            }
            break;
        case 45:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stFieldElementsStatusReqPkt >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            }
            break;
        case 46:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTrainHandOverCancellationAckPkt >(); break;
            }
            break;
        case 47:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stLocoRSSIMsg >(); break;
            }
            break;
        case 48:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stStationRSSIMsg >(); break;
            }
            break;
        case 49:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stStationaryKavachSysInfo >(); break;
            }
            break;
        case 50:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stOnboardKavachEventMsg >(); break;
            }
            break;
        case 52:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stOnboardKavachBOKSHealthMsg >(); break;
            }
            break;
        case 53:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            }
            break;
        case 54:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stFieldEventData >(); break;
            }
            break;
        case 59:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QList<QString>> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (nmsDBQuerys::*)(uint8_t , uint16_t , QStringList , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsDBQuerys::SigDBSMSnumbersResults)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (nmsDBQuerys::*)(uint8_t , uint16_t , QStringList , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsDBQuerys::SigDBRemoteUserResults)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (nmsDBQuerys::*)(uint8_t , uint16_t , QStringList , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsDBQuerys::SigDBStationInfo)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (nmsDBQuerys::*)(uint8_t , uint16_t , QStringList , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsDBQuerys::SigDBLocoInfo)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (nmsDBQuerys::*)(uint8_t , uint16_t , QStringList , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsDBQuerys::SigDBfaultmsgInfo)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (nmsDBQuerys::*)(uint8_t , uint16_t , QStringList , QList<QStringList> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsDBQuerys::SigDBSMSFaultsinfo)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject nmsDBQuerys::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_nmsDBQuerys.offsetsAndSize,
    qt_meta_data_nmsDBQuerys,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_nmsDBQuerys_t
, QtPrivate::TypeAndForceComplete<nmsDBQuerys, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QStringList>, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QList<QString>>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stKavachtoNMS *, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stStationFaults *, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QList<uint16_t>, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QList<uint16_t>, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<MovementAuthorityPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<StaticSpeedProfilePkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<GradientProfilePkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<LCGateProfilePkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<TurnoutSpeedProfilePkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<TagLinkingInfoPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<TrackConditionPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<TempSpeedRestrictionPkt, std::false_type>, QtPrivate::TypeAndForceComplete<quint64, std::false_type>, QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>, QtPrivate::TypeAndForceComplete<StationRegularHeader, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stStationHealthPkt, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stOnBoardHealthPkt, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stPDIVerCheckCmdPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stPDIVerCheckMsgPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stHeartBeatPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainHandOverReqPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainTakenOverPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainHandOverCancellationPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainLengthInfoPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainLengthInfoAck, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTSLReqPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTSLInformationPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stFieldElementsStatusReqPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainHandOverCancellationAckPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stLocoRSSIMsg, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stStationRSSIMsg, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stStationaryKavachSysInfo, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stOnboardKavachEventMsg, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stOnboardKavachBrakeEventMsg, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stOnboardKavachBOKSHealthMsg, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stFieldEventData, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QList<QString>>, std::false_type>


>,
    nullptr
} };


const QMetaObject *nmsDBQuerys::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nmsDBQuerys::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_nmsDBQuerys.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int nmsDBQuerys::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 60)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 60;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 60)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 60;
    }
    return _id;
}

// SIGNAL 0
void nmsDBQuerys::SigDBSMSnumbersResults(uint8_t _t1, uint16_t _t2, QStringList _t3, QStringList _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void nmsDBQuerys::SigDBRemoteUserResults(uint8_t _t1, uint16_t _t2, QStringList _t3, QStringList _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void nmsDBQuerys::SigDBStationInfo(uint8_t _t1, uint16_t _t2, QStringList _t3, QStringList _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void nmsDBQuerys::SigDBLocoInfo(uint8_t _t1, uint16_t _t2, QStringList _t3, QStringList _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void nmsDBQuerys::SigDBfaultmsgInfo(uint8_t _t1, uint16_t _t2, QStringList _t3, QStringList _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void nmsDBQuerys::SigDBSMSFaultsinfo(uint8_t _t1, uint16_t _t2, QStringList _t3, QList<QStringList> _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
