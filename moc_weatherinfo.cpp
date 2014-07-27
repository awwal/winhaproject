/****************************************************************************
** Meta object code from reading C++ file 'weatherinfo.h'
**
** Created: Sat Dec 25 21:06:09 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "weatherinfo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weatherinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WeatherInfo[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      65,   52,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_WeatherInfo[] = {
    "WeatherInfo\0\0temp,cond\0"
    "valuesReady(QString,QString)\0networkReply\0"
    "handleNetworkData(QNetworkReply*)\0"
};

const QMetaObject WeatherInfo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WeatherInfo,
      qt_meta_data_WeatherInfo, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WeatherInfo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WeatherInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WeatherInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WeatherInfo))
        return static_cast<void*>(const_cast< WeatherInfo*>(this));
    return QWidget::qt_metacast(_clname);
}

int WeatherInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: valuesReady((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: handleNetworkData((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void WeatherInfo::valuesReady(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
