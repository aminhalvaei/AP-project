#include "user_panel.h"
#include "container.h"
user_panel::user_panel(int _i)
{
    mainlayout=new QHBoxLayout();
    tool_layout=new QVBoxLayout();
    index= _i;
    logoUserPanel = new QPixmap(":/resource/image/faraz2.png");
    setWindowIcon(*logoUserPanel);
    setWindowTitle("user");
    //right
        rightlayout=new QVBoxLayout();

        piclabel= new QLabel();////////
        piclabel->setPixmap(QPixmap(":/resource/image/user/user_s.png"));///////////change she axesh
        piclabel->setFixedSize(100,100);

        namelabel=new QLabel(oUsers[index]->getUsername());

        delete_userButton=new QToolButton();
        delete_userButton->setMinimumSize(75,75);
        delete_userButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        ////icon
        delete_userButton->setIcon(QPixmap(":/resource/image/user_panel/delete.png"));///////
        delete_userButton->setIconSize(QSize(30, 30));
        delete_userButton->setText("Delete User");

        backpbt=new QToolButton();
        backpbt->setMinimumSize(75,75);
        backpbt->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        ////icon
        backpbt->setIcon(QPixmap(":/resource/image/user_panel/back.svg"));///////
        backpbt->setIconSize(QSize(30, 30));
        backpbt->setText("Back");

        rightlayout->addWidget(piclabel,0,Qt::AlignRight|Qt::AlignTop);
        rightlayout->addWidget(namelabel,0,Qt::AlignHCenter|Qt::AlignTop);
        rightlayout->addWidget(delete_userButton,0,Qt::AlignHCenter);
        rightlayout->addWidget(backpbt,0,Qt::AlignHCenter|Qt::AlignBottom);

    //row0
            row0box=new QGroupBox();
            row0layout=new QHBoxLayout();
            user_profileButton=new QToolButton();
            list_of_accountsButton=new QToolButton();
            user_entranceButton=new QToolButton();


            user_profileButton->setMinimumSize(75,75);
            list_of_accountsButton->setMinimumSize(75,75);
            user_entranceButton->setMinimumSize(75,75);




            user_profileButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            ////icon
            user_profileButton->setIcon(QPixmap(":/resource/image/user_panel/profile.png"));///////
            user_profileButton->setIconSize(QSize(30, 30));
            user_profileButton->setText("profile");

            list_of_accountsButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            ////icon
            list_of_accountsButton->setIcon(QPixmap(":/resource/image/user_panel/accs.png"));///////
            list_of_accountsButton->setIconSize(QSize(30, 30));
            list_of_accountsButton->setText("Accounts");

            user_entranceButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            ////icon
            user_entranceButton->setIcon(QPixmap(":/resource/image/user_panel/entrance.webp"));///////
            user_entranceButton->setIconSize(QSize(30, 30));
            user_entranceButton->setText("Entrance");

            row0layout->addWidget(user_profileButton);
            row0layout->addWidget(list_of_accountsButton);
            row0layout->addWidget(user_entranceButton);
            row0box->setLayout(row0layout);
            tool_layout->addWidget(row0box);
    //row1
    mainLayoutRow3=new QVBoxLayout();
    groupRow3=new QGroupBox("Profile");
    bottomlayout3=new QHBoxLayout();
    layoutRow3=new QGridLayout();
    NCLable=new QLabel("NationalCode: ");
    NCLineEdit=new QLineEdit();
    NCLineEdit->setValidator(new QIntValidator(this));
    QRegularExpression regex("^[a-zA-Z]*$");
    QValidator *alphaValidator = new QRegularExpressionValidator(regex, this);
    nameLable=new QLabel("Name: ");
    nameineEdit=new QLineEdit();
    nameineEdit->setValidator(alphaValidator);
    lastNameLable=new QLabel("Lastname: ");
    lastNameineEdit=new QLineEdit();
    lastNameineEdit->setValidator(alphaValidator);
    birthdateLable=new QLabel("Birthdate: ");
    dateEdit=new QDateEdit();
    userLable=new QLabel("Username: ");
    userLineEdit=new QLineEdit();
    showPass = new QCheckBox();
    passLable=new QLabel("Password: ");
    passLineEdit=new QLineEdit();
    passLable2=new QLabel("Confirm Password: ");
    passLineEdit2=new QLineEdit();
    passLineEdit->setEchoMode(QLineEdit::Password);
    passLineEdit2->setEchoMode(QLineEdit::Password);
    phonenumberLabel=new QLabel("Phonenumber: ");
    phonenumberled=new QLineEdit();
    phonenumberled->setValidator(new QIntValidator(this));
    emailLabel=new QLabel("Email: ");
    emailLineEdit=new QLineEdit();
    showEdit();
    edit_ok=new QPushButton("OK");
    edit_cancel=new QPushButton("Cancel");
    bottomlayout3->addWidget(edit_cancel);
    bottomlayout3->addWidget(edit_ok);
    bottomlayout3->setAlignment(Qt::AlignRight);

    layoutRow3->addWidget(NCLable,0,0);
        layoutRow3->addWidget(NCLineEdit,0,1);
        layoutRow3->addWidget(nameLable,1,0);
        layoutRow3->addWidget(nameineEdit,1,1);
        layoutRow3->addWidget(lastNameLable,2,0);
        layoutRow3->addWidget(lastNameineEdit,2,1);
        layoutRow3->addWidget(birthdateLable,3,0);
        layoutRow3->addWidget(dateEdit,3,1);
        layoutRow3->addWidget(phonenumberLabel,4,0);
        layoutRow3->addWidget(phonenumberled,4,1);
        layoutRow3->addWidget(userLable,5,0);
        layoutRow3->addWidget(userLineEdit,5,1);
        layoutRow3->addWidget(passLable,6,0);
        layoutRow3->addWidget(passLineEdit,6,1);
        layoutRow3->addWidget(passLable2,8,0);
        layoutRow3->addWidget(passLineEdit2,8,1);
        layoutRow3->addWidget(emailLabel,9,0);
        layoutRow3->addWidget(emailLineEdit,9,1);
        layoutRow3->addWidget(showPass,7,0,Qt::AlignLeft);
        mainLayoutRow3->addLayout(layoutRow3);
        mainLayoutRow3->addLayout(bottomlayout3);
        groupRow3->setLayout(mainLayoutRow3);
        //groupRow3->hide();
        tool_layout->addWidget(groupRow3);

        //row3
        show_entrance=new QGroupBox("Entrance Information");
        vlayout=new QVBoxLayout();
        table=new QTableWidget(0,2,this);
        inputHeader=new QTableWidgetItem("Entrance");
        outputHeader=new QTableWidgetItem("Exit");
        table->setColumnWidth(0,220);
        table->setColumnWidth(1,220);
        table->setFixedWidth(460);
        table->setHorizontalHeaderItem(0,inputHeader);
        table->setHorizontalHeaderItem(1,outputHeader);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);

        vlayout->addWidget(table);
        show_entrance->setLayout(vlayout);
        show_entrance->hide();
        tool_layout->addWidget(show_entrance);


        //
        mainlayout->addLayout(tool_layout);
                mainlayout->addLayout(rightlayout);

                setLayout(mainlayout);
                setFixedSize(600,400);

        connect(user_profileButton,SIGNAL(clicked()),this,SLOT(user_profileButton_clicked()));
        connect(list_of_accountsButton,SIGNAL(clicked()),this,SLOT(list_of_accountsButton_clicked()));
        connect(user_entranceButton,SIGNAL(clicked()),this,SLOT(user_entranceButton_clicked()));
        connect(delete_userButton,SIGNAL(clicked()),this,SLOT(delete_userButton_clicked()));
        connect(backpbt,SIGNAL(clicked()),this,SLOT(backToAdminPanel_sl()));
        connect(showPass,SIGNAL(stateChanged(int)),this,SLOT(showPass_sl(int)));
        connect(edit_cancel,SIGNAL(clicked()),this,SLOT(cancel_clicked()));
        connect(edit_ok,SIGNAL(clicked()),this,SLOT(ok_clicked()));
}
void user_panel::showEdit()
{
    nameineEdit->setText(oUsers[index]->getName());
    lastNameineEdit->setText(oUsers[index]->getlastName());
    passLineEdit->setText(oUsers[index]->getPassword());
    passLineEdit2->setText(oUsers[index]->getPassword());
    NCLineEdit->setText (QString::number((oUsers[index]->getNationalCode())));
    emailLineEdit->setText(oUsers[index]->getEmail());
    userLineEdit->setText(oUsers[index]->getUsername());
    phonenumberled->setText(oUsers[index]->getPhonenumber());
}
void user_panel::user_profileButton_clicked()
{
    if(groupRow3->isHidden())
    {
        showEdit();
        show_entrance->hide();
        groupRow3->show();
    }
   /* else
    {
        groupRow3->hide();
    }*/
    this->adjustSize();
}
void user_panel::list_of_accountsButton_clicked()
{
    if(oUsers[index]->getAccounts().size()!=0)
    {
        this->hide();
        listOfAccount = new accountofthisuser(index,false);
        listOfAccount->show();
        connect(listOfAccount,SIGNAL(backToAdmin_Sig()),this,SLOT(show()));
        connect(listOfAccount,SIGNAL(refreshAccsPage()),this,SLOT(list_of_accountsButton_clicked()));
    }
    else
    {
        QMessageBox::warning(this,"Warning","There is no account for this user yet");
        this->show();
    }

}

