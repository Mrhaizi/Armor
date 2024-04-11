/**
 * @file HostAddressRadio.cpp
 * @author yao
 * @date 2021年1月13日
 */

#include "HostAddressRadio.h"
#include <QNetworkInterface>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

HostAddressRadio::HostAddressRadio(QObject *parent) :
        QObject(parent), logger(__FUNCTION__),
        timer(new QTimer(this)), broadcast(new QUdpSocket(this)) {
    QNetworkInterface networkInterface;
    logger.info("HostAddress:");
    for (const QNetworkInterface &anInterface : networkInterface.allInterfaces()) {
        logger.info("\tNetwork Interface Name:{}", anInterface.humanReadableName());
        for (const QNetworkAddressEntry &addressEntry : anInterface.addressEntries()) {
            logger.info("\t\tIP:{} MASK:{}", addressEntry.ip(), addressEntry.netmask());
            if (!addressEntry.ip().isLoopback() && addressEntry.ip().toIPv4Address() != 0) {
                HostAddressEntry.append(addressEntry);
            }
        }
    }
    QJsonDocument jsonDocument;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    for (const QNetworkAddressEntry &addressEntry : HostAddressEntry) {
        QJsonObject EntryObject;
        EntryObject.insert("IP", addressEntry.ip().toString());
        EntryObject.insert("MASK", addressEntry.netmask().toString());
        jsonArray.append(EntryObject);
    }
    jsonObject.insert("hostAddress", jsonArray);
    jsonDocument.setObject(jsonObject);
    hostAddressJsonData = jsonDocument.toJson(QJsonDocument::Compact);

    timer->callOnTimeout([=]() {
        broadcast->writeDatagram(hostAddressJsonData, QHostAddress::Broadcast, 8849);
    });

    timer->start(500);
}
