#include "websocket.h"

extern NetworkThread *networkThread;

websocket::websocket()
{
    //ui->setupUi(this);

    server = new QWebSocketServer("rb_websocket", QWebSocketServer::NonSecureMode, this);
    if(server->listen(QHostAddress::Any, 1111)) //서버가 들어오는 연결을 수신하기 위해 listen을 호출
    {
        connect(server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
//        connect(server, SIGNAL(closed()), this, SLOT(onClosed()));
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    timer->start(100);
}

//websocket::~websocket()
//{
//    server->close();
//    qDeleteAll(clients.begin(), clients.end());
//    //delete ui;
//}


void websocket::onTimeout()
{
    static int cnt = 0;
    cnt++;

    if(clients.size() > 0)
    {
        if(cnt%5 == 0)
        {
            for(int i=0; i<clients.size(); i++)
            {
                QWebSocket *pSocket = clients[i];
                sendNotice(pSocket);
            }
        }
    }
}

void websocket::onNewConnection(){

    QWebSocket *pSocket = server->nextPendingConnection();

    connect(pSocket, SIGNAL(textMessageReceived(QString)), this, SLOT(onTextMessageReceived(QString)));
//    connect(pSocket, SIGNAL(binaryMessageReceived(QByteArray)), this, SLOT(onBinaryMessageReceived(QByteArray)));
    connect(pSocket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    //connect(pMP, SIGNAL(UpdateUI()), this, SLOT(MissionCheck(QString uuid)));

    clients << pSocket;

    //ui->te_msg->append(QString("New Client Connected.."));
}

void websocket::onClosed()
{

}

void websocket::onTextMessageReceived(QString message) //comand msg
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
//    qDebug() << "Message received:" << message;
    //ui->te_msg->append(message);

    if(pClient){
        QJsonObject json;
        QJsonDocument doc_json = QJsonDocument::fromJson(message.toUtf8());
        json = doc_json.object();

        if(json["msg_type"] == "command"){
            // Command Msg
            QString entry = json["entry"].toString();
            QString action = json["do"].toString();
            QJsonObject params = json["params"].toObject();
            QString uuid = json["uuid"].toString();
//            QString uuid = "req_move_3";
            QJsonObject error_info;
//            QString uuid = "req_move_3";


            if(action == "move")
            {
                //4.1 Move
                QJsonObject tempDest = params["dest"].toObject();
//                QString mm = QJsonDocument(tempDest).toJson(QJsonDocument::Compact);
//                qDebug()<<mm;

                double x = tempDest["x"].toDouble();
                double y = tempDest["y"].toDouble();
                double theta = tempDest["theta"].toDouble();

                pClient->sendTextMessage("moving");
                //pMP->MoveOmron(x,y,theta);
            }

            else if(action == "stop")
            {
                //4.6 Stop
                pClient->sendTextMessage("stop");
                //pMP->StopOmron();
            }

            else if(action == "get_map_info_list")
            {
                //4.8 Get Map Info List
////                QJsonObject json_data;//map 의 개수가 증가함에 따라 json object 의 개수가 늘어야함.
                QJsonObject json_out;
                QJsonArray json_arr;
//                QJsonObject json_out;
                json_out["msg_type"] = "cmd_result";
                json_out["result"] = "success";
                json_out["error_info"] = "null";


                ////////////map directory 내부에 있는 파일 list 반환////////////
                QDir dir("map/");
                QFileInfoList list = dir.entryInfoList(QDir::Files, QDir::NoSort);
//                QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks, QDir::Size | QDir::Reversed);

                for (int i = 0; i < list.size(); ++i)
                {
                   QJsonObject json_data;
                   QFileInfo fInfo = list.at(i);
                   QString fPath = fInfo.absoluteFilePath();

                   QString filelist = fPath.section("map/", -1);
/////////////////
                   json_data["data"] = data("OMRON","get_map_info_list","LD250", "MIR", filelist);
//                   QJsonObject data = json_data["data"];
                   QJsonObject data = json_data["data"].toObject();
                   json_arr.insert(i,data);//디렉토리 내부에 있는 파일 중 1번 out(omron에 들어가는 파일의 개수가 많아지면 0이 다른 숫자로 바뀌어야함.)
                   json_out["data"] = json_arr;
                }
                ////////////
                 qDebug() <<json_out["data"];
                 if(!error_info.empty())
                 {
                     json_out["error_info"] = error_info;
                 }
                 QJsonDocument doc_json(json_out);
                 QString str_json(doc_json.toJson(QJsonDocument::Indented));
//                QJsonObject data = json_data["data"].toObject();
                pClient->sendTextMessage(str_json);
            }


            else if(action == "get_map_info")
            {
                //4.9 Get Map Info
                QJsonObject json;
                json["msg_type"] = "cmd_result"; //만약 명령 수행시 성공했다면 result -> success (omron 이동 하면 success!)
                json["result"] = "success";

                if(!error_info.empty())
                {
                    json["error_info"] = error_info;
                }
                json["uuid"] = uuid;

                QJsonObject json_data;
            //    QJsonArray json_arr;

                json_data["origin_px"] = 5;
                json_data["origin_py"] = 5;
                json_data["with_gm"] = 5;
                json_data["scale_m2px"] = 20.0;
                json_data["filpped"] = "false";
                qDebug()<<params["map_id"].toString();

                if (params["map_id"].toString() == "")
                {
                    json["error_info"] = "null";
                    json_data["map_id"] = "original.png";
                    json_data["map_alias"] = 20.0;
                }

                else
                {
                    //나중에 유진에서 요청하는 맵 이름으로 변경하여 내보내기￣
                    std::cout<<"working"<<std::endl;
                    json_data["map_id"] = "2.png";
                    json_data["map_alias"] = 20.0;
                }
                json["data"] = json_data;


                QJsonDocument doc_json(json);
                //QString str_json(doc_json.toJson(QJsonDocument::Compact));￣
                QString str_json(doc_json.toJson(QJsonDocument::Indented));
                pClient->sendTextMessage(str_json);

            }

            else if(action == "get_map_data")
            {
                //4.10 Get Map Data
//                qDebug()<<params["map_id"];
                QString id = params["map_id"].toString();//server 에서 요청한 map 의 id 파싱
                QJsonObject json;
                QJsonObject json_data;
                QString fileName;
                int image_file_size;

                json_data["data_type"] = params["data_type"];
                json_data["map_id"] = params["map_id"];

                json["uuid"] = uuid;
                cv::Mat img;

                if (id == "")
                {
                    json["error_info"] = "null";
                    id = "original.png";//현재 사용하고 있는 map
                    fileName = id;

                    QFile* file = new QFile("map/"+id);
                    file->open(QFile::ReadOnly | QFile::Text);
                    image_file_size = file->size();
//                    qDebug()<<image_file_size;

                    json_data["filename"] = id;
//                    json_data["filesize"] = size;//파일 사이즈 알아내야 함.
                    json_data["flipped"] = false;
                    img = cv::imread("map/"+id.toStdString(),cv::IMREAD_GRAYSCALE); // 이미지 읽기

//                    mapImg=img;
//                    imshow("지금 사용하고 있는 맵",img);
                    //바이너리로 변경하여 유진로봇 api에 쏴주어야함.
                }

                else
                {
                    //나중에 유진에서 요청하는 맵 이름으로 변경하여 내보내기
                    id ="map/"+id;
                    QFile* file = new QFile(id);
                    file->open(QFile::ReadOnly | QFile::Text);
                    image_file_size = file->size();
//                    cout<<size1<<endl;

                    fileName=id;
                    json_data["map_id"] = id;
                    json_data["filename"] = id;
                    json_data["flipped"] = false;
                    img = cv::imread(id.toStdString(),cv::IMREAD_GRAYSCALE); // 이미지 읽기
                }

                QString prifix = "FILE_DATA";
                QString signature = json_data["data_type"].toString();
                if (signature == "map_image_png")
                {
                    signature = "MAP_IMAGE_PNG___";
                }
                else
                {
                    signature = "MAP_PACKAGE_COMP";
                }
                int header_size = signature.size()+fileName.size();
                qDebug()<<image_file_size;

                cv::imshow("맵",img);
                json["data"] = json_data;


                QJsonDocument doc_json(json);
                QString str_json(doc_json.toJson(QJsonDocument::Indented));
//                pClient->sendTextMessage("get_map_info");
                pClient->sendTextMessage(str_json);


//                auto decodeIMG = cv::imdecode(data_encode,cv::IMREAD_GRAYSCALE);
//                imshow("img",decodeIMG);
            }

            else if(action == "set_map_data")
            {
                //4.11 Set Map Data
            }


//            QString uuid = json["uuid"].toString();

//            QJsonObject error_info;
            sendCommandAck(pClient, "success", error_info, uuid);

//            pClient->sendTextMessage("end");

        }
    }
}


void websocket::onBinaryMessageReceived(QByteArray message){
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if(pClient){
        pClient->sendBinaryMessage(message);
    }
}

void websocket::onDisconnected(){
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if(pClient){
        clients.removeAll(pClient);
        pClient->deleteLater();
    }
}

void websocket::sendNotice(QWebSocket *client_socket){
    QJsonObject json;
    json["msg_type"] = "notice";
    json["robot_state"] = "ready";
    json["navi_mode"] = "navigate";

    QJsonObject json_robot;
    json_robot["x"] = QString::number(networkThread->x);
    json_robot["y"] = QString::number(networkThread->y);
    json_robot["theta"] = QString::number(networkThread->heading);
    json["robot_pose"] = json_robot;

    QJsonObject json_map;
    json_map["map_id"] = "test";
    json_map["map_alias"] = "1F";
    json["map"] = json_map;

    QJsonObject json_battery;
    json_battery["level"] = QString::number(networkThread->battery);
    json_battery["in_charging"] = false;
    json["battery"] = json_battery;

    QJsonDocument doc_json(json);
    //QString str_json(doc_json.toJson(QJsonDocument::Compact));
    QString str_json(doc_json.toJson(QJsonDocument::Indented));
//    client_socket->sendTextMessage("notice");
    client_socket->sendTextMessage(str_json);
}

void websocket::sendCommandAck(QWebSocket *client_socket, QString result, QJsonObject error_info, QString uuid)
{
    QJsonObject json;
    json["msg_type"] = "ack";
    json["result"] = result;

    if(!error_info.empty())
    {
        json["error_info"] = error_info;
    }
    json["uuid"] = uuid;

    QJsonDocument doc_json(json);
    //QString str_json(doc_json.toJson(QJsonDocument::Compact));
    QString str_json(doc_json.toJson(QJsonDocument::Indented));
//    client_socket->sendTextMessage("ack");
    client_socket->sendTextMessage(str_json);
}


void websocket::MissionCheck(QString uuid){
//    QJsonObject json;
    QJsonObject error_info;
//    QString uuid = uuid;
    for(int i=0; i<clients.size(); i++)
    {
        QWebSocket *pSocket = clients[i];

        if (1/*pMP->check == 1*/)
        {
            sendCommandResult(pSocket, "success", error_info, uuid);
            qDebug()<<"success";
        }

        else if (0/*pMP->check == 0*/)
        {
            sendCommandResult(pSocket, "Failed", error_info, uuid);
            qDebug()<<"Failed";
        }
    }
}


void websocket::sendCommandResult(QWebSocket *client_socket, QString result, QJsonObject error_info, QString uuid){

    QJsonObject json;
    json["msg_type"] = "cmd_result"; //만약 명령 수행시 성공했다면 result -> success (omron 이동 하면 success!)
    json["result"] = result;

    if(!error_info.empty())
    {
        json["error_info"] = error_info;
    }
    json["uuid"] = uuid;

    QJsonDocument doc_json(json);
    //QString str_json(doc_json.toJson(QJsonDocument::Compact));
    QString str_json(doc_json.toJson(QJsonDocument::Indented));
//    client_socket->sendTextMessage("success");
    client_socket->sendTextMessage(str_json);
}


void websocket::sendCommandResult(QWebSocket *client_socket, QString action, QString result, QJsonObject data, QJsonObject error_info, QString uuid){

    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    QJsonObject json;
    json["msg_type"] = "cmd_result"; //만약 명령 수행시 성공했다면 result -> success (omron 이동 하면 success!)
    json["result"] = result;
    json["uuid"] = uuid;

    if (action == "get_map_info_list")
    {
        //안쓴다.￣
//        QJsonObject json_out;
//        json_out["msg_type"] = "cmd_result";
//        json_out["result"] = "success";
//        json_out["error_info"] = "null";

//        if(!error_info.empty())
//        {
//            json_out["error_info"] = error_info;
//        }
//        qDebug()<<data;
//        json_out["data"] = data;
////        pClient->sendTextMessage("get_map_info_list");
//        QJsonDocument doc_json(json_out);
//        QString str_json(doc_json.toJson(QJsonDocument::Indented));
//        qDebug()<<str_json;
//        pClient->sendTextMessage(str_json);

    }

    else if (action == "get_map_data")
    {

        QJsonObject json_out;
        json_out["msg_type"] = "cmd_result";
        json_out["result"] = "success";
        json_out["error_info"] = "null";

        if(!error_info.empty())
        {
            json_out["error_info"] = error_info;
        }

        json_out["data"] = data;
        pClient->sendTextMessage("get_map_info_list");
        QJsonDocument doc_json(json_out);
        QString str_json(doc_json.toJson(QJsonDocument::Indented));
//        qDebug()<<str_json;
        pClient->sendTextMessage(str_json);

    }

//    json["uuid"] = uuid;

    QJsonDocument doc_json(json);
    //QString str_json(doc_json.toJson(QJsonDocument::Compact));
    QString str_json(doc_json.toJson(QJsonDocument::Indented));
    client_socket->sendTextMessage("success");
    client_socket->sendTextMessage(str_json);
}

QJsonObject websocket::data(QString robot_manufacture, QString action,QString robot_type, QString map_id, QString map_alias){

    QJsonObject json_data_map;
//    QJsonArray json_arr;
    QJsonObject json_out;

    if (action == "get_map_info_list")
    {
        json_data_map["robot_manufacturer"] = robot_manufacture;
        json_data_map["robot_type"] = robot_type;
        json_data_map["map_id"] = map_id;
        json_data_map["map_alias"] = map_alias;

//        QJsonArray json_arr;
//        json_arr.insert(0,json_data_map);//디렉토리 내부에 있는 파일 중 1번 out(omron에 들어가는 파일의 개수가 많아지면 0이 다른 숫자로 바뀌어야함.)
//        //    json_out["data"] = json_arr;
        json_out = json_data_map;
    }


    return json_out;
}
