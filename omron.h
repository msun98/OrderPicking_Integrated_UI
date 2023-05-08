#ifndef OMRON_H
#define OMRON_H

#include <QObject>
#include <QMouseEvent>
#include <QPoint>
#include <QDrag>
#include <QTimer>

#include <queue>
#include <sstream>
#include <vector>
#include <tbb/concurrent_queue.h>

#include "Common_header.h"
#include "telnetclient.h"
#include "networkthread.h"

#include <opencv2/imgproc.hpp>

class Omron : public QObject
{
    Q_OBJECT
public:
    explicit Omron(QObject *parent = nullptr);

    xyzInfo omron_xy_heading;
    void write_log(Integrated_infomation& Ii, const QString& text);
//    void Omron_Connect_and_initialzation();


    cv::Mat mainwindowMap;
    QTimer *uiTimer;
    QTimer timer;
    int x1;
    int y1;
    int text_1_x,text_1_y,text_1_z;
    queue<tuple<int, int, int>> q;
    cv::Point2d pt1;
    cv::Point2d pt2;
    double x_original;
    double y_original;

    double heading;

    //tbb::concurrent_queue<omron_PosInfo> OmronPos;

    //////////////for drag/////////////
    cv::Point2d pos_Start;
    cv::Point2d pos_End;

    QString textSaved = "";
    QStringList list;
    double img_x;
    double img_y;
    double x;
    double y;
    double theta;

    cv::Mat Drawing_original;
    cv::Mat Drawing;
    void SetRobotInfoText();
    void MoveOmron(double x, double y, double theta);
    void StopOmron();
    void enterPosStart(double x, double y);
    void enterPosEnd(double x, double y);
    void addPoint(QString x, QString y, QString heading);
    void num(QString x, QString y, QString heading);
//    void read(QString filename);
    void sendText();
    void saySomething();
    void dock();
    void undock();
    void stop();
    void moveGoal();
    int check;
    int write = 1;

private:
    bool flag;//도착 플래그

    int state = 1; //스테이트 머신의 상태
//    void read(QString filename);
    QVector <cv::Point2d> point_list;//나중에 헤딩이 필요한 경우 3d로 변경
    QVector<double> vector_x;
    QVector<double> vector_y;
    cv::Mat colored_map;
    cv::Mat Map_original;
    //bool add_flag = false;


    int push_num = 0;
    double mmperpix_x = 0;
    double mmperpix_y = 0;
    double min_x;
    double min_y;

    bool map_flag = false;
    cv::Point p1;
    cv::Point p3;


signals:
    void SIGNAL_LOG_WRITE();
    void completed();

private slots:
//    void UpdateUI();


//    void num(QString x, QString y, QString heading);
//    //void on_MovePoint_clicked();
    //void timeloop();
    //void on_departure_clicked();

    //void on_pushButton_clicked();

//    void mouse_clicked(double x, double y);
//    void mouse_released(double x, double y);


//    void on_UPDATE_UI();
//    void on_push_up_clicked();
//    void on_push_right_clicked();
//    void on_push_left_clicked();
//    void on_push_down_clicked();

};

#endif // OMRON_H
