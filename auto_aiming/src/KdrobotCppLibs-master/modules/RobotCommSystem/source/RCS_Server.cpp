/**
 * @file RCS_Server.cpp
 * @author yao
 * @date 2021年1月13日
 */

#include "RCS_Server.h"
#include <QTcpSocket>

QString  RCS_Server::__NAME__ = "__server__";

void RCS_Server::tcpServer_newConnection() {
    while (pTcpServer->hasPendingConnections()) {
        QTcpSocket *socket = pTcpServer->nextPendingConnection();
        connect(new TcpConnect(socket), SIGNAL(ServerReceive_HEAD(TcpConnect * , const QString &)),
                this, SLOT(TcpConnect_receive_HEAD(TcpConnect * , const QString &)));
    }
}

void RCS_Server::TcpConnect_disconnected(const QString &name) {
    logger.warn("client '{}' disconnected", name);
    QMutexLocker lk(&mutex);
    clientList.remove(name);
}

void RCS_Server::TcpConnect_receive_HEAD(TcpConnect *pTcpConnect, const QString &name) {
    QMutexLocker lk(&mutex);
    if (clientList.contains(name)) {
        pTcpConnect->send_SERVER_RET({{"error",      "There is already a client with the same name"},
                                      {"disconnect", true}});
        return;
    }

    clientList.insert(name, pTcpConnect);
    logger.info("client '{}' Connected", name);
    connect(pTcpConnect, SIGNAL(Receive_BROADCAST(const QString &, const QString &, const QJsonObject &)),
            this, SLOT(TcpConnect_receive_BROADCAST(const QString &, const QString &, const QJsonObject &)));

    connect(pTcpConnect,
            SIGNAL(ServerReceive_GET(const QString &, const QString &, const QString &, const QJsonObject &)),
            this, SLOT(TcpConnect_receive_GET(const QString &, const QString &, const QString &, const QJsonObject &)));

    connect(pTcpConnect,
            SIGNAL(ServerReceive_PUSH(const QString &, const QString &, const QString &, const QJsonObject &)),
            this,
            SLOT(TcpConnect_receive_PUSH(const QString &, const QString &, const QString &, const QJsonObject &)));

    connect(pTcpConnect, SIGNAL(ServerReceive_CLIENT_RET(const QString &, const QString &, const QJsonObject &)),
            this, SLOT(TcpConnect_receive_CLIENT_RET(const QString &, const QString &, const QJsonObject &)));

    connect(pTcpConnect, SIGNAL(disconnected(const QString &)),
            this, SLOT(TcpConnect_disconnected(const QString &)));

    connect(pTcpConnect, SIGNAL(disconnected(const QString &)),
            this, SIGNAL(ClientDisconnected(const QString &)));
    emit NewClient(pTcpConnect->socket->peerAddress(), name);
}

void RCS_Server::TcpConnect_receive_BROADCAST(const QString &from, const QString &broadcastName,
                                              const QJsonObject &message) {
    emit signal_BROADCAST(from, broadcastName, message);
    for (const auto &client : clientList) {
        if (client->name != from)
            client->send_BROADCAST(from, broadcastName, message);
    }
    logger.info("broadcast '{}' from '{}'", broadcastName, from);
}

void RCS_Server::TcpConnect_receive_PUSH(const QString &from, const QString &sendTo, const QString &var,
                                         const QJsonObject &obj) {
    if (sendTo == __NAME__) {
        auto pTcpConnect = clientList.find(from).value();
        auto it = callBackMap.find(var);
        if (it == callBackMap.end()) {
            pTcpConnect->send_SERVER_RET({{"error", "variable is not registered"},
                                          {"var",   var}});
            logger.error("PUSH request from '{}', the requested '{}' variable is not registered", from, var);
        } else if ((*it).second) {
            ((*it).second)(from, obj);
            logger.info("Receives a PUSH request from '{}', push the '{}' variable", from, var);
        } else {
            pTcpConnect->send_SERVER_RET({{"error", "variable is read only"},
                                          {"var",   var}});
            logger.error("PUSH request from '{}', the requested '{}' variable is read only", from, var);
        }
    } else {
        auto it = clientList.find(sendTo);
        if (it != clientList.end()) {
            it.value()->send_PUSH(sendTo, var, obj);
            logger.info("forwarding PUSH request from '{}' to '{}'", from, sendTo);
        } else {
            logger.error("not find client '{}'", sendTo);
            clientList.find(from).value()->send_SERVER_RET({{"error", "not find client '" + sendTo + '\''}});
        }
    }
}

