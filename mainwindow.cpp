#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cv_to_qt.h"
#include "qmylabel.h"

telnetclient  *telentClinetThread;
NetworkThread *networkThread;

//extern telnetclient *telentClinetThread;
//extern NetworkThread *networkThread;

class Integrated_infomation Integrated_info;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    Main_timer = new QTimer(this);
    connect(Main_timer, SIGNAL(timeout()), this, SLOT(Update_UI()));
    Main_timer->start(200);

    obj_RB5    = new Cobot();
    obj_Lift   = new lift();
    obj_Keti   = new Keti_vision();
    obj_Kitech = new Kitech_gripper();
    obj_omron  = new Omron();

    ui->LE_VISION_CMD->setText(QString("REQ,VISION,DETECT"));
    ui->LE_GRIPPER_CMD->setText(QString("R,g,3,0"));

    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts())
        ui->CB_SERIAL_PORT->addItem(port.portName());

    connect_SIG_SLOT();
    _log.PrintLog("OrderPicking Control.\n", ui->TE_GLOBAL_LOG, "green", true);

    ui->LB_RAINBOW_LOGO_2->setScaledContents(true);
    ui->LB_RAINBOW_LOGO_2->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->LB_RAINBOW_LOGO_3->setScaledContents(true);
    ui->LB_RAINBOW_LOGO_3->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->LB_RAINBOW_LOGO_4->setScaledContents(true);
    ui->LB_RAINBOW_LOGO_4->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->LB_RAINBOW_LOGO_5->setScaledContents(true);
    ui->LB_RAINBOW_LOGO_5->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->LB_RAINBOW_LOGO_6->setScaledContents(true);
    ui->LB_RAINBOW_LOGO_6->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    uiTimer = new QTimer(this);
    uiTimer->start(100);
    connect(uiTimer, SIGNAL(timeout()), this, SLOT(on_UPDATE_UI()));

    telentClinetThread = new telnetclient(this);
    telentClinetThread->start();
//    if (telentClinetThread->serverMessage_Flag)
//    {
//        _log.PrintLog("telentClinetThread opened.\n", ui->TE_GLOBAL_LOG, "blue", true);
//    }

    networkThread = new NetworkThread(this);
    networkThread->start();
//    _log.PrintLog("networkThread opened.\n", ui->TE_GLOBAL_LOG, "red", true);


    QString filename("./map/original.txt");
    read(filename);

    connect(ui->LB_OMRON_MAP, SIGNAL(mouse_clicked(double, double)), this, SLOT(mouse_clicked(double, double)));
    connect(ui->LB_OMRON_MAP, SIGNAL(mouse_released(double, double)), this, SLOT(mouse_released(double, double)));

}

MainWindow::~MainWindow()
{
     _log.PrintLog("OrderPicking Control closed.\n", ui->TE_GLOBAL_LOG, "green", true);
    delete ui;
}

void MainWindow::Update_UI()
{
    check_connection();
    check_state_RB5();

    if (!telentClinetThread->serverMessage_Flag)
    {
        _log.PrintLog("telentClinetThread closed.\n", ui->TE_GLOBAL_LOG, "blue", true);
    }

    if (!networkThread->networkThread_Flag)
    {
       _log.PrintLog("networkThread closed.\n", ui->TE_GLOBAL_LOG, "red", true);
    }

    if(Integrated_info.is_keti_est_point_get)
    {
        Integrated_info.is_keti_est_point_get = false;
        QString text = QString::number(Integrated_info.keti_grapsCoord.x) + ', '+ QString::number(Integrated_info.keti_grapsCoord.y) + ', ' + QString::number(Integrated_info.keti_grapsCoord.z);
        ui->LE_VISION_ESIMATED_COORD->setText(text);
    }
    QString text = QString::fromStdString(telentClinetThread->serverMessage);

    if(text != textSaved)
    {
        textSaved = text;
    }
    //cout << telentClinetThread->serverMessage <<endl;


    if(text.length() < 1)
    {
    }
    else
    {
        ui->TE_GLOBAL_LOG->append(text);
        qDebug()<<text;

       list = text.split(" ");
       qDebug()<<list[0];// using list[0] compare word failed or success!

       if (list[0]=="Failed")
        {
           qDebug() << "Failed to creat path...";
           check = 0;
           //cout<<"FFFFF"<<endl;
        }

        else if(list[0]=="Completed")
        {
           qDebug() << "move Point complete!";
           check = 1;
//           emit completed();
           //cout<<"SSSSS"<<endl;
            flag = true; // 로봇의 출발을 알리는 플래그
        }
    }
    telentClinetThread->serverMessage = "";
    SetRobotInfoText();
}

cv::Point p1_old;
cv::Point p3_old;
cv::Point p3_old_resize;
double new_point_x;
double new_point_y;

