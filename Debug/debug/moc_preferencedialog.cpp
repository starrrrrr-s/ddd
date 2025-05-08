/****************************************************************************
** Meta object code from reading C++ file 'preferencedialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../preferencedialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'preferencedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PreferenceDialog_t {
    QByteArrayData data[12];
    char stringdata0[291];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PreferenceDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PreferenceDialog_t qt_meta_stringdata_PreferenceDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "PreferenceDialog"
QT_MOC_LITERAL(1, 17, 28), // "on_pushButton_import_clicked"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 28), // "on_pushButton_export_clicked"
QT_MOC_LITERAL(4, 76, 35), // "on_pushButton_interfaceFont_c..."
QT_MOC_LITERAL(5, 112, 31), // "on_pushButton_eventFont_clicked"
QT_MOC_LITERAL(6, 144, 31), // "on_pushButton_cellColor_clicked"
QT_MOC_LITERAL(7, 176, 34), // "on_pushButton_eventColor_1_cl..."
QT_MOC_LITERAL(8, 211, 34), // "on_pushButton_eventColor_2_cl..."
QT_MOC_LITERAL(9, 246, 20), // "on_buttonBox_clicked"
QT_MOC_LITERAL(10, 267, 16), // "QAbstractButton*"
QT_MOC_LITERAL(11, 284, 6) // "button"

    },
    "PreferenceDialog\0on_pushButton_import_clicked\0"
    "\0on_pushButton_export_clicked\0"
    "on_pushButton_interfaceFont_clicked\0"
    "on_pushButton_eventFont_clicked\0"
    "on_pushButton_cellColor_clicked\0"
    "on_pushButton_eventColor_1_clicked\0"
    "on_pushButton_eventColor_2_clicked\0"
    "on_buttonBox_clicked\0QAbstractButton*\0"
    "button"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PreferenceDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    1,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void PreferenceDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PreferenceDialog *_t = static_cast<PreferenceDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_import_clicked(); break;
        case 1: _t->on_pushButton_export_clicked(); break;
        case 2: _t->on_pushButton_interfaceFont_clicked(); break;
        case 3: _t->on_pushButton_eventFont_clicked(); break;
        case 4: _t->on_pushButton_cellColor_clicked(); break;
        case 5: _t->on_pushButton_eventColor_1_clicked(); break;
        case 6: _t->on_pushButton_eventColor_2_clicked(); break;
        case 7: _t->on_buttonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PreferenceDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PreferenceDialog.data,
      qt_meta_data_PreferenceDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PreferenceDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PreferenceDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PreferenceDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int PreferenceDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
