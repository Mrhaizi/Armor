/**
 * @file RCS_Client.h
 * @author yao
 * @date 2021年1月13日
 */

#ifndef KDROBOTCPPLIBS_RCS_CLIENT_H
#define KDROBOTCPPLIBS_RCS_CLIENT_H

#include <functional>
#include <QtCore>
#include <QObject>
#include <QUdpSocket>
#include <QNetworkAddressEntry>
#include <QWaitCondition>
#include <QTcpServer>
#include "TcpConnect.h"

class RCS_Client : public QObject {
Q_OBJECT
    using getCallback = std::function<QJsonObject(const QString &, const QJsonObject &)>;
    using setCallback = std::function<void(const QString &, const QJsonObject &)>;
    uint16_t TcpPort;
    spdlogger logger;
    QList<QNetworkAddressEntry> HostAddressEntry;
    QUdpSocket *udpSocket = nullptr;
    TcpConnect *pTcpConnect = nullptr;

    QMutex udpMutex;
    QMutex waitMutex;
    QWaitCondition waitCondition;

    QMutex blockMutex, GET_BlockMutex;
    QWaitCondition blockCondition;
    QString blockName, blockVar;
    QJsonObject blockVal;

    bool Connected = false;
    QString ClientName;

    QMap<QString, std::pair<getCallback, setCallback>> callBackMap;
public:

    /**
     * 构造函数
     * @param _ClientName 客户端名
     * @param parent 父对象
     */
    RCS_Client(const QString &_ClientName, uint16_t _TcpPort = 8550, uint16_t _UdpPort = 8849,
               QObject *parent = nullptr);

    RCS_Client(const QString &_ClientName, const QHostAddress &addr, uint16_t _TcpPort = 8550,
               QObject *parent = nullptr);

    /**
     * 析构函数
     */
    ~RCS_Client();

    /**
     * 注册GET请求和PUSH请求回调
     * @param name 注册变量名
     * @param getter getter方法 第一参数为GET请求来源，返回值为相应参数的值Json格式
     *               简单写法为<code>return {{"KeyString", val}, {"KeyString", val}, ...}};</code>
     * @param setter setter方法 第一参数为PUSH请求来源，第二参数为PUSH值
     */
    void RegisterCallBack(const QString &name, const getCallback &getter, const setCallback &setter);

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
     * 判断链接就绪
     * @return 链接就绪
     */
    inline bool isConnected() {
        return Connected;
    }

    /**
     * 等待链接就绪
     * @param deadline 超时时间
     * @return 链接成功
     */
    bool waitConnected(const QDeadlineTimer &deadline = QDeadlineTimer(QDeadlineTimer::Forever)) {
        return Connected || waitCondition.wait(&waitMutex, deadline);
    }

    /**
     * 发送广播
     * @param bordcastName 广播名
     * @param val 广播内容
     */
    inline void BROADCAST(const QString &bordcastName, const QJsonObject &val) {
        if (waitConnected()) pTcpConnect->send_BROADCAST(bordcastName, val);
    }

    /**
     * 发送GET请求
     * @param target 请求目标客户端
     * @param var 变量名
     * @param info 附加信息
     */
    inline void GET(const QString &target, const QString &var, const QJsonObject &info = {}) {
        if (waitConnected()) pTcpConnect->send_GET(target, var, info);
    }

    /**
     * 发送GET请求，阻塞等待返回
     * @note 阻塞请求不会调用setter回调函数，而是直接返回获取到的值
     *       当遇到服务器返回错误或客户端返回错误时无法分辨，会继续等待知道超时，所以要确认请求是否正确
     *       该函数带锁，严格上不支持多线程同时调用，会阻塞，且没有超时机制
     *       该函数会调用{@link waitConnected}等待连接建立，超时时间同deadline
     * @see GET waitConnected
     * @param target 请求目标客户端
     * @param var 变量名
     * @param[out] timeout 返回超时状态
     * @param deadline 超时时间
     * @param info 附加信息
     * @return 获取到的值
     * @warning TODO 待测试
     */
    QJsonObject GET_Block(const QString &target, const QString &var, bool &timeout,
                          const QDeadlineTimer &deadline, const QJsonObject &info = {});

    /**
     * 发送PUSH请求
     * @param target 请求目标客户端
     * @param var 变量名
     * @param val 变量值
     */
    inline void PUSH(const QString &target, const QString &var, const QJsonObject &val) {
        if (waitConnected()) pTcpConnect->send_PUSH(target, var, val);
    }

    /* 内部槽用户无需关心 */
protected slots:

    void UdpReadyRead();

    void receive_GET(const QString &from, const QString &var, const QJsonObject &info);

    void receive_PUSH(const QString &from, const QString &var, const QJsonObject &val);

    void receive_BROADCAST(const QString &from, const QString &broadcastName, const QJsonObject &val);

    void receive_SERVER_RET(const QJsonObject &ret);

    void receive_CLIENT_RET(const QString &from, const QJsonObject &ret);

signals:

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

    void disconnected(const QString &name);
};


#endif
