#include "admin.h"
#include "container.h"
admin::admin(QString _username)


{
    mainlayout=new QHBoxLayout();
    tool_layout= new QVBoxLayout();

    //right
        rightlayout=new QVBoxLayout();

        piclabel= new QLabel();////////
        piclabel->setPixmap(QPixmap(":/resource/image/admin/admin_s.png"));
        piclabel->setFixedSize(100,100);

        namelabel=new QLabel(_username);

        logoutpbt=new QToolButton();
        logoutpbt->setMinimumSize(75,75);
        logoutpbt->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        logoutpbt->setIcon(QPixmap(":/resource/image/admin/logout.jpg"));
        logoutpbt->setIconSize(QSize(30, 30));
        logoutpbt->setText("Log Out");

        rightlayout->addWidget(piclabel,0,Qt::AlignRight|Qt::AlignTop);
        rightlayout->addWidget(namelabel,0,Qt::AlignHCenter|Qt::AlignTop);
        rightlayout->addWidget(logoutpbt,0,Qt::AlignHCenter|Qt::AlignBottom);

    logoAdmin = new QPixmap(":/resource/image/faraz2.png");
    setWindowIcon(*logoAdmin);
    //row0
    row0box=new QGroupBox();
        row0layout=new QHBoxLayout();
        manage_usersButton=new QToolButton();
        request_accountButton=new QToolButton();
        request_cardButton=new QToolButton();
        transaction_listButton=new QToolButton();
        manage_usersButton->setMinimumSize(75,75);
        request_accountButton->setMinimumSize(75,75);
        request_cardButton->setMinimumSize(75,75);
        transaction_listButton->setMinimumSize(75,75);

        manage_usersButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        manage_usersButton->setIcon(QPixmap(":/resource/image/admin/users.png"));///////
        manage_usersButton->setIconSize(QSize(30, 30));
        manage_usersButton->setText("users");

        request_accountButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        ////icon
        request_accountButton->setIcon(QPixmap(":/resource/image/admin/acc_reqs.png"));///////
        request_accountButton->setIconSize(QSize(30, 30));
        request_accountButton->setText("account requests");

        request_cardButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        ////icon
        request_cardButton->setIcon(QPixmap(":/resource/image/admin/card_reqs.svg"));///////
        request_cardButton->setIconSize(QSize(30, 30));
        request_cardButton->setText("card requests");

        transaction_listButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        ////icon
        transaction_listButton->setIcon(QPixmap(":/resource/image/admin/transactions.png"));///////
        transaction_listButton->setIconSize(QSize(30, 30));
        transaction_listButton->setText("transactions");

        row0layout->addWidget(manage_usersButton);
        row0layout->addWidget(transaction_listButton);
        row0layout->addWidget(request_accountButton);
        row0layout->addWidget(request_cardButton);

        row0box->setLayout(row0layout);
        tool_layout->addWidget(row0box);

    //row1
    row11box=new QGroupBox();
    row11box->setFlat(true);
    row11layout=new QVBoxLayout();
    //base
     row1box=new QGroupBox("manage users");
     row1layout=new QVBoxLayout();
     searchlayout=new QGridLayout();
     find_userButton=new QPushButton("find");
     add_userButton=new QPushButton("add");
     user_table=new QTableWidget(0,2);
     header1=new QTableWidgetItem("username");
     header2=new QTableWidgetItem("panel");
     user_table->setHorizontalHeaderItem(0,header1);
     user_table->setHorizontalHeaderItem(1,header2);
     user_table->setColumnWidth(0,300);
     user_table->setColumnWidth(1,310);
     user_table->setFixedWidth(630);

     user_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
     user_table->resizeRowsToContents();
     search_label=new QLabel("search by: ");
     search_combo=new QComboBox();
     search_combo->addItem("username");
     search_combo->addItem("account id");
     search_combo->addItem("card id");
     search_lineEdit=new QLineEdit();
     row1layout->addWidget(user_table);
     searchlayout->addWidget(search_label,0,0);
     searchlayout->addWidget(search_combo,0,1);
     searchlayout->addWidget(search_lineEdit,0,2);
     searchlayout->addWidget(find_userButton,0,3);
     searchlayout->addWidget(add_userButton,0,4);
     row1layout->addLayout(searchlayout);

     //add
     mainLayoutRow3=new QVBoxLayout();
     groupRow3=new QGroupBox("please fill the boxes");
     bottomlayout3=new QHBoxLayout();
     layoutRow3=new QFormLayout();
     NCLable=new QLabel("NationalCode: ");
     NCLineEdit=new QLineEdit();
     NCLineEdit->setFocus();
     NCLineEdit->setValidator(new QIntValidator);
     QRegularExpression regex("^[a-zA-Z]*$");
     QValidator *alphaValidator = new QRegularExpressionValidator(regex, this);
     nameLable=new QLabel("Name: ");
     nameineEdit=new QLineEdit();
     nameineEdit->setValidator(alphaValidator);
     lastNameLable=new QLabel("Lastname: ");
     lastNameineEdit=new QLineEdit();
     lastNameineEdit->setValidator(alphaValidator);
     birthdateLable=new QLabel("BirthDate: ");
     birthDateEdit=new QDateEdit();
     birthDateEdit->setCalendarPopup(true);
     userLable=new QLabel("UserName: ");
     newuserLineEdit=new QLineEdit();
     passLable=new QLabel("Password: ");
     passlable2=new QLabel("Confirm Password: ");
     newpassLineEdit=new QLineEdit();
     newpassLineEdit->setEchoMode(QLineEdit::Password);
     newpasslineEdit2=new QLineEdit();
     newpasslineEdit2->setEchoMode(QLineEdit::Password);
     phonenumberLabel=new QLabel("Phonenumber: ");
     phonenumberLineEdit=new QLineEdit();
     phonenumberLineEdit->setValidator(new QIntValidator);
     emailLabel=new QLabel("Email: ");
     emailLineEdit=new QLineEdit();

     ok=new QPushButton("OK");
     ok->setDefault(true);
     cancel=new QPushButton("Cancel");
     bottomlayout3->addWidget(cancel);
     bottomlayout3->addWidget(ok);
     bottomlayout3->setAlignment(Qt::AlignRight);

     powerPercentagelb = new QLabel("Password power:");
     powerPercentage = new QLabel();
     powerPercentagelb->hide();
     powerPercentage->hide();
     layoutRow3->addRow(NCLable,NCLineEdit);
     layoutRow3->addRow(nameLable,nameineEdit);
     layoutRow3->addRow(lastNameLable,lastNameineEdit);
     layoutRow3->addRow(birthdateLable,birthDateEdit);
     layoutRow3->addRow(userLable,newuserLineEdit);
     layoutRow3->addRow(passLable,newpassLineEdit);
     layoutRow3->addRow(powerPercentagelb,powerPercentage);
     layoutRow3->addRow(passlable2,newpasslineEdit2);
     layoutRow3->addRow(phonenumberLabel,phonenumberLineEdit);
     layoutRow3->addRow(emailLabel,emailLineEdit);

     mainLayoutRow3->addLayout(layoutRow3);
     mainLayoutRow3->addLayout(bottomlayout3);
     groupRow3->setLayout(mainLayoutRow3);
     groupRow3->hide();

     row1box->setLayout(row1layout);
     row11layout->addWidget(row1box);
     row11layout->addWidget(groupRow3);
     row11box->setLayout(row11layout);

     tool_layout->addWidget(row11box);
     //row11box->hide();

     //row2
     row2box=new QGroupBox("manage account request");
     row2layout=new QVBoxLayout();
     request_account_table=new QTableWidget(0,4,this);
     header21=new QTableWidgetItem("username");
     header22=new QTableWidgetItem("account type");
     header23=new QTableWidgetItem("primary credit");
     header24=new QTableWidgetItem("answer");
     request_account_table->setHorizontalHeaderItem(0,header21);
     request_account_table->setHorizontalHeaderItem(1,header22);
     request_account_table->setHorizontalHeaderItem(2,header23);
     request_account_table->setHorizontalHeaderItem(3,header24);
     request_account_table->setColumnWidth(0,150);
     request_account_table->setColumnWidth(1,150);
     request_account_table->setColumnWidth(2,150);
     request_account_table->setColumnWidth(3,150);
     request_account_table->setFixedWidth(620);
     request_account_table->resizeRowsToContents();
     row2layout->addWidget(request_account_table);
     row2box->setLayout(row2layout);
     tool_layout->addWidget(row2box);
     row2box->hide();

     //row3
     row3box=new QGroupBox("manage card request");
     row3layout=new QVBoxLayout();
     request_card_table=new QTableWidget(0,4,this);
     header31=new QTableWidgetItem("username");
     header32=new QTableWidgetItem("account id");
     header33=new QTableWidgetItem("account type");
     header34=new QTableWidgetItem("answer");
     request_card_table->setHorizontalHeaderItem(0,header31);
     request_card_table->setHorizontalHeaderItem(1,header32);
     request_card_table->setHorizontalHeaderItem(2,header33);
     request_card_table->setHorizontalHeaderItem(3,header34);
     request_card_table->setColumnWidth(0,150);
     request_card_table->setColumnWidth(1,150);
     request_card_table->setColumnWidth(2,150);
     request_card_table->setColumnWidth(3,150);
     request_card_table->setFixedWidth(620);
     request_card_table->resizeRowsToContents();
     row3layout->addWidget(request_card_table);
     row3box->setLayout(row3layout);
     tool_layout->addWidget(row3box);
     row3box->hide();

    //row4
     row4box=new QGroupBox("list of transactions");
     row4layout=new QVBoxLayout();
     transactin_list_table=new QTableWidget(1,4);
     header41=new QTableWidgetItem("time");
     header42=new QTableWidgetItem("origin account");
     header43=new QTableWidgetItem("destination account");
     header44=new QTableWidgetItem("cash");
     transactin_list_table->setHorizontalHeaderItem(0,header41);
     transactin_list_table->setHorizontalHeaderItem(1,header42);
     transactin_list_table->setHorizontalHeaderItem(2,header43);
     transactin_list_table->setHorizontalHeaderItem(3,header44);
     transactin_list_table->setColumnWidth(0,150);
     transactin_list_table->setColumnWidth(1,150);
     transactin_list_table->setColumnWidth(2,150);
     transactin_list_table->setColumnWidth(3,150);
     transactin_list_table->setFixedWidth(620);
     transactin_list_table->resizeRowsToContents();
     row4layout->addWidget(transactin_list_table);
     row4box->setLayout(row4layout);
     tool_layout->addWidget(row4box);
     row4box->hide();

     mainlayout->addLayout(tool_layout);
           mainlayout->addLayout(rightlayout);

     setLayout(mainlayout);
     setWindowTitle("Administrator");
     setFixedSize(800,500);

     oUser::clearMultiMap();
     saveAccount::clearCardMultiMap();
     refreshTable();
     connect(newpassLineEdit, SIGNAL(editingFinished()),this,SLOT(showPassStrong()));
     connect(manage_usersButton,SIGNAL(clicked()),this,SLOT(manage_users_clicked()));
     connect(find_userButton,SIGNAL(clicked()),this,SLOT(find_userButton_clicked()));
     connect(add_userButton,SIGNAL(clicked()),this,SLOT(add_userButton_clicked()));
     connect(ok,SIGNAL(clicked()),this,SLOT(ok_clicked()));
     connect(cancel,SIGNAL(clicked()),this,SLOT(cancel_clicked()));
     connect(request_accountButton,SIGNAL(clicked()),this,SLOT(request_accountButton_clicked()));
     connect(this,SIGNAL(clickedAccAndReq_sig(QString)),this,SLOT(AcceptAndReject_Clicked(QString)));
     //connect(this,SIGNAL(refreshAccreq()),this,SLOT(request_accountButton_clicked()));
     connect(request_cardButton,SIGNAL(clicked()),this,SLOT(request_cardButton_clicked()));
     connect(this,SIGNAL(clickedAccAndReq3_sig(QString)),this,SLOT(AcceptAndReject3_Clicked(QString)));
     //connect(this,SIGNAL(refreshCardReq()),this,SLOT(request_cardButton_clicked()));
     connect(transaction_listButton,SIGNAL(clicked()),this,SLOT(transaction_listButton_clicked()));
     connect(logoutpbt,SIGNAL(clicked()),this,SLOT(logout_sl()));
     connect(this,SIGNAL(clickedPanel_sig(int)),this,SLOT(user_panelButton_clicked(int)));

}

