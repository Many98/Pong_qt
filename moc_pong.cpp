/****************************************************************************
** Meta object code from reading C++ file 'pong.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pong.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pong.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PONG_t {
    QByteArrayData data[23];
    char stringdata0[320];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PONG_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PONG_t qt_meta_stringdata_PONG = {
    {
QT_MOC_LITERAL(0, 0, 4), // "PONG"
QT_MOC_LITERAL(1, 5, 19), // "ballRacketCollision"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 23), // "ballLeftBorderCollision"
QT_MOC_LITERAL(4, 50, 24), // "ballRightBorderCollision"
QT_MOC_LITERAL(5, 75, 29), // "ballHorizontalBorderCollision"
QT_MOC_LITERAL(6, 105, 13), // "windowResized"
QT_MOC_LITERAL(7, 119, 6), // "update"
QT_MOC_LITERAL(8, 126, 15), // "displayNewScore"
QT_MOC_LITERAL(9, 142, 14), // "centerPosition"
QT_MOC_LITERAL(10, 157, 7), // "newGame"
QT_MOC_LITERAL(11, 165, 10), // "singlePlay"
QT_MOC_LITERAL(12, 176, 9), // "multiPlay"
QT_MOC_LITERAL(13, 186, 11), // "resizeItems"
QT_MOC_LITERAL(14, 198, 15), // "playBorderSound"
QT_MOC_LITERAL(15, 214, 16), // "playClickedSound"
QT_MOC_LITERAL(16, 231, 4), // "mute"
QT_MOC_LITERAL(17, 236, 8), // "setSound"
QT_MOC_LITERAL(18, 245, 8), // "showInfo"
QT_MOC_LITERAL(19, 254, 12), // "showSettings"
QT_MOC_LITERAL(20, 267, 18), // "processNewSettings"
QT_MOC_LITERAL(21, 286, 9), // "pauseGame"
QT_MOC_LITERAL(22, 296, 23) // "resumeAfterDialogWindow"

    },
    "PONG\0ballRacketCollision\0\0"
    "ballLeftBorderCollision\0"
    "ballRightBorderCollision\0"
    "ballHorizontalBorderCollision\0"
    "windowResized\0update\0displayNewScore\0"
    "centerPosition\0newGame\0singlePlay\0"
    "multiPlay\0resizeItems\0playBorderSound\0"
    "playClickedSound\0mute\0setSound\0showInfo\0"
    "showSettings\0processNewSettings\0"
    "pauseGame\0resumeAfterDialogWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PONG[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  119,    2, 0x06 /* Public */,
       3,    0,  120,    2, 0x06 /* Public */,
       4,    0,  121,    2, 0x06 /* Public */,
       5,    0,  122,    2, 0x06 /* Public */,
       6,    0,  123,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  124,    2, 0x08 /* Private */,
       8,    0,  125,    2, 0x08 /* Private */,
       9,    0,  126,    2, 0x08 /* Private */,
      10,    0,  127,    2, 0x08 /* Private */,
      11,    0,  128,    2, 0x08 /* Private */,
      12,    0,  129,    2, 0x08 /* Private */,
      13,    0,  130,    2, 0x08 /* Private */,
      14,    0,  131,    2, 0x08 /* Private */,
      15,    0,  132,    2, 0x08 /* Private */,
      16,    0,  133,    2, 0x08 /* Private */,
      17,    0,  134,    2, 0x08 /* Private */,
      18,    0,  135,    2, 0x08 /* Private */,
      19,    0,  136,    2, 0x08 /* Private */,
      20,    0,  137,    2, 0x08 /* Private */,
      21,    0,  138,    2, 0x08 /* Private */,
      22,    0,  139,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

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

       0        // eod
};

void PONG::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PONG *_t = static_cast<PONG *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ballRacketCollision(); break;
        case 1: _t->ballLeftBorderCollision(); break;
        case 2: _t->ballRightBorderCollision(); break;
        case 3: _t->ballHorizontalBorderCollision(); break;
        case 4: _t->windowResized(); break;
        case 5: _t->update(); break;
        case 6: _t->displayNewScore(); break;
        case 7: _t->centerPosition(); break;
        case 8: _t->newGame(); break;
        case 9: _t->singlePlay(); break;
        case 10: _t->multiPlay(); break;
        case 11: _t->resizeItems(); break;
        case 12: _t->playBorderSound(); break;
        case 13: _t->playClickedSound(); break;
        case 14: _t->mute(); break;
        case 15: _t->setSound(); break;
        case 16: _t->showInfo(); break;
        case 17: _t->showSettings(); break;
        case 18: _t->processNewSettings(); break;
        case 19: _t->pauseGame(); break;
        case 20: _t->resumeAfterDialogWindow(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PONG::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PONG::ballRacketCollision)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PONG::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PONG::ballLeftBorderCollision)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (PONG::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PONG::ballRightBorderCollision)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (PONG::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PONG::ballHorizontalBorderCollision)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (PONG::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PONG::windowResized)) {
                *result = 4;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject PONG::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_PONG.data,
      qt_meta_data_PONG,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PONG::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PONG::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PONG.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int PONG::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void PONG::ballRacketCollision()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PONG::ballLeftBorderCollision()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PONG::ballRightBorderCollision()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PONG::ballHorizontalBorderCollision()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void PONG::windowResized()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
