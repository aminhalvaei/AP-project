#include "accountofthisuser.h"
#include "container.h"
#include "corporate.h"
QVector<account*> accounts;
accountofthisuser::accountofthisuser(int _user_index,bool _isUser)
{
    user_index =_user_index;
    isUser = _isUser;
    gridlayout = new QGridLayout();
    int counterOfAccount =oUsers[user_index]->getAccounts().size();
    logoAccounts = new QPixmap(":/resource/image/faraz2.png");
    setWindowIcon(*logoAccounts);
    setWindowTitle("Accounts");
    int i=0,j=0;
    for(; i< counterOfAccount ;i++)
    {
        account* acc = oUsers[user_index]->getAccounts()[i];   //changed by amin it was accounts[i];
        if(typeid(*acc)==typeid(timeDeposit))
            title ="Time Deposit";
        else if(typeid(*acc)==typeid(shortTerm))
            title ="Short Term";
        else if(typeid (*acc)==typeid(saveAccount))
            title ="Saveing Account";
        else if(typeid(*acc)==typeid(corporate))
            title ="Corporate";
        balancelbl.push_back(new QLabel("Balance ($): "));
        oUsers[user_index]->getAccounts()[i]->interestSettlement();
        balanceval.push_back(new QLabel(QString::number(oUsers[user_index]->getAccounts()[i]->getBalance())));
        accountIdlbl.push_back(new QLabel("Account ID: "));
        accountIdval.push_back(new QLabel(QString::number(oUsers[user_index]->getAccounts()[i]->getAccountId())));
        statuslbl.push_back(new QLabel("Status: "));
        statusval.push_back(new QLabel((oUsers[user_index]->getAccounts()[i]->getStatus())? "Active":"Inactive"));
        opendatelbl.push_back(new QLabel("Open Date:"));
        opendateval.push_back(new QLabel(oUsers[user_index]->getAccounts()[i]->getOpenDate().toString(Qt::ISODate)));
        innerlayout.push_back(new QFormLayout());
        group.push_back(new QGroupBox());
        if(title == "Corporate")
        {
            otherUserIdlbl.push_back(new QLabel("OtherUser: "));
            otherUserIdval.push_back(new QLabel());
            corporate* temp = dynamic_cast<corporate*>(oUsers[user_index]->getAccounts()[i]);
            QString _other;
            if(!temp->getOtherUsers().contains(oUsers[user_index]->getUsername()))
            {
                for(int i=0;i<temp->getOtherUsers().size();i++)
                {
                    _other+=temp->getOtherUsers()[i];
                    _other+= " ";
                }
            }
            else
            {
                _other+=temp->getOUserUsername();
                _other+=" ";
                for(int i=0;i<temp->getOtherUsers().size();i++)
                {
                  if(temp->getOtherUsers()[i]==oUsers[user_index]->getUsername())
                      continue;
                  _other+=temp->getOtherUsers()[i];
                  _other+= " ";
                }
            }
            otherUserIdval.back()->setText(_other);   ///changed by amin
            innerlayout[i]->addRow(otherUserIdlbl.back(),otherUserIdval.back());  ///changed by amin
        }
        panelBottom.push_back(new QPushButton("Panel"));
        panelBottom[i]->setObjectName("p"+QString::number(i));
        if(oUsers[user_index]->getAccounts()[i]->getStatus())
        {
            panelBottom[i]->setEnabled(true);
        }
        else
        {
            panelBottom[i]->setEnabled(false);
        }
        innerlayout[i]->addRow(balancelbl[i],balanceval[i]);
        innerlayout[i]->addRow(accountIdlbl[i],accountIdval[i]);
        innerlayout[i]->addRow(statuslbl[i],statusval[i]);
        innerlayout[i]->addRow(opendatelbl[i],opendateval[i]);

        if(!isUser)
        {
            removepbn.push_back(new QPushButton("Remove"));
            removepbn[i]->setObjectName("r"+QString::number(i));
            pbnsLayout.push_back(new QHBoxLayout());
            if(statusval[i]->text()=="Active")
            {
              statuspbn.push_back(new QPushButton("Deactive"));
            }
            else
            {
              statuspbn.push_back(new QPushButton("Active"));
              panelBottom[i]->setEnabled(false);
            }
            statuspbn[i]->setObjectName("s"+QString::number(i));
            pbnsLayout[i]->addWidget(panelBottom[i]);
            pbnsLayout[i]->addWidget(removepbn[i]);
            pbnsLayout[i]->addWidget(statuspbn[i]);
            if(title=="Corporate")
            innerlayout[i]->setLayout(5,QFormLayout::FieldRole,pbnsLayout[i]);
            else
            innerlayout[i]->setLayout(5,QFormLayout::FieldRole,pbnsLayout[i]);


        }
        else
        {
        innerlayout[i]->addWidget(panelBottom[i]);
        }
        group[i]->setTitle(title);
        group[i]->setLayout(innerlayout[i]);
        j = i/3;
        gridlayout->addWidget(group[i],j,i%3);
        connect(panelBottom[i],SIGNAL(clicked()),this,SLOT(slTopbn()));
        if(!isUser)
        {
            connect(removepbn[i],SIGNAL(clicked()),this,SLOT(slTopbn()));
            connect(statuspbn[i],SIGNAL(clicked()),this,SLOT(slTopbn()));
        }
    }
    backToUserPanel = new QPushButton("back",this);

    pbnlayout=new QVBoxLayout();
    mainlayout=new QVBoxLayout();
    pbnlayout->addWidget(backToUserPanel,Qt::AlignRight);
    pbnlayout->setAlignment(Qt::AlignRight);
    mainlayout->addLayout(gridlayout);
    mainlayout->addLayout(pbnlayout);
    setLayout(mainlayout);
    connect(backToUserPanel,SIGNAL(clicked()),this,SLOT(backTo()));
    connect(this,SIGNAL(pbn_sig(QString)),this,SLOT(pbn_sl(QString)));
}
void accountofthisuser::backTo()
{
    this->close();
    if(isUser)
    {
        emit backToUser_Sig();
    }
    else
    {
        emit backToAdmin_Sig();
    }
}

