#ifndef CORPORATE_H
#define CORPORATE_H
#include "shortterm.h"
class corporate : public shortTerm
{
    QVector<QString> otherUsers;
public:
    corporate() {TYPE = 3;}
    corporate(int _balance,QString _username,QVector<QString> _otherUsers):shortTerm(_balance,_username)
    {
        TYPE = 3;
        otherUsers = _otherUsers;
    }
    QVector<QString>& getOtherUsers(){return otherUsers;}
    void setOtherUsers(const QVector<QString> &value) {otherUsers = value;}

};

#endif // CORPORATE_H