void admin::showEdit()
{
    NCLineEdit->clear();
    nameineEdit->clear();
    lastNameineEdit->clear();
    birthDateEdit->clear();
    newuserLineEdit->clear();
    newpassLineEdit->clear();
    newpasslineEdit2->clear();
    phonenumberLineEdit->clear();
    emailLineEdit->clear();
}

void admin:: refreshTable()
{

    for(int i=user_table->rowCount()-1;i>=0;i--)
    {
        user_table->removeRow(i);
    }
    user_panelButton.clear();
    user_label.clear();
    for(int i=0;i<oUsers.size();i++)
    {
       user_label.push_back(new QLabel(oUsers[i]->getUsername()));
       user_panelButton.push_back(new QPushButton("Panel"));
       user_panelButton[i]->setObjectName(QString::number(i));
       user_table->insertRow(i);
       user_table->setCellWidget(i,0,user_label[i]);
       user_table->setCellWidget(i,1,user_panelButton[i]);
       connect(user_panelButton[i],SIGNAL(clicked()),this,SLOT(clickedPanel_sl()));
    }
}
void admin:: user_panelButton_clicked(int i)
{
    panel=new user_panel(i);
    panel->show();
    connect(panel,SIGNAL(backToAdminPanel_sig()),this,SLOT(showAdminAgain()));
    refreshTable();
}
void admin::find_userButton_clicked()
{
    int finder=0;
    if(search_combo->currentIndex()==0)
    {
        finder = findUser(search_lineEdit->text());
    }
    else if(search_combo->currentIndex()==1)
    {
        finder = findAccount(search_lineEdit->text());
        if(finder != -1)
           finder = findUser(accounts[finder]->getOUserUsername());
    }
    else if(search_combo->currentIndex()==2)
    {
        if(cards.contains(search_lineEdit->text()))
           finder = findUser(cards[search_lineEdit->text()]->getOUserId());
        else
           finder = -1;
    }
    if(finder == -1)
    {
        QMessageBox::critical(this,"Error","User not found!!!");
    }
    else
    {
        panel=new user_panel(finder);
        this->hide();
        panel->show();
        connect(panel,SIGNAL(backToAdminPanel_sig()),this,SLOT(showAdminAgain()));
    }
    search_lineEdit->clear();
}
void admin::add_userButton_clicked()
{
   row1box->hide();
   NCLineEdit->clear();
   nameineEdit->clear();
   lastNameineEdit->clear();
   birthDateEdit->clear();
   newuserLineEdit->clear();
   newpassLineEdit->clear();
   newpasslineEdit2->clear();
   phonenumberLineEdit->clear();
   powerPercentagelb->hide();
   powerPercentage->hide();
   groupRow3->show();
   this->adjustSize();
}
void admin::ok_clicked()
{
    QString text1 = NCLineEdit->text();
    QString text2 = nameineEdit->text();
    QString text3 = lastNameineEdit->text();
    QDate text4=birthDateEdit->date();
    QString text5 = newuserLineEdit->text();
    QString text6 = newpassLineEdit->text();
    QString text7= newpasslineEdit2->text();
    QString text8= phonenumberLineEdit->text();
        if (text1.isEmpty()|text2.isEmpty()|text3.isEmpty()|text4.isNull()|text5.isEmpty()|text6.isEmpty()|text7.isEmpty()|text8.isEmpty())
          {
            QMessageBox::warning(this, tr("Empty Field"),
                tr("Please fill all the empty fields."));
            return;
        }
        else if(!check_username(text5,this))
        {
            return;
        }
        else if(text6!=text7)
        {
            QMessageBox::warning(this, tr("Error"),
                tr("Passwords didnt match!!"));
            return;
        }
        else if(password_strength(text6,&powerPass))
        {
            QMessageBox::warning(this, tr("Error"),
                tr("Password is not strong enough!"));
            return;
        }
        else{
                oUsers.push_back(new oUser(nameineEdit->text(),lastNameineEdit->text(),NCLineEdit->text().toInt(),newuserLineEdit->text(),newpassLineEdit->text(),birthDateEdit->date(),phonenumberLineEdit->text(),emailLineEdit->text()));
                QMessageBox::information(this,"Message","User added successfully.");
                refreshTable();
                row1box->show();
                groupRow3->hide();
        }
        this->adjustSize();
        //make_account();///////////////////////////////////////////
}
void admin::cancel_clicked()
{
   row1box->show();
   groupRow3->hide();
   this->adjustSize();
}
void admin::request_accountButton_clicked()
{
    if(row2box->isHidden())
    {
        if(oUser::getAccountRequestList().isEmpty())
        {
            QMessageBox::information(this,"Information","There is no account request!!!");
        }

        refreshAccountRequestTable();
        groupRow3->hide();
        row11box->hide();
        row2box->show();
        row3box->hide();
        row4box->hide();
    }
    /*else
    {
        row2box->hide();
    }*/
    this->adjustSize();
}
void admin::request_cardButton_clicked()
{
    if(row3box->isHidden())
    {
        if(saveAccount::getCardRequestList().isEmpty())
        {
            QMessageBox::information(this,"Information","There is no card request!!!");
        }
        refreshCardRequestTable();
        groupRow3->hide();
        row11box->hide();
        row2box->hide();
        row3box->show();
        row4box->hide();
    }
    /*else
    {
        row3box->hide();
    }*/
    this->adjustSize();
}
void admin::transaction_listButton_clicked()
{
    if(row4box->isHidden())
    {
        if(oUser::getAllTransactions().isEmpty())
        {
            QMessageBox::information(this,"Information","There is no transactions!!!");
        }
        for(int i=transactin_list_table->rowCount()-1;i>=0;i--)
        {
            transactin_list_table->removeRow(i);
        }
            QMultiMap<int,transaction>:: iterator settrans = oUser::getAllTransactions().begin();
            int i=0;
            for(;settrans != oUser::getAllTransactions().end();settrans++)
              {
                    QTableWidgetItem* timetemp=new QTableWidgetItem(settrans->dateTransaction.toString(Qt::ISODate));
                    QTableWidgetItem* originAccounttemp= new QTableWidgetItem(QString::number(settrans.key()));
                    QTableWidgetItem* destinationAccounttemp= new QTableWidgetItem(QString::number(settrans->accountId));
                    QTableWidgetItem* cashtemp= new QTableWidgetItem(QString::number(settrans->amount));
                    transactin_list_table->insertRow(i);
                    transactin_list_table->setItem(i,0,timetemp);
                    transactin_list_table->setItem(i,1,originAccounttemp);
                    transactin_list_table->setItem(i,2,destinationAccounttemp);
                    transactin_list_table->setItem(i,3,cashtemp);
                    i++;
               }
        groupRow3->hide();
        row11box->hide();
        row2box->hide();
        row3box->hide();
        row4box->show();
    }
    /*else
    {
        row4box->hide();
    }*/
    this->adjustSize();
}

