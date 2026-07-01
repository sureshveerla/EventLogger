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
    const uint offsetsAndSize[416];
    char stringdata0[3756];
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
QT_MOC_LITERAL(216, 22), // "SlotFaultPktInserttoDB"
QT_MOC_LITERAL(239, 14), // "stKavachtoNMS*"
QT_MOC_LITERAL(254, 14), // "pstKavachtoNMS"
QT_MOC_LITERAL(269, 13), // "strFaultsCode"
QT_MOC_LITERAL(283, 11), // "strFaultMsg"
QT_MOC_LITERAL(295, 25), // "SlotStnFaultPktInserttoDB"
QT_MOC_LITERAL(321, 16), // "stStationFaults*"
QT_MOC_LITERAL(338, 12), // "pstStnFaults"
QT_MOC_LITERAL(351, 14), // "strLstModuleID"
QT_MOC_LITERAL(366, 18), // "strLstFaultCodeTyp"
QT_MOC_LITERAL(385, 15), // "SlotStationInfo"
QT_MOC_LITERAL(401, 12), // "SlotLocoInfo"
QT_MOC_LITERAL(414, 17), // "SlotPrvPromptInfo"
QT_MOC_LITERAL(432, 22), // "SlotFaultMsginserttoDB"
QT_MOC_LITERAL(455, 10), // "strMsgType"
QT_MOC_LITERAL(466, 12), // "strTimestamp"
QT_MOC_LITERAL(479, 15), // "QList<uint16_t>"
QT_MOC_LITERAL(495, 14), // "faultByteArray"
QT_MOC_LITERAL(510, 10), // "strFirmNam"
QT_MOC_LITERAL(521, 8), // "uint32_t"
QT_MOC_LITERAL(530, 4), // "uiID"
QT_MOC_LITERAL(535, 25), // "SlotStnFaultMsginserttoDB"
QT_MOC_LITERAL(561, 11), // "usFaultCode"
QT_MOC_LITERAL(573, 25), // "SlotSMSFaultMsginserttoDB"
QT_MOC_LITERAL(599, 12), // "strFirmnamID"
QT_MOC_LITERAL(612, 28), // "SlotSMSStnFaultMsginserttoDB"
QT_MOC_LITERAL(641, 11), // "usFaultCOde"
QT_MOC_LITERAL(653, 12), // "strFirmNamID"
QT_MOC_LITERAL(666, 25), // "SlotAccessReqInsertintoDB"
QT_MOC_LITERAL(692, 18), // "stAccessRequestPkt"
QT_MOC_LITERAL(711, 8), // "stheader"
QT_MOC_LITERAL(720, 9), // "uiPktType"
QT_MOC_LITERAL(730, 8), // "uiPktLen"
QT_MOC_LITERAL(739, 7), // "uiFrmNo"
QT_MOC_LITERAL(747, 11), // "uiSrcLocoID"
QT_MOC_LITERAL(759, 12), // "uiSrcLocoVer"
QT_MOC_LITERAL(772, 13), // "uiAbsLoco_Loc"
QT_MOC_LITERAL(786, 10), // "uiTrainLen"
QT_MOC_LITERAL(797, 10), // "uiTrainSpd"
QT_MOC_LITERAL(808, 11), // "uiMovMntDir"
QT_MOC_LITERAL(820, 14), // "uiEmergencySts"
QT_MOC_LITERAL(835, 10), // "uiLocoMode"
QT_MOC_LITERAL(846, 10), // "uiApprStID"
QT_MOC_LITERAL(857, 13), // "uiLastRfidTag"
QT_MOC_LITERAL(871, 7), // "uitinNo"
QT_MOC_LITERAL(879, 11), // "uiLongitude"
QT_MOC_LITERAL(891, 10), // "uiLatitude"
QT_MOC_LITERAL(902, 13), // "uiLocoRandmrl"
QT_MOC_LITERAL(916, 9), // "uiMACCode"
QT_MOC_LITERAL(926, 8), // "uiPktCRC"
QT_MOC_LITERAL(935, 10), // "ucMASecCnt"
QT_MOC_LITERAL(946, 9), // "usRouteID"
QT_MOC_LITERAL(956, 5), // "uiCRC"
QT_MOC_LITERAL(962, 27), // "SlotLocoRegularInsertintoDB"
QT_MOC_LITERAL(990, 11), // "uidoubtover"
QT_MOC_LITERAL(1002, 12), // "uidoubtunder"
QT_MOC_LITERAL(1015, 10), // "uitrainint"
QT_MOC_LITERAL(1026, 8), // "uiTagDup"
QT_MOC_LITERAL(1035, 13), // "uitagLinkInfo"
QT_MOC_LITERAL(1049, 10), // "uiBrkApply"
QT_MOC_LITERAL(1060, 12), // "uinewMAReply"
QT_MOC_LITERAL(1073, 15), // "uiLastRefProfNo"
QT_MOC_LITERAL(1089, 7), // "uiSigOV"
QT_MOC_LITERAL(1097, 9), // "uiInfoAck"
QT_MOC_LITERAL(1107, 7), // "uiSpare"
QT_MOC_LITERAL(1115, 14), // "strLocoHlthSts"
QT_MOC_LITERAL(1130, 34), // "SlotAccessAuthorityPktInserti..."
QT_MOC_LITERAL(1165, 17), // "uiSrcStnILCIBS_ID"
QT_MOC_LITERAL(1183, 18), // "uiSRCStnILCIBS_ver"
QT_MOC_LITERAL(1202, 15), // "uiStnILCIBS_Loc"
QT_MOC_LITERAL(1218, 13), // "uiDestLoco_ID"
QT_MOC_LITERAL(1232, 16), // "uiAlotUpLnk_Freq"
QT_MOC_LITERAL(1249, 16), // "uiAlotDnLnk_Freq"
QT_MOC_LITERAL(1266, 20), // "uiAlotTDMA_Timeslots"
QT_MOC_LITERAL(1287, 14), // "uiStnRndNum_RS"
QT_MOC_LITERAL(1302, 9), // "uiStnTDMA"
QT_MOC_LITERAL(1312, 10), // "uiMAC_Code"
QT_MOC_LITERAL(1323, 8), // "uiPktCrc"
QT_MOC_LITERAL(1332, 38), // "SlotAdditionalEmergencyPktIns..."
QT_MOC_LITERAL(1371, 12), // "uiGenSoSCall"
QT_MOC_LITERAL(1384, 26), // "SlotInsertDBStnRegMASubPkt"
QT_MOC_LITERAL(1411, 20), // "MovementAuthorityPkt"
QT_MOC_LITERAL(1432, 7), // "stMAPkt"
QT_MOC_LITERAL(1440, 27), // "SlotInsertDBStnRegSSPSubPkt"
QT_MOC_LITERAL(1468, 21), // "StaticSpeedProfilePkt"
QT_MOC_LITERAL(1490, 8), // "stSSPPkt"
QT_MOC_LITERAL(1499, 32), // "SlotInsertDBStnRegGradientSubPkt"
QT_MOC_LITERAL(1532, 18), // "GradientProfilePkt"
QT_MOC_LITERAL(1551, 13), // "stGradprofPkt"
QT_MOC_LITERAL(1565, 30), // "SlotInsertDBStnRegLCGateSubPkt"
QT_MOC_LITERAL(1596, 16), // "LCGateProfilePkt"
QT_MOC_LITERAL(1613, 11), // "stLCGatePkt"
QT_MOC_LITERAL(1625, 36), // "SlotInsertDBStnRegTurnoutSpee..."
QT_MOC_LITERAL(1662, 22), // "TurnoutSpeedProfilePkt"
QT_MOC_LITERAL(1685, 8), // "stTSPPkt"
QT_MOC_LITERAL(1694, 38), // "SlotInsertDBStnRegTagLinkingI..."
QT_MOC_LITERAL(1733, 17), // "TagLinkingInfoPkt"
QT_MOC_LITERAL(1751, 15), // "stTagLinkInfPkt"
QT_MOC_LITERAL(1767, 37), // "SlotInsertDBStnRegTrackCondDa..."
QT_MOC_LITERAL(1805, 17), // "TrackConditionPkt"
QT_MOC_LITERAL(1823, 18), // "stTrackCondDataPkt"
QT_MOC_LITERAL(1842, 27), // "SlotInsertDBStnRegTSRSubPkt"
QT_MOC_LITERAL(1870, 23), // "TempSpeedRestrictionPkt"
QT_MOC_LITERAL(1894, 8), // "stTSRPkt"
QT_MOC_LITERAL(1903, 28), // "SlotInsertDBStationRegHeader"
QT_MOC_LITERAL(1932, 8), // "stHeader"
QT_MOC_LITERAL(1941, 20), // "StationRegularHeader"
QT_MOC_LITERAL(1962, 13), // "stStnRglrHPkt"
QT_MOC_LITERAL(1976, 28), // "SlotInsertDBStationhealthPkt"
QT_MOC_LITERAL(2005, 18), // "stStationHealthPkt"
QT_MOC_LITERAL(2024, 12), // "stStnHlthPkt"
QT_MOC_LITERAL(2037, 9), // "strEvntID"
QT_MOC_LITERAL(2047, 11), // "strEvntData"
QT_MOC_LITERAL(2059, 5), // "uiCrc"
QT_MOC_LITERAL(2065, 28), // "SlotInsertDBOnBoardhealthPkt"
QT_MOC_LITERAL(2094, 18), // "stOnBoardHealthPkt"
QT_MOC_LITERAL(2113, 14), // "stOnBrdHlthPkt"
QT_MOC_LITERAL(2128, 24), // "SlotInsertDBS2SPDIVerCmd"
QT_MOC_LITERAL(2153, 14), // "stPacketHeader"
QT_MOC_LITERAL(2168, 8), // "stPktHdr"
QT_MOC_LITERAL(2177, 19), // "stPDIVerCheckCmdPkt"
QT_MOC_LITERAL(2197, 11), // "stPDIVerCmd"
QT_MOC_LITERAL(2209, 24), // "SlotInsertDBS2SPDIVerMsg"
QT_MOC_LITERAL(2234, 19), // "stPDIVerCheckMsgPkt"
QT_MOC_LITERAL(2254, 11), // "stPDIVerMsg"
QT_MOC_LITERAL(2266, 24), // "SlotInsertDBS2SHeartBeat"
QT_MOC_LITERAL(2291, 14), // "stHeartBeatPkt"
QT_MOC_LITERAL(2306, 11), // "stHeartBeat"
QT_MOC_LITERAL(2318, 31), // "SlotInsertDBS2STrainHandOverReq"
QT_MOC_LITERAL(2350, 21), // "stTrainHandOverReqPkt"
QT_MOC_LITERAL(2372, 14), // "stTrnHndOveReq"
QT_MOC_LITERAL(2387, 32), // "SlotInsertDBS2STrainTakenOverMsg"
QT_MOC_LITERAL(2420, 19), // "stTrainTakenOverPkt"
QT_MOC_LITERAL(2440, 14), // "stTrnTknOveMsg"
QT_MOC_LITERAL(2455, 43), // "SlotInsertDBS2STrainHandOverC..."
QT_MOC_LITERAL(2499, 30), // "stTrainHandOverCancellationPkt"
QT_MOC_LITERAL(2530, 18), // "stTrnHndOvrCnclPkt"
QT_MOC_LITERAL(2549, 40), // "SlotInsertDBS2STrainLengthInf..."
QT_MOC_LITERAL(2590, 20), // "stTrainLengthInfoPkt"
QT_MOC_LITERAL(2611, 15), // "stTrnLenInfoPkt"
QT_MOC_LITERAL(2627, 35), // "SlotInsertDBS2SLengthInformat..."
QT_MOC_LITERAL(2663, 20), // "stTrainLengthInfoAck"
QT_MOC_LITERAL(2684, 15), // "stTrnLenInfoAck"
QT_MOC_LITERAL(2700, 30), // "SlotInsertDBS2STSLRouteRequest"
QT_MOC_LITERAL(2731, 11), // "stTSLReqPkt"
QT_MOC_LITERAL(2743, 13), // "stTSLRouteReq"
QT_MOC_LITERAL(2757, 41), // "SlotInsertDBS2STSLAuthorityIn..."
QT_MOC_LITERAL(2799, 19), // "stTSLInformationPkt"
QT_MOC_LITERAL(2819, 12), // "stTSLInfoPkt"
QT_MOC_LITERAL(2832, 37), // "SlotInsertDBS2SFieldElementsS..."
QT_MOC_LITERAL(2870, 27), // "stFieldElementsStatusReqPkt"
QT_MOC_LITERAL(2898, 18), // "stFldElementStsReq"
QT_MOC_LITERAL(2917, 43), // "SlotInsertDBS2STrainHandoverC..."
QT_MOC_LITERAL(2961, 33), // "stTrainHandOverCancellationAc..."
QT_MOC_LITERAL(2995, 18), // "stTrnHndOvrCnclAck"
QT_MOC_LITERAL(3014, 27), // "SlotInsertDBLocoRSSIMessage"
QT_MOC_LITERAL(3042, 13), // "stLocoRSSIMsg"
QT_MOC_LITERAL(3056, 10), // "stLocoRSSI"
QT_MOC_LITERAL(3067, 30), // "SlotInsertDBStationRSSIMessage"
QT_MOC_LITERAL(3098, 16), // "stStationRSSIMsg"
QT_MOC_LITERAL(3115, 9), // "stStnRSSI"
QT_MOC_LITERAL(3125, 30), // "SlotInsertDBStatioKavachSysSts"
QT_MOC_LITERAL(3156, 25), // "stStationaryKavachSysInfo"
QT_MOC_LITERAL(3182, 16), // "stStnKavchSysSts"
QT_MOC_LITERAL(3199, 27), // "SlotInsertDBOnBoardEventMsg"
QT_MOC_LITERAL(3227, 23), // "stOnboardKavachEventMsg"
QT_MOC_LITERAL(3251, 16), // "stOnBoardEvntMsg"
QT_MOC_LITERAL(3268, 32), // "SlotInsertDBOnBoardBrakeEventMsg"
QT_MOC_LITERAL(3301, 28), // "stOnboardKavachBrakeEventMsg"
QT_MOC_LITERAL(3330, 21), // "stOnBoardBrakeEvntMsg"
QT_MOC_LITERAL(3352, 32), // "SlotInsertDBOnboardBOKSHealthMsg"
QT_MOC_LITERAL(3385, 28), // "stOnboardKavachBOKSHealthMsg"
QT_MOC_LITERAL(3414, 18), // "stOnBoardSysHealth"
QT_MOC_LITERAL(3433, 28), // "SlotInsertDBFieldInputStatus"
QT_MOC_LITERAL(3462, 10), // "usRelayCnt"
QT_MOC_LITERAL(3473, 15), // "byArrRelayImage"
QT_MOC_LITERAL(3489, 31), // "SlotInsertDBFieldInputEventData"
QT_MOC_LITERAL(3521, 16), // "stFieldEventData"
QT_MOC_LITERAL(3538, 13), // "stFldEvntData"
QT_MOC_LITERAL(3552, 25), // "SlotInserttoDBFieldStatus"
QT_MOC_LITERAL(3578, 10), // "strFieldId"
QT_MOC_LITERAL(3589, 8), // "ucStatus"
QT_MOC_LITERAL(3598, 20), // "SlotInsertRemoteUser"
QT_MOC_LITERAL(3619, 7), // "strName"
QT_MOC_LITERAL(3627, 8), // "strUName"
QT_MOC_LITERAL(3636, 6), // "strPwd"
QT_MOC_LITERAL(3643, 7), // "bStatus"
QT_MOC_LITERAL(3651, 20), // "SlotFetchRemoteUsers"
QT_MOC_LITERAL(3672, 20), // "SlotDeleteRemoteUser"
QT_MOC_LITERAL(3693, 9), // "strUserID"
QT_MOC_LITERAL(3703, 20), // "SlotUpdateRemoteUser"
QT_MOC_LITERAL(3724, 21), // "QList<QList<QString>>"
QT_MOC_LITERAL(3746, 9) // "lstvalues"

    },
    "nmsDBQuerys\0SigDBSMSnumbersResults\0\0"
    "uint8_t\0ucColCount\0uint16_t\0usRowCount\0"
    "strlstFldNames\0strlstRowValues\0"
    "SigDBRemoteUserResults\0SigDBStationInfo\0"
    "SigDBLocoInfo\0SigDBfaultmsgInfo\0"
    "SigDBSMSFaultsinfo\0QList<QStringList>\0"
    "SlotFaultPktInserttoDB\0stKavachtoNMS*\0"
    "pstKavachtoNMS\0strFaultsCode\0strFaultMsg\0"
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
    "ucStatus\0SlotInsertRemoteUser\0strName\0"
    "strUName\0strPwd\0bStatus\0SlotFetchRemoteUsers\0"
    "SlotDeleteRemoteUser\0strUserID\0"
    "SlotUpdateRemoteUser\0QList<QList<QString>>\0"
    "lstvalues"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nmsDBQuerys[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      55,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    4,  344,    2, 0x06,    1 /* Public */,
       9,    4,  353,    2, 0x06,    6 /* Public */,
      10,    4,  362,    2, 0x06,   11 /* Public */,
      11,    4,  371,    2, 0x06,   16 /* Public */,
      12,    4,  380,    2, 0x06,   21 /* Public */,
      13,    4,  389,    2, 0x06,   26 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      15,    3,  398,    2, 0x0a,   31 /* Public */,
      20,    5,  405,    2, 0x0a,   35 /* Public */,
      25,    0,  416,    2, 0x0a,   41 /* Public */,
      26,    0,  417,    2, 0x0a,   42 /* Public */,
      27,    0,  418,    2, 0x0a,   43 /* Public */,
      28,    5,  419,    2, 0x0a,   44 /* Public */,
      36,    5,  430,    2, 0x0a,   50 /* Public */,
      38,    4,  441,    2, 0x0a,   56 /* Public */,
      40,    4,  450,    2, 0x0a,   61 /* Public */,
      43,   23,  459,    2, 0x0a,   66 /* Public */,
      68,   31,  506,    2, 0x0a,   90 /* Public */,
      81,   16,  569,    2, 0x0a,  122 /* Public */,
      93,    9,  602,    2, 0x0a,  139 /* Public */,
      95,    1,  621,    2, 0x0a,  149 /* Public */,
      98,    1,  624,    2, 0x0a,  151 /* Public */,
     101,    1,  627,    2, 0x0a,  153 /* Public */,
     104,    1,  630,    2, 0x0a,  155 /* Public */,
     107,    1,  633,    2, 0x0a,  157 /* Public */,
     110,    1,  636,    2, 0x0a,  159 /* Public */,
     113,    1,  639,    2, 0x0a,  161 /* Public */,
     116,    1,  642,    2, 0x0a,  163 /* Public */,
     119,    2,  645,    2, 0x0a,  165 /* Public */,
     123,    4,  650,    2, 0x0a,  168 /* Public */,
     129,    4,  659,    2, 0x0a,  173 /* Public */,
     132,    2,  668,    2, 0x0a,  178 /* Public */,
     137,    2,  673,    2, 0x0a,  181 /* Public */,
     140,    2,  678,    2, 0x0a,  184 /* Public */,
     143,    2,  683,    2, 0x0a,  187 /* Public */,
     146,    2,  688,    2, 0x0a,  190 /* Public */,
     149,    2,  693,    2, 0x0a,  193 /* Public */,
     152,    2,  698,    2, 0x0a,  196 /* Public */,
     155,    2,  703,    2, 0x0a,  199 /* Public */,
     158,    2,  708,    2, 0x0a,  202 /* Public */,
     161,    2,  713,    2, 0x0a,  205 /* Public */,
     164,    2,  718,    2, 0x0a,  208 /* Public */,
     167,    2,  723,    2, 0x0a,  211 /* Public */,
     170,    1,  728,    2, 0x0a,  214 /* Public */,
     173,    1,  731,    2, 0x0a,  216 /* Public */,
     176,    1,  734,    2, 0x0a,  218 /* Public */,
     179,    1,  737,    2, 0x0a,  220 /* Public */,
     182,    1,  740,    2, 0x0a,  222 /* Public */,
     185,    1,  743,    2, 0x0a,  224 /* Public */,
     188,    4,  746,    2, 0x0a,  226 /* Public */,
     191,    1,  755,    2, 0x0a,  231 /* Public */,
     194,    2,  758,    2, 0x0a,  233 /* Public */,
     197,    4,  763,    2, 0x0a,  236 /* Public */,
     202,    0,  772,    2, 0x0a,  241 /* Public */,
     203,    1,  773,    2, 0x0a,  242 /* Public */,
     205,    1,  776,    2, 0x0a,  244 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::QStringList, QMetaType::QStringList,    4,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::QStringList, QMetaType::QStringList,    4,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::QStringList, QMetaType::QStringList,    4,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::QStringList, QMetaType::QStringList,    4,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::QStringList, QMetaType::QStringList,    4,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::QStringList, 0x80000000 | 14,    4,    6,    7,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 16, QMetaType::QString, QMetaType::QString,   17,   18,   19,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList,   22,   23,   24,   18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 31, QMetaType::QString, 0x80000000 | 34,   29,   30,   32,   33,   35,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 5, QMetaType::QString, 0x80000000 | 34,   29,   30,   37,   33,   35,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 31, QMetaType::QString,   29,   30,   32,   39,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 5, QMetaType::QString,   29,   30,   41,   42,
    QMetaType::Void, 0x80000000 | 44, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 34,   45,   46,   47,   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,   62,   63,   64,   65,   66,   67,
    QMetaType::Void, 0x80000000 | 44, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, QMetaType::QString, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 34,   45,   46,   47,   48,   49,   50,   51,   69,   70,   71,   52,   53,   54,   55,   56,   58,   72,   73,   59,   74,   75,   76,   77,   78,   79,   80,   63,   64,   65,   66,   67,
    QMetaType::Void, 0x80000000 | 44, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34,   45,   46,   47,   48,   82,   83,   84,   85,   86,   87,   88,   89,   90,   91,   92,   67,
    QMetaType::Void, 0x80000000 | 44, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34, 0x80000000 | 34,   45,   46,   47,   48,   82,   83,   84,   94,   67,
    QMetaType::Void, 0x80000000 | 96,   97,
    QMetaType::Void, 0x80000000 | 99,  100,
    QMetaType::Void, 0x80000000 | 102,  103,
    QMetaType::Void, 0x80000000 | 105,  106,
    QMetaType::Void, 0x80000000 | 108,  109,
    QMetaType::Void, 0x80000000 | 111,  112,
    QMetaType::Void, 0x80000000 | 114,  115,
    QMetaType::Void, 0x80000000 | 117,  118,
    QMetaType::ULongLong, 0x80000000 | 44, 0x80000000 | 121,  120,  122,
    QMetaType::Void, 0x80000000 | 124, QMetaType::QStringList, QMetaType::QStringList, 0x80000000 | 34,  125,  126,  127,  128,
    QMetaType::Void, 0x80000000 | 130, QMetaType::QString, QMetaType::QString, 0x80000000 | 34,  131,  126,  127,  128,
    QMetaType::Void, 0x80000000 | 133, 0x80000000 | 135,  134,  136,
    QMetaType::Void, 0x80000000 | 133, 0x80000000 | 138,  134,  139,
    QMetaType::Void, 0x80000000 | 133, 0x80000000 | 141,  134,  142,
    QMetaType::Void, 0x80000000 | 133, 0x80000000 | 144,  134,  145,
    QMetaType::Void, 0x80000000 | 133, 0x80000000 | 147,  134,  148,
    QMetaType::Void, 0x80000000 | 133, 0x80000000 | 150,  134,  151,
    QMetaType::Void, 0x80000000 | 133, 0x80000000 | 153,  134,  154,
    QMetaType::Void, 0x80000000 | 133, 0x80000000 | 156,  134,  157,
    QMetaType::Void, 0x80000000 | 133, 0x80000000 | 159,  134,  160,
    QMetaType::Void, 0x80000000 | 133, 0x80000000 | 162,  134,  163,
    QMetaType::Void, 0x80000000 | 133, 0x80000000 | 165,  134,  166,
    QMetaType::Void, 0x80000000 | 133, 0x80000000 | 168,  134,  169,
    QMetaType::Void, 0x80000000 | 171,  172,
    QMetaType::Void, 0x80000000 | 174,  175,
    QMetaType::Void, 0x80000000 | 177,  178,
    QMetaType::Void, 0x80000000 | 180,  181,
    QMetaType::Void, 0x80000000 | 183,  184,
    QMetaType::Void, 0x80000000 | 186,  187,
    QMetaType::Void, 0x80000000 | 133, 0x80000000 | 5, QMetaType::QByteArray, 0x80000000 | 34,  134,  189,  190,   67,
    QMetaType::Void, 0x80000000 | 192,  193,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3,  195,  196,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool,  198,  199,  200,  201,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  204,
    QMetaType::Void, 0x80000000 | 206,  207,

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
        case 6: _t->SlotFaultPktInserttoDB((*reinterpret_cast< std::add_pointer_t<stKavachtoNMS*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 7: _t->SlotStnFaultPktInserttoDB((*reinterpret_cast< std::add_pointer_t<stStationFaults*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[5]))); break;
        case 8: _t->SlotStationInfo(); break;
        case 9: _t->SlotLocoInfo(); break;
        case 10: _t->SlotPrvPromptInfo(); break;
        case 11: _t->SlotFaultMsginserttoDB((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<uint16_t>>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[5]))); break;
        case 12: _t->SlotStnFaultMsginserttoDB((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[5]))); break;
        case 13: _t->SlotSMSFaultMsginserttoDB((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<uint16_t>>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 14: _t->SlotSMSStnFaultMsginserttoDB((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 15: _t->SlotAccessReqInsertintoDB((*reinterpret_cast< std::add_pointer_t<stAccessRequestPkt>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[13])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[14])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[15])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[16])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[17])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[18])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[19])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[20])),(*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[21])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[22])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[23]))); break;
        case 16: _t->SlotLocoRegularInsertintoDB((*reinterpret_cast< std::add_pointer_t<stAccessRequestPkt>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[13])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[14])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[15])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[16])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[17])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[18])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[19])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[20])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[21])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[22])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[23])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[24])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[25])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[26])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[27])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[28])),(*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[29])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[30])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[31]))); break;
        case 17: _t->SlotAccessAuthorityPktInsertintoDB((*reinterpret_cast< std::add_pointer_t<stAccessRequestPkt>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[13])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[14])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[15])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[16]))); break;
        case 18: _t->SlotAdditionalEmergencyPktInsertintoDB((*reinterpret_cast< std::add_pointer_t<stAccessRequestPkt>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[9]))); break;
        case 19: _t->SlotInsertDBStnRegMASubPkt((*reinterpret_cast< std::add_pointer_t<MovementAuthorityPkt>>(_a[1]))); break;
        case 20: _t->SlotInsertDBStnRegSSPSubPkt((*reinterpret_cast< std::add_pointer_t<StaticSpeedProfilePkt>>(_a[1]))); break;
        case 21: _t->SlotInsertDBStnRegGradientSubPkt((*reinterpret_cast< std::add_pointer_t<GradientProfilePkt>>(_a[1]))); break;
        case 22: _t->SlotInsertDBStnRegLCGateSubPkt((*reinterpret_cast< std::add_pointer_t<LCGateProfilePkt>>(_a[1]))); break;
        case 23: _t->SlotInsertDBStnRegTurnoutSpeedSubPkt((*reinterpret_cast< std::add_pointer_t<TurnoutSpeedProfilePkt>>(_a[1]))); break;
        case 24: _t->SlotInsertDBStnRegTagLinkingInfoSubPkt((*reinterpret_cast< std::add_pointer_t<TagLinkingInfoPkt>>(_a[1]))); break;
        case 25: _t->SlotInsertDBStnRegTrackCondDataSubPkt((*reinterpret_cast< std::add_pointer_t<TrackConditionPkt>>(_a[1]))); break;
        case 26: _t->SlotInsertDBStnRegTSRSubPkt((*reinterpret_cast< std::add_pointer_t<TempSpeedRestrictionPkt>>(_a[1]))); break;
        case 27: { quint64 _r = _t->SlotInsertDBStationRegHeader((*reinterpret_cast< std::add_pointer_t<stAccessRequestPkt>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<StationRegularHeader>>(_a[2])));
            if (_a[0]) *reinterpret_cast< quint64*>(_a[0]) = std::move(_r); }  break;
        case 28: _t->SlotInsertDBStationhealthPkt((*reinterpret_cast< std::add_pointer_t<stStationHealthPkt>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4]))); break;
        case 29: _t->SlotInsertDBOnBoardhealthPkt((*reinterpret_cast< std::add_pointer_t<stOnBoardHealthPkt>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4]))); break;
        case 30: _t->SlotInsertDBS2SPDIVerCmd((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stPDIVerCheckCmdPkt>>(_a[2]))); break;
        case 31: _t->SlotInsertDBS2SPDIVerMsg((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stPDIVerCheckMsgPkt>>(_a[2]))); break;
        case 32: _t->SlotInsertDBS2SHeartBeat((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stHeartBeatPkt>>(_a[2]))); break;
        case 33: _t->SlotInsertDBS2STrainHandOverReq((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTrainHandOverReqPkt>>(_a[2]))); break;
        case 34: _t->SlotInsertDBS2STrainTakenOverMsg((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTrainTakenOverPkt>>(_a[2]))); break;
        case 35: _t->SlotInsertDBS2STrainHandOverCancellationReq((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTrainHandOverCancellationPkt>>(_a[2]))); break;
        case 36: _t->SlotInsertDBS2STrainLengthInformationReq((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTrainLengthInfoPkt>>(_a[2]))); break;
        case 37: _t->SlotInsertDBS2SLengthInformationAck((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTrainLengthInfoAck>>(_a[2]))); break;
        case 38: _t->SlotInsertDBS2STSLRouteRequest((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTSLReqPkt>>(_a[2]))); break;
        case 39: _t->SlotInsertDBS2STSLAuthorityInformationPkt((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTSLInformationPkt>>(_a[2]))); break;
        case 40: _t->SlotInsertDBS2SFieldElementsStatusReq((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stFieldElementsStatusReqPkt>>(_a[2]))); break;
        case 41: _t->SlotInsertDBS2STrainHandoverCancellationAck((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTrainHandOverCancellationAckPkt>>(_a[2]))); break;
        case 42: _t->SlotInsertDBLocoRSSIMessage((*reinterpret_cast< std::add_pointer_t<stLocoRSSIMsg>>(_a[1]))); break;
        case 43: _t->SlotInsertDBStationRSSIMessage((*reinterpret_cast< std::add_pointer_t<stStationRSSIMsg>>(_a[1]))); break;
        case 44: _t->SlotInsertDBStatioKavachSysSts((*reinterpret_cast< std::add_pointer_t<stStationaryKavachSysInfo>>(_a[1]))); break;
        case 45: _t->SlotInsertDBOnBoardEventMsg((*reinterpret_cast< std::add_pointer_t<stOnboardKavachEventMsg>>(_a[1]))); break;
        case 46: _t->SlotInsertDBOnBoardBrakeEventMsg((*reinterpret_cast< std::add_pointer_t<stOnboardKavachBrakeEventMsg>>(_a[1]))); break;
        case 47: _t->SlotInsertDBOnboardBOKSHealthMsg((*reinterpret_cast< std::add_pointer_t<stOnboardKavachBOKSHealthMsg>>(_a[1]))); break;
        case 48: _t->SlotInsertDBFieldInputStatus((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4]))); break;
        case 49: _t->SlotInsertDBFieldInputEventData((*reinterpret_cast< std::add_pointer_t<stFieldEventData>>(_a[1]))); break;
        case 50: _t->SlotInserttoDBFieldStatus((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[2]))); break;
        case 51: _t->SlotInsertRemoteUser((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 52: _t->SlotFetchRemoteUsers(); break;
        case 53: _t->SlotDeleteRemoteUser((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 54: _t->SlotUpdateRemoteUser((*reinterpret_cast< std::add_pointer_t<QList<QList<QString>>>>(_a[1]))); break;
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
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stAccessRequestPkt >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stAccessRequestPkt >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stAccessRequestPkt >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stAccessRequestPkt >(); break;
            }
            break;
        case 27:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stAccessRequestPkt >(); break;
            }
            break;
        case 28:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stStationHealthPkt >(); break;
            }
            break;
        case 29:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stOnBoardHealthPkt >(); break;
            }
            break;
        case 30:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPDIVerCheckCmdPkt >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            }
            break;
        case 31:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPDIVerCheckMsgPkt >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            }
            break;
        case 32:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stHeartBeatPkt >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            }
            break;
        case 33:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTrainHandOverReqPkt >(); break;
            }
            break;
        case 34:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTrainTakenOverPkt >(); break;
            }
            break;
        case 35:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTrainHandOverCancellationPkt >(); break;
            }
            break;
        case 36:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTrainLengthInfoPkt >(); break;
            }
            break;
        case 37:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTrainLengthInfoAck >(); break;
            }
            break;
        case 38:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTSLReqPkt >(); break;
            }
            break;
        case 39:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTSLInformationPkt >(); break;
            }
            break;
        case 40:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stFieldElementsStatusReqPkt >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            }
            break;
        case 41:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTrainHandOverCancellationAckPkt >(); break;
            }
            break;
        case 42:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stLocoRSSIMsg >(); break;
            }
            break;
        case 43:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stStationRSSIMsg >(); break;
            }
            break;
        case 44:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stStationaryKavachSysInfo >(); break;
            }
            break;
        case 45:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stOnboardKavachEventMsg >(); break;
            }
            break;
        case 47:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stOnboardKavachBOKSHealthMsg >(); break;
            }
            break;
        case 48:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            }
            break;
        case 49:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stFieldEventData >(); break;
            }
            break;
        case 54:
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
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stKavachtoNMS *, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stStationFaults *, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QList<uint16_t>, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QList<uint16_t>, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<MovementAuthorityPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<StaticSpeedProfilePkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<GradientProfilePkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<LCGateProfilePkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<TurnoutSpeedProfilePkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<TagLinkingInfoPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<TrackConditionPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<TempSpeedRestrictionPkt, std::false_type>, QtPrivate::TypeAndForceComplete<quint64, std::false_type>, QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>, QtPrivate::TypeAndForceComplete<StationRegularHeader, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stStationHealthPkt, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stOnBoardHealthPkt, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stPDIVerCheckCmdPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stPDIVerCheckMsgPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stHeartBeatPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainHandOverReqPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainTakenOverPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainHandOverCancellationPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainLengthInfoPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainLengthInfoAck, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTSLReqPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTSLInformationPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stFieldElementsStatusReqPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainHandOverCancellationAckPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stLocoRSSIMsg, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stStationRSSIMsg, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stStationaryKavachSysInfo, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stOnboardKavachEventMsg, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stOnboardKavachBrakeEventMsg, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stOnboardKavachBOKSHealthMsg, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stFieldEventData, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QList<QString>>, std::false_type>


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
        if (_id < 55)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 55;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 55)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 55;
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
