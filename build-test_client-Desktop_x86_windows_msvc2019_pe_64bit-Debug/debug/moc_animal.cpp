/****************************************************************************
** Meta object code from reading C++ file 'animal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../test_client/animal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'animal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_animal_t {
    QByteArrayData data[17];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_animal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_animal_t qt_meta_stringdata_animal = {
    {
QT_MOC_LITERAL(0, 0, 6), // "animal"
QT_MOC_LITERAL(1, 7, 6), // "get_id"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 13), // "get_longitude"
QT_MOC_LITERAL(4, 29, 12), // "get_latitude"
QT_MOC_LITERAL(5, 42, 8), // "get_time"
QT_MOC_LITERAL(6, 51, 9), // "on_server"
QT_MOC_LITERAL(7, 61, 6), // "set_id"
QT_MOC_LITERAL(8, 68, 3), // "_id"
QT_MOC_LITERAL(9, 72, 13), // "set_longitude"
QT_MOC_LITERAL(10, 86, 10), // "_longitude"
QT_MOC_LITERAL(11, 97, 12), // "set_latitude"
QT_MOC_LITERAL(12, 110, 9), // "_latitude"
QT_MOC_LITERAL(13, 120, 8), // "set_time"
QT_MOC_LITERAL(14, 129, 5), // "_time"
QT_MOC_LITERAL(15, 135, 9), // "set_check"
QT_MOC_LITERAL(16, 145, 6) // "_check"

    },
    "animal\0get_id\0\0get_longitude\0get_latitude\0"
    "get_time\0on_server\0set_id\0_id\0"
    "set_longitude\0_longitude\0set_latitude\0"
    "_latitude\0set_time\0_time\0set_check\0"
    "_check"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_animal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    0,   70,    2, 0x0a /* Public */,
       4,    0,   71,    2, 0x0a /* Public */,
       5,    0,   72,    2, 0x0a /* Public */,
       6,    0,   73,    2, 0x0a /* Public */,
       7,    1,   74,    2, 0x0a /* Public */,
       9,    1,   77,    2, 0x0a /* Public */,
      11,    1,   80,    2, 0x0a /* Public */,
      13,    1,   83,    2, 0x0a /* Public */,
      15,    1,   86,    2, 0x0a /* Public */,
      13,    0,   89,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::QString,
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::Int,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,

       0        // eod
};

void animal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<animal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->get_id();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: { double _r = _t->get_longitude();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 2: { double _r = _t->get_latitude();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->get_time();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->on_server();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->set_id((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->set_longitude((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->set_latitude((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->set_time((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->set_check((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->set_time(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject animal::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_animal.data,
    qt_meta_data_animal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *animal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *animal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_animal.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int animal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE