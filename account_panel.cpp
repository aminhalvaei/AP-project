#include "account_panel.h"
#include "container.h"
QMap<QString,card*> cards;
account_panel::account_panel(int _user_index,int _accounts_index,int _account_oUsers_index,bool _isUser,QString _title)
{
    mainLayout= new QHBoxLayout();
     tool_layout=new QVBoxLayout();
    user_index =_user_index;
    accounts_index = _accounts_index;
    account_oUsers_index = _account_oUsers_index;
    isUser = _isUser;
    logoAccountPanel = new QPixmap(":/resource/image/faraz2.png");
    setWindowIcon(*logoAccountPanel);
    setWindowTitle("Account Panel");

    //right
    rightlayout=new QVBoxLayout();

    piclabel= new QLabel();////////
    piclabel->setPixmap(QPixmap(":/resource/image/account_panel/account_pic_s.png"));///////////change she axesh
    piclabel->setFixedSize(100,100);

    namelabel=new QLabel();

    backToListOfAccs=new QToolButton();
    backToListOfAccs->setMinimumSize(75,75);
    backToListOfAccs->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ////icon
    backToListOfAccs->setIcon(QPixmap(":/resource/image/account_panel/back.svg"));///////
    backToListOfAccs->setIconSize(QSize(30, 30));
    backToListOfAccs->setText("Back");

    rightlayout->addWidget(piclabel,0,Qt::AlignRight|Qt::AlignTop);
    rightlayout->addWidget(namelabel,0,Qt::AlignHCenter|Qt::AlignTop);
    rightlayout->addWidget(backToListOfAccs,0,Qt::AlignHCenter|Qt::AlignBottom);

    //row1
    //row1
        layoutRow1= new QHBoxLayout();
        groupRow1 = new QGroupBox("Account Services");

        balanceBottom=new QToolButton();
        transactionBottom=new QToolButton();
        transactionListBottom=new QToolButton();
        cardBottom=new QToolButton();
        dynamicPasswordBottom=new QToolButton();

        balanceBottom->setMinimumSize(75,75);
        transactionBottom->setMinimumSize(75,75);
        transactionListBottom->setMinimumSize(75,75);
        cardBottom->setMinimumSize(75,75);
        dynamicPasswordBottom->setMinimumSize(75,75);

            balanceBottom->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            ////icon
            balanceBottom->setIcon(QPixmap(":/resource/image/account_panel/balance.jpg"));///////
            balanceBottom->setIconSize(QSize(30, 30));
            balanceBottom->setText("Balance");

            transactionBottom->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            ////icon
            transactionBottom->setIcon(QPixmap(":/resource/image/account_panel/transactions.png"));///////
            transactionBottom->setIconSize(QSize(30, 30));
            transactionBottom->setText("Transaction");

            transactionListBottom->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            ////icon
            transactionListBottom->setIcon(QPixmap(":/resource/image/account_panel/tlist.webp"));///////
            transactionListBottom->setIconSize(QSize(30, 30));
            transactionListBottom->setText("Transaction List");

            cardBottom->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            ////icon
            cardBottom->setIcon(QPixmap(":/resource/image/account_panel/card.jpg"));///////
        cardBottom->setIconSize(QSize(30, 30));
        cardBottom->setText("Card");

        dynamicPasswordBottom->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            ////icon
        dynamicPasswordBottom->setIcon(QPixmap(":/resource/image/account_panel/dpass.png"));///////
        dynamicPasswordBottom->setIconSize(QSize(30, 30));
        dynamicPasswordBottom->setText("DynamicPassword");
    if(typeid(*accounts[_accounts_index])==typeid (timeDeposit))
    {
        cardBottom->setEnabled(false);
    }
    layoutRow1->addWidget(balanceBottom);
    layoutRow1->addWidget(transactionBottom);
    layoutRow1->addWidget(transactionListBottom);
    layoutRow1->addWidget(cardBottom);
    layoutRow1->addWidget(dynamicPasswordBottom);

    groupRow1->setLayout(layoutRow1);
        tool_layout->addWidget(groupRow1);

    //row2 (balance)
    groupRow2 = new QGroupBox("Balance");
    backBottom=new QPushButton("back");
    hlayout=new QGridLayout();
    balance_lable=new QLabel("Balance ($): ");
    balance_lable2=new QLabel("");
    hlayout->addWidget(balance_lable,0,0);
    hlayout->addWidget(balance_lable2,0,1);
    hlayout->addWidget(backBottom,1,1);
    groupRow2->setLayout(hlayout);
    tool_layout->addWidget(groupRow2);
    groupRow2->hide();

    connect(balanceBottom,SIGNAL(clicked()),this,SLOT(get_balance()));
    connect(backBottom,SIGNAL(clicked()),this,SLOT(back_clicked()));

    //row 3 transaction
    mainLayoutRow3=new QVBoxLayout();
    accountIdslayout=new QHBoxLayout();
    fieldslayout=new QHBoxLayout();
    pbtslayout=new QHBoxLayout();
    destinationAccountIdlbl=new QLabel("Destination Account ID:");
    amountlbl=new QLabel("Amount:");
    destinationAccountIdled=new QLineEdit();
    destinationAccountIdled->setValidator(new QIntValidator(1000000000,999999999,this));
    amountled=new QLineEdit();
    amountled->setValidator(new QIntValidator(1,1000000000));
    submitpbt=new QPushButton("submit");
    cancelpbt=new QPushButton("cancel");
    pbtslayout->addWidget(submitpbt);
    pbtslayout->addWidget(cancelpbt);
    accountIdslayout->addWidget(destinationAccountIdlbl);
    accountIdslayout->addWidget(destinationAccountIdled);


    fieldslayout->addWidget(amountlbl);
    fieldslayout->addWidget(amountled);

    mainLayoutRow3->addLayout(accountIdslayout);
    mainLayoutRow3->addLayout(fieldslayout);
    mainLayoutRow3->addLayout(pbtslayout);

    groupRow3=new QGroupBox();
    groupRow3->setLayout(mainLayoutRow3);
    tool_layout->addWidget(groupRow3);
    groupRow3->hide();

    connect(transactionBottom,SIGNAL(clicked()),this,SLOT(transaction_clicked()));
    connect(cancelpbt,SIGNAL(clicked()),this,SLOT(cancel_sl()));
    connect(submitpbt,SIGNAL(clicked()),this,SLOT(submit_sl()));

    //row4
    //10 gardesh
    groupRow4=new QGroupBox();
    transTable = new QTableWidget();
    groupRow4=new QGroupBox("Transactions Information");
    transTable=new QTableWidget(0,4,this);
    desAccountId =new QTableWidgetItem("Destination ID");
    sorAccountId =new QTableWidgetItem("Source ID");
    transDate=new QTableWidgetItem("Date");
    amount=new QTableWidgetItem("Amount");
    transTable->setColumnWidth(0,112);
    transTable->setColumnWidth(1,112);
    transTable->setColumnWidth(2,112);
    transTable->setColumnWidth(3,112);
    transTable->setFixedWidth(460);
    transTable->setHorizontalHeaderItem(0,sorAccountId);
    transTable->setHorizontalHeaderItem(1,desAccountId);
    transTable->setHorizontalHeaderItem(2,amount);
    transTable->setHorizontalHeaderItem(3,transDate);
    transTable->resizeRowsToContents();
    transTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    backpbt=new QPushButton("back");
    pdfButton= new QPushButton("PDF");
    hpbnsLayout=new QHBoxLayout();
    hpbnsLayout->addWidget(pdfButton);
    hpbnsLayout->addWidget(backpbt);
    hpbnsLayout->setAlignment(Qt::AlignHCenter);
    vlayout=new QVBoxLayout();
    vlayout->addWidget(transTable);
    vlayout->addLayout(hpbnsLayout);
    groupRow4->setLayout(vlayout);
    groupRow4->hide();
    tool_layout->addWidget(groupRow4);
    connect(transactionListBottom,SIGNAL(clicked()),this,SLOT(show_transaction_list()));
    connect(pdfButton,SIGNAL(clicked()),this,SLOT(pdf_dialog()));
    connect(backpbt,SIGNAL(clicked()),this,SLOT(backpbt_sl()));
    //row5

    groupRow5=new QGroupBox();
    cardFormLayout = new QFormLayout();
    cardIdlbl =new QLabel("Card ID:");
    cardIdlbl2 =new QLabel();
    cvv2lbl =new QLabel("CVV2:");
    cvv2lbl2 =new QLabel();
    datelbl =new QLabel("Expiration Date:");
    datelbl2 =new QLabel();
    userNamelbl  =new QLabel("User Name:");
    userNamelbl2 =new QLabel();
    accountIdlbl =new QLabel("Account ID:");
    accountIdlbl2 =new QLabel();
    backpbn = new QPushButton("back");
    cardFormLayout->addRow(userNamelbl,userNamelbl2);
    cardFormLayout->addRow(accountIdlbl,accountIdlbl2);
    cardFormLayout->addRow(cardIdlbl,cardIdlbl2);
    cardFormLayout->addRow(cvv2lbl,cvv2lbl2);
    cardFormLayout->addRow(datelbl,datelbl2);
    //Admin
    if(!isUser)
    {
        removepbn = new QPushButton("Remove");
        statuspbn = new QPushButton();
        pbnsLayout = new QHBoxLayout();
        pbnsLayout->addWidget(removepbn);
        pbnsLayout->addWidget(statuspbn);
        pbnsLayout->addWidget(backpbn);
        saveAccount* temp = dynamic_cast<saveAccount*>(accounts[accounts_index]);
        if(temp!=NULL)
        {
            if(temp->getMyCard()!=nullptr)
            {
                if(temp->getMyCard()->getStatus())
                {
                   statuspbn->setText("Deactive");
                }
                else
                 {
                   statuspbn->setText("Active");
                 }
            }
        }
        cardFormLayout->setLayout(5,QFormLayout::FieldRole,pbnsLayout);
    }
    else
    {
        cardFormLayout->addWidget(backpbn);
    }
    if(!isUser)
    {
        connect(removepbn,SIGNAL(clicked()),this,SLOT(remove_clicked()));
        connect(statuspbn,SIGNAL(clicked()),this,SLOT(status_clicked()));
    }
        connect(backpbn,SIGNAL(clicked()),this,SLOT(backFromCard_clicked()));
    groupRow5->setLayout(cardFormLayout);
    groupRow5->hide();
    tool_layout->addWidget(groupRow5);
    connect(cardBottom,SIGNAL(clicked()),this,SLOT(card_clicked()));
    connect(backToListOfAccs,SIGNAL(clicked()),this,SLOT(backToAccs_clicked()));

    //row6

    timerInt = 120;
    dynamicGroup= new QGroupBox();
    dynamicGrid = new QGridLayout;
    dynamiclb = new QLabel("Dynamic Password: ");
    dynamicPasslb = new QLabel();
    timerlb = new QLabel("Timer: ");
    timerNumber = new QLabel();
    dynamic_timer = new QTimer();
    backDynamicBottom=new QPushButton("back");
    dynamicGrid->addWidget(dynamiclb,0,0);
    dynamicGrid->addWidget(dynamicPasslb,0,1);
    dynamicGrid->addWidget(timerlb,1,0);
    dynamicGrid->addWidget(timerNumber,1,1);
    dynamicGrid->addWidget(backDynamicBottom,2,1);
    dynamicGroup->setLayout(dynamicGrid);
    dynamicGroup->hide();
    tool_layout->addWidget(dynamicGroup);

    connect(backDynamicBottom,SIGNAL(clicked()),this,SLOT(backDynamic_clicked()));
    connect(dynamicPasswordBottom,SIGNAL(clicked()),this,SLOT(dynamicShow_sl()));
    connect(dynamic_timer,SIGNAL(timeout()),this,SLOT(showDynamicPass_sl()));




    if(typeid(accounts[accounts_index])==typeid(timeDeposit*))
    {
        cardBottom->setEnabled(false);
    }
    mainLayout->addLayout(tool_layout);
        mainLayout->addLayout(rightlayout);
    setLayout(mainLayout);

}
void account_panel::get_balance()
{
    if(groupRow2->isHidden())
    {
        accounts[accounts_index]->interestSettlement();
        balance_lable2->setNum(accounts[accounts_index]->getBalance());
        groupRow3->hide();
        groupRow4->hide();
        groupRow5->hide();
        groupRow2->show();
    }
    else
    {
         groupRow2->hide();
    }
    this->adjustSize();

}
void account_panel::back_clicked()
{
 groupRow2->hide();
 this->adjustSize();
}
void account_panel::cancel_sl()
{
    destinationAccountIdled->clear();
    amountled->clear();
    groupRow3->hide();
    this->adjustSize();
}
void account_panel::submit_sl()
{
    int desAccountIndex = findAccount(destinationAccountIdled->text());
    if(destinationAccountIdled->text()!="" && amountled->text() !="")
    {
        if(desAccountIndex != -1)
        {
            if(accounts[desAccountIndex]->getStatus())
            {
            QMessageBox::StandardButton reply=QMessageBox::question(this,"Transaction",
            tr("Are you sure that you want to transfer \'%1\' to \'%2\'?").arg(amountled->text()).arg(accounts[desAccountIndex]->getOUserUsername()));
                   if (reply == QMessageBox::Yes)
                    {
                       transaction* newTrans = new transaction();
                       calculateBalance(accounts_index,desAccountIndex,amountled->text().toUInt(),this);
                       newTrans->amount = amountled->text().toUInt();
                       newTrans->accountId = destinationAccountIdled->text().toInt();
                       newTrans->dateTransaction = QDateTime::currentDateTime();
                       //oUsers[user_index]->getAccounts()[accounts_index]->getTransactions().push_back(*newTrans);
                       accounts[accounts_index]->getTransactions().push_back(*newTrans);
                       oUser::getAllTransactions().insert(accounts[accounts_index]->getAccountId(),*newTrans);
                       transaction* newdesTrans = new transaction();
                       newdesTrans->amount = amountled->text().toUInt();
                       newdesTrans->accountId = accounts[accounts_index]->getAccountId();
                       newdesTrans->dateTransaction = QDateTime::currentDateTime();
                       accounts[findAccount(destinationAccountIdled->text())]->getTransactions().push_back(*newdesTrans);
                   }
            }
            else
            {
                QMessageBox::critical(this,"Error","The account you want to trade with is deactive!!!");
                return;
            }
        }
        else
        {
           QMessageBox::critical(this,"Error","There is no account with this ID!!!");
           return;
        }
    }
    else
    {
        QMessageBox::warning(this, tr("Empty Field"),
            tr("Please fill all the empty fields."));
        return;
    }
    destinationAccountIdled->clear();
    amountled->clear();
    groupRow3->hide();
    this->adjustSize();
}
void account_panel::show_transaction_list()
{
    if(groupRow4->isHidden())
    {
        for(int i=transTable->rowCount()-1;i>=0;i--)
        {
            transTable->removeRow(i);
        }
    for(int i=0;i<accounts[accounts_index]->getTransactions().size();i++)
    {
        if(i<=10)
        {
        QTableWidgetItem* zerotemp= new QTableWidgetItem(QString::number(accounts[accounts_index]->getAccountId()));
        QTableWidgetItem* firsttemp= new QTableWidgetItem(QString::number(accounts[accounts_index]->getTransactions()[i].accountId));
        QTableWidgetItem* secondtemp= new QTableWidgetItem(QString::number(accounts[accounts_index]->getTransactions()[i].amount));
        QTableWidgetItem* thirdtemp= new QTableWidgetItem(accounts[accounts_index]->getTransactions()[i].dateTransaction.toString(Qt::ISODate));
        transTable->insertRow(i);
        transTable->setItem(i,0,zerotemp);
        transTable->setItem(i,1,firsttemp);
        transTable->setItem(i,2,secondtemp);
        transTable->setItem(i,3,thirdtemp);
        }
        else
           break;
    }
        groupRow2->hide();
        groupRow3->hide();
        groupRow5->hide();
        groupRow4->show();

    }
    else
    {
        groupRow4->hide();
    }
    this->adjustSize();
}

