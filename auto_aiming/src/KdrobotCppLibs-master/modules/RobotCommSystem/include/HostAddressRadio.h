/**
 * @file HostAddressRadio.h
 * @author yao
 * @date 2021年1月13日
 */

#ifndef KDROBOTCPPLIBS_HOSTADDRESSRADIO_H
#define KDROBOTCPPLIBS_HOSTADDRESSRADIO_H

#include <QObject>
#include <spdlogger.h>
#include <QTimer>
#include <QUdpSocket>
#include <QHostAddress>
#include <QNetworkAddressEntry>

class HostAddressRadio : public QObject {
Q_OBJECT

    spdlogger logger;
    QTimer *timer;
    QUdpSocket *broadcast;
    QList<QNetworkAddressEntry> HostAddressEntry;
    QByteArray hostAddressJsonData;

public:
    HostAddressRadio(QObject *parent = nullptr);

    inline void stop() {
        timer->stop();
    }
};

#endif
