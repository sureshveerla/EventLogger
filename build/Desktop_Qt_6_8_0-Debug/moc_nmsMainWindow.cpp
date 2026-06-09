/****************************************************************************
** Meta object code from reading C++ file 'nmsMainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
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
#error "This file was generated using the moc from 6.8.0. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSnmsMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSnmsMainWindowENDCLASS = QtMocHelpers::stringData(
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
    "bStatus"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSnmsMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      43,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      36,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,  272,    2, 0x06,    1 /* Public */,
       8,    3,  279,    2, 0x06,    5 /* Public */,
      13,    3,  286,    2, 0x06,    9 /* Public */,
      16,    0,  293,    2, 0x06,   13 /* Public */,
      17,    0,  294,    2, 0x06,   14 /* Public */,
      18,    5,  295,    2, 0x06,   15 /* Public */,
      26,    5,  306,    2, 0x06,   21 /* Public */,
      29,    4,  317,    2, 0x06,   27 /* Public */,
      31,    4,  326,    2, 0x06,   32 /* Public */,
      33,    2,  335,    2, 0x06,   37 /* Public */,
      35,    4,  340,    2, 0x06,   40 /* Public */,
      38,   23,  349,    2, 0x06,   45 /* Public */,
      64,   31,  396,    2, 0x06,   69 /* Public */,
      77,   16,  459,    2, 0x06,  101 /* Public */,
      89,    9,  492,    2, 0x06,  118 /* Public */,
      91,    2,  511,    2, 0x06,  128 /* Public */,
      95,    4,  516,    2, 0x06,  131 /* Public */,
     101,    4,  525,    2, 0x06,  136 /* Public */,
     104,    2,  534,    2, 0x06,  141 /* Public */,
     109,    2,  539,    2, 0x06,  144 /* Public */,
     112,    2,  544,    2, 0x06,  147 /* Public */,
     115,    2,  549,    2, 0x06,  150 /* Public */,
     118,    2,  554,    2, 0x06,  153 /* Public */,
     121,    2,  559,    2, 0x06,  156 /* Public */,
     124,    2,  564,    2, 0x06,  159 /* Public */,
     127,    2,  569,    2, 0x06,  162 /* Public */,
     130,    2,  574,    2, 0x06,  165 /* Public */,
     133,    2,  579,    2, 0x06,  168 /* Public */,
     136,    2,  584,    2, 0x06,  171 /* Public */,
     139,    2,  589,    2, 0x06,  174 /* Public */,
     142,    1,  594,    2, 0x06,  177 /* Public */,
     145,    1,  597,    2, 0x06,  179 /* Public */,
     148,    4,  600,    2, 0x06,  181 /* Public */,
     151,    1,  609,    2, 0x06,  186 /* Public */,
     154,    0,  612,    2, 0x06,  188 /* Public */,
     155,    2,  613,    2, 0x06,  189 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
     158,    3,  618,    2, 0x08,  192 /* Private */,
     160,    0,  625,    2, 0x08,  196 /* Private */,
     161,    1,  626,    2, 0x08,  197 /* Private */,
     163,    3,  629,    2, 0x08,  199 /* Private */,
     164,    4,  636,    2, 0x08,  203 /* Private */,
     169,    1,  645,    2, 0x08,  208 /* Private */,
     170,    2,  648,    2, 0x08,  210 /* Private */,

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
    QMetaType::Void, 0x80000000 | 96, QMetaType::QString, QMetaType::QString, 0x80000000 | 24,   97,   98,   99,  100,
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
    QMetaType::Void, 0x80000000 | 105, 0x80000000 | 27, QMetaType::QByteArray, 0x80000000 | 24,  106,  149,  150,   63,
    QMetaType::Void, 0x80000000 | 152,  153,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,  156,  157,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::UShort, QMetaType::QByteArray,    4,    5,  159,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  162,
    QMetaType::Void, 0x80000000 | 3, QMetaType::UShort, QMetaType::QByteArray,    4,    5,  159,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QString, QMetaType::Bool,  165,  166,  167,  168,
    QMetaType::Void, 0x80000000 | 93,   94,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,  171,  172,

       0        // eod
};

