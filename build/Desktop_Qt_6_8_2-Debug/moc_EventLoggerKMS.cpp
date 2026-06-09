/****************************************************************************
** Meta object code from reading C++ file 'EventLoggerKMS.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/EventLoggerKMS.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EventLoggerKMS.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN14EventLoggerKMSE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN14EventLoggerKMSE = QtMocHelpers::stringData(
    "EventLoggerKMS",
    "SigSendToVC",
    "",
    "packet",
    "QHostAddress",
    "vcAddr",
    "vcPort",
    "SigChannelChangeover",
    "newSimID",
    "SigCSQUpdated",
    "csqValue",
    "KMSSignalQuality",
    "quality",
    "SigKMSPacketReceived",
    "msgType",
    "SigKMSPacketSent",
    "SlotHandleUDPFromVC",
    "datagram",
    "senderIP",
    "senderPort",
    "SlotPollCSQ",
    "SlotHandleGSMData"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN14EventLoggerKMSE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   62,    2, 0x06,    1 /* Public */,
       7,    1,   69,    2, 0x06,    5 /* Public */,
       9,    2,   72,    2, 0x06,    7 /* Public */,
      13,    2,   77,    2, 0x06,   10 /* Public */,
      15,    2,   82,    2, 0x06,   13 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      16,    3,   87,    2, 0x0a,   16 /* Public */,
      20,    0,   94,    2, 0x0a,   20 /* Public */,
      21,    0,   95,    2, 0x08,   21 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 4, QMetaType::UShort,    3,    5,    6,
    QMetaType::Void, QMetaType::UChar,    8,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 11,   10,   12,
    QMetaType::Void, QMetaType::UChar, QMetaType::QByteArray,   14,    3,
    QMetaType::Void, QMetaType::UChar, QMetaType::QByteArray,   14,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 4, QMetaType::UShort,   17,   18,   19,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject EventLoggerKMS::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN14EventLoggerKMSE.offsetsAndSizes,
    qt_meta_data_ZN14EventLoggerKMSE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN14EventLoggerKMSE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<EventLoggerKMS, std::true_type>,
        // method 'SigSendToVC'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>,
        // method 'SigChannelChangeover'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        // method 'SigCSQUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<KMSSignalQuality, std::false_type>,
        // method 'SigKMSPacketReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'SigKMSPacketSent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'SlotHandleUDPFromVC'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>,
        // method 'SlotPollCSQ'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SlotHandleGSMData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void EventLoggerKMS::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<EventLoggerKMS *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->SigSendToVC((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[3]))); break;
        case 1: _t->SigChannelChangeover((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1]))); break;
        case 2: _t->SigCSQUpdated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<KMSSignalQuality>>(_a[2]))); break;
        case 3: _t->SigKMSPacketReceived((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 4: _t->SigKMSPacketSent((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 5: _t->SlotHandleUDPFromVC((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[3]))); break;
        case 6: _t->SlotPollCSQ(); break;
        case 7: _t->SlotHandleGSMData(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (EventLoggerKMS::*)(QByteArray , QHostAddress , quint16 );
            if (_q_method_type _q_method = &EventLoggerKMS::SigSendToVC; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (EventLoggerKMS::*)(quint8 );
            if (_q_method_type _q_method = &EventLoggerKMS::SigChannelChangeover; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (EventLoggerKMS::*)(int , KMSSignalQuality );
            if (_q_method_type _q_method = &EventLoggerKMS::SigCSQUpdated; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (EventLoggerKMS::*)(quint8 , QByteArray );
            if (_q_method_type _q_method = &EventLoggerKMS::SigKMSPacketReceived; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (EventLoggerKMS::*)(quint8 , QByteArray );
            if (_q_method_type _q_method = &EventLoggerKMS::SigKMSPacketSent; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject *EventLoggerKMS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EventLoggerKMS::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN14EventLoggerKMSE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EventLoggerKMS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void EventLoggerKMS::SigSendToVC(QByteArray _t1, QHostAddress _t2, quint16 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EventLoggerKMS::SigChannelChangeover(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EventLoggerKMS::SigCSQUpdated(int _t1, KMSSignalQuality _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void EventLoggerKMS::SigKMSPacketReceived(quint8 _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void EventLoggerKMS::SigKMSPacketSent(quint8 _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
