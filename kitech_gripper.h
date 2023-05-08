#ifndef KITECH_GRIPPER_H
#define KITECH_GRIPPER_H

#include <QObject>
#include <QTcpSocket>
#include <QByteArray>
#include <QHostAddress>

#include "Common_header.h"

class Kitech_gripper : public QObject
{
    Q_OBJECT

public:
    explicit Kitech_gripper(QObject *parent = nullptr);

    ipInfo IP_GRIPPER;
    QTcpSocket *Kitech_Client;

    void write_log(Integrated_infomation& Ii, const QString& text);
    void Gripper_Connect();

signals:
    void SIGNAL_LOG_WRITE();

public slots:
    void onReadyCmdRead();

    void onKitechConnected();

    void onKitechdisConnected();
};

#endif // KITECH_GRIPPER_H
