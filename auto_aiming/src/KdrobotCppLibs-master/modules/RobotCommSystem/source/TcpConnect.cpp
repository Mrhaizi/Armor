/**
 * @file TcpConnect.cpp
 * @author yao
 * @date 2021年1月13日
 */

#include <QJsonObject>
#include <CRC.h>
#include "TcpConnect.h"

#define SUM_32BIT(N) ((uint8_t)((((N) >> 24) & 0xff) + (((N) >> 16) & 0xff) + (((N) >> 8) & 0xff) + ((N) & 0xff)))
#define PACK_LEN_OFFSET 2
#define HEAD_SUM_OFFSET 1
#define HEAD_LEN 6
#define HASH_LEN 2
#define ADDI_LED HEAD_LEN + HASH_LEN

TcpConnect::TcpConnect(QTcpSocket *Socket, const QString &_name) : name(_name), logger(__FUNCTION__) {
    Socket->setParent(this);
    if (name.isEmpty()) {
        timer = new QTimer(this);
        timer->callOnTimeout(this, &::TcpConnect::WaitHEADTimeout);
        timer->start(10e3);
    }
    qThread = new QThread;
    moveToThread(qThread);
    qThread->start();
    this->socket = Socket;
    connect(Socket, SIGNAL(readyRead()), this, SLOT(Socket_readyRead()));
    connect(this, SIGNAL(Thread_write(QByteArray)), this, SLOT(write(QByteArray)),
            Qt::QueuedConnection);
    connect(Socket, &QTcpSocket::disconnected, this, [=]() {
        emit disconnected(name);
        deleteLater();
    });

    /* 构造没有连接名为服务端链接 */
    if (!name.isEmpty()) {
        send_HEAD();
        mode = CLIENT;
    } else {
        mode = SERVER;
    }
}

void TcpConnect::write(QByteArray data) {
    if (socket->thread() != QThread::currentThread()) {
        emit Thread_write(data);
        return;
    }
    uint16_t crc = CRC::Verify_CRC16_Check_Sum(data);
    uint32_t size = data.size();
    data.push_front({(const char *) &size, sizeof(uint32_t)});
    uint8_t head_sum = SUM_32BIT(size);
    data.push_front((char) head_sum);
    data.push_front((char) 0xa5);
    data.append((const char *) &crc, 2);
    if (!socket->isWritable() && !socket->waitForBytesWritten(1000)) {
        logger.error("{}: waitForBytesWritten time out!", name);
        return;
    }
    socket->write(data);
}

void TcpConnect::Socket_readyRead() {
    ReceiveBuff.push_back(socket->readAll());
    restart:
    auto dataPtr = ReceiveBuff.constData();
    int size = ReceiveBuff.size();
    for (int i = 0; i < size; i++) {
        if (dataPtr[i] == (char) 0xa5) {
            uint8_t head_sum = *(uint8_t *) (dataPtr + i + HEAD_SUM_OFFSET);
            int dataPackSize = *(uint32_t *) (dataPtr + i + PACK_LEN_OFFSET);
            if (dataPackSize < 0 || head_sum != SUM_32BIT(dataPackSize))
                continue;
            while (size - i < dataPackSize + ADDI_LED) {
                if (!socket->waitForReadyRead(1000)) break;
                ReceiveBuff.push_back(socket->readAll());
                size = ReceiveBuff.size();
            }
            dataPtr = ReceiveBuff.constData();
            QByteArray Data(dataPtr + i + HEAD_LEN, dataPackSize);
            uint16_t crc = *(uint16_t *)(dataPtr + i + HEAD_LEN + dataPackSize);
            uint16_t crcCheck = CRC::Verify_CRC16_Check_Sum(Data);
            if (crc == crcCheck) {
                DecodeJson(Data);
                ReceiveBuff.remove(0, i + dataPackSize + ADDI_LED);
                if (ReceiveBuff.size())
                    goto restart;
            }
        }
    }
}

