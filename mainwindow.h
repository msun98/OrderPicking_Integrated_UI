#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTcpSocket>
#include <QtDebug>
#include <QDrag>
#include <thread>
#include <queue>

#include "cobot.h"
#include "lift.h"
#include "keti_vision.h"
#include "kitech_gripper.h"
#include "log_writer.h"
#include "option_writer.h"
#include "telnetclient.h"
#include "networkthread.h"
#include "omron.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTimer *Main_timer;

    Log_writer _log;

    Option_writer settings;

    Cobot *obj_RB5;
    lift *obj_Lift;
    Keti_vision *obj_Keti;
    Kitech_gripper * obj_Kitech;
    Omron *obj_omron;

    int STAT = STANBY;
    std::atomic<bool> FSM_Flag;
    std::atomic<int> State_Machine_Flag;
    std::thread* FSM_Thread = NULL;
    std::queue<int> Senario_list;

    void connect_SIG_SLOT();
    void connect_Log_system();

    void check_connection();
    void check_state_LIFT();
    void check_state_RB5();

    void SetRobotInfoText();
//    void on_UPDATE_UI();
    bool map_flag = true;


    void get_FSM_State_From_QListWidget(std::queue<int>& list, Ui::MainWindow *& ui);
    void FSM_Loop();
    void read(QString filename);

    double x_original;
    double y_original;

    double heading;

    QVector<double> vector_x;
    QVector<double> vector_y;

    int push_num = 0;
    double mmperpix_x = 0;
    double mmperpix_y = 0;
    double min_x;
    double min_y;
    queue<tuple<int, int, int>> q;
    cv::Point2d pt1;
    cv::Point2d pt2;

    cv::Mat colored_map;
    cv::Mat Map_original;
    int write = 1;
    cv::Mat Drawing_original;

    cv::Point2d pos_Start;
    cv::Point2d pos_End;

    cv::Point p1;
    cv::Point p3;

    double img_x;
    double img_y;

    cv::Mat mainwindowMap;
    QTimer *uiTimer;
    QString textSaved = "";
    QStringList list;
    int check;
    bool flag;//도착 플래그



private slots:

    /*
        void mousePressEvent(QMouseEvent *event) override;
        void mouseReleaseEvent(QMouseEvent *event) override;
        void mouseDoubleClickEvent(QMouseEvent *event) override;
        void mouseMoveEvent(QMouseEvent *event) override;
     */
    void on_UPDATE_UI();

    void Update_UI();

    void Update_Log();

    void mouse_clicked(double x, double y);

    void mouse_released(double x, double y);

    void on_BTN_CONNECT_GRIPPER_clicked();

    void on_BTN_CONNECT_OMRON_clicked();

    void on_BTN_CONNECT_LIFT_clicked();

    void on_BTN_CONNECT_RB5_clicked();

    void on_BTN_CONNECT_VISION_clicked();

    void on_BTN_GLOBAL_INIT_clicked();

    void on_BTN_CHECK_SOCKET_STATUS_clicked();

    void on_BTN_RB5_MOVE_INIT_clicked();

    void on_BTN_RB5_MOVE_VISION_clicked();

    void on_BTN_RB5_MOVE_GRIPPER_READY_clicked();

    void on_BTN_RB5_MOVE_GRIPPER_GRAPS_clicked();

    void on_BTN_RB5_MOVE_EXTRA_1_clicked();

    void on_BTN_RB5_MOVE_EXTRA_2_clicked();

    void on_BTN_RB5_SAVE_INIT_clicked();

    void on_BTN_RB5_SAVE_VISION_clicked();

    void on_BTN_RB5_SAVE_GRIPPER_READY_clicked();

    void on_BTN_RB5_SAVE_GRIPPER_GRAPS_clicked();

    void on_BTN_RB5_SAVE_EXTRA_1_clicked();

    void on_BTN_RB5_SAVE_EXTRA_2_clicked();

    void on_BTN_RB5_PASUE_clicked();

    void on_BTN_RB5_RESUME_clicked();

    void on_BTN_RB5_HOLT_clicked();

    void on_SLIDER_RB5_SPEED_valueChanged(int value);

    void on_SB_RB5_SPEED_valueChanged(int arg1);

    void on_BTN_RB5_MODE_clicked();

    void on_BTN_SENARIO_CUSTOM_ADD_clicked();

    void on_BTN_SENARIO_CUSTOM_DEL_clicked();

    void on_BTN_SENARIO_EXECUTION_BASIC_clicked();

    void on_BTN_SENARIO_EXECUTION_CUSTOM_clicked();

    void on_BTN_VISION_CMD_WRITE_clicked();

    void on_BTN_GRIPPER_CMD_WRITE_clicked();

    void on_BTN_GRIPPER_UNFOLD_clicked();

    void on_BTN_GRIPPER_GRAP_clicked();

    void on_BTN_GRIPPER_VISION_clicked();

    void on_CB_GRIPPER_GE_CMD_WRITE_clicked();

    void on_BTN_SET_IP_PORT_KETI_clicked();

    void on_BTN_SET_IP_PORT_KITECH_clicked();

    void on_BTN_SET_CALIB_T_V2N_clicked();

    void on_BTN_SET_CALIB_T_N2E_clicked();

    void on_BTN_VISION_OUT_SAVE_clicked();

    void on_BTN_LIFT_SERIAL_OPEN_clicked();

    void on_BTN_OMRON_ADD_clicked();

    void on_BTN_LIFT_HOMING_clicked();

    void on_BTN_VISION_OUT_LOAD_clicked();

    void on_BTN_RB5_MOVE_GRAPS_POINT_clicked();

    void on_BTN_RB5_CALC_GRAPS_POINT_clicked();

    void on_BTN_SET_GRAPS_POINT_clicked();

    void on_BTN_LOAD_GRAPS_POINT_clicked();

    void on_BTN_TE_GLOBAL_CLEAR_clicked();

    void on_BTN_VISION_OUT_SET_clicked();

    void on_BTN_LIFT_REQ_DATA_clicked();

    void on_btn_say_clicked();


    void on_BTN_SH_11_clicked();

    void on_BTN_SH_12_clicked();

    void on_BTN_SH_13_clicked();

    void on_BTN_SH_14_clicked();

    void on_BTN_SH_21_clicked();
    
    void on_BTN_SH_22_clicked();
    
    void on_BTN_SH_23_clicked();
    
    void on_BTN_SH_24_clicked();
    
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
