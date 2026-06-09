/****************************************************************************
** Meta object code from reading C++ file 'kavachpkthandler.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../include/kavachpkthandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kavachpkthandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KavachPktHandler_t {
    const uint offsetsAndSize[34];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_KavachPktHandler_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_KavachPktHandler_t qt_meta_stringdata_KavachPktHandler = {
    {
QT_MOC_LITERAL(0, 16), // "KavachPktHandler"
QT_MOC_LITERAL(17, 7), // "logToDB"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 7), // "message"
QT_MOC_LITERAL(34, 12), // "updatePrompt"
QT_MOC_LITERAL(47, 7), // "sendAck"
QT_MOC_LITERAL(55, 12), // "QHostAddress"
QT_MOC_LITERAL(68, 2), // "ip"
QT_MOC_LITERAL(71, 4), // "port"
QT_MOC_LITERAL(76, 7), // "sendSMS"
QT_MOC_LITERAL(84, 17), // "SigNewFaultPacket"
QT_MOC_LITERAL(102, 8), // "senderIP"
QT_MOC_LITERAL(111, 10), // "senderPort"
QT_MOC_LITERAL(122, 8), // "datagram"
QT_MOC_LITERAL(131, 20), // "SigPreviousFaultInfo"
QT_MOC_LITERAL(152, 20), // "SigStationConnStatus"
QT_MOC_LITERAL(173, 13) // "enqueuePacket"

    },
    "KavachPktHandler\0logToDB\0\0message\0"
    "updatePrompt\0sendAck\0QHostAddress\0ip\0"
    "port\0sendSMS\0SigNewFaultPacket\0senderIP\0"
    "senderPort\0datagram\0SigPreviousFaultInfo\0"
    "SigStationConnStatus\0enqueuePacket"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KavachPktHandler[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       4,    1,   65,    2, 0x06,    3 /* Public */,
       5,    2,   68,    2, 0x06,    5 /* Public */,
       9,    1,   73,    2, 0x06,    8 /* Public */,
      10,    3,   76,    2, 0x06,   10 /* Public */,
      14,    0,   83,    2, 0x06,   14 /* Public */,
      15,    0,   84,    2, 0x06,   15 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      16,    3,   85,    2, 0x0a,   16 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 6, QMetaType::UShort,    7,    8,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 6, QMetaType::UShort, QMetaType::QByteArray,   11,   12,   13,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, QMetaType::UShort, QMetaType::QByteArray,   11,   12,   13,

       0        // eod
};

void KavachPktHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KavachPktHandler *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->logToDB((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->updatePrompt((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->sendAck((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2]))); break;
        case 3: _t->sendSMS((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->SigNewFaultPacket((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[3]))); break;
        case 5: _t->SigPreviousFaultInfo(); break;
        case 6: _t->SigStationConnStatus(); break;
        case 7: _t->enqueuePacket((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KavachPktHandler::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KavachPktHandler::logToDB)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (KavachPktHandler::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KavachPktHandler::updatePrompt)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (KavachPktHandler::*)(QHostAddress , quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KavachPktHandler::sendAck)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (KavachPktHandler::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KavachPktHandler::sendSMS)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (KavachPktHandler::*)(QHostAddress , quint16 , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KavachPktHandler::SigNewFaultPacket)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (KavachPktHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KavachPktHandler::SigPreviousFaultInfo)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (KavachPktHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KavachPktHandler::SigStationConnStatus)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject KavachPktHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_KavachPktHandler.offsetsAndSize,
    qt_meta_data_KavachPktHandler,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_KavachPktHandler_t
, QtPrivate::TypeAndForceComplete<KavachPktHandler, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>


>,
    nullptr
} };


const QMetaObject *KavachPktHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KavachPktHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KavachPktHandler.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int KavachPktHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void KavachPktHandler::logToDB(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KavachPktHandler::updatePrompt(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KavachPktHandler::sendAck(QHostAddress _t1, quint16 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void KavachPktHandler::sendSMS(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void KavachPktHandler::SigNewFaultPacket(QHostAddress _t1, quint16 _t2, QByteArray _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void KavachPktHandler::SigPreviousFaultInfo()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void KavachPktHandler::SigStationConnStatus()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
