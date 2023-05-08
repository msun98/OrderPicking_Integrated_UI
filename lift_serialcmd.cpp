#include "lift_serialcmd.h"

CMD_LIFT::CMD_LIFT()
{
    init();
}

void CMD_LIFT::init()
{
    REQ_MAIN_DATA.resize(7);
    REQ_MAIN_DATA[0] = 0xb7;
    REQ_MAIN_DATA[1] = 0xac;
    REQ_MAIN_DATA[2] = 0x01;
    REQ_MAIN_DATA[3] = 0x04;
    REQ_MAIN_DATA[4] = 0x01;
    REQ_MAIN_DATA[5] = 0xc1;
    REQ_MAIN_DATA[6] = 0xd6;

    // PID_FUNC_CMD_TYPE
    INIT_SET.resize(8);
    INIT_SET[0] = 0xb7;
    INIT_SET[1] = 0xac;
    INIT_SET[2] = 0x01;
    INIT_SET[3] = 0xb7;
    INIT_SET[4] = 0x02;
    INIT_SET[5] = 0x03;
    INIT_SET[6] = 0x00;
    INIT_SET[7] = 0xe0;

    INIT_SET_CW.resize(7);
    INIT_SET_CW[0] = 0xb7;
    INIT_SET_CW[1] = 0xac;
    INIT_SET_CW[2] = 0x01;
    INIT_SET_CW[3] = 0x23;
    INIT_SET_CW[4] = 0x01;
    INIT_SET_CW[5] = 0x02;
    INIT_SET_CW[6] = 0x76;

    INIT_SET_CCW.resize(7);
    INIT_SET_CCW[0] = 0xb7;
    INIT_SET_CCW[1] = 0xac;
    INIT_SET_CCW[2] = 0x01;
    INIT_SET_CCW[3] = 0x23;
    INIT_SET_CCW[4] = 0x01;
    INIT_SET_CCW[5] = 0x01;
    INIT_SET_CCW[6] = 0x77;

    RELEASE_LIMIT_SW.resize(7);
    RELEASE_LIMIT_SW[0] = 0xb7;
    RELEASE_LIMIT_SW[1] = 0xac;
    RELEASE_LIMIT_SW[2] = 0x01;
    RELEASE_LIMIT_SW[3] = 0x11;
    RELEASE_LIMIT_SW[4] = 0x01;
    RELEASE_LIMIT_SW[5] = 0x00;
    RELEASE_LIMIT_SW[6] = 0x8a;

}


QByteArray CMD_LIFT::movePos(int pos)
{
    auto toByte = int2Bytes(pos);

    // vec<char> to QByteArray


}


QByteArray CMD_LIFT::movePos_Inc(int incLoc, short rpm)
{
    QByteArray data;
    data.append(int2Byte(183));
    data.append(int2Byte(172));
    data.append(int2Byte(1));
    data.append(int2Byte(220));
    data.append(int2Byte(6));

    auto dloc = int2Bytes(incLoc);
    data.append(dloc);

    auto drpm = short2Bytes(rpm);
    data.append(drpm);

    appendCheckSum(data);

    if(data.size()!=12)
        return QByteArray();

    return data;
}

QByteArray CMD_LIFT::setMaxVel_posCtr(short rpm)
{
    QByteArray data;
    data.append(int2Byte(183));
    data.append(int2Byte(172));
    data.append(int2Byte(1));
    data.append(int2Byte(122));
    data.append(int2Byte(2));


    auto drpm = short2Bytes(rpm);
    data.append(drpm);

    appendCheckSum(data);

    if(data.size()!=8)
        return QByteArray();

    return data;
}

QByteArray CMD_LIFT::setEncoderPPR(int ppr)
{
    auto toByte = int2Bytes(ppr);
}

bool CMD_LIFT::appendCheckSum(QByteArray & bytes)
{
    char checkSum = NULL;

    if(bytes.size() ==0)
        return false;

    for(int i=0; i<=bytes.size(); ++i)
    {
        checkSum += bytes[i];
    }
    checkSum = ~checkSum + char(1);

    bytes.append(checkSum);

    return true;
}

char CMD_LIFT::int2Byte(int val)
{
    if(val > 255)
        return NULL;

    char out;
    memcpy(&out, &val, 1);
    return out;
}

int CMD_LIFT::bytes2Int(const QByteArray& data)
{
    int output;
    memcpy(&output, data.data(), 4);

    return output;
}

short CMD_LIFT::bytes2Short(const QByteArray& data)
{

    short output;
    memcpy(&output, data.data(), 4);

    return output;
}

QByteArray CMD_LIFT::short2Bytes(short paramShort)
{
    QByteArray bytes;
    bytes.reserve(2);

    memcpy(bytes.data(), &paramShort, 2);

    return bytes;
}

QByteArray CMD_LIFT::int2Bytes(int paramInt)
{

    QByteArray bytes;
    bytes.reserve(4);

    memcpy(bytes.data(), &paramInt, 4);

    return bytes;
}

void CMD_LIFT::viewBytes(const QByteArray& data)
{
    QString v;
    for(int i=0; i<data.size(); ++i)
    {
        v.append(data.at(i));
        v = v + " ";
    }
    qDebug() << v;
}
