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
    const uint offsetsAndSize[62];
    char stringdata0[387];
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
QT_MOC_LITERAL(130, 20), // "SigEventDataReceived"
QT_MOC_LITERAL(151, 15), // "SlotOnReadyRead"
QT_MOC_LITERAL(167, 11), // "QUdpSocket*"
QT_MOC_LITERAL(179, 8), // "pcsocket"
QT_MOC_LITERAL(188, 17), // "StationConnStatus"
QT_MOC_LITERAL(206, 15), // "SlotKMSSendToVC"
QT_MOC_LITERAL(222, 6), // "packet"
QT_MOC_LITERAL(229, 6), // "vcAddr"
QT_MOC_LITERAL(236, 6), // "vcPort"
QT_MOC_LITERAL(243, 17), // "SlotUpdateGPSTime"
QT_MOC_LITERAL(261, 7), // "gpsTime"
QT_MOC_LITERAL(269, 16), // "SendSNTPResponse"
QT_MOC_LITERAL(286, 6), // "socket"
QT_MOC_LITERAL(293, 10), // "clientAddr"
QT_MOC_LITERAL(304, 10), // "clientPort"
QT_MOC_LITERAL(315, 7), // "request"
QT_MOC_LITERAL(323, 10), // "GetGPSTime"
QT_MOC_LITERAL(334, 30), // "SlotSendAckEventLoggertoKavach"
QT_MOC_LITERAL(365, 14), // "stNMStoKavach*"
QT_MOC_LITERAL(380, 6) // "pstAck"

    },
    "nmsUDPServer\0SigNewFaultPacket\0\0"
    "QHostAddress\0senderIP\0senderPort\0"
    "datagram\0SigStationDisConnected\0"
    "strSenderIP\0bstatus\0SigConnected\0"
    "SigEventDataReceived\0SlotOnReadyRead\0"
    "QUdpSocket*\0pcsocket\0StationConnStatus\0"
    "SlotKMSSendToVC\0packet\0vcAddr\0vcPort\0"
    "SlotUpdateGPSTime\0gpsTime\0SendSNTPResponse\0"
    "socket\0clientAddr\0clientPort\0request\0"
    "GetGPSTime\0SlotSendAckEventLoggertoKavach\0"
    "stNMStoKavach*\0pstAck"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nmsUDPServer[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   80,    2, 0x06,    1 /* Public */,
       7,    2,   87,    2, 0x06,    5 /* Public */,
      10,    2,   92,    2, 0x06,    8 /* Public */,
      11,    0,   97,    2, 0x06,   11 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    1,   98,    2, 0x08,   12 /* Private */,
      15,    0,  101,    2, 0x08,   14 /* Private */,
      16,    3,  102,    2, 0x08,   15 /* Private */,
      20,    1,  109,    2, 0x0a,   19 /* Public */,
      22,    4,  112,    2, 0x0a,   21 /* Public */,
      27,    0,  121,    2, 0x0a,   26 /* Public */,
      28,    3,  122,    2, 0x0a,   27 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::UShort, QMetaType::QByteArray,    4,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    8,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 3, QMetaType::UShort,   17,   18,   19,
    QMetaType::Void, QMetaType::QDateTime,   21,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 3, QMetaType::UShort, QMetaType::QByteArray,   23,   24,   25,   26,
    QMetaType::QDateTime,
    QMetaType::Void, 0x80000000 | 3, QMetaType::UShort, 0x80000000 | 29,    4,    5,   30,

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
        case 3: _t->SigEventDataReceived(); break;
        case 4: _t->SlotOnReadyRead((*reinterpret_cast< std::add_pointer_t<QUdpSocket*>>(_a[1]))); break;
        case 5: _t->StationConnStatus(); break;
        case 6: _t->SlotKMSSendToVC((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[3]))); break;
        case 7: _t->SlotUpdateGPSTime((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1]))); break;
        case 8: _t->SendSNTPResponse((*reinterpret_cast< std::add_pointer_t<QUdpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[4]))); break;
        case 9: { QDateTime _r = _t->GetGPSTime();
            if (_a[0]) *reinterpret_cast< QDateTime*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->SlotSendAckEventLoggertoKavach((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<stNMStoKavach*>>(_a[3]))); break;
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
        {
            using _t = void (nmsUDPServer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmsUDPServer::SigEventDataReceived)) {
                *result = 3;
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
, QtPrivate::TypeAndForceComplete<nmsUDPServer, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QUdpSocket *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QDateTime &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QUdpSocket *, std::false_type>, QtPrivate::TypeAndForceComplete<const QHostAddress &, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<QDateTime, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<stNMStoKavach *, std::false_type>


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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
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

// SIGNAL 3
void nmsUDPServer::SigEventDataReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
