/****************************************************************************
** Meta object code from reading C++ file 'mytext.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mytext.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mytext.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyText_t {
    QByteArrayData data[19];
    char stringdata0[444];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyText_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyText_t qt_meta_stringdata_MyText = {
    {
QT_MOC_LITERAL(0, 0, 6), // "MyText"
QT_MOC_LITERAL(1, 7, 23), // "on_action_new_triggered"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 24), // "on_action_open_triggered"
QT_MOC_LITERAL(4, 57, 24), // "on_action_save_triggered"
QT_MOC_LITERAL(5, 82, 26), // "on_action_saveas_triggered"
QT_MOC_LITERAL(6, 109, 24), // "on_action_exit_triggered"
QT_MOC_LITERAL(7, 134, 24), // "on_action_undo_triggered"
QT_MOC_LITERAL(8, 159, 23), // "on_action_cut_triggered"
QT_MOC_LITERAL(9, 183, 24), // "on_action_copy_triggered"
QT_MOC_LITERAL(10, 208, 25), // "on_action_paste_triggered"
QT_MOC_LITERAL(11, 234, 23), // "on_action_del_triggered"
QT_MOC_LITERAL(12, 258, 24), // "on_action_find_triggered"
QT_MOC_LITERAL(13, 283, 26), // "on_action_replay_triggered"
QT_MOC_LITERAL(14, 310, 23), // "on_action_all_triggered"
QT_MOC_LITERAL(15, 334, 24), // "on_action_font_triggered"
QT_MOC_LITERAL(16, 359, 24), // "on_action_redo_triggered"
QT_MOC_LITERAL(17, 384, 33), // "on_textEdit_cursorPositionCha..."
QT_MOC_LITERAL(18, 418, 25) // "on_action_color_triggered"

    },
    "MyText\0on_action_new_triggered\0\0"
    "on_action_open_triggered\0"
    "on_action_save_triggered\0"
    "on_action_saveas_triggered\0"
    "on_action_exit_triggered\0"
    "on_action_undo_triggered\0"
    "on_action_cut_triggered\0"
    "on_action_copy_triggered\0"
    "on_action_paste_triggered\0"
    "on_action_del_triggered\0"
    "on_action_find_triggered\0"
    "on_action_replay_triggered\0"
    "on_action_all_triggered\0"
    "on_action_font_triggered\0"
    "on_action_redo_triggered\0"
    "on_textEdit_cursorPositionChanged\0"
    "on_action_color_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyText[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    0,  111,    2, 0x08 /* Private */,
      15,    0,  112,    2, 0x08 /* Private */,
      16,    0,  113,    2, 0x08 /* Private */,
      17,    0,  114,    2, 0x08 /* Private */,
      18,    0,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyText::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyText *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_action_new_triggered(); break;
        case 1: _t->on_action_open_triggered(); break;
        case 2: _t->on_action_save_triggered(); break;
        case 3: _t->on_action_saveas_triggered(); break;
        case 4: _t->on_action_exit_triggered(); break;
        case 5: _t->on_action_undo_triggered(); break;
        case 6: _t->on_action_cut_triggered(); break;
        case 7: _t->on_action_copy_triggered(); break;
        case 8: _t->on_action_paste_triggered(); break;
        case 9: _t->on_action_del_triggered(); break;
        case 10: _t->on_action_find_triggered(); break;
        case 11: _t->on_action_replay_triggered(); break;
        case 12: _t->on_action_all_triggered(); break;
        case 13: _t->on_action_font_triggered(); break;
        case 14: _t->on_action_redo_triggered(); break;
        case 15: _t->on_textEdit_cursorPositionChanged(); break;
        case 16: _t->on_action_color_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MyText::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MyText.data,
    qt_meta_data_MyText,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyText::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyText::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyText.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MyText::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
