/****************************************************************************
** Meta object code from reading C++ file 'nmsUDPServer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../include/nmsUDPServer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nmsUDPServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_nmsUDPServer_t {
    const uint offsetsAndSize[66];
    char stringdata0[409];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_nmsUDPServer_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_nmsUDPServer_t qt_meta_stringdata_nmsUDPServer = {
    {
QT_MOC_LITERAL(0, 12), // "nmsUDPServer"
QT_MOC_LITERAL(13, 17), // "SigNewFaultPacket"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 12), // "QHostAddress"
QT_MOC_LITERAL(45, 8), // "senderIP"
QT_MOC_LITERAL(54, 10), // "senderPort"
QT_MOC_LITERAL(65, 8), // "datagram"
QT_MOC_LITERAL(74, 22), // "SigStationDisConnected"
QT_MOC_LITERAL(97, 11), // "strSenderIP"
QT_MOC_LITERAL(109, 7), // "bstatus"
QT_MOC_LITERAL(117, 12), // "SigConnected"
QT_MOC_LITERAL(130, 15), // "SlotOnReadyRead"
QT_MOC_LITERAL(146, 11), // "QUdpSocket*"
QT_MOC_LITERAL(158, 8), // "pcsocket"
QT_MOC_LITERAL(167, 17), // "StationConnStatus"
QT_MOC_LITERAL(185, 15), // "SlotKMSSendToVC"
QT_MOC_LITERAL(201, 6), // "packet"
QT_MOC_LITERAL(208, 6), // "vcAddr"
QT_MOC_LITERAL(215, 6), // "vcPort"
QT_MOC_LITERAL(222, 17), // "SlotUpdateGPSTime"
QT_MOC_LITERAL(240, 7), // "gpsTime"
QT_MOC_LITERAL(248, 16), // "SendSNTPResponse"
QT_MOC_LITERAL(265, 6), // "socket"
QT_MOC_LITERAL(272, 10), // "clientAddr"
QT_MOC_LITERAL(283, 10), // "clientPort"
QT_MOC_LITERAL(294, 7), // "request"
QT_MOC_LITERAL(302, 10), // "GetGPSTime"
QT_MOC_LITERAL(313, 22), // "SlotSendAckNMStoKavach"
QT_MOC_LITERAL(336, 7), // "byteArr"
QT_MOC_LITERAL(344, 11), // "SlotSendAck"
QT_MOC_LITERAL(356, 14), // "stNMStoKavach*"
QT_MOC_LITERAL(371, 6), // "pstAck"
QT_MOC_LITERAL(378, 30) // "SlotSendAckEventLoggertoKavach"

    },
    "nmsUDPServer\0SigNewFaultPacket\0\0"
    "QHostAddress\0senderIP\0senderPort\0"
    "datagram\0SigStationDisConnected\0"
    "strSenderIP\0bstatus\0SigConnected\0"
    "SlotOnReadyRead\0QUdpSocket*\0pcsocket\0"
    "StationConnStatus\0SlotKMSSendToVC\0"
    "packet\0vcAddr\0vcPort\0SlotUpdateGPSTime\0"
    "gpsTime\0SendSNTPResponse\0socket\0"
    "clientAddr\0clientPort\0request\0GetGPSTime\0"
    "SlotSendAckNMStoKavach\0byteArr\0"
    "SlotSendAck\0stNMStoKavach*\0pstAck\0"
    "SlotSendAckEventLoggertoKavach"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nmsUDPServer[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   86,    2, 0x06,    1 /* Public */,
       7,    2,   93,    2, 0x06,    5 /* Public */,
      10,    2,   98,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    1,  103,    2, 0x08,   11 /* Private */,
      14,    0,  106,    2, 0x08,   13 /* Private */,
      15,    3,  107,    2, 0x08,   14 /* Private */,
      19,    1,  114,    2, 0x0a,   18 /* Public */,
      21,    4,  117,    2, 0x0a,   20 /* Public */,
      26,    0,  126,    2, 0x0a,   25 /* Public */,
      27,    1,  127,    2, 0x0a,   26 /* Public */,
      29,    3,  130,    2, 0x0a,   28 /* Public */,
      32,    3,  137,    2, 0x0a,   32 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::UShort, QMetaType::QByteArray,    4,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    8,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 3, QMetaType::UShort,   16,   17,   18,
    QMetaType::Void, QMetaType::QDateTime,   20,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 3, QMetaType::UShort, QMetaType::QByteArray,   22,   23,   24,   25,
    QMetaType::QDateTime,
    QMetaType::Void, QMetaType::QByteArray,   28,
    QMetaType::Void, 0x80000000 | 3, QMetaType::UShort, 0x80000000 | 30,    4,    5,   31,
    QMetaType::Void, 0x80000000 | 3, QMetaType::UShort, 0x80000000 | 30,    4,    5,   31,

       0        // eod
};

void nmsUDPServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<nmsUDPServer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SigNewFaultPacket((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[3]))); break;
        case 1: _t->SigStationDisConnected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 2: _t->SigConnected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 3: _t->SlotOnReadyRead((*reinterpret_cast< std::add_pointer_t<QUdpSocket*>>(_a[1]))); break;
        case 4: _t->StationConnStatus(); break;
        case 5: _t->SlotKMSSendToVC((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[3]))); break;
        case 6: _t->SlotUpdateGPSTime((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1]))); break;
        case 7: _t->SendSNTPResponse((*reinterpret_cast< std::add_pointer_t<QUdpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[4]))); break;
        case 8: { QDateTime _r = _t->GetGPSTime();
            if (_a[0]) *reinterpret_cast< QDateTime*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->SlotSendAckNMStoKavach((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 10: _t->SlotSendAck((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<stNMStoKavach*>>(_a[3]))); break;
        case 11: _t->SlotSendAckEventLoggertoKavach((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<stNMStoKavach*>>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (nmsUDPServer::*)(QHostAddress , quint16 , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsUDPServer::SigNewFaultPacket)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (nmsUDPServer::*)(QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsUDPServer::SigStationDisConnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (nmsUDPServer::*)(QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsUDPServer::SigConnected)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject nmsUDPServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_nmsUDPServer.offsetsAndSize,
    qt_meta_data_nmsUDPServer,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_nmsUDPServer_t
, QtPrivate::TypeAndForceComplete<nmsUDPServer, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QUdpSocket *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QDateTime &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QUdpSocket *, std::false_type>, QtPrivate::TypeAndForceComplete<const QHostAddress &, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<QDateTime, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<stNMStoKavach *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<stNMStoKavach *, std::false_type>


>,
    nullptr
} };


const QMetaObject *nmsUDPServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nmsUDPServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_nmsUDPServer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int nmsUDPServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void nmsUDPServer::SigNewFaultPacket(QHostAddress _t1, quint16 _t2, QByteArray _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void nmsUDPServer::SigStationDisConnected(QString _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void nmsUDPServer::SigConnected(QString _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
