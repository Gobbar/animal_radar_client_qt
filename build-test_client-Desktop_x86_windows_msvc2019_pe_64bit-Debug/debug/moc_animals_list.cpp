/****************************************************************************
** Meta object code from reading C++ file 'animals_list.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../test_client/animals_list.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'animals_list.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_animals_list_t {
    QByteArrayData data[10];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_animals_list_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_animals_list_t qt_meta_stringdata_animals_list = {
    {
QT_MOC_LITERAL(0, 0, 12), // "animals_list"
QT_MOC_LITERAL(1, 13, 8), // "set_list"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 7), // "animal*"
QT_MOC_LITERAL(4, 31, 2), // "_a"
QT_MOC_LITERAL(5, 34, 5), // "set_n"
QT_MOC_LITERAL(6, 40, 2), // "_n"
QT_MOC_LITERAL(7, 43, 6), // "set_dt"
QT_MOC_LITERAL(8, 50, 3), // "_dt"
QT_MOC_LITERAL(9, 54, 5) // "get_n"

    },
    "animals_list\0set_list\0\0animal*\0_a\0"
    "set_n\0_n\0set_dt\0_dt\0get_n"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_animals_list[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       5,    1,   37,    2, 0x0a /* Public */,
       7,    1,   40,    2, 0x0a /* Public */,
       9,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Int,

       0        // eod
};

void animals_list::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<animals_list *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->set_list((*reinterpret_cast< animal*(*)>(_a[1]))); break;
        case 1: _t->set_n((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->set_dt((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { int _r = _t->get_n();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< animal* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject animals_list::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_animals_list.data,
    qt_meta_data_animals_list,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *animals_list::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *animals_list::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_animals_list.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int animals_list::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE