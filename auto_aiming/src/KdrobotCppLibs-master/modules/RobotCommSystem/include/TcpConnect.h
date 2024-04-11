/**
 * @file TcpConnect.h
 * @author yao
 * @date 2021年1月13日
 */

#ifndef KDROBOTCPPLIBS_TCPCONNECT_H
#define KDROBOTCPPLIBS_TCPCONNECT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QJsonDocument>
#include <QJsonObject>
#include <QThread>
#include <spdlogger.h>
#include <QTimer>
#include <QJsonDocument>
#include <QCryptographicHash>

/**
 * TCP连接层
 * @brief 用户不能创建该类的对象，应该由RCS_Server和RCS_Client去创建
 *        服务端从TCPServer中获取到一个TCPSocket后构建对象不用加连接名，链接ServerReceive_HEAD信号量，
 *        该信号量会返回this指针，用于记录链接，如果等待HEAD超时对象会自动析构，无需手动析构
 *
 */
class TcpConnect : public QObject {
Q_OBJECT

    friend class RCS_Server;

    friend class RCS_Client;

public:
    typedef enum {
        HEAD,           //!<@brief 身份头标识
        BROADCAST,      //!<@brief 广播标识
        PUSH,           //!<@brief 推送请求标识
        GET,            //!<@brief 获取请求标识
        SERVER_RET,     //!<@brief 服务端返回值标识
        CLIENT_RET,     //!<@brief 客户端返回值标识
        DIRECT_LINK,    //!<@brief 直连请求标识 TODO DIRECT_LINK未完成
    } PACK_TYPE;

    static const char *PACK_TYPE_ToString(PACK_TYPE type);

    typedef enum {
        SERVER,
        CLIENT,
    } MODE_TYPE;

private:
    QByteArray ReceiveBuff;
    QTcpSocket *socket;
    QTimer *timer;
    QThread *qThread;
    QString name;
    spdlogger logger;
    MODE_TYPE mode;

protected:
    TcpConnect(QTcpSocket *Socket, const QString &_name = QString());

    /**
     * 发送说明头
     */
    void send_HEAD();

    /**
     * 发送广播，客户端调用
     * @param bordcastName 广播名
     * @param message 广播消息
     */
    void send_BROADCAST(const QString &bordcastName, const QJsonObject &message);

    /**
     * 发送广播，服务器调用
     * @param from 来源
     * @param bordcastName 广播名
     * @param message 广播消息
     */
    void send_BROADCAST(const QString &from, const QString &bordcastName, const QJsonObject &message);

    /**
     * 发送PUSH请求，客户端服务器共用
     * @param from_sendTo 客户端调用时表示sentTo目的客户端，服务端调用时表示from来源
     * @param var 变量名
     * @param val 变量值
     */
    void send_PUSH(const QString &from_sendTo, const QString &var, const QJsonObject &val);

    /**
     * 发送GET请求，客户端服务器共用
     * @param from_sendTo 客户端调用时表示sentTo目的客户端，服务端调用时表示from来源
     * @param var 变量名
     * @param info 附加信息
     */
    void send_GET(const QString &from_sendTo, const QString &var, const QJsonObject &info = QJsonObject());

    /**
     * 发送服务端返回值，仅由服务端调用
     * @param ret 返回值
     */
    void send_SERVER_RET(const QJsonObject &ret);

    /**
     * 发送客户端返回值，客户端服务器共用
     * @param from_sendTo 客户端调用时表示sentTo目的客户端，服务端调用时表示from来源
     * @param ret 返回值
     */
    void send_CLIENT_RET(const QString &from_sendTo, const QJsonObject &ret);

    virtual ~TcpConnect();

private:
    void DecodeJson(QByteArray &data);

    inline void write(const QJsonObject &obj) {
        QJsonDocument jdom;
        jdom.setObject(obj);
        write(jdom.toJson(QJsonDocument::Compact));
    }

protected slots:

    void Socket_readyRead();

    void WaitHEADTimeout();

    void write(QByteArray data);


Q_SIGNALS:

    /**
     * 跨线程操作IO的信号量
     * @param data 要发送的数据
     */
    void Thread_write(const QByteArray &data);

    /**
     * 连接断开信号量
     * @param name 连接名（自己的名字）
     */
    void disconnected(const QString &name);

    /**
     * 接收到广播消息，服务端客户端相同
     * @param from 来源（服务端为链接自己的名字，客户端为发送者的名字）
     * @param var 消息名
     * @param val 消息值
     */
    void Receive_BROADCAST(const QString &from, const QString &var, const QJsonObject &val);

    /**
     * 服务端接收到连接头
     * @param connect 链接指针
     * @param name 客户端名
     */
    void ServerReceive_HEAD(TcpConnect *connect, const QString &name);

    /**
     * 服务端收到PUSH请求
     * @param from 来源（本链接客户端名字）
     * @param target 目标（目的客户端名）
     * @param var 要推送的消息名
     * @param val 要推送的消息值
     */
    void ServerReceive_PUSH(const QString &from, const QString &target, const QString &var, const QJsonObject &val);

    /**
     * 服务端收到GET请求
     * @param from 来源（本链接客户端名字）
     * @param target 目标（目的客户端名）
     * @param var 要获取的消息名
     */
    void ServerReceive_GET(const QString &from, const QString &target, const QString &var, const QJsonObject &info);

    /**
     * 服务器收到客户端返回值
     * @param from 来源（发送者名）
     * @param target 目标（目的客户端名）
     * @param val
     */
    void ServerReceive_CLIENT_RET(const QString &from, const QString &sendTo, const QJsonObject &val);

    /**
     * 客户端接收到PUSH
     * @param from 来源（发送者名）
     * @param var 推送的消息名
     * @param val 推送的消息值
     */
    void ClientReceive_PUSH(const QString &from, const QString &var, const QJsonObject &val);

    /**
     * 客户端收到GET请求
     * @param from 来源（发送者名）
     * @param var 发送者要获取的消息名
     */
    void ClientReceive_GET(const QString &from, const QString &var, const QJsonObject &info);

    /**
     * 客户端收到服务器返回值
     * @param val 返回值
     */
    void ClientReceive_SERVER_RET(const QJsonObject &val);

    /**
     * 客户端收到远端客户端返回值
     * @param from 来源（发送者名）
     * @param val 返回值
     */
    void ClientReceive_CLIENT_RET(const QString &from, const QJsonObject &val);
};

#endif //RCS_SERVER_TCPCONNECT_H
