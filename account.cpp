#include "account.h"
#include "container.h"
int account::getTYPE() const
{
    return TYPE;
}

void account::setAccountId(int value)
{
    accountId = value;
}

void account::setOpenDate(const QDateTime &value)
{
    openDate = value;
}

void account::setOUserUsername(const QString &value)
{
    oUserUsername = value;
}

void account::setTransactions(const QVector<transaction> &value)
{
    transactions = value;
}

account::account(int _balance,QString _username)
{
    controlInterest = 0;
    balance =_balance;
    status = true;
    openDate = QDateTime::currentDateTime();
    oUserUsername=_username;
    std::uniform_int_distribution<int> randAccount(100000000, 999999999);
    accountId = randAccount(*QRandomGenerator::global());
}
account::~account(){}
