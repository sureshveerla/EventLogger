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
    const uint offsetsAndSize[44];
    char stringdata0[265];
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
QT_MOC_LITERAL(186, 19), // "SlotHandleUDPFromVC"
QT_MOC_LITERAL(206, 8), // "datagram"
QT_MOC_LITERAL(215, 8), // "senderIP"
QT_MOC_LITERAL(224, 10), // "senderPort"
QT_MOC_LITERAL(235, 11), // "SlotPollCSQ"
QT_MOC_LITERAL(247, 17) // "SlotHandleGSMData"

    },
    "EventLoggerKMS\0SigSendToVC\0\0packet\0"
    "QHostAddress\0vcAddr\0vcPort\0"
    "SigChannelChangeover\0newSimID\0"
    "SigCSQUpdated\0csqValue\0KMSSignalQuality\0"
    "quality\0SigKMSPacketReceived\0msgType\0"
    "SigKMSPacketSent\0SlotHandleUDPFromVC\0"
    "datagram\0senderIP\0senderPort\0SlotPollCSQ\0"
    "SlotHandleGSMData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EventLoggerKMS[] = {

 // content:
      10,       // revision
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
        case 5: _t->SlotHandleUDPFromVC((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[3]))); break;
        case 6: _t->SlotPollCSQ(); break;
        case 7: _t->SlotHandleGSMData(); break;
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
    }
}

const QMetaObject EventLoggerKMS::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_EventLoggerKMS.offsetsAndSize,
    qt_meta_data_EventLoggerKMS,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_EventLoggerKMS_t
, QtPrivate::TypeAndForceComplete<EventLoggerKMS, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<quint8, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<KMSSignalQuality, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<quint8, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<quint8, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
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
QT_END_MOC_NAMESPACE
