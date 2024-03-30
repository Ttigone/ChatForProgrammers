/****************************************************************************
** Meta object code from reading C++ file 'windowagentbase.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../../external-modules/qwindowkit-main/src/core/windowagentbase.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'windowagentbase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_QWK__WindowAgentBase_t {
    uint offsetsAndSizes[32];
    char stringdata0[21];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[11];
    char stringdata5[6];
    char stringdata6[19];
    char stringdata7[4];
    char stringdata8[10];
    char stringdata9[13];
    char stringdata10[8];
    char stringdata11[11];
    char stringdata12[5];
    char stringdata13[9];
    char stringdata14[9];
    char stringdata15[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QWK__WindowAgentBase_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QWK__WindowAgentBase_t qt_meta_stringdata_QWK__WindowAgentBase = {
    {
        QT_MOC_LITERAL(0, 20),  // "QWK::WindowAgentBase"
        QT_MOC_LITERAL(21, 14),  // "showSystemMenu"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 3),  // "pos"
        QT_MOC_LITERAL(41, 10),  // "centralize"
        QT_MOC_LITERAL(52, 5),  // "raise"
        QT_MOC_LITERAL(58, 18),  // "setWindowAttribute"
        QT_MOC_LITERAL(77, 3),  // "key"
        QT_MOC_LITERAL(81, 9),  // "attribute"
        QT_MOC_LITERAL(91, 12),  // "SystemButton"
        QT_MOC_LITERAL(104, 7),  // "Unknown"
        QT_MOC_LITERAL(112, 10),  // "WindowIcon"
        QT_MOC_LITERAL(123, 4),  // "Help"
        QT_MOC_LITERAL(128, 8),  // "Minimize"
        QT_MOC_LITERAL(137, 8),  // "Maximize"
        QT_MOC_LITERAL(146, 5)   // "Close"
    },
    "QWK::WindowAgentBase",
    "showSystemMenu",
    "",
    "pos",
    "centralize",
    "raise",
    "setWindowAttribute",
    "key",
    "attribute",
    "SystemButton",
    "Unknown",
    "WindowIcon",
    "Help",
    "Minimize",
    "Maximize",
    "Close"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QWK__WindowAgentBase[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       1,   48, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x0a,    1 /* Public */,
       4,    0,   41,    2, 0x0a,    3 /* Public */,
       5,    0,   42,    2, 0x0a,    4 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       6,    2,   43,    2, 0x02,    5 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::QVariant,    7,    8,

 // enums: name, alias, flags, count, data
       9,    9, 0x0,    6,   53,

 // enum data: key, value
      10, uint(QWK::WindowAgentBase::Unknown),
      11, uint(QWK::WindowAgentBase::WindowIcon),
      12, uint(QWK::WindowAgentBase::Help),
      13, uint(QWK::WindowAgentBase::Minimize),
      14, uint(QWK::WindowAgentBase::Maximize),
      15, uint(QWK::WindowAgentBase::Close),

       0        // eod
};

Q_CONSTINIT const QMetaObject QWK::WindowAgentBase::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QWK__WindowAgentBase.offsetsAndSizes,
    qt_meta_data_QWK__WindowAgentBase,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QWK__WindowAgentBase_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<WindowAgentBase, std::true_type>,
        // method 'showSystemMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        // method 'centralize'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'raise'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setWindowAttribute'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>
    >,
    nullptr
} };

void QWK::WindowAgentBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WindowAgentBase *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showSystemMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 1: _t->centralize(); break;
        case 2: _t->raise(); break;
        case 3: { bool _r = _t->setWindowAttribute((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *QWK::WindowAgentBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QWK::WindowAgentBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QWK__WindowAgentBase.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QWK::WindowAgentBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
