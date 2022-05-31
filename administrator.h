#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "person.h"
#include <QVector>
class administrator : public person
{

public:
    administrator() {}
    administrator(QString,QString,int,QString,QString,QDate,QString,QString);
    void removeOUser(QString);
    void addOUser(QString,QString,int,QString,QString,QDate,QString,QString);
    void printAllOUser();

};

#endif // ADMINISTRATOR_H
