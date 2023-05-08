#include "lift.h"

lift::lift(QObject *parent) : QObject(parent)
{
    connect(&serial_Lift, SIGNAL(readyRead()), this, SLOT(onReadyCmdRead()));
    connect(&statCheck, SIGNAL(timeout()), this, SLOT(onStatCheck()));

    Integrated_info.init_lift = -1;
}

bool lift::Open(QString port)
{
    if(serial_Lift.isOpen())
        serial_Lift.close();

    serial_Lift.setPortName(port);
    serial_Lift.setBaudRate(QSerialPort::Baud19200);
    serial_Lift.setDataBits(QSerialPort::Data8);
    serial_Lift.setStopBits(QSerialPort::OneStop);
    serial_Lift.setParity(QSerialPort::NoParity);

    write_log(Integrated_info, "[Lift] trying to connect..\n");

    if(!serial_Lift.open(QIODevice::ReadWrite))
    {
        write_log(Integrated_info, "[Lift] Lift connection failed.\n");
        return false;
    }
    else
    {
        write_log(Integrated_info, "[Lift] Lift connection succecssed.\n");

        Integrated_info.init_lift = 1;
        usleep(100*100);
        serial_Lift.write(LCMD.RELEASE_LIMIT_SW);

        statCheck.start(200);
        return true;
    }
}

void lift::Lift_Connect(QString port)
{
    if(!Open(port))
        return;
}

void lift::Lift_homing(bool dir)
{
    if(!serial_Lift.isOpen())
    {
        write_log(Integrated_info, "[Lift] Lift not connected yet.\n");
        return;
    }

    serial_Lift.write(LCMD.INIT_SET);
    usleep(100*100);

    if(dir == true)
        serial_Lift.write(LCMD.INIT_SET_CCW);

    else
        serial_Lift.write(LCMD.INIT_SET_CW);
}

void lift::writeData(int cmd, int data)
{
//    if (serial_Lift.isOpen())
//    {
//        switch (cmd) {
//        case liftCMD::NONE:
//            break;
//        case liftCMD::RELEASE_LIMIT_SW:
//            serial_Lift.write(LCMD.RELEASE_LIMIT_SW);
//            break;
//        case liftCMD::MOVE_POS:
//                serial_Lift.write(LCMD.movePos(data));
//            break;
//        case liftCMD::MOVE_POS_INC:
//                serial_Lift.write(LCMD.movePos_Inc(data));
//            break;
//        default:
//            break;
//        }
//    }
}

void lift::onStatCheck()
{
    if(!serial_Lift.isOpen())
        return;

    //serial_Lift.write(PID193);
}

void lift::onReadyCmdRead()
{
    QByteArray Received_Data = serial_Lift.readAll();
    qDebug() << "DATA Size " << Received_Data.size();

    serial_Lift.clear();
//    QString dec;
//    for(int i=0; i<Received_Data.size();++i)
//    {
//        QString hex = QString("%1").arg((unsigned char)Received_Data[i] , 0, 16);
//        bool bStatus = false;
//        uint nHex = hex.toUInt(&bStatus,16);

//        dec.append(QString::number(nHex));
//        dec.append(QString(" "));

//    }

//    QStringList decList;
//    decList = dec.split(" ");
//    int PID = decList.at(3).toInt();

//    switch (PID)
//    {
//    case 193:
//        read_PID193(Received_Data);
//        break;
//    default:
//        break;
//    }

//    qDebug() << "Received_Data " << dec;
}

void lift::req_mainData()
{
    serial_Lift.write(LCMD.REQ_MAIN_DATA);
}

void lift::read_PID193(const QByteArray &Received_Data)
{
    QByteArray dRPM;
    dRPM.append(Received_Data[5]);
    dRPM.append(Received_Data[6]);
    int rpm;
    memcpy(&rpm, dRPM.data(), 2);

    if(rpm == preRPM)
    {
        Integrated_info.lifts.is_lift_move = false;
    }
    else
    {
        Integrated_info.lifts.is_lift_move = true;
    }
    preRPM = rpm;

    QByteArray dAmpere;
    dAmpere.append(Received_Data[7]);
    dAmpere.append(Received_Data[8]);
    int ampere;
    memcpy(&ampere, dAmpere.data(), 2);

    QByteArray dControlType;
    dControlType.append(Received_Data[9]);
    int CT;
    memcpy(&CT, dControlType.data(), 1);

    QByteArray dSRPM;
    dSRPM.append(Received_Data[10]);
    dSRPM.append(Received_Data[11]);
    int srpm;
    memcpy(&srpm, dSRPM.data(), 2);

    QByteArray dCToutput;
    dCToutput.append(Received_Data[12]);
    dCToutput.append(Received_Data[13]);
    int ctout;
    memcpy(&ctout, dCToutput.data(), 2);

    QByteArray dAlaram;
    dAlaram.append(Received_Data[14]);
    int ala;
    memcpy(&ala, dAlaram.data(), 1);

    QByteArray dLocation;
    dLocation.append(Received_Data[15]);
    dLocation.append(Received_Data[16]);
    dLocation.append(Received_Data[17]);
    dLocation.append(Received_Data[18]);
    int locat;
    memcpy(&locat, dLocation.data(), 4);

    qDebug() << "LIFT LOCATION : " << locat;

    QByteArray dBrake;
    dBrake.append(Received_Data[15]);
    int brake;
    memcpy(&brake, dBrake.data(), 1);

    QByteArray dTemp;
    dTemp.append(Received_Data[16]);
    int temp;
    memcpy(&temp, dTemp.data(), 1);
}

void lift::write_log(Integrated_infomation& Ii, const QString& text)
{
    Ii.Log_info.append(text);
    emit SIGNAL_LOG_WRITE();
}
