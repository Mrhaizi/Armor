/****************************************************************************
** Meta object code from reading C++ file 'RCS_Client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "RCS_Client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RCS_Client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RCS_Client_t {
    QByteArrayData data[21];
    char stringdata0[226];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RCS_Client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RCS_Client_t qt_meta_stringdata_RCS_Client = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RCS_Client"
QT_MOC_LITERAL(1, 11, 13), // "signal_RETURN"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 21), // "TcpConnect::PACK_TYPE"
QT_MOC_LITERAL(4, 48, 4), // "type"
QT_MOC_LITERAL(5, 53, 3), // "ret"
QT_MOC_LITERAL(6, 57, 16), // "signal_BROADCAST"
QT_MOC_LITERAL(7, 74, 4), // "from"
QT_MOC_LITERAL(8, 79, 13), // "broadcastName"
QT_MOC_LITERAL(9, 93, 7), // "message"
QT_MOC_LITERAL(10, 101, 12), // "disconnected"
QT_MOC_LITERAL(11, 114, 4), // "name"
QT_MOC_LITERAL(12, 119, 12), // "UdpReadyRead"
QT_MOC_LITERAL(13, 132, 11), // "receive_GET"
QT_MOC_LITERAL(14, 144, 3), // "var"
QT_MOC_LITERAL(15, 148, 4), // "info"
QT_MOC_LITERAL(16, 153, 12), // "receive_PUSH"
QT_MOC_LITERAL(17, 166, 3), // "val"
QT_MOC_LITERAL(18, 170, 17), // "receive_BROADCAST"
QT_MOC_LITERAL(19, 188, 18), // "receive_SERVER_RET"
QT_MOC_LITERAL(20, 207, 18) // "receive_CLIENT_RET"

    },
    "RCS_Client\0signal_RETURN\0\0"
    "TcpConnect::PACK_TYPE\0type\0ret\0"
    "signal_BROADCAST\0from\0broadcastName\0"
    "message\0disconnected\0name\0UdpReadyRead\0"
    "receive_GET\0var\0info\0receive_PUSH\0val\0"
    "receive_BROADCAST\0receive_SERVER_RET\0"
    "receive_CLIENT_RET"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RCS_Client[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,
       6,    3,   64,    2, 0x06 /* Public */,
      10,    1,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   74,    2, 0x09 /* Protected */,
      13,    3,   75,    2, 0x09 /* Protected */,
      16,    3,   82,    2, 0x09 /* Protected */,
      18,    3,   89,    2, 0x09 /* Protected */,
      19,    1,   96,    2, 0x09 /* Protected */,
      20,    2,   99,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QJsonObject,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QJsonObject,    7,    8,    9,
    QMetaType::Void, QMetaType::QString,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QJsonObject,    7,   14,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QJsonObject,    7,   14,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QJsonObject,    7,    8,   17,
    QMetaType::Void, QMetaType::QJsonObject,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonObject,    7,    5,

       0        // eod
};

void RCS_Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RCS_Client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_RETURN((*reinterpret_cast< TcpConnect::PACK_TYPE(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2]))); break;
        case 1: _t->signal_BROADCAST((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QJsonObject(*)>(_a[3]))); break;
        case 2: _t->disconnected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->UdpReadyRead(); break;
        case 4: _t->receive_GET((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QJsonObject(*)>(_a[3]))); break;
        case 5: _t->receive_PUSH((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QJsonObject(*)>(_a[3]))); break;
        case 6: _t->receive_BROADCAST((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QJsonObject(*)>(_a[3]))); break;
        case 7: _t->receive_SERVER_RET((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 8: _t->receive_CLIENT_RET((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RCS_Client::*)(TcpConnect::PACK_TYPE , const QJsonObject & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RCS_Client::signal_RETURN)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RCS_Client::*)(const QString & , const QString & , const QJsonObject & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RCS_Client::signal_BROADCAST)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RCS_Client::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RCS_Client::disconnected)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RCS_Client::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_RCS_Client.data,
    qt_meta_data_RCS_Client,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RCS_Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RCS_Client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RCS_Client.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RCS_Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void RCS_Client::signal_RETURN(TcpConnect::PACK_TYPE _t1, const QJsonObject & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RCS_Client::signal_BROADCAST(const QString & _t1, const QString & _t2, const QJsonObject & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RCS_Client::disconnected(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