void admin::logout_sl()
{
    this->close();
    emit logout();
}

void admin::clickedPanel_sl()
{
    this->hide();
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    emit clickedPanel_sig(buttonSender->objectName().toInt());
}
void admin::manage_users_clicked()
{
    if(row11box->isHidden())
    {
        refreshTable();
        row11box->show();
        row1box->show();
        groupRow3->hide();

        row2box->hide();
        row3box->hide();
        row4box->hide();
    }
    /*else
    {
        row1box->hide();
        groupRow3->hide();
        row11box->hide();
        this->adjustSize();
    }*/
}
void admin::clickedAccAndRej_sl()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    emit clickedAccAndReq_sig(buttonSender->objectName());
}

void admin::AcceptAndReject_Clicked(QString _namepbn)
{
    int numberpbn = _namepbn[1].digitValue();
    QMultiMap<QString,accreq>:: iterator setReq = oUser::getAccountRequestList().begin();
    setReq+numberpbn;
    if(_namepbn[0]=="p")
    {
        int indexUser = findUser(setReq.key());
        if(setReq.value().accType == "Saving Account")
        {
            saveAccount* saveAccountTemp = new saveAccount(setReq->balance,setReq.key());
            accounts.push_back(saveAccountTemp);
            oUsers[indexUser]->getAccounts().push_back(saveAccountTemp);
        }
        else if(setReq.value().accType == "ShortTerm Account")
        {
            shortTerm* shortTermTemp = new shortTerm(setReq->balance,setReq.key());
            accounts.push_back(shortTermTemp);
            oUsers[indexUser]->getAccounts().push_back(shortTermTemp);
        }
        else if(setReq.value().accType == "TimeDeposit Account")
        {
            timeDeposit* timeDepositTemp = new timeDeposit(setReq->balance,setReq.key());
            accounts.push_back(timeDepositTemp);
            oUsers[indexUser]->getAccounts().push_back(timeDepositTemp);
        }
        else
        {
            corporate* corporateTemp = new corporate(setReq->balance,setReq.key(),setReq->others.toVector());
            QString others;
            for(int i=0;i<corporateTemp->getOtherUsers().size();i++)
            {
                others+=corporateTemp->getOtherUsers()[i]+" ";
            }
            QMessageBox::StandardButton reply=QMessageBox::question(this,"Question",tr("This account also will be added for this users\n \'%1\' ").arg(others));
            if (reply == QMessageBox::No)
            {
                return;
            }
            accounts.push_back(corporateTemp);
            oUsers[indexUser]->getAccounts().push_back(corporateTemp);
            for(int i=0;i<corporateTemp->getOtherUsers().size();i++)
            {
                oUsers[findUser(corporateTemp->getOtherUsers()[i])]->getAccounts().push_back(corporateTemp);
            }
        }
    }
    oUser::getAccountRequestList().erase(setReq);
    refreshAccountRequestTable();
}
void admin::clickedAccAndRej3_sl()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    emit clickedAccAndReq3_sig(buttonSender->objectName());
}
void admin::AcceptAndReject3_Clicked(QString _namepbn)
{
    int numberpbn = _namepbn[1].digitValue();
    QMultiMap<QString,cardreq>:: iterator setcardReq = saveAccount::getCardRequestList().begin();
    setcardReq+numberpbn;
    if(_namepbn[0]=="p")
    {
        card* cardTemp = new card(setcardReq->accountId,setcardReq.key());
        saveAccount* temp = dynamic_cast<saveAccount*>(oUsers[findUser(setcardReq.key())]->getAccounts()[findAccount(QString::number(setcardReq.value().accountId))]);
        temp->setMyCard(cardTemp);
        saveAccount* temp2 = dynamic_cast<saveAccount*>(accounts[findAccount(QString::number(setcardReq.value().accountId))]);
        temp2->setMyCard(cardTemp);
        cards.insert(temp2->getMyCard()->getCardId(),cardTemp);

    }
    saveAccount::getCardRequestList().erase(setcardReq);
    refreshCardRequestTable();
}
void admin::showPassStrong()
{
    password_strength(newpassLineEdit->text(),&powerPass);
    powerPercentage->setText(QString::number(powerPass)+"%");
    powerPercentagelb->show();
    powerPercentage->show();
    newpasslineEdit2->setFocus();
}

