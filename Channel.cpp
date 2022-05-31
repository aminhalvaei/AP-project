#include "Channel.h"

Channel::Channel(QTcpSocket* _socket, QObject* parent) : QObject(parent)
{
    socket = _socket;
    thread = std::thread(&Channel::communicate, this);
}
Channel::~Channel()
{
    thread.join();
}

void Channel::communicate()
{
    while (true) {
        while (!socket->waitForReadyRead(-1));
        QByteArray b = socket->readAll();
        QMap<QString, card*>::iterator itr;
        for (itr = cards.begin(); itr != cards.end(); itr++)
            if (itr.value()->getCardId().toStdString() == b.toStdString())
                break;
        if (itr != cards.end())
            socket->write("ID is valid.");
        else
            socket->write("ID is not valid.");
        socket->waitForBytesWritten(3000);
    }
}
