#include "cobot.h"

Cobot::Cobot(QObject *parent) : QObject(parent)
{
    memset(&systemStat, 0, sizeof(systemSTAT));
    systemStat.sdata.program_mode = -1;
    systemStat.sdata.robot_state = -1;

    IP_RB5_CMD.ip = "192.168.1.100";
    IP_RB5_CMD.port = 5000;

    IP_RB5_DATA.ip = "192.168.1.100";
    IP_RB5_DATA.port = 5001;

    init_timer = new QTimer(this);

    connect(&cmdSocket,  SIGNAL(connected()),    this, SLOT(onCmdConnected()));
    connect(&cmdSocket,  SIGNAL(disconnected()), this, SLOT(onCmdDisconnected()));
    connect(&dataSocket, SIGNAL(connected()),    this, SLOT(onDataConnected()));
    connect(&dataSocket, SIGNAL(disconnected()), this, SLOT(onDataDisconnected()));

    connect(&timer, SIGNAL(timeout()), this, SLOT(requestDataPacket()));
    connect(&systemTimer, SIGNAL(timeout()), this, SLOT(onSystemCheck()));
    systemTimer.start(300);
}

void Cobot::onSystemCheck()
{
//    qDebug() << "systemStat.sdata.init_state_info " << systemStat.sdata.init_state_info << " Integrated_info.RB5_check_connection_CMD_DATA "
//             << Integrated_info.RB5_check_connection_CMD_DATA;
    check_socket_state();
    get_Joint_Tcp(Integrated_info.joints, Integrated_info.tcps);

    if(Integrated_info.RB5_check_connection_CMD && Integrated_info.RB5_check_connection_DATA)
    {
        Integrated_info.init_rb5 = CMD_DATA_CONNECTED;
        Integrated_info.RB5_check_connection_CMD_DATA = true;
    }

    else
        Integrated_info.RB5_check_connection_CMD_DATA = false;

    if(Integrated_info.RB5_check_connection_CMD_DATA == true && systemStat.sdata.init_state_info == INIT_STAT_INFO_INIT_DONE)
    {
        Integrated_info.init_rb5 = ALL_CONNECT_AND_INIT_COMPLETE;
        if(flag_check_connection_initializaion == false)
        {
             write_log(Integrated_info, "[RB5] RB5 Init completed.");
             flag_check_connection_initializaion = true;
        }
    }


    if(fabs(_mslider_Spd - systemStat.sdata.default_speed) > 0.005)
    {
        if(speed_changed == true)
        {
            // value changed
            BaseSpeedChange(_mslider_Spd);
            speed_changed = false;
        }
        else
        {
            float spd = systemStat.sdata.default_speed;
        }
    }

}

void Cobot::onReadyCmdRead()
{
    QByteArray datas = cmdSocket.readAll();
    if(QString(datas.data()).compare("The command was executed\n") == 0)
    {
        //qDebug() << "The RB5 command was executed.";
        cmdConfirmFlag = true;
        if(moveCmdFlag == true)
        {
            moveCmdCnt = 5;
            systemStat.sdata.robot_state = 3;
            moveCmdFlag = false;
        }
    }
    else
    {
        //print(QString::fromLocal8Bit(datas.data(),datas.length()));
    }
}

void Cobot::onReadyDataRead()
{
    QByteArray datas = dataSocket.readAll();
    recvBuf +=datas;

    while(recvBuf.length() > 4 )
    {
        if( recvBuf[0] == '$')
        {
            int size = ((int)((unsigned char)recvBuf[2]<<8)|(int)((unsigned char)recvBuf[1]));
            if(size <= recvBuf.length() )
            {
                int templen = recvBuf.length();
                if(3 == recvBuf[3])
                {
                    if(moveCmdCnt > 0)
                    {
                        moveCmdCnt--;
                    }
                    else
                    {
                        memcpy(&systemStat,recvBuf.data(),sizeof(systemSTAT));
                    }
                    recvBuf.remove(0,sizeof(systemSTAT));
                }
                else if(4 == recvBuf[3])
                {
                    memcpy(&systemConfig,recvBuf.data(),sizeof(systemCONFIG));
                    recvBuf.remove(0,sizeof(systemCONFIG));
                }
                else if(10 == recvBuf[3])
                {
                    memcpy(&systemPopup,recvBuf.data(),sizeof(systemPOPUP));
                    recvBuf.remove(0,sizeof(systemPOPUP));
                }
                else
                {
                    recvBuf.remove(0,1);
                }

            }

        }
        else
        {
            recvBuf.remove(0,1);
        }
    }
}

