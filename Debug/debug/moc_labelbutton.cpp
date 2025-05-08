/****************************************************************************
** Meta object code from reading C++ file 'labelbutton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../labelbutton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'labelbutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LabelButton_t {
    QByteArrayData data[12];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LabelButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LabelButton_t qt_meta_stringdata_LabelButton = {
    {
QT_MOC_LITERAL(0, 0, 11), // "LabelButton"
QT_MOC_LITERAL(1, 12, 10), // "mouseLeave"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10), // "mouseEnter"
QT_MOC_LITERAL(4, 35, 7), // "clicked"
QT_MOC_LITERAL(5, 43, 7), // "pressed"
QT_MOC_LITERAL(6, 51, 8), // "released"
QT_MOC_LITERAL(7, 60, 6), // "dropIn"
QT_MOC_LITERAL(8, 67, 8), // "filePath"
QT_MOC_LITERAL(9, 76, 14), // "ShowEnterStyle"
QT_MOC_LITERAL(10, 91, 16), // "ShowPressedStyle"
QT_MOC_LITERAL(11, 108, 17) // "ShowReleasedStyle"

    },
    "LabelButton\0mouseLeave\0\0mouseEnter\0"
    "clicked\0pressed\0released\0dropIn\0"
    "filePath\0ShowEnterStyle\0ShowPressedStyle\0"
    "ShowReleasedStyle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LabelButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,
       7,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   67,    2, 0x0a /* Public */,
      10,    0,   68,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LabelButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LabelButton *_t = static_cast<LabelButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mouseLeave(); break;
        case 1: _t->mouseEnter(); break;
        case 2: _t->clicked(); break;
        case 3: _t->pressed(); break;
        case 4: _t->released(); break;
        case 5: _t->dropIn((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->ShowEnterStyle(); break;
        case 7: _t->ShowPressedStyle(); break;
        case 8: _t->ShowReleasedStyle(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (LabelButton::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelButton::mouseLeave)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LabelButton::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelButton::mouseEnter)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (LabelButton::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelButton::clicked)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (LabelButton::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelButton::pressed)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (LabelButton::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelButton::released)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (LabelButton::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelButton::dropIn)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LabelButton::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_LabelButton.data,
      qt_meta_data_LabelButton,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LabelButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LabelButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LabelButton.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int LabelButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void LabelButton::mouseLeave()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LabelButton::mouseEnter()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void LabelButton::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void LabelButton::pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void LabelButton::released()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void LabelButton::dropIn(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
