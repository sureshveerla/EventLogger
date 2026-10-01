/****************************************************************************
** Meta object code from reading C++ file 'EventLoggerGPS.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../include/EventLoggerGPS.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EventLoggerGPS.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EventLogger_t {
    const uint offsetsAndSize[38];
    char stringdata0[215];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_EventLogger_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_EventLogger_t qt_meta_stringdata_EventLogger = {
    {
QT_MOC_LITERAL(0, 11), // "EventLogger"
QT_MOC_LITERAL(12, 11), // "gpsTOWReady"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 4), // "iTOW"
QT_MOC_LITERAL(30, 17), // "gpsPPSStatusReady"
QT_MOC_LITERAL(48, 5), // "valid"
QT_MOC_LITERAL(54, 11), // "gpsUTCReady"
QT_MOC_LITERAL(66, 7), // "utcTime"
QT_MOC_LITERAL(74, 16), // "gpsPositionReady"
QT_MOC_LITERAL(91, 8), // "latitude"
QT_MOC_LITERAL(100, 9), // "longitude"
QT_MOC_LITERAL(110, 13), // "gpsSpeedReady"
QT_MOC_LITERAL(124, 9), // "speedMMps"
QT_MOC_LITERAL(134, 12), // "gpsFixStatus"
QT_MOC_LITERAL(147, 6), // "status"
QT_MOC_LITERAL(154, 17), // "gpsFixStatusReady"
QT_MOC_LITERAL(172, 11), // "readGPSData"
QT_MOC_LITERAL(184, 14), // "handlePPSEvent"
QT_MOC_LITERAL(199, 15) // "checkPPSTimeout"

    },
    "EventLogger\0gpsTOWReady\0\0iTOW\0"
    "gpsPPSStatusReady\0valid\0gpsUTCReady\0"
    "utcTime\0gpsPositionReady\0latitude\0"
    "longitude\0gpsSpeedReady\0speedMMps\0"
    "gpsFixStatus\0status\0gpsFixStatusReady\0"
    "readGPSData\0handlePPSEvent\0checkPPSTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EventLogger[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    1 /* Public */,
       4,    1,   77,    2, 0x06,    3 /* Public */,
       6,    1,   80,    2, 0x06,    5 /* Public */,
       8,    3,   83,    2, 0x06,    7 /* Public */,
      11,    1,   90,    2, 0x06,   11 /* Public */,
      13,    1,   93,    2, 0x06,   13 /* Public */,
      15,    1,   96,    2, 0x06,   15 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      16,    0,   99,    2, 0x08,   17 /* Private */,
      17,    0,  100,    2, 0x08,   18 /* Private */,
      18,    0,  101,    2, 0x08,   19 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::QDateTime,    7,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Bool,    9,   10,    5,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::UChar,   14,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EventLogger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EventLogger *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->gpsTOWReady((*reinterpret_cast< std::add_pointer_t<quint32>>(_a[1]))); break;
        case 1: _t->gpsPPSStatusReady((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->gpsUTCReady((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1]))); break;
        case 3: _t->gpsPositionReady((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 4: _t->gpsSpeedReady((*reinterpret_cast< std::add_pointer_t<qint32>>(_a[1]))); break;
        case 5: _t->gpsFixStatus((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->gpsFixStatusReady((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1]))); break;
        case 7: _t->readGPSData(); break;
        case 8: _t->handlePPSEvent(); break;
        case 9: _t->checkPPSTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EventLogger::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EventLogger::gpsTOWReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (EventLogger::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EventLogger::gpsPPSStatusReady)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (EventLogger::*)(const QDateTime & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EventLogger::gpsUTCReady)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (EventLogger::*)(double , double , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EventLogger::gpsPositionReady)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (EventLogger::*)(qint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EventLogger::gpsSpeedReady)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (EventLogger::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EventLogger::gpsFixStatus)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (EventLogger::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EventLogger::gpsFixStatusReady)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject EventLogger::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_EventLogger.offsetsAndSize,
    qt_meta_data_EventLogger,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_EventLogger_t
, QtPrivate::TypeAndForceComplete<EventLogger, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<quint32, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QDateTime &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<qint32, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<quint8, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *EventLogger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EventLogger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EventLogger.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EventLogger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void EventLogger::gpsTOWReady(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EventLogger::gpsPPSStatusReady(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EventLogger::gpsUTCReady(const QDateTime & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void EventLogger::gpsPositionReady(double _t1, double _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void EventLogger::gpsSpeedReady(qint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void EventLogger::gpsFixStatus(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void EventLogger::gpsFixStatusReady(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
