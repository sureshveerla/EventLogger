/****************************************************************************
** Meta object code from reading C++ file 'EventLoggerStatusLED.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/EventLoggerStatusLED.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EventLoggerStatusLED.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN20EventLoggerStatusLEDE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN20EventLoggerStatusLEDE = QtMocHelpers::stringData(
    "EventLoggerStatusLED",
    "Start",
    "",
    "SetVCIPStatus",
    "status",
    "SetGPSStatus",
    "SetGSMStatus",
    "EventDataReceived",
    "VCIPLedTimeout",
    "EventLedTimeout",
    "FaultLedTimeout",
    "GPSLedTimeout"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN20EventLoggerStatusLEDE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x0a,    1 /* Public */,
       3,    1,   69,    2, 0x0a,    2 /* Public */,
       5,    1,   72,    2, 0x0a,    4 /* Public */,
       6,    1,   75,    2, 0x0a,    6 /* Public */,
       7,    0,   78,    2, 0x0a,    8 /* Public */,
       8,    0,   79,    2, 0x08,    9 /* Private */,
       9,    0,   80,    2, 0x08,   10 /* Private */,
      10,    0,   81,    2, 0x08,   11 /* Private */,
      11,    0,   82,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::UChar,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject EventLoggerStatusLED::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN20EventLoggerStatusLEDE.offsetsAndSizes,
    qt_meta_data_ZN20EventLoggerStatusLEDE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN20EventLoggerStatusLEDE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<EventLoggerStatusLED, std::true_type>,
        // method 'Start'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SetVCIPStatus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'SetGPSStatus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        // method 'SetGSMStatus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'EventDataReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'VCIPLedTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'EventLedTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'FaultLedTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'GPSLedTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void EventLoggerStatusLED::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<EventLoggerStatusLED *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->Start(); break;
        case 1: _t->SetVCIPStatus((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->SetGPSStatus((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1]))); break;
        case 3: _t->SetGSMStatus((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->EventDataReceived(); break;
        case 5: _t->VCIPLedTimeout(); break;
        case 6: _t->EventLedTimeout(); break;
        case 7: _t->FaultLedTimeout(); break;
        case 8: _t->GPSLedTimeout(); break;
        default: ;
        }
    }
}

const QMetaObject *EventLoggerStatusLED::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EventLoggerStatusLED::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN20EventLoggerStatusLEDE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EventLoggerStatusLED::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