void MainWindow::on_UPDATE_UI()
{


    cv::Mat Drawing = colored_map.clone();
    p1 = cv::Point(pos_Start.x, pos_Start.y);
    p3 = cv::Point(pos_End.x, pos_End.y);
    new_point_x = p1.x;
    new_point_y = p1.y;

//    cout<<abs(p3.y-p1.y)/ <<endl;

    double hypotenuse = sqrt(pow(p3.x-p1.x,2)+pow(p3.y-p1.y,2));
//    cout<<length<<endl;

//    if (hypotenuse > 43)
//    {
//        double ang = abs(p3.y-p1.y)/ hypotenuse ;
////        double angle = round(asin(ang)*180/3.14);
////        cout<<"angle : "<<angle<<endl;
//    }

//////////////////////////////////////////////////////////////////////////////////////////////////////
    // 실제 차량 측정값.
//    cv::rectangle(Drawing, cv::Rect(cv::Point(round(img_x+30),round(img_y+25)), cv::Point(round(img_x-30), round(img_y-25))), cv::Scalar(0, 0, 255), 1, 8, 0);
    cv::Point ptCenter(round(img_x),round(img_y));
    cv::Size2f size(846/mmperpix_x,592/mmperpix_y);
    cv::RotatedRect rot_rect(ptCenter, size, heading);

    cv::Rect bound_rect = rot_rect.boundingRect();
    cv::rectangle(Drawing, bound_rect, cv::Scalar(0, 0, 255), 1, 8, 0); //omron이 회전함에 따라 자동차 모양도 도는지 확인.

//    cv::rectangle(Drawing, cv::Rect(cv::Point(round(img_x+30),round(img_y+25)),
//                                    cv::Point(round(img_x-30), round(img_y-25))), cv::Scalar(0, 0, 255), 1, 8, 0);


    cv::circle(Drawing, cv::Point(round(img_x),round(img_y)), 2,cv::Scalar(0, 0, 255),4);
    // 차량 헤딩벡터(p1.x,p1.y => 실체 차량의 위치를 넣어야 함.)
    heading = heading*3.14/180;

    if(heading > 0)
    {
       if(heading < 90)
       {
           cv::arrowedLine(Drawing, cv::Point(round(img_x),round(img_y)),
                           cv::Point(round(img_x)+round(30*cos(heading)),round(img_y)-round(30*sin(heading))),
                           cv::Scalar(255, 0, 0),1,cv::LINE_AA,0,0.1);//(y축)*/
       }
       else
       {
            cv::arrowedLine(Drawing, cv::Point(round(img_x),round(img_y)),
                            cv::Point(round(img_x)-round(30*cos(heading)),round(img_y)-round(30*sin(heading))),
                            cv::Scalar(255, 0, 0),1,cv::LINE_AA,0,0.1);//(y축)*/
       }

    }

    else
    {
        heading = - heading;

        if(abs(heading) < 90)
        {
            cv::arrowedLine(Drawing, cv::Point(round(img_x),round(img_y)),
                            cv::Point(round(img_x)+round(30*cos(heading)),round(img_y)+round(30*sin(heading))),
                            cv::Scalar(255, 0, 0),1,cv::LINE_AA,0,0.1);//(y축)*/

        }
        else
        {
             cv::arrowedLine(Drawing, cv::Point(round(img_x),round(img_y)),
                             cv::Point(round(img_x)-round(30*cos(heading)),round(img_y)+round(30*sin(heading))),
                             cv::Scalar(255, 0, 0),1,cv::LINE_AA,0,0.1);//(y축)*/
        }
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////

    double p_now_x = 42 * abs(p1.x-p3.x)/hypotenuse; // 길이 리사이즈x
    double p_now_y = sqrt(pow(42,2)-pow(p_now_x,2));
//    cout<<p_now_x<<","<<p_now_y<<endl;
//    cout<<new_point_x<<endl;

    if (p3_old != p3)
    {
//        cv::line(Drawing, p1, cv::Point(new_point_x,new_point_y), cv::Scalar(0, 0, 0), 2, cv::LINE_AA, 0);
        if(p1.x<p3.x && p1.y>p3.y)
        {
            new_point_x = p1.x+p_now_x;
            new_point_y = p1.y-p_now_y;
        }

        else if(p1.x>p3.x && p1.y>p3.y)
        {
             new_point_x = p1.x-p_now_x;
             new_point_y = p1.y-p_now_y;
        }

        else if(p1.x>p3.x && p1.y<p3.y)
        {
             new_point_x = p1.x-p_now_x;
             new_point_y = p1.y+p_now_y;
        }

        else if(p1.x<p3.x && p1.y<p3.y)
        {
             new_point_x = p1.x+p_now_x;
             new_point_y = p1.y+p_now_y;
        }

        if(heading == 360)
        {
            heading = 0;
            cout<<heading<<endl;
        }

        cv::line(Drawing, p1, cv::Point(new_point_x,new_point_y), cv::Scalar(0, 0, 0), 2, cv::LINE_AA, 0);
        cv::circle(Drawing, p1, 5, cv::Scalar(0,0,255), 4);

        //heading
        ui -> LE_OMRON_HEADING -> setText(QString::number(0));

//        p3_old = p3;
        p3_old = p3;
        p3_old_resize = cv::Point(new_point_x,new_point_y);
        p1_old = p1;

        if(p1 == p3)
        {
//            cout<<"p1 == p3"<<endl;

            heading = heading; // 실제 옴론으로 부터 측정한 값, 이전 옴론의 위치랑 헤딩방향 동일하게 진행
            ui -> LE_OMRON_HEADING -> setText(QString::number(heading));

//            cv::putText(Drawing, "start != end" ,cv::Point(p1.x-20, p1.y-20), 1, 2, cv::Scalar(255, 0, 0), 1, 8);

        }

        else
        {
            // 클릭으로 드래그를 하면 해딩 각도를 지정할 수 있다.
            heading = round(atan2(p3.y-p1.y, p3.x-p1.x)*180/3.14);

            if (heading<0)
            {
                heading = abs(heading);
            }

            else
            {
                if(heading != 0)
                {
                    heading = 360 - heading;
                }
            }

            ui -> LE_OMRON_HEADING -> setText(QString::number(heading));
        }
    }

    else
    {
        if(heading == 360)
        {
            heading = 0;
            cout<<heading<<endl;
        }

        cv::line(Drawing, p1_old, p3_old_resize, cv::Scalar(0, 0, 0), 2, cv::LINE_AA, 0);
        cv::circle(Drawing, p1_old, 5, cv::Scalar(0,0,255), 4);
    }

    mainwindowMap = Drawing.clone();
    ui->LB_OMRON_MAP->setPixmap(QPixmap::fromImage(mat_to_qimage_cpy(Drawing)));
}

void MainWindow::SetRobotInfoText()
{

    ui->te_status->setText(networkThread->status);
    ui->le_battery->setText(QString::number(networkThread->battery));
    ui->le_location->setText(QString::number(networkThread->x) + " , " + QString::number(networkThread->y) + " , " + QString::number(networkThread->heading));

    heading = networkThread->heading;

    if (map_flag == true)
    {
        int rb_x = networkThread->x;
        int rb_y = networkThread->y;

//        cout<<rb_y<<endl;

        img_x = (rb_x-(min_x))/mmperpix_x;
//        (ui->txt->height() - pos_Start.y - 1)
        // 점플립
        //cout<<ui->txt->height()<<endl;
        img_y = (rb_y-(min_y))/mmperpix_y;
//        cout<<img_y<<endl;
        img_y = -img_y+ui->LB_OMRON_MAP->height();
    }

//    ui->txt->setPixmap(QPixmap::fromImage(mat_to_qimage_cpy(Drawing)));
    ui->le_temperature->setText(QString::number(networkThread->temperature));

}

int zero_x = 0;
int zero_y = 0;
int gray = 1;
void MainWindow::read(QString filename) // 데이터 읽음과 동시에 분리.
{
    QFile file(filename);
//    qDebug()<<filename;
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << " Could not open the file for reading";
        return;
    }

    cv::Mat map(ui->LB_OMRON_MAP->height(),ui->LB_OMRON_MAP->width(),CV_8U,cv::Scalar(255));

    QTextStream in(&file);
    QString myText = in.readAll();

//////////////////////점plot//////////////////
    int index = myText.indexOf("DATA", Qt::CaseInsensitive)+5; //data의 첫번째 문자 위치 544250
    QString str2 = myText.mid(index);
    QStringList x = str2.split("\n"); // x
    QVector <cv::Point2d> point_list;
//    cv::Mat map(ui->txt->height(),ui->txt->width(),CV_8U,cv::Scalar(255));

    ////min max 찾는 for
    for (int i=0; i<x.size()-1; i++)
    {
       QStringList x_1; //선언을 함.
       x_1 = x[i].split(" ");

       x_original = x_1[0].toDouble();
       y_original = x_1[1].toDouble();

       vector_x.push_back(x_original);
       vector_y.push_back(y_original);
    }

    double max_x = *max_element(vector_x.begin(), vector_x.end());
    double max_y = *max_element(vector_y.begin(), vector_y.end());
    min_x = *min_element(vector_x.begin(), vector_x.end());
    min_y = *min_element(vector_y.begin(), vector_y.end());

    mmperpix_x = round((max_x-min_x)/ui->LB_OMRON_MAP->width());
    mmperpix_y = round((max_y-min_y)/ui->LB_OMRON_MAP->height());

    for (int i=0; i<x.size()-1; i++)
    {
       QStringList x_1; //선언을 함.
       x_1 = x[i].split(" ");

       double x_original= x_1[0].toDouble();
       double y_original= x_1[1].toDouble();


// Robot(real) -> img(pixel)

       double I_x = (x_original-(min_x))/mmperpix_x;
       double I_y = (y_original-(min_y))/mmperpix_y;

       if (x_original==0)
       {
           zero_x = I_x;
       }

       if (y_original==0)
       {
           zero_y = I_y;
           cout<<x_original<<","<<y_original<<endl;
       }

       point_list.push_back(cv::Point2d(I_x,I_y));
       map.ptr<uchar>(point_list[i].y)[int(point_list[i].x)]=0;

    }
    cv::flip(map,map,0);//이미지 상하반전
    cv::cvtColor(map, colored_map, cv::COLOR_GRAY2BGR);

//    cout<<"zero_x"<<zero_x<<endl;



    //////////////////////선plot/////////////////////////////
    /// start_index_line
    int start_index_line = myText.indexOf("LINE", Qt::CaseInsensitive)+6; //data의 첫번째 문자 위치 544250
    int data_index_line = myText.indexOf("DATA", Qt::CaseInsensitive); //data의 첫번째 문자 위치 544250

//     qDebug() << "Start index: " << start_index_line;
//     qDebug() << "Data index: " << data_index_line;


     QString LineString = myText.mid(start_index_line, data_index_line-start_index_line+1);
     QStringList line = LineString.split("\n"); // x

     ////min max 찾는 for
     for (int i=0; i<line.size()-1; i++)
     {
//        QStringList list; //선언을 함.
        QStringList list_line = line[i].split(" ");

        cv::line(colored_map, cv::Point((list_line[0].toDouble()-(min_x))/mmperpix_x,-(list_line[1].toDouble()-(min_y))/mmperpix_y+ui->LB_OMRON_MAP->height()),
                         cv::Point((list_line[2].toDouble()-(min_x))/mmperpix_x,-(list_line[3].toDouble()-(min_y))/mmperpix_y+ui->LB_OMRON_MAP->height()),
                         cv::Scalar(0, 0, 0), 2, cv::LINE_4, 0);
     }

////////////////////////////////////////////////////////
//    Drawing_original = colored_map.clone(); //덮어쓰기 할 때 쓰려고 만듦.
    if (write == 1) // 최초에 map png 저장하기 위해 생성.
    {
       //유진에서 map image 에 원점과 x,y축이 없는 것이 좋다함.

        cv::Mat ori;
        cv::Mat img_threshold;
        cv::cvtColor(colored_map, ori, cv::COLOR_BGR2GRAY);
        threshold(ori, img_threshold, 200, 255, cv::THRESH_BINARY);
//        imshow("bin",img_threshold);
        cv::imwrite("./map/original.png",img_threshold);

        write = 2;
    }
    cv::circle(colored_map, cv::Point(zero_x,ui->LB_OMRON_MAP->height()-zero_y), 2, cv::Scalar(255, 0, 255),2,-1);//원점 좌표
    cv::arrowedLine(colored_map, cv::Point(0,-zero_y+ui->LB_OMRON_MAP->height()),cv::Point(ui->LB_OMRON_MAP->width()-4,-zero_y+ui->LB_OMRON_MAP->height()),
                    cv::Scalar(0, 0, 255),1,cv::LINE_8,0,0.03);//(x축)
    cv::arrowedLine(colored_map, cv::Point(zero_x,ui->LB_OMRON_MAP->height()), cv::Point(zero_x,3),cv::Scalar(255, 0, 0),1,cv::LINE_8,0,0.05);//(y축)
    Drawing_original = colored_map.clone(); //덮어쓰기 할 때 쓰려고 만듦.

    ui->LB_OMRON_MAP->setPixmap(QPixmap::fromImage(mat_to_qimage_cpy(colored_map)));

    map_flag = true;

    file.close();
}


