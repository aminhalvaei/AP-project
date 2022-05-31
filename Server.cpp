#include "Server.h"

Server::Server(QObject* parent) : QObject(parent)
{
    server = new QTcpServer();
    server->listen(QHostAddress::Any, 4444);
    if (server->isListening()) {
        connect(server, SIGNAL(newConnection()), this, SLOT(newConnection_slot()));
    }
}

void Server::newConnection_slot()
{
    connection.push_back(new Channel(server->nextPendingConnection()));
}
