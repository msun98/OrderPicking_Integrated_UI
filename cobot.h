#ifndef COBOT_H
#define COBOT_H

#include <QObject>
#include <QTimer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTime>

#include "Common_header.h"
#include "option_writer.h"

#include <eigen3/Eigen/Core>

class Cobot : public QObject
{
    Q_OBJECT

public:
    explicit Cobot(QObject *parent = nullptr);

    Option_writer settings;

    systemSTAT systemStat;
    systemCONFIG systemConfig;
    systemPOPUP  systemPopup;

    ipInfo IP_RB5_CMD;
    ipInfo IP_RB5_DATA;
    QTcpSocket cmdSocket;
    QTcpSocket dataSocket;

    QTimer* init_timer;

    bool flag_check_RB5_MODE = false;
    bool flag_check_connection_initializaion = false;

    // check socket status
    int test = 0;

    float _mslider_Spd = 0.f;

    int cmdConfirmFlag;
    int moveCmdFlag;
    int moveCmdCnt;

    int speed_changed = false;

    QByteArray recvBuf;

    QTimer timer;
    QTimer logicTimer;
    QTimer systemTimer;

    void write_log(Integrated_infomation& Ii, const QString& text);

    void check_socket_state();
    void MoveJoint_specific_pos(const QString& path);
    void SaveJoint_specific_pos(const QString& path);

    tcpInfo calcCalibration(xyzInfo visionPoint, const tcpInfo& v2n, const tcpInfo& n2e);
    Eigen::Matrix3f calcRoll(float x);
    Eigen::Matrix3f calcPitch(float y);
    Eigen::Matrix3f calcYaw(float z);


    void RB5_Connect_and_initialzation();
    void RB5_MODE_CHANGE();

    void CobotInit();
    void MoveJoint(float joint1, float joint2, float joint3, float joint4, float joint5, float joint6, float spd = -1, float acc = -1);
    void MoveTCP(float x, float y, float z, float rx, float ry, float rz, float spd = -1, float acc = -1);
    void MoveCircle_ThreePoint(int type, float x1, float y1, float z1, float rx1, float ry1, float rz1, float x2, float y2, float z2, float rx2, float ry2, float rz2, float spd = -1, float acc = -1);
    void MoveCircle_Axis(int type, float cx, float cy, float cz, float ax, float ay, float az, float rot_angle, float spd, float acc);

    void MoveJointBlend_Clear();
    void MoveJointBlend_AddPoint(float joint1, float joint2, float joint3, float joint4, float joint5, float joint6, float spd = -1, float acc = -1);
    void MoveJointBlend_MovePoint();

    void MoveTCPBlend_Clear();
    void MoveTCPBlend_AddPoint(float radius, float x, float y, float z, float rx, float ry, float rz, float spd = -1, float acc = -1);
    void MoveTCPBlend_MovePoint();

    void ControlBoxDigitalOut(int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7, int d8, int d9, int d10, int d11, int d12, int d13, int d14, int d15);
    void ControlBoxAnalogOut(float a0, float a1, float a2, float a3);

    void ToolOut(int volt, int d0, int d1);
    void ProgramMode_Real();
    void ProgramMode_Simulation();

    void BaseSpeedChange(float spd);

    void MotionPause();
    void MotionHalt();
    void MotionResume();

    void CollisionResume();
    int IsMotionIdle();

    void get_Joint_Tcp(jointInfo& js, tcpInfo& ts);

private:
    int initFlag;

signals:
    void SIGNAL_LOG_WRITE();

public slots:
    void onSystemCheck();
    void task_intialization();

    void onReadyCmdRead();
    void onReadyDataRead();
    void requestDataPacket();

    void onCmdConnected();
    void onCmdDisconnected();
    void onDataConnected();
    void onDataDisconnected();
    void onSliderChange_RB5_Speed(int val);

};

#endif // COBOT_H


