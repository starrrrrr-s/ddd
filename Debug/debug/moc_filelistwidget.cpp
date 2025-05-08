/****************************************************************************
** Meta object code from reading C++ file 'filelistwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../filelistwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filelistwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileListWidget_t {
    QByteArrayData data[8];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileListWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileListWidget_t qt_meta_stringdata_FileListWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "FileListWidget"
QT_MOC_LITERAL(1, 15, 11), // "fileRemoved"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "fileName"
QT_MOC_LITERAL(4, 37, 18), // "onContextMenuEvent"
QT_MOC_LITERAL(5, 56, 3), // "pos"
QT_MOC_LITERAL(6, 60, 10), // "onOpenFile"
QT_MOC_LITERAL(7, 71, 12) // "onDeleteFile"

    },
    "FileListWidget\0fileRemoved\0\0fileName\0"
    "onContextMenuEvent\0pos\0onOpenFile\0"
    "onDeleteFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileListWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x08 /* Private */,
       6,    0,   40,    2, 0x08 /* Private */,
       7,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FileListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FileListWidget *_t = static_cast<FileListWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fileRemoved((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onContextMenuEvent((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 2: _t->onOpenFile(); break;
        case 3: _t->onDeleteFile(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (FileListWidget::*_t)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileListWidget::fileRemoved)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FileListWidget::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_FileListWidget.data,
      qt_meta_data_FileListWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FileListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileListWidget.stringdata0))
        return static_cast<void*>(this);
    return QListWidget::qt_metacast(_clname);
}

int FileListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void FileListWidget::fileRemoved(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
