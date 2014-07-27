/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Fri 4. Feb 17:18:01 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      36,   11,   11,   11, 0x08,
      78,   60,   11,   11, 0x08,
     110,   11,   11,   11, 0x08,
     122,   11,   11,   11, 0x08,
     136,   11,   11,   11, 0x08,
     151,  149,   11,   11, 0x08,
     181,  175,   11,   11, 0x08,
     198,  175,   11,   11, 0x08,
     219,  175,   11,   11, 0x08,
     251,  241,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_backButton_clicked()\0"
    "on_nextButton_clicked()\0username,password\0"
    "setCredentials(QString,QString)\0"
    "showWinha()\0showWebmail()\0showPortal()\0"
    "i\0presentWidgetIndex(int)\0state\0"
    "showFooter(bool)\0mailWidgetDone(bool)\0"
    "winhaWidgetDone(bool)\0temp,cond\0"
    "setWeather(QString,QString)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
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
        switch (_id) {
        case 0: on_backButton_clicked(); break;
        case 1: on_nextButton_clicked(); break;
        case 2: setCredentials((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: showWinha(); break;
        case 4: showWebmail(); break;
        case 5: showPortal(); break;
        case 6: presentWidgetIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: showFooter((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: mailWidgetDone((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: winhaWidgetDone((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: setWeather((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
