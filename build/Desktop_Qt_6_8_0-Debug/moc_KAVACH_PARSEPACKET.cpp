/****************************************************************************
** Meta object code from reading C++ file 'KAVACH_PARSEPACKET.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/KAVACH_PARSEPACKET.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KAVACH_PARSEPACKET.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSKAVACH_PARSEPACKETENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSKAVACH_PARSEPACKETENDCLASS = QtMocHelpers::stringData(
    "KAVACH_PARSEPACKET",
    "SigInsertDBStnRegMASubPkt",
    "",
    "MovementAuthorityPkt",
    "stMAPkt",
    "SigInsertDBStnRegSSPSubPkt",
    "StaticSpeedProfilePkt",
    "stSSPPkt",
    "SigInsertDBStnRegGradientSubPkt",
    "GradientProfilePkt",
    "stGradprofPkt",
    "SigInsertDBStnRegLCGateSubPkt",
    "LCGateProfilePkt",
    "stLCGatePkt",
    "SigInsertDBStnRegTurnoutSpeedSubPkt",
    "TurnoutSpeedProfilePkt",
    "stTSPPkt",
    "SigInsertDBStnRegTagLinkingInfoSubPkt",
    "TagLinkingInfoPkt",
    "stTagLinkInfPkt",
    "SigInsertDBStnRegTrackCondDataSubPkt",
    "TrackConditionPkt",
    "stTrackCondDataPkt",
    "SigInsertDBStnRegTSRSubPkt",
    "TempSpeedRestrictionPkt",
    "stTSRPkt",
    "SigStationRegHeader",
    "StationRegularHeader",
    "stStnRglrHPkt"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSKAVACH_PARSEPACKETENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    1 /* Public */,
       5,    1,   71,    2, 0x06,    3 /* Public */,
       8,    1,   74,    2, 0x06,    5 /* Public */,
      11,    1,   77,    2, 0x06,    7 /* Public */,
      14,    1,   80,    2, 0x06,    9 /* Public */,
      17,    1,   83,    2, 0x06,   11 /* Public */,
      20,    1,   86,    2, 0x06,   13 /* Public */,
      23,    1,   89,    2, 0x06,   15 /* Public */,
      26,    1,   92,    2, 0x06,   17 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 27,   28,

       0        // eod
};

Q_CONSTINIT const QMetaObject KAVACH_PARSEPACKET::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSKAVACH_PARSEPACKETENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSKAVACH_PARSEPACKETENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSKAVACH_PARSEPACKETENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<KAVACH_PARSEPACKET, std::true_type>,
        // method 'SigInsertDBStnRegMASubPkt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<MovementAuthorityPkt, std::false_type>,
        // method 'SigInsertDBStnRegSSPSubPkt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<StaticSpeedProfilePkt, std::false_type>,
        // method 'SigInsertDBStnRegGradientSubPkt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<GradientProfilePkt, std::false_type>,
        // method 'SigInsertDBStnRegLCGateSubPkt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<LCGateProfilePkt, std::false_type>,
        // method 'SigInsertDBStnRegTurnoutSpeedSubPkt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<TurnoutSpeedProfilePkt, std::false_type>,
        // method 'SigInsertDBStnRegTagLinkingInfoSubPkt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<TagLinkingInfoPkt, std::false_type>,
        // method 'SigInsertDBStnRegTrackCondDataSubPkt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<TrackConditionPkt, std::false_type>,
        // method 'SigInsertDBStnRegTSRSubPkt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<TempSpeedRestrictionPkt, std::false_type>,
        // method 'SigStationRegHeader'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<StationRegularHeader, std::false_type>
    >,
    nullptr
} };

