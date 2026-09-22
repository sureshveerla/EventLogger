/****************************************************************************
** Meta object code from reading C++ file 'EventLoggerStatusLED.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../include/EventLoggerStatusLED.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EventLoggerStatusLED.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EventLoggerStatusLED_t {
    const uint offsetsAndSize[20];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_EventLoggerStatusLED_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_EventLoggerStatusLED_t qt_meta_stringdata_EventLoggerStatusLED = {
    {
QT_MOC_LITERAL(0, 20), // "EventLoggerStatusLED"
QT_MOC_LITERAL(21, 5), // "Start"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 13), // "SetVCIPStatus"
QT_MOC_LITERAL(42, 6), // "status"
QT_MOC_LITERAL(49, 12), // "SetGPSStatus"
QT_MOC_LITERAL(62, 12), // "SetGSMStatus"
QT_MOC_LITERAL(75, 17), // "EventDataReceived"
QT_MOC_LITERAL(93, 15), // "EventLedTimeout"
QT_MOC_LITERAL(109, 15) // "FaultLedTimeout"

    },
    "EventLoggerStatusLED\0Start\0\0SetVCIPStatus\0"
    "status\0SetGPSStatus\0SetGSMStatus\0"
    "EventDataReceived\0EventLedTimeout\0"
    "FaultLedTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EventLoggerStatusLED[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x0a,    1 /* Public */,
       3,    1,   57,    2, 0x0a,    2 /* Public */,
       5,    1,   60,    2, 0x0a,    4 /* Public */,
       6,    1,   63,    2, 0x0a,    6 /* Public */,
       7,    0,   66,    2, 0x0a,    8 /* Public */,
       8,    0,   67,    2, 0x08,    9 /* Private */,
       9,    0,   68,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::UChar,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EventLoggerStatusLED::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EventLoggerStatusLED *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Start(); break;
        case 1: _t->SetVCIPStatus((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->SetGPSStatus((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1]))); break;
        case 3: _t->SetGSMStatus((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->EventDataReceived(); break;
        case 5: _t->EventLedTimeout(); break;
        case 6: _t->FaultLedTimeout(); break;
        default: ;
        }
    }
}

const QMetaObject EventLoggerStatusLED::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_EventLoggerStatusLED.offsetsAndSize,
    qt_meta_data_EventLoggerStatusLED,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_EventLoggerStatusLED_t
, QtPrivate::TypeAndForceComplete<EventLoggerStatusLED, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<quint8, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *EventLoggerStatusLED::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EventLoggerStatusLED::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EventLoggerStatusLED.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EventLoggerStatusLED::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