void user_panel::backToAdminPanel_sl()
{
    this->close();
    emit backToAdminPanel_sig();
}
void user_panel::user_entranceButton_clicked()
{
    if(show_entrance->isHidden())
    {
        for(int i=table->rowCount()-1;i>=0;i--)
        {
            table->removeRow(i);
        }
    for(int i=0;i<oUsers[index]->getLogActivity().size();i++)
    {
        QTableWidgetItem* Inputtemp=new QTableWidgetItem(oUsers[index]->getLogActivity()[i].entrance.toString(Qt::ISODate));
        QTableWidgetItem* Outputtemp= new QTableWidgetItem(oUsers[index]->getLogActivity()[i].exit.toString(Qt::ISODate));
        table->insertRow(i);
        table->setItem(i,0,Inputtemp);
        table->setItem(i,1,Outputtemp);
    }
        show_entrance->show();
        groupRow3->hide();

    }
    /*else
    {
        show_entrance->hide();
    }*/
    this->adjustSize();
}
void user_panel::delete_userButton_clicked()
{
        QMessageBox::StandardButton reply=QMessageBox::question(this,"delete user","Are you sure you want to delete this user?",QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::Yes)
            {
                for(int i=0;i<oUsers[index]->getAccounts().size();i++)
                {
                    if(!(typeid(*oUsers[index]->getAccounts()[i])==typeid(timeDeposit)))
                    {
                        saveAccount* temp = dynamic_cast<saveAccount*>(oUsers[index]->getAccounts()[i]);
                        if(temp->getMyCard())
                        {
                            if(typeid(*temp)==typeid(corporate))
                            {
                                corporate* tempptr = dynamic_cast<corporate*>(oUsers[index]->getAccounts()[i]);
                                if(!tempptr->getOtherUsers().contains(oUsers[index]->getUsername()))
                                {
                                    cards.remove(tempptr->getMyCard()->getCardId());
                                    delete tempptr->getMyCard();
                                    tempptr->setMyCardNULL();
                                }
                                else
                                {
                                    //hichi
                                }
                            }
                            else
                            {
                                QString cardId=temp->getMyCard()->getCardId();
                                delete cards[cardId];
                                cards.remove(cardId);
                                temp->setMyCardNULL();
                            }
                        }

                    }
                    //QString test= typeid(*(oUsers[index]->getAccounts()[i])).name();///////////////test

                    if(typeid(*(oUsers[index]->getAccounts()[i]))==typeid(corporate))
                    {
                        corporate* temp = dynamic_cast<corporate*>(oUsers[index]->getAccounts()[i]);
                        if(!temp->getOtherUsers().contains(oUsers[index]->getUsername()))
                        {
                            accounts.remove(findAccount(QString::number(temp->getAccountId())));
                            oUsers[index]->getAccounts().remove(i);
                            for(int i=0;i<temp->getOtherUsers().size();i++)
                            {
                                int finder=findUser(temp->getOtherUsers()[i]);
                                oUsers[finder]->getAccounts().remove(findAccount(oUsers[finder]->getAccounts(),QString::number(temp->getAccountId())));
                            }
                            delete temp;
                        }
                        else
                        {
                            oUsers[index]->getAccounts().remove(i);
                            for(int i=0;i<temp->getOtherUsers().size();i++)
                            {
                                if(temp->getOtherUsers()[i]==oUsers[index]->getUsername())
                                {
                                    temp->getOtherUsers().remove(i);
                                    break;
                                }
                            }
                        }

                    }
                    else
                    {
                        accounts.remove(findAccount(QString::number(oUsers[index]->getAccounts()[i]->getAccountId())));
                        delete oUsers[index]->getAccounts()[i];
                        oUsers[index]->getAccounts().remove(i);
                    }


            }
                delete oUsers[index];
                oUsers.remove(index);
                QMessageBox::information(this,"Information","User deleted successfully");
                backToAdminPanel_sl();
        }
}
void user_panel::showPass_sl(int _state)
{
    if(_state)
    {
        passLineEdit->setEchoMode(QLineEdit::Normal);
        passLineEdit2->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        passLineEdit->setEchoMode(QLineEdit::Password);
        passLineEdit2->setEchoMode(QLineEdit::Password);
    }
}
void user_panel::cancel_clicked()
{
    showEdit();
    this->adjustSize();
}
void user_panel::ok_clicked()
{
    QString text1 = NCLineEdit->text();
    QString text2 = nameineEdit->text();
    QString text3 = lastNameineEdit->text();
    QDate text4= dateEdit->date();
    QString text5 = userLineEdit->text();
    QString text6 = passLineEdit->text();
    QString text7 = passLineEdit2->text();
    QString text8 = emailLineEdit->text();
        if (text1.isEmpty()|text2.isEmpty()|text3.isEmpty()|text4.isNull()|text5.isEmpty()|text6.isEmpty()|text7.isEmpty())
          {  QMessageBox::information(this, tr("Empty Field"),
                tr("Please fill all the empty fields."));
            return;
        }
        else
        {
    QMessageBox::StandardButton reply=QMessageBox::question(this,"edit profile","Are you sure you want save this changes?");
   if (reply == QMessageBox::Yes)
   {
       QMessageBox::information(this,"successful","your changes saved");
       changProfile();
       this->adjustSize();
   }
        }
}

void user_panel::changProfile()
{
    oUsers[index]->setName(nameineEdit->text());
    oUsers[index]->setlastName(lastNameineEdit->text());
    oUsers[index]->setPassword(passLineEdit->text());
    oUsers[index]->setPassword(passLineEdit2->text());
    oUsers[index]->setNationalCode(NCLineEdit->text().toInt());
    oUsers[index]->setEmail(emailLineEdit->text());
    oUsers[index]->setUsername(userLineEdit->text());
    oUsers[index]->setPhonenumber(phonenumberled->text());
}
