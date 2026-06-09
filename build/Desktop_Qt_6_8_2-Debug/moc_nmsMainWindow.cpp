/****************************************************************************
** Meta object code from reading C++ file 'nmsMainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/nmsMainWindow.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nmsMainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN13nmsMainWindowE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN13nmsMainWindowE = QtMocHelpers::stringData(
    "nmsMainWindow",
    "SigSendAckNMStoKavach",
    "",
    "QHostAddress",
    "senderIP",
    "senderPort",
    "stNMStoKavach*",
    "pstAck",
    "SigFaultPktInserttoDB",
    "stKavachtoNMS*",
    "pstKavachtoNMS",
    "strFaultsCode",
    "strFaultMsg",
    "SigStnFaultPktInserttoDB",
    "stStationFaults*",
    "pstStnFaults",
    "strLstModuleID",
    "strLstFaultCodeTyp",
    "SigStationInfo",
    "SigLocoInfo",
    "SigFaultMsginserttoDB",
    "strMsgType",
    "strTimestamp",
    "QList<uint16_t>",
    "faultByteArray",
    "strFirmNam",
    "uint32_t",
    "uiID",
    "SigStnFaultMsginserttoDB",
    "uint16_t",
    "usFaultCode",
    "SigSMSFaultMsginserttoDB",
    "strFirmNamID",
    "SigSMSStnFaultMsginserttoDB",
    "usFaultCOde",
    "SigSendSMS",
    "message",
    "SigSendFaultmessage",
    "strTimeStamp",
    "strFirmid",
    "SigAccessReqInsertintoDB",
    "stAccessRequestPkt",
    "stheader",
    "uiPktType",
    "uiPktLen",
    "uiFrmNo",
    "uiSrcLocoID",
    "uiSrcLocoVer",
    "uiAbsLoco_Loc",
    "uiTrainLen",
    "uiTrainSpd",
    "uiMovMntDir",
    "uiEmergencySts",
    "uiLocoMode",
    "uiApprStID",
    "uiLastRfidTag",
    "uitinNo",
    "uiLongitude",
    "uiLatitude",
    "uiLocoRandmrl",
    "uiMACCode",
    "uiPktCRC",
    "uint8_t",
    "ucMASecCnt",
    "usRouteID",
    "uiCRC",
    "SigLocoRegularInsertintoDB",
    "uidoubtover",
    "uidoubtunder",
    "uitrainint",
    "uiTagDup",
    "uitagLinkInfo",
    "uiBrkApply",
    "uinewMAReply",
    "uiLastRefProfNo",
    "uiSigOV",
    "uiInfoAck",
    "uiSpare",
    "strLocoHlthSts",
    "SigAccessAuthorityPktInsertintoDB",
    "uiSrcStnILCIBS_ID",
    "uiSRCStnILCIBS_ver",
    "uiStnILCIBS_Loc",
    "uiDestLoco_ID",
    "uiAlotUpLnk_Freq",
    "uiAlotDnLnk_Freq",
    "uiAlotTDMA_Timeslots",
    "uiStnRndNum_RS",
    "uiStnTDMA",
    "uiMAC_Code",
    "uiPktCrc",
    "SigAdditionalEmergencyPktInsertintoDB",
    "uiGenSoSCall",
    "SigInsertDBStationRegHeader",
    "stHeader",
    "StationRegularHeader",
    "stStnRglrHPkt",
    "SigInsertDBStationhealthPkt",
    "stStationHealthPkt",
    "stStnHlthPkt",
    "strEvntID",
    "strEvntData",
    "uiCrc",
    "SigInsertDBOnBoardhealthPkt",
    "stOnBoardHealthPkt",
    "stOnBrdHlthPkt",
    "SigInsertDBS2SPDIVerCmd",
    "stPacketHeader",
    "stPktHdr",
    "stPDIVerCheckCmdPkt",
    "stPDIVerCmd",
    "SigInsertDBS2SPDIVerMsg",
    "stPDIVerCheckMsgPkt",
    "stPDIVerMsg",
    "SigInsertDBS2SHeartBeat",
    "stHeartBeatPkt",
    "stHeartBeat",
    "SigInsertDBS2STrainHandOverReq",
    "stTrainHandOverReqPkt",
    "stTrnHndOveReq",
    "SigInsertDBS2STrainTakenOverMsg",
    "stTrainTakenOverPkt",
    "stTrnTknOveMsg",
    "SigInsertDBS2STrainHandOverCancellationReq",
    "stTrainHandOverCancellationPkt",
    "stTrnHndOvrCnclPkt",
    "SigInsertDBS2STrainLengthInformationReq",
    "stTrainLengthInfoPkt",
    "stTrnLenInfoPkt",
    "SigInsertDBS2SLengthInformationAck",
    "stTrainLengthInfoAck",
    "stTrnLenInfoAck",
    "SigInsertDBS2STSLRouteRequest",
    "stTSLReqPkt",
    "stTSLRouteReq",
    "SigInsertDBS2STSLAuthorityInformationPkt",
    "stTSLInformationPkt",
    "stTSLInfoPkt",
    "SigInsertDBS2SFieldElementsStatusReq",
    "stFieldElementsStatusReqPkt",
    "stFldElementStsReq",
    "SigInsertDBS2STrainHandoverCancellationAck",
    "stTrainHandOverCancellationAckPkt",
    "stTrnHndOvrCnclAck",
    "SigInsertDBLocoRSSIMessage",
    "stLocoRSSIMsg",
    "stLocoRSSI",
    "SigInsertDBStationRSSIMessage",
    "stStationRSSIMsg",
    "stStnRSSI",
    "SigInsertDBStationKavachSysSts",
    "stStationaryKavachSysInfo",
    "stStnKavchSysSts",
    "SigInsertDBOnBoardEventMessage",
    "stOnboardKavachEventMsg",
    "stOnBoardEventMsg",
    "SigInsertDBOnBoardBrakeEventMsg",
    "stOnboardKavachBrakeEventMsg",
    "stOnBoardBrakeEvntMsg",
    "SigInsertDBOnBoardSystemHealthMsg",
    "stOnboardKavachBOKSHealthMsg",
    "stOnBoardSysHealth",
    "SigInsertDBFieldInputStatus",
    "usRelayCnt",
    "byArrRelayImage",
    "SigInsertDBFieldInputEventData",
    "stFieldEventData",
    "stFldEvntData",
    "SigShowAllStations",
    "SigStationisConnected",
    "strStationName",
    "bstatus",
    "SlotNewFaultPacket",
    "datagram",
    "SlotPreviousFaultInfo",
    "SlottabChanged",
    "index",
    "SlotUpadateSchematic",
    "SlotStationNameAndID",
    "strLstStationID",
    "strLstStationNames",
    "strDateTime",
    "bStationSts",
    "SlotStationRegHeader",
    "SlotStationconnStatus",
    "strHostAddr",
    "bStatus",
    "SlotKMSChannelChangeover",
    "newSimID",
    "SlotKMSPacketReceived",
    "msgType",
    "packet",
    "SlotKMSPacketSent",
    "SlotDoPing",
    "SlotSendNextReplayPacket",
    "SlotVCHeartbeat",
    "SlotGPSPosition",
    "dLat",
    "dLon",
    "bValid"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN13nmsMainWindowE[] = {

 // content:
      12,       // revision
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
      13,    5,  352,    2, 0x06,    9 /* Public */,
      18,    0,  363,    2, 0x06,   15 /* Public */,
      19,    0,  364,    2, 0x06,   16 /* Public */,
      20,    5,  365,    2, 0x06,   17 /* Public */,
      28,    5,  376,    2, 0x06,   23 /* Public */,
      31,    4,  387,    2, 0x06,   29 /* Public */,
      33,    4,  396,    2, 0x06,   34 /* Public */,
      35,    2,  405,    2, 0x06,   39 /* Public */,
      37,    4,  410,    2, 0x06,   42 /* Public */,
      40,   23,  419,    2, 0x06,   47 /* Public */,
      66,   31,  466,    2, 0x06,   71 /* Public */,
      79,   16,  529,    2, 0x06,  103 /* Public */,
      91,    9,  562,    2, 0x06,  120 /* Public */,
      93,    2,  581,    2, 0x06,  130 /* Public */,
      97,    4,  586,    2, 0x06,  133 /* Public */,
     103,    4,  595,    2, 0x06,  138 /* Public */,
     106,    2,  604,    2, 0x06,  143 /* Public */,
     111,    2,  609,    2, 0x06,  146 /* Public */,
     114,    2,  614,    2, 0x06,  149 /* Public */,
     117,    2,  619,    2, 0x06,  152 /* Public */,
     120,    2,  624,    2, 0x06,  155 /* Public */,
     123,    2,  629,    2, 0x06,  158 /* Public */,
     126,    2,  634,    2, 0x06,  161 /* Public */,
     129,    2,  639,    2, 0x06,  164 /* Public */,
     132,    2,  644,    2, 0x06,  167 /* Public */,
     135,    2,  649,    2, 0x06,  170 /* Public */,
     138,    2,  654,    2, 0x06,  173 /* Public */,
     141,    2,  659,    2, 0x06,  176 /* Public */,
     144,    1,  664,    2, 0x06,  179 /* Public */,
     147,    1,  667,    2, 0x06,  181 /* Public */,
     150,    1,  670,    2, 0x06,  183 /* Public */,
     153,    1,  673,    2, 0x06,  185 /* Public */,
     156,    1,  676,    2, 0x06,  187 /* Public */,
     159,    1,  679,    2, 0x06,  189 /* Public */,
     162,    4,  682,    2, 0x06,  191 /* Public */,
     165,    1,  691,    2, 0x06,  196 /* Public */,
     168,    0,  694,    2, 0x06,  198 /* Public */,
     169,    2,  695,    2, 0x06,  199 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
     172,    3,  700,    2, 0x08,  202 /* Private */,
     174,    0,  707,    2, 0x08,  206 /* Private */,
     175,    1,  708,    2, 0x08,  207 /* Private */,
     177,    3,  711,    2, 0x08,  209 /* Private */,
     178,    4,  718,    2, 0x08,  213 /* Private */,
     183,    1,  727,    2, 0x08,  218 /* Private */,
     184,    2,  730,    2, 0x08,  220 /* Private */,
     187,    1,  735,    2, 0x08,  223 /* Private */,
     189,    2,  738,    2, 0x08,  225 /* Private */,
     192,    2,  743,    2, 0x08,  228 /* Private */,
     193,    0,  748,    2, 0x08,  231 /* Private */,
     194,    0,  749,    2, 0x08,  232 /* Private */,
     195,    0,  750,    2, 0x08,  233 /* Private */,
     196,    3,  751,    2, 0x08,  234 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::UShort, 0x80000000 | 6,    4,    5,    7,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString, QMetaType::QString,   10,   11,   12,
    QMetaType::Void, 0x80000000 | 14, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList,   15,   16,   17,   11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 23, QMetaType::QString, 0x80000000 | 26,   21,   22,   24,   25,   27,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 29, QMetaType::QString, 0x80000000 | 26,   21,   22,   30,   25,   27,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 23, QMetaType::QString,   21,   22,   24,   32,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 29, QMetaType::QString,   21,   22,   34,   32,
    QMetaType::Void, 0x80000000 | 26, QMetaType::QString,   27,   36,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   21,   38,   39,   12,
    QMetaType::Void, 0x80000000 | 41, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 62, 0x80000000 | 29, 0x80000000 | 26,   42,   43,   44,   45,   46,   47,   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,   63,   64,   65,
    QMetaType::Void, 0x80000000 | 41, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, QMetaType::QString, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 62, 0x80000000 | 29, 0x80000000 | 26,   42,   43,   44,   45,   46,   47,   48,   67,   68,   69,   49,   50,   51,   52,   53,   55,   70,   71,   56,   72,   73,   74,   75,   76,   77,   78,   60,   61,   63,   64,   65,
    QMetaType::Void, 0x80000000 | 41, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26,   42,   43,   44,   45,   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,   90,   65,
    QMetaType::Void, 0x80000000 | 41, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 26,   42,   43,   44,   45,   80,   81,   82,   92,   65,
    QMetaType::Void, 0x80000000 | 41, 0x80000000 | 95,   94,   96,
    QMetaType::Void, 0x80000000 | 98, QMetaType::QStringList, QMetaType::QStringList, 0x80000000 | 26,   99,  100,  101,  102,
    QMetaType::Void, 0x80000000 | 104, QMetaType::QString, QMetaType::QString, 0x80000000 | 26,  105,  100,  101,  102,
    QMetaType::Void, 0x80000000 | 107, 0x80000000 | 109,  108,  110,
    QMetaType::Void, 0x80000000 | 107, 0x80000000 | 112,  108,  113,
    QMetaType::Void, 0x80000000 | 107, 0x80000000 | 115,  108,  116,
    QMetaType::Void, 0x80000000 | 107, 0x80000000 | 118,  108,  119,
    QMetaType::Void, 0x80000000 | 107, 0x80000000 | 121,  108,  122,
    QMetaType::Void, 0x80000000 | 107, 0x80000000 | 124,  108,  125,
    QMetaType::Void, 0x80000000 | 107, 0x80000000 | 127,  108,  128,
    QMetaType::Void, 0x80000000 | 107, 0x80000000 | 130,  108,  131,
    QMetaType::Void, 0x80000000 | 107, 0x80000000 | 133,  108,  134,
    QMetaType::Void, 0x80000000 | 107, 0x80000000 | 136,  108,  137,
    QMetaType::Void, 0x80000000 | 107, 0x80000000 | 139,  108,  140,
    QMetaType::Void, 0x80000000 | 107, 0x80000000 | 142,  108,  143,
    QMetaType::Void, 0x80000000 | 145,  146,
    QMetaType::Void, 0x80000000 | 148,  149,
    QMetaType::Void, 0x80000000 | 151,  152,
    QMetaType::Void, 0x80000000 | 154,  155,
    QMetaType::Void, 0x80000000 | 157,  158,
    QMetaType::Void, 0x80000000 | 160,  161,
    QMetaType::Void, 0x80000000 | 107, 0x80000000 | 29, QMetaType::QByteArray, 0x80000000 | 26,  108,  163,  164,   65,
    QMetaType::Void, 0x80000000 | 166,  167,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,  170,  171,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::UShort, QMetaType::QByteArray,    4,    5,  173,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  176,
    QMetaType::Void, 0x80000000 | 3, QMetaType::UShort, QMetaType::QByteArray,    4,    5,  173,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QString, QMetaType::Bool,  179,  180,  181,  182,
    QMetaType::Void, 0x80000000 | 95,   96,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,  185,  186,
    QMetaType::Void, QMetaType::UChar,  188,
    QMetaType::Void, QMetaType::UChar, QMetaType::QByteArray,  190,  191,
    QMetaType::Void, QMetaType::UChar, QMetaType::QByteArray,  190,  191,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Bool,  197,  198,  199,

       0        // eod
};

