/**
 * @file JsonConfig.h
 * @author yao
 * @date 2021年1月13日
 */

#ifndef KDROBOTCPPLIBS_JSONCONFIG_H
#define KDROBOTCPPLIBS_JSONCONFIG_H

#include <exception>

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMutex>
#include "spdlogger.h"

class JsonConfig {
    static QMap<QString, JsonConfig> JsonConfigMap;     //!<@brief 全局索引
    QJsonDocument jsonDocument;                         //!<@brief Json根对象
    QString Path;                                       //!<@brief 文件所在路径
    bool opened = false;                                //!<@brief 文件打开成功标志
    spdlogger logger;                                   //!<@brief 日志器

public:
    JsonConfig() : logger(__FUNCTION__) {};

    JsonConfig(const QString &filePath);

    JsonConfig operator=(const JsonConfig &jsonConfig);

    /**
     * @brief 打开配置文件
     * @param filePath 配置文件路径
     * @return 打开成功
     */
    bool open(const QString &filePath = "config.json");

    /**
     * @brief 判断配置文件是否成功打开
     * @return
     */
    inline bool isOpen() {
        return opened;
    }

    /**
     * @brief 获取配置文件所在路径
     * @return 配置文件所在路径
     */
    inline const QString &getPath() const {
        return Path;
    }

    /**
     * @brief 按路径查找对象，使用'/'分隔
     * @param path 对象路径
     * @return Json对象
     */
    QJsonValue findObject(const QString &path);

    /**
     * @brief 按路径查找查找整型对象，并按给出的条件判断是否合法，
     *        不合法抛出异常
     * @param path 对象路径
     * @param defaultValue 默认值
     * @param cmp 判断规则
     * @return 整型数值
     */
    int findInt(const QString &path, int defaultValue, std::function<bool(int)> cmp = [](int a) { return true; });

    /**
     * @brief 默认值为0的重载{@see findInt(const QString &, int, std::function<bool(int)>)}
     * @param path 对象路径
     * @param cmp 判断规则
     * @return 整型数值
     */
    inline int findInt(const QString &path, std::function<bool(int)> cmp = [](int a) { return true; }) {
        return findInt(path, 0, cmp);
    }

    /**
     * @brief JsonConfig工厂方法
     * @param filePath 文件名
     * @return JsonConfig对象
     */
    static JsonConfig &factory(const QString &filePath = "config.json");
};


#endif //KDROBOTCPPLIBS_JSONCONFIG_H
