#pragma once

#include <QObject>
#include <QtNetwork/QTcpServer>
#include <vector>

#include "Channel.h"

class Server : public QObject
{
    Q_OBJECT

private:
    QTcpServer* server;
    std::vector<Channel*> connection;

public:
    explicit Server(QObject* parent = nullptr);

public slots:
    void newConnection_slot();
};
