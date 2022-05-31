#include "card.h"


void card::setCardId(const QString &value)
{
    cardId = value;
}

void card::setCVV2(int value)
{
    CVV2 = value;
}

void card::setExpirationDate(const QDate &value)
{
    expirationDate = value;
}

card::card(int _oAccountId,QString _oUserId)
{
    status =true;
    std::uniform_int_distribution<int> randCvv2(1000, 9999);
    CVV2 = randCvv2(*QRandomGenerator::global());
    cardId = this->createCardId();
    oUserId = _oUserId;
    oAccountId = _oAccountId;
    expirationDate= QDate::currentDate().addYears(2);
}

QString card::createCardId()
{
    std::uniform_int_distribution<int> randNumber(1000, 9999);
    QString x;
    cardId.push_back("1533");
    for (int i = 0; i < 3; i++) {
        int value = randNumber(*QRandomGenerator::global());
        x.setNum(value);
        cardId.push_back(x);
    }
    return cardId;
}
