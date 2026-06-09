/****************************************************************************
** Meta object code from reading C++ file 'nmsMainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../include/nmsMainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nmsMainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_nmsMainWindow_t {
    const uint offsetsAndSize[396];
    char stringdata0[3369];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_nmsMainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_nmsMainWindow_t qt_meta_stringdata_nmsMainWindow = {
    {
QT_MOC_LITERAL(0, 13), // "nmsMainWindow"
QT_MOC_LITERAL(14, 21), // "SigSendAckNMStoKavach"
QT_MOC_LITERAL(36, 0), // ""
QT_MOC_LITERAL(37, 12), // "QHostAddress"
QT_MOC_LITERAL(50, 8), // "senderIP"
QT_MOC_LITERAL(59, 10), // "senderPort"
QT_MOC_LITERAL(70, 14), // "stNMStoKavach*"
QT_MOC_LITERAL(85, 6), // "pstAck"
QT_MOC_LITERAL(92, 21), // "SigFaultPktInserttoDB"
QT_MOC_LITERAL(114, 14), // "stKavachtoNMS*"
QT_MOC_LITERAL(129, 14), // "pstKavachtoNMS"
QT_MOC_LITERAL(144, 13), // "strFaultsCode"
QT_MOC_LITERAL(158, 11), // "strFaultMsg"
QT_MOC_LITERAL(170, 24), // "SigStnFaultPktInserttoDB"
QT_MOC_LITERAL(195, 16), // "stStationFaults*"
QT_MOC_LITERAL(212, 12), // "pstStnFaults"
QT_MOC_LITERAL(225, 14), // "SigStationInfo"
QT_MOC_LITERAL(240, 11), // "SigLocoInfo"
QT_MOC_LITERAL(252, 21), // "SigFaultMsginserttoDB"
QT_MOC_LITERAL(274, 10), // "strMsgType"
QT_MOC_LITERAL(285, 12), // "strTimestamp"
QT_MOC_LITERAL(298, 15), // "QList<uint16_t>"
QT_MOC_LITERAL(314, 14), // "faultByteArray"
QT_MOC_LITERAL(329, 10), // "strFirmNam"
QT_MOC_LITERAL(340, 8), // "uint32_t"
QT_MOC_LITERAL(349, 4), // "uiID"
QT_MOC_LITERAL(354, 24), // "SigStnFaultMsginserttoDB"
QT_MOC_LITERAL(379, 8), // "uint16_t"
QT_MOC_LITERAL(388, 11), // "usFaultCode"
QT_MOC_LITERAL(400, 24), // "SigSMSFaultMsginserttoDB"
QT_MOC_LITERAL(425, 12), // "strFirmNamID"
QT_MOC_LITERAL(438, 27), // "SigSMSStnFaultMsginserttoDB"
QT_MOC_LITERAL(466, 11), // "usFaultCOde"
QT_MOC_LITERAL(478, 10), // "SigSendSMS"
QT_MOC_LITERAL(489, 7), // "message"
QT_MOC_LITERAL(497, 19), // "SigSendFaultmessage"
QT_MOC_LITERAL(517, 12), // "strTimeStamp"
QT_MOC_LITERAL(530, 9), // "strFirmid"
QT_MOC_LITERAL(540, 24), // "SigAccessReqInsertintoDB"
QT_MOC_LITERAL(565, 18), // "stAccessRequestPkt"
QT_MOC_LITERAL(584, 8), // "stheader"
QT_MOC_LITERAL(593, 9), // "uiPktType"
QT_MOC_LITERAL(603, 8), // "uiPktLen"
QT_MOC_LITERAL(612, 7), // "uiFrmNo"
QT_MOC_LITERAL(620, 11), // "uiSrcLocoID"
QT_MOC_LITERAL(632, 12), // "uiSrcLocoVer"
QT_MOC_LITERAL(645, 13), // "uiAbsLoco_Loc"
QT_MOC_LITERAL(659, 10), // "uiTrainLen"
QT_MOC_LITERAL(670, 10), // "uiTrainSpd"
QT_MOC_LITERAL(681, 11), // "uiMovMntDir"
QT_MOC_LITERAL(693, 14), // "uiEmergencySts"
QT_MOC_LITERAL(708, 10), // "uiLocoMode"
QT_MOC_LITERAL(719, 10), // "uiApprStID"
QT_MOC_LITERAL(730, 13), // "uiLastRfidTag"
QT_MOC_LITERAL(744, 7), // "uitinNo"
QT_MOC_LITERAL(752, 11), // "uiLongitude"
QT_MOC_LITERAL(764, 10), // "uiLatitude"
QT_MOC_LITERAL(775, 13), // "uiLocoRandmrl"
QT_MOC_LITERAL(789, 9), // "uiMACCode"
QT_MOC_LITERAL(799, 8), // "uiPktCRC"
QT_MOC_LITERAL(808, 7), // "uint8_t"
QT_MOC_LITERAL(816, 10), // "ucMASecCnt"
QT_MOC_LITERAL(827, 9), // "usRouteID"
QT_MOC_LITERAL(837, 5), // "uiCRC"
QT_MOC_LITERAL(843, 26), // "SigLocoRegularInsertintoDB"
QT_MOC_LITERAL(870, 11), // "uidoubtover"
QT_MOC_LITERAL(882, 12), // "uidoubtunder"
QT_MOC_LITERAL(895, 10), // "uitrainint"
QT_MOC_LITERAL(906, 8), // "uiTagDup"
QT_MOC_LITERAL(915, 13), // "uitagLinkInfo"
QT_MOC_LITERAL(929, 10), // "uiBrkApply"
QT_MOC_LITERAL(940, 12), // "uinewMAReply"
QT_MOC_LITERAL(953, 15), // "uiLastRefProfNo"
QT_MOC_LITERAL(969, 7), // "uiSigOV"
QT_MOC_LITERAL(977, 9), // "uiInfoAck"
QT_MOC_LITERAL(987, 7), // "uiSpare"
QT_MOC_LITERAL(995, 14), // "strLocoHlthSts"
QT_MOC_LITERAL(1010, 33), // "SigAccessAuthorityPktInsertin..."
QT_MOC_LITERAL(1044, 17), // "uiSrcStnILCIBS_ID"
QT_MOC_LITERAL(1062, 18), // "uiSRCStnILCIBS_ver"
QT_MOC_LITERAL(1081, 15), // "uiStnILCIBS_Loc"
QT_MOC_LITERAL(1097, 13), // "uiDestLoco_ID"
QT_MOC_LITERAL(1111, 16), // "uiAlotUpLnk_Freq"
QT_MOC_LITERAL(1128, 16), // "uiAlotDnLnk_Freq"
QT_MOC_LITERAL(1145, 20), // "uiAlotTDMA_Timeslots"
QT_MOC_LITERAL(1166, 14), // "uiStnRndNum_RS"
QT_MOC_LITERAL(1181, 9), // "uiStnTDMA"
QT_MOC_LITERAL(1191, 10), // "uiMAC_Code"
QT_MOC_LITERAL(1202, 8), // "uiPktCrc"
QT_MOC_LITERAL(1211, 37), // "SigAdditionalEmergencyPktInse..."
QT_MOC_LITERAL(1249, 12), // "uiGenSoSCall"
QT_MOC_LITERAL(1262, 27), // "SigInsertDBStationRegHeader"
QT_MOC_LITERAL(1290, 8), // "stHeader"
QT_MOC_LITERAL(1299, 20), // "StationRegularHeader"
QT_MOC_LITERAL(1320, 13), // "stStnRglrHPkt"
QT_MOC_LITERAL(1334, 27), // "SigInsertDBStationhealthPkt"
QT_MOC_LITERAL(1362, 18), // "stStationHealthPkt"
QT_MOC_LITERAL(1381, 12), // "stStnHlthPkt"
QT_MOC_LITERAL(1394, 9), // "strEvntID"
QT_MOC_LITERAL(1404, 11), // "strEvntData"
QT_MOC_LITERAL(1416, 5), // "uiCrc"
QT_MOC_LITERAL(1422, 27), // "SigInsertDBOnBoardhealthPkt"
QT_MOC_LITERAL(1450, 18), // "stOnBoardHealthPkt"
QT_MOC_LITERAL(1469, 14), // "stOnBrdHlthPkt"
QT_MOC_LITERAL(1484, 23), // "SigInsertDBS2SPDIVerCmd"
QT_MOC_LITERAL(1508, 14), // "stPacketHeader"
QT_MOC_LITERAL(1523, 8), // "stPktHdr"
QT_MOC_LITERAL(1532, 19), // "stPDIVerCheckCmdPkt"
QT_MOC_LITERAL(1552, 11), // "stPDIVerCmd"
QT_MOC_LITERAL(1564, 23), // "SigInsertDBS2SPDIVerMsg"
QT_MOC_LITERAL(1588, 19), // "stPDIVerCheckMsgPkt"
QT_MOC_LITERAL(1608, 11), // "stPDIVerMsg"
QT_MOC_LITERAL(1620, 23), // "SigInsertDBS2SHeartBeat"
QT_MOC_LITERAL(1644, 14), // "stHeartBeatPkt"
QT_MOC_LITERAL(1659, 11), // "stHeartBeat"
QT_MOC_LITERAL(1671, 30), // "SigInsertDBS2STrainHandOverReq"
QT_MOC_LITERAL(1702, 21), // "stTrainHandOverReqPkt"
QT_MOC_LITERAL(1724, 14), // "stTrnHndOveReq"
QT_MOC_LITERAL(1739, 31), // "SigInsertDBS2STrainTakenOverMsg"
QT_MOC_LITERAL(1771, 19), // "stTrainTakenOverPkt"
QT_MOC_LITERAL(1791, 14), // "stTrnTknOveMsg"
QT_MOC_LITERAL(1806, 42), // "SigInsertDBS2STrainHandOverCa..."
QT_MOC_LITERAL(1849, 30), // "stTrainHandOverCancellationPkt"
QT_MOC_LITERAL(1880, 18), // "stTrnHndOvrCnclPkt"
QT_MOC_LITERAL(1899, 39), // "SigInsertDBS2STrainLengthInfo..."
QT_MOC_LITERAL(1939, 20), // "stTrainLengthInfoPkt"
QT_MOC_LITERAL(1960, 15), // "stTrnLenInfoPkt"
QT_MOC_LITERAL(1976, 34), // "SigInsertDBS2SLengthInformati..."
QT_MOC_LITERAL(2011, 20), // "stTrainLengthInfoAck"
QT_MOC_LITERAL(2032, 15), // "stTrnLenInfoAck"
QT_MOC_LITERAL(2048, 29), // "SigInsertDBS2STSLRouteRequest"
QT_MOC_LITERAL(2078, 11), // "stTSLReqPkt"
QT_MOC_LITERAL(2090, 13), // "stTSLRouteReq"
QT_MOC_LITERAL(2104, 40), // "SigInsertDBS2STSLAuthorityInf..."
QT_MOC_LITERAL(2145, 19), // "stTSLInformationPkt"
QT_MOC_LITERAL(2165, 12), // "stTSLInfoPkt"
QT_MOC_LITERAL(2178, 36), // "SigInsertDBS2SFieldElementsSt..."
QT_MOC_LITERAL(2215, 27), // "stFieldElementsStatusReqPkt"
QT_MOC_LITERAL(2243, 18), // "stFldElementStsReq"
QT_MOC_LITERAL(2262, 42), // "SigInsertDBS2STrainHandoverCa..."
QT_MOC_LITERAL(2305, 33), // "stTrainHandOverCancellationAc..."
QT_MOC_LITERAL(2339, 18), // "stTrnHndOvrCnclAck"
QT_MOC_LITERAL(2358, 26), // "SigInsertDBLocoRSSIMessage"
QT_MOC_LITERAL(2385, 13), // "stLocoRSSIMsg"
QT_MOC_LITERAL(2399, 10), // "stLocoRSSI"
QT_MOC_LITERAL(2410, 29), // "SigInsertDBStationRSSIMessage"
QT_MOC_LITERAL(2440, 16), // "stStationRSSIMsg"
QT_MOC_LITERAL(2457, 9), // "stStnRSSI"
QT_MOC_LITERAL(2467, 30), // "SigInsertDBStationKavachSysSts"
QT_MOC_LITERAL(2498, 25), // "stStationaryKavachSysInfo"
QT_MOC_LITERAL(2524, 16), // "stStnKavchSysSts"
QT_MOC_LITERAL(2541, 30), // "SigInsertDBOnBoardEventMessage"
QT_MOC_LITERAL(2572, 23), // "stOnboardKavachEventMsg"
QT_MOC_LITERAL(2596, 17), // "stOnBoardEventMsg"
QT_MOC_LITERAL(2614, 31), // "SigInsertDBOnBoardBrakeEventMsg"
QT_MOC_LITERAL(2646, 28), // "stOnboardKavachBrakeEventMsg"
QT_MOC_LITERAL(2675, 21), // "stOnBoardBrakeEvntMsg"
QT_MOC_LITERAL(2697, 33), // "SigInsertDBOnBoardSystemHealt..."
QT_MOC_LITERAL(2731, 28), // "stOnboardKavachBOKSHealthMsg"
QT_MOC_LITERAL(2760, 18), // "stOnBoardSysHealth"
QT_MOC_LITERAL(2779, 27), // "SigInsertDBFieldInputStatus"
QT_MOC_LITERAL(2807, 10), // "usRelayCnt"
QT_MOC_LITERAL(2818, 15), // "byArrRelayImage"
QT_MOC_LITERAL(2834, 30), // "SigInsertDBFieldInputEventData"
QT_MOC_LITERAL(2865, 16), // "stFieldEventData"
QT_MOC_LITERAL(2882, 13), // "stFldEvntData"
QT_MOC_LITERAL(2896, 18), // "SigShowAllStations"
QT_MOC_LITERAL(2915, 21), // "SigStationisConnected"
QT_MOC_LITERAL(2937, 14), // "strStationName"
QT_MOC_LITERAL(2952, 7), // "bstatus"
QT_MOC_LITERAL(2960, 18), // "SlotNewFaultPacket"
QT_MOC_LITERAL(2979, 8), // "datagram"
QT_MOC_LITERAL(2988, 21), // "SlotPreviousFaultInfo"
QT_MOC_LITERAL(3010, 14), // "SlottabChanged"
QT_MOC_LITERAL(3025, 5), // "index"
QT_MOC_LITERAL(3031, 20), // "SlotUpadateSchematic"
QT_MOC_LITERAL(3052, 20), // "SlotStationNameAndID"
QT_MOC_LITERAL(3073, 15), // "strLstStationID"
QT_MOC_LITERAL(3089, 18), // "strLstStationNames"
QT_MOC_LITERAL(3108, 11), // "strDateTime"
QT_MOC_LITERAL(3120, 11), // "bStationSts"
QT_MOC_LITERAL(3132, 20), // "SlotStationRegHeader"
QT_MOC_LITERAL(3153, 21), // "SlotStationconnStatus"
QT_MOC_LITERAL(3175, 11), // "strHostAddr"
QT_MOC_LITERAL(3187, 7), // "bStatus"
QT_MOC_LITERAL(3195, 24), // "SlotKMSChannelChangeover"
QT_MOC_LITERAL(3220, 8), // "newSimID"
QT_MOC_LITERAL(3229, 21), // "SlotKMSPacketReceived"
QT_MOC_LITERAL(3251, 7), // "msgType"
QT_MOC_LITERAL(3259, 6), // "packet"
QT_MOC_LITERAL(3266, 17), // "SlotKMSPacketSent"
QT_MOC_LITERAL(3284, 10), // "SlotDoPing"
QT_MOC_LITERAL(3295, 24), // "SlotSendNextReplayPacket"
QT_MOC_LITERAL(3320, 15), // "SlotVCHeartbeat"
QT_MOC_LITERAL(3336, 15), // "SlotGPSPosition"
QT_MOC_LITERAL(3352, 4), // "dLat"
QT_MOC_LITERAL(3357, 4), // "dLon"
QT_MOC_LITERAL(3362, 6) // "bValid"

    },
    "nmsMainWindow\0SigSendAckNMStoKavach\0"
    "\0QHostAddress\0senderIP\0senderPort\0"
    "stNMStoKavach*\0pstAck\0SigFaultPktInserttoDB\0"
    "stKavachtoNMS*\0pstKavachtoNMS\0"
    "strFaultsCode\0strFaultMsg\0"
    "SigStnFaultPktInserttoDB\0stStationFaults*\0"
    "pstStnFaults\0SigStationInfo\0SigLocoInfo\0"
    "SigFaultMsginserttoDB\0strMsgType\0"
    "strTimestamp\0QList<uint16_t>\0"
    "faultByteArray\0strFirmNam\0uint32_t\0"
    "uiID\0SigStnFaultMsginserttoDB\0uint16_t\0"
    "usFaultCode\0SigSMSFaultMsginserttoDB\0"
    "strFirmNamID\0SigSMSStnFaultMsginserttoDB\0"
    "usFaultCOde\0SigSendSMS\0message\0"
    "SigSendFaultmessage\0strTimeStamp\0"
    "strFirmid\0SigAccessReqInsertintoDB\0"
    "stAccessRequestPkt\0stheader\0uiPktType\0"
    "uiPktLen\0uiFrmNo\0uiSrcLocoID\0uiSrcLocoVer\0"
    "uiAbsLoco_Loc\0uiTrainLen\0uiTrainSpd\0"
    "uiMovMntDir\0uiEmergencySts\0uiLocoMode\0"
    "uiApprStID\0uiLastRfidTag\0uitinNo\0"
    "uiLongitude\0uiLatitude\0uiLocoRandmrl\0"
    "uiMACCode\0uiPktCRC\0uint8_t\0ucMASecCnt\0"
    "usRouteID\0uiCRC\0SigLocoRegularInsertintoDB\0"
    "uidoubtover\0uidoubtunder\0uitrainint\0"
    "uiTagDup\0uitagLinkInfo\0uiBrkApply\0"
    "uinewMAReply\0uiLastRefProfNo\0uiSigOV\0"
    "uiInfoAck\0uiSpare\0strLocoHlthSts\0"
    "SigAccessAuthorityPktInsertintoDB\0"
    "uiSrcStnILCIBS_ID\0uiSRCStnILCIBS_ver\0"
    "uiStnILCIBS_Loc\0uiDestLoco_ID\0"
    "uiAlotUpLnk_Freq\0uiAlotDnLnk_Freq\0"
    "uiAlotTDMA_Timeslots\0uiStnRndNum_RS\0"
    "uiStnTDMA\0uiMAC_Code\0uiPktCrc\0"
    "SigAdditionalEmergencyPktInsertintoDB\0"
    "uiGenSoSCall\0SigInsertDBStationRegHeader\0"
    "stHeader\0StationRegularHeader\0"
    "stStnRglrHPkt\0SigInsertDBStationhealthPkt\0"
    "stStationHealthPkt\0stStnHlthPkt\0"
    "strEvntID\0strEvntData\0uiCrc\0"
    "SigInsertDBOnBoardhealthPkt\0"
    "stOnBoardHealthPkt\0stOnBrdHlthPkt\0"
    "SigInsertDBS2SPDIVerCmd\0stPacketHeader\0"
    "stPktHdr\0stPDIVerCheckCmdPkt\0stPDIVerCmd\0"
    "SigInsertDBS2SPDIVerMsg\0stPDIVerCheckMsgPkt\0"
    "stPDIVerMsg\0SigInsertDBS2SHeartBeat\0"
    "stHeartBeatPkt\0stHeartBeat\0"
    "SigInsertDBS2STrainHandOverReq\0"
    "stTrainHandOverReqPkt\0stTrnHndOveReq\0"
    "SigInsertDBS2STrainTakenOverMsg\0"
    "stTrainTakenOverPkt\0stTrnTknOveMsg\0"
    "SigInsertDBS2STrainHandOverCancellationReq\0"
    "stTrainHandOverCancellationPkt\0"
    "stTrnHndOvrCnclPkt\0"
    "SigInsertDBS2STrainLengthInformationReq\0"
    "stTrainLengthInfoPkt\0stTrnLenInfoPkt\0"
    "SigInsertDBS2SLengthInformationAck\0"
    "stTrainLengthInfoAck\0stTrnLenInfoAck\0"
    "SigInsertDBS2STSLRouteRequest\0stTSLReqPkt\0"
    "stTSLRouteReq\0SigInsertDBS2STSLAuthorityInformationPkt\0"
    "stTSLInformationPkt\0stTSLInfoPkt\0"
    "SigInsertDBS2SFieldElementsStatusReq\0"
    "stFieldElementsStatusReqPkt\0"
    "stFldElementStsReq\0"
    "SigInsertDBS2STrainHandoverCancellationAck\0"
    "stTrainHandOverCancellationAckPkt\0"
    "stTrnHndOvrCnclAck\0SigInsertDBLocoRSSIMessage\0"
    "stLocoRSSIMsg\0stLocoRSSI\0"
    "SigInsertDBStationRSSIMessage\0"
    "stStationRSSIMsg\0stStnRSSI\0"
    "SigInsertDBStationKavachSysSts\0"
    "stStationaryKavachSysInfo\0stStnKavchSysSts\0"
    "SigInsertDBOnBoardEventMessage\0"
    "stOnboardKavachEventMsg\0stOnBoardEventMsg\0"
    "SigInsertDBOnBoardBrakeEventMsg\0"
    "stOnboardKavachBrakeEventMsg\0"
    "stOnBoardBrakeEvntMsg\0"
    "SigInsertDBOnBoardSystemHealthMsg\0"
    "stOnboardKavachBOKSHealthMsg\0"
    "stOnBoardSysHealth\0SigInsertDBFieldInputStatus\0"
    "usRelayCnt\0byArrRelayImage\0"
    "SigInsertDBFieldInputEventData\0"
    "stFieldEventData\0stFldEvntData\0"
    "SigShowAllStations\0SigStationisConnected\0"
    "strStationName\0bstatus\0SlotNewFaultPacket\0"
    "datagram\0SlotPreviousFaultInfo\0"
    "SlottabChanged\0index\0SlotUpadateSchematic\0"
    "SlotStationNameAndID\0strLstStationID\0"
    "strLstStationNames\0strDateTime\0"
    "bStationSts\0SlotStationRegHeader\0"
    "SlotStationconnStatus\0strHostAddr\0"
    "bStatus\0SlotKMSChannelChangeover\0"
    "newSimID\0SlotKMSPacketReceived\0msgType\0"
    "packet\0SlotKMSPacketSent\0SlotDoPing\0"
    "SlotSendNextReplayPacket\0SlotVCHeartbeat\0"
    "SlotGPSPosition\0dLat\0dLon\0bValid"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nmsMainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      54,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      40,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,  338,    2, 0x06,    1 /* Public */,
       8,    3,  345,    2, 0x06,    5 /* Public */,
      13,    3,  352,    2, 0x06,    9 /* Public */,
      16,    0,  359,    2, 0x06,   13 /* Public */,
      17,    0,  360,    2, 0x06,   14 /* Public */,
      18,    5,  361,    2, 0x06,   15 /* Public */,
      26,    5,  372,    2, 0x06,   21 /* Public */,
      29,    4,  383,    2, 0x06,   27 /* Public */,
      31,    4,  392,    2, 0x06,   32 /* Public */,
      33,    2,  401,    2, 0x06,   37 /* Public */,
      35,    4,  406,    2, 0x06,   40 /* Public */,
      38,   23,  415,    2, 0x06,   45 /* Public */,
      64,   31,  462,    2, 0x06,   69 /* Public */,
      77,   16,  525,    2, 0x06,  101 /* Public */,
      89,    9,  558,    2, 0x06,  118 /* Public */,
      91,    2,  577,    2, 0x06,  128 /* Public */,
      95,    4,  582,    2, 0x06,  131 /* Public */,
     101,    4,  591,    2, 0x06,  136 /* Public */,
     104,    2,  600,    2, 0x06,  141 /* Public */,
     109,    2,  605,    2, 0x06,  144 /* Public */,
     112,    2,  610,    2, 0x06,  147 /* Public */,
     115,    2,  615,    2, 0x06,  150 /* Public */,
     118,    2,  620,    2, 0x06,  153 /* Public */,
     121,    2,  625,    2, 0x06,  156 /* Public */,
     124,    2,  630,    2, 0x06,  159 /* Public */,
     127,    2,  635,    2, 0x06,  162 /* Public */,
     130,    2,  640,    2, 0x06,  165 /* Public */,
     133,    2,  645,    2, 0x06,  168 /* Public */,
     136,    2,  650,    2, 0x06,  171 /* Public */,
     139,    2,  655,    2, 0x06,  174 /* Public */,
     142,    1,  660,    2, 0x06,  177 /* Public */,
     145,    1,  663,    2, 0x06,  179 /* Public */,
     148,    1,  666,    2, 0x06,  181 /* Public */,
     151,    1,  669,    2, 0x06,  183 /* Public */,
     154,    1,  672,    2, 0x06,  185 /* Public */,
     157,    1,  675,    2, 0x06,  187 /* Public */,
     160,    4,  678,    2, 0x06,  189 /* Public */,
     163,    1,  687,    2, 0x06,  194 /* Public */,
     166,    0,  690,    2, 0x06,  196 /* Public */,
     167,    2,  691,    2, 0x06,  197 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
     170,    3,  696,    2, 0x08,  200 /* Private */,
     172,    0,  703,    2, 0x08,  204 /* Private */,
     173,    1,  704,    2, 0x08,  205 /* Private */,
     175,    3,  707,    2, 0x08,  207 /* Private */,
     176,    4,  714,    2, 0x08,  211 /* Private */,
     181,    1,  723,    2, 0x08,  216 /* Private */,
     182,    2,  726,    2, 0x08,  218 /* Private */,
     185,    1,  731,    2, 0x08,  221 /* Private */,
     187,    2,  734,    2, 0x08,  223 /* Private */,
     190,    2,  739,    2, 0x08,  226 /* Private */,
     191,    0,  744,    2, 0x08,  229 /* Private */,
     192,    0,  745,    2, 0x08,  230 /* Private */,
     193,    0,  746,    2, 0x08,  231 /* Private */,
     194,    3,  747,    2, 0x08,  232 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::UShort, 0x80000000 | 6,    4,    5,    7,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString, QMetaType::QString,   10,   11,   12,
    QMetaType::Void, 0x80000000 | 14, QMetaType::QString, QMetaType::QString,   15,   11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 21, QMetaType::QString, 0x80000000 | 24,   19,   20,   22,   23,   25,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 27, QMetaType::QString, 0x80000000 | 24,   19,   20,   28,   23,   25,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 21, QMetaType::QString,   19,   20,   22,   30,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 27, QMetaType::QString,   19,   20,   32,   30,
    QMetaType::Void, 0x80000000 | 24, QMetaType::QString,   25,   34,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   19,   36,   37,   12,
    QMetaType::Void, 0x80000000 | 39, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 60, 0x80000000 | 27, 0x80000000 | 24,   40,   41,   42,   43,   44,   45,   46,   47,   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,   61,   62,   63,
    QMetaType::Void, 0x80000000 | 39, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, QMetaType::QString, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 60, 0x80000000 | 27, 0x80000000 | 24,   40,   41,   42,   43,   44,   45,   46,   65,   66,   67,   47,   48,   49,   50,   51,   53,   68,   69,   54,   70,   71,   72,   73,   74,   75,   76,   58,   59,   61,   62,   63,
    QMetaType::Void, 0x80000000 | 39, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24,   40,   41,   42,   43,   78,   79,   80,   81,   82,   83,   84,   85,   86,   87,   88,   63,
    QMetaType::Void, 0x80000000 | 39, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24,   40,   41,   42,   43,   78,   79,   80,   90,   63,
    QMetaType::Void, 0x80000000 | 39, 0x80000000 | 93,   92,   94,
    QMetaType::Void, 0x80000000 | 96, QMetaType::QStringList, QMetaType::QStringList, 0x80000000 | 24,   97,   98,   99,  100,
    QMetaType::Void, 0x80000000 | 102, QMetaType::QString, QMetaType::QString, 0x80000000 | 24,  103,   98,   99,  100,
    QMetaType::Void, 0x80000000 | 105, 0x80000000 | 107,  106,  108,
    QMetaType::Void, 0x80000000 | 105, 0x80000000 | 110,  106,  111,
    QMetaType::Void, 0x80000000 | 105, 0x80000000 | 113,  106,  114,
    QMetaType::Void, 0x80000000 | 105, 0x80000000 | 116,  106,  117,
    QMetaType::Void, 0x80000000 | 105, 0x80000000 | 119,  106,  120,
    QMetaType::Void, 0x80000000 | 105, 0x80000000 | 122,  106,  123,
    QMetaType::Void, 0x80000000 | 105, 0x80000000 | 125,  106,  126,
    QMetaType::Void, 0x80000000 | 105, 0x80000000 | 128,  106,  129,
    QMetaType::Void, 0x80000000 | 105, 0x80000000 | 131,  106,  132,
    QMetaType::Void, 0x80000000 | 105, 0x80000000 | 134,  106,  135,
    QMetaType::Void, 0x80000000 | 105, 0x80000000 | 137,  106,  138,
    QMetaType::Void, 0x80000000 | 105, 0x80000000 | 140,  106,  141,
    QMetaType::Void, 0x80000000 | 143,  144,
    QMetaType::Void, 0x80000000 | 146,  147,
    QMetaType::Void, 0x80000000 | 149,  150,
    QMetaType::Void, 0x80000000 | 152,  153,
    QMetaType::Void, 0x80000000 | 155,  156,
    QMetaType::Void, 0x80000000 | 158,  159,
    QMetaType::Void, 0x80000000 | 105, 0x80000000 | 27, QMetaType::QByteArray, 0x80000000 | 24,  106,  161,  162,   63,
    QMetaType::Void, 0x80000000 | 164,  165,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,  168,  169,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::UShort, QMetaType::QByteArray,    4,    5,  171,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  174,
    QMetaType::Void, 0x80000000 | 3, QMetaType::UShort, QMetaType::QByteArray,    4,    5,  171,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QString, QMetaType::Bool,  177,  178,  179,  180,
    QMetaType::Void, 0x80000000 | 93,   94,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,  183,  184,
    QMetaType::Void, QMetaType::UChar,  186,
    QMetaType::Void, QMetaType::UChar, QMetaType::QByteArray,  188,  189,
    QMetaType::Void, QMetaType::UChar, QMetaType::QByteArray,  188,  189,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Bool,  195,  196,  197,

       0        // eod
};

void nmsMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<nmsMainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SigSendAckNMStoKavach((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<stNMStoKavach*>>(_a[3]))); break;
        case 1: _t->SigFaultPktInserttoDB((*reinterpret_cast< std::add_pointer_t<stKavachtoNMS*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 2: _t->SigStnFaultPktInserttoDB((*reinterpret_cast< std::add_pointer_t<stStationFaults*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 3: _t->SigStationInfo(); break;
        case 4: _t->SigLocoInfo(); break;
        case 5: _t->SigFaultMsginserttoDB((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<uint16_t>>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[5]))); break;
        case 6: _t->SigStnFaultMsginserttoDB((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[5]))); break;
        case 7: _t->SigSMSFaultMsginserttoDB((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<uint16_t>>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 8: _t->SigSMSStnFaultMsginserttoDB((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 9: _t->SigSendSMS((*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 10: _t->SigSendFaultmessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 11: _t->SigAccessReqInsertintoDB((*reinterpret_cast< std::add_pointer_t<stAccessRequestPkt>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[13])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[14])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[15])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[16])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[17])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[18])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[19])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[20])),(*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[21])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[22])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[23]))); break;
        case 12: _t->SigLocoRegularInsertintoDB((*reinterpret_cast< std::add_pointer_t<stAccessRequestPkt>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[13])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[14])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[15])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[16])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[17])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[18])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[19])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[20])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[21])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[22])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[23])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[24])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[25])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[26])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[27])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[28])),(*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[29])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[30])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[31]))); break;
        case 13: _t->SigAccessAuthorityPktInsertintoDB((*reinterpret_cast< std::add_pointer_t<stAccessRequestPkt>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[13])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[14])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[15])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[16]))); break;
        case 14: _t->SigAdditionalEmergencyPktInsertintoDB((*reinterpret_cast< std::add_pointer_t<stAccessRequestPkt>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[9]))); break;
        case 15: _t->SigInsertDBStationRegHeader((*reinterpret_cast< std::add_pointer_t<stAccessRequestPkt>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<StationRegularHeader>>(_a[2]))); break;
        case 16: _t->SigInsertDBStationhealthPkt((*reinterpret_cast< std::add_pointer_t<stStationHealthPkt>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4]))); break;
        case 17: _t->SigInsertDBOnBoardhealthPkt((*reinterpret_cast< std::add_pointer_t<stOnBoardHealthPkt>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4]))); break;
        case 18: _t->SigInsertDBS2SPDIVerCmd((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stPDIVerCheckCmdPkt>>(_a[2]))); break;
        case 19: _t->SigInsertDBS2SPDIVerMsg((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stPDIVerCheckMsgPkt>>(_a[2]))); break;
        case 20: _t->SigInsertDBS2SHeartBeat((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stHeartBeatPkt>>(_a[2]))); break;
        case 21: _t->SigInsertDBS2STrainHandOverReq((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTrainHandOverReqPkt>>(_a[2]))); break;
        case 22: _t->SigInsertDBS2STrainTakenOverMsg((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTrainTakenOverPkt>>(_a[2]))); break;
        case 23: _t->SigInsertDBS2STrainHandOverCancellationReq((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTrainHandOverCancellationPkt>>(_a[2]))); break;
        case 24: _t->SigInsertDBS2STrainLengthInformationReq((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTrainLengthInfoPkt>>(_a[2]))); break;
        case 25: _t->SigInsertDBS2SLengthInformationAck((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTrainLengthInfoAck>>(_a[2]))); break;
        case 26: _t->SigInsertDBS2STSLRouteRequest((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTSLReqPkt>>(_a[2]))); break;
        case 27: _t->SigInsertDBS2STSLAuthorityInformationPkt((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTSLInformationPkt>>(_a[2]))); break;
        case 28: _t->SigInsertDBS2SFieldElementsStatusReq((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stFieldElementsStatusReqPkt>>(_a[2]))); break;
        case 29: _t->SigInsertDBS2STrainHandoverCancellationAck((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<stTrainHandOverCancellationAckPkt>>(_a[2]))); break;
        case 30: _t->SigInsertDBLocoRSSIMessage((*reinterpret_cast< std::add_pointer_t<stLocoRSSIMsg>>(_a[1]))); break;
        case 31: _t->SigInsertDBStationRSSIMessage((*reinterpret_cast< std::add_pointer_t<stStationRSSIMsg>>(_a[1]))); break;
        case 32: _t->SigInsertDBStationKavachSysSts((*reinterpret_cast< std::add_pointer_t<stStationaryKavachSysInfo>>(_a[1]))); break;
        case 33: _t->SigInsertDBOnBoardEventMessage((*reinterpret_cast< std::add_pointer_t<stOnboardKavachEventMsg>>(_a[1]))); break;
        case 34: _t->SigInsertDBOnBoardBrakeEventMsg((*reinterpret_cast< std::add_pointer_t<stOnboardKavachBrakeEventMsg>>(_a[1]))); break;
        case 35: _t->SigInsertDBOnBoardSystemHealthMsg((*reinterpret_cast< std::add_pointer_t<stOnboardKavachBOKSHealthMsg>>(_a[1]))); break;
        case 36: _t->SigInsertDBFieldInputStatus((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4]))); break;
        case 37: _t->SigInsertDBFieldInputEventData((*reinterpret_cast< std::add_pointer_t<stFieldEventData>>(_a[1]))); break;
        case 38: _t->SigShowAllStations(); break;
        case 39: _t->SigStationisConnected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 40: _t->SlotNewFaultPacket((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[3]))); break;
        case 41: _t->SlotPreviousFaultInfo(); break;
        case 42: _t->SlottabChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 43: _t->SlotUpadateSchematic((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[3]))); break;
        case 44: _t->SlotStationNameAndID((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 45: _t->SlotStationRegHeader((*reinterpret_cast< std::add_pointer_t<StationRegularHeader>>(_a[1]))); break;
        case 46: _t->SlotStationconnStatus((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 47: _t->SlotKMSChannelChangeover((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1]))); break;
        case 48: _t->SlotKMSPacketReceived((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 49: _t->SlotKMSPacketSent((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 50: _t->SlotDoPing(); break;
        case 51: _t->SlotSendNextReplayPacket(); break;
        case 52: _t->SlotVCHeartbeat(); break;
        case 53: _t->SlotGPSPosition((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stAccessRequestPkt >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stAccessRequestPkt >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stAccessRequestPkt >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stAccessRequestPkt >(); break;
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
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stStationHealthPkt >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stOnBoardHealthPkt >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPDIVerCheckCmdPkt >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            }
            break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPDIVerCheckMsgPkt >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            }
            break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stHeartBeatPkt >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            }
            break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTrainHandOverReqPkt >(); break;
            }
            break;
        case 22:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTrainTakenOverPkt >(); break;
            }
            break;
        case 23:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTrainHandOverCancellationPkt >(); break;
            }
            break;
        case 24:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTrainLengthInfoPkt >(); break;
            }
            break;
        case 25:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTrainLengthInfoAck >(); break;
            }
            break;
        case 26:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTSLReqPkt >(); break;
            }
            break;
        case 27:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTSLInformationPkt >(); break;
            }
            break;
        case 28:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stFieldElementsStatusReqPkt >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            }
            break;
        case 29:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stTrainHandOverCancellationAckPkt >(); break;
            }
            break;
        case 30:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stLocoRSSIMsg >(); break;
            }
            break;
        case 31:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stStationRSSIMsg >(); break;
            }
            break;
        case 32:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stStationaryKavachSysInfo >(); break;
            }
            break;
        case 33:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stOnboardKavachEventMsg >(); break;
            }
            break;
        case 35:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stOnboardKavachBOKSHealthMsg >(); break;
            }
            break;
        case 36:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            }
            break;
        case 37:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stFieldEventData >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (nmsMainWindow::*)(QHostAddress , quint16 , stNMStoKavach * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigSendAckNMStoKavach)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stKavachtoNMS * , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigFaultPktInserttoDB)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stStationFaults * , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigStnFaultPktInserttoDB)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigStationInfo)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigLocoInfo)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(QString , QString , QList<uint16_t> , QString , uint32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigFaultMsginserttoDB)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(QString , QString , uint16_t , QString , uint32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigStnFaultMsginserttoDB)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(QString , QString , QList<uint16_t> , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigSMSFaultMsginserttoDB)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(QString , QString , uint16_t , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigSMSStnFaultMsginserttoDB)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(uint32_t , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigSendSMS)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigSendFaultmessage)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stAccessRequestPkt , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint8_t , uint16_t , uint32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigAccessReqInsertintoDB)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stAccessRequestPkt , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , QString , uint32_t , uint32_t , uint8_t , uint16_t , uint32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigLocoRegularInsertintoDB)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stAccessRequestPkt , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigAccessAuthorityPktInsertintoDB)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stAccessRequestPkt , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigAdditionalEmergencyPktInsertintoDB)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stAccessRequestPkt , StationRegularHeader );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBStationRegHeader)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stStationHealthPkt , QStringList , QStringList , uint32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBStationhealthPkt)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stOnBoardHealthPkt , QString , QString , uint32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBOnBoardhealthPkt)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stPDIVerCheckCmdPkt );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBS2SPDIVerCmd)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stPDIVerCheckMsgPkt );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBS2SPDIVerMsg)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stHeartBeatPkt );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBS2SHeartBeat)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stTrainHandOverReqPkt );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBS2STrainHandOverReq)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stTrainTakenOverPkt );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBS2STrainTakenOverMsg)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stTrainHandOverCancellationPkt );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBS2STrainHandOverCancellationReq)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stTrainLengthInfoPkt );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBS2STrainLengthInformationReq)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stTrainLengthInfoAck );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBS2SLengthInformationAck)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stTSLReqPkt );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBS2STSLRouteRequest)) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stTSLInformationPkt );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBS2STSLAuthorityInformationPkt)) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stFieldElementsStatusReqPkt );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBS2SFieldElementsStatusReq)) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stTrainHandOverCancellationAckPkt );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBS2STrainHandoverCancellationAck)) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stLocoRSSIMsg );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBLocoRSSIMessage)) {
                *result = 30;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stStationRSSIMsg );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBStationRSSIMessage)) {
                *result = 31;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stStationaryKavachSysInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBStationKavachSysSts)) {
                *result = 32;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stOnboardKavachEventMsg );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBOnBoardEventMessage)) {
                *result = 33;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stOnboardKavachBrakeEventMsg );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBOnBoardBrakeEventMsg)) {
                *result = 34;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stOnboardKavachBOKSHealthMsg );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBOnBoardSystemHealthMsg)) {
                *result = 35;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , uint16_t , QByteArray , uint32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBFieldInputStatus)) {
                *result = 36;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stFieldEventData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigInsertDBFieldInputEventData)) {
                *result = 37;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigShowAllStations)) {
                *result = 38;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsMainWindow::SigStationisConnected)) {
                *result = 39;
                return;
            }
        }
    }
}