void MainWindow::mouse_clicked(double x, double y)
{
    pos_Start.x = x;
    pos_Start.y = y;

    double r_x = (pos_Start.x * mmperpix_x)+(min_x)+30-2-14;//오차 수정
//    double r_x = pos_Start.x * mmperpix￣_x;//오차 수정
//    double r_y = (ui->txt->height() - pos_Start.y - 1) * mmperpix_y-abs(min_y) + 10-4;//오차수정 (flip 모드로 변환시켰기 때문에 변환 과정 필요)
    double r_y = (ui->LB_OMRON_MAP->height() - pos_Start.y - 1) * mmperpix_y + (min_y) + 30+5;//오차수정 (flip 모드로 변환시켰기 때문에 변환 과정 필요)

        ui -> LE_OMRON_X -> setText(QString::number(r_x));
        ui -> LE_OMRON_Y -> setText(QString::number(r_y));
//        color_flag = 1;


        if (r_x == 0)
        {
        }

        if (r_y == 0)
        {
            cout<<pt1.y<<endl;
        }


}

void MainWindow::mouse_released(double x, double y)
{
    pos_End.x = x;
    pos_End.y = y;
}

void MainWindow::Update_Log()
{
    _log.PrintLog(Integrated_info.Log_info.toStdString(), ui->TE_GLOBAL_LOG, "black", false);
    Integrated_info.Log_info.clear();
}

void MainWindow::on_BTN_TE_GLOBAL_CLEAR_clicked()
{
    ui->TE_GLOBAL_LOG->clear();
}

void MainWindow::on_SLIDER_RB5_SPEED_valueChanged(int value)
{
    ui->SB_RB5_SPEED->setValue(value);

    QString text = "";
    text.append(QString::number(value));
    text.append(" %");
    ui->label_7->setText(text);

    if(Integrated_info.init_rb5 == ALL_CONNECT_AND_INIT_COMPLETE)
    {
        obj_RB5->_mslider_Spd  = value/100.0;
        obj_RB5->speed_changed = true;
    }
}

void MainWindow::on_SB_RB5_SPEED_valueChanged(int arg1)
{
    ui->SLIDER_RB5_SPEED->setValue(arg1);

    QString text = "";
    text.append(QString::number(arg1));
    text.append(" %");
    ui->label_7->setText(text);

    if(Integrated_info.init_rb5 == ALL_CONNECT_AND_INIT_COMPLETE)
    {
        obj_RB5->_mslider_Spd  = arg1 / 100.0;
        obj_RB5->speed_changed = true;
    }
}

void MainWindow::on_BTN_CONNECT_OMRON_clicked()
{
//    obj_omron->Omron_Connect_and_initialzation();
}

void MainWindow::on_BTN_CONNECT_LIFT_clicked()
{
    if(ui->CB_SERIAL_PORT->currentText() != "")
        obj_Lift->Lift_Connect(ui->CB_SERIAL_PORT->currentText());
    else
        _log.PrintLog("[lift] port not avaliable.", ui->TE_GLOBAL_LOG, "red", false);
}

void MainWindow::on_BTN_LIFT_SERIAL_OPEN_clicked()
{
    if(ui->CB_SERIAL_PORT->currentText() != "")
        obj_Lift->Lift_Connect(ui->CB_SERIAL_PORT->currentText());
    else
        _log.PrintLog("[lift] port not avaliable.", ui->TE_GLOBAL_LOG, "red", false);
}

void MainWindow::on_BTN_LIFT_HOMING_clicked()
{
    obj_Lift->Lift_homing(true);
}


void MainWindow::on_BTN_CONNECT_RB5_clicked()
{
    obj_RB5->RB5_Connect_and_initialzation();
}

void MainWindow::on_BTN_CONNECT_VISION_clicked()
{
    obj_Keti->Vision_Connect();
}

void MainWindow::on_BTN_CONNECT_GRIPPER_clicked()
{
    obj_Kitech->Gripper_Connect();
}

void MainWindow::on_BTN_GLOBAL_INIT_clicked()
{

}


void MainWindow::check_state_LIFT()
{

}

void MainWindow::connect_SIG_SLOT()
{
    connect_Log_system();

    // OMRON
    connect(ui->LB_OMRON_MAP, SIGNAL(mouse_clicked(double, double)), this, SLOT(mouse_clicked(double, double)));
    connect(ui->LB_OMRON_MAP, SIGNAL(mouse_released(double, double)), this, SLOT(mouse_released(double, double)));
}

void MainWindow::connect_Log_system()
{
    connect(obj_RB5, SIGNAL(SIGNAL_LOG_WRITE()), this, SLOT(Update_Log()));
    connect(obj_Keti, SIGNAL(SIGNAL_LOG_WRITE()), this, SLOT(Update_Log()));
    connect(obj_Kitech, SIGNAL(SIGNAL_LOG_WRITE()), this, SLOT(Update_Log()));
    connect(obj_Lift, SIGNAL(SIGNAL_LOG_WRITE()), this, SLOT(Update_Log()));
    connect(obj_omron, SIGNAL(SIGNAL_LOG_WRITE()), this, SLOT(Update_Log()));
}

void MainWindow::on_BTN_SENARIO_CUSTOM_ADD_clicked()
{
    QString text = ui->CB_SENARIO_CUSTOM_LIST->currentText();
    ui->LW_SENARIO_CUSTOM_LIST->addItem(text);
}

