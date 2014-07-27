/****************************************************************************
** Meta object code from reading C++ file 'winhawindow.h'
**
** Created: Thu Dec 23 15:06:28 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "winhawindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'winhawindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Winhawindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      31,   12,   12,   12, 0x08,
      51,   12,   12,   12, 0x08,
      87,   84,   12,   12, 0x08,
     111,   84,   12,   12, 0x08,
     132,   84,   12,   12, 0x08,
     148,   84,   12,   12, 0x08,
     164,   12,   12,   12, 0x08,
     185,   12,   12,   12, 0x08,
     210,  208,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Winhawindow[] = {
    "Winhawindow\0\0goToLoginScreen()\0"
    "adjustLoginButton()\0"
    "on_passwordField_returnPressed()\0ok\0"
    "preCompletionPage(bool)\0completionPage(bool)\0"
    "loginPage(bool)\0winhaPage(bool)\0"
    "onExportBtnClicked()\0onLoginButtonClicked()\0"
    ",\0setWeather(QString,QString)\0"
};

const QMetaObject Winhawindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Winhawindow,
      qt_meta_data_Winhawindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Winhawindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Winhawindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Winhawindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Winhawindow))
        return static_cast<void*>(const_cast< Winhawindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int Winhawindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: goToLoginScreen(); break;
        case 1: adjustLoginButton(); break;
        case 2: on_passwordField_returnPressed(); break;
        case 3: preCompletionPage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: completionPage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: loginPage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: winhaPage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: onExportBtnClicked(); break;
        case 8: onLoginButtonClicked(); break;
        case 9: setWeather((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