const QMetaObject nmsMainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_nmsMainWindow.offsetsAndSize,
    qt_meta_data_nmsMainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_nmsMainWindow_t
, QtPrivate::TypeAndForceComplete<nmsMainWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<stNMStoKavach *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stKavachtoNMS *, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stStationFaults *, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QList<uint16_t>, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QList<uint16_t>, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>, QtPrivate::TypeAndForceComplete<StationRegularHeader, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stStationHealthPkt, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stOnBoardHealthPkt, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stPDIVerCheckCmdPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stPDIVerCheckMsgPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stHeartBeatPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainHandOverReqPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainTakenOverPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainHandOverCancellationPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainLengthInfoPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainLengthInfoAck, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTSLReqPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTSLInformationPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stFieldElementsStatusReqPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<stTrainHandOverCancellationAckPkt, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stLocoRSSIMsg, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stStationRSSIMsg, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stStationaryKavachSysInfo, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stOnboardKavachEventMsg, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stOnboardKavachBrakeEventMsg, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stOnboardKavachBOKSHealthMsg, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<stFieldEventData, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<StationRegularHeader, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<quint8, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<quint8, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<quint8, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *nmsMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nmsMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_nmsMainWindow.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int nmsMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 54)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 54;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 54)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 54;
    }
    return _id;
}

