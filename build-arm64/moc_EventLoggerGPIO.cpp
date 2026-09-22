/****************************************************************************
** Meta object code from reading C++ file 'EventLoggerGPIO.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../include/EventLoggerGPIO.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EventLoggerGPIO.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EventLoggerGPIO_t {
    const uint offsetsAndSize[30];
    char stringdata0[219];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_EventLoggerGPIO_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_EventLoggerGPIO_t qt_meta_stringdata_EventLoggerGPIO = {
    {
QT_MOC_LITERAL(0, 15), // "EventLoggerGPIO"
QT_MOC_LITERAL(16, 14), // "onGPSReadyRead"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 17), // "onGPSBlinkTimeout"
QT_MOC_LITERAL(50, 20), // "onGPSWatchdogTimeout"
QT_MOC_LITERAL(71, 17), // "onGSMCheckTimeout"
QT_MOC_LITERAL(89, 15), // "onVCPingTimeout"
QT_MOC_LITERAL(105, 14), // "onPingFinished"
QT_MOC_LITERAL(120, 8), // "exitCode"
QT_MOC_LITERAL(129, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(150, 10), // "exitStatus"
QT_MOC_LITERAL(161, 11), // "onPingError"
QT_MOC_LITERAL(173, 22), // "QProcess::ProcessError"
QT_MOC_LITERAL(196, 5), // "error"
QT_MOC_LITERAL(202, 16) // "onVCBlinkTimeout"

    },
    "EventLoggerGPIO\0onGPSReadyRead\0\0"
    "onGPSBlinkTimeout\0onGPSWatchdogTimeout\0"
    "onGSMCheckTimeout\0onVCPingTimeout\0"
    "onPingFinished\0exitCode\0QProcess::ExitStatus\0"
    "exitStatus\0onPingError\0QProcess::ProcessError\0"
    "error\0onVCBlinkTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EventLoggerGPIO[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x08,    1 /* Private */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    2,   67,    2, 0x08,    6 /* Private */,
      11,    1,   72,    2, 0x08,    9 /* Private */,
      14,    0,   75,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 9,    8,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,

       0        // eod
};

void EventLoggerGPIO::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EventLoggerGPIO *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onGPSReadyRead(); break;
        case 1: _t->onGPSBlinkTimeout(); break;
        case 2: _t->onGPSWatchdogTimeout(); break;
        case 3: _t->onGSMCheckTimeout(); break;
        case 4: _t->onVCPingTimeout(); break;
        case 5: _t->onPingFinished((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QProcess::ExitStatus>>(_a[2]))); break;
        case 6: _t->onPingError((*reinterpret_cast< std::add_pointer_t<QProcess::ProcessError>>(_a[1]))); break;
        case 7: _t->onVCBlinkTimeout(); break;
        default: ;
        }
    }
}

const QMetaObject EventLoggerGPIO::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_EventLoggerGPIO.offsetsAndSize,
    qt_meta_data_EventLoggerGPIO,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_EventLoggerGPIO_t
, QtPrivate::TypeAndForceComplete<EventLoggerGPIO, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QProcess::ExitStatus, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QProcess::ProcessError, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *EventLoggerGPIO::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EventLoggerGPIO::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EventLoggerGPIO.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EventLoggerGPIO::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