void MainWindow::on_BTN_SENARIO_CUSTOM_DEL_clicked()
{
    QListWidgetItem *it = ui->LW_SENARIO_CUSTOM_LIST->takeItem(ui->LW_SENARIO_CUSTOM_LIST->currentRow());
    delete it;
}

void MainWindow::on_BTN_SENARIO_EXECUTION_BASIC_clicked()
{
    //Senario_list.push(FSM_State::OMRON_MOVE_GOAL_1);
}

void MainWindow::on_BTN_SENARIO_EXECUTION_CUSTOM_clicked()
{
    // Queue List custom
    if(FSM_Thread == NULL)
    {
        FSM_Flag = true;
        State_Machine_Flag = 0;
        FSM_Thread = new std::thread(&MainWindow::FSM_Loop, this);

        get_FSM_State_From_QListWidget(Senario_list, ui);
    }
    else
    {
        qDebug() << "FSM Flag Not Nullptr";
    }
}

//void MainWindow::mouse_clicked(double x, double y)
//{
//    obj_omron->pos_Start.x = x;
//    obj_omron->pos_Start.y = y;
//    obj_omron->enterPosStart(x, y);
//}

//void MainWindow::mouse_released(double x, double y)
//{
//    obj_omron->pos_End.x = x;
//    obj_omron->pos_End.y = y;
//    obj_omron->enterPosEnd(x, y);
//}

void MainWindow::on_BTN_VISION_CMD_WRITE_clicked()
{
    if(Integrated_info.init_vision == true)
    {
        auto text = ui->LE_VISION_CMD->text();
        _log.PrintLog(text.toStdString(), ui->TE_GLOBAL_LOG, "green", true);
        QByteArray br = text.toUtf8();
        obj_Keti->Keti_Client->write(br);
    }
    else
    {
        _log.PrintLog("Not connected KETI yet.", ui->TE_GLOBAL_LOG, "red", true);
    }
}

void MainWindow::on_BTN_GRIPPER_CMD_WRITE_clicked()
{
    // all cmd write in hand
    if(Integrated_info.init_gripper == true)
    {
        auto text = ui->LE_GRIPPER_CMD->text();
        QString Log = "[Gripper] cmd : " + text;
        QByteArray br = text.toUtf8();

        _log.PrintLog(Log.toStdString(), ui->TE_GLOBAL_LOG, "green", true);
        obj_Kitech->Kitech_Client->write(br);
    }
    else
    {
        _log.PrintLog("Not connected KITECH yet.", ui->TE_GLOBAL_LOG, "red", true);
    }
}

void MainWindow::on_BTN_GRIPPER_UNFOLD_clicked()
{
    // preset unfold(gripper ready) pos cmd
    if(Integrated_info.init_gripper == true)
    {
        QString text("R,x,9,0");
        QString Log = "[Gripper] cmd : " + text;
        QByteArray br = text.toUtf8();

        _log.PrintLog(Log.toStdString(), ui->TE_GLOBAL_LOG, "green", true);
        obj_Kitech->Kitech_Client->write(br);
    }
    else
    {
        _log.PrintLog("Not connected KITECH yet.", ui->TE_GLOBAL_LOG, "red", true);
    }
}

void MainWindow::on_BTN_GRIPPER_GRAP_clicked()
{
    // preset graps pos cmd in free grapMode & power
    if(Integrated_info.init_gripper == true)
    {
        auto grap = ui->CB_GRIPPER_GRAPS->currentText();
        auto powe = ui->CB_GRIPPER_POWER->currentText();

        QString text = "G," + grap + "," + powe + ",0";
        QString Log = "[Gripper] cmd : " + text;
        QByteArray br = text.toUtf8();

        _log.PrintLog(Log.toStdString(), ui->TE_GLOBAL_LOG, "green", true);
        obj_Kitech->Kitech_Client->write(br);
    }
    else
    {
        _log.PrintLog("Not connected KITECH yet.", ui->TE_GLOBAL_LOG, "red", true);
    }
}

void MainWindow::on_BTN_GRIPPER_VISION_clicked()
{
    // preset vision pos cmd
    if(Integrated_info.init_gripper == true)
    {
        QString text("R,x,3,0");
        QString Log = "[Gripper] cmd : " + text;
        QByteArray br = text.toUtf8();

        _log.PrintLog(Log.toStdString(), ui->TE_GLOBAL_LOG, "green", true);
        obj_Kitech->Kitech_Client->write(br);
    }
    else
    {
        _log.PrintLog("Not connected KITECH yet.", ui->TE_GLOBAL_LOG, "red", true);
    }
}

void MainWindow::on_CB_GRIPPER_GE_CMD_WRITE_clicked()
{
    // preset gripper pos cmd in free mode & grapMode & power
    if(Integrated_info.init_gripper == true)
    {
        auto mode = ui->CB_GRIPPER_GE_MODE->currentText();
        auto grap = ui->CB_GRIPPER_GE_GRAPS->currentText();
        auto powe = ui->CB_GRIPPER_GE_POWER->currentText();

        QString text = mode + "," + grap + "," + powe + ",0";
        QString Log = "[Gripper] cmd : " + text;
        QByteArray br = text.toUtf8();

        _log.PrintLog(Log.toStdString(), ui->TE_GLOBAL_LOG, "green", true);
        obj_Kitech->Kitech_Client->write(br);
    }
    else
    {
        _log.PrintLog("Not connected KITECH yet.", ui->TE_GLOBAL_LOG, "red", true);
    }
}

void MainWindow::on_BTN_SET_IP_PORT_KETI_clicked()
{
    if(ui->LE_IP_KETI->text() != "" && ui->LE_PORT_KETI->text() != "")
    {
        obj_Keti->Keti_Client->abort();

        usleep(100*100);

        QString ip   = ui->LE_IP_KETI->text();
        int     port = ui->LE_PORT_KETI->text().toInt();
        obj_Keti->Keti_Client->connectToHost(QHostAddress(ip), port);

        _log.PrintLog("[Vision] reconnection new IP & port.", ui->TE_GLOBAL_LOG, "black", true);

    }
    else
    {
        _log.PrintLog("[Vision] put IP, port.", ui->TE_GLOBAL_LOG, "red", true);
    }
}

void MainWindow::on_BTN_SET_IP_PORT_KITECH_clicked()
{
    if(ui->LE_IP_KITECH->text() != "" && ui->LE_PORT_KITECH->text() != "")
    {
        obj_Kitech->Kitech_Client->abort();

        usleep(100*100);

        QString ip   = ui->LE_IP_KITECH->text();
        int     port = ui->LE_PORT_KITECH->text().toInt();
        obj_Kitech->Kitech_Client->connectToHost(QHostAddress(ip), port);

        _log.PrintLog("[Gripper] reconnection new IP & port.", ui->TE_GLOBAL_LOG, "black", true);

    }
    else
    {
        _log.PrintLog("[Gripper] put IP, port.", ui->TE_GLOBAL_LOG, "red", true);
    }
}

// vision to node
void MainWindow::on_BTN_SET_CALIB_T_V2N_clicked()
{
    if(ui->LE_VISION_CALIB_Tx_V2N->text() != "")
    {
        auto tx = ui->LE_VISION_CALIB_Tx_V2N->text();
        auto ty = ui->LE_VISION_CALIB_Ty_V2N->text();
        auto tz = ui->LE_VISION_CALIB_Tz_V2N->text();

        Integrated_info.CALIB_v2n.x = tx.toFloat();
        Integrated_info.CALIB_v2n.y = ty.toFloat();
        Integrated_info.CALIB_v2n.z = tz.toFloat();
    }
    else
        _log.PrintLog("put cali info.", ui->TE_GLOBAL_LOG, "red", true);
}

