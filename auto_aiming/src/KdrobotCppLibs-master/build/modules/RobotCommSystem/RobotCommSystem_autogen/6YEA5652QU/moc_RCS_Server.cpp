/****************************************************************************
** Meta object code from reading C++ file 'RCS_Server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "RCS_Server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RCS_Server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RCS_Server_t {
    QByteArrayData data[28];
    char stringdata0[375];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RCS_Server_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RCS_Server_t qt_meta_stringdata_RCS_Server = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RCS_Server"
QT_MOC_LITERAL(1, 11, 9), // "NewClient"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 12), // "QHostAddress"
QT_MOC_LITERAL(4, 35, 4), // "addr"
QT_MOC_LITERAL(5, 40, 4), // "name"
QT_MOC_LITERAL(6, 45, 18), // "ClientDisconnected"
QT_MOC_LITERAL(7, 64, 13), // "signal_RETURN"
QT_MOC_LITERAL(8, 78, 21), // "TcpConnect::PACK_TYPE"
QT_MOC_LITERAL(9, 100, 4), // "type"
QT_MOC_LITERAL(10, 105, 3), // "ret"
QT_MOC_LITERAL(11, 109, 16), // "signal_BROADCAST"
QT_MOC_LITERAL(12, 126, 4), // "from"
QT_MOC_LITERAL(13, 131, 13), // "broadcastName"
QT_MOC_LITERAL(14, 145, 7), // "message"
QT_MOC_LITERAL(15, 153, 23), // "tcpServer_newConnection"
QT_MOC_LITERAL(16, 177, 23), // "TcpConnect_receive_HEAD"
QT_MOC_LITERAL(17, 201, 11), // "TcpConnect*"
QT_MOC_LITERAL(18, 213, 11), // "pTcpConnect"
QT_MOC_LITERAL(19, 225, 28), // "TcpConnect_receive_BROADCAST"
QT_MOC_LITERAL(20, 254, 23), // "TcpConnect_receive_PUSH"
QT_MOC_LITERAL(21, 278, 6), // "sendTo"
QT_MOC_LITERAL(22, 285, 3), // "var"
QT_MOC_LITERAL(23, 289, 3), // "obj"
QT_MOC_LITERAL(24, 293, 22), // "TcpConnect_receive_GET"
QT_MOC_LITERAL(25, 316, 4), // "info"
QT_MOC_LITERAL(26, 321, 29), // "TcpConnect_receive_CLIENT_RET"
QT_MOC_LITERAL(27, 351, 23) // "TcpConnect_disconnected"

    },
    "RCS_Server\0NewClient\0\0QHostAddress\0"
    "addr\0name\0ClientDisconnected\0signal_RETURN\0"
    "TcpConnect::PACK_TYPE\0type\0ret\0"
    "signal_BROADCAST\0from\0broadcastName\0"
    "message\0tcpServer_newConnection\0"
    "TcpConnect_receive_HEAD\0TcpConnect*\0"
    "pTcpConnect\0TcpConnect_receive_BROADCAST\0"
    "TcpConnect_receive_PUSH\0sendTo\0var\0"
    "obj\0TcpConnect_receive_GET\0info\0"
    "TcpConnect_receive_CLIENT_RET\0"
    "TcpConnect_disconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RCS_Server[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       6,    1,   74,    2, 0x06 /* Public */,
       7,    2,   77,    2, 0x06 /* Public */,
      11,    3,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,   89,    2, 0x09 /* Protected */,
      16,    2,   90,    2, 0x09 /* Protected */,
      19,    3,   95,    2, 0x09 /* Protected */,
      20,    4,  102,    2, 0x09 /* Protected */,
      24,    4,  111,    2, 0x09 /* Protected */,
      26,    3,  120,    2, 0x09 /* Protected */,
      27,    1,  127,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 8, QMetaType::QJsonObject,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QJsonObject,   12,   13,   14,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17, QMetaType::QString,   18,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QJsonObject,   12,   13,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QJsonObject,   12,   21,   22,   23,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QJsonObject,   12,   21,   22,   25,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QJsonObject,   12,   21,   10,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void RCS_Server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RCS_Server *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NewClient((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->ClientDisconnected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->signal_RETURN((*reinterpret_cast< TcpConnect::PACK_TYPE(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2]))); break;
        case 3: _t->signal_BROADCAST((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QJsonObject(*)>(_a[3]))); break;
        case 4: _t->tcpServer_newConnection(); break;
        case 5: _t->TcpConnect_receive_HEAD((*reinterpret_cast< TcpConnect*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->TcpConnect_receive_BROADCAST((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QJsonObject(*)>(_a[3]))); break;
        case 7: _t->TcpConnect_receive_PUSH((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QJsonObject(*)>(_a[4]))); break;
        case 8: _t->TcpConnect_receive_GET((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QJsonObject(*)>(_a[4]))); break;
        case 9: _t->TcpConnect_receive_CLIENT_RET((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QJsonObject(*)>(_a[3]))); break;
        case 10: _t->TcpConnect_disconnected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TcpConnect* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RCS_Server::*)(const QHostAddress & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RCS_Server::NewClient)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RCS_Server::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RCS_Server::ClientDisconnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RCS_Server::*)(TcpConnect::PACK_TYPE , const QJsonObject & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RCS_Server::signal_RETURN)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (RCS_Server::*)(const QString & , const QString & , const QJsonObject & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RCS_Server::signal_BROADCAST)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RCS_Server::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_RCS_Server.data,
    qt_meta_data_RCS_Server,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RCS_Server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RCS_Server::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RCS_Server.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RCS_Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void RCS_Server::NewClient(const QHostAddress & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RCS_Server::ClientDisconnected(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RCS_Server::signal_RETURN(TcpConnect::PACK_TYPE _t1, const QJsonObject & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RCS_Server::signal_BROADCAST(const QString & _t1, const QString & _t2, const QJsonObject & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