void account_panel::remove_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Question","Are you sure?",QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            saveAccount* tempptr = dynamic_cast<saveAccount*>(oUsers[user_index]->getAccounts()[account_oUsers_index]);
            if(typeid(*tempptr)==typeid(corporate))
            {
                corporate* tempptr = dynamic_cast<corporate*>(oUsers[user_index]->getAccounts()[account_oUsers_index]);
                if(!tempptr->getOtherUsers().contains(oUsers[user_index]->getUsername())) //head
                {
                    cards.remove(cardIdlbl2->text());
                    corporate* temp = dynamic_cast<corporate*>(accounts[accounts_index]);
                    temp->setCardReqStatus(false);//added by amin
                    delete temp->getMyCard();
                    temp->setMyCardNULL();
                    QMessageBox::information(this,"Information","Card deleted successfully");
                }
                else
                {
                    QMessageBox::critical(this,"Error","admin just can remove card by entering with head account!!!");
                }

            }
            else
            {
                cards.remove(cardIdlbl2->text());
                tempptr->setCardReqStatus(false);
                delete tempptr->getMyCard();
                tempptr->setMyCardNULL();
                QMessageBox::information(this,"Information","Card deleted successfully");
            }
        }

        groupRow5->close();
        this->adjustSize();
}

void account_panel::status_clicked()
{
    if(statuspbn->text()=="Active")
    {
        saveAccount* tempptr = dynamic_cast<saveAccount*>(oUsers[user_index]->getAccounts()[account_oUsers_index]);
        tempptr->getMyCard()->setStatus(true);
        statuspbn->setText("Deactive");
    }
    else
    {
        saveAccount* tempptr = dynamic_cast<saveAccount*>(oUsers[user_index]->getAccounts()[account_oUsers_index]);
        tempptr->getMyCard()->setStatus(false);
        statuspbn->setText("Active");
    }
}

void account_panel::backFromCard_clicked()
{
    groupRow5->hide();
    this->adjustSize();
}

void account_panel::backToAccs_clicked()
{
    this->close();
    emit backToAccs_sig();
}

void account_panel::pdf_dialog()
{
    if(transTable->rowCount()==0)
    {
        QMessageBox::warning(this,"Warning","There is no transaction yet!!!");
        return;
    }
    QString path=QFileDialog::getSaveFileName(this,tr("Save file"),"/New transactions.pdf",tr("PDF(*.pdf)"));
    QPdfWriter writer(path);
    //writer.setPageSize(QPagedPaintDevice::A4);
    writer.setPageMargins(QMargins(30, 30, 30, 30));
    QPainter painter(&writer);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Times", 10));
    QRect r = painter.viewport();
    QFont headerFont("Times New Roman", 8);
    QFont titleFont("Times New Roman", 14, QFont::Bold);
    QTextCharFormat txtformat = QTextCharFormat();
    //QTextDocument doc;
    //QTextCursor* cursor = new QTextCursor(&doc);
    txtformat.setFont(headerFont);
    QString line;
    line+="Transactions Information\n\n";
    line+="   Destination ID   ";
    line+="Source ID   ";
    line+="Amount   ";
    line+="Date\n";
    for(int i=0;i<transTable->rowCount();i++)
    {
    line+=QString::number(i+1)+") ";
    line+=(QString::number(accounts[accounts_index]->getAccountId()))+"   ";
    line+=(QString::number(accounts[accounts_index]->getTransactions()[i].accountId))+"   ";
    line+=(QString::number(accounts[accounts_index]->getTransactions()[i].amount))+"   ";
    line+=(accounts[accounts_index]->getTransactions()[i].dateTransaction.toString(Qt::ISODate));
    line+="\n";
    }
    painter.drawText(r, Qt::AlignTop, line);
    line.clear();
    painter.end();
}

