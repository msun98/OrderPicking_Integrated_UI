#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include <QObject>
#include <QWebSocketServer>
#include <QWebSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <queue>
#include <vector>
#include <QTimer>
#include <QDebug>
#include <QFileInfoList>

#include <iostream>
#include <filesystem>

#include "Common_header.h"
#include "omron.h"

class websocket : public QObject
{
    Q_OBJECT
public:
    explicit websocket(QObject *parent = nullptr);
    websocket();

public slots:
    void onTimeout();

    void onNewConnection();
    void onClosed();

    void onTextMessageReceived(QString message);
    void onBinaryMessageReceived(QByteArray message);
    void MissionCheck(QString uuid);
    void onDisconnected();

private:
    QTimer  *timer;

    QWebSocketServer *server;
    QList<QWebSocket *> clients;

    QJsonObject data(QString robot_manufacture, QString action,QString robot_type, QString map_id, QString map_alias);
    void sendNotice(QWebSocket *client_socket);
    void sendCommandAck(QWebSocket *client_socket, QString result, QJsonObject error_info, QString uuid);
    void sendCommandResult(QWebSocket *client_socket, QString result, QJsonObject error_info, QString uuid);
    void sendCommandResult(QWebSocket *client_socket, QString action, QString result, QJsonObject data, QJsonObject error_info, QString uuid);

};

#endif // WEBSOCKET_H
