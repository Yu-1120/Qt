/****************************************************************************
** Meta object code from reading C++ file 'mymplayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mymplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mymplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyMplayer_t {
    QByteArrayData data[13];
    char stringdata0[305];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyMplayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyMplayer_t qt_meta_stringdata_MyMplayer = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MyMplayer"
QT_MOC_LITERAL(1, 10, 30), // "on_pushButton_addvideo_clicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 33), // "on_pushButton_deletevideo_cli..."
QT_MOC_LITERAL(4, 76, 32), // "on_pushButton_clearvideo_clicked"
QT_MOC_LITERAL(5, 109, 26), // "on_pushButton_play_clicked"
QT_MOC_LITERAL(6, 136, 28), // "on_pushButton_cancel_clicked"
QT_MOC_LITERAL(7, 165, 31), // "on_pushButton_stop_cont_clicked"
QT_MOC_LITERAL(8, 197, 26), // "on_pushButton_prev_clicked"
QT_MOC_LITERAL(9, 224, 26), // "on_pushButton_next_clicked"
QT_MOC_LITERAL(10, 251, 31), // "on_listWidget_itemDoubleClicked"
QT_MOC_LITERAL(11, 283, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(12, 300, 4) // "item"

    },
    "MyMplayer\0on_pushButton_addvideo_clicked\0"
    "\0on_pushButton_deletevideo_clicked\0"
    "on_pushButton_clearvideo_clicked\0"
    "on_pushButton_play_clicked\0"
    "on_pushButton_cancel_clicked\0"
    "on_pushButton_stop_cont_clicked\0"
    "on_pushButton_prev_clicked\0"
    "on_pushButton_next_clicked\0"
    "on_listWidget_itemDoubleClicked\0"
    "QListWidgetItem*\0item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyMplayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    1,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void MyMplayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyMplayer *_t = static_cast<MyMplayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_addvideo_clicked(); break;
        case 1: _t->on_pushButton_deletevideo_clicked(); break;
        case 2: _t->on_pushButton_clearvideo_clicked(); break;
        case 3: _t->on_pushButton_play_clicked(); break;
        case 4: _t->on_pushButton_cancel_clicked(); break;
        case 5: _t->on_pushButton_stop_cont_clicked(); break;
        case 6: _t->on_pushButton_prev_clicked(); break;
        case 7: _t->on_pushButton_next_clicked(); break;
        case 8: _t->on_listWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MyMplayer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyMplayer.data,
      qt_meta_data_MyMplayer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyMplayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyMplayer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyMplayer.stringdata0))
        return static_cast<void*>(const_cast< MyMplayer*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyMplayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
