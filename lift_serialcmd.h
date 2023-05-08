#pragma once

#include <QByteArray>
#include <vector>

#include "Common_header.h"

class CMD_LIFT
{
public:
    CMD_LIFT();
    // req status info
    QByteArray REQ_MAIN_DATA;       // PID 193
    QByteArray RELEASE_LIMIT_SW;    // PID 17

    // homing
    QByteArray INIT_SET;            // PID 183
    QByteArray INIT_SET_CCW;        // PID
    QByteArray INIT_SET_CW;         // PID

    void init();

    QByteArray movePos(int pos);
    QByteArray movePos_Inc(int incLoc, short rpm);
    QByteArray setMaxVel_posCtr(short rpm);
    QByteArray setEncoderPPR(int ppr);

    bool appendCheckSum(QByteArray & bytes);

    int bytes2Int(const QByteArray& data);
    short bytes2Short(const QByteArray& data);

    QByteArray short2Bytes(short paramShort);
    QByteArray int2Bytes(int paramInt);

    char int2Byte(int val);

    void viewBytes(const QByteArray& data);

};

