/****************************************************************************
** Meta object code from reading C++ file 'VCOMCOMM.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/KdrobotCppLibs-master/modules/VCOMCOMM/include/VCOMCOMM.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VCOMCOMM.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VCOMCOMM_t {
    QByteArrayData data[15];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VCOMCOMM_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VCOMCOMM_t qt_meta_stringdata_VCOMCOMM = {
    {
QT_MOC_LITERAL(0, 0, 8), // "VCOMCOMM"
QT_MOC_LITERAL(1, 9, 11), // "receiveData"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 7), // "uint8_t"
QT_MOC_LITERAL(4, 30, 8), // "fun_code"
QT_MOC_LITERAL(5, 39, 8), // "uint16_t"
QT_MOC_LITERAL(6, 48, 2), // "id"
QT_MOC_LITERAL(7, 51, 4), // "data"
QT_MOC_LITERAL(8, 56, 25), // "CrossThreadTransmitSignal"
QT_MOC_LITERAL(9, 82, 13), // "portReadyRead"
QT_MOC_LITERAL(10, 96, 17), // "portErrorOccurred"
QT_MOC_LITERAL(11, 114, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(12, 143, 5), // "error"
QT_MOC_LITERAL(13, 149, 11), // "TrackleData"
QT_MOC_LITERAL(14, 161, 8) // "Transmit"

    },
    "VCOMCOMM\0receiveData\0\0uint8_t\0fun_code\0"
    "uint16_t\0id\0data\0CrossThreadTransmitSignal\0"
    "portReadyRead\0portErrorOccurred\0"
    "QSerialPort::SerialPortError\0error\0"
    "TrackleData\0Transmit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VCOMCOMM[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   44,    2, 0x06 /* Public */,
       8,    3,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   58,    2, 0x09 /* Protected */,
      10,    1,   59,    2, 0x09 /* Protected */,
      13,    3,   62,    2, 0x0a /* Public */,
      14,    3,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::QByteArray,    4,    6,    7,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::QByteArray,    4,    6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::QByteArray,    4,    6,    7,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::QByteArray,    4,    6,    7,

       0        // eod
};

void VCOMCOMM::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VCOMCOMM *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receiveData((*reinterpret_cast< uint8_t(*)>(_a[1])),(*reinterpret_cast< uint16_t(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 1: _t->CrossThreadTransmitSignal((*reinterpret_cast< uint8_t(*)>(_a[1])),(*reinterpret_cast< uint16_t(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 2: _t->portReadyRead(); break;
        case 3: _t->portErrorOccurred((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 4: _t->TrackleData((*reinterpret_cast< uint8_t(*)>(_a[1])),(*reinterpret_cast< uint16_t(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 5: _t->Transmit((*reinterpret_cast< uint8_t(*)>(_a[1])),(*reinterpret_cast< uint16_t(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VCOMCOMM::*)(uint8_t , uint16_t , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VCOMCOMM::receiveData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VCOMCOMM::*)(uint8_t , uint16_t , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VCOMCOMM::CrossThreadTransmitSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VCOMCOMM::staticMetaObject = { {
    &QSerialPort::staticMetaObject,
    qt_meta_stringdata_VCOMCOMM.data,
    qt_meta_data_VCOMCOMM,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VCOMCOMM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VCOMCOMM::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VCOMCOMM.stringdata0))
        return static_cast<void*>(this);
    return QSerialPort::qt_metacast(_clname);
}

int VCOMCOMM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSerialPort::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void VCOMCOMM::receiveData(uint8_t _t1, uint16_t _t2, const QByteArray & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VCOMCOMM::CrossThreadTransmitSignal(uint8_t _t1, uint16_t _t2, const QByteArray & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