void account_panel::backpbt_sl()
{
    groupRow4->hide();
    this->adjustSize();
}

void account_panel::card_clicked()
{
    saveAccount* temp = dynamic_cast<saveAccount*>(accounts[accounts_index]);
        if(temp->getCardReqStatus())
        {
            if(temp->getMyCard())
            {
                if((temp->getMyCard()->getStatus() && isUser) || (!isUser))
                {
                    if(groupRow5->isHidden())
                       {
                            userNamelbl2->setText(oUsers[user_index]->getUsername());
                            accountIdlbl2->setText(QString::number(accounts[accounts_index]->getAccountId()));
                            cvv2lbl2->setText(QString::number(temp->getMyCard()->getCVV2()));
                             QString _card(temp->getMyCard()->getCardId());
                               _card.insert(4," ");
                               _card.insert(9," ");
                               _card.insert(14," ");
                            cardIdlbl2->setText(_card);
                            datelbl2->setText(temp->getMyCard()->getExpirationDate().toString(Qt::ISODate));
                            groupRow2->hide();
                            groupRow3->hide();
                            groupRow4->hide();
                            groupRow5->show();
                    }
                    else
                    {
                        groupRow5->hide();
                    }
                    this->adjustSize();
                }
                else
                {
                    QMessageBox::critical(this,"Error","Your card is deactivated!!!");
                }
            }
            else if(!temp->getMyCard() && isUser)
            {
                if(temp->getCardRequestList().contains(QString::number(accounts[accounts_index]->getAccountId())))
                {
                    QMessageBox::warning(this,"Warning","Your request is not checked yet by admin!");
                }
                else
                {
                    //QMessageBox::critical(this,"Error","Your request has rejected");
                    QMessageBox::StandardButton reply= QMessageBox::question(this,"Request","Do you want to make a new card request?");
                    if (reply == QMessageBox::Yes)
                    {
                        cardreq tempreq;
                        tempreq.accType=typeid(*temp).name();
                        tempreq.accType.remove(0,5);
                        tempreq.accountId=oUsers[user_index]->getAccounts()[account_oUsers_index]->getAccountId();
                        temp->getCardRequestList().insert(oUsers[user_index]->getUsername(),tempreq);
                        temp->setCardReqStatus(true);
                    }
                }
            }
            else if(!temp->getMyCard() && !isUser)
            {
                QMessageBox::information(this,"Information","You didnt check request card.\nThis request is in your request table");
            }
        }
        else if(!temp->getCardReqStatus() && isUser)
         {
            QMessageBox::StandardButton reply= QMessageBox::question(this,"Request","You didnt request any card\nDo you want to request?");
            if (reply == QMessageBox::Yes)
            {
                cardreq tempreq;
                tempreq.accType=typeid(*temp).name();
                tempreq.accType.remove(0,5);
                tempreq.accountId=oUsers[user_index]->getAccounts()[account_oUsers_index]->getAccountId();
                temp->getCardRequestList().insert(oUsers[user_index]->getUsername(),tempreq);
                temp->setCardReqStatus(true);
            }
         }
        else if(!temp->getCardReqStatus() && !isUser)
        {
            QMessageBox::StandardButton reply= QMessageBox::question(this,"Create","User didnt have any card\nDo you want to create?");
            if (reply == QMessageBox::Yes)
            {
                QMessageBox::information(this,"Information","Card created successfully.");
                card* cardTemp = new card(oUsers[user_index]->getAccounts()[account_oUsers_index]->getAccountId(),oUsers[user_index]->getUsername());
                cards.insert(cardTemp->getCardId(),cardTemp);
                temp->setMyCard(cardTemp);
                temp->setCardReqStatus(true);
                statuspbn->setText("Active");
            }
        }
}
void account_panel::transaction_clicked()
{
    if(groupRow3->isHidden())
    {
        destinationAccountIdled->clear();
        amountled->clear();
        groupRow2->hide();
        groupRow4->hide();
        groupRow5->hide();
        groupRow3->show();
    }
    else
    {
        groupRow3->hide();
    }
    this->adjustSize();
}
void account_panel::dynamicShow_sl()
{
    dynamic_timer->start(1000);
    if(timerInt==120)
    {
        std::uniform_int_distribution<int> randDynamicPass(1000000, 9999999);
        dynamicPasslb->setNum(randDynamicPass(*QRandomGenerator::global()));
        timerNumber->setNum(120);
    }
    if(dynamicGroup->isHidden())
    {
        groupRow2->hide();
        groupRow3->hide();
        groupRow4->hide();
        groupRow5->hide();
        dynamicGroup->show();
    }
    else
    {
        dynamicGroup->hide();
    }
    this->adjustSize();
}

void account_panel::showDynamicPass_sl()
{
    timerNumber->setNum(timerInt);
    if(timerNumber==0)
    {
        timerInt = 120;
        dynamic_timer->stop();
        dynamicGroup->hide();
        dynamicPasslb->clear();
    }
    timerInt--;
}

void account_panel::backDynamic_clicked()
{
    dynamicGroup->hide();
    this->adjustSize();
}

