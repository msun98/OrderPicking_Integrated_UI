#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>

#include "Common_header.h"
#include "lift_serialcmd.h"

class lift : public QObject
{
    Q_OBJECT
public:
    explicit lift(QObject *parent = nullptr);

    QSerialPort serial_Lift;
    CMD_LIFT LCMD;
    QTimer statCheck;

    int  preRPM = -1;
    bool flag_changeRPM = false;

    bool Open(QString port);

    void req_mainData();


    void Lift_Connect(QString port);
    void Lift_homing(bool dir = true);
    void write_log(Integrated_infomation& Ii, const QString& text);
    void writeData(int cmd, int data);

    void read_PID193(const QByteArray &Received_Data);

signals:
    void SIGNAL_LOG_WRITE();

private slots:

    void onStatCheck();

    void onReadyCmdRead();



};

#endif // LIFT_H
