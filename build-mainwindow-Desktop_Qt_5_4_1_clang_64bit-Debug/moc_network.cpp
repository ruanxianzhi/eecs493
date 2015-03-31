/****************************************************************************
** Meta object code from reading C++ file 'network.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow/network.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'network.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_netWork_t {
    QByteArrayData data[7];
    char stringdata[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_netWork_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_netWork_t qt_meta_stringdata_netWork = {
    {
QT_MOC_LITERAL(0, 0, 7), // "netWork"
QT_MOC_LITERAL(1, 8, 23), // "processPendingDatagrams"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 14), // "chooseredcolor"
QT_MOC_LITERAL(4, 48, 15), // "choosebluecolor"
QT_MOC_LITERAL(5, 64, 16), // "choosegreencolor"
QT_MOC_LITERAL(6, 81, 17) // "chooseyellowcolor"

    },
    "netWork\0processPendingDatagrams\0\0"
    "chooseredcolor\0choosebluecolor\0"
    "choosegreencolor\0chooseyellowcolor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_netWork[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void netWork::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        netWork *_t = static_cast<netWork *>(_o);
        switch (_id) {
        case 0: _t->processPendingDatagrams(); break;
        case 1: _t->chooseredcolor(); break;
        case 2: _t->choosebluecolor(); break;
        case 3: _t->choosegreencolor(); break;
        case 4: _t->chooseyellowcolor(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject netWork::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_netWork.data,
      qt_meta_data_netWork,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *netWork::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *netWork::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_netWork.stringdata))
        return static_cast<void*>(const_cast< netWork*>(this));
    return QWidget::qt_metacast(_clname);
}

int netWork::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
