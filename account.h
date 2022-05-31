#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QDateTime>
#include <QRandomGenerator64>
#include "structures.h"
using namespace str;
class account
{
    int balance;
    int accountId;
    QDateTime openDate;
    int controlInterest;
    bool status;
    QVector<transaction> transactions;
    QString oUserUsername;

protected:
    int TYPE;

public:
    account() {}
    account(int,QString);
    virtual ~account()=0;
    int getBalance(){return balance;}
    int getAccountId(){return accountId;}
    QDateTime getOpenDate(){return openDate;}
    bool getStatus(){return status;}
    QVector<transaction>& getTransactions(){return transactions;}
    QString getOUserUsername(){return oUserUsername;}
    int getControlInterest(){return controlInterest;}
    void setStatus(bool _status){status = _status;}
    void setBalance(int _balance){balance = _balance;}
    void setControlInterest(int _controlInterest){controlInterest = _controlInterest;}
    virtual void interestSettlement()=0;
    int getTYPE() const;
    void setAccountId(int value);
    void setOpenDate(const QDateTime &value);
    void setOUserUsername(const QString &value);
    void setTransactions(const QVector<transaction> &value);
};

#endif // ACCOUNT_H
