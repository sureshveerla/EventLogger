/****************************************************************************
** Meta object code from reading C++ file 'EventLoggerKMS.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../include/EventLoggerKMS.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EventLoggerKMS.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EventLoggerKMS_t {
    const uint offsetsAndSize[50];
    char stringdata0[307];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_EventLoggerKMS_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_EventLoggerKMS_t qt_meta_stringdata_EventLoggerKMS = {
    {
QT_MOC_LITERAL(0, 14), // "EventLoggerKMS"
QT_MOC_LITERAL(15, 11), // "SigSendToVC"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 6), // "packet"
QT_MOC_LITERAL(35, 12), // "QHostAddress"
QT_MOC_LITERAL(48, 6), // "vcAddr"
QT_MOC_LITERAL(55, 6), // "vcPort"
QT_MOC_LITERAL(62, 20), // "SigChannelChangeover"
QT_MOC_LITERAL(83, 8), // "newSimID"
QT_MOC_LITERAL(92, 13), // "SigCSQUpdated"
QT_MOC_LITERAL(106, 8), // "csqValue"
QT_MOC_LITERAL(115, 16), // "KMSSignalQuality"
QT_MOC_LITERAL(132, 7), // "quality"
QT_MOC_LITERAL(140, 20), // "SigKMSPacketReceived"
QT_MOC_LITERAL(161, 7), // "msgType"
QT_MOC_LITERAL(169, 16), // "SigKMSPacketSent"
QT_MOC_LITERAL(186, 18), // "SigGSMHealthStatus"
QT_MOC_LITERAL(205, 6), // "status"
QT_MOC_LITERAL(212, 19), // "SlotHandleUDPFromVC"
QT_MOC_LITERAL(232, 8), // "datagram"
QT_MOC_LITERAL(241, 8), // "senderIP"
QT_MOC_LITERAL(250, 10), // "senderPort"
QT_MOC_LITERAL(261, 11), // "SlotPollCSQ"
QT_MOC_LITERAL(273, 17), // "SlotHandleGSMData"
QT_MOC_LITERAL(291, 15) // "SlotBlinkGSMLed"

    },
    "EventLoggerKMS\0SigSendToVC\0\0packet\0"
    "QHostAddress\0vcAddr\0vcPort\0"
    "SigChannelChangeover\0newSimID\0"
    "SigCSQUpdated\0csqValue\0KMSSignalQuality\0"
    "quality\0SigKMSPacketReceived\0msgType\0"
    "SigKMSPacketSent\0SigGSMHealthStatus\0"
    "status\0SlotHandleUDPFromVC\0datagram\0"
    "senderIP\0senderPort\0SlotPollCSQ\0"
    "SlotHandleGSMData\0SlotBlinkGSMLed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EventLoggerKMS[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   74,    2, 0x06,    1 /* Public */,
       7,    1,   81,    2, 0x06,    5 /* Public */,
       9,    2,   84,    2, 0x06,    7 /* Public */,
      13,    2,   89,    2, 0x06,   10 /* Public */,
      15,    2,   94,    2, 0x06,   13 /* Public */,
      16,    1,   99,    2, 0x06,   16 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      18,    3,  102,    2, 0x0a,   18 /* Public */,
      22,    0,  109,    2, 0x0a,   22 /* Public */,
      23,    0,  110,    2, 0x08,   23 /* Private */,
      24,    0,  111,    2, 0x08,   24 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 4, QMetaType::UShort,    3,    5,    6,
    QMetaType::Void, QMetaType::UChar,    8,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 11,   10,   12,
    QMetaType::Void, QMetaType::UChar, QMetaType::QByteArray,   14,    3,
    QMetaType::Void, QMetaType::UChar, QMetaType::QByteArray,   14,    3,
    QMetaType::Void, QMetaType::Bool,   17,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 4, QMetaType::UShort,   19,   20,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EventLoggerKMS::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EventLoggerKMS *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SigSendToVC((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[3]))); break;
        case 1: _t->SigChannelChangeover((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1]))); break;
        case 2: _t->SigCSQUpdated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<KMSSignalQuality>>(_a[2]))); break;
        case 3: _t->SigKMSPacketReceived((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 4: _t->SigKMSPacketSent((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 5: _t->SigGSMHealthStatus((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->SlotHandleUDPFromVC((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[3]))); break;
        case 7: _t->SlotPollCSQ(); break;
        case 8: _t->SlotHandleGSMData(); break;
        case 9: _t->SlotBlinkGSMLed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EventLoggerKMS::*)(QByteArray , QHostAddress , quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EventLoggerKMS::SigSendToVC)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (EventLoggerKMS::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EventLoggerKMS::SigChannelChangeover)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (EventLoggerKMS::*)(int , KMSSignalQuality );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EventLoggerKMS::SigCSQUpdated)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (EventLoggerKMS::*)(quint8 , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EventLoggerKMS::SigKMSPacketReceived)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (EventLoggerKMS::*)(quint8 , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EventLoggerKMS::SigKMSPacketSent)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (EventLoggerKMS::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EventLoggerKMS::SigGSMHealthStatus)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject EventLoggerKMS::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_EventLoggerKMS.offsetsAndSize,
    qt_meta_data_EventLoggerKMS,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_EventLoggerKMS_t
, QtPrivate::TypeAndForceComplete<EventLoggerKMS, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<quint8, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<KMSSignalQuality, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<quint8, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<quint8, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *EventLoggerKMS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EventLoggerKMS::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EventLoggerKMS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EventLoggerKMS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
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

// SIGNAL 5
void EventLoggerKMS::SigGSMHealthStatus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
