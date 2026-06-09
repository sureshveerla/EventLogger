/****************************************************************************
** Meta object code from reading C++ file 'nmsDBQuerys.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/nmsDBQuerys.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nmsDBQuerys.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11nmsDBQuerysE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN11nmsDBQuerysE = QtMocHelpers::stringData(
    "nmsDBQuerys",
    "SigDBSMSnumbersResults",
    "",
    "uint8_t",
    "ucColCount",
    "uint16_t",
    "usRowCount",
    "strlstFldNames",
    "strlstRowValues",
    "SigDBRemoteUserResults",
    "SigDBStationInfo",
    "SigDBLocoInfo",
    "SigDBfaultmsgInfo",
    "SigDBSMSFaultsinfo",
    "QList<QStringList>",
    "SlotInsertSMSNumbers",
    "strUName",
    "strMobNo",
    "bStatus",
    "SlotFetchSMSNumbers",
    "SlotDeleteSMSNumber",
    "SlotUpdateSMSNumber",
    "strName",
    "bstatus",
    "QList<QList<QString>>",
    "lstvalues",
    "SlotFaultPktInserttoDB",
    "stKavachtoNMS*",
    "pstKavachtoNMS",
    "strFaultsCode",
    "strFaultMsg",
    "SlotStnFaultPktInserttoDB",
    "stStationFaults*",
    "pstStnFaults",
    "strLstModuleID",
    "strLstFaultCodeTyp",
    "SlotStationInfo",
    "SlotLocoInfo",
    "SlotPrvPromptInfo",
    "SlotFaultMsginserttoDB",
    "strMsgType",
    "strTimestamp",
    "QList<uint16_t>",
    "faultByteArray",
    "strFirmNam",
    "uint32_t",
    "uiID",
    "SlotStnFaultMsginserttoDB",
    "usFaultCode",
    "SlotSMSFaultMsginserttoDB",
    "strFirmnamID",
    "SlotSMSStnFaultMsginserttoDB",
    "usFaultCOde",
    "strFirmNamID",
    "SlotAccessReqInsertintoDB",
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
    "ucMASecCnt",
    "usRouteID",
    "uiCRC",
    "SlotLocoRegularInsertintoDB",
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
    "SlotAccessAuthorityPktInsertintoDB",
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
    "SlotAdditionalEmergencyPktInsertintoDB",
    "uiGenSoSCall",
    "SlotInsertDBStnRegMASubPkt",
    "MovementAuthorityPkt",
    "stMAPkt",
    "SlotInsertDBStnRegSSPSubPkt",
    "StaticSpeedProfilePkt",
    "stSSPPkt",
    "SlotInsertDBStnRegGradientSubPkt",
    "GradientProfilePkt",
    "stGradprofPkt",
    "SlotInsertDBStnRegLCGateSubPkt",
    "LCGateProfilePkt",
    "stLCGatePkt",
    "SlotInsertDBStnRegTurnoutSpeedSubPkt",
    "TurnoutSpeedProfilePkt",
    "stTSPPkt",
    "SlotInsertDBStnRegTagLinkingInfoSubPkt",
    "TagLinkingInfoPkt",
    "stTagLinkInfPkt",
    "SlotInsertDBStnRegTrackCondDataSubPkt",
    "TrackConditionPkt",
    "stTrackCondDataPkt",
    "SlotInsertDBStnRegTSRSubPkt",
    "TempSpeedRestrictionPkt",
    "stTSRPkt",
    "SlotInsertDBStationRegHeader",
    "stHeader",
    "StationRegularHeader",
    "stStnRglrHPkt",
    "SlotInsertDBStationhealthPkt",
    "stStationHealthPkt",
    "stStnHlthPkt",
    "strEvntID",
    "strEvntData",
    "uiCrc",
    "SlotInsertDBOnBoardhealthPkt",
    "stOnBoardHealthPkt",
    "stOnBrdHlthPkt",
    "SlotInsertDBS2SPDIVerCmd",
    "stPacketHeader",
    "stPktHdr",
    "stPDIVerCheckCmdPkt",
    "stPDIVerCmd",
    "SlotInsertDBS2SPDIVerMsg",
    "stPDIVerCheckMsgPkt",
    "stPDIVerMsg",
    "SlotInsertDBS2SHeartBeat",
    "stHeartBeatPkt",
    "stHeartBeat",
    "SlotInsertDBS2STrainHandOverReq",
    "stTrainHandOverReqPkt",
    "stTrnHndOveReq",
    "SlotInsertDBS2STrainTakenOverMsg",
    "stTrainTakenOverPkt",
    "stTrnTknOveMsg",
    "SlotInsertDBS2STrainHandOverCancellationReq",
    "stTrainHandOverCancellationPkt",
    "stTrnHndOvrCnclPkt",
    "SlotInsertDBS2STrainLengthInformationReq",
    "stTrainLengthInfoPkt",
    "stTrnLenInfoPkt",
    "SlotInsertDBS2SLengthInformationAck",
    "stTrainLengthInfoAck",
    "stTrnLenInfoAck",
    "SlotInsertDBS2STSLRouteRequest",
    "stTSLReqPkt",
    "stTSLRouteReq",
    "SlotInsertDBS2STSLAuthorityInformationPkt",
    "stTSLInformationPkt",
    "stTSLInfoPkt",
    "SlotInsertDBS2SFieldElementsStatusReq",
    "stFieldElementsStatusReqPkt",
    "stFldElementStsReq",
    "SlotInsertDBS2STrainHandoverCancellationAck",
    "stTrainHandOverCancellationAckPkt",
    "stTrnHndOvrCnclAck",
    "SlotInsertDBLocoRSSIMessage",
    "stLocoRSSIMsg",
    "stLocoRSSI",
    "SlotInsertDBStationRSSIMessage",
    "stStationRSSIMsg",
    "stStnRSSI",
    "SlotInsertDBStatioKavachSysSts",
    "stStationaryKavachSysInfo",
    "stStnKavchSysSts",
    "SlotInsertDBOnBoardEventMsg",
    "stOnboardKavachEventMsg",
    "stOnBoardEvntMsg",
    "SlotInsertDBOnBoardBrakeEventMsg",
    "stOnboardKavachBrakeEventMsg",
    "stOnBoardBrakeEvntMsg",
    "SlotInsertDBOnboardBOKSHealthMsg",
    "stOnboardKavachBOKSHealthMsg",
    "stOnBoardSysHealth",
    "SlotInsertDBFieldInputStatus",
    "usRelayCnt",
    "byArrRelayImage",
    "SlotInsertDBFieldInputEventData",
    "stFieldEventData",
    "stFldEvntData",
    "SlotInserttoDBFieldStatus",
    "strFieldId",
    "ucStatus",
    "SlotInsertRemoteUser",
    "strPwd",
    "SlotFetchRemoteUsers",
    "SlotDeleteRemoteUser",
    "strUserID",
    "SlotUpdateRemoteUser"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN11nmsDBQuerysE[] = {

 // content:
      12,       // revision
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

Q_CONSTINIT const QMetaObject nmsDBQuerys::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN11nmsDBQuerysE.offsetsAndSizes,
    qt_meta_data_ZN11nmsDBQuerysE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN11nmsDBQuerysE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<nmsDBQuerys, std::true_type>,
        // method 'SigDBSMSnumbersResults'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'SigDBRemoteUserResults'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'SigDBStationInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'SigDBLocoInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'SigDBfaultmsgInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'SigDBSMSFaultsinfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<QStringList>, std::false_type>,
        // method 'SlotInsertSMSNumbers'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'SlotFetchSMSNumbers'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SlotDeleteSMSNumber'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'SlotUpdateSMSNumber'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'SlotUpdateSMSNumber'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<QList<QString>>, std::false_type>,
        // method 'SlotFaultPktInserttoDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stKavachtoNMS *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'SlotStnFaultPktInserttoDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stStationFaults *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'SlotStationInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SlotLocoInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SlotPrvPromptInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SlotFaultMsginserttoDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<uint16_t>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        // method 'SlotStnFaultMsginserttoDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        // method 'SlotSMSFaultMsginserttoDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<uint16_t>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'SlotSMSStnFaultMsginserttoDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'SlotAccessReqInsertintoDB'
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
        // method 'SlotLocoRegularInsertintoDB'
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
        // method 'SlotAccessAuthorityPktInsertintoDB'
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
        // method 'SlotAdditionalEmergencyPktInsertintoDB'
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
        // method 'SlotInsertDBStnRegMASubPkt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<MovementAuthorityPkt, std::false_type>,
        // method 'SlotInsertDBStnRegSSPSubPkt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<StaticSpeedProfilePkt, std::false_type>,
        // method 'SlotInsertDBStnRegGradientSubPkt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<GradientProfilePkt, std::false_type>,
        // method 'SlotInsertDBStnRegLCGateSubPkt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<LCGateProfilePkt, std::false_type>,
        // method 'SlotInsertDBStnRegTurnoutSpeedSubPkt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<TurnoutSpeedProfilePkt, std::false_type>,
        // method 'SlotInsertDBStnRegTagLinkingInfoSubPkt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<TagLinkingInfoPkt, std::false_type>,
        // method 'SlotInsertDBStnRegTrackCondDataSubPkt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<TrackConditionPkt, std::false_type>,
        // method 'SlotInsertDBStnRegTSRSubPkt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<TempSpeedRestrictionPkt, std::false_type>,
        // method 'SlotInsertDBStationRegHeader'
        QtPrivate::TypeAndForceComplete<quint64, std::false_type>,
        QtPrivate::TypeAndForceComplete<stAccessRequestPkt, std::false_type>,
        QtPrivate::TypeAndForceComplete<StationRegularHeader, std::false_type>,
        // method 'SlotInsertDBStationhealthPkt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stStationHealthPkt, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        // method 'SlotInsertDBOnBoardhealthPkt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stOnBoardHealthPkt, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        // method 'SlotInsertDBS2SPDIVerCmd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPDIVerCheckCmdPkt, std::false_type>,
        // method 'SlotInsertDBS2SPDIVerMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPDIVerCheckMsgPkt, std::false_type>,
        // method 'SlotInsertDBS2SHeartBeat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stHeartBeatPkt, std::false_type>,
        // method 'SlotInsertDBS2STrainHandOverReq'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stTrainHandOverReqPkt, std::false_type>,
        // method 'SlotInsertDBS2STrainTakenOverMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stTrainTakenOverPkt, std::false_type>,
        // method 'SlotInsertDBS2STrainHandOverCancellationReq'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stTrainHandOverCancellationPkt, std::false_type>,
        // method 'SlotInsertDBS2STrainLengthInformationReq'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stTrainLengthInfoPkt, std::false_type>,
        // method 'SlotInsertDBS2SLengthInformationAck'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stTrainLengthInfoAck, std::false_type>,
        // method 'SlotInsertDBS2STSLRouteRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stTSLReqPkt, std::false_type>,
        // method 'SlotInsertDBS2STSLAuthorityInformationPkt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stTSLInformationPkt, std::false_type>,
        // method 'SlotInsertDBS2SFieldElementsStatusReq'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stFieldElementsStatusReqPkt, std::false_type>,
        // method 'SlotInsertDBS2STrainHandoverCancellationAck'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<stTrainHandOverCancellationAckPkt, std::false_type>,
        // method 'SlotInsertDBLocoRSSIMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stLocoRSSIMsg, std::false_type>,
        // method 'SlotInsertDBStationRSSIMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stStationRSSIMsg, std::false_type>,
        // method 'SlotInsertDBStatioKavachSysSts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stStationaryKavachSysInfo, std::false_type>,
        // method 'SlotInsertDBOnBoardEventMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stOnboardKavachEventMsg, std::false_type>,
        // method 'SlotInsertDBOnBoardBrakeEventMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stOnboardKavachBrakeEventMsg, std::false_type>,
        // method 'SlotInsertDBOnboardBOKSHealthMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stOnboardKavachBOKSHealthMsg, std::false_type>,
        // method 'SlotInsertDBFieldInputStatus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stPacketHeader, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        // method 'SlotInsertDBFieldInputEventData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<stFieldEventData, std::false_type>,
        // method 'SlotInserttoDBFieldStatus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>,
        // method 'SlotInsertRemoteUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'SlotFetchRemoteUsers'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SlotDeleteRemoteUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'SlotUpdateRemoteUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<QList<QString>>, std::false_type>
    >,
    nullptr
} };

void nmsDBQuerys::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<nmsDBQuerys *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
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
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
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
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (nmsDBQuerys::*)(uint8_t , uint16_t , QStringList , QStringList );
            if (_q_method_type _q_method = &nmsDBQuerys::SigDBSMSnumbersResults; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (nmsDBQuerys::*)(uint8_t , uint16_t , QStringList , QStringList );
            if (_q_method_type _q_method = &nmsDBQuerys::SigDBRemoteUserResults; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (nmsDBQuerys::*)(uint8_t , uint16_t , QStringList , QStringList );
            if (_q_method_type _q_method = &nmsDBQuerys::SigDBStationInfo; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (nmsDBQuerys::*)(uint8_t , uint16_t , QStringList , QStringList );
            if (_q_method_type _q_method = &nmsDBQuerys::SigDBLocoInfo; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (nmsDBQuerys::*)(uint8_t , uint16_t , QStringList , QStringList );
            if (_q_method_type _q_method = &nmsDBQuerys::SigDBfaultmsgInfo; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (nmsDBQuerys::*)(uint8_t , uint16_t , QStringList , QList<QStringList> );
            if (_q_method_type _q_method = &nmsDBQuerys::SigDBSMSFaultsinfo; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject *nmsDBQuerys::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nmsDBQuerys::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN11nmsDBQuerysE.stringdata0))
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
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
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
