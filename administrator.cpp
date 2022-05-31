#include "administrator.h"
#include "container.h"
QVector<oUser*> oUsers;
administrator::administrator(QString _name,QString _lastName,int _nationalCode,QString _userName,QString _password,QDate _birthdate,QString _phonenumber,QString _email)
    :person(_name,_lastName,_nationalCode,_userName,_password,_birthdate,_phonenumber,_email)
{
}

void administrator::removeOUser(QString _username)
{
    int index = findUser(_username);
    oUsers.remove(index);
}

void administrator::addOUser(QString _name,QString _lastName,int _nationalCode,QString _userName,QString _password,QDate _birthdate,QString _phonenumber,QString _email)//for QT
{
    oUser* newUser = new oUser(_name,_lastName,_nationalCode,_userName,_password,_birthdate,_phonenumber,_email);
    oUsers.push_back(newUser);
}



