/****************************************************************************
** Meta object code from reading C++ file 'initfile.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../initfile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'initfile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_initfile_t {
    QByteArrayData data[11];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_initfile_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_initfile_t qt_meta_stringdata_initfile = {
    {
QT_MOC_LITERAL(0, 0, 8), // "initfile"
QT_MOC_LITERAL(1, 9, 8), // "starting"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 6), // "mysql*"
QT_MOC_LITERAL(4, 26, 7), // "mysql_c"
QT_MOC_LITERAL(5, 34, 9), // "json_save"
QT_MOC_LITERAL(6, 44, 18), // "filemysqlInitList*"
QT_MOC_LITERAL(7, 63, 4), // "list"
QT_MOC_LITERAL(8, 68, 14), // "file_mysqlinit"
QT_MOC_LITERAL(9, 83, 17), // "on_submit_clicked"
QT_MOC_LITERAL(10, 101, 17) // "on_cancel_clicked"

    },
    "initfile\0starting\0\0mysql*\0mysql_c\0"
    "json_save\0filemysqlInitList*\0list\0"
    "file_mysqlinit\0on_submit_clicked\0"
    "on_cancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_initfile[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   42,    2, 0x0a /* Public */,
       8,    0,   45,    2, 0x0a /* Public */,
       9,    0,   46,    2, 0x08 /* Private */,
      10,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void initfile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<initfile *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->starting((*reinterpret_cast< mysql*(*)>(_a[1]))); break;
        case 1: _t->json_save((*reinterpret_cast< filemysqlInitList*(*)>(_a[1]))); break;
        case 2: { bool _r = _t->file_mysqlinit();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->on_submit_clicked(); break;
        case 4: _t->on_cancel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< mysql* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (initfile::*)(mysql * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&initfile::starting)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject initfile::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_initfile.data,
    qt_meta_data_initfile,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *initfile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *initfile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_initfile.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int initfile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void initfile::starting(mysql * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
