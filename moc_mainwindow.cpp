/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include <QDate>
#include "../../Calendar/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Window_t {
    QByteArrayData data[14];
    char stringdata0[234];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Window_t qt_meta_stringdata_Window = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Window"
QT_MOC_LITERAL(1, 7, 13), // "LocaleChanged"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 15), // "FirstDayChanged"
QT_MOC_LITERAL(4, 38, 20), // "SelectionModeChanged"
QT_MOC_LITERAL(5, 59, 23), // "HorizontalHeaderChanged"
QT_MOC_LITERAL(6, 83, 21), // "VerticalHeaderChanged"
QT_MOC_LITERAL(7, 105, 19), // "SelectedDateChanged"
QT_MOC_LITERAL(8, 125, 14), // "MinDateChanged"
QT_MOC_LITERAL(9, 140, 14), // "MaxDateChanged"
QT_MOC_LITERAL(10, 155, 20), // "WeekdayFormatChanged"
QT_MOC_LITERAL(11, 176, 20), // "WeekendFormatChanged"
QT_MOC_LITERAL(12, 197, 15), // "ReformatHeaders"
QT_MOC_LITERAL(13, 213, 20) // "ReformatCalendarPage"

    },
    "Window\0LocaleChanged\0\0FirstDayChanged\0"
    "SelectionModeChanged\0HorizontalHeaderChanged\0"
    "VerticalHeaderChanged\0SelectedDateChanged\0"
    "MinDateChanged\0MaxDateChanged\0"
    "WeekdayFormatChanged\0WeekendFormatChanged\0"
    "ReformatHeaders\0ReformatCalendarPage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Window[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       3,    1,   77,    2, 0x08 /* Private */,
       4,    1,   80,    2, 0x08 /* Private */,
       5,    1,   83,    2, 0x08 /* Private */,
       6,    1,   86,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    1,   90,    2, 0x08 /* Private */,
       9,    1,   93,    2, 0x08 /* Private */,
      10,    0,   96,    2, 0x08 /* Private */,
      11,    0,   97,    2, 0x08 /* Private */,
      12,    0,   98,    2, 0x08 /* Private */,
      13,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    2,
    QMetaType::Void, QMetaType::QDate,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->LocaleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->FirstDayChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->SelectionModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->HorizontalHeaderChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->VerticalHeaderChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->SelectedDateChanged(); break;
        case 6: _t->MinDateChanged((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 7: _t->MaxDateChanged((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 8: _t->WeekdayFormatChanged(); break;
        case 9: _t->WeekendFormatChanged(); break;
        case 10: _t->ReformatHeaders(); break;
        case 11: _t->ReformatCalendarPage(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Window::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Window.data,
    qt_meta_data_Window,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Window.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