void TcpConnect::DecodeJson(QByteArray &data) {
    QJsonParseError error;
    QJsonDocument jdom = QJsonDocument::fromJson(data, &error);
    if (error.error != QJsonParseError::NoError) {
        logger.error("Json error:{} {}\n{}", error.error, error.errorString(), data);
        return;
    }
    QJsonObject obj = jdom.object();
    PACK_TYPE type = (PACK_TYPE) obj.value("type").toInt(-1);
    QJsonObject body = obj.value("body").toObject();

    switch (type) {
        case HEAD: {
            QString string = obj.value("name").toString();
            if (string.isEmpty()) {
                logger.error("not find Address\n{}", data);
                return;
            }
            if (name.isEmpty()) {
                name = string;
                setObjectName(string);
                socket->setObjectName(string + "_Socket");
                timer->stop();
                switch (mode) {
                    case SERVER:
                        emit ServerReceive_HEAD(this, string);
                        break;
                    case CLIENT:
                        break;
                }
            } else logger.error("Repeat set name \"{}\" to \"{}\"", name, string);
            break;
        }
        case BROADCAST: {
            emit Receive_BROADCAST(mode == SERVER ? name : obj.find("from")->toString(),
                                   obj.find("bordcastName")->toString(),
                                   obj.find("bordcast")->toObject());
            break;
        }
        case PUSH: {
            QString from_sendTo = obj.find("from_sendTo")->toString();
            QString tar_var = obj.find("var")->toString();
            QJsonObject tar_val = obj.find("val")->toObject();
            switch (mode) {
                case SERVER:
                    emit ServerReceive_PUSH(name, from_sendTo, tar_var, tar_val);
                    break;
                case CLIENT:
                    emit ClientReceive_PUSH(from_sendTo, tar_var, tar_val);
                    break;
            }
            break;
        }
        case GET: {
            QString from_sendTo = obj.find("from_sendTo")->toString();
            QString tar_var = obj.find("var")->toString();
            QJsonObject info = obj.find("info")->toObject();
            switch (mode) {
                case SERVER:
                    emit ServerReceive_GET(name, from_sendTo, tar_var, info);
                    break;
                case CLIENT:
                    emit ClientReceive_GET(from_sendTo, tar_var, info);
                    break;
            }
            break;
        }
        case SERVER_RET: {
            QJsonObject info = obj.find("ret")->toObject();
            emit ClientReceive_SERVER_RET(info);
            if (info.find("disconnect")->toBool(false))
                socket->disconnectFromHost();
            break;
        }
        case CLIENT_RET: {
            QString from_sendTo = obj.find("from_sendTo")->toString();
            QJsonObject ret = obj.find("ret")->toObject();
            switch (mode) {
                case SERVER:
                    emit ServerReceive_CLIENT_RET(name, from_sendTo, ret);
                    break;
                case CLIENT:
                    emit ClientReceive_CLIENT_RET(from_sendTo, ret);
                    break;
            }
            break;
        }
        default:
            logger.error("Unknown type {}\n{}", type, data);
    }
}

void TcpConnect::WaitHEADTimeout() {
    logger.error("Wait HEAD time out IP={}", socket->peerAddress().toString());
    if (qThread != nullptr) {
        qThread->quit();
        qThread->deleteLater();
        qThread = nullptr;
    }
    this->deleteLater();
}

TcpConnect::~TcpConnect() {
    if (qThread != nullptr) {
        qThread->quit();
        qThread = nullptr;
    }
}

void TcpConnect::send_HEAD() {
    QJsonObject obj;
    obj.insert("type", HEAD);
    obj.insert("name", name);
    write(obj);
}

void TcpConnect::send_BROADCAST(const QString &from, const QString &bordcastName, const QJsonObject &message) {
    QJsonObject obj;
    obj.insert("type", BROADCAST);
    obj.insert("from", from);
    obj.insert("bordcastName", bordcastName);
    obj.insert("bordcast", message);
    write(obj);
}

void TcpConnect::send_BROADCAST(const QString &bordcastName, const QJsonObject &message) {
    QJsonObject obj;
    obj.insert("type", BROADCAST);
    obj.insert("bordcastName", bordcastName);
    obj.insert("bordcast", message);
    write(obj);
}

void TcpConnect::send_PUSH(const QString &from_sendTo, const QString &var, const QJsonObject &val) {
    QJsonObject obj;
    obj.insert("type", PUSH);
    obj.insert("from_sendTo", from_sendTo);
    obj.insert("var", var);
    obj.insert("val", val);
    write(obj);
}

void TcpConnect::send_GET(const QString &from_sendTo, const QString &var, const QJsonObject &info) {
    QJsonObject obj;
    obj.insert("type", GET);
    obj.insert("from_sendTo", from_sendTo);
    obj.insert("var", var);
    obj.insert("info", info);
    write(obj);
}

void TcpConnect::send_SERVER_RET(const QJsonObject &ret) {
    QJsonObject obj;
    obj.insert("type", SERVER_RET);
    obj.insert("ret", ret);
    write(obj);
}

void TcpConnect::send_CLIENT_RET(const QString &from_sendTo, const QJsonObject &ret) {
    QJsonObject obj;
    obj.insert("type", CLIENT_RET);
    obj.insert("from_sendTo", from_sendTo);
    obj.insert("ret", ret);
    write(obj);
}

const char *TcpConnect::PACK_TYPE_ToString(TcpConnect::PACK_TYPE type) {
    switch (type) {
        case HEAD:
            return "HEAD";
        case BROADCAST:
            return "BROADCAST";
        case PUSH:
            return "PUSH";
        case GET:
            return "GET";
        case SERVER_RET:
            return "SERVER_RET";
        case CLIENT_RET:
            return "CLIENT_RET";
        case DIRECT_LINK:
            return "DIRECT_LINK";
    }
    return "Unknown";
}
