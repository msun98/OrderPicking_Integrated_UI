/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <qmylabel.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionIP_Port_change;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QLabel *LB_RAINBOW_LOGO_2;
    QLabel *lable_get_info_2;
    QFrame *frame_robot_info;
    QGridLayout *gridLayout_5;
    QLabel *label_status;
    QTextEdit *te_status;
    QLabel *label_battery;
    QLineEdit *le_battery;
    QLabel *label_location;
    QLineEdit *le_location;
    QLabel *label_temperature;
    QLineEdit *le_temperature;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_6;
    QLabel *label_23;
    QLineEdit *LE_OMRON_X;
    QPushButton *BTN_OMRON_ADD;
    QPushButton *BTN_OMRON_SAVE_GOAL_1;
    QLabel *label_20;
    QLineEdit *LE_OMRON_BATTERY;
    QLabel *label_24;
    QLineEdit *LE_OMRON_Y;
    QLabel *label_21;
    QLineEdit *LE_OMRON_LOCATION;
    QPushButton *BTN_OMRON_SAVE_ST;
    QPushButton *BTN_OMRON_SAVE_GOAL_2;
    QLabel *label_25;
    QLineEdit *LE_OMRON_HEADING;
    QLabel *label_22;
    QLineEdit *LE_OMRON_TEMP;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_7;
    QLineEdit *le_say;
    QPushButton *btn_say;
    QWidget *tab_6;
    QGroupBox *GR_LIFT;
    QLineEdit *LE_LIFT_REF;
    QLineEdit *LE_LIFT_ENCODER;
    QLineEdit *LE_LIFT_GOAL;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QPushButton *BTN_LIFT_LOAD_TOP;
    QPushButton *BTN_LIFT_SAVE_TOP;
    QPushButton *BTN_LIFT_SET_TOP;
    QLineEdit *LE_LIFT_TOP;
    QPushButton *BTN_LIFT_SAVE_MIDDLE;
    QPushButton *BTN_LIFT_SET_MIDDLE;
    QLineEdit *LE_LIFT_MIDDLE;
    QPushButton *BTN_LIFT_LOAD_MIDDLE;
    QPushButton *BTN_LIFT_SAVE_BOTTOM;
    QPushButton *BTN_LIFT_SET_BOTTOM;
    QLineEdit *LE_LIFT_BOTTOM;
    QPushButton *BTN_LIFT_LOAD_BOTTOM;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QComboBox *CB_SERIAL_PORT;
    QPushButton *BTN_LIFT_SERIAL_OPEN;
    QPushButton *BTN_LIFT_HOMING;
    QPushButton *BTN_LIFT_REQ_DATA;
    QLabel *LB_RAINBOW_LOGO_3;
    QWidget *tab_3;
    QGroupBox *GR_RB5;
    QPushButton *BTN_RB5_MOVE_VISION;
    QPushButton *BTN_RB5_MOVE_GRIPPER_READY;
    QPushButton *BTN_RB5_MOVE_GRIPPER_GRAPS;
    QPushButton *BTN_RB5_MOVE_INIT;
    QPushButton *BTN_RB5_SAVE_GRIPPER_GRAPS;
    QPushButton *BTN_RB5_SAVE_GRIPPER_READY;
    QPushButton *BTN_RB5_SAVE_INIT;
    QPushButton *BTN_RB5_SAVE_VISION;
    QPushButton *BTN_RB5_MODE;
    QSlider *SLIDER_RB5_SPEED;
    QLabel *label_7;
    QPushButton *BTN_RB5_MOVE_EXTRA_1;
    QPushButton *BTN_RB5_SAVE_EXTRA_1;
    QPushButton *BTN_RB5_MOVE_EXTRA_2;
    QPushButton *BTN_RB5_SAVE_EXTRA_2;
    QPushButton *BTN_RB5_PASUE;
    QPushButton *BTN_RB5_RESUME;
    QPushButton *BTN_RB5_HOLT;
    QSpinBox *SB_RB5_SPEED;
    QLabel *label_41;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLineEdit *LE_JOINT_1;
    QLabel *label_11;
    QLineEdit *LE_JOINT_4;
    QLabel *label_9;
    QLineEdit *LE_JOINT_2;
    QLabel *label_12;
    QLineEdit *LE_JOINT_5;
    QLabel *label_10;
    QLineEdit *LE_JOINT_3;
    QLabel *label_13;
    QLineEdit *LE_JOINT_6;
    QLabel *label_15;
    QLineEdit *LE_RB5_X;
    QLabel *label_16;
    QLineEdit *LE_RB5_RX;
    QLabel *label_17;
    QLineEdit *LE_RB5_Y;
    QLabel *label_18;
    QLineEdit *LE_RB5_RY;
    QLabel *label_19;
    QLineEdit *LE_RB5_Z;
    QLabel *label_14;
    QLineEdit *LE_RB5_RZ;
    QLabel *LB_RAINBOW_LOGO_4;
    QWidget *tab_4;
    QGroupBox *GR_KITECH;
    QLineEdit *LE_GRIPPER_CMD;
    QPushButton *BTN_GRIPPER_CMD_WRITE;
    QPushButton *BTN_GRIPPER_UNFOLD;
    QPushButton *BTN_GRIPPER_GRAP;
    QPushButton *BTN_GRIPPER_VISION;
    QComboBox *CB_GRIPPER_GRAPS;
    QComboBox *CB_GRIPPER_POWER;
    QComboBox *CB_GRIPPER_GE_MODE;
    QComboBox *CB_GRIPPER_GE_GRAPS;
    QComboBox *CB_GRIPPER_GE_POWER;
    QPushButton *CB_GRIPPER_GE_CMD_WRITE;
    QPushButton *BTN_RB5_CALC_GRAPS_POINT;
    QPushButton *BTN_RB5_MOVE_GRAPS_POINT;
    QLabel *label_58;
    QLabel *label_59;
    QLabel *label_57;
    QLineEdit *LE_GRAPS_POINT_Z;
    QLineEdit *LE_GRAPS_POINT_Y;
    QLineEdit *LE_GRAPS_POINT_X;
    QLineEdit *LE_GRAPS_POINT_Rx;
    QLineEdit *LE_GRAPS_POINT_Rz;
    QLineEdit *LE_GRAPS_POINT_Ry;
    QLabel *label_61;
    QLabel *label_60;
    QLabel *label_62;
    QPushButton *BTN_LOAD_GRAPS_POINT;
    QPushButton *BTN_SET_GRAPS_POINT;
    QGroupBox *GR_KETI;
    QLineEdit *LE_VISION_CMD;
    QPushButton *BTN_VISION_CMD_WRITE;
    QLineEdit *LE_VISION_ESIMATED_COORD;
    QPushButton *BTN_VISION_OUT_SET;
    QPushButton *BTN_VISION_OUT_LOAD;
    QPushButton *BTN_VISION_OUT_SAVE;
    QGroupBox *GB_CALIB_V2N;
    QPushButton *BTN_SET_CALIB_T_V2N;
    QLineEdit *LE_VISION_CALIB_Tx_V2N;
    QLineEdit *LE_VISION_CALIB_Tz_V2N;
    QLineEdit *LE_VISION_CALIB_Ty_V2N;
    QLabel *label_48;
    QLabel *label_49;
    QLabel *label_50;
    QGroupBox *GB_CALIB_V2N_2;
    QPushButton *BTN_SET_CALIB_T_N2E;
    QLineEdit *LE_VISION_CALIB_Tx_N2E;
    QLineEdit *LE_VISION_CALIB_Tz_N2E;
    QLineEdit *LE_VISION_CALIB_Ty_N2E;
    QLabel *label_51;
    QLabel *label_52;
    QLabel *label_53;
    QLabel *label_54;
    QLineEdit *LE_VISION_CALIB_Ry_N2E;
    QLabel *label_55;
    QLineEdit *LE_VISION_CALIB_Rz_N2E;
    QLineEdit *LE_VISION_CALIB_Rx_N2E;
    QLabel *label_56;
    QLabel *LB_RAINBOW_LOGO_5;
    QWidget *tab_5;
    QGroupBox *GR_SENARIO;
    QGroupBox *GR_SENARIO_CUSTOM;
    QLabel *label_47;
    QComboBox *CB_SENARIO_CUSTOM_LIST;
    QPushButton *BTN_SENARIO_CUSTOM_ADD;
    QPushButton *BTN_SENARIO_CUSTOM_DEL;
    QListWidget *LW_SENARIO_CUSTOM_LIST;
    QPushButton *BTN_SENARIO_EXECUTION_CUSTOM;
    QGroupBox *GR_SENARIO_BASIC;
    QLabel *label_44;
    QLabel *label_45;
    QLabel *label_46;
    QComboBox *CB_SENARIO_OBJECT;
    QComboBox *CB_SENARIO_LIFT_LEVEL;
    QComboBox *CB_SENARIO_SHELF_LOCATION;
    QPushButton *BTN_SENARIO_EXECUTION_BASIC;
    QLabel *LB_RAINBOW_LOGO_6;
    QPushButton *BTN_CHECK_SOCKET_STATUS;
    QLineEdit *LE_RB5_INIT;
    QLineEdit *LE_VISION_INIT;
    QPushButton *BTN_CONNECT_GRIPPER;
    QLabel *label_6;
    QPushButton *BTN_CONNECT_VISION;
    QPushButton *BTN_GLOBAL_INIT;
    QLabel *label_2;
    QLineEdit *LE_GRIPPER_INIT;
    QPushButton *BTN_CONNECT_OMRON;
    QPushButton *BTN_CONNECT_LIFT;
    QLineEdit *LE_OMRON_INIT;
    QLineEdit *LE_LIFT_INIT;
    QPushButton *BTN_CONNECT_RB5;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_3;
    QGroupBox *GE_MOVE_INFO;
    QLineEdit *LE_OMRON_MOVE_INFO;
    QLineEdit *LE_LIFT_MOVE_INFO;
    QLineEdit *LE_RB5_MOVE_INFO;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QLineEdit *LE_INFO_MOVE_INFO_1;
    QLineEdit *LE_INFO_MOVE_INFO_2;
    QLabel *label_42;
    QLabel *label_43;
    QGroupBox *GR_GLOBAL_STATUS;
    QLineEdit *LE_IP_KETI;
    QLabel *label_39;
    QLineEdit *LE_IP_KITECH;
    QLabel *label_40;
    QLineEdit *LE_PORT_KETI;
    QLineEdit *LE_PORT_KITECH;
    QPushButton *BTN_SET_IP_PORT_KETI;
    QPushButton *BTN_SET_IP_PORT_KITECH;
    QLabel *label;
    QTextEdit *TE_GLOBAL_LOG;
    QGroupBox *groupBox;
    QMyLabel *LB_OMRON_MAP;
    QLabel *LB_KETI_FRAME;
    QLabel *label_26;
    QPushButton *BTN_TE_GLOBAL_CLEAR;
    QLabel *label_27;
    QGroupBox *GR_GLOBAL_STATUS_2;
    QLabel *LB_Shelves_2;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_3;
    QPushButton *BTN_SH_14;
    QPushButton *BTN_SH_13;
    QPushButton *BTN_SH_11;
    QPushButton *BTN_SH_12;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_4;
    QPushButton *BTN_SH_42;
    QPushButton *BTN_SH_44;
    QPushButton *BTN_SH_41;
    QPushButton *BTN_SH_43;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QPushButton *BTN_SH_24;
    QPushButton *BTN_SH_34;
    QPushButton *BTN_SH_23;
    QPushButton *BTN_SH_33;
    QPushButton *BTN_SH_22;
    QPushButton *BTN_SH_32;
    QPushButton *BTN_SH_21;
    QPushButton *BTN_SH_31;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1881, 1087);
        actionIP_Port_change = new QAction(MainWindow);
        actionIP_Port_change->setObjectName(QString::fromUtf8("actionIP_Port_change"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(1090, 10, 661, 991));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        LB_RAINBOW_LOGO_2 = new QLabel(tab_2);
        LB_RAINBOW_LOGO_2->setObjectName(QString::fromUtf8("LB_RAINBOW_LOGO_2"));
        LB_RAINBOW_LOGO_2->setGeometry(QRect(400, 810, 241, 91));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LB_RAINBOW_LOGO_2->sizePolicy().hasHeightForWidth());
        LB_RAINBOW_LOGO_2->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(8);
        LB_RAINBOW_LOGO_2->setFont(font);
        LB_RAINBOW_LOGO_2->setStyleSheet(QString::fromUtf8("background-color:rgb(31,34,41)"));
        LB_RAINBOW_LOGO_2->setPixmap(QPixmap(QString::fromUtf8(":/icon/icon/background2.jpg")));
        LB_RAINBOW_LOGO_2->setScaledContents(false);
        LB_RAINBOW_LOGO_2->setAlignment(Qt::AlignCenter);
        lable_get_info_2 = new QLabel(tab_2);
        lable_get_info_2->setObjectName(QString::fromUtf8("lable_get_info_2"));
        lable_get_info_2->setGeometry(QRect(49, 160, 131, 17));
        frame_robot_info = new QFrame(tab_2);
        frame_robot_info->setObjectName(QString::fromUtf8("frame_robot_info"));
        frame_robot_info->setGeometry(QRect(50, 180, 231, 251));
        frame_robot_info->setFrameShape(QFrame::StyledPanel);
        frame_robot_info->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_robot_info);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_status = new QLabel(frame_robot_info);
        label_status->setObjectName(QString::fromUtf8("label_status"));

        gridLayout_5->addWidget(label_status, 0, 0, 1, 1);

        te_status = new QTextEdit(frame_robot_info);
        te_status->setObjectName(QString::fromUtf8("te_status"));
        te_status->setReadOnly(true);

        gridLayout_5->addWidget(te_status, 0, 1, 1, 1);

        label_battery = new QLabel(frame_robot_info);
        label_battery->setObjectName(QString::fromUtf8("label_battery"));

        gridLayout_5->addWidget(label_battery, 1, 0, 1, 1);

        le_battery = new QLineEdit(frame_robot_info);
        le_battery->setObjectName(QString::fromUtf8("le_battery"));
        le_battery->setReadOnly(true);

        gridLayout_5->addWidget(le_battery, 1, 1, 1, 1);

        label_location = new QLabel(frame_robot_info);
        label_location->setObjectName(QString::fromUtf8("label_location"));

        gridLayout_5->addWidget(label_location, 2, 0, 1, 1);

        le_location = new QLineEdit(frame_robot_info);
        le_location->setObjectName(QString::fromUtf8("le_location"));
        le_location->setReadOnly(true);

        gridLayout_5->addWidget(le_location, 2, 1, 1, 1);

        label_temperature = new QLabel(frame_robot_info);
        label_temperature->setObjectName(QString::fromUtf8("label_temperature"));

        gridLayout_5->addWidget(label_temperature, 3, 0, 1, 1);

        le_temperature = new QLineEdit(frame_robot_info);
        le_temperature->setObjectName(QString::fromUtf8("le_temperature"));
        le_temperature->setReadOnly(true);

        gridLayout_5->addWidget(le_temperature, 3, 1, 1, 1);

        layoutWidget = new QWidget(tab_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 50, 581, 89));
        gridLayout_6 = new QGridLayout(layoutWidget);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(layoutWidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setWeight(50);
        label_23->setFont(font1);

        gridLayout_6->addWidget(label_23, 0, 0, 1, 1);

        LE_OMRON_X = new QLineEdit(layoutWidget);
        LE_OMRON_X->setObjectName(QString::fromUtf8("LE_OMRON_X"));

        gridLayout_6->addWidget(LE_OMRON_X, 0, 1, 1, 1);

        BTN_OMRON_ADD = new QPushButton(layoutWidget);
        BTN_OMRON_ADD->setObjectName(QString::fromUtf8("BTN_OMRON_ADD"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Liberation Sans"));
        font2.setPointSize(8);
        BTN_OMRON_ADD->setFont(font2);

        gridLayout_6->addWidget(BTN_OMRON_ADD, 0, 2, 2, 1);

        BTN_OMRON_SAVE_GOAL_1 = new QPushButton(layoutWidget);
        BTN_OMRON_SAVE_GOAL_1->setObjectName(QString::fromUtf8("BTN_OMRON_SAVE_GOAL_1"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(7);
        font3.setBold(false);
        font3.setWeight(50);
        BTN_OMRON_SAVE_GOAL_1->setFont(font3);

        gridLayout_6->addWidget(BTN_OMRON_SAVE_GOAL_1, 0, 3, 2, 1);

        label_20 = new QLabel(layoutWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font1);

        gridLayout_6->addWidget(label_20, 0, 4, 1, 1);

        LE_OMRON_BATTERY = new QLineEdit(layoutWidget);
        LE_OMRON_BATTERY->setObjectName(QString::fromUtf8("LE_OMRON_BATTERY"));
        LE_OMRON_BATTERY->setReadOnly(true);

        gridLayout_6->addWidget(LE_OMRON_BATTERY, 0, 5, 1, 1);

        label_24 = new QLabel(layoutWidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setFont(font1);

        gridLayout_6->addWidget(label_24, 1, 0, 2, 1);

        LE_OMRON_Y = new QLineEdit(layoutWidget);
        LE_OMRON_Y->setObjectName(QString::fromUtf8("LE_OMRON_Y"));

        gridLayout_6->addWidget(LE_OMRON_Y, 1, 1, 2, 1);

        label_21 = new QLabel(layoutWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font1);

        gridLayout_6->addWidget(label_21, 1, 4, 2, 1);

        LE_OMRON_LOCATION = new QLineEdit(layoutWidget);
        LE_OMRON_LOCATION->setObjectName(QString::fromUtf8("LE_OMRON_LOCATION"));
        LE_OMRON_LOCATION->setReadOnly(true);

        gridLayout_6->addWidget(LE_OMRON_LOCATION, 1, 5, 2, 1);

        BTN_OMRON_SAVE_ST = new QPushButton(layoutWidget);
        BTN_OMRON_SAVE_ST->setObjectName(QString::fromUtf8("BTN_OMRON_SAVE_ST"));
        BTN_OMRON_SAVE_ST->setFont(font3);

        gridLayout_6->addWidget(BTN_OMRON_SAVE_ST, 2, 2, 2, 1);

        BTN_OMRON_SAVE_GOAL_2 = new QPushButton(layoutWidget);
        BTN_OMRON_SAVE_GOAL_2->setObjectName(QString::fromUtf8("BTN_OMRON_SAVE_GOAL_2"));
        BTN_OMRON_SAVE_GOAL_2->setFont(font3);

        gridLayout_6->addWidget(BTN_OMRON_SAVE_GOAL_2, 2, 3, 2, 1);

        label_25 = new QLabel(layoutWidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(9);
        font4.setBold(false);
        font4.setWeight(50);
        label_25->setFont(font4);

        gridLayout_6->addWidget(label_25, 3, 0, 1, 1);

        LE_OMRON_HEADING = new QLineEdit(layoutWidget);
        LE_OMRON_HEADING->setObjectName(QString::fromUtf8("LE_OMRON_HEADING"));

        gridLayout_6->addWidget(LE_OMRON_HEADING, 3, 1, 1, 1);

        label_22 = new QLabel(layoutWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font1);

        gridLayout_6->addWidget(label_22, 3, 4, 1, 1);

        LE_OMRON_TEMP = new QLineEdit(layoutWidget);
        LE_OMRON_TEMP->setObjectName(QString::fromUtf8("LE_OMRON_TEMP"));
        LE_OMRON_TEMP->setReadOnly(true);

        gridLayout_6->addWidget(LE_OMRON_TEMP, 3, 5, 1, 1);

        layoutWidget_2 = new QWidget(tab_2);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(290, 180, 351, 51));
        gridLayout_7 = new QGridLayout(layoutWidget_2);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        le_say = new QLineEdit(layoutWidget_2);
        le_say->setObjectName(QString::fromUtf8("le_say"));

        gridLayout_7->addWidget(le_say, 0, 0, 1, 1);

        btn_say = new QPushButton(layoutWidget_2);
        btn_say->setObjectName(QString::fromUtf8("btn_say"));

        gridLayout_7->addWidget(btn_say, 0, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        GR_LIFT = new QGroupBox(tab_6);
        GR_LIFT->setObjectName(QString::fromUtf8("GR_LIFT"));
        GR_LIFT->setGeometry(QRect(10, 30, 641, 281));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Arial"));
        GR_LIFT->setFont(font5);
        GR_LIFT->setStyleSheet(QString::fromUtf8(""));
        LE_LIFT_REF = new QLineEdit(GR_LIFT);
        LE_LIFT_REF->setObjectName(QString::fromUtf8("LE_LIFT_REF"));
        LE_LIFT_REF->setGeometry(QRect(40, 70, 91, 20));
        LE_LIFT_REF->setReadOnly(true);
        LE_LIFT_ENCODER = new QLineEdit(GR_LIFT);
        LE_LIFT_ENCODER->setObjectName(QString::fromUtf8("LE_LIFT_ENCODER"));
        LE_LIFT_ENCODER->setGeometry(QRect(40, 100, 91, 20));
        LE_LIFT_ENCODER->setReadOnly(true);
        LE_LIFT_GOAL = new QLineEdit(GR_LIFT);
        LE_LIFT_GOAL->setObjectName(QString::fromUtf8("LE_LIFT_GOAL"));
        LE_LIFT_GOAL->setGeometry(QRect(40, 130, 91, 20));
        label_29 = new QLabel(GR_LIFT);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(10, 70, 31, 20));
        label_29->setFont(font1);
        label_30 = new QLabel(GR_LIFT);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(10, 100, 31, 20));
        label_30->setFont(font1);
        label_31 = new QLabel(GR_LIFT);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(10, 130, 31, 20));
        label_31->setFont(font1);
        BTN_LIFT_LOAD_TOP = new QPushButton(GR_LIFT);
        BTN_LIFT_LOAD_TOP->setObjectName(QString::fromUtf8("BTN_LIFT_LOAD_TOP"));
        BTN_LIFT_LOAD_TOP->setGeometry(QRect(236, 70, 51, 21));
        BTN_LIFT_LOAD_TOP->setFont(font);
        BTN_LIFT_SAVE_TOP = new QPushButton(GR_LIFT);
        BTN_LIFT_SAVE_TOP->setObjectName(QString::fromUtf8("BTN_LIFT_SAVE_TOP"));
        BTN_LIFT_SAVE_TOP->setGeometry(QRect(210, 90, 51, 21));
        BTN_LIFT_SAVE_TOP->setFont(font);
        BTN_LIFT_SET_TOP = new QPushButton(GR_LIFT);
        BTN_LIFT_SET_TOP->setObjectName(QString::fromUtf8("BTN_LIFT_SET_TOP"));
        BTN_LIFT_SET_TOP->setGeometry(QRect(186, 70, 51, 21));
        BTN_LIFT_SET_TOP->setFont(font);
        LE_LIFT_TOP = new QLineEdit(GR_LIFT);
        LE_LIFT_TOP->setObjectName(QString::fromUtf8("LE_LIFT_TOP"));
        LE_LIFT_TOP->setGeometry(QRect(200, 40, 71, 20));
        BTN_LIFT_SAVE_MIDDLE = new QPushButton(GR_LIFT);
        BTN_LIFT_SAVE_MIDDLE->setObjectName(QString::fromUtf8("BTN_LIFT_SAVE_MIDDLE"));
        BTN_LIFT_SAVE_MIDDLE->setGeometry(QRect(360, 90, 51, 21));
        BTN_LIFT_SAVE_MIDDLE->setFont(font);
        BTN_LIFT_SET_MIDDLE = new QPushButton(GR_LIFT);
        BTN_LIFT_SET_MIDDLE->setObjectName(QString::fromUtf8("BTN_LIFT_SET_MIDDLE"));
        BTN_LIFT_SET_MIDDLE->setGeometry(QRect(336, 70, 51, 21));
        BTN_LIFT_SET_MIDDLE->setFont(font);
        LE_LIFT_MIDDLE = new QLineEdit(GR_LIFT);
        LE_LIFT_MIDDLE->setObjectName(QString::fromUtf8("LE_LIFT_MIDDLE"));
        LE_LIFT_MIDDLE->setGeometry(QRect(350, 40, 71, 20));
        BTN_LIFT_LOAD_MIDDLE = new QPushButton(GR_LIFT);
        BTN_LIFT_LOAD_MIDDLE->setObjectName(QString::fromUtf8("BTN_LIFT_LOAD_MIDDLE"));
        BTN_LIFT_LOAD_MIDDLE->setGeometry(QRect(386, 70, 51, 21));
        BTN_LIFT_LOAD_MIDDLE->setFont(font);
        BTN_LIFT_SAVE_BOTTOM = new QPushButton(GR_LIFT);
        BTN_LIFT_SAVE_BOTTOM->setObjectName(QString::fromUtf8("BTN_LIFT_SAVE_BOTTOM"));
        BTN_LIFT_SAVE_BOTTOM->setGeometry(QRect(510, 90, 51, 21));
        BTN_LIFT_SAVE_BOTTOM->setFont(font);
        BTN_LIFT_SET_BOTTOM = new QPushButton(GR_LIFT);
        BTN_LIFT_SET_BOTTOM->setObjectName(QString::fromUtf8("BTN_LIFT_SET_BOTTOM"));
        BTN_LIFT_SET_BOTTOM->setGeometry(QRect(486, 70, 51, 21));
        BTN_LIFT_SET_BOTTOM->setFont(font);
        LE_LIFT_BOTTOM = new QLineEdit(GR_LIFT);
        LE_LIFT_BOTTOM->setObjectName(QString::fromUtf8("LE_LIFT_BOTTOM"));
        LE_LIFT_BOTTOM->setGeometry(QRect(500, 40, 71, 20));
        BTN_LIFT_LOAD_BOTTOM = new QPushButton(GR_LIFT);
        BTN_LIFT_LOAD_BOTTOM->setObjectName(QString::fromUtf8("BTN_LIFT_LOAD_BOTTOM"));
        BTN_LIFT_LOAD_BOTTOM->setGeometry(QRect(536, 70, 51, 21));
        BTN_LIFT_LOAD_BOTTOM->setFont(font);
        label_32 = new QLabel(GR_LIFT);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(160, 40, 31, 20));
        label_32->setFont(font1);
        label_33 = new QLabel(GR_LIFT);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(310, 40, 31, 20));
        label_33->setFont(font1);
        label_34 = new QLabel(GR_LIFT);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(460, 40, 31, 20));
        label_34->setFont(font1);
        CB_SERIAL_PORT = new QComboBox(GR_LIFT);
        CB_SERIAL_PORT->setObjectName(QString::fromUtf8("CB_SERIAL_PORT"));
        CB_SERIAL_PORT->setGeometry(QRect(10, 40, 86, 25));
        BTN_LIFT_SERIAL_OPEN = new QPushButton(GR_LIFT);
        BTN_LIFT_SERIAL_OPEN->setObjectName(QString::fromUtf8("BTN_LIFT_SERIAL_OPEN"));
        BTN_LIFT_SERIAL_OPEN->setGeometry(QRect(100, 40, 41, 25));
        BTN_LIFT_SERIAL_OPEN->setFont(font2);
        BTN_LIFT_HOMING = new QPushButton(GR_LIFT);
        BTN_LIFT_HOMING->setObjectName(QString::fromUtf8("BTN_LIFT_HOMING"));
        BTN_LIFT_HOMING->setGeometry(QRect(10, 170, 131, 81));
        BTN_LIFT_REQ_DATA = new QPushButton(GR_LIFT);
        BTN_LIFT_REQ_DATA->setObjectName(QString::fromUtf8("BTN_LIFT_REQ_DATA"));
        BTN_LIFT_REQ_DATA->setGeometry(QRect(150, 170, 131, 81));
        LB_RAINBOW_LOGO_3 = new QLabel(tab_6);
        LB_RAINBOW_LOGO_3->setObjectName(QString::fromUtf8("LB_RAINBOW_LOGO_3"));
        LB_RAINBOW_LOGO_3->setGeometry(QRect(400, 810, 241, 91));
        sizePolicy.setHeightForWidth(LB_RAINBOW_LOGO_3->sizePolicy().hasHeightForWidth());
        LB_RAINBOW_LOGO_3->setSizePolicy(sizePolicy);
        LB_RAINBOW_LOGO_3->setFont(font);
        LB_RAINBOW_LOGO_3->setStyleSheet(QString::fromUtf8("background-color:rgb(31,34,41)"));
        LB_RAINBOW_LOGO_3->setPixmap(QPixmap(QString::fromUtf8(":/icon/icon/background2.jpg")));
        LB_RAINBOW_LOGO_3->setScaledContents(false);
        LB_RAINBOW_LOGO_3->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_6, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        GR_RB5 = new QGroupBox(tab_3);
        GR_RB5->setObjectName(QString::fromUtf8("GR_RB5"));
        GR_RB5->setGeometry(QRect(10, 10, 631, 421));
        GR_RB5->setFont(font5);
        GR_RB5->setStyleSheet(QString::fromUtf8(";"));
        BTN_RB5_MOVE_VISION = new QPushButton(GR_RB5);
        BTN_RB5_MOVE_VISION->setObjectName(QString::fromUtf8("BTN_RB5_MOVE_VISION"));
        BTN_RB5_MOVE_VISION->setGeometry(QRect(290, 110, 71, 41));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Arial"));
        font6.setPointSize(7);
        BTN_RB5_MOVE_VISION->setFont(font6);
        BTN_RB5_MOVE_GRIPPER_READY = new QPushButton(GR_RB5);
        BTN_RB5_MOVE_GRIPPER_READY->setObjectName(QString::fromUtf8("BTN_RB5_MOVE_GRIPPER_READY"));
        BTN_RB5_MOVE_GRIPPER_READY->setGeometry(QRect(290, 170, 71, 41));
        BTN_RB5_MOVE_GRIPPER_READY->setFont(font6);
        BTN_RB5_MOVE_GRIPPER_GRAPS = new QPushButton(GR_RB5);
        BTN_RB5_MOVE_GRIPPER_GRAPS->setObjectName(QString::fromUtf8("BTN_RB5_MOVE_GRIPPER_GRAPS"));
        BTN_RB5_MOVE_GRIPPER_GRAPS->setGeometry(QRect(290, 230, 71, 41));
        BTN_RB5_MOVE_GRIPPER_GRAPS->setFont(font6);
        BTN_RB5_MOVE_INIT = new QPushButton(GR_RB5);
        BTN_RB5_MOVE_INIT->setObjectName(QString::fromUtf8("BTN_RB5_MOVE_INIT"));
        BTN_RB5_MOVE_INIT->setGeometry(QRect(290, 50, 71, 41));
        BTN_RB5_MOVE_INIT->setFont(font6);
        BTN_RB5_SAVE_GRIPPER_GRAPS = new QPushButton(GR_RB5);
        BTN_RB5_SAVE_GRIPPER_GRAPS->setObjectName(QString::fromUtf8("BTN_RB5_SAVE_GRIPPER_GRAPS"));
        BTN_RB5_SAVE_GRIPPER_GRAPS->setGeometry(QRect(400, 230, 71, 41));
        BTN_RB5_SAVE_GRIPPER_GRAPS->setFont(font6);
        BTN_RB5_SAVE_GRIPPER_READY = new QPushButton(GR_RB5);
        BTN_RB5_SAVE_GRIPPER_READY->setObjectName(QString::fromUtf8("BTN_RB5_SAVE_GRIPPER_READY"));
        BTN_RB5_SAVE_GRIPPER_READY->setGeometry(QRect(400, 170, 71, 41));
        BTN_RB5_SAVE_GRIPPER_READY->setFont(font6);
        BTN_RB5_SAVE_INIT = new QPushButton(GR_RB5);
        BTN_RB5_SAVE_INIT->setObjectName(QString::fromUtf8("BTN_RB5_SAVE_INIT"));
        BTN_RB5_SAVE_INIT->setGeometry(QRect(400, 50, 71, 41));
        BTN_RB5_SAVE_INIT->setFont(font6);
        BTN_RB5_SAVE_VISION = new QPushButton(GR_RB5);
        BTN_RB5_SAVE_VISION->setObjectName(QString::fromUtf8("BTN_RB5_SAVE_VISION"));
        BTN_RB5_SAVE_VISION->setGeometry(QRect(400, 110, 71, 41));
        BTN_RB5_SAVE_VISION->setFont(font6);
        BTN_RB5_MODE = new QPushButton(GR_RB5);
        BTN_RB5_MODE->setObjectName(QString::fromUtf8("BTN_RB5_MODE"));
        BTN_RB5_MODE->setGeometry(QRect(50, 360, 71, 31));
        BTN_RB5_MODE->setFont(font);
        SLIDER_RB5_SPEED = new QSlider(GR_RB5);
        SLIDER_RB5_SPEED->setObjectName(QString::fromUtf8("SLIDER_RB5_SPEED"));
        SLIDER_RB5_SPEED->setGeometry(QRect(30, 310, 151, 16));
        SLIDER_RB5_SPEED->setMaximum(100);
        SLIDER_RB5_SPEED->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(GR_RB5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 330, 31, 16));
        label_7->setFont(font);
        BTN_RB5_MOVE_EXTRA_1 = new QPushButton(GR_RB5);
        BTN_RB5_MOVE_EXTRA_1->setObjectName(QString::fromUtf8("BTN_RB5_MOVE_EXTRA_1"));
        BTN_RB5_MOVE_EXTRA_1->setGeometry(QRect(290, 290, 71, 41));
        BTN_RB5_MOVE_EXTRA_1->setFont(font6);
        BTN_RB5_SAVE_EXTRA_1 = new QPushButton(GR_RB5);
        BTN_RB5_SAVE_EXTRA_1->setObjectName(QString::fromUtf8("BTN_RB5_SAVE_EXTRA_1"));
        BTN_RB5_SAVE_EXTRA_1->setGeometry(QRect(400, 290, 71, 41));
        BTN_RB5_SAVE_EXTRA_1->setFont(font6);
        BTN_RB5_MOVE_EXTRA_2 = new QPushButton(GR_RB5);
        BTN_RB5_MOVE_EXTRA_2->setObjectName(QString::fromUtf8("BTN_RB5_MOVE_EXTRA_2"));
        BTN_RB5_MOVE_EXTRA_2->setGeometry(QRect(290, 350, 71, 41));
        BTN_RB5_MOVE_EXTRA_2->setFont(font6);
        BTN_RB5_SAVE_EXTRA_2 = new QPushButton(GR_RB5);
        BTN_RB5_SAVE_EXTRA_2->setObjectName(QString::fromUtf8("BTN_RB5_SAVE_EXTRA_2"));
        BTN_RB5_SAVE_EXTRA_2->setGeometry(QRect(400, 350, 71, 41));
        BTN_RB5_SAVE_EXTRA_2->setFont(font6);
        BTN_RB5_PASUE = new QPushButton(GR_RB5);
        BTN_RB5_PASUE->setObjectName(QString::fromUtf8("BTN_RB5_PASUE"));
        BTN_RB5_PASUE->setGeometry(QRect(500, 40, 111, 91));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Arial"));
        font7.setPointSize(9);
        font7.setBold(true);
        font7.setWeight(75);
        BTN_RB5_PASUE->setFont(font7);
        BTN_RB5_PASUE->setStyleSheet(QString::fromUtf8("background-color: rgb(252, 233, 79);"));
        BTN_RB5_RESUME = new QPushButton(GR_RB5);
        BTN_RB5_RESUME->setObjectName(QString::fromUtf8("BTN_RB5_RESUME"));
        BTN_RB5_RESUME->setGeometry(QRect(500, 170, 111, 91));
        BTN_RB5_RESUME->setFont(font7);
        BTN_RB5_RESUME->setStyleSheet(QString::fromUtf8("background-color: rgb(138, 226, 52);"));
        BTN_RB5_HOLT = new QPushButton(GR_RB5);
        BTN_RB5_HOLT->setObjectName(QString::fromUtf8("BTN_RB5_HOLT"));
        BTN_RB5_HOLT->setGeometry(QRect(500, 300, 111, 91));
        BTN_RB5_HOLT->setFont(font7);
        BTN_RB5_HOLT->setStyleSheet(QString::fromUtf8("background-color:red"));
        SB_RB5_SPEED = new QSpinBox(GR_RB5);
        SB_RB5_SPEED->setObjectName(QString::fromUtf8("SB_RB5_SPEED"));
        SB_RB5_SPEED->setGeometry(QRect(190, 340, 71, 51));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Arial"));
        font8.setPointSize(14);
        font8.setBold(true);
        font8.setWeight(75);
        SB_RB5_SPEED->setFont(font8);
        SB_RB5_SPEED->setMaximum(100);
        label_41 = new QLabel(GR_RB5);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(70, 330, 31, 16));
        label_41->setFont(font);
        label_41->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,0)"));
        layoutWidget1 = new QWidget(GR_RB5);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 41, 241, 261));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        LE_JOINT_1 = new QLineEdit(layoutWidget1);
        LE_JOINT_1->setObjectName(QString::fromUtf8("LE_JOINT_1"));
        LE_JOINT_1->setStyleSheet(QString::fromUtf8("background-color:white"));
        LE_JOINT_1->setReadOnly(true);

        gridLayout->addWidget(LE_JOINT_1, 0, 1, 1, 1);

        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        gridLayout->addWidget(label_11, 0, 2, 1, 1);

        LE_JOINT_4 = new QLineEdit(layoutWidget1);
        LE_JOINT_4->setObjectName(QString::fromUtf8("LE_JOINT_4"));
        LE_JOINT_4->setStyleSheet(QString::fromUtf8("background-color:white"));
        LE_JOINT_4->setReadOnly(true);

        gridLayout->addWidget(LE_JOINT_4, 0, 3, 1, 1);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        gridLayout->addWidget(label_9, 1, 0, 1, 1);

        LE_JOINT_2 = new QLineEdit(layoutWidget1);
        LE_JOINT_2->setObjectName(QString::fromUtf8("LE_JOINT_2"));
        LE_JOINT_2->setStyleSheet(QString::fromUtf8("background-color:white"));
        LE_JOINT_2->setReadOnly(true);

        gridLayout->addWidget(LE_JOINT_2, 1, 1, 1, 1);

        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        gridLayout->addWidget(label_12, 1, 2, 1, 1);

        LE_JOINT_5 = new QLineEdit(layoutWidget1);
        LE_JOINT_5->setObjectName(QString::fromUtf8("LE_JOINT_5"));
        LE_JOINT_5->setStyleSheet(QString::fromUtf8("background-color:white"));
        LE_JOINT_5->setReadOnly(true);

        gridLayout->addWidget(LE_JOINT_5, 1, 3, 1, 1);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        gridLayout->addWidget(label_10, 2, 0, 1, 1);

        LE_JOINT_3 = new QLineEdit(layoutWidget1);
        LE_JOINT_3->setObjectName(QString::fromUtf8("LE_JOINT_3"));
        LE_JOINT_3->setStyleSheet(QString::fromUtf8("background-color:white"));
        LE_JOINT_3->setReadOnly(true);

        gridLayout->addWidget(LE_JOINT_3, 2, 1, 1, 1);

        label_13 = new QLabel(layoutWidget1);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);

        gridLayout->addWidget(label_13, 2, 2, 1, 1);

        LE_JOINT_6 = new QLineEdit(layoutWidget1);
        LE_JOINT_6->setObjectName(QString::fromUtf8("LE_JOINT_6"));
        LE_JOINT_6->setStyleSheet(QString::fromUtf8("background-color:white"));
        LE_JOINT_6->setReadOnly(true);

        gridLayout->addWidget(LE_JOINT_6, 2, 3, 1, 1);

        label_15 = new QLabel(layoutWidget1);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);

        gridLayout->addWidget(label_15, 3, 0, 1, 1);

        LE_RB5_X = new QLineEdit(layoutWidget1);
        LE_RB5_X->setObjectName(QString::fromUtf8("LE_RB5_X"));
        LE_RB5_X->setStyleSheet(QString::fromUtf8("background-color:white"));
        LE_RB5_X->setReadOnly(true);

        gridLayout->addWidget(LE_RB5_X, 3, 1, 1, 1);

        label_16 = new QLabel(layoutWidget1);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font);

        gridLayout->addWidget(label_16, 3, 2, 1, 1);

        LE_RB5_RX = new QLineEdit(layoutWidget1);
        LE_RB5_RX->setObjectName(QString::fromUtf8("LE_RB5_RX"));
        LE_RB5_RX->setStyleSheet(QString::fromUtf8("background-color:white"));
        LE_RB5_RX->setReadOnly(true);

        gridLayout->addWidget(LE_RB5_RX, 3, 3, 1, 1);

        label_17 = new QLabel(layoutWidget1);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font);

        gridLayout->addWidget(label_17, 4, 0, 1, 1);

        LE_RB5_Y = new QLineEdit(layoutWidget1);
        LE_RB5_Y->setObjectName(QString::fromUtf8("LE_RB5_Y"));
        LE_RB5_Y->setStyleSheet(QString::fromUtf8("background-color:white"));
        LE_RB5_Y->setReadOnly(true);

        gridLayout->addWidget(LE_RB5_Y, 4, 1, 1, 1);

        label_18 = new QLabel(layoutWidget1);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font);

        gridLayout->addWidget(label_18, 4, 2, 1, 1);

        LE_RB5_RY = new QLineEdit(layoutWidget1);
        LE_RB5_RY->setObjectName(QString::fromUtf8("LE_RB5_RY"));
        LE_RB5_RY->setStyleSheet(QString::fromUtf8("background-color:white"));
        LE_RB5_RY->setReadOnly(true);

        gridLayout->addWidget(LE_RB5_RY, 4, 3, 1, 1);

        label_19 = new QLabel(layoutWidget1);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font);

        gridLayout->addWidget(label_19, 5, 0, 1, 1);

        LE_RB5_Z = new QLineEdit(layoutWidget1);
        LE_RB5_Z->setObjectName(QString::fromUtf8("LE_RB5_Z"));
        LE_RB5_Z->setStyleSheet(QString::fromUtf8("background-color:white"));
        LE_RB5_Z->setReadOnly(true);

        gridLayout->addWidget(LE_RB5_Z, 5, 1, 1, 1);

        label_14 = new QLabel(layoutWidget1);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font);

        gridLayout->addWidget(label_14, 5, 2, 1, 1);

        LE_RB5_RZ = new QLineEdit(layoutWidget1);
        LE_RB5_RZ->setObjectName(QString::fromUtf8("LE_RB5_RZ"));
        LE_RB5_RZ->setStyleSheet(QString::fromUtf8("background-color:white"));
        LE_RB5_RZ->setReadOnly(true);

        gridLayout->addWidget(LE_RB5_RZ, 5, 3, 1, 1);

        LB_RAINBOW_LOGO_4 = new QLabel(tab_3);
        LB_RAINBOW_LOGO_4->setObjectName(QString::fromUtf8("LB_RAINBOW_LOGO_4"));
        LB_RAINBOW_LOGO_4->setGeometry(QRect(400, 810, 241, 91));
        sizePolicy.setHeightForWidth(LB_RAINBOW_LOGO_4->sizePolicy().hasHeightForWidth());
        LB_RAINBOW_LOGO_4->setSizePolicy(sizePolicy);
        LB_RAINBOW_LOGO_4->setFont(font);
        LB_RAINBOW_LOGO_4->setStyleSheet(QString::fromUtf8("background-color:rgb(31,34,41)"));
        LB_RAINBOW_LOGO_4->setPixmap(QPixmap(QString::fromUtf8(":/icon/icon/background2.jpg")));
        LB_RAINBOW_LOGO_4->setScaledContents(false);
        LB_RAINBOW_LOGO_4->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        GR_KITECH = new QGroupBox(tab_4);
        GR_KITECH->setObjectName(QString::fromUtf8("GR_KITECH"));
        GR_KITECH->setGeometry(QRect(20, 450, 301, 331));
        GR_KITECH->setFont(font5);
        GR_KITECH->setStyleSheet(QString::fromUtf8(""));
        LE_GRIPPER_CMD = new QLineEdit(GR_KITECH);
        LE_GRIPPER_CMD->setObjectName(QString::fromUtf8("LE_GRIPPER_CMD"));
        LE_GRIPPER_CMD->setGeometry(QRect(10, 30, 221, 20));
        BTN_GRIPPER_CMD_WRITE = new QPushButton(GR_KITECH);
        BTN_GRIPPER_CMD_WRITE->setObjectName(QString::fromUtf8("BTN_GRIPPER_CMD_WRITE"));
        BTN_GRIPPER_CMD_WRITE->setGeometry(QRect(240, 30, 51, 21));
        BTN_GRIPPER_CMD_WRITE->setFont(font);
        BTN_GRIPPER_UNFOLD = new QPushButton(GR_KITECH);
        BTN_GRIPPER_UNFOLD->setObjectName(QString::fromUtf8("BTN_GRIPPER_UNFOLD"));
        BTN_GRIPPER_UNFOLD->setGeometry(QRect(20, 60, 90, 30));
        QFont font9;
        font9.setFamily(QString::fromUtf8("Arial"));
        font9.setBold(true);
        font9.setWeight(75);
        BTN_GRIPPER_UNFOLD->setFont(font9);
        BTN_GRIPPER_GRAP = new QPushButton(GR_KITECH);
        BTN_GRIPPER_GRAP->setObjectName(QString::fromUtf8("BTN_GRIPPER_GRAP"));
        BTN_GRIPPER_GRAP->setGeometry(QRect(20, 100, 90, 30));
        BTN_GRIPPER_GRAP->setFont(font9);
        BTN_GRIPPER_VISION = new QPushButton(GR_KITECH);
        BTN_GRIPPER_VISION->setObjectName(QString::fromUtf8("BTN_GRIPPER_VISION"));
        BTN_GRIPPER_VISION->setGeometry(QRect(20, 140, 90, 30));
        BTN_GRIPPER_VISION->setFont(font9);
        CB_GRIPPER_GRAPS = new QComboBox(GR_KITECH);
        CB_GRIPPER_GRAPS->addItem(QString());
        CB_GRIPPER_GRAPS->addItem(QString());
        CB_GRIPPER_GRAPS->addItem(QString());
        CB_GRIPPER_GRAPS->addItem(QString());
        CB_GRIPPER_GRAPS->addItem(QString());
        CB_GRIPPER_GRAPS->addItem(QString());
        CB_GRIPPER_GRAPS->setObjectName(QString::fromUtf8("CB_GRIPPER_GRAPS"));
        CB_GRIPPER_GRAPS->setGeometry(QRect(120, 100, 51, 25));
        CB_GRIPPER_POWER = new QComboBox(GR_KITECH);
        CB_GRIPPER_POWER->addItem(QString());
        CB_GRIPPER_POWER->addItem(QString());
        CB_GRIPPER_POWER->addItem(QString());
        CB_GRIPPER_POWER->addItem(QString());
        CB_GRIPPER_POWER->addItem(QString());
        CB_GRIPPER_POWER->addItem(QString());
        CB_GRIPPER_POWER->addItem(QString());
        CB_GRIPPER_POWER->addItem(QString());
        CB_GRIPPER_POWER->addItem(QString());
        CB_GRIPPER_POWER->addItem(QString());
        CB_GRIPPER_POWER->setObjectName(QString::fromUtf8("CB_GRIPPER_POWER"));
        CB_GRIPPER_POWER->setGeometry(QRect(120, 130, 51, 25));
        CB_GRIPPER_GE_MODE = new QComboBox(GR_KITECH);
        CB_GRIPPER_GE_MODE->addItem(QString());
        CB_GRIPPER_GE_MODE->addItem(QString());
        CB_GRIPPER_GE_MODE->setObjectName(QString::fromUtf8("CB_GRIPPER_GE_MODE"));
        CB_GRIPPER_GE_MODE->setGeometry(QRect(210, 60, 60, 20));
        CB_GRIPPER_GE_GRAPS = new QComboBox(GR_KITECH);
        CB_GRIPPER_GE_GRAPS->addItem(QString());
        CB_GRIPPER_GE_GRAPS->addItem(QString());
        CB_GRIPPER_GE_GRAPS->addItem(QString());
        CB_GRIPPER_GE_GRAPS->addItem(QString());
        CB_GRIPPER_GE_GRAPS->addItem(QString());
        CB_GRIPPER_GE_GRAPS->addItem(QString());
        CB_GRIPPER_GE_GRAPS->setObjectName(QString::fromUtf8("CB_GRIPPER_GE_GRAPS"));
        CB_GRIPPER_GE_GRAPS->setGeometry(QRect(210, 90, 60, 20));
        CB_GRIPPER_GE_POWER = new QComboBox(GR_KITECH);
        CB_GRIPPER_GE_POWER->addItem(QString());
        CB_GRIPPER_GE_POWER->addItem(QString());
        CB_GRIPPER_GE_POWER->addItem(QString());
        CB_GRIPPER_GE_POWER->addItem(QString());
        CB_GRIPPER_GE_POWER->addItem(QString());
        CB_GRIPPER_GE_POWER->addItem(QString());
        CB_GRIPPER_GE_POWER->addItem(QString());
        CB_GRIPPER_GE_POWER->addItem(QString());
        CB_GRIPPER_GE_POWER->addItem(QString());
        CB_GRIPPER_GE_POWER->addItem(QString());
        CB_GRIPPER_GE_POWER->setObjectName(QString::fromUtf8("CB_GRIPPER_GE_POWER"));
        CB_GRIPPER_GE_POWER->setGeometry(QRect(210, 120, 60, 20));
        CB_GRIPPER_GE_CMD_WRITE = new QPushButton(GR_KITECH);
        CB_GRIPPER_GE_CMD_WRITE->setObjectName(QString::fromUtf8("CB_GRIPPER_GE_CMD_WRITE"));
        CB_GRIPPER_GE_CMD_WRITE->setGeometry(QRect(220, 150, 51, 21));
        CB_GRIPPER_GE_CMD_WRITE->setFont(font);
        BTN_RB5_CALC_GRAPS_POINT = new QPushButton(GR_KITECH);
        BTN_RB5_CALC_GRAPS_POINT->setObjectName(QString::fromUtf8("BTN_RB5_CALC_GRAPS_POINT"));
        BTN_RB5_CALC_GRAPS_POINT->setGeometry(QRect(190, 190, 89, 51));
        BTN_RB5_CALC_GRAPS_POINT->setFont(font2);
        BTN_RB5_MOVE_GRAPS_POINT = new QPushButton(GR_KITECH);
        BTN_RB5_MOVE_GRAPS_POINT->setObjectName(QString::fromUtf8("BTN_RB5_MOVE_GRAPS_POINT"));
        BTN_RB5_MOVE_GRAPS_POINT->setGeometry(QRect(190, 260, 89, 51));
        BTN_RB5_MOVE_GRAPS_POINT->setFont(font2);
        label_58 = new QLabel(GR_KITECH);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setGeometry(QRect(10, 220, 21, 17));
        label_59 = new QLabel(GR_KITECH);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setGeometry(QRect(10, 250, 21, 17));
        label_57 = new QLabel(GR_KITECH);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setGeometry(QRect(10, 190, 16, 17));
        LE_GRAPS_POINT_Z = new QLineEdit(GR_KITECH);
        LE_GRAPS_POINT_Z->setObjectName(QString::fromUtf8("LE_GRAPS_POINT_Z"));
        LE_GRAPS_POINT_Z->setGeometry(QRect(30, 250, 51, 21));
        QFont font10;
        font10.setFamily(QString::fromUtf8("Liberation Sans"));
        font10.setPointSize(9);
        LE_GRAPS_POINT_Z->setFont(font10);
        LE_GRAPS_POINT_Y = new QLineEdit(GR_KITECH);
        LE_GRAPS_POINT_Y->setObjectName(QString::fromUtf8("LE_GRAPS_POINT_Y"));
        LE_GRAPS_POINT_Y->setGeometry(QRect(30, 220, 51, 20));
        LE_GRAPS_POINT_Y->setFont(font10);
        LE_GRAPS_POINT_X = new QLineEdit(GR_KITECH);
        LE_GRAPS_POINT_X->setObjectName(QString::fromUtf8("LE_GRAPS_POINT_X"));
        LE_GRAPS_POINT_X->setGeometry(QRect(30, 190, 51, 20));
        LE_GRAPS_POINT_X->setFont(font10);
        LE_GRAPS_POINT_Rx = new QLineEdit(GR_KITECH);
        LE_GRAPS_POINT_Rx->setObjectName(QString::fromUtf8("LE_GRAPS_POINT_Rx"));
        LE_GRAPS_POINT_Rx->setGeometry(QRect(130, 190, 51, 20));
        LE_GRAPS_POINT_Rz = new QLineEdit(GR_KITECH);
        LE_GRAPS_POINT_Rz->setObjectName(QString::fromUtf8("LE_GRAPS_POINT_Rz"));
        LE_GRAPS_POINT_Rz->setGeometry(QRect(130, 250, 51, 20));
        LE_GRAPS_POINT_Ry = new QLineEdit(GR_KITECH);
        LE_GRAPS_POINT_Ry->setObjectName(QString::fromUtf8("LE_GRAPS_POINT_Ry"));
        LE_GRAPS_POINT_Ry->setGeometry(QRect(130, 220, 51, 20));
        label_61 = new QLabel(GR_KITECH);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        label_61->setGeometry(QRect(100, 220, 21, 17));
        label_60 = new QLabel(GR_KITECH);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setGeometry(QRect(100, 250, 21, 17));
        label_62 = new QLabel(GR_KITECH);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setGeometry(QRect(100, 190, 21, 17));
        BTN_LOAD_GRAPS_POINT = new QPushButton(GR_KITECH);
        BTN_LOAD_GRAPS_POINT->setObjectName(QString::fromUtf8("BTN_LOAD_GRAPS_POINT"));
        BTN_LOAD_GRAPS_POINT->setGeometry(QRect(130, 280, 51, 25));
        BTN_SET_GRAPS_POINT = new QPushButton(GR_KITECH);
        BTN_SET_GRAPS_POINT->setObjectName(QString::fromUtf8("BTN_SET_GRAPS_POINT"));
        BTN_SET_GRAPS_POINT->setGeometry(QRect(70, 280, 51, 25));
        GR_KETI = new QGroupBox(tab_4);
        GR_KETI->setObjectName(QString::fromUtf8("GR_KETI"));
        GR_KETI->setGeometry(QRect(20, 20, 301, 401));
        GR_KETI->setFont(font5);
        GR_KETI->setStyleSheet(QString::fromUtf8(""));
        LE_VISION_CMD = new QLineEdit(GR_KETI);
        LE_VISION_CMD->setObjectName(QString::fromUtf8("LE_VISION_CMD"));
        LE_VISION_CMD->setGeometry(QRect(10, 340, 221, 20));
        BTN_VISION_CMD_WRITE = new QPushButton(GR_KETI);
        BTN_VISION_CMD_WRITE->setObjectName(QString::fromUtf8("BTN_VISION_CMD_WRITE"));
        BTN_VISION_CMD_WRITE->setGeometry(QRect(240, 340, 51, 21));
        BTN_VISION_CMD_WRITE->setFont(font);
        LE_VISION_ESIMATED_COORD = new QLineEdit(GR_KETI);
        LE_VISION_ESIMATED_COORD->setObjectName(QString::fromUtf8("LE_VISION_ESIMATED_COORD"));
        LE_VISION_ESIMATED_COORD->setGeometry(QRect(10, 370, 101, 20));
        BTN_VISION_OUT_SET = new QPushButton(GR_KETI);
        BTN_VISION_OUT_SET->setObjectName(QString::fromUtf8("BTN_VISION_OUT_SET"));
        BTN_VISION_OUT_SET->setGeometry(QRect(120, 370, 51, 21));
        BTN_VISION_OUT_SET->setFont(font);
        BTN_VISION_OUT_LOAD = new QPushButton(GR_KETI);
        BTN_VISION_OUT_LOAD->setObjectName(QString::fromUtf8("BTN_VISION_OUT_LOAD"));
        BTN_VISION_OUT_LOAD->setGeometry(QRect(180, 370, 51, 21));
        BTN_VISION_OUT_LOAD->setFont(font);
        BTN_VISION_OUT_SAVE = new QPushButton(GR_KETI);
        BTN_VISION_OUT_SAVE->setObjectName(QString::fromUtf8("BTN_VISION_OUT_SAVE"));
        BTN_VISION_OUT_SAVE->setGeometry(QRect(240, 370, 51, 21));
        BTN_VISION_OUT_SAVE->setFont(font);
        GB_CALIB_V2N = new QGroupBox(tab_4);
        GB_CALIB_V2N->setObjectName(QString::fromUtf8("GB_CALIB_V2N"));
        GB_CALIB_V2N->setGeometry(QRect(340, 20, 291, 401));
        BTN_SET_CALIB_T_V2N = new QPushButton(GB_CALIB_V2N);
        BTN_SET_CALIB_T_V2N->setObjectName(QString::fromUtf8("BTN_SET_CALIB_T_V2N"));
        BTN_SET_CALIB_T_V2N->setGeometry(QRect(180, 40, 51, 25));
        LE_VISION_CALIB_Tx_V2N = new QLineEdit(GB_CALIB_V2N);
        LE_VISION_CALIB_Tx_V2N->setObjectName(QString::fromUtf8("LE_VISION_CALIB_Tx_V2N"));
        LE_VISION_CALIB_Tx_V2N->setGeometry(QRect(90, 40, 81, 20));
        LE_VISION_CALIB_Tz_V2N = new QLineEdit(GB_CALIB_V2N);
        LE_VISION_CALIB_Tz_V2N->setObjectName(QString::fromUtf8("LE_VISION_CALIB_Tz_V2N"));
        LE_VISION_CALIB_Tz_V2N->setGeometry(QRect(90, 100, 81, 20));
        LE_VISION_CALIB_Ty_V2N = new QLineEdit(GB_CALIB_V2N);
        LE_VISION_CALIB_Ty_V2N->setObjectName(QString::fromUtf8("LE_VISION_CALIB_Ty_V2N"));
        LE_VISION_CALIB_Ty_V2N->setGeometry(QRect(90, 70, 81, 20));
        label_48 = new QLabel(GB_CALIB_V2N);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(10, 40, 71, 17));
        label_49 = new QLabel(GB_CALIB_V2N);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(10, 70, 71, 17));
        label_50 = new QLabel(GB_CALIB_V2N);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(10, 100, 71, 17));
        GB_CALIB_V2N_2 = new QGroupBox(tab_4);
        GB_CALIB_V2N_2->setObjectName(QString::fromUtf8("GB_CALIB_V2N_2"));
        GB_CALIB_V2N_2->setGeometry(QRect(340, 450, 301, 331));
        BTN_SET_CALIB_T_N2E = new QPushButton(GB_CALIB_V2N_2);
        BTN_SET_CALIB_T_N2E->setObjectName(QString::fromUtf8("BTN_SET_CALIB_T_N2E"));
        BTN_SET_CALIB_T_N2E->setGeometry(QRect(180, 40, 51, 25));
        LE_VISION_CALIB_Tx_N2E = new QLineEdit(GB_CALIB_V2N_2);
        LE_VISION_CALIB_Tx_N2E->setObjectName(QString::fromUtf8("LE_VISION_CALIB_Tx_N2E"));
        LE_VISION_CALIB_Tx_N2E->setGeometry(QRect(90, 40, 81, 20));
        LE_VISION_CALIB_Tz_N2E = new QLineEdit(GB_CALIB_V2N_2);
        LE_VISION_CALIB_Tz_N2E->setObjectName(QString::fromUtf8("LE_VISION_CALIB_Tz_N2E"));
        LE_VISION_CALIB_Tz_N2E->setGeometry(QRect(90, 100, 81, 20));
        LE_VISION_CALIB_Ty_N2E = new QLineEdit(GB_CALIB_V2N_2);
        LE_VISION_CALIB_Ty_N2E->setObjectName(QString::fromUtf8("LE_VISION_CALIB_Ty_N2E"));
        LE_VISION_CALIB_Ty_N2E->setGeometry(QRect(90, 70, 81, 20));
        label_51 = new QLabel(GB_CALIB_V2N_2);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setGeometry(QRect(10, 40, 71, 17));
        label_52 = new QLabel(GB_CALIB_V2N_2);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setGeometry(QRect(10, 70, 71, 17));
        label_53 = new QLabel(GB_CALIB_V2N_2);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(10, 100, 71, 17));
        label_54 = new QLabel(GB_CALIB_V2N_2);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setGeometry(QRect(10, 190, 71, 17));
        LE_VISION_CALIB_Ry_N2E = new QLineEdit(GB_CALIB_V2N_2);
        LE_VISION_CALIB_Ry_N2E->setObjectName(QString::fromUtf8("LE_VISION_CALIB_Ry_N2E"));
        LE_VISION_CALIB_Ry_N2E->setGeometry(QRect(90, 160, 81, 20));
        label_55 = new QLabel(GB_CALIB_V2N_2);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setGeometry(QRect(10, 160, 71, 17));
        LE_VISION_CALIB_Rz_N2E = new QLineEdit(GB_CALIB_V2N_2);
        LE_VISION_CALIB_Rz_N2E->setObjectName(QString::fromUtf8("LE_VISION_CALIB_Rz_N2E"));
        LE_VISION_CALIB_Rz_N2E->setGeometry(QRect(90, 190, 81, 20));
        LE_VISION_CALIB_Rx_N2E = new QLineEdit(GB_CALIB_V2N_2);
        LE_VISION_CALIB_Rx_N2E->setObjectName(QString::fromUtf8("LE_VISION_CALIB_Rx_N2E"));
        LE_VISION_CALIB_Rx_N2E->setGeometry(QRect(90, 130, 81, 20));
        label_56 = new QLabel(GB_CALIB_V2N_2);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setGeometry(QRect(10, 130, 71, 17));
        LB_RAINBOW_LOGO_5 = new QLabel(tab_4);
        LB_RAINBOW_LOGO_5->setObjectName(QString::fromUtf8("LB_RAINBOW_LOGO_5"));
        LB_RAINBOW_LOGO_5->setGeometry(QRect(400, 810, 241, 91));
        sizePolicy.setHeightForWidth(LB_RAINBOW_LOGO_5->sizePolicy().hasHeightForWidth());
        LB_RAINBOW_LOGO_5->setSizePolicy(sizePolicy);
        LB_RAINBOW_LOGO_5->setFont(font);
        LB_RAINBOW_LOGO_5->setStyleSheet(QString::fromUtf8("background-color:rgb(31,34,41)"));
        LB_RAINBOW_LOGO_5->setPixmap(QPixmap(QString::fromUtf8(":/icon/icon/background2.jpg")));
        LB_RAINBOW_LOGO_5->setScaledContents(false);
        LB_RAINBOW_LOGO_5->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        GR_SENARIO = new QGroupBox(tab_5);
        GR_SENARIO->setObjectName(QString::fromUtf8("GR_SENARIO"));
        GR_SENARIO->setGeometry(QRect(10, 20, 641, 601));
        GR_SENARIO->setFont(font5);
        GR_SENARIO_CUSTOM = new QGroupBox(GR_SENARIO);
        GR_SENARIO_CUSTOM->setObjectName(QString::fromUtf8("GR_SENARIO_CUSTOM"));
        GR_SENARIO_CUSTOM->setGeometry(QRect(10, 190, 621, 411));
        label_47 = new QLabel(GR_SENARIO_CUSTOM);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(0, 30, 111, 17));
        CB_SENARIO_CUSTOM_LIST = new QComboBox(GR_SENARIO_CUSTOM);
        CB_SENARIO_CUSTOM_LIST->addItem(QString());
        CB_SENARIO_CUSTOM_LIST->addItem(QString());
        CB_SENARIO_CUSTOM_LIST->addItem(QString());
        CB_SENARIO_CUSTOM_LIST->addItem(QString());
        CB_SENARIO_CUSTOM_LIST->addItem(QString());
        CB_SENARIO_CUSTOM_LIST->addItem(QString());
        CB_SENARIO_CUSTOM_LIST->addItem(QString());
        CB_SENARIO_CUSTOM_LIST->addItem(QString());
        CB_SENARIO_CUSTOM_LIST->addItem(QString());
        CB_SENARIO_CUSTOM_LIST->addItem(QString());
        CB_SENARIO_CUSTOM_LIST->addItem(QString());
        CB_SENARIO_CUSTOM_LIST->addItem(QString());
        CB_SENARIO_CUSTOM_LIST->addItem(QString());
        CB_SENARIO_CUSTOM_LIST->addItem(QString());
        CB_SENARIO_CUSTOM_LIST->setObjectName(QString::fromUtf8("CB_SENARIO_CUSTOM_LIST"));
        CB_SENARIO_CUSTOM_LIST->setGeometry(QRect(290, 50, 241, 41));
        BTN_SENARIO_CUSTOM_ADD = new QPushButton(GR_SENARIO_CUSTOM);
        BTN_SENARIO_CUSTOM_ADD->setObjectName(QString::fromUtf8("BTN_SENARIO_CUSTOM_ADD"));
        BTN_SENARIO_CUSTOM_ADD->setGeometry(QRect(290, 100, 241, 31));
        BTN_SENARIO_CUSTOM_DEL = new QPushButton(GR_SENARIO_CUSTOM);
        BTN_SENARIO_CUSTOM_DEL->setObjectName(QString::fromUtf8("BTN_SENARIO_CUSTOM_DEL"));
        BTN_SENARIO_CUSTOM_DEL->setGeometry(QRect(290, 140, 241, 31));
        LW_SENARIO_CUSTOM_LIST = new QListWidget(GR_SENARIO_CUSTOM);
        LW_SENARIO_CUSTOM_LIST->setObjectName(QString::fromUtf8("LW_SENARIO_CUSTOM_LIST"));
        LW_SENARIO_CUSTOM_LIST->setGeometry(QRect(0, 50, 281, 361));
        BTN_SENARIO_EXECUTION_CUSTOM = new QPushButton(GR_SENARIO_CUSTOM);
        BTN_SENARIO_EXECUTION_CUSTOM->setObjectName(QString::fromUtf8("BTN_SENARIO_EXECUTION_CUSTOM"));
        BTN_SENARIO_EXECUTION_CUSTOM->setGeometry(QRect(290, 180, 241, 41));
        QFont font11;
        font11.setFamily(QString::fromUtf8("Liberation Sans"));
        font11.setPointSize(15);
        font11.setBold(true);
        font11.setItalic(true);
        font11.setUnderline(true);
        font11.setWeight(75);
        BTN_SENARIO_EXECUTION_CUSTOM->setFont(font11);
        BTN_SENARIO_EXECUTION_CUSTOM->setStyleSheet(QString::fromUtf8("background-color:rgb(128,128,128);\n"
"color:rgb(255,255,0)"));
        GR_SENARIO_BASIC = new QGroupBox(GR_SENARIO);
        GR_SENARIO_BASIC->setObjectName(QString::fromUtf8("GR_SENARIO_BASIC"));
        GR_SENARIO_BASIC->setGeometry(QRect(10, 30, 621, 151));
        label_44 = new QLabel(GR_SENARIO_BASIC);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(10, 30, 181, 51));
        QFont font12;
        font12.setFamily(QString::fromUtf8("Liberation Sans"));
        font12.setPointSize(18);
        label_44->setFont(font12);
        label_45 = new QLabel(GR_SENARIO_BASIC);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(260, 30, 91, 51));
        label_45->setFont(font12);
        label_46 = new QLabel(GR_SENARIO_BASIC);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(420, 30, 111, 51));
        label_46->setFont(font12);
        CB_SENARIO_OBJECT = new QComboBox(GR_SENARIO_BASIC);
        CB_SENARIO_OBJECT->addItem(QString());
        CB_SENARIO_OBJECT->addItem(QString());
        CB_SENARIO_OBJECT->addItem(QString());
        CB_SENARIO_OBJECT->setObjectName(QString::fromUtf8("CB_SENARIO_OBJECT"));
        CB_SENARIO_OBJECT->setGeometry(QRect(180, 30, 71, 51));
        QFont font13;
        font13.setPointSize(15);
        font13.setBold(true);
        font13.setUnderline(true);
        font13.setWeight(75);
        CB_SENARIO_OBJECT->setFont(font13);
        CB_SENARIO_OBJECT->setStyleSheet(QString::fromUtf8("background-color:rgb(128,128,128);\n"
"color:rgb(255,255,0)"));
        CB_SENARIO_LIFT_LEVEL = new QComboBox(GR_SENARIO_BASIC);
        CB_SENARIO_LIFT_LEVEL->addItem(QString());
        CB_SENARIO_LIFT_LEVEL->addItem(QString());
        CB_SENARIO_LIFT_LEVEL->addItem(QString());
        CB_SENARIO_LIFT_LEVEL->setObjectName(QString::fromUtf8("CB_SENARIO_LIFT_LEVEL"));
        CB_SENARIO_LIFT_LEVEL->setGeometry(QRect(340, 30, 71, 51));
        CB_SENARIO_LIFT_LEVEL->setFont(font13);
        CB_SENARIO_LIFT_LEVEL->setStyleSheet(QString::fromUtf8("background-color:rgb(128,128,128);\n"
"color:rgb(255,255,0)"));
        CB_SENARIO_SHELF_LOCATION = new QComboBox(GR_SENARIO_BASIC);
        CB_SENARIO_SHELF_LOCATION->addItem(QString());
        CB_SENARIO_SHELF_LOCATION->addItem(QString());
        CB_SENARIO_SHELF_LOCATION->addItem(QString());
        CB_SENARIO_SHELF_LOCATION->setObjectName(QString::fromUtf8("CB_SENARIO_SHELF_LOCATION"));
        CB_SENARIO_SHELF_LOCATION->setGeometry(QRect(520, 30, 71, 51));
        CB_SENARIO_SHELF_LOCATION->setFont(font13);
        CB_SENARIO_SHELF_LOCATION->setStyleSheet(QString::fromUtf8("background-color:rgb(128,128,128);\n"
"color:rgb(255,255,0)"));
        BTN_SENARIO_EXECUTION_BASIC = new QPushButton(GR_SENARIO_BASIC);
        BTN_SENARIO_EXECUTION_BASIC->setObjectName(QString::fromUtf8("BTN_SENARIO_EXECUTION_BASIC"));
        BTN_SENARIO_EXECUTION_BASIC->setGeometry(QRect(210, 100, 201, 41));
        BTN_SENARIO_EXECUTION_BASIC->setFont(font11);
        BTN_SENARIO_EXECUTION_BASIC->setStyleSheet(QString::fromUtf8("background-color:rgb(128,128,128);\n"
"color:rgb(255,255,0)"));
        LB_RAINBOW_LOGO_6 = new QLabel(tab_5);
        LB_RAINBOW_LOGO_6->setObjectName(QString::fromUtf8("LB_RAINBOW_LOGO_6"));
        LB_RAINBOW_LOGO_6->setGeometry(QRect(400, 810, 241, 91));
        sizePolicy.setHeightForWidth(LB_RAINBOW_LOGO_6->sizePolicy().hasHeightForWidth());
        LB_RAINBOW_LOGO_6->setSizePolicy(sizePolicy);
        LB_RAINBOW_LOGO_6->setFont(font);
        LB_RAINBOW_LOGO_6->setStyleSheet(QString::fromUtf8("background-color:rgb(31,34,41)"));
        LB_RAINBOW_LOGO_6->setPixmap(QPixmap(QString::fromUtf8(":/icon/icon/background2.jpg")));
        LB_RAINBOW_LOGO_6->setScaledContents(false);
        LB_RAINBOW_LOGO_6->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_5, QString());
        BTN_CHECK_SOCKET_STATUS = new QPushButton(centralwidget);
        BTN_CHECK_SOCKET_STATUS->setObjectName(QString::fromUtf8("BTN_CHECK_SOCKET_STATUS"));
        BTN_CHECK_SOCKET_STATUS->setGeometry(QRect(180, 130, 93, 41));
        BTN_CHECK_SOCKET_STATUS->setFont(font6);
        LE_RB5_INIT = new QLineEdit(centralwidget);
        LE_RB5_INIT->setObjectName(QString::fromUtf8("LE_RB5_INIT"));
        LE_RB5_INIT->setGeometry(QRect(130, 40, 40, 40));
        LE_RB5_INIT->setStyleSheet(QString::fromUtf8("    border-style: outset;\n"
"    border-width: 1px;\n"
"    border-color: black;"));
        LE_RB5_INIT->setReadOnly(true);
        LE_VISION_INIT = new QLineEdit(centralwidget);
        LE_VISION_INIT->setObjectName(QString::fromUtf8("LE_VISION_INIT"));
        LE_VISION_INIT->setGeometry(QRect(180, 40, 40, 40));
        LE_VISION_INIT->setStyleSheet(QString::fromUtf8("    border-style: outset;\n"
"    border-width: 1px;\n"
"    border-color: black;"));
        LE_VISION_INIT->setReadOnly(true);
        BTN_CONNECT_GRIPPER = new QPushButton(centralwidget);
        BTN_CONNECT_GRIPPER->setObjectName(QString::fromUtf8("BTN_CONNECT_GRIPPER"));
        BTN_CONNECT_GRIPPER->setGeometry(QRect(230, 90, 41, 30));
        BTN_CONNECT_GRIPPER->setFont(font);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(225, 20, 51, 16));
        QFont font14;
        font14.setBold(false);
        font14.setItalic(false);
        font14.setWeight(50);
        label_6->setFont(font14);
        label_6->setStyleSheet(QString::fromUtf8("    font:  10px;\n"
""));
        label_6->setAlignment(Qt::AlignCenter);
        BTN_CONNECT_VISION = new QPushButton(centralwidget);
        BTN_CONNECT_VISION->setObjectName(QString::fromUtf8("BTN_CONNECT_VISION"));
        BTN_CONNECT_VISION->setGeometry(QRect(180, 90, 41, 30));
        BTN_CONNECT_VISION->setFont(font);
        BTN_GLOBAL_INIT = new QPushButton(centralwidget);
        BTN_GLOBAL_INIT->setObjectName(QString::fromUtf8("BTN_GLOBAL_INIT"));
        BTN_GLOBAL_INIT->setGeometry(QRect(30, 130, 141, 28));
        BTN_GLOBAL_INIT->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(25, 20, 51, 16));
        label_2->setFont(font14);
        label_2->setStyleSheet(QString::fromUtf8("    font:  10px;\n"
""));
        label_2->setAlignment(Qt::AlignCenter);
        LE_GRIPPER_INIT = new QLineEdit(centralwidget);
        LE_GRIPPER_INIT->setObjectName(QString::fromUtf8("LE_GRIPPER_INIT"));
        LE_GRIPPER_INIT->setGeometry(QRect(230, 40, 40, 40));
        LE_GRIPPER_INIT->setStyleSheet(QString::fromUtf8("    border-style: outset;\n"
"    border-width: 1px;\n"
"    border-color: black;"));
        LE_GRIPPER_INIT->setReadOnly(true);
        BTN_CONNECT_OMRON = new QPushButton(centralwidget);
        BTN_CONNECT_OMRON->setObjectName(QString::fromUtf8("BTN_CONNECT_OMRON"));
        BTN_CONNECT_OMRON->setGeometry(QRect(30, 90, 41, 30));
        BTN_CONNECT_OMRON->setFont(font);
        BTN_CONNECT_LIFT = new QPushButton(centralwidget);
        BTN_CONNECT_LIFT->setObjectName(QString::fromUtf8("BTN_CONNECT_LIFT"));
        BTN_CONNECT_LIFT->setGeometry(QRect(80, 90, 41, 30));
        BTN_CONNECT_LIFT->setFont(font);
        LE_OMRON_INIT = new QLineEdit(centralwidget);
        LE_OMRON_INIT->setObjectName(QString::fromUtf8("LE_OMRON_INIT"));
        LE_OMRON_INIT->setGeometry(QRect(30, 40, 40, 40));
        LE_OMRON_INIT->setStyleSheet(QString::fromUtf8("    border-style: outset;\n"
"    border-width: 1px;\n"
"    border-color: black;"));
        LE_OMRON_INIT->setReadOnly(true);
        LE_LIFT_INIT = new QLineEdit(centralwidget);
        LE_LIFT_INIT->setObjectName(QString::fromUtf8("LE_LIFT_INIT"));
        LE_LIFT_INIT->setGeometry(QRect(80, 40, 40, 40));
        LE_LIFT_INIT->setStyleSheet(QString::fromUtf8("    border-style: outset;\n"
"    border-width: 1px;\n"
"    border-color: black;\n"
""));
        LE_LIFT_INIT->setReadOnly(true);
        BTN_CONNECT_RB5 = new QPushButton(centralwidget);
        BTN_CONNECT_RB5->setObjectName(QString::fromUtf8("BTN_CONNECT_RB5"));
        BTN_CONNECT_RB5->setGeometry(QRect(130, 90, 41, 30));
        BTN_CONNECT_RB5->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(125, 20, 51, 16));
        label_4->setFont(font14);
        label_4->setStyleSheet(QString::fromUtf8("    font:  10px;\n"
""));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(175, 20, 51, 16));
        label_5->setFont(font14);
        label_5->setStyleSheet(QString::fromUtf8("    font:  10px;\n"
""));
        label_5->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(75, 20, 51, 16));
        label_3->setFont(font14);
        label_3->setStyleSheet(QString::fromUtf8("    font:  10px;\n"
""));
        label_3->setAlignment(Qt::AlignCenter);
        GE_MOVE_INFO = new QGroupBox(centralwidget);
        GE_MOVE_INFO->setObjectName(QString::fromUtf8("GE_MOVE_INFO"));
        GE_MOVE_INFO->setGeometry(QRect(290, 20, 311, 81));
        GE_MOVE_INFO->setFont(font5);
        LE_OMRON_MOVE_INFO = new QLineEdit(GE_MOVE_INFO);
        LE_OMRON_MOVE_INFO->setObjectName(QString::fromUtf8("LE_OMRON_MOVE_INFO"));
        LE_OMRON_MOVE_INFO->setGeometry(QRect(70, 30, 40, 40));
        LE_OMRON_MOVE_INFO->setStyleSheet(QString::fromUtf8("    border-style: outset;\n"
"    border-width: 1px;\n"
"    border-color: black;"));
        LE_OMRON_MOVE_INFO->setReadOnly(true);
        LE_LIFT_MOVE_INFO = new QLineEdit(GE_MOVE_INFO);
        LE_LIFT_MOVE_INFO->setObjectName(QString::fromUtf8("LE_LIFT_MOVE_INFO"));
        LE_LIFT_MOVE_INFO->setGeometry(QRect(120, 30, 40, 40));
        LE_LIFT_MOVE_INFO->setStyleSheet(QString::fromUtf8("    border-style: outset;\n"
"    border-width: 1px;\n"
"    border-color: black;"));
        LE_LIFT_MOVE_INFO->setReadOnly(true);
        LE_RB5_MOVE_INFO = new QLineEdit(GE_MOVE_INFO);
        LE_RB5_MOVE_INFO->setObjectName(QString::fromUtf8("LE_RB5_MOVE_INFO"));
        LE_RB5_MOVE_INFO->setGeometry(QRect(170, 30, 40, 40));
        LE_RB5_MOVE_INFO->setStyleSheet(QString::fromUtf8("    border-style: outset;\n"
"    border-width: 1px;\n"
"    border-color: black;"));
        LE_RB5_MOVE_INFO->setReadOnly(true);
        label_36 = new QLabel(GE_MOVE_INFO);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(64, 10, 51, 16));
        label_36->setFont(font14);
        label_36->setStyleSheet(QString::fromUtf8("    font:  10px;\n"
""));
        label_36->setAlignment(Qt::AlignCenter);
        label_37 = new QLabel(GE_MOVE_INFO);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(114, 10, 51, 16));
        label_37->setFont(font14);
        label_37->setStyleSheet(QString::fromUtf8("    font:  10px;\n"
""));
        label_37->setAlignment(Qt::AlignCenter);
        label_38 = new QLabel(GE_MOVE_INFO);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(164, 10, 51, 16));
        label_38->setFont(font14);
        label_38->setStyleSheet(QString::fromUtf8("    font:  10px;\n"
""));
        label_38->setAlignment(Qt::AlignCenter);
        LE_INFO_MOVE_INFO_1 = new QLineEdit(GE_MOVE_INFO);
        LE_INFO_MOVE_INFO_1->setObjectName(QString::fromUtf8("LE_INFO_MOVE_INFO_1"));
        LE_INFO_MOVE_INFO_1->setGeometry(QRect(220, 30, 31, 16));
        LE_INFO_MOVE_INFO_1->setStyleSheet(QString::fromUtf8("background-color:rgb(255,0,0)"));
        LE_INFO_MOVE_INFO_2 = new QLineEdit(GE_MOVE_INFO);
        LE_INFO_MOVE_INFO_2->setObjectName(QString::fromUtf8("LE_INFO_MOVE_INFO_2"));
        LE_INFO_MOVE_INFO_2->setGeometry(QRect(220, 50, 31, 16));
        LE_INFO_MOVE_INFO_2->setStyleSheet(QString::fromUtf8("background-color:rgb(0,255,0)"));
        label_42 = new QLabel(GE_MOVE_INFO);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(260, 30, 21, 16));
        label_42->setFont(font);
        label_43 = new QLabel(GE_MOVE_INFO);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(260, 50, 21, 16));
        label_43->setFont(font);
        GR_GLOBAL_STATUS = new QGroupBox(centralwidget);
        GR_GLOBAL_STATUS->setObjectName(QString::fromUtf8("GR_GLOBAL_STATUS"));
        GR_GLOBAL_STATUS->setGeometry(QRect(290, 110, 311, 91));
        GR_GLOBAL_STATUS->setFont(font5);
        LE_IP_KETI = new QLineEdit(GR_GLOBAL_STATUS);
        LE_IP_KETI->setObjectName(QString::fromUtf8("LE_IP_KETI"));
        LE_IP_KETI->setGeometry(QRect(60, 30, 121, 20));
        LE_IP_KETI->setReadOnly(false);
        label_39 = new QLabel(GR_GLOBAL_STATUS);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(10, 30, 51, 20));
        label_39->setFont(font1);
        LE_IP_KITECH = new QLineEdit(GR_GLOBAL_STATUS);
        LE_IP_KITECH->setObjectName(QString::fromUtf8("LE_IP_KITECH"));
        LE_IP_KITECH->setGeometry(QRect(60, 50, 121, 20));
        LE_IP_KITECH->setReadOnly(false);
        label_40 = new QLabel(GR_GLOBAL_STATUS);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(10, 50, 51, 20));
        label_40->setFont(font1);
        LE_PORT_KETI = new QLineEdit(GR_GLOBAL_STATUS);
        LE_PORT_KETI->setObjectName(QString::fromUtf8("LE_PORT_KETI"));
        LE_PORT_KETI->setGeometry(QRect(190, 30, 71, 20));
        LE_PORT_KETI->setReadOnly(false);
        LE_PORT_KITECH = new QLineEdit(GR_GLOBAL_STATUS);
        LE_PORT_KITECH->setObjectName(QString::fromUtf8("LE_PORT_KITECH"));
        LE_PORT_KITECH->setGeometry(QRect(190, 50, 71, 20));
        LE_PORT_KITECH->setReadOnly(false);
        BTN_SET_IP_PORT_KETI = new QPushButton(GR_GLOBAL_STATUS);
        BTN_SET_IP_PORT_KETI->setObjectName(QString::fromUtf8("BTN_SET_IP_PORT_KETI"));
        BTN_SET_IP_PORT_KETI->setGeometry(QRect(270, 30, 31, 21));
        BTN_SET_IP_PORT_KETI->setFont(font6);
        BTN_SET_IP_PORT_KITECH = new QPushButton(GR_GLOBAL_STATUS);
        BTN_SET_IP_PORT_KITECH->setObjectName(QString::fromUtf8("BTN_SET_IP_PORT_KITECH"));
        BTN_SET_IP_PORT_KITECH->setGeometry(QRect(270, 50, 31, 21));
        BTN_SET_IP_PORT_KITECH->setFont(font6);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(570, 220, 131, 16));
        label->setFont(font5);
        label->setScaledContents(true);
        TE_GLOBAL_LOG = new QTextEdit(centralwidget);
        TE_GLOBAL_LOG->setObjectName(QString::fromUtf8("TE_GLOBAL_LOG"));
        TE_GLOBAL_LOG->setGeometry(QRect(570, 250, 500, 501));
        TE_GLOBAL_LOG->setFont(font);
        TE_GLOBAL_LOG->setStyleSheet(QString::fromUtf8("    border-style: outset;\n"
"    border-width: 1px;\n"
"    border-color: black;\n"
"background-color:rgb(255,255,255)"));
        TE_GLOBAL_LOG->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        TE_GLOBAL_LOG->setReadOnly(false);
        TE_GLOBAL_LOG->setTextInteractionFlags(Qt::TextEditorInteraction);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(610, 20, 471, 181));
        LB_OMRON_MAP = new QMyLabel(centralwidget);
        LB_OMRON_MAP->setObjectName(QString::fromUtf8("LB_OMRON_MAP"));
        LB_OMRON_MAP->setGeometry(QRect(20, 250, 500, 500));
        LB_OMRON_MAP->setStyleSheet(QString::fromUtf8("    border-style: outset;\n"
"    border-width: 1px;\n"
"    border-color: black;\n"
"background-color:rgb(255,255,255)"));
        LB_KETI_FRAME = new QLabel(centralwidget);
        LB_KETI_FRAME->setObjectName(QString::fromUtf8("LB_KETI_FRAME"));
        LB_KETI_FRAME->setGeometry(QRect(20, 780, 501, 241));
        LB_KETI_FRAME->setStyleSheet(QString::fromUtf8("    border-style: outset;\n"
"    border-width: 1px;\n"
"    border-color: black;\n"
"background-color:rgb(255,255,255)"));
        label_26 = new QLabel(centralwidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(20, 220, 101, 16));
        label_26->setFont(font5);
        label_26->setScaledContents(true);
        BTN_TE_GLOBAL_CLEAR = new QPushButton(centralwidget);
        BTN_TE_GLOBAL_CLEAR->setObjectName(QString::fromUtf8("BTN_TE_GLOBAL_CLEAR"));
        BTN_TE_GLOBAL_CLEAR->setGeometry(QRect(960, 220, 111, 21));
        label_27 = new QLabel(centralwidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(20, 760, 101, 16));
        label_27->setFont(font5);
        label_27->setScaledContents(true);
        GR_GLOBAL_STATUS_2 = new QGroupBox(centralwidget);
        GR_GLOBAL_STATUS_2->setObjectName(QString::fromUtf8("GR_GLOBAL_STATUS_2"));
        GR_GLOBAL_STATUS_2->setGeometry(QRect(570, 760, 501, 261));
        GR_GLOBAL_STATUS_2->setFont(font5);
        LB_Shelves_2 = new QLabel(GR_GLOBAL_STATUS_2);
        LB_Shelves_2->setObjectName(QString::fromUtf8("LB_Shelves_2"));
        LB_Shelves_2->setGeometry(QRect(400, 220, 81, 21));
        LB_Shelves_2->setLayoutDirection(Qt::LeftToRight);
        LB_Shelves_2->setAutoFillBackground(false);
        LB_Shelves_2->setStyleSheet(QString::fromUtf8("    border-style: outset;\n"
"\n"
"    border-width: 1px;\n"
"    border-color: black;\n"
"background-color:rgb(255,255,255)"));
        LB_Shelves_2->setAlignment(Qt::AlignCenter);
        layoutWidget2 = new QWidget(GR_GLOBAL_STATUS_2);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(30, 70, 82, 124));
        gridLayout_3 = new QGridLayout(layoutWidget2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        BTN_SH_14 = new QPushButton(layoutWidget2);
        BTN_SH_14->setObjectName(QString::fromUtf8("BTN_SH_14"));

        gridLayout_3->addWidget(BTN_SH_14, 0, 0, 1, 1);

        BTN_SH_13 = new QPushButton(layoutWidget2);
        BTN_SH_13->setObjectName(QString::fromUtf8("BTN_SH_13"));

        gridLayout_3->addWidget(BTN_SH_13, 3, 0, 1, 1);

        BTN_SH_11 = new QPushButton(layoutWidget2);
        BTN_SH_11->setObjectName(QString::fromUtf8("BTN_SH_11"));

        gridLayout_3->addWidget(BTN_SH_11, 5, 0, 1, 1);

        BTN_SH_12 = new QPushButton(layoutWidget2);
        BTN_SH_12->setObjectName(QString::fromUtf8("BTN_SH_12"));

        gridLayout_3->addWidget(BTN_SH_12, 4, 0, 1, 1);

        layoutWidget3 = new QWidget(GR_GLOBAL_STATUS_2);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(370, 70, 82, 124));
        gridLayout_4 = new QGridLayout(layoutWidget3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        BTN_SH_42 = new QPushButton(layoutWidget3);
        BTN_SH_42->setObjectName(QString::fromUtf8("BTN_SH_42"));

        gridLayout_4->addWidget(BTN_SH_42, 2, 0, 1, 1);

        BTN_SH_44 = new QPushButton(layoutWidget3);
        BTN_SH_44->setObjectName(QString::fromUtf8("BTN_SH_44"));

        gridLayout_4->addWidget(BTN_SH_44, 0, 0, 1, 1);

        BTN_SH_41 = new QPushButton(layoutWidget3);
        BTN_SH_41->setObjectName(QString::fromUtf8("BTN_SH_41"));

        gridLayout_4->addWidget(BTN_SH_41, 5, 0, 1, 1);

        BTN_SH_43 = new QPushButton(layoutWidget3);
        BTN_SH_43->setObjectName(QString::fromUtf8("BTN_SH_43"));

        gridLayout_4->addWidget(BTN_SH_43, 1, 0, 1, 1);

        widget = new QWidget(GR_GLOBAL_STATUS_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(160, 70, 168, 124));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        BTN_SH_24 = new QPushButton(widget);
        BTN_SH_24->setObjectName(QString::fromUtf8("BTN_SH_24"));

        gridLayout_2->addWidget(BTN_SH_24, 0, 0, 1, 1);

        BTN_SH_34 = new QPushButton(widget);
        BTN_SH_34->setObjectName(QString::fromUtf8("BTN_SH_34"));

        gridLayout_2->addWidget(BTN_SH_34, 0, 1, 1, 1);

        BTN_SH_23 = new QPushButton(widget);
        BTN_SH_23->setObjectName(QString::fromUtf8("BTN_SH_23"));

        gridLayout_2->addWidget(BTN_SH_23, 1, 0, 1, 1);

        BTN_SH_33 = new QPushButton(widget);
        BTN_SH_33->setObjectName(QString::fromUtf8("BTN_SH_33"));

        gridLayout_2->addWidget(BTN_SH_33, 1, 1, 1, 1);

        BTN_SH_22 = new QPushButton(widget);
        BTN_SH_22->setObjectName(QString::fromUtf8("BTN_SH_22"));

        gridLayout_2->addWidget(BTN_SH_22, 2, 0, 1, 1);

        BTN_SH_32 = new QPushButton(widget);
        BTN_SH_32->setObjectName(QString::fromUtf8("BTN_SH_32"));

        gridLayout_2->addWidget(BTN_SH_32, 2, 1, 1, 1);

        BTN_SH_21 = new QPushButton(widget);
        BTN_SH_21->setObjectName(QString::fromUtf8("BTN_SH_21"));

        gridLayout_2->addWidget(BTN_SH_21, 3, 0, 1, 1);

        BTN_SH_31 = new QPushButton(widget);
        BTN_SH_31->setObjectName(QString::fromUtf8("BTN_SH_31"));

        gridLayout_2->addWidget(BTN_SH_31, 3, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionIP_Port_change->setText(QApplication::translate("MainWindow", "Ip && Port change", nullptr));
        LB_RAINBOW_LOGO_2->setText(QString());
        lable_get_info_2->setText(QApplication::translate("MainWindow", "Robot Information", nullptr));
        label_status->setText(QApplication::translate("MainWindow", "Status :", nullptr));
        label_battery->setText(QApplication::translate("MainWindow", "Battery :", nullptr));
        label_location->setText(QApplication::translate("MainWindow", "Location :", nullptr));
        label_temperature->setText(QApplication::translate("MainWindow", "Temp :", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "X :", nullptr));
        BTN_OMRON_ADD->setText(QApplication::translate("MainWindow", "ADD", nullptr));
        BTN_OMRON_SAVE_GOAL_1->setText(QApplication::translate("MainWindow", "Save \n"
"Goal 1", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "Battery :", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "Y :", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "Location :", nullptr));
        BTN_OMRON_SAVE_ST->setText(QApplication::translate("MainWindow", "Save \n"
"Start point", nullptr));
        BTN_OMRON_SAVE_GOAL_2->setText(QApplication::translate("MainWindow", "Save \n"
"Goal 2", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "\316\270 :", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "Temp :", nullptr));
        btn_say->setText(QApplication::translate("MainWindow", "Say", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "OMRON", nullptr));
        GR_LIFT->setTitle(QApplication::translate("MainWindow", "LIFT", nullptr));
        label_29->setText(QApplication::translate("MainWindow", "Ref :", nullptr));
        label_30->setText(QApplication::translate("MainWindow", "Enc:", nullptr));
        label_31->setText(QApplication::translate("MainWindow", "Goal:", nullptr));
        BTN_LIFT_LOAD_TOP->setText(QApplication::translate("MainWindow", "Load", nullptr));
        BTN_LIFT_SAVE_TOP->setText(QApplication::translate("MainWindow", "Save", nullptr));
        BTN_LIFT_SET_TOP->setText(QApplication::translate("MainWindow", "Set", nullptr));
        BTN_LIFT_SAVE_MIDDLE->setText(QApplication::translate("MainWindow", "Save", nullptr));
        BTN_LIFT_SET_MIDDLE->setText(QApplication::translate("MainWindow", "Set", nullptr));
        BTN_LIFT_LOAD_MIDDLE->setText(QApplication::translate("MainWindow", "Load", nullptr));
        BTN_LIFT_SAVE_BOTTOM->setText(QApplication::translate("MainWindow", "Save", nullptr));
        BTN_LIFT_SET_BOTTOM->setText(QApplication::translate("MainWindow", "Set", nullptr));
        BTN_LIFT_LOAD_BOTTOM->setText(QApplication::translate("MainWindow", "Load", nullptr));
        label_32->setText(QApplication::translate("MainWindow", "Top:", nullptr));
        label_33->setText(QApplication::translate("MainWindow", "Mid :", nullptr));
        label_34->setText(QApplication::translate("MainWindow", "Bot:", nullptr));
        BTN_LIFT_SERIAL_OPEN->setText(QApplication::translate("MainWindow", "open", nullptr));
        BTN_LIFT_HOMING->setText(QApplication::translate("MainWindow", "homing", nullptr));
        BTN_LIFT_REQ_DATA->setText(QApplication::translate("MainWindow", "REQ\n"
"DATA", nullptr));
        LB_RAINBOW_LOGO_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "LIFT", nullptr));
        GR_RB5->setTitle(QApplication::translate("MainWindow", "RB5", nullptr));
        BTN_RB5_MOVE_VISION->setText(QApplication::translate("MainWindow", "Move \n"
"vision Pos", nullptr));
        BTN_RB5_MOVE_GRIPPER_READY->setText(QApplication::translate("MainWindow", "Move \n"
"ready Pos", nullptr));
        BTN_RB5_MOVE_GRIPPER_GRAPS->setText(QApplication::translate("MainWindow", "Move \n"
"graps Pos", nullptr));
        BTN_RB5_MOVE_INIT->setText(QApplication::translate("MainWindow", "Move \n"
"init Pos", nullptr));
        BTN_RB5_SAVE_GRIPPER_GRAPS->setText(QApplication::translate("MainWindow", "Save \n"
"graps Pos", nullptr));
        BTN_RB5_SAVE_GRIPPER_READY->setText(QApplication::translate("MainWindow", "Save \n"
"ready Pos", nullptr));
        BTN_RB5_SAVE_INIT->setText(QApplication::translate("MainWindow", "Save \n"
"init Pos", nullptr));
        BTN_RB5_SAVE_VISION->setText(QApplication::translate("MainWindow", "Save \n"
"vision Pos", nullptr));
        BTN_RB5_MODE->setText(QApplication::translate("MainWindow", "Simul.", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "0%", nullptr));
        BTN_RB5_MOVE_EXTRA_1->setText(QApplication::translate("MainWindow", "Move \n"
"extra Pos 1", nullptr));
        BTN_RB5_SAVE_EXTRA_1->setText(QApplication::translate("MainWindow", "Save \n"
"extra Pos 1", nullptr));
        BTN_RB5_MOVE_EXTRA_2->setText(QApplication::translate("MainWindow", "Move \n"
"extra Pos 2", nullptr));
        BTN_RB5_SAVE_EXTRA_2->setText(QApplication::translate("MainWindow", "Save \n"
"extra Pos 2", nullptr));
        BTN_RB5_PASUE->setText(QApplication::translate("MainWindow", "Pause", nullptr));
        BTN_RB5_RESUME->setText(QApplication::translate("MainWindow", "Resume", nullptr));
        BTN_RB5_HOLT->setText(QApplication::translate("MainWindow", "Holt", nullptr));
        label_41->setText(QApplication::translate("MainWindow", " %", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "J1", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "J4", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "J2", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "J5", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "J3", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "J6", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "X", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "Rx", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "Y", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "Ry", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "Z", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "Rz", nullptr));
        LB_RAINBOW_LOGO_4->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "RB5", nullptr));
        GR_KITECH->setTitle(QApplication::translate("MainWindow", "GRIPPER", nullptr));
        BTN_GRIPPER_CMD_WRITE->setText(QApplication::translate("MainWindow", "Write", nullptr));
        BTN_GRIPPER_UNFOLD->setText(QApplication::translate("MainWindow", "Unfold", nullptr));
        BTN_GRIPPER_GRAP->setText(QApplication::translate("MainWindow", "Grap", nullptr));
        BTN_GRIPPER_VISION->setText(QApplication::translate("MainWindow", "Vision", nullptr));
        CB_GRIPPER_GRAPS->setItemText(0, QApplication::translate("MainWindow", "g", nullptr));
        CB_GRIPPER_GRAPS->setItemText(1, QApplication::translate("MainWindow", "p", nullptr));
        CB_GRIPPER_GRAPS->setItemText(2, QApplication::translate("MainWindow", "m", nullptr));
        CB_GRIPPER_GRAPS->setItemText(3, QApplication::translate("MainWindow", "i", nullptr));
        CB_GRIPPER_GRAPS->setItemText(4, QApplication::translate("MainWindow", "t", nullptr));
        CB_GRIPPER_GRAPS->setItemText(5, QApplication::translate("MainWindow", "e", nullptr));

        CB_GRIPPER_POWER->setItemText(0, QApplication::translate("MainWindow", "0", nullptr));
        CB_GRIPPER_POWER->setItemText(1, QApplication::translate("MainWindow", "1", nullptr));
        CB_GRIPPER_POWER->setItemText(2, QApplication::translate("MainWindow", "2", nullptr));
        CB_GRIPPER_POWER->setItemText(3, QApplication::translate("MainWindow", "3", nullptr));
        CB_GRIPPER_POWER->setItemText(4, QApplication::translate("MainWindow", "4", nullptr));
        CB_GRIPPER_POWER->setItemText(5, QApplication::translate("MainWindow", "5", nullptr));
        CB_GRIPPER_POWER->setItemText(6, QApplication::translate("MainWindow", "6", nullptr));
        CB_GRIPPER_POWER->setItemText(7, QApplication::translate("MainWindow", "7", nullptr));
        CB_GRIPPER_POWER->setItemText(8, QApplication::translate("MainWindow", "8", nullptr));
        CB_GRIPPER_POWER->setItemText(9, QApplication::translate("MainWindow", "9", nullptr));

        CB_GRIPPER_GE_MODE->setItemText(0, QApplication::translate("MainWindow", "R", nullptr));
        CB_GRIPPER_GE_MODE->setItemText(1, QApplication::translate("MainWindow", "G", nullptr));

        CB_GRIPPER_GE_GRAPS->setItemText(0, QApplication::translate("MainWindow", "g", nullptr));
        CB_GRIPPER_GE_GRAPS->setItemText(1, QApplication::translate("MainWindow", "p", nullptr));
        CB_GRIPPER_GE_GRAPS->setItemText(2, QApplication::translate("MainWindow", "m", nullptr));
        CB_GRIPPER_GE_GRAPS->setItemText(3, QApplication::translate("MainWindow", "i", nullptr));
        CB_GRIPPER_GE_GRAPS->setItemText(4, QApplication::translate("MainWindow", "t", nullptr));
        CB_GRIPPER_GE_GRAPS->setItemText(5, QApplication::translate("MainWindow", "e", nullptr));

        CB_GRIPPER_GE_POWER->setItemText(0, QApplication::translate("MainWindow", "0", nullptr));
        CB_GRIPPER_GE_POWER->setItemText(1, QApplication::translate("MainWindow", "1", nullptr));
        CB_GRIPPER_GE_POWER->setItemText(2, QApplication::translate("MainWindow", "2", nullptr));
        CB_GRIPPER_GE_POWER->setItemText(3, QApplication::translate("MainWindow", "3", nullptr));
        CB_GRIPPER_GE_POWER->setItemText(4, QApplication::translate("MainWindow", "4", nullptr));
        CB_GRIPPER_GE_POWER->setItemText(5, QApplication::translate("MainWindow", "5", nullptr));
        CB_GRIPPER_GE_POWER->setItemText(6, QApplication::translate("MainWindow", "6", nullptr));
        CB_GRIPPER_GE_POWER->setItemText(7, QApplication::translate("MainWindow", "7", nullptr));
        CB_GRIPPER_GE_POWER->setItemText(8, QApplication::translate("MainWindow", "8", nullptr));
        CB_GRIPPER_GE_POWER->setItemText(9, QApplication::translate("MainWindow", "9", nullptr));

        CB_GRIPPER_GE_CMD_WRITE->setText(QApplication::translate("MainWindow", "Write", nullptr));
        BTN_RB5_CALC_GRAPS_POINT->setText(QApplication::translate("MainWindow", "calc\n"
"graps point", nullptr));
        BTN_RB5_MOVE_GRAPS_POINT->setText(QApplication::translate("MainWindow", "move\n"
"graps point", nullptr));
        label_58->setText(QApplication::translate("MainWindow", "ty", nullptr));
        label_59->setText(QApplication::translate("MainWindow", "tz", nullptr));
        label_57->setText(QApplication::translate("MainWindow", "tx", nullptr));
        label_61->setText(QApplication::translate("MainWindow", "Ry", nullptr));
        label_60->setText(QApplication::translate("MainWindow", "Rz", nullptr));
        label_62->setText(QApplication::translate("MainWindow", "Rx", nullptr));
        BTN_LOAD_GRAPS_POINT->setText(QApplication::translate("MainWindow", "load.", nullptr));
        BTN_SET_GRAPS_POINT->setText(QApplication::translate("MainWindow", "set.", nullptr));
        GR_KETI->setTitle(QApplication::translate("MainWindow", "VISION", nullptr));
        BTN_VISION_CMD_WRITE->setText(QApplication::translate("MainWindow", "Write", nullptr));
        BTN_VISION_OUT_SET->setText(QApplication::translate("MainWindow", "Set", nullptr));
        BTN_VISION_OUT_LOAD->setText(QApplication::translate("MainWindow", "Load", nullptr));
        BTN_VISION_OUT_SAVE->setText(QApplication::translate("MainWindow", "Save", nullptr));
        GB_CALIB_V2N->setTitle(QApplication::translate("MainWindow", "calibration V2N", nullptr));
        BTN_SET_CALIB_T_V2N->setText(QApplication::translate("MainWindow", "set.", nullptr));
        label_48->setText(QApplication::translate("MainWindow", "tx_v2n :", nullptr));
        label_49->setText(QApplication::translate("MainWindow", "ty_v2n :", nullptr));
        label_50->setText(QApplication::translate("MainWindow", "tz_v2n :", nullptr));
        GB_CALIB_V2N_2->setTitle(QApplication::translate("MainWindow", "calibration N2E", nullptr));
        BTN_SET_CALIB_T_N2E->setText(QApplication::translate("MainWindow", "set.", nullptr));
        label_51->setText(QApplication::translate("MainWindow", "tx_n2e :", nullptr));
        label_52->setText(QApplication::translate("MainWindow", "ty_n2e :", nullptr));
        label_53->setText(QApplication::translate("MainWindow", "tz_n2e :", nullptr));
        label_54->setText(QApplication::translate("MainWindow", "Rz_n2e :", nullptr));
        label_55->setText(QApplication::translate("MainWindow", "Ry_n2e :", nullptr));
        label_56->setText(QApplication::translate("MainWindow", "Rx_n2e :", nullptr));
        LB_RAINBOW_LOGO_5->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "SOCKET", nullptr));
        GR_SENARIO->setTitle(QApplication::translate("MainWindow", "SENARIO", nullptr));
        GR_SENARIO_CUSTOM->setTitle(QApplication::translate("MainWindow", "CUSTOM", nullptr));
        label_47->setText(QApplication::translate("MainWindow", "Custom Senario", nullptr));
        CB_SENARIO_CUSTOM_LIST->setItemText(0, QApplication::translate("MainWindow", "[OMRON]  MOVE GOAL1", nullptr));
        CB_SENARIO_CUSTOM_LIST->setItemText(1, QApplication::translate("MainWindow", "[OMRON]  MOVE GOAL 2", nullptr));
        CB_SENARIO_CUSTOM_LIST->setItemText(2, QApplication::translate("MainWindow", "[OMRON]  MOVE INIT LOCATION", nullptr));
        CB_SENARIO_CUSTOM_LIST->setItemText(3, QApplication::translate("MainWindow", "[OMRON]  MOVE EXTRA LOCATION", nullptr));
        CB_SENARIO_CUSTOM_LIST->setItemText(4, QApplication::translate("MainWindow", "    [RB5]      MOVE INIT POS", nullptr));
        CB_SENARIO_CUSTOM_LIST->setItemText(5, QApplication::translate("MainWindow", "    [RB5]      MOVE VISION POS", nullptr));
        CB_SENARIO_CUSTOM_LIST->setItemText(6, QApplication::translate("MainWindow", "    [RB5]      MOVE GRIPPER READY POS", nullptr));
        CB_SENARIO_CUSTOM_LIST->setItemText(7, QApplication::translate("MainWindow", "    [RB5]      MOVE GRIPPER GRAPS POS", nullptr));
        CB_SENARIO_CUSTOM_LIST->setItemText(8, QApplication::translate("MainWindow", "    [LIFT]      MOVE TOP", nullptr));
        CB_SENARIO_CUSTOM_LIST->setItemText(9, QApplication::translate("MainWindow", "    [LIFT]      MOVE MID", nullptr));
        CB_SENARIO_CUSTOM_LIST->setItemText(10, QApplication::translate("MainWindow", "    [LIFT]      MOVE BOT", nullptr));
        CB_SENARIO_CUSTOM_LIST->setItemText(11, QApplication::translate("MainWindow", "  [VISION]  REQ,VISION,DETECT", nullptr));
        CB_SENARIO_CUSTOM_LIST->setItemText(12, QApplication::translate("MainWindow", "[GRIPPER] GRPAS", nullptr));
        CB_SENARIO_CUSTOM_LIST->setItemText(13, QApplication::translate("MainWindow", "[GRIPPER] VISION POS", nullptr));

        BTN_SENARIO_CUSTOM_ADD->setText(QApplication::translate("MainWindow", "ADD", nullptr));
        BTN_SENARIO_CUSTOM_DEL->setText(QApplication::translate("MainWindow", "DELETE", nullptr));
        BTN_SENARIO_EXECUTION_CUSTOM->setText(QApplication::translate("MainWindow", "Scenario Execution", nullptr));
        GR_SENARIO_BASIC->setTitle(QApplication::translate("MainWindow", "BASIC", nullptr));
        label_44->setText(QApplication::translate("MainWindow", "Pick up Object", nullptr));
        label_45->setText(QApplication::translate("MainWindow", "at level ", nullptr));
        label_46->setText(QApplication::translate("MainWindow", "On shelf", nullptr));
        CB_SENARIO_OBJECT->setItemText(0, QApplication::translate("MainWindow", "A", nullptr));
        CB_SENARIO_OBJECT->setItemText(1, QApplication::translate("MainWindow", "B", nullptr));
        CB_SENARIO_OBJECT->setItemText(2, QApplication::translate("MainWindow", "C", nullptr));

        CB_SENARIO_LIFT_LEVEL->setItemText(0, QApplication::translate("MainWindow", "TOP", nullptr));
        CB_SENARIO_LIFT_LEVEL->setItemText(1, QApplication::translate("MainWindow", "MID", nullptr));
        CB_SENARIO_LIFT_LEVEL->setItemText(2, QApplication::translate("MainWindow", "BOT", nullptr));

        CB_SENARIO_SHELF_LOCATION->setItemText(0, QApplication::translate("MainWindow", "1", nullptr));
        CB_SENARIO_SHELF_LOCATION->setItemText(1, QApplication::translate("MainWindow", "2", nullptr));
        CB_SENARIO_SHELF_LOCATION->setItemText(2, QApplication::translate("MainWindow", "3", nullptr));

        BTN_SENARIO_EXECUTION_BASIC->setText(QApplication::translate("MainWindow", "Scenario Execution", nullptr));
        LB_RAINBOW_LOGO_6->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "SENARIO", nullptr));
        BTN_CHECK_SOCKET_STATUS->setText(QApplication::translate("MainWindow", "check\n"
"Socek", nullptr));
        BTN_CONNECT_GRIPPER->setText(QApplication::translate("MainWindow", "conn.", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "GRIPPER", nullptr));
        BTN_CONNECT_VISION->setText(QApplication::translate("MainWindow", "conn.", nullptr));
        BTN_GLOBAL_INIT->setText(QApplication::translate("MainWindow", "Global intialization", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "OMRON", nullptr));
        BTN_CONNECT_OMRON->setText(QApplication::translate("MainWindow", "conn.", nullptr));
        BTN_CONNECT_LIFT->setText(QApplication::translate("MainWindow", "conn.", nullptr));
        BTN_CONNECT_RB5->setText(QApplication::translate("MainWindow", "conn.", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "RB5", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "VISION", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "LIFT", nullptr));
        GE_MOVE_INFO->setTitle(QApplication::translate("MainWindow", "Move info", nullptr));
        label_36->setText(QApplication::translate("MainWindow", "OMRON", nullptr));
        label_37->setText(QApplication::translate("MainWindow", "LIFT", nullptr));
        label_38->setText(QApplication::translate("MainWindow", "RB5", nullptr));
        label_42->setText(QApplication::translate("MainWindow", "stop", nullptr));
        label_43->setText(QApplication::translate("MainWindow", "move", nullptr));
        GR_GLOBAL_STATUS->setTitle(QApplication::translate("MainWindow", "IP && Port", nullptr));
        label_39->setText(QApplication::translate("MainWindow", "Vision   :", nullptr));
        label_40->setText(QApplication::translate("MainWindow", "Gripper :", nullptr));
        BTN_SET_IP_PORT_KETI->setText(QApplication::translate("MainWindow", "set", nullptr));
        BTN_SET_IP_PORT_KITECH->setText(QApplication::translate("MainWindow", "set", nullptr));
        label->setText(QApplication::translate("MainWindow", "GLOBAL LOG", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "LIFT INFO", nullptr));
        LB_OMRON_MAP->setText(QString());
        LB_KETI_FRAME->setText(QString());
        label_26->setText(QApplication::translate("MainWindow", "OMRON MAP", nullptr));
        BTN_TE_GLOBAL_CLEAR->setText(QApplication::translate("MainWindow", "clear", nullptr));
        label_27->setText(QApplication::translate("MainWindow", "KETI FRAME", nullptr));
        GR_GLOBAL_STATUS_2->setTitle(QApplication::translate("MainWindow", "Shelfs", nullptr));
        LB_Shelves_2->setText(QApplication::translate("MainWindow", "desk", nullptr));
        BTN_SH_14->setText(QApplication::translate("MainWindow", "1-4", nullptr));
        BTN_SH_13->setText(QApplication::translate("MainWindow", "1-3", nullptr));
        BTN_SH_11->setText(QApplication::translate("MainWindow", "1-1", nullptr));
        BTN_SH_12->setText(QApplication::translate("MainWindow", "1-2", nullptr));
        BTN_SH_42->setText(QApplication::translate("MainWindow", "4-2", nullptr));
        BTN_SH_44->setText(QApplication::translate("MainWindow", "4-4", nullptr));
        BTN_SH_41->setText(QApplication::translate("MainWindow", "4-1", nullptr));
        BTN_SH_43->setText(QApplication::translate("MainWindow", "4-3", nullptr));
        BTN_SH_24->setText(QApplication::translate("MainWindow", "2-4", nullptr));
        BTN_SH_34->setText(QApplication::translate("MainWindow", "3-4", nullptr));
        BTN_SH_23->setText(QApplication::translate("MainWindow", "2-3", nullptr));
        BTN_SH_33->setText(QApplication::translate("MainWindow", "3-3", nullptr));
        BTN_SH_22->setText(QApplication::translate("MainWindow", "2-2", nullptr));
        BTN_SH_32->setText(QApplication::translate("MainWindow", "3-2", nullptr));
        BTN_SH_21->setText(QApplication::translate("MainWindow", "2-1", nullptr));
        BTN_SH_31->setText(QApplication::translate("MainWindow", "3-1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
