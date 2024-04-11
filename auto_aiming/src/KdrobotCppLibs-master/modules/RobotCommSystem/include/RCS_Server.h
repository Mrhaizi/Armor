/**
 * @file RCS_Server.h
 * @author yao
 * @date 2021年1月13日
 */

#ifndef KDROBOTCPPLIBS_ROBOTCOMMSYSTEMSERVER_H
#define KDROBOTCPPLIBS_ROBOTCOMMSYSTEMSERVER_H

#include <QObject>
#include <QMutex>
#include <QMutexLocker>
#include <QTcpServer>
#include "spdlogger.h"
#include "HostAddressRadio.h"
#include "TcpConnect.h"

class RCS_Server : public QObject {
Q_OBJECT
    using getCallback = std::function<QJsonObject(const QString &, const QJsonObject &)>;
    using setCallback = std::function<void(const QString &, const QJsonObject &)>;

    spdlogger logger;
    HostAddressRadio *hostAddressRadio = nullptr;
    QTcpServer *pTcpServer;
    QMutex mutex;
    QMap<QString, TcpConnect *> clientList;
    QMap<QString, std::pair<getCallback, setCallback>> callBackMap;
public:
    static QString  __NAME__;
    /**
     * 构造函数
     * @param TcpPort 使用的Tcp端口
     * @param udpRadio 是否开启Udp广播服务器IP
     */
    RCS_Server(uint16_t TcpPort = 8850, bool udpRadio = true);

    /**
     * 注册GET请求和PUSH请求回调
     * @param name 注册变量名
     * @param getter getter方法 第一参数为GET请求来源，返回值为相应参数的值Json格式
     *               简单写法为<code>return {{"KeyString", val}, {"KeyString", val}, ...}};</code>
     * @param setter setter方法 第一参数为PUSH请求来源，第二参数为PUSH值
     */
    void RegisterCallBack(const QString &name, const getCallback &getter, const setCallback &setter){
        callBackMap.insert(name, {getter, setter});
    }

    /**
     * 发送广播
     * @param bordcastName 广播名
     * @param val 广播内容
     */
    void BROADCAST(const QString &bordcastName, const QJsonObject &val);

    /**
     * 向指定客户端发送广播
     * @param clientName 客户端名
     * @param bordcastName 广播名
     * @param val 广播内容
     */
    void BROADCAST(const QString & clientName, const QString &bordcastName, const QJsonObject &val);

    /**
     * 发送PUSH请求
     * @param target 请求目标客户端
     * @param var 变量名
     * @param val 变量值
     */
    void PUSH(const QString &target, const QString &var, const QJsonObject &val);

    /**
     * 注册GET请求和PUSH请求回调，在类内使用，可绑定对象
     * @param name 注册变量名
     * @param obj1 对象指针
     * @param getter getter方法
     * @param obj2 对象指针
     * @param setter setter方法
     */
    template<class T1, typename getterFUN, class T2, typename setterFUN>
    void RegisterCallBack(const QString &name, T1 *obj1, getterFUN getter, T2 *obj2, setterFUN setter) {
        using namespace std::placeholders;
        this->RegisterCallBack(name, std::bind(getter, obj1, _1, _2), std::bind(setter, obj2, _1, _2));
    }

    /**
     * PUSH请求回调，在类内使用，可绑定对象
     * @param name 注册变量名
     * @param obj1 对象指针
     * @param getter getter方法
     */
    template<class T1, typename getterFUN>
    void RegisterGetCallBack(const QString &name, T1 *obj1, getterFUN fun) {
        using namespace std::placeholders;
        this->RegisterCallBack(name, std::bind(fun, obj1, _1, _2), {});
    }

    /**
     * GET请求回调，在类内使用，可绑定对象
     * @param name 注册变量名
     * @param obj1 对象指针
     * @param getter getter方法
     */
    template<class T1, typename getterFUN>
    void RegisterPushCallBack(const QString &name, T1 *obj1, getterFUN fun) {
        using namespace std::placeholders;
        this->RegisterCallBack(name, {}, std::bind(fun, obj1, _1, _2));
    }

    /**
     * 回调函数反注册，getter和setter全部注销
     * @param name 变量名
     * @return
     */
    int UnregisterCallBack(const QString &name);

    /**
     * 获取客户端名字列表
     * @return
     */
    QList<QString> getClientNameList();

    /**
     * 获取客户端数量
     * @return 客户端数量
     */
    size_t getClientCount();

    /**
     * 断开指定客户端连接
     * @param name 客户端名
     * @return 查询到客户端并断开返回true，客户端不在列表中返回false
     */
    bool disconnect(const QString &name);

private:
    QJsonObject GET_ClientList(const QString &, const QJsonObject &);

signals:
    void NewClient(const QHostAddress &addr, const QString &name);

    void ClientDisconnected(const QString &name);

    /**
     * 返回值信号量
     * @param type
     * @param ret
     */
    void signal_RETURN(TcpConnect::PACK_TYPE type, const QJsonObject &ret);

    /**
     * 收到广播信号量
     * @param from 来源
     * @param broadcastName 广播名
     * @param message 广播消息
     */
    void signal_BROADCAST(const QString &from, const QString &broadcastName, const QJsonObject &message);


protected slots:

    void tcpServer_newConnection();

    void TcpConnect_receive_HEAD(TcpConnect *pTcpConnect, const QString &name);

    void TcpConnect_receive_BROADCAST(const QString &from, const QString &broadcastName, const QJsonObject &message);

    void TcpConnect_receive_PUSH(const QString &from, const QString &sendTo,
                                 const QString &var, const QJsonObject &obj);

    void TcpConnect_receive_GET(const QString &from, const QString &sendTo,
                                const QString &var, const QJsonObject &info);

    void TcpConnect_receive_CLIENT_RET(const QString &from, const QString &sendTo, const QJsonObject &ret);

    void TcpConnect_disconnected(const QString &name);
};


#endif
