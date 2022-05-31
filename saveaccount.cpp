#include "saveaccount.h"
QMultiMap<QString,cardreq> saveAccount::cardRequestList= saveAccount::addCardReq("Yoosof","save Account",123456);
int saveAccount::stc_control=0;
saveAccount::saveAccount(int _balance,QString _username):account(_balance,_username)
{
    cardReqStatus =false;
    myCard=nullptr;   
    stc_control++; //filehadling stc_control=cardRequestList.size();
    TYPE = 1;
}
QMultiMap<QString,cardreq> saveAccount::addCardReq(QString _username, QString _type, int _accountId)
{
    QMultiMap<QString,cardreq> multiMap;
    cardreq reqtemp;
    reqtemp.accType=_type;
    reqtemp.accountId=_accountId;
    multiMap.insert(_username,reqtemp);
    return multiMap;
}

void saveAccount::clearCardMultiMap()
{
    if(stc_control==0)
    cardRequestList.clear();
}