// SIGNAL 0
void nmsMainWindow::SigSendAckNMStoKavach(QHostAddress _t1, quint16 _t2, stNMStoKavach * _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void nmsMainWindow::SigFaultPktInserttoDB(stKavachtoNMS * _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void nmsMainWindow::SigStnFaultPktInserttoDB(stStationFaults * _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void nmsMainWindow::SigStationInfo()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void nmsMainWindow::SigLocoInfo()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void nmsMainWindow::SigFaultMsginserttoDB(QString _t1, QString _t2, QList<uint16_t> _t3, QString _t4, uint32_t _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void nmsMainWindow::SigStnFaultMsginserttoDB(QString _t1, QString _t2, uint16_t _t3, QString _t4, uint32_t _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void nmsMainWindow::SigSMSFaultMsginserttoDB(QString _t1, QString _t2, QList<uint16_t> _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void nmsMainWindow::SigSMSStnFaultMsginserttoDB(QString _t1, QString _t2, uint16_t _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void nmsMainWindow::SigSendSMS(uint32_t _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void nmsMainWindow::SigSendFaultmessage(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void nmsMainWindow::SigAccessReqInsertintoDB(stAccessRequestPkt _t1, uint32_t _t2, uint32_t _t3, uint32_t _t4, uint32_t _t5, uint32_t _t6, uint32_t _t7, uint32_t _t8, uint32_t _t9, uint32_t _t10, uint32_t _t11, uint32_t _t12, uint32_t _t13, uint32_t _t14, uint32_t _t15, uint32_t _t16, uint32_t _t17, uint32_t _t18, uint32_t _t19, uint32_t _t20, uint8_t _t21, uint16_t _t22, uint32_t _t23)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t10))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t11))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t12))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t13))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t14))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t15))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t16))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t17))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t18))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t19))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t20))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t21))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t22))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t23))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void nmsMainWindow::SigLocoRegularInsertintoDB(stAccessRequestPkt _t1, uint32_t _t2, uint32_t _t3, uint32_t _t4, uint32_t _t5, uint32_t _t6, uint32_t _t7, uint32_t _t8, uint32_t _t9, uint32_t _t10, uint32_t _t11, uint32_t _t12, uint32_t _t13, uint32_t _t14, uint32_t _t15, uint32_t _t16, uint32_t _t17, uint32_t _t18, uint32_t _t19, uint32_t _t20, uint32_t _t21, uint32_t _t22, uint32_t _t23, uint32_t _t24, uint32_t _t25, QString _t26, uint32_t _t27, uint32_t _t28, uint8_t _t29, uint16_t _t30, uint32_t _t31)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t10))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t11))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t12))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t13))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t14))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t15))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t16))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t17))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t18))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t19))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t20))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t21))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t22))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t23))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t24))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t25))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t26))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t27))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t28))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t29))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t30))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t31))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void nmsMainWindow::SigAccessAuthorityPktInsertintoDB(stAccessRequestPkt _t1, uint32_t _t2, uint32_t _t3, uint32_t _t4, uint32_t _t5, uint32_t _t6, uint32_t _t7, uint32_t _t8, uint32_t _t9, uint32_t _t10, uint32_t _t11, uint32_t _t12, uint32_t _t13, uint32_t _t14, uint32_t _t15, uint32_t _t16)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t10))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t11))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t12))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t13))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t14))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t15))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t16))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void nmsMainWindow::SigAdditionalEmergencyPktInsertintoDB(stAccessRequestPkt _t1, uint32_t _t2, uint32_t _t3, uint32_t _t4, uint32_t _t5, uint32_t _t6, uint32_t _t7, uint32_t _t8, uint32_t _t9)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void nmsMainWindow::SigInsertDBStationRegHeader(stAccessRequestPkt _t1, StationRegularHeader _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void nmsMainWindow::SigInsertDBStationhealthPkt(stStationHealthPkt _t1, QStringList _t2, QStringList _t3, uint32_t _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void nmsMainWindow::SigInsertDBOnBoardhealthPkt(stOnBoardHealthPkt _t1, QString _t2, QString _t3, uint32_t _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void nmsMainWindow::SigInsertDBS2SPDIVerCmd(stPacketHeader _t1, stPDIVerCheckCmdPkt _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void nmsMainWindow::SigInsertDBS2SPDIVerMsg(stPacketHeader _t1, stPDIVerCheckMsgPkt _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void nmsMainWindow::SigInsertDBS2SHeartBeat(stPacketHeader _t1, stHeartBeatPkt _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void nmsMainWindow::SigInsertDBS2STrainHandOverReq(stPacketHeader _t1, stTrainHandOverReqPkt _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void nmsMainWindow::SigInsertDBS2STrainTakenOverMsg(stPacketHeader _t1, stTrainTakenOverPkt _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void nmsMainWindow::SigInsertDBS2STrainHandOverCancellationReq(stPacketHeader _t1, stTrainHandOverCancellationPkt _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void nmsMainWindow::SigInsertDBS2STrainLengthInformationReq(stPacketHeader _t1, stTrainLengthInfoPkt _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void nmsMainWindow::SigInsertDBS2SLengthInformationAck(stPacketHeader _t1, stTrainLengthInfoAck _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void nmsMainWindow::SigInsertDBS2STSLRouteRequest(stPacketHeader _t1, stTSLReqPkt _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void nmsMainWindow::SigInsertDBS2STSLAuthorityInformationPkt(stPacketHeader _t1, stTSLInformationPkt _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void nmsMainWindow::SigInsertDBS2SFieldElementsStatusReq(stPacketHeader _t1, stFieldElementsStatusReqPkt _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void nmsMainWindow::SigInsertDBS2STrainHandoverCancellationAck(stPacketHeader _t1, stTrainHandOverCancellationAckPkt _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void nmsMainWindow::SigInsertDBLocoRSSIMessage(stLocoRSSIMsg _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 30, _a);
}

// SIGNAL 31
void nmsMainWindow::SigInsertDBStationRSSIMessage(stStationRSSIMsg _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}

// SIGNAL 32
void nmsMainWindow::SigInsertDBStationKavachSysSts(stStationaryKavachSysInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 32, _a);
}

// SIGNAL 33
void nmsMainWindow::SigInsertDBOnBoardEventMessage(stOnboardKavachEventMsg _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 33, _a);
}

// SIGNAL 34
void nmsMainWindow::SigInsertDBOnBoardBrakeEventMsg(stOnboardKavachBrakeEventMsg _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 34, _a);
}

// SIGNAL 35
void nmsMainWindow::SigInsertDBOnBoardSystemHealthMsg(stOnboardKavachBOKSHealthMsg _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 35, _a);
}

// SIGNAL 36
void nmsMainWindow::SigInsertDBFieldInputStatus(stPacketHeader _t1, uint16_t _t2, QByteArray _t3, uint32_t _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 36, _a);
}

// SIGNAL 37
void nmsMainWindow::SigInsertDBFieldInputEventData(stFieldEventData _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 37, _a);
}

// SIGNAL 38
void nmsMainWindow::SigShowAllStations()
{
    QMetaObject::activate(this, &staticMetaObject, 38, nullptr);
}

// SIGNAL 39
void nmsMainWindow::SigStationisConnected(QString _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 39, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
