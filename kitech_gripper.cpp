#include "kitech_gripper.h"


Kitech_gripper::Kitech_gripper(QObject *parent) : QObject(parent)
{
    Kitech_Client = new QTcpSocket();

    IP_GRIPPER.ip = "192.168.1.151";
    IP_GRIPPER.port = 6002;
    connect(Kitech_Client, SIGNAL(connected()), this, SLOT(onKitechConnected()));
    connect(Kitech_Client, SIGNAL(disconnected()), this, SLOT(onKitechdisConnected()));
}

void Kitech_gripper::Gripper_Connect()
{
    if(!Integrated_info.init_gripper)
    {
        Kitech_Client->connectToHost(QHostAddress(IP_GRIPPER.ip), IP_GRIPPER.port);
        connect(Kitech_Client, SIGNAL(readyRead()), this, SLOT(onReadyCmdRead()));
        write_log(Integrated_info, "[Gripper] Server conneting...\n");
    }
}

void Kitech_gripper::onReadyCmdRead()
{
    QByteArray Read_Data = Kitech_Client->readAll();
    Integrated_info.kitech_res = QString(Read_Data);
}

void Kitech_gripper::onKitechConnected()
{
    Integrated_info.init_gripper = true;
    write_log(Integrated_info, "[Gripper] Server connected.\n");
}

void Kitech_gripper::onKitechdisConnected()
{
    Integrated_info.init_gripper = false;
    write_log(Integrated_info, "[Gripper] Server disconnected.\n");
}

void Kitech_gripper::write_log(Integrated_infomation& Ii, const QString& text)
{
    Ii.Log_info.append(text);
    emit SIGNAL_LOG_WRITE();
}

