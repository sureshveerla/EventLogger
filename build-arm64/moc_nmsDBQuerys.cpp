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
    const uint offsetsAndSize[428];
    char stringdata0[3854];
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
QT_MOC_LITERAL(506, 14), // "strLstModuleID"
QT_MOC_LITERAL(521, 18), // "strLstFaultCodeTyp"
QT_MOC_LITERAL(540, 15), // "SlotStationInfo"
QT_MOC_LITERAL(556, 12), // "SlotLocoInfo"
QT_MOC_LITERAL(569, 17), // "SlotPrvPromptInfo"
QT_MOC_LITERAL(587, 22), // "SlotFaultMsginserttoDB"
QT_MOC_LITERAL(610, 10), // "strMsgType"
QT_MOC_LITERAL(621, 12), // "strTimestamp"
QT_MOC_LITERAL(634, 15), // "QList<uint16_t>"
QT_MOC_LITERAL(650, 14), // "faultByteArray"
QT_MOC_LITERAL(665, 10), // "strFirmNam"
QT_MOC_LITERAL(676, 8), // "uint32_t"
QT_MOC_LITERAL(685, 4), // "uiID"
QT_MOC_LITERAL(690, 25), // "SlotStnFaultMsginserttoDB"
QT_MOC_LITERAL(716, 11), // "usFaultCode"
QT_MOC_LITERAL(728, 25), // "SlotSMSFaultMsginserttoDB"
QT_MOC_LITERAL(754, 12), // "strFirmnamID"
QT_MOC_LITERAL(767, 28), // "SlotSMSStnFaultMsginserttoDB"
QT_MOC_LITERAL(796, 11), // "usFaultCOde"
QT_MOC_LITERAL(808, 12), // "strFirmNamID"
QT_MOC_LITERAL(821, 25), // "SlotAccessReqInsertintoDB"
QT_MOC_LITERAL(847, 18), // "stAccessRequestPkt"
QT_MOC_LITERAL(866, 8), // "stheader"
QT_MOC_LITERAL(875, 9), // "uiPktType"
QT_MOC_LITERAL(885, 8), // "uiPktLen"
QT_MOC_LITERAL(894, 7), // "uiFrmNo"
QT_MOC_LITERAL(902, 11), // "uiSrcLocoID"
QT_MOC_LITERAL(914, 12), // "uiSrcLocoVer"
QT_MOC_LITERAL(927, 13), // "uiAbsLoco_Loc"
QT_MOC_LITERAL(941, 10), // "uiTrainLen"
QT_MOC_LITERAL(952, 10), // "uiTrainSpd"
QT_MOC_LITERAL(963, 11), // "uiMovMntDir"
QT_MOC_LITERAL(975, 14), // "uiEmergencySts"
QT_MOC_LITERAL(990, 10), // "uiLocoMode"
QT_MOC_LITERAL(1001, 10), // "uiApprStID"
QT_MOC_LITERAL(1012, 13), // "uiLastRfidTag"
QT_MOC_LITERAL(1026, 7), // "uitinNo"
QT_MOC_LITERAL(1034, 11), // "uiLongitude"
QT_MOC_LITERAL(1046, 10), // "uiLatitude"
QT_MOC_LITERAL(1057, 13), // "uiLocoRandmrl"
QT_MOC_LITERAL(1071, 9), // "uiMACCode"
QT_MOC_LITERAL(1081, 8), // "uiPktCRC"
QT_MOC_LITERAL(1090, 10), // "ucMASecCnt"
QT_MOC_LITERAL(1101, 9), // "usRouteID"
QT_MOC_LITERAL(1111, 5), // "uiCRC"
QT_MOC_LITERAL(1117, 27), // "SlotLocoRegularInsertintoDB"
QT_MOC_LITERAL(1145, 11), // "uidoubtover"
QT_MOC_LITERAL(1157, 12), // "uidoubtunder"
QT_MOC_LITERAL(1170, 10), // "uitrainint"
QT_MOC_LITERAL(1181, 8), // "uiTagDup"
QT_MOC_LITERAL(1190, 13), // "uitagLinkInfo"
QT_MOC_LITERAL(1204, 10), // "uiBrkApply"
QT_MOC_LITERAL(1215, 12), // "uinewMAReply"
QT_MOC_LITERAL(1228, 15), // "uiLastRefProfNo"
QT_MOC_LITERAL(1244, 7), // "uiSigOV"
QT_MOC_LITERAL(1252, 9), // "uiInfoAck"
QT_MOC_LITERAL(1262, 7), // "uiSpare"
QT_MOC_LITERAL(1270, 14), // "strLocoHlthSts"
QT_MOC_LITERAL(1285, 34), // "SlotAccessAuthorityPktInserti..."
QT_MOC_LITERAL(1320, 17), // "uiSrcStnILCIBS_ID"
QT_MOC_LITERAL(1338, 18), // "uiSRCStnILCIBS_ver"
QT_MOC_LITERAL(1357, 15), // "uiStnILCIBS_Loc"
QT_MOC_LITERAL(1373, 13), // "uiDestLoco_ID"
QT_MOC_LITERAL(1387, 16), // "uiAlotUpLnk_Freq"
QT_MOC_LITERAL(1404, 16), // "uiAlotDnLnk_Freq"
QT_MOC_LITERAL(1421, 20), // "uiAlotTDMA_Timeslots"
QT_MOC_LITERAL(1442, 14), // "uiStnRndNum_RS"
QT_MOC_LITERAL(1457, 9), // "uiStnTDMA"
QT_MOC_LITERAL(1467, 10), // "uiMAC_Code"
QT_MOC_LITERAL(1478, 8), // "uiPktCrc"
QT_MOC_LITERAL(1487, 38), // "SlotAdditionalEmergencyPktIns..."
QT_MOC_LITERAL(1526, 12), // "uiGenSoSCall"
QT_MOC_LITERAL(1539, 26), // "SlotInsertDBStnRegMASubPkt"
QT_MOC_LITERAL(1566, 20), // "MovementAuthorityPkt"
QT_MOC_LITERAL(1587, 7), // "stMAPkt"
QT_MOC_LITERAL(1595, 27), // "SlotInsertDBStnRegSSPSubPkt"
QT_MOC_LITERAL(1623, 21), // "StaticSpeedProfilePkt"
QT_MOC_LITERAL(1645, 8), // "stSSPPkt"
QT_MOC_LITERAL(1654, 32), // "SlotInsertDBStnRegGradientSubPkt"
QT_MOC_LITERAL(1687, 18), // "GradientProfilePkt"
QT_MOC_LITERAL(1706, 13), // "stGradprofPkt"
QT_MOC_LITERAL(1720, 30), // "SlotInsertDBStnRegLCGateSubPkt"
QT_MOC_LITERAL(1751, 16), // "LCGateProfilePkt"
QT_MOC_LITERAL(1768, 11), // "stLCGatePkt"
QT_MOC_LITERAL(1780, 36), // "SlotInsertDBStnRegTurnoutSpee..."
QT_MOC_LITERAL(1817, 22), // "TurnoutSpeedProfilePkt"
QT_MOC_LITERAL(1840, 8), // "stTSPPkt"
QT_MOC_LITERAL(1849, 38), // "SlotInsertDBStnRegTagLinkingI..."
QT_MOC_LITERAL(1888, 17), // "TagLinkingInfoPkt"
QT_MOC_LITERAL(1906, 15), // "stTagLinkInfPkt"
QT_MOC_LITERAL(1922, 37), // "SlotInsertDBStnRegTrackCondDa..."
QT_MOC_LITERAL(1960, 17), // "TrackConditionPkt"
QT_MOC_LITERAL(1978, 18), // "stTrackCondDataPkt"
QT_MOC_LITERAL(1997, 27), // "SlotInsertDBStnRegTSRSubPkt"
QT_MOC_LITERAL(2025, 23), // "TempSpeedRestrictionPkt"
QT_MOC_LITERAL(2049, 8), // "stTSRPkt"
QT_MOC_LITERAL(2058, 28), // "SlotInsertDBStationRegHeader"
QT_MOC_LITERAL(2087, 8), // "stHeader"
QT_MOC_LITERAL(2096, 20), // "StationRegularHeader"
QT_MOC_LITERAL(2117, 13), // "stStnRglrHPkt"
QT_MOC_LITERAL(2131, 28), // "SlotInsertDBStationhealthPkt"
QT_MOC_LITERAL(2160, 18), // "stStationHealthPkt"
QT_MOC_LITERAL(2179, 12), // "stStnHlthPkt"
QT_MOC_LITERAL(2192, 9), // "strEvntID"
QT_MOC_LITERAL(2202, 11), // "strEvntData"
QT_MOC_LITERAL(2214, 5), // "uiCrc"
QT_MOC_LITERAL(2220, 28), // "SlotInsertDBOnBoardhealthPkt"
QT_MOC_LITERAL(2249, 18), // "stOnBoardHealthPkt"
QT_MOC_LITERAL(2268, 14), // "stOnBrdHlthPkt"
QT_MOC_LITERAL(2283, 24), // "SlotInsertDBS2SPDIVerCmd"
QT_MOC_LITERAL(2308, 14), // "stPacketHeader"
QT_MOC_LITERAL(2323, 8), // "stPktHdr"
QT_MOC_LITERAL(2332, 19), // "stPDIVerCheckCmdPkt"
QT_MOC_LITERAL(2352, 11), // "stPDIVerCmd"
QT_MOC_LITERAL(2364, 24), // "SlotInsertDBS2SPDIVerMsg"
QT_MOC_LITERAL(2389, 19), // "stPDIVerCheckMsgPkt"
QT_MOC_LITERAL(2409, 11), // "stPDIVerMsg"
QT_MOC_LITERAL(2421, 24), // "SlotInsertDBS2SHeartBeat"
QT_MOC_LITERAL(2446, 14), // "stHeartBeatPkt"
QT_MOC_LITERAL(2461, 11), // "stHeartBeat"
QT_MOC_LITERAL(2473, 31), // "SlotInsertDBS2STrainHandOverReq"
QT_MOC_LITERAL(2505, 21), // "stTrainHandOverReqPkt"
QT_MOC_LITERAL(2527, 14), // "stTrnHndOveReq"
QT_MOC_LITERAL(2542, 32), // "SlotInsertDBS2STrainTakenOverMsg"
QT_MOC_LITERAL(2575, 19), // "stTrainTakenOverPkt"
QT_MOC_LITERAL(2595, 14), // "stTrnTknOveMsg"
QT_MOC_LITERAL(2610, 43), // "SlotInsertDBS2STrainHandOverC..."
QT_MOC_LITERAL(2654, 30), // "stTrainHandOverCancellationPkt"
QT_MOC_LITERAL(2685, 18), // "stTrnHndOvrCnclPkt"
QT_MOC_LITERAL(2704, 40), // "SlotInsertDBS2STrainLengthInf..."
QT_MOC_LITERAL(2745, 20), // "stTrainLengthInfoPkt"
QT_MOC_LITERAL(2766, 15), // "stTrnLenInfoPkt"
QT_MOC_LITERAL(2782, 35), // "SlotInsertDBS2SLengthInformat..."
QT_MOC_LITERAL(2818, 20), // "stTrainLengthInfoAck"
QT_MOC_LITERAL(2839, 15), // "stTrnLenInfoAck"
QT_MOC_LITERAL(2855, 30), // "SlotInsertDBS2STSLRouteRequest"
QT_MOC_LITERAL(2886, 11), // "stTSLReqPkt"
QT_MOC_LITERAL(2898, 13), // "stTSLRouteReq"
QT_MOC_LITERAL(2912, 41), // "SlotInsertDBS2STSLAuthorityIn..."
QT_MOC_LITERAL(2954, 19), // "stTSLInformationPkt"
QT_MOC_LITERAL(2974, 12), // "stTSLInfoPkt"
QT_MOC_LITERAL(2987, 37), // "SlotInsertDBS2SFieldElementsS..."
QT_MOC_LITERAL(3025, 27), // "stFieldElementsStatusReqPkt"
QT_MOC_LITERAL(3053, 18), // "stFldElementStsReq"
QT_MOC_LITERAL(3072, 43), // "SlotInsertDBS2STrainHandoverC..."
QT_MOC_LITERAL(3116, 33), // "stTrainHandOverCancellationAc..."
QT_MOC_LITERAL(3150, 18), // "stTrnHndOvrCnclAck"
QT_MOC_LITERAL(3169, 27), // "SlotInsertDBLocoRSSIMessage"
QT_MOC_LITERAL(3197, 13), // "stLocoRSSIMsg"
QT_MOC_LITERAL(3211, 10), // "stLocoRSSI"
QT_MOC_LITERAL(3222, 30), // "SlotInsertDBStationRSSIMessage"
QT_MOC_LITERAL(3253, 16), // "stStationRSSIMsg"
QT_MOC_LITERAL(3270, 9), // "stStnRSSI"
QT_MOC_LITERAL(3280, 30), // "SlotInsertDBStatioKavachSysSts"
QT_MOC_LITERAL(3311, 25), // "stStationaryKavachSysInfo"
QT_MOC_LITERAL(3337, 16), // "stStnKavchSysSts"
QT_MOC_LITERAL(3354, 27), // "SlotInsertDBOnBoardEventMsg"
QT_MOC_LITERAL(3382, 23), // "stOnboardKavachEventMsg"
QT_MOC_LITERAL(3406, 16), // "stOnBoardEvntMsg"
QT_MOC_LITERAL(3423, 32), // "SlotInsertDBOnBoardBrakeEventMsg"
QT_MOC_LITERAL(3456, 28), // "stOnboardKavachBrakeEventMsg"
QT_MOC_LITERAL(3485, 21), // "stOnBoardBrakeEvntMsg"
QT_MOC_LITERAL(3507, 32), // "SlotInsertDBOnboardBOKSHealthMsg"
QT_MOC_LITERAL(3540, 28), // "stOnboardKavachBOKSHealthMsg"
QT_MOC_LITERAL(3569, 18), // "stOnBoardSysHealth"
QT_MOC_LITERAL(3588, 28), // "SlotInsertDBFieldInputStatus"
QT_MOC_LITERAL(3617, 10), // "usRelayCnt"
QT_MOC_LITERAL(3628, 15), // "byArrRelayImage"
QT_MOC_LITERAL(3644, 31), // "SlotInsertDBFieldInputEventData"
QT_MOC_LITERAL(3676, 16), // "stFieldEventData"
QT_MOC_LITERAL(3693, 13), // "stFldEvntData"
QT_MOC_LITERAL(3707, 25), // "SlotInserttoDBFieldStatus"
QT_MOC_LITERAL(3733, 10), // "strFieldId"
QT_MOC_LITERAL(3744, 8), // "ucStatus"
QT_MOC_LITERAL(3753, 20), // "SlotInsertRemoteUser"
QT_MOC_LITERAL(3774, 6), // "strPwd"
QT_MOC_LITERAL(3781, 20), // "SlotFetchRemoteUsers"
QT_MOC_LITERAL(3802, 20), // "SlotDeleteRemoteUser"
QT_MOC_LITERAL(3823, 9), // "strUserID"
QT_MOC_LITERAL(3833, 20) // "SlotUpdateRemoteUser"

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
    "pstStnFaults\0strLstModuleID\0"
    "strLstFaultCodeTyp\0SlotStationInfo\0"
    "SlotLocoInfo\0SlotPrvPromptInfo\0"
    "SlotFaultMsginserttoDB\0strMsgType\0"
    "strTimestamp\0QList<uint16_t>\0"
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
      31,    5,  456,    2, 0x0a,   48 /* Public */,
      36,    0,  467,    2, 0x0a,   54 /* Public */,
      37,    0,  468,    2, 0x0a,   55 /* Public */,
      38,    0,  469,    2, 0x0a,   56 /* Public */,
      39,    5,  470,    2, 0x0a,   57 /* Public */,
      47,    5,  481,    2, 0x0a,   63 /* Public */,
      49,    4,  492,    2, 0x0a,   69 /* Public */,
      51,    4,  501,    2, 0x0a,   74 /* Public */,
      54,   23,  510,    2, 0x0a,   79 /* Public */,
      79,   31,  557,    2, 0x0a,  103 /* Public */,
      92,   16,  620,    2, 0x0a,  135 /* Public */,
     104,    9,  653,    2, 0x0a,  152 /* Public */,
     106,    1,  672,    2, 0x0a,  162 /* Public */,
     109,    1,  675,    2, 0x0a,  164 /* Public */,
     112,    1,  678,    2, 0x0a,  166 /* Public */,
     115,    1,  681,    2, 0x0a,  168 /* Public */,
     118,    1,  684,    2, 0x0a,  170 /* Public */,
     121,    1,  687,    2, 0x0a,  172 /* Public */,
     124,    1,  690,    2, 0x0a,  174 /* Public */,
     127,    1,  693,    2, 0x0a,  176 /* Public */,
     130,    2,  696,    2, 0x0a,  178 /* Public */,
     134,    4,  701,    2, 0x0a,  181 /* Public */,
     140,    4,  710,    2, 0x0a,  186 /* Public */,
     143,    2,  719,    2, 0x0a,  191 /* Public */,
     148,    2,  724,    2, 0x0a,  194 /* Public */,
     151,    2,  729,    2, 0x0a,  197 /* Public */,
     154,    2,  734,    2, 0x0a,  200 /* Public */,
     157,    2,  739,    2, 0x0a,  203 /* Public */,
     160,    2,  744,    2, 0x0a,  206 /* Public */,
     163,    2,  749,    2, 0x0a,  209 /* Public */,
     166,    2,  754,    2, 0x0a,  212 /* Public */,
     169,    2,  759,    2, 0x0a,  215 /* Public */,
     172,    2,  764,    2, 0x0a,  218 /* Public */,
     175,    2,  769,    2, 0x0a,  221 /* Public */,
     178,    2,  774,    2, 0x0a,  224 /* Public */,
     181,    1,  779,    2, 0x0a,  227 /* Public */,
     184,    1,  782,    2, 0x0a,  229 /* Public */,
     187,    1,  785,    2, 0x0a,  231 /* Public */,
     190,    1,  788,    2, 0x0a,  233 /* Public */,
     193,    1,  791,    2, 0x0a,  235 /* Public */,
     196,    1,  794,    2, 0x0a,  237 /* Public */,
     199,    4,  797,    2, 0x0a,  239 /* Public */,
     202,    1,  806,    2, 0x0a,  244 /* Public */,
     205,    2,  809,    2, 0x0a,  246 /* Public */,
     208,    4,  814,    2, 0x0a,  249 /* Public */,
     210,    0,  823,    2, 0x0a,  254 /* Public */,
     211,    1,  824,    2, 0x0a,  255 /* Public */,
     213,    1,  827,    2, 0x0a,  257 /* Public */,

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
    QMetaType::Void, 0x80000000 | 32, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList,   33,   34,   35,   29,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 42, QMetaType::QString, 0x80000000 | 45,   40,   41,   43,   44,   46,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 5, QMetaType::QString, 0x80000000 | 45,   40,   41,   48,   44,   46,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 42, QMetaType::QString,   40,   41,   43,   50,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 5, QMetaType::QString,   40,   41,   52,   53,
    QMetaType::Void, 0x80000000 | 55, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 45,   56,   57,   58,   59,   60,   61,   62,   63,   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,
    QMetaType::Void, 0x80000000 | 55, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, QMetaType::QString, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 45,   56,   57,   58,   59,   60,   61,   62,   80,   81,   82,   63,   64,   65,   66,   67,   69,   83,   84,   70,   85,   86,   87,   88,   89,   90,   91,   74,   75,   76,   77,   78,
    QMetaType::Void, 0x80000000 | 55, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45,   56,   57,   58,   59,   93,   94,   95,   96,   97,   98,   99,  100,  101,  102,  103,   78,
    QMetaType::Void, 0x80000000 | 55, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45,   56,   57,   58,   59,   93,   94,   95,  105,   78,
    QMetaType::Void, 0x80000000 | 107,  108,
    QMetaType::Void, 0x80000000 | 110,  111,
    QMetaType::Void, 0x80000000 | 113,  114,
    QMetaType::Void, 0x80000000 | 116,  117,
    QMetaType::Void, 0x80000000 | 119,  120,
    QMetaType::Void, 0x80000000 | 122,  123,
    QMetaType::Void, 0x80000000 | 125,  126,
    QMetaType::Void, 0x80000000 | 128,  129,
    QMetaType::ULongLong, 0x80000000 | 55, 0x80000000 | 132,  131,  133,
    QMetaType::Void, 0x80000000 | 135, QMetaType::QStringList, QMetaType::QStringList, 0x80000000 | 45,  136,  137,  138,  139,
    QMetaType::Void, 0x80000000 | 141, QMetaType::QString, QMetaType::QString, 0x80000000 | 45,  142,  137,  138,  139,
    QMetaType::Void, 0x80000000 | 144, 0x80000000 | 146,  145,  147,
    QMetaType::Void, 0x80000000 | 144, 0x80000000 | 149,  145,  150,
    QMetaType::Void, 0x80000000 | 144, 0x80000000 | 152,  145,  153,
    QMetaType::Void, 0x80000000 | 144, 0x80000000 | 155,  145,  156,
    QMetaType::Void, 0x80000000 | 144, 0x80000000 | 158,  145,  159,
    QMetaType::Void, 0x80000000 | 144, 0x80000000 | 161,  145,  162,
    QMetaType::Void, 0x80000000 | 144, 0x80000000 | 164,  145,  165,
    QMetaType::Void, 0x80000000 | 144, 0x80000000 | 167,  145,  168,
    QMetaType::Void, 0x80000000 | 144, 0x80000000 | 170,  145,  171,
    QMetaType::Void, 0x80000000 | 144, 0x80000000 | 173,  145,  174,
    QMetaType::Void, 0x80000000 | 144, 0x80000000 | 176,  145,  177,
    QMetaType::Void, 0x80000000 | 144, 0x80000000 | 179,  145,  180,
    QMetaType::Void, 0x80000000 | 182,  183,
    QMetaType::Void, 0x80000000 | 185,  186,
    QMetaType::Void, 0x80000000 | 188,  189,
    QMetaType::Void, 0x80000000 | 191,  192,
    QMetaType::Void, 0x80000000 | 194,  195,
    QMetaType::Void, 0x80000000 | 197,  198,
    QMetaType::Void, 0x80000000 | 144, 0x80000000 | 5, QMetaType::QByteArray, 0x80000000 | 45,  145,  200,  201,   78,
    QMetaType::Void, 0x80000000 | 203,  204,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3,  206,  207,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   22,   16,  209,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  212,
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
        case 12: _t->SlotStnFaultPktInserttoDB((*reinterpret_cast< std::add_pointer_t<stStationFaults*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[5]))); break;
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
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QList<QString>>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stKavachtoNMS *, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stStationFaults *, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QList<uint16_t>, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QList<uint16_t>, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<MovementAuthorityPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<StaticSpeedProfilePkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<GradientProfilePkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<LCGateProfilePkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<TurnoutSpeedProfilePkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<TagLinkingInfoPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<TrackConditionPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<TempSpeedRestrictionPkt, std::false_type>, QtPrivate::TypeAndForceComplete<quint64, std::false_type>, QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>, QtPrivate::TypeAndForceComplete<StationRegularHeader, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stStationHealthPkt, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stOnBoardHealthPkt, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stPDIVerCheckCmdPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stPDIVerCheckMsgPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stHeartBeatPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainHandOverReqPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainTakenOverPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainHandOverCancellationPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainLengthInfoPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainLengthInfoAck, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTSLReqPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTSLInformationPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stFieldElementsStatusReqPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainHandOverCancellationAckPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stLocoRSSIMsg, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stStationRSSIMsg, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stStationaryKavachSysInfo, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stOnboardKavachEventMsg, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stOnboardKavachBrakeEventMsg, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stOnboardKavachBOKSHealthMsg, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stFieldEventData, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QList<QString>>, std::false_type>


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
