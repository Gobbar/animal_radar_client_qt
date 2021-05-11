/****************************************************************************
** Meta object code from reading C++ file 'database.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../test_client/database.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'database.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_database_t {
    QByteArrayData data[16];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_database_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_database_t qt_meta_stringdata_database = {
    {
QT_MOC_LITERAL(0, 0, 8), // "database"
QT_MOC_LITERAL(1, 9, 10), // "getAnimals"
QT_MOC_LITERAL(2, 20, 7), // "animal*"
QT_MOC_LITERAL(3, 28, 0), // ""
QT_MOC_LITERAL(4, 29, 3), // "str"
QT_MOC_LITERAL(5, 33, 7), // "getSize"
QT_MOC_LITERAL(6, 41, 9), // "setAnimal"
QT_MOC_LITERAL(7, 51, 7), // "animal&"
QT_MOC_LITERAL(8, 59, 1), // "a"
QT_MOC_LITERAL(9, 61, 10), // "_longitude"
QT_MOC_LITERAL(10, 72, 9), // "_latitude"
QT_MOC_LITERAL(11, 82, 5), // "_time"
QT_MOC_LITERAL(12, 88, 6), // "_check"
QT_MOC_LITERAL(13, 95, 9), // "tableName"
QT_MOC_LITERAL(14, 105, 6), // "fields"
QT_MOC_LITERAL(15, 112, 6) // "values"

    },
    "database\0getAnimals\0animal*\0\0str\0"
    "getSize\0setAnimal\0animal&\0a\0_longitude\0"
    "_latitude\0_time\0_check\0tableName\0"
    "fields\0values"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_database[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    3, 0x0a /* Public */,
       5,    1,   47,    3, 0x0a /* Public */,
       6,    1,   50,    3, 0x0a /* Public */,
       6,    4,   53,    3, 0x0a /* Public */,
       6,    3,   62,    3, 0x2a /* Public | MethodCloned */,
       6,    3,   69,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2, QMetaType::QString,    4,
    QMetaType::Int, QMetaType::QString,    4,
    QMetaType::Bool, 0x80000000 | 7,    8,
    QMetaType::Bool, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Bool,    9,   10,   11,   12,
    QMetaType::Bool, QMetaType::Double, QMetaType::Double, QMetaType::Int,    9,   10,   11,
    QMetaType::Bool, QMetaType::QString, QMetaType::QStringList, QMetaType::QStringList,   13,   14,   15,

       0        // eod
};

void database::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<database *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { animal* _r = _t->getAnimals((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< animal**>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->getSize((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->setAnimal((*reinterpret_cast< animal(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->setAnimal((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->setAnimal((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->setAnimal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject database::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_database.data,
    qt_meta_data_database,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *database::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *database::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_database.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int database::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