void admin::showAdminAgain()
{
    /*row1box->hide();
    row11box->hide();*/
    this->adjustSize();
    this->show();
}

void admin::refreshCardRequestTable()
{
    for(int i=request_card_table->rowCount()-1;i>=0;i--)
    {
        request_card_table->removeRow(i);
    }
    rejectButton3.clear();
    acceptButton3.clear();
    buttonlayout3.clear();
    button_box3.clear();
    QMultiMap<QString,cardreq>:: iterator setTrans = saveAccount::getCardRequestList().begin();
    int i =0;
    for (;setTrans!=saveAccount::getCardRequestList().end(); setTrans++)
    {
        QTableWidgetItem* usernametemp=new QTableWidgetItem(setTrans.key());
        QTableWidgetItem* accountIdtemp= new QTableWidgetItem(QString::number(setTrans->accountId));
        QTableWidgetItem* accountTypetemp= new QTableWidgetItem(setTrans->accType);
        request_card_table->insertRow(i);
        request_card_table->setRowHeight(i,60);
        request_card_table->setItem(i,0,usernametemp);
        request_card_table->setItem(i,1,accountIdtemp);
        request_card_table->setItem(i,2,accountTypetemp);
        rejectButton3.push_back(new QPushButton("reject"));
        rejectButton3[i]->setObjectName("r"+QString::number(i));
        acceptButton3.push_back(new QPushButton("accept"));
        acceptButton3[i]->setObjectName("p"+QString::number(i));
        buttonlayout3.push_back(new QHBoxLayout());
        buttonlayout3[i]->addWidget(acceptButton3[i]);
        buttonlayout3[i]->addWidget(rejectButton3[i]);
        button_box3.push_back(new QGroupBox());
        button_box3[i]->setLayout(buttonlayout3[i]);
        request_card_table->setCellWidget(i,3,button_box3[i]);
        connect(acceptButton3[i],SIGNAL(clicked()),this,SLOT(clickedAccAndRej3_sl()));
        connect(rejectButton3[i],SIGNAL(clicked()),this,SLOT(clickedAccAndRej3_sl()));
        i++;
    }
}