void Cobot::requestDataPacket()
{
    dataSocket.write("reqdata");
}

void Cobot::onCmdConnected()
{
   Integrated_info.RB5_check_connection_CMD = true;
   Integrated_info.init_rb5 = CMD_CONNECTED;
   write_log(Integrated_info, "[RB5] CMD socket connected!\n");
}

void Cobot::onCmdDisconnected()
{
   Integrated_info.RB5_check_connection_CMD = false;
   Integrated_info.init_rb5 = NO_CONNECTION;
   write_log(Integrated_info, "[RB5] CMD socket disconnected.\n");
}

void Cobot::onDataConnected()
{
   Integrated_info.RB5_check_connection_DATA = true;
   Integrated_info.init_rb5 = CMD_DATA_CONNECTED;
   write_log(Integrated_info, "[RB5] DATA socket connected!\n");
}

void Cobot::onDataDisconnected()
{
   Integrated_info.RB5_check_connection_DATA = false;
   Integrated_info.init_rb5 = NO_CONNECTION;
   write_log(Integrated_info, "[RB5] CMD socket disconnected.\n");
}

int Cobot::IsMotionIdle()
{
    return ((cmdConfirmFlag == true) && (systemStat.sdata.robot_state == 1));
}
void Cobot::CobotInit()
{
    QString text;
    text.sprintf("mc jall init");
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void Cobot::ProgramMode_Real()
{
    QString text;
    text.sprintf("pgmode real");
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void Cobot::ProgramMode_Simulation()
{
    QString text;
    text.sprintf("pgmode simulation");
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void Cobot::MoveJoint(float joint1, float joint2, float joint3, float joint4, float joint5, float joint6, float spd, float acc)
{
    if(joint1 == -1)
        return;

    QString text;
    text.sprintf("jointall %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f", spd, acc, joint1, joint2, joint3, joint4, joint5, joint6);
    moveCmdFlag = true;
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
    systemStat.sdata.robot_state = 3; //run
}
void Cobot::MoveTCP(float x, float y, float z, float rx, float ry, float rz, float spd, float acc)
{
    QString text;
    text.sprintf("movetcp %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f", spd, acc, x, y, z, rx, ry, rz);
    moveCmdFlag = true;
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
    systemStat.sdata.robot_state = 3; //run
}
void Cobot::MoveCircle_ThreePoint(int type, float x1, float y1, float z1, float rx1, float ry1, float rz1, float x2, float y2, float z2, float rx2, float ry2, float rz2, float spd, float acc)
{
    QString text;
    char buf[15];
    if(type == 0)
    {
        sprintf(buf, "intended");
    }
    else if(type == 1)
    {
        sprintf(buf, "constant");
    }
    else if(type == 2)
    {
        sprintf(buf, "radial");
    }
    text.sprintf("movecircle threepoints %s %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f",
                 buf, spd, acc, x1, y1, z1, rx1, ry1, rz1, x2, y2, z2, rx2, ry2, rz2);
    moveCmdFlag = true;
    cmdConfirmFlag =false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
    systemStat.sdata.robot_state = 3;
}
void Cobot::MoveCircle_Axis(int type, float cx, float cy, float cz, float ax, float ay, float az, float rot_angle, float spd, float acc)
{
    QString text;
    char buf[15];
    if(type == 0)
    {
        sprintf(buf, "intended");
    }
    else if(type == 1)
    {
        sprintf(buf, "constant");
    }
    else if(type == 2)
    {
        sprintf(buf, "radial");
    }
    text.sprintf("movecircle axis %s %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f",
                 buf, spd, acc, rot_angle, cx, cy, cz, ax, ay, az);
    moveCmdFlag = true;
    cmdConfirmFlag =false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
    systemStat.sdata.robot_state = 3;
}
void Cobot::MoveJointBlend_Clear()
{
    QString text;
    text.sprintf("blend_jnt clear_pt");
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void Cobot::MoveJointBlend_AddPoint(float joint1, float joint2, float joint3, float joint4, float joint5, float joint6, float spd, float acc)
{
    QString text;
    text.sprintf("blend_jnt add_pt %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f", spd, acc, joint1, joint2, joint3, joint4, joint5, joint6);
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
    systemStat.sdata.robot_state = 3; //run
}
void Cobot::MoveJointBlend_MovePoint()
{
    QString text;
    text.sprintf("blend_jnt move_pt");
    moveCmdFlag = true;
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
    systemStat.sdata.robot_state = 3;
}
void Cobot::MoveTCPBlend_Clear()
{
    QString text;
    text.sprintf("blend_tcp clear_pt");
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void Cobot::MoveTCPBlend_AddPoint(float radius, float x, float y, float z, float rx, float ry, float rz, float spd, float acc)
{
    QString text;
    text.sprintf("blend_tcp add_pt %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f", spd, acc, radius, x, y, z, rx, ry, rz);
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
    systemStat.sdata.robot_state = 3; //run
}
void Cobot::MoveTCPBlend_MovePoint()
{
    QString text;
    text.sprintf("blend_tcp move_pt");
    moveCmdFlag = true;
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
    systemStat.sdata.robot_state = 3;
}
void Cobot::ControlBoxDigitalOut(int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7, int d8, int d9, int d10, int d11, int d12, int d13, int d14, int d15)
{
    QString text;
    text.sprintf("digital_out %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15);
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void Cobot::ControlBoxAnalogOut(float a0, float a1, float a2, float a3)
{
    QString text;
    text.sprintf("analog_out %.3f, %.3f, %.3f, %.3f", a0, a1, a2, a3);
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void Cobot::ToolOut(int volt, int d0, int d1)
{
    int temp_volt = volt;
    if((temp_volt != 12) && (temp_volt != 24))
    {
        temp_volt = 0;
    }

    QString text;
    text.sprintf("tool_out %d, %d, %d", temp_volt, d0, d1);
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void Cobot::BaseSpeedChange(float spd)
{
    QString text;
    if(spd > 1.0)
    {
        spd = 1.0;
    }
    if(spd < 0.0)
    {
        spd = 0.0;
    }
    text.sprintf("sdw default_speed %.3f", spd);
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void Cobot::MotionPause()
{
    if(Integrated_info.init_rb5 == CMD_DATA_CONNECTED)
    {
        QString text;
        text.sprintf("task pause");
        cmdConfirmFlag = false;
        cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
        write_log(Integrated_info, "[RB5] RB5 pause.\n");
    }
}
void Cobot::MotionHalt()
{
    if(Integrated_info.init_rb5 == CMD_DATA_CONNECTED)
    {
        QString text;
        text.sprintf("task stop");
        cmdConfirmFlag = false;
        cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
        write_log(Integrated_info, "[RB5] RB5 holt.\n");
    }
}
void Cobot::MotionResume()
{
    if(Integrated_info.init_rb5 == CMD_DATA_CONNECTED)
    {
        QString text;
        text.sprintf("task resume_a");
        cmdConfirmFlag = false;
        cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
        write_log(Integrated_info, "[RB5] RB5 resume.\n");
    }
}
void Cobot::CollisionResume()
{
    if(Integrated_info.init_rb5 == CMD_DATA_CONNECTED)
    {
        QString text;
        text.sprintf("task resume_b");
        cmdConfirmFlag = false;
        cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
        write_log(Integrated_info, "[RB5] RB5 collision resume.\n");
    }
}

void Cobot::onSliderChange_RB5_Speed(int val)
{
    qDebug() << "val" << val;
   _mslider_Spd  = val/100.0;
   speed_changed = true;
}

void Cobot::RB5_Connect_and_initialzation()
{
    write_log(Integrated_info, "[RB5] Connection start.\n");
    if(!Integrated_info.RB5_check_connection_CMD)
    {
        cmdSocket.connectToHost(QHostAddress(IP_RB5_CMD.ip), IP_RB5_CMD.port);
        connect(&cmdSocket, SIGNAL(readyRead()), this, SLOT(onReadyCmdRead()));
        write_log(Integrated_info, "[RB5] CMD socket conneting...\n");
    }
    usleep(300);
    if(!Integrated_info.RB5_check_connection_DATA)
    {
        dataSocket.connectToHost(QHostAddress(IP_RB5_DATA.ip), IP_RB5_DATA.port);
        connect(&dataSocket, SIGNAL(readyRead()), this, SLOT(onReadyDataRead()));
        write_log(Integrated_info, "[RB5] DATA socket conneting...\n");
        timer.start(20);
    }

    connect(init_timer, SIGNAL(timeout()), this, SLOT(task_intialization()));
    init_timer->start(200);
}

void Cobot::task_intialization()
{
    //qDebug() << "task timer";
    if(Integrated_info.RB5_check_connection_CMD_DATA == true)
    {
        if(systemStat.sdata.init_state_info == INIT_STAT_INFO_INIT_DONE)
        {
            Integrated_info.init_rb5 = ALL_CONNECT_AND_INIT_COMPLETE;
            write_log(Integrated_info, "[RB5] Initialzation already finished.\n");
        }
        else
        {
            write_log(Integrated_info, "[RB5] Initialzation start.\n");
            CobotInit();
        }

        init_timer->stop();
    }
}

void Cobot::MoveJoint_specific_pos(const QString& path)
{
    qDebug() << "Integrated_info.init_rb5 " << Integrated_info.init_rb5 << " path " << path;
    if(Integrated_info.init_rb5 == ALL_CONNECT_AND_INIT_COMPLETE)
    {
        jointInfo js;
        tcpInfo ts;
        settings.ReadSettingFile_RB5(path.toStdString(), js, ts);

        if(path == "RB5_INIT_POS.json")
            write_log(Integrated_info, "[RB5] RB5 move init pos.\n");
        else if(path == "RB5_VISION_POS.json")
            write_log(Integrated_info, "[RB5] RB5 move vision pos.\n");
        else if(path == "RB5_GRIPPER_READY_POS.json")
            write_log(Integrated_info, "[RB5] RB5 move gripper ready pos.\n");
        else if(path == "RB5_GRIPPER_GRAPS_POS.json")
            write_log(Integrated_info, "[RB5] RB5 move gripper graps pos.\n");
        else if(path == "RB5_EXTRA_1_POS.json")
            write_log(Integrated_info, "[RB5] RB5 move extra 1 pos.\n");
        else if(path == "RB5_EXTRA_2_POS.json")
            write_log(Integrated_info, "[RB5] RB5 move extra 2 pos.\n");

        MoveJoint(js.joint_1, js.joint_2 , js.joint_3 , js.joint_4, js.joint_5, js.joint_6, -1, -1);
    }
    else
        write_log(Integrated_info, "[RB5] RB5 does not connected.\n");

}

void Cobot::SaveJoint_specific_pos(const QString& path)
{
    if(Integrated_info.init_rb5 == ALL_CONNECT_AND_INIT_COMPLETE)
    {
        jointInfo js;
        tcpInfo ts;
        get_Joint_Tcp(js, ts);

        if(settings.WriteSettingFile_RB5(path.toStdString(), js, ts))
        {
            if(path == "RB5_INIT_POS.json")
                write_log(Integrated_info, "[RB5] RB5 save init pos.\n");
            else if(path == "RB5_VISION_POS.json")
                write_log(Integrated_info, "[RB5] RB5 save vision pos.\n");
            else if(path == "RB5_GRIPPER_READY_POS.json")
                write_log(Integrated_info, "[RB5] RB5 save gripper ready pos.\n");
            else if(path == "RB5_GRIPPER_GRAPS_POS.json")
                write_log(Integrated_info, "[RB5] RB5 save gripper graps pos.\n");
            else if(path == "RB5_EXTRA_1_POS.json")
                write_log(Integrated_info, "[RB5] RB5 save extra 1 pos.\n");
            else if(path == "RB5_EXTRA_2_POS.json")
                write_log(Integrated_info, "[RB5] RB5 save extra 2 pos.\n");
        }
    }
    else
    {
       write_log(Integrated_info, "[RB5] RB5 does not connected.\n");
    }
}
void Cobot::RB5_MODE_CHANGE()
{
    if(Integrated_info.init_rb5 == ALL_CONNECT_AND_INIT_COMPLETE)
    {
        if(Integrated_info.RB5_mode == false)
        {
            QString text;
            text.sprintf("pgmode real");
            cmdConfirmFlag = false;
            cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
            Integrated_info.RB5_mode = true;
            write_log(Integrated_info, "[RB5] RB5 Real mode.\n");
        }
        else
        {
            QString text;
            text.sprintf("pgmode simulation");
            cmdConfirmFlag = false;
            cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
            Integrated_info.RB5_mode = false;
            write_log(Integrated_info, "[RB5] RB5 Simulation mode.\n");
        }
    }
    else
    {
       write_log(Integrated_info, "[RB5] RB5 does not connected.\n");
    }

}

void Cobot::get_Joint_Tcp(jointInfo& js, tcpInfo& ts)
{
    js.joint_1 = systemStat.sdata.jnt_ang[0];
    js.joint_2 = systemStat.sdata.jnt_ang[1];
    js.joint_3 = systemStat.sdata.jnt_ang[2];
    js.joint_4 = systemStat.sdata.jnt_ang[3];
    js.joint_5 = systemStat.sdata.jnt_ang[4];
    js.joint_6 = systemStat.sdata.jnt_ang[5];

    ts.x  = systemStat.sdata.tcp_pos[0];
    ts.y  = systemStat.sdata.tcp_pos[1];
    ts.z  = systemStat.sdata.tcp_pos[2];
    ts.rx = systemStat.sdata.tcp_pos[3];
    ts.ry = systemStat.sdata.tcp_pos[4];
    ts.rz = systemStat.sdata.tcp_pos[5];
}

void Cobot::check_socket_state()
{
    Integrated_info.socket_state_RB5_CMD = cmdSocket.state();
    Integrated_info.socket_state_RB5_DATA = dataSocket.state();
}

tcpInfo Cobot::calcCalibration(xyzInfo visionPoint, const tcpInfo& v2n, const tcpInfo& n2e)
{
    tcpInfo   tcps;
    jointInfo joints;
    settings.ReadSettingFile_RB5("RB5_VISION_POS.json", joints, tcps);

    auto roll_v  = calcRoll(tcps.rx);
    auto pitch_v = calcPitch(tcps.ry);
    auto yaw_v   = calcYaw(tcps.rz);

    Eigen::Matrix4f T_RB5_visionPos= Eigen::Matrix4f::Identity();
    T_RB5_visionPos << 1.f, 0.f, 0.f, tcps.x,
                   0.f, 1.f, 0.f, tcps.y,
                   0.f, 0.f, 1.f, tcps.z,
                   0.f, 0.f, 0.f, 1.f;

    Eigen::Matrix3f R_RB5_visionPos = yaw_v * pitch_v * roll_v;
    T_RB5_visionPos.block(0,0,3,3) = R_RB5_visionPos;


    Eigen::Matrix4f t_N2E = Eigen::Matrix4f::Identity();
    t_N2E <<  1.f, 0.f, 0.f, 0.f,
              0.f, 1.f, 0.f, n2e.y,
              0.f, 0.f, 1.f, n2e.z,
              0.f, 0.f, 0.f, 1.f;

    auto roll_N2E  = calcRoll(n2e.rx);
    auto pitch_N2E = calcPitch(n2e.ry);
    auto yaw_N2E   = calcYaw(n2e.rz);

    Eigen::Matrix4f R_N2E = Eigen::Matrix4f::Identity();
    R_N2E << 1.f, 0.f, 0.f, 0.0,
             0.f, 1.f, 0.f, 0.0,
             0.f, 0.f, 1.f, 0.0,
             0.f, 0.f, 0.f, 1.f;

    Eigen::Matrix3f _R_N2E = yaw_N2E * pitch_N2E * roll_N2E;
    R_N2E.block(0,0,3,3) = _R_N2E;

    Eigen::Matrix4f T_P2N = Eigen::Matrix4f::Identity();
    T_P2N << 1.f, 0.f, 0.f, visionPoint.x + v2n.x,
             0.f, 1.f, 0.f, visionPoint.y + v2n.y,
             0.f, 0.f, 1.f, visionPoint.z + v2n.z,
             0.f, 0.f, 0.f,                   1.f;

    Eigen::Matrix4f T_RB5_to_Camera = T_RB5_visionPos * t_N2E * R_N2E * T_P2N;

    tcpInfo GrapsPoints;
    GrapsPoints.x = T_RB5_to_Camera(0,3);
    GrapsPoints.y = T_RB5_to_Camera(1,3);
    GrapsPoints.z = T_RB5_to_Camera(2,3);
    GrapsPoints.rx = tcps.rx;
    GrapsPoints.ry = tcps.ry;
    GrapsPoints.rz = tcps.rz;

    return GrapsPoints;
}

Eigen::Matrix3f Cobot::calcRoll(float x)
{
   float rad = x / 180 * M_PI;
   Eigen::Matrix3f Rx;
   Rx << 1,        0,         0,
         0, cos(rad), -sin(rad),
         0, sin(rad),  cos(rad);
   return Rx;
}

Eigen::Matrix3f Cobot::calcPitch(float y)
{
    float rad = y / 180 * M_PI;
    Eigen::Matrix3f Ry;
    Ry << cos(rad),     0,  sin(rad),
                 0,     1,         0,
         -sin(rad),     0,  cos(rad);
    return Ry;
}

Eigen::Matrix3f Cobot::calcYaw(float z)
{
    float rad = z / 180 * M_PI;
    Eigen::Matrix3f Rz;
    Rz << cos(rad),   -sin(rad),        0,
          sin(rad),    cos(rad),        0,
                  0,          0,        1;
    return Rz;
}


void Cobot::write_log(Integrated_infomation& Ii, const QString& text)
{
    Ii.Log_info.append(text);
    emit SIGNAL_LOG_WRITE();
}