// node to end-effect
void MainWindow::on_BTN_SET_CALIB_T_N2E_clicked()
{
    if(ui->LE_VISION_CALIB_Rx_N2E->text() != "")
    {
        auto Rx = ui->LE_VISION_CALIB_Rx_N2E->text();
        auto Ry = ui->LE_VISION_CALIB_Ry_N2E->text();
        auto Rz = ui->LE_VISION_CALIB_Rz_N2E->text();

        auto tx = ui->LE_VISION_CALIB_Tx_N2E->text();
        auto ty = ui->LE_VISION_CALIB_Ty_N2E->text();
        auto tz = ui->LE_VISION_CALIB_Tz_N2E->text();

        Integrated_info.CALIB_n2e.rx = Rx.toFloat();
        Integrated_info.CALIB_n2e.ry = Ry.toFloat();
        Integrated_info.CALIB_n2e.rz = Rz.toFloat();

        Integrated_info.CALIB_n2e.x = tx.toFloat();
        Integrated_info.CALIB_n2e.y = ty.toFloat();
        Integrated_info.CALIB_n2e.z = tz.toFloat();
    }

    else
        _log.PrintLog("put cali info.", ui->TE_GLOBAL_LOG, "red", true);
}

void MainWindow::on_BTN_VISION_OUT_SET_clicked()
{
    if(ui->LE_VISION_ESIMATED_COORD->text() == "")
    {
        _log.PrintLog("put est point.", ui->TE_GLOBAL_LOG, "red", true);
        return;
    }

    auto coord = ui->LE_VISION_ESIMATED_COORD->text();
    auto coords = coord.split(',');

    qDebug() << QString(coords.at(0)).toFloat();
    qDebug() << coord;
    qDebug() << QString(coords.at(2)).toFloat();

    Integrated_info.keti_grapsCoord.x = QString(coords.at(0)).toFloat();
    Integrated_info.keti_grapsCoord.y = QString(coords.at(1)).toFloat();
    Integrated_info.keti_grapsCoord.z = QString(coords.at(2)).toFloat();

    QString path = "VISION_ESTIMATED_POINTS.json";
    obj_Keti->saveEstimated_GrapsPoints(path);

    _log.PrintLog("[VISION] set successed.", ui->TE_GLOBAL_LOG, "black", true);

}

void MainWindow::on_BTN_VISION_OUT_SAVE_clicked()
{
    QString path = "VISION_ESTIMATED_POINTS.json";
    obj_Keti->saveEstimated_GrapsPoints(path);
    _log.PrintLog("[VISION] save est points", ui->TE_GLOBAL_LOG, "black", true);
}

void MainWindow::on_BTN_VISION_OUT_LOAD_clicked()
{
    QString path = "VISION_ESTIMATED_POINTS.json";
    obj_Keti->loadEstimated_GrapsPoints(path);

    QString text = QString::number(Integrated_info.keti_grapsCoord.x) + ","+ QString::number(Integrated_info.keti_grapsCoord.y) + "," + QString::number(Integrated_info.keti_grapsCoord.z);
    ui->LE_VISION_ESIMATED_COORD->setText(text);
    _log.PrintLog("[VISION] load est points", ui->TE_GLOBAL_LOG, "black", true);
}

