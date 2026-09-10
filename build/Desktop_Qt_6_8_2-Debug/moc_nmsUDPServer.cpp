/****************************************************************************
** Meta object code from reading C++ file 'nmsUDPServer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/nmsUDPServer.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nmsUDPServer.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12nmsUDPServerE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN12nmsUDPServerE = QtMocHelpers::stringData(
    "nmsUDPServer",
    "SigNewFaultPacket",
    "",
    "QHostAddress",
    "senderIP",
    "senderPort",
    "datagram",
    "SigStationDisConnected",
    "strSenderIP",
    "bstatus",
    "SigConnected",
    "SlotOnReadyRead",
    "QUdpSocket*",
    "pcsocket",
    "StationConnStatus",
    "SlotKMSSendToVC",
    "packet",
    "vcAddr",
    "vcPort",
    "SlotUpdateGPSTime",
    "gpsTime",
    "SendSNTPResponse",
    "socket",
    "clientAddr",
    "clientPort",
    "request",
    "GetGPSTime",
    "SlotSendAckEventLoggertoKavach",
    "stNMStoKavach*",
    "pstAck"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN12nmsUDPServerE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   74,    2, 0x06,    1 /* Public */,
       7,    2,   81,    2, 0x06,    5 /* Public */,
      10,    2,   86,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    1,   91,    2, 0x08,   11 /* Private */,
      14,    0,   94,    2, 0x08,   13 /* Private */,
      15,    3,   95,    2, 0x08,   14 /* Private */,
      19,    1,  102,    2, 0x0a,   18 /* Public */,
      21,    4,  105,    2, 0x0a,   20 /* Public */,
      26,    0,  114,    2, 0x0a,   25 /* Public */,
      27,    3,  115,    2, 0x0a,   26 /* Public */,

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
    QMetaType::Void, 0x80000000 | 3, QMetaType::UShort, 0x80000000 | 28,    4,    5,   29,

       0        // eod
};

Q_CONSTINIT const QMetaObject nmsUDPServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN12nmsUDPServerE.offsetsAndSizes,
    qt_meta_data_ZN12nmsUDPServerE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN12nmsUDPServerE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<nmsUDPServer, std::true_type>,
        // method 'SigNewFaultPacket'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'SigStationDisConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'SigConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'SlotOnReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QUdpSocket *, std::false_type>,
        // method 'StationConnStatus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SlotKMSSendToVC'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>,
        // method 'SlotUpdateGPSTime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDateTime &, std::false_type>,
        // method 'SendSNTPResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QUdpSocket *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QHostAddress &, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'GetGPSTime'
        QtPrivate::TypeAndForceComplete<QDateTime, std::false_type>,
        // method 'SlotSendAckEventLoggertoKavach'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>,
        QtPrivate::TypeAndForceComplete<stNMStoKavach *, std::false_type>
    >,
    nullptr
} };

void nmsUDPServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<nmsUDPServer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
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
        case 9: _t->SlotSendAckEventLoggertoKavach((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<stNMStoKavach*>>(_a[3]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QUdpSocket* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QUdpSocket* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (nmsUDPServer::*)(QHostAddress , quint16 , QByteArray );
            if (_q_method_type _q_method = &nmsUDPServer::SigNewFaultPacket; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (nmsUDPServer::*)(QString , bool );
            if (_q_method_type _q_method = &nmsUDPServer::SigStationDisConnected; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (nmsUDPServer::*)(QString , bool );
            if (_q_method_type _q_method = &nmsUDPServer::SigConnected; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *nmsUDPServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nmsUDPServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN12nmsUDPServerE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int nmsUDPServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
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
