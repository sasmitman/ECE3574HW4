/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      46,   11,   11,   11, 0x08,
      72,   11,   11,   11, 0x08,
     100,   11,   11,   11, 0x08,
     129,   11,   11,   11, 0x08,
     158,   11,   11,   11, 0x08,
     188,   11,   11,   11, 0x08,
     212,   11,   11,   11, 0x08,
     235,   11,   11,   11, 0x08,
     254,   11,   11,   11, 0x08,
     277,   11,   11,   11, 0x08,
     300,   11,   11,   11, 0x08,
     319,   11,   11,   11, 0x08,
     339,   11,   11,   11, 0x08,
     361,   11,   11,   11, 0x08,
     387,   11,   11,   11, 0x08,
     408,   11,   11,   11, 0x08,
     424,   11,   11,   11, 0x08,
     440,   11,   11,   11, 0x08,
     456,   11,   11,   11, 0x08,
     472,   11,   11,   11, 0x08,
     488,   11,   11,   11, 0x08,
     504,   11,   11,   11, 0x08,
     520,   11,   11,   11, 0x08,
     536,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_actionRegisterUser_triggered()\0"
    "on_actionExit_triggered()\0"
    "on_actionLogOut_triggered()\0"
    "on_actionNewGame_triggered()\0"
    "on_actionEndGame_triggered()\0"
    "on_actionChangepw_triggered()\0"
    "on_loginlogin_clicked()\0on_loginexit_clicked()\0"
    "on_regOK_clicked()\0on_regCancel_clicked()\0"
    "on_wchangepw_clicked()\0on_wexit_clicked()\0"
    "on_wstart_clicked()\0on_changeok_clicked()\0"
    "on_changecancel_clicked()\0"
    "on_gameend_clicked()\0on_p1_clicked()\0"
    "on_p2_clicked()\0on_p3_clicked()\0"
    "on_p4_clicked()\0on_p5_clicked()\0"
    "on_p6_clicked()\0on_p7_clicked()\0"
    "on_p8_clicked()\0on_p9_clicked()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_actionRegisterUser_triggered(); break;
        case 1: _t->on_actionExit_triggered(); break;
        case 2: _t->on_actionLogOut_triggered(); break;
        case 3: _t->on_actionNewGame_triggered(); break;
        case 4: _t->on_actionEndGame_triggered(); break;
        case 5: _t->on_actionChangepw_triggered(); break;
        case 6: _t->on_loginlogin_clicked(); break;
        case 7: _t->on_loginexit_clicked(); break;
        case 8: _t->on_regOK_clicked(); break;
        case 9: _t->on_regCancel_clicked(); break;
        case 10: _t->on_wchangepw_clicked(); break;
        case 11: _t->on_wexit_clicked(); break;
        case 12: _t->on_wstart_clicked(); break;
        case 13: _t->on_changeok_clicked(); break;
        case 14: _t->on_changecancel_clicked(); break;
        case 15: _t->on_gameend_clicked(); break;
        case 16: _t->on_p1_clicked(); break;
        case 17: _t->on_p2_clicked(); break;
        case 18: _t->on_p3_clicked(); break;
        case 19: _t->on_p4_clicked(); break;
        case 20: _t->on_p5_clicked(); break;
        case 21: _t->on_p6_clicked(); break;
        case 22: _t->on_p7_clicked(); break;
        case 23: _t->on_p8_clicked(); break;
        case 24: _t->on_p9_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
