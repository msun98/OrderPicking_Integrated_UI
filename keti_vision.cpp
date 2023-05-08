#include "keti_vision.h"

Keti_vision::Keti_vision(QObject *parent) : QObject(parent)
{
    Keti_Client = new QTcpSocket();
    IP_VISION.ip = "192.168.1.153";
    IP_VISION.port = 7777;

    connect(Keti_Client, SIGNAL(connected()), this, SLOT(onKetiConnected()));
}

void Keti_vision::Vision_Connect()
{
    if(!Integrated_info.init_vision)
    {
        Keti_Client->abort();
        Keti_Client->connectToHost(QHostAddress(IP_VISION.ip), IP_VISION.port);
        connect(Keti_Client, SIGNAL(readyRead()), this, SLOT(onReadyCmdRead()));
        write_log(Integrated_info, "[Vision] Server conneting...\n");
    }
}

void Keti_vision::onReadyCmdRead()
{
    QByteArray Read_Data = Keti_Client->readAll();

    if(Read_Data[0] == 'R')
    {
       Integrated_info.keti_res = QString(Read_Data);
       Read_Data.remove(0, 10);

       auto a = Read_Data.split(',');
       Integrated_info.keti_grapsCoord.x = QString(a[0]).toFloat();
       Integrated_info.keti_grapsCoord.y = QString(a[1]).toFloat();
       Integrated_info.keti_grapsCoord.z = QString(a[2]).toFloat();

       Integrated_info.is_keti_est_point_get = true;

       if(a.size() == 4)
       {
           char* buf = a[4].data();
           std::vector<uchar> _buf;
           for(int i=0; i<Read_Data.size(); ++i)
           {
               _buf.push_back(static_cast<uchar>(buf[i]));
           }

           cv::Mat DecodedImage = cv::imdecode(_buf, cv::IMREAD_COLOR);
           DecodedImage.copyTo(Integrated_info.Keti_Frame);
       }
    }
}

void Keti_vision::saveEstimated_GrapsPoints(const QString& path)
{
    if(Integrated_info.keti_grapsCoord.x != -1)
        settings.WriteSettingFile_VISION(path.toStdString(), Integrated_info.keti_grapsCoord);
    else
        write_log(Integrated_info, "[Vision] need est point.\n");
}

void Keti_vision::loadEstimated_GrapsPoints(const QString &path)
{
    settings.ReadSettingFile_VISION(path.toStdString(), Integrated_info.keti_grapsCoord);
}

void Keti_vision::onKetiConnected()
{
    Integrated_info.init_vision = true;
    write_log(Integrated_info, "[Vision] Server connected.\n");
}

void Keti_vision::onKetidisConnected()
{
    Integrated_info.init_vision = false;
    write_log(Integrated_info, "[Vision] Server disconnected.\n");
}

void Keti_vision::write_log(Integrated_infomation& Ii, const QString& text)
{
    Ii.Log_info.append(text);
    emit SIGNAL_LOG_WRITE();
}
