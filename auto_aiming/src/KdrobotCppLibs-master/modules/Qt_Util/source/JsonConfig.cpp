/**
 * @file JsonConfig.cpp
 * @author yao
 * @date 2021年1月13日
 */

#include "JsonConfig.h"

QMap<QString, JsonConfig> JsonConfig::JsonConfigMap = {};

JsonConfig::JsonConfig(const QString &filePath) : logger(__FUNCTION__) {
    open(filePath);
}

bool JsonConfig::open(const QString &filePath) {
    if (JsonConfigMap.contains(filePath)) {
        *this = JsonConfigMap[filePath];
        return true;
    }
    QFile file(filePath);
    if (!file.exists()) {
        return false;
    }
    file.open(QIODevice::ReadOnly);
    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll(), &jsonError);
    file.close();

    if (!jsonDoc.isNull() && (jsonError.error == QJsonParseError::NoError)) {
        jsonDocument = jsonDoc;
        Path = QFileInfo(file).absolutePath();
        JsonConfigMap.insert(filePath, *this);
        opened = true;
        return true;
    } else return false;
}

QJsonValue JsonConfig::findObject(const QString &path) {
    QStringList list = path.split('/');
    auto object = jsonDocument.object();
    for (const QString &node : list) {
        auto TmpObj = object[node];
        if (!TmpObj.isNull() && TmpObj.isObject()) {
            object = TmpObj.toObject();
        } else return TmpObj;
    }
    return object;
}

int JsonConfig::findInt(const QString &path, int defaultValue, std::function<bool(int)> cmp) {
    int val = findObject(path).toInt(defaultValue);
    if (!cmp(val)) {
        logger.error("'{}' missing or error", path.toStdString());
        throw std::runtime_error("config error");
    }
    return val;
}

JsonConfig &JsonConfig::factory(const QString &filePath) {
    if (!JsonConfigMap.contains(filePath)) {
        return JsonConfigMap.insert(filePath, JsonConfig(filePath)).value();
    }
    return JsonConfigMap[filePath];
}

JsonConfig JsonConfig::operator=(const JsonConfig &jsonConfig) {
    this->logger = jsonConfig.logger;
    this->jsonDocument = jsonConfig.jsonDocument;
    this->opened = jsonConfig.opened;
    return *this;
}