void KAVACH_PARSEPACKET::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KAVACH_PARSEPACKET *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SigInsertDBStnRegMASubPkt((*reinterpret_cast< std::add_pointer_t<MovementAuthorityPkt>>(_a[1]))); break;
        case 1: _t->SigInsertDBStnRegSSPSubPkt((*reinterpret_cast< std::add_pointer_t<StaticSpeedProfilePkt>>(_a[1]))); break;
        case 2: _t->SigInsertDBStnRegGradientSubPkt((*reinterpret_cast< std::add_pointer_t<GradientProfilePkt>>(_a[1]))); break;
        case 3: _t->SigInsertDBStnRegLCGateSubPkt((*reinterpret_cast< std::add_pointer_t<LCGateProfilePkt>>(_a[1]))); break;
        case 4: _t->SigInsertDBStnRegTurnoutSpeedSubPkt((*reinterpret_cast< std::add_pointer_t<TurnoutSpeedProfilePkt>>(_a[1]))); break;
        case 5: _t->SigInsertDBStnRegTagLinkingInfoSubPkt((*reinterpret_cast< std::add_pointer_t<TagLinkingInfoPkt>>(_a[1]))); break;
        case 6: _t->SigInsertDBStnRegTrackCondDataSubPkt((*reinterpret_cast< std::add_pointer_t<TrackConditionPkt>>(_a[1]))); break;
        case 7: _t->SigInsertDBStnRegTSRSubPkt((*reinterpret_cast< std::add_pointer_t<TempSpeedRestrictionPkt>>(_a[1]))); break;
        case 8: _t->SigStationRegHeader((*reinterpret_cast< std::add_pointer_t<StationRegularHeader>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KAVACH_PARSEPACKET::*)(MovementAuthorityPkt );
            if (_t _q_method = &KAVACH_PARSEPACKET::SigInsertDBStnRegMASubPkt; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (KAVACH_PARSEPACKET::*)(StaticSpeedProfilePkt );
            if (_t _q_method = &KAVACH_PARSEPACKET::SigInsertDBStnRegSSPSubPkt; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (KAVACH_PARSEPACKET::*)(GradientProfilePkt );
            if (_t _q_method = &KAVACH_PARSEPACKET::SigInsertDBStnRegGradientSubPkt; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (KAVACH_PARSEPACKET::*)(LCGateProfilePkt );
            if (_t _q_method = &KAVACH_PARSEPACKET::SigInsertDBStnRegLCGateSubPkt; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (KAVACH_PARSEPACKET::*)(TurnoutSpeedProfilePkt );
            if (_t _q_method = &KAVACH_PARSEPACKET::SigInsertDBStnRegTurnoutSpeedSubPkt; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (KAVACH_PARSEPACKET::*)(TagLinkingInfoPkt );
            if (_t _q_method = &KAVACH_PARSEPACKET::SigInsertDBStnRegTagLinkingInfoSubPkt; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (KAVACH_PARSEPACKET::*)(TrackConditionPkt );
            if (_t _q_method = &KAVACH_PARSEPACKET::SigInsertDBStnRegTrackCondDataSubPkt; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (KAVACH_PARSEPACKET::*)(TempSpeedRestrictionPkt );
            if (_t _q_method = &KAVACH_PARSEPACKET::SigInsertDBStnRegTSRSubPkt; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (KAVACH_PARSEPACKET::*)(StationRegularHeader );
            if (_t _q_method = &KAVACH_PARSEPACKET::SigStationRegHeader; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject *KAVACH_PARSEPACKET::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KAVACH_PARSEPACKET::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSKAVACH_PARSEPACKETENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int KAVACH_PARSEPACKET::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void KAVACH_PARSEPACKET::SigInsertDBStnRegMASubPkt(MovementAuthorityPkt _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KAVACH_PARSEPACKET::SigInsertDBStnRegSSPSubPkt(StaticSpeedProfilePkt _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KAVACH_PARSEPACKET::SigInsertDBStnRegGradientSubPkt(GradientProfilePkt _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void KAVACH_PARSEPACKET::SigInsertDBStnRegLCGateSubPkt(LCGateProfilePkt _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void KAVACH_PARSEPACKET::SigInsertDBStnRegTurnoutSpeedSubPkt(TurnoutSpeedProfilePkt _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void KAVACH_PARSEPACKET::SigInsertDBStnRegTagLinkingInfoSubPkt(TagLinkingInfoPkt _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void KAVACH_PARSEPACKET::SigInsertDBStnRegTrackCondDataSubPkt(TrackConditionPkt _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void KAVACH_PARSEPACKET::SigInsertDBStnRegTSRSubPkt(TempSpeedRestrictionPkt _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void KAVACH_PARSEPACKET::SigStationRegHeader(StationRegularHeader _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
