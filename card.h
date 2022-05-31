#ifndef CARD_H
#define CARD_H
#include <QDate>
#include <QRandomGenerator64>
class card
{
    QString cardId;
    int CVV2;
    QDate expirationDate;
    bool status;
    QString oUserId;
    int oAccountId;
public:
    card(int , QString);
    QString getCardId(){return cardId;}
    QString createCardId();
    int getCVV2(){return CVV2;}
    bool getStatus(){return status;}
    QDate getExpirationDate(){return expirationDate;}
    QString getOUserId(){return oUserId;}
    int getOAccountId(){return oAccountId;}
    void setStatus(bool _status){status = _status;}
    void setCardId(const QString &value);
    void setCVV2(int value);
    void setExpirationDate(const QDate &value);
};

#endif // CARD_H
