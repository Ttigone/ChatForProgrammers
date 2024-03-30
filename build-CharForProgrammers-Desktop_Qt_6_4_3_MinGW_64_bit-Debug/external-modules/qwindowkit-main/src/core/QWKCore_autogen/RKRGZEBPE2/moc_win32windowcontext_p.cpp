/****************************************************************************
** Meta object code from reading C++ file 'win32windowcontext_p.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../../external-modules/qwindowkit-main/src/core/contexts/win32windowcontext_p.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'win32windowcontext_p.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_QWK__Win32WindowContext_t {
    uint offsetsAndSizes[2];
    char stringdata0[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QWK__Win32WindowContext_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QWK__Win32WindowContext_t qt_meta_stringdata_QWK__Win32WindowContext = {
    {
        QT_MOC_LITERAL(0, 23)   // "QWK::Win32WindowContext"
    },
    "QWK::Win32WindowContext"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QWK__Win32WindowContext[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject QWK::Win32WindowContext::staticMetaObject = { {
    QMetaObject::SuperData::link<AbstractWindowContext::staticMetaObject>(),
    qt_meta_stringdata_QWK__Win32WindowContext.offsetsAndSizes,
    qt_meta_data_QWK__Win32WindowContext,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QWK__Win32WindowContext_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Win32WindowContext, std::true_type>
    >,
    nullptr
} };

void QWK::Win32WindowContext::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *QWK::Win32WindowContext::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QWK::Win32WindowContext::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QWK__Win32WindowContext.stringdata0))
        return static_cast<void*>(this);
    return AbstractWindowContext::qt_metacast(_clname);
}

int QWK::Win32WindowContext::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractWindowContext::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
