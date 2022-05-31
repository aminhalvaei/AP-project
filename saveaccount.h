#ifndef SAVEACCOUNT_H
#define SAVEACCOUNT_H
#include "account.h"
#include "card.h"
#include "boost/assign/list_of.hpp"
#include <QMultiMap>
class saveAccount : public account
{
    card* myCard;
    static int stc_control;
    bool cardReqStatus;
    static QMultiMap<QString,cardreq> cardRequestList;
public:
    saveAccount() {stc_control++; TYPE = 1;}
    saveAccount(int,QString);
    static int getStc_sontrol(){return stc_control;}
    bool getCardReqStatus(){return cardReqStatus;}
    static QMultiMap<QString,cardreq>& getCardRequestList(){return cardRequestList;}
    card* getMyCard(){return myCard;}
    void setCardReqStatus(bool _cardReqStatus){cardReqStatus = _cardReqStatus;}
    void setMyCardNULL(){myCard=nullptr;}
    void setMyCard(card* _myCard){myCard=_myCard;}
    void interestSettlement(){};
    static QMultiMap<QString,cardreq>addCardReq(QString,QString,int);
    static void clearCardMultiMap();

};
#endif // SAVEACCOUNT_H
