#ifndef SHORTTERM_H
#define SHORTTERM_H
#include "saveaccount.h"
class shortTerm : public saveAccount
{
public:
    shortTerm() {TYPE = 2;}
    shortTerm(int _balance,QString _username):saveAccount(_balance,_username){TYPE = 2;}
    void interestSettlement()
    {
        int diffsec = getOpenDate().secsTo(QDateTime::currentDateTime());
        int base =30*24*60*60;
        diffsec-=(getControlInterest()*base);
        if(diffsec >= base){
            int i = diffsec/base;
            setControlInterest(i+getControlInterest());
            for(;i> 0;i--)
            {
            setBalance(getBalance()+getBalance()*(.05));
            }
        }
    }
};

#endif // SHORTTERM_H