void RCS_Server::TcpConnect_receive_GET(const QString &from, const QString &sendTo, const QString &var,
                                        const QJsonObject &info) {
    if (sendTo == __NAME__) {
        auto pTcpConnect = clientList.find(from).value();
        auto it = callBackMap.find(var);
        if (it == callBackMap.end()) {
            pTcpConnect->send_SERVER_RET({{"error", "variable is not registered"},
                                          {"var",   var}});
            logger.error("GET request from '{}', the requested '{}' variable is not registered", from,
                         var);
        } else if ((*it).first) {
            pTcpConnect->send_PUSH(__NAME__, var, ((*it).first)(from, info));
            logger.info("Receives a GET request from '{}', gets the '{}' variable", from, var);
        } else {
            pTcpConnect->send_SERVER_RET({{"error", "variable is write only"},
                                          {"var",   var}});
            logger.error("GET request from '{}', the requested '{}' variable is write only", from,
                         var);
        }
    } else {
        auto it = clientList.find(sendTo);
        if (it != clientList.end()) {
            it.value()->send_GET(from, var, info);
            logger.info("forwarding GET request from '{}' to '{}'", from, sendTo);
        } else {
            logger.error("not find client '{}'", sendTo);
            clientList.find(from).value()->send_SERVER_RET({{"error", "not find client '" + sendTo + '\''}});
        }
    }
}

void RCS_Server::TcpConnect_receive_CLIENT_RET(const QString &from, const QString &sendTo, const QJsonObject &ret) {
    if (sendTo == __NAME__) {
        emit signal_RETURN(TcpConnect::CLIENT_RET, ret);
    } else {
        auto it = clientList.find(sendTo);
        if (it != clientList.end()) {
            it.value()->send_CLIENT_RET(from, ret);
            logger.info("forwarding CLIENT_RET request from '{}' to '{}'", from, sendTo);
        } else {
            logger.error("not find client '{}'", sendTo);
            clientList.find(sendTo).value()->send_SERVER_RET({{"error", "not find client '" + sendTo + '\''}});
        }
    }
}

RCS_Server::RCS_Server(uint16_t TcpPort, bool udpRadio) : logger(__FUNCTION__) {
    if (udpRadio) hostAddressRadio = new HostAddressRadio(this);
    pTcpServer = new QTcpServer(this);
    if (!pTcpServer->listen(QHostAddress::Any, TcpPort)) {
        logger.error("TCP can't listing");
        throw std::runtime_error("TCP can't listing");
    }
    connect(pTcpServer, SIGNAL(newConnection()), this, SLOT(tcpServer_newConnection()));
    RegisterGetCallBack("ClientList", this, &RCS_Server::GET_ClientList);
}

QList<QString> RCS_Server::getClientNameList() {
    return clientList.keys();
}

size_t RCS_Server::getClientCount() {
    return clientList.count();
}

bool RCS_Server::disconnect(const QString &name) {
    auto it = clientList.find(name);
    if (it != clientList.end()) {
        (*it)->deleteLater();
        clientList.erase(it);
        return true;
    } else return false;
}

QJsonObject RCS_Server::GET_ClientList(const QString &, const QJsonObject &) {
    QJsonArray array = QJsonArray::fromStringList(getClientNameList());
    return {{"clientList", array}};
}

void RCS_Server::BROADCAST(const QString &bordcastName, const QJsonObject &val) {
    for (auto &client : clientList)
        client->send_BROADCAST(__NAME__, bordcastName, val);
}

void RCS_Server::BROADCAST(const QString &clientName, const QString &bordcastName, const QJsonObject &val) {
    auto it = clientList.find(clientName);
    if (it != clientList.end())
        it.value()->send_BROADCAST(__NAME__, bordcastName, val);
}

int RCS_Server::UnregisterCallBack(const QString &name) {
    return callBackMap.remove(name);
}

void RCS_Server::PUSH(const QString &target, const QString &var, const QJsonObject &val) {
    auto it = clientList.find(target);
    if (it != clientList.end())
        it.value()->send_PUSH(__NAME__, var, val);
}
