#ifndef OUSER_H
#define OUSER_H
#include "person.h"
#include "account.h"
#include <QVector>
#include <QMultiMap>
using namespace str;
//#include <boost>
class oUser :public person
{
    QVector<account*> accounts;
    bool status;
    QVector<struct log> logActivity;
    static QMultiMap<QString,accreq> accountRequestList ;
    static QMultiMap<int,transaction> allTransactions;
    static int count;
    bool accountReqStatus;

public:

    oUser() {count++;}
    oUser(QString,QString,int,QString,QString,QDate,QString,QString);
    QVector<account*>& getAccounts(){return accounts;}
    static int getCount(){return count;}
    bool getStatus(){return status;}
    static QMultiMap<QString,accreq>& getAccountRequestList(){return accountRequestList;}
    static QMultiMap<int,transaction>& getAllTransactions(){return allTransactions;}
    QVector <struct log>& getLogActivity(){return logActivity;}
    bool getAccountReqStatus(){return accountReqStatus;}
    void setStatus(bool _status){status = _status;}
    void setAccountRequestList(QMultiMap<QString,accreq> _accountRequestList){ accountRequestList = _accountRequestList;}
    void setAllTransactions(QMultiMap<int,transaction> _allTransactions){allTransactions = _allTransactions;}
    void setAccountReqStatus(bool _accountReqStatus){accountReqStatus=_accountReqStatus;}
    void printLogActivitesInPDF();
    static QMultiMap<QString,accreq>  addReq(QString,QString,int,QStringList);
    static QMultiMap<int,transaction> addReq(int,int ,int ,QDateTime);
    static void clearMultiMap();
    void setLogActivity(const QVector<struct log> &value);
};

#endif // OUSER_H