Q_CONSTINIT const QMetaObject nmsMainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSnmsMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSnmsMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSnmsMainWindowENDCLASS_t,
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
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
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
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
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
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

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
        case 16: _t->SigInsertDBStationhealthPkt((*reinterpret_cast< std::add_pointer_t<stStationHealthPkt>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4]))); break;
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
        case 32: _t->SigInsertDBFieldInputStatus((*reinterpret_cast< std::add_pointer_t<stPacketHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[4]))); break;
        case 33: _t->SigInsertDBFieldInputEventData((*reinterpret_cast< std::add_pointer_t<stFieldEventData>>(_a[1]))); break;
        case 34: _t->SigShowAllStations(); break;
        case 35: _t->SigStationisConnected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 36: _t->SlotNewFaultPacket((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[3]))); break;
        case 37: _t->SlotPreviousFaultInfo(); break;
        case 38: _t->SlottabChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 39: _t->SlotUpadateSchematic((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[3]))); break;
        case 40: _t->SlotStationNameAndID((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 41: _t->SlotStationRegHeader((*reinterpret_cast< std::add_pointer_t<StationRegularHeader>>(_a[1]))); break;
        case 42: _t->SlotStationconnStatus((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
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
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< stPacketHeader >(); break;
            }
            break;
        case 33:
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
            if (_t _q_method = &nmsMainWindow::SigSendAckNMStoKavach; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stKavachtoNMS * , QString , QString );
            if (_t _q_method = &nmsMainWindow::SigFaultPktInserttoDB; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stStationFaults * , QString , QString );
            if (_t _q_method = &nmsMainWindow::SigStnFaultPktInserttoDB; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)();
            if (_t _q_method = &nmsMainWindow::SigStationInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)();
            if (_t _q_method = &nmsMainWindow::SigLocoInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(QString , QString , QList<uint16_t> , QString , uint32_t );
            if (_t _q_method = &nmsMainWindow::SigFaultMsginserttoDB; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(QString , QString , uint16_t , QString , uint32_t );
            if (_t _q_method = &nmsMainWindow::SigStnFaultMsginserttoDB; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(QString , QString , QList<uint16_t> , QString );
            if (_t _q_method = &nmsMainWindow::SigSMSFaultMsginserttoDB; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(QString , QString , uint16_t , QString );
            if (_t _q_method = &nmsMainWindow::SigSMSStnFaultMsginserttoDB; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(uint32_t , QString );
            if (_t _q_method = &nmsMainWindow::SigSendSMS; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(QString , QString , QString , QString );
            if (_t _q_method = &nmsMainWindow::SigSendFaultmessage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stAccessRequestPkt , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint8_t , uint16_t , uint32_t );
            if (_t _q_method = &nmsMainWindow::SigAccessReqInsertintoDB; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stAccessRequestPkt , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , QString , uint32_t , uint32_t , uint8_t , uint16_t , uint32_t );
            if (_t _q_method = &nmsMainWindow::SigLocoRegularInsertintoDB; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stAccessRequestPkt , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t );
            if (_t _q_method = &nmsMainWindow::SigAccessAuthorityPktInsertintoDB; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stAccessRequestPkt , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t , uint32_t );
            if (_t _q_method = &nmsMainWindow::SigAdditionalEmergencyPktInsertintoDB; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stAccessRequestPkt , StationRegularHeader );
            if (_t _q_method = &nmsMainWindow::SigInsertDBStationRegHeader; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stStationHealthPkt , QString , QString , uint32_t );
            if (_t _q_method = &nmsMainWindow::SigInsertDBStationhealthPkt; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stOnBoardHealthPkt , QString , QString , uint32_t );
            if (_t _q_method = &nmsMainWindow::SigInsertDBOnBoardhealthPkt; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stPDIVerCheckCmdPkt );
            if (_t _q_method = &nmsMainWindow::SigInsertDBS2SPDIVerCmd; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stPDIVerCheckMsgPkt );
            if (_t _q_method = &nmsMainWindow::SigInsertDBS2SPDIVerMsg; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stHeartBeatPkt );
            if (_t _q_method = &nmsMainWindow::SigInsertDBS2SHeartBeat; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stTrainHandOverReqPkt );
            if (_t _q_method = &nmsMainWindow::SigInsertDBS2STrainHandOverReq; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stTrainTakenOverPkt );
            if (_t _q_method = &nmsMainWindow::SigInsertDBS2STrainTakenOverMsg; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stTrainHandOverCancellationPkt );
            if (_t _q_method = &nmsMainWindow::SigInsertDBS2STrainHandOverCancellationReq; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stTrainLengthInfoPkt );
            if (_t _q_method = &nmsMainWindow::SigInsertDBS2STrainLengthInformationReq; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stTrainLengthInfoAck );
            if (_t _q_method = &nmsMainWindow::SigInsertDBS2SLengthInformationAck; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stTSLReqPkt );
            if (_t _q_method = &nmsMainWindow::SigInsertDBS2STSLRouteRequest; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stTSLInformationPkt );
            if (_t _q_method = &nmsMainWindow::SigInsertDBS2STSLAuthorityInformationPkt; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stFieldElementsStatusReqPkt );
            if (_t _q_method = &nmsMainWindow::SigInsertDBS2SFieldElementsStatusReq; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , stTrainHandOverCancellationAckPkt );
            if (_t _q_method = &nmsMainWindow::SigInsertDBS2STrainHandoverCancellationAck; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stLocoRSSIMsg );
            if (_t _q_method = &nmsMainWindow::SigInsertDBLocoRSSIMessage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 30;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stStationRSSIMsg );
            if (_t _q_method = &nmsMainWindow::SigInsertDBStationRSSIMessage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 31;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stPacketHeader , uint16_t , QByteArray , uint32_t );
            if (_t _q_method = &nmsMainWindow::SigInsertDBFieldInputStatus; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 32;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(stFieldEventData );
            if (_t _q_method = &nmsMainWindow::SigInsertDBFieldInputEventData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 33;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)();
            if (_t _q_method = &nmsMainWindow::SigShowAllStations; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 34;
                return;
            }
        }
        {
            using _t = void (nmsMainWindow::*)(QString , bool );
            if (_t _q_method = &nmsMainWindow::SigStationisConnected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 35;
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
    if (!strcmp(_clname, qt_meta_stringdata_CLASSnmsMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int nmsMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 43)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 43;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 43)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 43;
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
void nmsMainWindow::SigInsertDBStationhealthPkt(stStationHealthPkt _t1, QString _t2, QString _t3, uint32_t _t4)
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
void nmsMainWindow::SigInsertDBFieldInputStatus(stPacketHeader _t1, uint16_t _t2, QByteArray _t3, uint32_t _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 32, _a);
}

// SIGNAL 33
void nmsMainWindow::SigInsertDBFieldInputEventData(stFieldEventData _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 33, _a);
}

// SIGNAL 34
void nmsMainWindow::SigShowAllStations()
{
    QMetaObject::activate(this, &staticMetaObject, 34, nullptr);
}

// SIGNAL 35
void nmsMainWindow::SigStationisConnected(QString _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 35, _a);
}
QT_WARNING_POP
