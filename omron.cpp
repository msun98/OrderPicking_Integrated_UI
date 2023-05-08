#include "omron.h"

extern telnetclient *telentClinetThread;
extern NetworkThread *networkThread;

Omron::Omron(QObject *parent) : QObject(parent)
{

}


// mouse_clicked
void Omron::enterPosStart(double x, double y)
{
    pos_Start.x = x;
    pos_Start.y = y;

//    double r_x = (pos_Start.x * mmperpix_x)+(min_x)+30-2-14;//오차 수정
    //double r_x = pos_Start.x * mmperpix￣_x;//오차 수정
    //double r_y = (ui->txt->height() - pos_Start.y - 1) * mmperpix_y-abs(min_y) + 10-4;//오차수정 (flip 모드로 변환시켰기 때문에 변환 과정 필요)
    //double r_y = (ui->txt->height() - pos_Start.y - 1) * mmperpix_y + (min_y) + 30+5;//오차수정 (flip 모드로 변환시켰기 때문에 변환 과정 필요)

    //ui -> x_get -> setText(QString::number(r_x));
    //ui -> y_get -> setText(QString::number(r_y));
    //color_flag = 1;

//    if (r_x == 0)
//    {}

//    if (r_y == 0)
//        cout<<pt1.y<<endl;

}

// mouse_released
void Omron::enterPosEnd(double x, double y)
{
    pos_End.x = x;
    pos_End.y = y;
}

// on_add_clicked
int i_num = 0;
void Omron::addPoint(QString x, QString y, QString heading)
{
    QString x1 = x;
    QString y1 = y;
    QString z1 = heading;

    num(x, y, heading);
    QString add = x1+","+y1+","+z1;

    xyzInfo pos;
    pos.x = x1.toInt();
    pos.y = y1.toInt();
    pos.z = z1.toInt();
    //OmronPos.push(pos);

//    ui -> listView -> addItem(add);
//    ui -> x_get -> setText("");
//    ui -> y_get -> setText("");
//    ui -> z_get -> setText("");

    bool add_flag = true;
    //cv::Mat Drawing = colored_map;
    Drawing = colored_map;

    if (add_flag)
    {
        i_num = i_num+1;

        cv::circle(Drawing, p1, 1, cv::Scalar(255, 0, 0),2,-1); //blue (save)
        cv::putText(Drawing, to_string(i_num) ,p1, 1, 1, cv::Scalar(255, 0, 0), 1, 8);

        add_flag = false;
    }

    Drawing.copyTo(Integrated_info.omrons.omron_map);
    //ui->txt->setPixmap(QPixmap::fromImage(mat_to_qimage_cpy(Drawing)));
}

void Omron::num(QString x, QString y, QString heading)
{
    QString x1 = x;
    QString y1 = y;
    QString z1 = heading;

//    문자열의 길이가 0이라면 무시, 아니면 경로 추가
//  QString으로 받아온 문자를 int 형으로 변환해야 함.

    if (x1.length()!=0 && y1.length()!=0){
        text_1_x = x1.toInt(),text_1_y=y1.toInt(),text_1_z = z1.toInt();
         q.push(std::make_tuple(text_1_x,text_1_y,text_1_z));//que의 값을 넣음.
    }
}

void Omron::SetRobotInfoText()
{
    xyzInfo loc;
    loc.x = networkThread->x;
    loc.y = networkThread->x;
    loc.z = networkThread->heading;

    Integrated_info.omrons.omron_location = loc;
    Integrated_info.omrons.omron_battery = networkThread->battery;
    Integrated_info.omrons.omron_temp = networkThread->temperature;

    if (map_flag == true)
    {
        int rb_x = networkThread->x;
        int rb_y = networkThread->y;

        //cout<<rb_y<<endl;

        img_x = (rb_x-(min_x))/mmperpix_x;
        //(ui->txt->height() - pos_Start.y - 1)
        // 점플립
        //cout<<ui->txt->height()<<endl;
        img_y = (rb_y-(min_y))/mmperpix_y;
        //cout<<img_y<<endl;
        //img_y = -img_y+ui->txt->height();
    }

    //ui->txt->setPixmap(QPixmap::fromImage(mat_to_qimage_cpy(Drawing)));
}

void Omron::sendText()
{
//    QString text = ui->te_send->toPlainText();
//    telentClinetThread->sendCommand = text.toStdString();
//    telentClinetThread->flag = 1;
}

void Omron::saySomething()
{
//    QString text = "dotask say ";
//    text.append(ui->le_say->text());
//    telentClinetThread->sendCommand = text.toStdString();
//    cout << text.toStdString() << endl;
//    telentClinetThread->flag = 1;
}

void Omron::dock()
{
//    QString text = "dock";
//    telentClinetThread->sendCommand = text.toStdString();
//    cout << text.toStdString() << endl;
//    telentClinetThread->flag = 1;
}

void Omron::undock()
{
//    QString text = "undock";
//    telentClinetThread->sendCommand = text.toStdString();
//    cout << text.toStdString() << endl;
//    telentClinetThread->flag = 1;
}

void Omron::stop()
{
//    QString text = "stop";
//    telentClinetThread->sendCommand = text.toStdString();
//    qDebug() << "move Point complete!";
//    check = 1;

//    cout << text.toStdString() << endl;
//    telentClinetThread->flag = 1;
}

void Omron::moveGoal()
{
    cout<<"hi"<<endl;
}

void Omron::write_log(Integrated_infomation& Ii, const QString& text)
{
    Ii.Log_info.append(text);
    emit SIGNAL_LOG_WRITE();
}

