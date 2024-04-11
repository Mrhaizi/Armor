/**
 * @file MainThread.h
 * @author yao
 * @date 2021年1月13日
 */

#ifndef KDROBOTCPPLIBS_MAINTHREAD_H
#define KDROBOTCPPLIBS_MAINTHREAD_H

#include <QObject>
#include <QThread>
#include <spdlogger.h>
#include <JsonConfig.h>

#ifdef linux
#include <BackTrace.h>
#endif

/**
 * @class MainThread
 * @brief 程序人口模板
 * @details
 *     使用方法：主线程构造模板应继承该类然后重写main方法
 *     {@code
 *      #include <MainThread.h>
 *
 *      class MyMainThread : public MainThread {
 *          Q_OBJECT
 *      public:
 *          MyMainThread(const QStringList &args, QObject *parent = nullptr) : MainThread(args, parent) {
 *              //Init your self object
 *          }
 *      protected:
 *          void main(const QStringList &args) override {
 *              logger.info("Hello World");
 *          }
 *      };}
 *      主函数写法：
 *      {@code
 *      int main(int argc, char *argv[]) {
 *          QCoreApplication app(argc, argv);
 *          MyMainThread myMainThread(app.arguments());
 *          QObject::connect(&myMainThread, SIGNAL(threadExit()), &app, SLOT(quit()));
 *          return app.exec();
 *      }}
 * main方法运行于一个新的线程内，此时Qt框架已经启动
 * @warning 注意带有Qt信号量的对象应在主线程内构造，防止消息循环被阻塞
 * @warning 内置堆栈回溯功能，不需要再次定义{@link BackTrace}
 */
class MainThread : public QThread {
Q_OBJECT
#ifdef linux
    static BackTrace backTrace;    ///<@brief 堆栈回溯
#endif
protected:
    spdlogger logger;       ///<@brief 日志器
    JsonConfig config;      ///<@brief json配置
    QStringList args;       ///<@brief 命令行参数
    volatile bool running = true;   ///<@brief 用于控制线程退出的标志位,初始默认值为true
public:

    /**
     * @brief 构造函数
     * @details
     * 执行的功能有
     * 1. 检查命令行参数-l, --log <log>指定全局日期输出到文件
     * 2. 检查命令行参数-c, --config <config>指定配置文件路径
     * 3. 检查命令行参数-d, --directory <currentPath>指定工作目录
     * 4. 读取配置文件，更改运行目录，重定向日志
     * ~~5. 启动线程调用main方法~~
     * @warning 因为存在线程提前运行的问题，所以不再自动启动线程，需要手动在重载的构造函数末尾启动
     *
     * @note 建议自行写构造函数用于初始化和线程有关的对象。
     * @note 没有设置命令行参数或配置文件则运行路径不变。
     *       设置运行目录优先级为先命令行参数，配置文件所在路径。
     * @param args 命令行参数
     * @param parent 父对象指针,可有可无
     */
    MainThread(const QStringList &args, QObject *parent = nullptr);

    /**
     * @brief 析构函数
     * @details 可以重写以达到自己的功能,但是必须确保线程退出
     *
     * 示例:{@code#define KDROBOTCPPLIBS_MAINTHREAD_H

#include <QObject>
#include <QThread>
#include <spdlogger.h>
#include <JsonConfig.h>

#ifdef linux();
     *     this->wait();
     * }}
     */
    virtual ~MainThread();

protected:
    void run() override final;

    /**
     * 主方法纯虚函数,需要继承并实现
     * @details 方法退出时会发出信号量finished, running赋值false
     * @param args 命令行参数
     */
    virtual void main(const QStringList &args) = 0;

signals:

    /**
     * @brief 线程退出信号量
     */
    int threadExit();
};

#endif //KDROBOTCPPLIBS_MAINTHREAD_H
