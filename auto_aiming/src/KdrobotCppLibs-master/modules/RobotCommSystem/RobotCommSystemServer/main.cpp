/**
 * @file main.cpp
 * @author yao
 * @date 2021年1月13日
 * @brief 机器人网络通讯系统服务器主函数
 */

#include <QCoreApplication>
#include "main.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    app.setApplicationName("RobotCommSystemServer");
    MyMainThread myMainThread(app.arguments());
    QObject::connect(&myMainThread, SIGNAL(threadExit()), &app, SLOT(quit()));
    return app.exec();
}