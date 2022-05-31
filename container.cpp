#include "container.h"
#include "corporate.h"
#include "timedeposit.h"
int findUser(QString _username){
    for(int i=0;i<oUsers.size();i++)
        if(oUsers[i]->getUsername() == _username)
            return i;
    return -1;
}

int findAccount(QString _accountId)
{
    for(int i = 0; i<accounts.size();i++)
    {
        if(accounts[i]->getAccountId()== _accountId.toLong())
        {
            return i;
        }
    }
    return -1;
}

void calculateBalance(int _sourceAccountIndex, int _destinationAccountIndex, int _amount,QWidget* _this)
{
    if(accounts[_sourceAccountIndex]->getBalance()< _amount)
    {
        QMessageBox::critical(_this,"Error","Your balance is not enough!!!!");
    }
    else
    {
        int sourceNewBalance =accounts[_sourceAccountIndex]->getBalance()-_amount;
        int destinatioanNewBalance = accounts[_destinationAccountIndex]->getBalance()+_amount;
        accounts[_sourceAccountIndex]->setBalance(sourceNewBalance);
        accounts[_destinationAccountIndex]->setBalance(destinatioanNewBalance);
       // oUsers[_sourceUserIndex]->getAccounts()[_sourceAccountIndex]->setBalance(sourceNewBalance);
       // oUsers[_desUserIndex]->getAccounts()[_destinationAccountIndex]->setBalance(destinatioanNewBalance);
        timeDeposit* temp = dynamic_cast<timeDeposit*>(accounts[_sourceAccountIndex]);
        if(temp)
        {
               QMessageBox::information(_this,"Information","Your time deposite account change to short account.");
               (shortTerm) *temp;
        }
        QMessageBox::information(_this,"Information","Tranfer is performed successfully.");
    }
}
void make_account(void) ////test
{
        shortTerm *temp2 = new shortTerm(1250000,"alireza");
        saveAccount *temp1 = new saveAccount(10000,"alireza");
        timeDeposit *temp=new timeDeposit(3000,"alireza");
        accounts.push_back(temp);
        accounts.push_back(temp1);
        accounts.push_back(temp2);
        oUsers[0]->getAccounts().push_back(temp);
        oUsers[0]->getAccounts().push_back(temp1);
        oUsers[0]->getAccounts().push_back(temp2);

}

int findAccount(QVector<account*> _vector,QString _accountId)
{
    for(int i=0;i<_vector.size();i++)
    {
        if(QString::number(_vector[i]->getAccountId())==_accountId)
            return i;
    }
    return -1;
}


