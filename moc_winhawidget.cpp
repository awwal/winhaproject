/****************************************************************************
** Meta object code from reading C++ file 'winhawidget.h'
**
** Created: Fri 4. Feb 17:18:12 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "winhawidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'winhawidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Winhawidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   13,   12,   12, 0x05,
      41,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      62,   59,   12,   12, 0x08,
      86,   59,   12,   12, 0x08,
     107,   59,   12,   12, 0x08,
     123,   59,   12,   12, 0x08,
     139,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Winhawidget[] = {
    "Winhawidget\0\0value\0statusUpdate(QString)\0"
    "doneFinally(bool)\0ok\0preCompletionPage(bool)\0"
    "completionPage(bool)\0loginPage(bool)\0"
    "winhaPage(bool)\0onExportBtnClicked()\0"
};

const QMetaObject Winhawidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Winhawidget,
      qt_meta_data_Winhawidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Winhawidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Winhawidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Winhawidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Winhawidget))
        return static_cast<void*>(const_cast< Winhawidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Winhawidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: statusUpdate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: doneFinally((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: preCompletionPage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: completionPage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: loginPage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: winhaPage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: onExportBtnClicked(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Winhawidget::statusUpdate(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Winhawidget::doneFinally(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