Q_CONSTINIT const QMetaObject nmsMainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN13nmsMainWindowE.offsetsAndSizes,
    qt_meta_data_ZN13nmsMainWindowE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN13nmsMainWindowE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<nmsMainWindow, std::true_type>,
        // method 'SigSendAckNMStoKavach'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>,
        QtPrivate::TypeAndForceComplete<stNMStoKavach *, std::false_type>,
        // method 'SigFaultPktInserttoDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stKavachtoNMS *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'SigStnFaultPktInserttoDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stStationFaults *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'SigStationInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SigLocoInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SigFaultMsginserttoDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<uint16_t>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        // method 'SigStnFaultMsginserttoDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        // method 'SigSMSFaultMsginserttoDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<uint16_t>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'SigSMSStnFaultMsginserttoDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'SigSendSMS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'SigSendFaultmessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'SigAccessReqInsertintoDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        // method 'SigLocoRegularInsertintoDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        // method 'SigAccessAuthorityPktInsertintoDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        // method 'SigAdditionalEmergencyPktInsertintoDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        // method 'SigInsertDBStationRegHeader'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>,
        QtPrivate::TypeAndForceComplete<StationRegularHeader, std::false_type>,
        // method 'SigInsertDBStationhealthPkt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stStationHealthPkt, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        // method 'SigInsertDBOnBoardhealthPkt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stOnBoardHealthPkt, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        // method 'SigInsertDBS2SPDIVerCmd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPDIVerCheckCmdPkt, std::false_type>,
        // method 'SigInsertDBS2SPDIVerMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPDIVerCheckMsgPkt, std::false_type>,
        // method 'SigInsertDBS2SHeartBeat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stHeartBeatPkt, std::false_type>,
        // method 'SigInsertDBS2STrainHandOverReq'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stTrainHandOverReqPkt, std::false_type>,
        // method 'SigInsertDBS2STrainTakenOverMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stTrainTakenOverPkt, std::false_type>,
        // method 'SigInsertDBS2STrainHandOverCancellationReq'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stTrainHandOverCancellationPkt, std::false_type>,
        // method 'SigInsertDBS2STrainLengthInformationReq'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stTrainLengthInfoPkt, std::false_type>,
        // method 'SigInsertDBS2SLengthInformationAck'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stTrainLengthInfoAck, std::false_type>,
        // method 'SigInsertDBS2STSLRouteRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stTSLReqPkt, std::false_type>,
        // method 'SigInsertDBS2STSLAuthorityInformationPkt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stTSLInformationPkt, std::false_type>,
        // method 'SigInsertDBS2SFieldElementsStatusReq'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stFieldElementsStatusReqPkt, std::false_type>,
        // method 'SigInsertDBS2STrainHandoverCancellationAck'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stTrainHandOverCancellationAckPkt, std::false_type>,
        // method 'SigInsertDBLocoRSSIMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stLocoRSSIMsg, std::false_type>,
        // method 'SigInsertDBStationRSSIMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stStationRSSIMsg, std::false_type>,
        // method 'SigInsertDBStationKavachSysSts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stStationaryKavachSysInfo, std::false_type>,
        // method 'SigInsertDBOnBoardEventMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stOnboardKavachEventMsg, std::false_type>,
        // method 'SigInsertDBOnBoardBrakeEventMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stOnboardKavachBrakeEventMsg, std::false_type>,
        // method 'SigInsertDBOnBoardSystemHealthMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stOnboardKavachBOKSHealthMsg, std::false_type>,
        // method 'SigInsertDBFieldInputStatus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        // method 'SigInsertDBFieldInputEventData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stFieldEventData, std::false_type>,
        // method 'SigShowAllStations'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SigStationisConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'SlotNewFaultPacket'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'SlotPreviousFaultInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SlottabChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SlotUpadateSchematic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'SlotStationNameAndID'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'SlotStationRegHeader'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<StationRegularHeader, std::false_type>,
        // method 'SlotStationconnStatus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'SlotKMSChannelChangeover'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        // method 'SlotKMSPacketReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'SlotKMSPacketSent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'SlotDoPing'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SlotSendNextReplayPacket'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SlotVCHeartbeat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SlotGPSPosition'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void nmsMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<nmsMainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->SigSendAckNMStoKavach((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<stNMStoKavach*>>(_a[3]))); break;
        case 1: _t->SigFaultPktInserttoDB((*reinterpret_cast< std::add_pointer_t<stKavachtoNMS*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 2: _t->SigStnFaultPktInserttoDB((*reinterpret_cast< std::add_pointer_t<stStationFaults*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[5]))); break;
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
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
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
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (nmsMainWindow::*)(QHostAddress , quint16 , stNMStoKavach * );
            if (_q_method_type _q_method = &nmsMainWindow::SigSendAckNMStoKavach; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stKavachtoNMS * , QString , QString );
            if (_q_method_type _q_method = &nmsMainWindow::SigFaultPktInserttoDB; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stStationFaults * , QStringList , QStringList , QStringList , QStringList );
            if (_q_method_type _q_method = &nmsMainWindow::SigStnFaultPktInserttoDB; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)();
            if (_q_method_type _q_method = &nmsMainWindow::SigStationInfo; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)();
            if (_q_method_type _q_method = &nmsMainWindow::SigLocoInfo; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(QString , QString , QList<uint16_t> , QString , uint32_t );
            if (_q_method_type _q_method = &nmsMainWindow::SigFaultMsginserttoDB; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(QString , QString , uint16_t , QString , uint32_t );
            if (_q_method_type _q_method = &nmsMainWindow::SigStnFaultMsginserttoDB; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(QString , QString , QList<uint16_t> , QString );
            if (_q_method_type _q_method = &nmsMainWindow::SigSMSFaultMsginserttoDB; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(QString , QString , uint16_t , QString );
            if (_q_method_type _q_method = &nmsMainWindow::SigSMSStnFaultMsginserttoDB; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(uint32_t , QString );
            if (_q_method_type _q_method = &nmsMainWindow::SigSendSMS; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(QString , QString , QString , QString );
            if (_q_method_type _q_method = &nmsMainWindow::SigSendFaultmessage; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stAccessRequestPkt , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint8_t , uint16_t , uint32_t );
            if (_q_method_type _q_method = &nmsMainWindow::SigAccessReqInsertintoDB; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stAccessRequestPkt , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , QString , uint32_t , uint32_t , uint8_t , uint16_t , uint32_t );
            if (_q_method_type _q_method = &nmsMainWindow::SigLocoRegularInsertintoDB; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stAccessRequestPkt , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t );
            if (_q_method_type _q_method = &nmsMainWindow::SigAccessAuthorityPktInsertintoDB; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stAccessRequestPkt , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t );
            if (_q_method_type _q_method = &nmsMainWindow::SigAdditionalEmergencyPktInsertintoDB; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stAccessRequestPkt , StationRegularHeader );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBStationRegHeader; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 15;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stStationHealthPkt , QStringList , QStringList , uint32_t );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBStationhealthPkt; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 16;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stOnBoardHealthPkt , QString , QString , uint32_t );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBOnBoardhealthPkt; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 17;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stPacketHeader , stPDIVerCheckCmdPkt );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBS2SPDIVerCmd; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 18;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stPacketHeader , stPDIVerCheckMsgPkt );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBS2SPDIVerMsg; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 19;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stPacketHeader , stHeartBeatPkt );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBS2SHeartBeat; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 20;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stPacketHeader , stTrainHandOverReqPkt );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBS2STrainHandOverReq; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 21;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stPacketHeader , stTrainTakenOverPkt );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBS2STrainTakenOverMsg; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 22;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stPacketHeader , stTrainHandOverCancellationPkt );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBS2STrainHandOverCancellationReq; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 23;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stPacketHeader , stTrainLengthInfoPkt );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBS2STrainLengthInformationReq; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 24;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stPacketHeader , stTrainLengthInfoAck );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBS2SLengthInformationAck; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 25;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stPacketHeader , stTSLReqPkt );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBS2STSLRouteRequest; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 26;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stPacketHeader , stTSLInformationPkt );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBS2STSLAuthorityInformationPkt; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 27;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stPacketHeader , stFieldElementsStatusReqPkt );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBS2SFieldElementsStatusReq; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 28;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stPacketHeader , stTrainHandOverCancellationAckPkt );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBS2STrainHandoverCancellationAck; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 29;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stLocoRSSIMsg );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBLocoRSSIMessage; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 30;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stStationRSSIMsg );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBStationRSSIMessage; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 31;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stStationaryKavachSysInfo );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBStationKavachSysSts; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 32;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stOnboardKavachEventMsg );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBOnBoardEventMessage; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 33;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stOnboardKavachBrakeEventMsg );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBOnBoardBrakeEventMsg; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 34;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stOnboardKavachBOKSHealthMsg );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBOnBoardSystemHealthMsg; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 35;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stPacketHeader , uint16_t , QByteArray , uint32_t );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBFieldInputStatus; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 36;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(stFieldEventData );
            if (_q_method_type _q_method = &nmsMainWindow::SigInsertDBFieldInputEventData; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 37;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)();
            if (_q_method_type _q_method = &nmsMainWindow::SigShowAllStations; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 38;
                return;
            }
        }
        {
            using _q_method_type = void (nmsMainWindow::*)(QString , bool );
            if (_q_method_type _q_method = &nmsMainWindow::SigStationisConnected; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 39;
                return;
            }
        }
    }
}

const QMetaObject *nmsMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nmsMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN13nmsMainWindowE.stringdata0))
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
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
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
void nmsMainWindow::SigStnFaultPktInserttoDB(stStationFaults * _t1, QStringList _t2, QStringList _t3, QStringList _t4, QStringList _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
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
