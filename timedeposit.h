#ifndef TIMEDEPOSIT_H
#define TIMEDEPOSIT_H
#include "account.h"
#include "shortterm.h"
class timeDeposit : public account
{
public:
    timeDeposit() {TYPE = 4;}
    timeDeposit(int _balance,QString _username):account(_balance,_username){TYPE = 4;}
    void interestSettlement(){
        int diffsec = getOpenDate().secsTo(QDateTime::currentDateTime());
        int base =3*30*24*60*60;
        diffsec-=(getControlInterest()*base);
        if(diffsec >= base){
            int i = diffsec/base;
            setControlInterest(i+getControlInterest());
            for(;i> 0;i--)
            {
            setBalance(getBalance()+getBalance()*(.15));
            }
        }
    }
    explicit operator shortTerm()
    {
        interestSettlement();
        shortTerm* newObj = new shortTerm(getBalance(),getOUserUsername());
        return *newObj;
    }
};

#endif // TIMEDEPOSIT_H
