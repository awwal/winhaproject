/****************************************************************************
** Meta object code from reading C++ file 'loginform.h'
**
** Created: Sat Dec 25 21:06:00 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "loginform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LoginForm[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      56,   10,   10,   10, 0x08,
      89,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LoginForm[] = {
    "LoginForm\0\0username,password\0"
    "loginDone(QString,QString)\0"
    "on_passwordfield_returnPressed()\0"
    "on_pushButton_clicked()\0"
};

const QMetaObject LoginForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LoginForm,
      qt_meta_data_LoginForm, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LoginForm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LoginForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LoginForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LoginForm))
        return static_cast<void*>(const_cast< LoginForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int LoginForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: loginDone((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: on_passwordfield_returnPressed(); break;
        case 2: on_pushButton_clicked(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void LoginForm::loginDone(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
