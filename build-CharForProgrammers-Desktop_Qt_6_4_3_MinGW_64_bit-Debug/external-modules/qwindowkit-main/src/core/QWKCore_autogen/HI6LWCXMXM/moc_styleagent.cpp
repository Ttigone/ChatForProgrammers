/****************************************************************************
** Meta object code from reading C++ file 'styleagent.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../../external-modules/qwindowkit-main/src/core/style/styleagent.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'styleagent.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_QWK__StyleAgent_t {
    uint offsetsAndSizes[16];
    char stringdata0[16];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[8];
    char stringdata5[6];
    char stringdata6[5];
    char stringdata7[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QWK__StyleAgent_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QWK__StyleAgent_t qt_meta_stringdata_QWK__StyleAgent = {
    {
        QT_MOC_LITERAL(0, 15),  // "QWK::StyleAgent"
        QT_MOC_LITERAL(16, 18),  // "systemThemeChanged"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 11),  // "SystemTheme"
        QT_MOC_LITERAL(48, 7),  // "Unknown"
        QT_MOC_LITERAL(56, 5),  // "Light"
        QT_MOC_LITERAL(62, 4),  // "Dark"
        QT_MOC_LITERAL(67, 12)   // "HighContrast"
    },
    "QWK::StyleAgent",
    "systemThemeChanged",
    "",
    "SystemTheme",
    "Unknown",
    "Light",
    "Dark",
    "HighContrast"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QWK__StyleAgent[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       1,   21, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // enums: name, alias, flags, count, data
       3,    3, 0x0,    4,   26,

 // enum data: key, value
       4, uint(QWK::StyleAgent::Unknown),
       5, uint(QWK::StyleAgent::Light),
       6, uint(QWK::StyleAgent::Dark),
       7, uint(QWK::StyleAgent::HighContrast),

       0        // eod
};

Q_CONSTINIT const QMetaObject QWK::StyleAgent::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QWK__StyleAgent.offsetsAndSizes,
    qt_meta_data_QWK__StyleAgent,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QWK__StyleAgent_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<StyleAgent, std::true_type>,
        // method 'systemThemeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void QWK::StyleAgent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StyleAgent *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->systemThemeChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (StyleAgent::*)();
            if (_t _q_method = &StyleAgent::systemThemeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *QWK::StyleAgent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QWK::StyleAgent::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QWK__StyleAgent.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QWK::StyleAgent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QWK::StyleAgent::systemThemeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
