#pragma once

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <thread>
#include "container.h"

class Channel : public QObject
{
    Q_OBJECT

private:
    QTcpSocket* socket;
    std::thread thread;

public:
    explicit Channel(QTcpSocket*, QObject* parent = nullptr);
    ~Channel();

    void communicate();
};