void admin::refreshAccountRequestTable()
{
    for(int i=request_account_table->rowCount()-1;i>=0;i--)
    {
        request_account_table->removeRow(i);
    }
    rejectButton.clear();
    acceptButton.clear();
    buttonlayout.clear();
    button_box.clear();
    QMultiMap<QString,accreq>:: iterator setReq = oUser::getAccountRequestList().begin();
    int i =0;
    for (;setReq!=oUser::getAccountRequestList().end(); setReq++)
    {
        request_account_table->insertRow(i);
        request_account_table->setRowHeight(i,60);
        request_account_table->setItem(i,0,new QTableWidgetItem(setReq.key()));
        request_account_table->setItem(i,1,new QTableWidgetItem(setReq->accType));
        request_account_table->setItem(i,2,new QTableWidgetItem(QString::number(setReq->balance)));
        rejectButton.push_back(new QPushButton("reject"));
        rejectButton[i]->setObjectName("r"+QString::number(i));
        acceptButton.push_back(new QPushButton("accept"));
        acceptButton[i]->setObjectName("p"+QString::number(i));
        buttonlayout.push_back(new QHBoxLayout());
        buttonlayout[i]->addWidget(acceptButton[i]);
        buttonlayout[i]->addWidget(rejectButton[i]);
        button_box.push_back(new QGroupBox());
        button_box[i]->setLayout(buttonlayout[i]);
        request_account_table->setCellWidget(i,3,button_box[i]);
        connect(acceptButton[i],SIGNAL(clicked()),this,SLOT(clickedAccAndRej_sl()));
        connect(rejectButton[i],SIGNAL(clicked()),this,SLOT(clickedAccAndRej_sl()));
        i++;
    }
}
