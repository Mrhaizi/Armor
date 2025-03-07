/**
 * @file VCOMCOMM.cpp
 * @author yao
 * @date 2021年1月13日
 * @brief 虚拟串口通信协议的PC端
 */

#include "VCOMCOMM.h"
#include <iostream>
#include <QSerialPortInfo>
#include "CRC.h"

VCOMCOMM::VCOMCOMM(uint16_t PID, uint16_t VID, QObject *parent) : QSerialPort(parent), logger(__FUNCTION__) {
    pid = PID;
    vid = VID;
    thread_id = QThread::currentThreadId();
    connect(this, &QSerialPort::readyRead, this, &VCOMCOMM::portReadyRead);
    connect(this, &QSerialPort::errorOccurred, this, &VCOMCOMM::portErrorOccurred);
    connect(this, &VCOMCOMM::CrossThreadTransmitSignal, this, &VCOMCOMM::Transmit, Qt::QueuedConnection);
    connect(this, &VCOMCOMM::receiveData, this, &VCOMCOMM::TrackleData);
    if (!auto_connect())
        logger.warn("not find VCOMCOMM Device");
}

VCOMCOMM::VCOMCOMM(const QString &manufacturer, QObject *parent)
        : QSerialPort(parent), logger(__FUNCTION__), manufacturer(manufacturer) {
    pid = vid = 0;
    thread_id = QThread::currentThreadId();
    connect(this, &QSerialPort::readyRead, this, &VCOMCOMM::portReadyRead);
    connect(this, &QSerialPort::errorOccurred, this, &VCOMCOMM::portErrorOccurred);
    connect(this, &VCOMCOMM::CrossThreadTransmitSignal, this, &VCOMCOMM::Transmit, Qt::QueuedConnection);
    connect(this, &VCOMCOMM::receiveData, this, &VCOMCOMM::TrackleData);
    if (!auto_connect())
        logger.warn("not find VCOMCOMM Device");
}

bool VCOMCOMM::auto_connect() {
    QSerialPortInfo selected_port;
    for (const QSerialPortInfo &info : QSerialPortInfo::availablePorts()) {
        if (manufacturer.isEmpty()) {
            if (info.hasVendorIdentifier() && info.hasProductIdentifier() &&
                info.vendorIdentifier() == vid && info.productIdentifier() == pid) {
                selected_port = info;
            }
        } else if (info.manufacturer() == manufacturer) {
            selected_port = info;
        }
    }
    if (!selected_port.isNull()) {
        logger.info("find VCOMCOMM Driver, Port:'{}', Manufacturer:'{}'",
                    selected_port.portName(), selected_port.manufacturer());
        if (this->isOpen()) {
            logger.info("close port and reopen");
            this->close();
        } else logger.info("open port");
        this->setPort(selected_port);
        if (this->open(ReadWrite) && (this->error() == SerialPortError::NoError))
            return true;
        else logger.error("can't open port {}", selected_port.portName());
    }
    return false;
}

void VCOMCOMM::portReadyRead() {
    QByteArray data = this->readAll();
    this->clear(Input);
    uint8_t *pdata = (uint8_t *) data.data();
    if (pdata[0] == 0x5a) {
        uint8_t fun = pdata[1];
        uint16_t id = *((uint16_t *) (pdata + 2));
        uint16_t len = *((uint16_t *) (pdata + 4));
        if (len + 8 != data.size())
            return;
        uint16_t crc = *((uint16_t *) (pdata + 6 + len));
        QByteArray array((const char *) (pdata + 6), len);
        uint16_t c = CRC::Verify_CRC16_Check_Sum(array);
        if (len == 0 || c == crc) {
            logger.debug("RX: fun=0x{:02X}, id=0x{:04X}, crc=0x{:04X}|0x{:04X}", fun, id, crc, c);
            emit receiveData(fun, id, array);
        } else logger.warn("RX: fun=0x{:02X}, id=0x{:04X}, crc=0x{:04X}|0x{:04X} CRC Error", fun, id, crc, c);
    }
}

void VCOMCOMM::portErrorOccurred(SerialPortError error) {
    if (error != NoError) {
        QMetaEnum metaEnum = QMetaEnum::fromType<SerialPortError>();
        logger.error("{}", metaEnum.valueToKey(error));
    }
}

void VCOMCOMM::Transmit(uint8_t fun_code, uint16_t id, const QByteArray &data) {
    if (thread_id != QThread::currentThreadId()) {
        emit CrossThreadTransmitSignal(fun_code, id, data);
        return;
    }
    logger.debug("TX: fun=0x{:02X}, id=0x{:04X}", fun_code, id);
    /* 忽略读写错误 */
    SerialPortError port_err = this->error();
    if (port_err == ReadError || port_err == WriteError)
        port_err = NoError;
    if (!(this->isOpen() && port_err == NoError) && !this->auto_connect()) {
        logger.error("Transmit Error, Port is closed or error");
        return;
    }
    if (data.size() > 64 - 8) {
        logger.error("VCOMCOMM out of range len={}", data.size());
        throw std::runtime_error("VCOMCOMM out of range");
    }
    uint8_t len = (uint8_t) data.size();
    uint8_t buff[64] = {0x5a, fun_code};
    *((uint16_t *) (buff + 2)) = id;
    *((uint16_t *) (buff + 4)) = len;
    memcpy(buff + 6, data.data(), len);
    *((uint16_t *) (buff + 6 + len)) = (len == 0) ? 0 : CRC::Verify_CRC16_Check_Sum(data);
    this->writeData((const char *) buff, len + 8);
    this->waitForBytesWritten(100);
    this->clear(Output);
}
void VCOMCOMM::setPidVid(uint16_t PID, uint16_t VID) {
    pid = PID;
    vid = VID;
}

void VCOMCOMM::setManufacturer(const QString &manufacturer) {
    VCOMCOMM::manufacturer = manufacturer;
}
void VCOMCOMM::TrackleData(uint8_t fun_code, uint16_t id, const QByteArray &data) {
    std::cout << data << std::endl;
}