void MainWindow::on_BTN_OMRON_ADD_clicked()
{
    QString x       =  ui->LE_OMRON_X->text();
    QString y       =  ui->LE_OMRON_Y->text();
    QString heading =  ui->LE_OMRON_HEADING->text();
    obj_omron->addPoint(x, y, heading);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief RB5
///////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
/// \brief BASIC RB5
//////////////////////////////////////////////////////////////////
void MainWindow::check_state_RB5()
{
    if(Integrated_info.RB5_mode == false)
        ui->BTN_RB5_MODE->setText("simul.");
    else
        ui->BTN_RB5_MODE->setText("real.");

    // check Move something
    // state of robot motion [1:idle  2:paused or stopped by accident  3: moving]
    if(obj_RB5->systemStat.sdata.robot_state == 3)
        ui->LE_RB5_MOVE_INFO->setStyleSheet("background-color:green");
    else
        ui->LE_RB5_MOVE_INFO->setStyleSheet("background-color:red");

    if(Integrated_info.lifts.is_lift_move == true)
        ui->LE_LIFT_MOVE_INFO->setStyleSheet("background-color:green");
    else
        ui->LE_LIFT_MOVE_INFO->setStyleSheet("background-color:red");

    if(Integrated_info.omrons.is_omron_move == true)
        ui->LE_OMRON_MOVE_INFO->setStyleSheet("background-color:green");
    else
        ui->LE_OMRON_MOVE_INFO->setStyleSheet("background-color:red");


    QString text = "";
    text.append(QString::number(obj_RB5->systemStat.sdata.default_speed * 100));
    text.append(" %");
    ui->label_41->setText(text);

    ui->LE_JOINT_1->setText(QString::number(Integrated_info.joints.joint_1));
    ui->LE_JOINT_2->setText(QString::number(Integrated_info.joints.joint_2));
    ui->LE_JOINT_3->setText(QString::number(Integrated_info.joints.joint_3));
    ui->LE_JOINT_4->setText(QString::number(Integrated_info.joints.joint_4));
    ui->LE_JOINT_5->setText(QString::number(Integrated_info.joints.joint_5));
    ui->LE_JOINT_6->setText(QString::number(Integrated_info.joints.joint_6));

    ui->LE_RB5_X->setText(QString::number(Integrated_info.tcps.x));
    ui->LE_RB5_Y->setText(QString::number(Integrated_info.tcps.y));
    ui->LE_RB5_Z->setText(QString::number(Integrated_info.tcps.z));
    ui->LE_RB5_RX->setText(QString::number(Integrated_info.tcps.rx));
    ui->LE_RB5_RY->setText(QString::number(Integrated_info.tcps.ry));
    ui->LE_RB5_RZ->setText(QString::number(Integrated_info.tcps.rz));
}

void MainWindow::on_BTN_RB5_MOVE_INIT_clicked()
{
    obj_RB5->MoveJoint_specific_pos("RB5_INIT_POS.json");
}

void MainWindow::on_BTN_RB5_MOVE_VISION_clicked()
{
    obj_RB5->MoveJoint_specific_pos("RB5_VISION_POS.json");
}

void MainWindow::on_BTN_RB5_MOVE_GRIPPER_READY_clicked()
{
    obj_RB5->MoveJoint_specific_pos("RB5_GRIPPER_READY_POS.json");
}

void MainWindow::on_BTN_RB5_MOVE_GRIPPER_GRAPS_clicked()
{
    obj_RB5->MoveJoint_specific_pos("RB5_GRIPPER_GRAPS_POS.json");
}

void MainWindow::on_BTN_RB5_MOVE_EXTRA_1_clicked()
{
    obj_RB5->MoveJoint_specific_pos("RB5_EXTRA_1_POS.json");
}

void MainWindow::on_BTN_RB5_MOVE_EXTRA_2_clicked()
{
    obj_RB5->MoveJoint_specific_pos("RB5_EXTRA_2_POS.json");
}

void MainWindow::on_BTN_RB5_SAVE_INIT_clicked()
{
    obj_RB5->SaveJoint_specific_pos("RB5_INIT_POS.json");
}

void MainWindow::on_BTN_RB5_SAVE_VISION_clicked()
{
    obj_RB5->SaveJoint_specific_pos("RB5_VISION_POS.json");
}

void MainWindow::on_BTN_RB5_SAVE_GRIPPER_READY_clicked()
{
    obj_RB5->SaveJoint_specific_pos("RB5_GRIPPER_READY_POS.json");
}

void MainWindow::on_BTN_RB5_SAVE_GRIPPER_GRAPS_clicked()
{
    obj_RB5->SaveJoint_specific_pos("RB5_GRIPPER_GRAPS_POS.json");
}

void MainWindow::on_BTN_RB5_SAVE_EXTRA_1_clicked()
{
    obj_RB5->SaveJoint_specific_pos("RB5_EXTRA_1_POS.json");
}

void MainWindow::on_BTN_RB5_SAVE_EXTRA_2_clicked()
{
    obj_RB5->SaveJoint_specific_pos("RB5_EXTRA_2_POS.json");
}

void MainWindow::on_BTN_RB5_PASUE_clicked()
{
    obj_RB5->MotionPause();
}

void MainWindow::on_BTN_RB5_RESUME_clicked()
{
    obj_RB5->MotionResume();
}

void MainWindow::on_BTN_RB5_HOLT_clicked()
{
    obj_RB5->MotionHalt();
}

void MainWindow::on_BTN_RB5_MODE_clicked()
{
    obj_RB5->RB5_MODE_CHANGE();
}

//////////////////////////////////////////////////////////////////
/// \brief GRAPS POINTS & CALIBRATION
//////////////////////////////////////////////////////////////////
void MainWindow::on_BTN_RB5_MOVE_GRAPS_POINT_clicked()
{
    if(Integrated_info.CALIB_n2e.x == -1 || Integrated_info.CALIB_v2n.x == -1)
    {
        _log.PrintLog("[CALIB] need cali info", ui->TE_GLOBAL_LOG, "red", true);
        return;
    }

    obj_RB5->MoveTCP(Integrated_info.GrapsPoint.x, Integrated_info.GrapsPoint.y, Integrated_info.GrapsPoint.z, Integrated_info.GrapsPoint.rx,
                     Integrated_info.GrapsPoint.ry, Integrated_info.GrapsPoint.rz, -1, -1);
}

void MainWindow::on_BTN_RB5_CALC_GRAPS_POINT_clicked()
{
    if(Integrated_info.keti_grapsCoord.x == -1)
    {
        _log.PrintLog("[CALIB] need est points", ui->TE_GLOBAL_LOG, "red", true);
        return;
    }

    if(Integrated_info.CALIB_n2e.x == -1 || Integrated_info.CALIB_v2n.x == -1)
    {
        _log.PrintLog("[CALIB] need cali info", ui->TE_GLOBAL_LOG, "red", true);
        return;
    }

    Integrated_info.GrapsPoint = obj_RB5->calcCalibration(Integrated_info.keti_grapsCoord, Integrated_info.CALIB_v2n, Integrated_info.CALIB_n2e);

    ui->LE_GRAPS_POINT_X->setText(QString::number(Integrated_info.GrapsPoint.x));
    ui->LE_GRAPS_POINT_Y->setText(QString::number(Integrated_info.GrapsPoint.y));
    ui->LE_GRAPS_POINT_Z->setText(QString::number(Integrated_info.GrapsPoint.z));
    ui->LE_GRAPS_POINT_Rx->setText(QString::number(Integrated_info.GrapsPoint.rx));
    ui->LE_GRAPS_POINT_Ry->setText(QString::number(Integrated_info.GrapsPoint.ry));
    ui->LE_GRAPS_POINT_Rz->setText(QString::number(Integrated_info.GrapsPoint.rz));

    settings.WriteSettingFile_CALIB("GrapsPoint.json", Integrated_info.GrapsPoint);
}


void MainWindow::on_BTN_SET_GRAPS_POINT_clicked()
{
    if(ui->LE_GRAPS_POINT_X->text() == "")
    {
        _log.PrintLog("[CALIB] need graps point", ui->TE_GLOBAL_LOG, "red", true);
        return;
    }

    Integrated_info.GrapsPoint.x  = ui->LE_GRAPS_POINT_X->text().toFloat();
    Integrated_info.GrapsPoint.y  = ui->LE_GRAPS_POINT_Y->text().toFloat();
    Integrated_info.GrapsPoint.z  = ui->LE_GRAPS_POINT_Z->text().toFloat();
    Integrated_info.GrapsPoint.rx = ui->LE_GRAPS_POINT_Rx->text().toFloat();
    Integrated_info.GrapsPoint.ry = ui->LE_GRAPS_POINT_Ry->text().toFloat();
    Integrated_info.GrapsPoint.rz = ui->LE_GRAPS_POINT_Rz->text().toFloat();

    settings.WriteSettingFile_CALIB("GrapsPoint.json", Integrated_info.GrapsPoint);
    _log.PrintLog("[CALIB] set graps point", ui->TE_GLOBAL_LOG, "black", true);

}

void MainWindow::on_BTN_LOAD_GRAPS_POINT_clicked()
{
    if(ui->LE_GRAPS_POINT_X->text() == "")
    {
        _log.PrintLog("[CALIB] need graps point", ui->TE_GLOBAL_LOG, "red", true);
        return;
    }

    settings.ReadSettingFile_CALIB("GrapsPoint.json", Integrated_info.GrapsPoint);
    _log.PrintLog("[CALIB] load graps point", ui->TE_GLOBAL_LOG, "black", true);

    ui->LE_GRAPS_POINT_X->setText(QString::number(Integrated_info.GrapsPoint.x));
    ui->LE_GRAPS_POINT_Y->setText(QString::number(Integrated_info.GrapsPoint.y));
    ui->LE_GRAPS_POINT_Z->setText(QString::number(Integrated_info.GrapsPoint.z));
    ui->LE_GRAPS_POINT_Rx->setText(QString::number(Integrated_info.GrapsPoint.rx));
    ui->LE_GRAPS_POINT_Ry->setText(QString::number(Integrated_info.GrapsPoint.ry));
    ui->LE_GRAPS_POINT_Rz->setText(QString::number(Integrated_info.GrapsPoint.rz));

}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief FSM
///////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::get_FSM_State_From_QListWidget(std::queue<int>& list, Ui::MainWindow *& ui)
{

    for(int i=0; i<ui->LW_SENARIO_CUSTOM_LIST->count(); ++i)
    {
        QString state =  ui->LW_SENARIO_CUSTOM_LIST->item(i)->text();

        if(state == "[OMRON]  MOVE GOAL1")
        {
            list.push(FSM_State::OMRON_MOVE_GOAL_1);
        }
        else if(state == "[OMRON]  MOVE GOAL 2")
        {
            list.push(FSM_State::OMRON_MOVE_GOAL_2);
        }
        else if(state == "[OMRON]  MOVE INIT LOCATION")
        {
            list.push(FSM_State::OMRON_MOVE_START);
        }
        else if(state == "[OMRON]  MOVE EXTRA LOCATION")
        {

        }
        else if(state == "[RB5]      MOVE INIT POS")
        {
            list.push(FSM_State::RB5_MOVE_INIT);
        }
        else if(state == "[RB5]      MOVE VISION POS")
        {
            list.push(FSM_State::RB5_MOVE_VISION);
        }
        else if(state == "[RB5]      MOVE GRIPPER READY POS")
        {
            list.push(FSM_State::RB5_MOVE_GRIPPER_READY);
        }
        else if(state == "[RB5]      MOVE GRIPPER GRAPS POS")
        {
            list.push(FSM_State::RB5_MOVE_GRIPPER_GRAPS);
        }
        else if(state == "[LIFT]      MOVE TOP")
        {
            list.push(FSM_State::LIFT_MOVE_TOP);
        }
        else if(state == "[LIFT]      MOVE MID")
        {
            list.push(FSM_State::LIFT_MOVE_MID);
        }
        else if(state == "[LIFT]      MOVE BOT")
        {
            list.push(FSM_State::LIFT_MOVE_BOT);
        }
    }
}


void MainWindow::FSM_Loop()
{
    std::queue<int> List_queue = Senario_list;

    while(FSM_Flag)
    {
        if(STAT == FSM_State::STANBY)
        {
            if(!List_queue.empty())
            {
                STAT = List_queue.front();
                List_queue.pop();
            }

        }
        else if(STAT == FSM_State::OMRON_MOVE_START)
        {

        }
        else if(STAT == FSM_State::OMRON_MOVE_GOAL_1)
        {

        }
        else if(STAT == FSM_State::OMRON_MOVE_GOAL_2)
        {

        }
        else if(STAT == FSM_State::RB5_MOVE_INIT)
        {
            obj_RB5->MoveJoint_specific_pos("INIT");

            if(obj_RB5->systemStat.sdata.robot_state == RB5_idle)
            {
                STAT = FSM_State::STANBY;
            }
        }
        else if(STAT == FSM_State::RB5_MOVE_VISION)
        {
            obj_RB5->MoveJoint_specific_pos("VISION");

            if(obj_RB5->systemStat.sdata.robot_state == RB5_idle)
            {
                STAT = FSM_State::STANBY;
            }
        }
        else if(STAT == FSM_State::RB5_MOVE_GRIPPER_READY)
        {
            obj_RB5->MoveJoint_specific_pos("GRIPPER_READY");

            if(obj_RB5->systemStat.sdata.robot_state == RB5_idle)
            {
                STAT = FSM_State::STANBY;
            }
        }
        else if(STAT == FSM_State::RB5_MOVE_GRIPPER_GRAPS)
        {
            obj_RB5->MoveJoint_specific_pos("GRIPPER_GRAPS");

            if(obj_RB5->systemStat.sdata.robot_state == RB5_idle)
            {
                STAT = FSM_State::STANBY;
            }
        }
        else if(STAT == FSM_State::LIFT_MOVE_TOP)
        {
            //obj_Lift->Lift_MOVE_UP();
            if(1)
            {
                STAT = FSM_State::STANBY;
            }
        }
        else if(STAT == FSM_State::LIFT_MOVE_MID)
        {
            //obj_Lift->Lift_MOVE_UP();
            if(1)
            {
                STAT = FSM_State::STANBY;
            }
        }
        else if(STAT == FSM_State::LIFT_MOVE_BOT)
        {
            //obj_Lift->Lift_MOVE_UP();
            if(1)
            {
                STAT = FSM_State::STANBY;
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief STATUS CHECK
///////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_BTN_CHECK_SOCKET_STATUS_clicked()
{
    qDebug() << "CHECK_SOCKET_STATUS_clicked";
    int state_RB5_CMD = obj_RB5->cmdSocket.state();
    switch (state_RB5_CMD)
    {
        case QTcpSocket::UnconnectedState : // The socket is not connected.
            _log.PrintLog("[RB5] CMD socket is not connected.\n", ui->TE_GLOBAL_LOG, "red", false);
        break;
        case QTcpSocket::HostLookupState : // The socket is performing a host name lookup.
            _log.PrintLog("[RB5] CMD socket is performing a host name lookup.\n", ui->TE_GLOBAL_LOG, "black", false);
        break;
        case QTcpSocket::ConnectingState : // The socket has started establishing a connection.
            _log.PrintLog("[RB5] CMD socket has started establishing a connection.\n", ui->TE_GLOBAL_LOG, "black", false);
        break;
        case QTcpSocket::ConnectedState : // A connection is established.
            _log.PrintLog("[RB5] CMD socket is established.\n", ui->TE_GLOBAL_LOG, "green", false);
        break;
        case QTcpSocket::BoundState : // The socket is bound to an address and port.
            _log.PrintLog("[RB5] CMD socket is bound to an address and port.\n", ui->TE_GLOBAL_LOG, "black", false);
        break;
        case QTcpSocket::ClosingState : // The socket is about to close (data may still be waiting to be written).
            _log.PrintLog("[RB5] CMD socket is about to close.\n", ui->TE_GLOBAL_LOG, "black", false);
        break;
    }

    int state_RB5_DATA = obj_RB5->dataSocket.state();
    switch (state_RB5_DATA)
    {
        case QTcpSocket::UnconnectedState : // The socket is not connected.
            _log.PrintLog("[RB5] DATA socket is not connected.\n", ui->TE_GLOBAL_LOG, "red", false);
        break;
        case QTcpSocket::HostLookupState : // The socket is performing a host name lookup.
            _log.PrintLog("[RB5] DATA socket is performing a host name lookup.\n", ui->TE_GLOBAL_LOG, "black", false);
        break;
        case QTcpSocket::ConnectingState : // The socket has started establishing a connection.
            _log.PrintLog("[RB5] DATA socket has started establishing a connection.\n", ui->TE_GLOBAL_LOG, "black", false);
        break;
        case QTcpSocket::ConnectedState : // A connection is established.
            _log.PrintLog("[RB5] DATA socket is established.\n", ui->TE_GLOBAL_LOG, "green", false);
        break;
        case QTcpSocket::BoundState : // The socket is bound to an address and port.
            _log.PrintLog("[RB5] DATA socket is bound to an address and port.\n", ui->TE_GLOBAL_LOG, "black", false);
        break;
        case QTcpSocket::ClosingState : // The socket is about to close (data may still be waiting to be written).
            _log.PrintLog("[RB5] DATA socket is about to close.\n", ui->TE_GLOBAL_LOG, "black", false);
        break;
    }

    int state_VISION = obj_Keti->Keti_Client->state();
    switch (state_VISION)
    {
        case QTcpSocket::UnconnectedState : // The socket is not connected.
            _log.PrintLog("[VISION] socket is not connected.\n", ui->TE_GLOBAL_LOG, "red", false);
        break;
        case QTcpSocket::HostLookupState : // The socket is performing a host name lookup.
            _log.PrintLog("[VISION] socket is performing a host name lookup.\n", ui->TE_GLOBAL_LOG, "black", false);
        break;
        case QTcpSocket::ConnectingState : // The socket has started establishing a connection.
            _log.PrintLog("[VISION] socket has started establishing a connection.\n", ui->TE_GLOBAL_LOG, "black", false);
        break;
        case QTcpSocket::ConnectedState : // A connection is established.
            _log.PrintLog("[VISION] socket is established.\n", ui->TE_GLOBAL_LOG, "green", false);
        break;
        case QTcpSocket::BoundState : // The socket is bound to an address and port.
            _log.PrintLog("[VISION] socket is bound to an address and port.\n", ui->TE_GLOBAL_LOG, "black", false);
        break;
        case QTcpSocket::ClosingState : // The socket is about to close (data may still be waiting to be written).
            _log.PrintLog("[VISION] socket is about to close.\n", ui->TE_GLOBAL_LOG, "black", false);
        break;
    }

    int state_GRIPPER = obj_Kitech->Kitech_Client->state();
    switch (state_GRIPPER)
    {
        case QTcpSocket::UnconnectedState : // The socket is not connected.
            _log.PrintLog("[GRIPPER] socket is not connected.\n", ui->TE_GLOBAL_LOG, "red", false);
        break;
        case QTcpSocket::HostLookupState : // The socket is performing a host name lookup.
            _log.PrintLog("[GRIPPER] socket is performing a host name lookup.\n", ui->TE_GLOBAL_LOG, "black", false);
        break;
        case QTcpSocket::ConnectingState : // The socket has started establishing a connection.
            _log.PrintLog("[GRIPPER] socket has started establishing a connection.\n", ui->TE_GLOBAL_LOG, "black", false);
        break;
        case QTcpSocket::ConnectedState : // A connection is established.
            _log.PrintLog("[GRIPPER] socket is established.\n", ui->TE_GLOBAL_LOG, "green", false);
        break;
        case QTcpSocket::BoundState : // The socket is bound to an address and port.
            _log.PrintLog("[GRIPPER] socket is bound to an address and port.\n", ui->TE_GLOBAL_LOG, "black", false);
        break;
        case QTcpSocket::ClosingState : // The socket is about to close (data may still be waiting to be written).
            _log.PrintLog("[GRIPPER] socket is about to close.\n", ui->TE_GLOBAL_LOG, "black", false);
        break;
    }

    auto state_LIFT = obj_Lift->serial_Lift.error();
    switch (state_LIFT)
    {
        //No error occurred.
        case QSerialPort::NoError :
            _log.PrintLog("[LIFT] NoError.\n", ui->TE_GLOBAL_LOG, "black", false);
        break;

        // An error occurred while attempting to open an non-existing device.
        case QSerialPort::DeviceNotFoundError :
            _log.PrintLog("[LIFT] DeviceNotFoundError.\n", ui->TE_GLOBAL_LOG, "red", false);
        break;

        // An error occurred while attempting to open an already opened device
        // by another process or a user not having enough permission and credentials to open.
        case QSerialPort::PermissionError :
            _log.PrintLog("[LIFT] PermissionError.\n", ui->TE_GLOBAL_LOG, "red", false);
        break;

        // An error occurred while attempting to open an already opened device in this object.
        case QSerialPort::OpenError :
            _log.PrintLog("[LIFT] OpenError.\n", ui->TE_GLOBAL_LOG, "red", false);
        break;

        // This error occurs when an operation is executed
        // that can only be successfully performed if the device is open.
        case QSerialPort::NotOpenError :
            _log.PrintLog("[LIFT] NotOpenError.\n", ui->TE_GLOBAL_LOG, "red", false);
        break;

        // An I/O error occurred while writing the data.
        case QSerialPort::WriteError :
            _log.PrintLog("[LIFT] WriteError.\n", ui->TE_GLOBAL_LOG, "red", false);
        break;
        case QSerialPort::ReadError :
            _log.PrintLog("[LIFT] ReadError.\n", ui->TE_GLOBAL_LOG, "red", false);
        break;
        case QSerialPort::ResourceError :
            _log.PrintLog("[LIFT] ResourceError.\n", ui->TE_GLOBAL_LOG, "red", false);
        break;
        case QSerialPort::UnsupportedOperationError :
            _log.PrintLog("[LIFT] UnsupportedOperationError.\n", ui->TE_GLOBAL_LOG, "red", false);
        break;
        case QSerialPort::TimeoutError :
            _log.PrintLog("[LIFT] TimeoutError.\n", ui->TE_GLOBAL_LOG, "red", false);
        break;
        case QSerialPort::UnknownError :
            _log.PrintLog("[LIFT] UnknownError.\n", ui->TE_GLOBAL_LOG, "red", false);
        break;
    }
    //Integrated_info.Log_info.append(QString("\n"));
}

void MainWindow::check_connection()
{
    if(Integrated_info.init_rb5 == RB5_connect_info::NO_CONNECTION)
    {
        ui->LE_RB5_INIT->setStyleSheet("border-style: outset;border-width: 1px;border-color: black");
        ui->BTN_CONNECT_RB5->setText("conn.");
    }
    else if(Integrated_info.init_rb5 == RB5_connect_info::CMD_CONNECTED)
    {
        ui->LE_RB5_INIT->setStyleSheet("background-color:yellow");
    }
    else if(Integrated_info.init_rb5 == RB5_connect_info::DATA_CONNECTED)
    {
        ui->LE_RB5_INIT->setStyleSheet("background-color:pink");
    }
    else if(Integrated_info.init_rb5 == RB5_connect_info::ALL_CONNECT_AND_INIT_COMPLETE)
    {
        ui->LE_RB5_INIT->setStyleSheet("background-color:green");
        ui->BTN_CONNECT_RB5->setText("dis.");
    }

    if(Integrated_info.init_omron == socket_connect_info::DISCONNECTED)
    {
        ui->LE_OMRON_INIT->setStyleSheet("border-style: outset;border-width: 1px;border-color: black");
        ui->BTN_CONNECT_OMRON->setText("conn.");
    }
    else if(Integrated_info.init_omron == socket_connect_info::CONNECTED)
    {
        ui->LE_OMRON_INIT->setStyleSheet("background-color:green");
        ui->BTN_CONNECT_OMRON->setText("dis.");
    }

    if(Integrated_info.init_vision == socket_connect_info::DISCONNECTED)
    {
        ui->LE_VISION_INIT->setStyleSheet("border-style: outset;border-width: 1px;border-color: black");
        ui->BTN_CONNECT_VISION->setText("conn.");
    }
    else if(Integrated_info.init_vision == socket_connect_info::CONNECTED)
    {
        ui->LE_VISION_INIT->setStyleSheet("background-color:green");
        ui->BTN_CONNECT_VISION->setText("dis.");
    }

    if(Integrated_info.init_gripper == socket_connect_info::DISCONNECTED)
    {
        ui->LE_GRIPPER_INIT->setStyleSheet("border-style: outset;border-width: 1px;border-color: black");
        ui->BTN_CONNECT_GRIPPER->setText("conn.");
    }
    else if(Integrated_info.init_gripper == socket_connect_info::CONNECTED)
    {
        ui->LE_GRIPPER_INIT->setStyleSheet("background-color:green");
        ui->BTN_CONNECT_GRIPPER->setText("dis.");
    }

    if(Integrated_info.init_lift == socket_connect_info::DISCONNECTED)
    {
        ui->LE_LIFT_INIT->setStyleSheet("border-style: outset;border-width: 1px;border-color: black");
        ui->BTN_CONNECT_LIFT->setText("conn.");
    }
    else if(Integrated_info.init_lift == socket_connect_info::CONNECTED)
    {
        ui->LE_LIFT_INIT->setStyleSheet("background-color:green");
        ui->BTN_CONNECT_LIFT->setText("dis.");
    }
}
// ff ff f4 40

void MainWindow::on_BTN_LIFT_REQ_DATA_clicked()
{
    obj_Lift->req_mainData();
}

void MainWindow::on_btn_say_clicked()
{
    QString text = "dotask say ";
    text.append(ui->le_say->text());
    telentClinetThread->sendCommand = text.toStdString();
//    cout << text.toStdString() << endl;
    telentClinetThread->flag = 1;
}

void MainWindow::on_BTN_SH_11_clicked()
{
    ui -> LE_OMRON_X -> setText("3771");
    ui -> LE_OMRON_Y -> setText("35890");
    ui -> LE_OMRON_HEADING -> setText("0");
}

void MainWindow::on_BTN_SH_12_clicked()
{
    ui -> LE_OMRON_X -> setText("4478");
    ui -> LE_OMRON_Y -> setText("35890");
    ui -> LE_OMRON_HEADING -> setText("0");
}

void MainWindow::on_BTN_SH_13_clicked()
{
    ui -> LE_OMRON_X -> setText("5327");
    ui -> LE_OMRON_Y -> setText("35890");
    ui -> LE_OMRON_HEADING -> setText("0");
}


void MainWindow::on_BTN_SH_14_clicked()
{
    ui -> LE_OMRON_X -> setText("6086");
    ui -> LE_OMRON_Y -> setText("35890");
    ui -> LE_OMRON_HEADING -> setText("0");
}

///////////////////////////////////////

void MainWindow::on_BTN_SH_21_clicked()
{
    ui -> LE_OMRON_X -> setText("4205");
    ui -> LE_OMRON_Y -> setText("35384");
    ui -> LE_OMRON_HEADING -> setText("180");
}

void MainWindow::on_BTN_SH_22_clicked()
{
    ui -> LE_OMRON_X -> setText("4205");
    ui -> LE_OMRON_Y -> setText("35384");
    ui -> LE_OMRON_HEADING -> setText("180");
}

void MainWindow::on_BTN_SH_23_clicked()
{
    ui -> LE_OMRON_X -> setText("4205");
    ui -> LE_OMRON_Y -> setText("35384");
    ui -> LE_OMRON_HEADING -> setText("180");
}

void MainWindow::on_BTN_SH_24_clicked()
{
    ui -> LE_OMRON_X -> setText("4205");
    ui -> LE_OMRON_Y -> setText("35384");
    ui -> LE_OMRON_HEADING -> setText("180");
}
