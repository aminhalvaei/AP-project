#include "ouser.h"

QMultiMap<QString,accreq> oUser::accountRequestList  = oUser::addReq("yosoof","saveAccount",10000,{"mamad"});
QMultiMap<int,transaction> oUser::allTransactions = oUser::addReq(9876567,12234567,20000,QDateTime(QDate(2000,4,5),QTime(12,30,30)));
int oUser::count=0;

void oUser::setLogActivity(const QVector<struct log> &value)
{
    logActivity = value;
}

oUser::oUser(QString _name,QString _lastName,int _nationalCode,QString _userName,QString _password,QDate _birthdate,QString _phonenumber,QString _email)
    :person(_name,_lastName,_nationalCode,_userName,_password,_birthdate,_phonenumber,_email)
{
   accountReqStatus=false;
   status = true;
   count++;  //for filehandling -> count=oUsers.size();

}

QMultiMap<QString,accreq> oUser::addReq(QString _username, QString _type, int _balance,QStringList _others)
{
    QMultiMap<QString,accreq> multiMap;
    accreq reqtemp;
    reqtemp.accType=_type;
    reqtemp.balance=_balance;
    reqtemp.others=_others;
    multiMap.insert(_username,reqtemp);
    return multiMap;
}

QMultiMap<int,transaction> oUser::addReq(int _sourceAccountId,int _accID,int _amount,QDateTime _datetime)
{
    QMultiMap<int,transaction> multiMap;
    transaction tran;
    tran.accountId = _accID;
    tran.amount = _amount;
    tran.dateTransaction = _datetime;
    multiMap.insert(_sourceAccountId,tran);
    return multiMap;
}

void oUser::clearMultiMap()
{
    if(count==0)
    {
        accountRequestList.clear();
        allTransactions.clear();
    }

}