void accountofthisuser::slTopbn()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    emit pbn_sig(buttonSender->objectName());
}

void accountofthisuser::pbn_sl(QString _namepbn)
{
    int numberpbn = _namepbn[1].digitValue();
    if(_namepbn[0]=="r")
        {
            int finder =findAccount(accountIdval[numberpbn]->text());
            QMessageBox::StandardButton reply = QMessageBox::question(this,"Question","Are you sure?",QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::Yes)
            {
                saveAccount* temp = dynamic_cast<saveAccount*>(oUsers[user_index]->getAccounts()[numberpbn]);
                if(temp!=nullptr)
                {
                    ///cards delete
                    if(temp->getMyCard()!=NULL)
                    {
                        //corporate* temp2 = dynamic_cast<corporate*>(oUsers[user_index]->getAccounts()[numberpbn]);
                        if(typeid(*temp)!=typeid(corporate))
                        {
                            cards.remove(temp->getMyCard()->getCardId());
                            temp->setMyCardNULL();
                            saveAccount* temp2 = dynamic_cast<saveAccount*>(accounts[finder]);
                            temp2->setMyCardNULL();
                            delete temp2->getMyCard();
                        }
                        else
                        {
                            corporate* temp2 = dynamic_cast<corporate*>(accounts[finder]);
                            if(!temp2->getOtherUsers().contains(oUsers[user_index]->getUsername())) //head
                            {
                                cards.remove(temp->getMyCard()->getCardId());
                                ////oUsers
                                temp2->setMyCardNULL();
                                /*for(int i=0;i<temp2->getOtherUsers().size();i++)
                                {
                                    corporate* temp3 = dynamic_cast<corporate*>(oUsers[findUser(temp2->getOtherUsers()[i])]);
                                    temp3->setMyCardNULL();
                                }*/
                                ////

                                //corporate* temp2 = dynamic_cast<corporate*>(accounts[finder]);
                                //temp2->setMyCardNULL();
                                delete temp2->getMyCard();
                            }
                            else
                            {
                                oUsers[user_index]->getAccounts().remove(numberpbn);
                                accounts.remove(finder);
                                delete temp->getMyCard();
                            }

                        }
                    }
                    ////////accounts delete
                    if(typeid(*temp)==typeid(corporate))
                    {
                        corporate* temp = dynamic_cast<corporate*>(oUsers[user_index]->getAccounts()[numberpbn]);
                        if(!temp->getOtherUsers().contains(oUsers[user_index]->getUsername())) //head
                        {
                            accounts.remove(finder);
                            oUsers[user_index]->getAccounts().remove(numberpbn);
                            for(int i=0;i<temp->getOtherUsers().size();i++)
                            {
                                int finder=findUser(temp->getOtherUsers()[i]);
                                oUsers[finder]->getAccounts().remove(findAccount(oUsers[finder]->getAccounts(),QString::number(temp->getAccountId())));
                            }
                            delete temp;
                        }
                        else
                        {
                            oUsers[user_index]->getAccounts().remove(numberpbn);
                            for(int i=0;i<temp->getOtherUsers().size();i++)
                            {
                                if(temp->getOtherUsers()[i]==oUsers[user_index]->getUsername())
                                {
                                    temp->getOtherUsers().remove(i);
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        delete oUsers[user_index]->getAccounts()[numberpbn];
                        oUsers[user_index]->getAccounts().remove(numberpbn);
                        accounts.remove(finder);
                    }

                }
                else
                {
                    delete oUsers[user_index]->getAccounts()[numberpbn];
                    oUsers[user_index]->getAccounts().remove(numberpbn);
                    accounts.remove(finder);
                }
                this->close();
                emit refreshAccsPage();
            }
            else
            {
                return;
            }
        }
    else if(_namepbn[0]=="p")
    {
        panel_dialog= new account_panel(user_index,findAccount(accountIdval[numberpbn]->text()),numberpbn,isUser,title);
        this->hide();
        panel_dialog->show();
        connect(panel_dialog,SIGNAL(backToAccs_sig()),this,SLOT(show()));

    }
    else
    {
        if(oUsers[user_index]->getAccounts()[numberpbn]->getStatus())
        {
            oUsers[user_index]->getAccounts()[numberpbn]->setStatus(false);
            //accounts[findAccount(accountIdval[numberpbn]->text())]->setStatus(false);
            statuspbn[numberpbn]->setText("Active");
            statusval[numberpbn]->setText("Inactive");
            panelBottom[numberpbn]->setEnabled(false);
        }
        else
        {
            oUsers[user_index]->getAccounts()[numberpbn]->setStatus(true);
            //accounts[findAccount(accountIdval[numberpbn]->text())]->setStatus(true);
            statuspbn[numberpbn]->setText("Deactive");
            statusval[numberpbn]->setText("Active");
            panelBottom[numberpbn]->setEnabled(true);

        }
    }
}


