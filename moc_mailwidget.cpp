/****************************************************************************
** Meta object code from reading C++ file 'mailwidget.h'
**
** Created: Fri 4. Feb 17:18:06 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mailwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mailwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MailWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x05,
      40,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      61,   58,   11,   11, 0x08,
      77,   58,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MailWidget[] = {
    "MailWidget\0\0value\0statusUpdate(QString)\0"
    "doneFinally(bool)\0ok\0loginPage(bool)\0"
    "mailPage(bool)\0"
};

const QMetaObject MailWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MailWidget,
      qt_meta_data_MailWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MailWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MailWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MailWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MailWidget))
        return static_cast<void*>(const_cast< MailWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MailWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: statusUpdate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: doneFinally((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: loginPage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: mailPage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MailWidget::statusUpdate(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MailWidget::doneFinally(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
