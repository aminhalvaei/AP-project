#include "user.h"
#include "container.h"
#include "user_panel.h"
user::user(QString _username)
{
    logouser = new QPixmap(":/resource/image/faraz2.png");
    setWindowIcon(*logouser);
    mainLayout= new QHBoxLayout();
    tool_layout= new QVBoxLayout();
    enteranceDateTime=new QDateTime(QDateTime::currentDateTime());
    index=findUser(_username);

    //right
        rightlayout=new QVBoxLayout();

        piclabel= new QLabel();
        piclabel->setPixmap(QPixmap(":/resource/image/user/user_s.png"));
        piclabel->setFixedSize(100,100);

        namelabel=new QLabel(_username);

        logoutpbt=new QToolButton();
        logoutpbt->setMinimumSize(75,75);
        logoutpbt->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        ////icon
        logoutpbt->setIcon(QPixmap(":/resource/image/admin/logout.jpg"));
        logoutpbt->setIconSize(QSize(30, 30));
        logoutpbt->setText("Log Out");

        rightlayout->addWidget(piclabel,0,Qt::AlignRight|Qt::AlignTop);
        rightlayout->addWidget(namelabel,0,Qt::AlignHCenter|Qt::AlignTop);
        rightlayout->addWidget(logoutpbt,0,Qt::AlignHCenter|Qt::AlignBottom);

        //row1
            layoutRow1= new QHBoxLayout();
            groupRow1 = new QGroupBox(_username);

            accountRequestBottom=new QToolButton();
            accountlistBottom=new QToolButton();
            editProfileBottom=new QToolButton();
            entrancelistBottom=new QToolButton();
            accountRequestBottom->setMinimumSize(75,75);
            accountlistBottom->setMinimumSize(75,75);
            editProfileBottom->setMinimumSize(75,75);
            entrancelistBottom->setMinimumSize(75,75);

            accountRequestBottom->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            accountRequestBottom->setIcon(QPixmap(":/resource/image/user/req_acc.png"));
            accountRequestBottom->setIconSize(QSize(30, 30));
            accountRequestBottom->setText("Request Account");

            accountlistBottom->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            accountlistBottom->setIcon(QPixmap(":/resource/image/user/accounts.png"));
            accountlistBottom->setIconSize(QSize(30, 30));
            accountlistBottom->setText("Accounts");

            editProfileBottom->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            editProfileBottom->setIcon(QPixmap(":/resource/image/user/edit_pro.png"));
            editProfileBottom->setIconSize(QSize(30, 30));
            editProfileBottom->setText("Edit Profile");

            entrancelistBottom->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            entrancelistBottom->setIcon(QPixmap(":/resource/image/user/entrance.webp"));
            entrancelistBottom->setIconSize(QSize(30, 30));
            entrancelistBottom->setText("Entrance");

            layoutRow1->addWidget(accountlistBottom);
            layoutRow1->addWidget(accountRequestBottom);
            layoutRow1->addWidget(entrancelistBottom);
            layoutRow1->addWidget(editProfileBottom);


            groupRow1->setLayout(layoutRow1);
            tool_layout->addWidget(groupRow1);



    //row2
    other_user_box=new QGroupBox();

    groupRow2 = new QGroupBox("Request Account");
    layoutRow2 = new QGridLayout();

    pickLable=new QLabel("Pick one Account");
    layoutRow2->addWidget(pickLable, 0, 0);

    row2Cmb = new QComboBox();
    row2Cmb->addItem("Saving Account");
    row2Cmb->addItem("ShortTerm Account");
    row2Cmb->addItem("Corporate Account");
    row2Cmb->addItem("TimeDeposit Account");
    layoutRow2->addWidget(row2Cmb, 0, 1);

    creditLabel=new QLabel("Enter primary credit ($): ");
    creditLineEdit= new QLineEdit();
    creditLineEdit->setValidator(new QIntValidator(1,1000000000));
    layoutRow2->addWidget(creditLabel, 3, 0);
    layoutRow2->addWidget(creditLineEdit, 3, 1);

    sendRequestBottom=new QPushButton("Send Request");
    cancelRequestBottom=new QPushButton("Cancel");
    bottomlayout=new QHBoxLayout();
    bottomlayout->addWidget(cancelRequestBottom);
    bottomlayout->addWidget(sendRequestBottom);
    bottomlayout->setAlignment(Qt::AlignRight);

    layoutRow2->addLayout(bottomlayout,4, 1);

    groupRow2->setLayout(layoutRow2);
    tool_layout->addWidget(groupRow2);
    //groupRow2->hide();


    corporateBox=new QGroupBox();
    corporateLayout=new QVBoxLayout();

    num_label=new QLabel("Numbers of other users: ");
    numLineEdit=new QLineEdit();
    numLineEdit->setValidator(new QIntValidator(1,100));
    num_ok_boottom=new QPushButton("ok");
    hlayout=new QHBoxLayout();
    hlayout->addWidget(num_label);
    hlayout->addWidget(numLineEdit);
    hlayout->addWidget(num_ok_boottom);

    corporateLayout->addLayout(hlayout);
    corporateBox->setLayout(corporateLayout);
    layoutRow2->addWidget(corporateBox,1,0,1,2);
    corporateBox->hide();

    //row3
    mainLayoutRow3=new QVBoxLayout();
    groupRow3=new QGroupBox("Edit Profile");
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
    phonenumberLabel=new QLabel("Phonenumber: ");
    phonenumberled=new QLineEdit();
    passLineEdit->setEchoMode(QLineEdit::Password);
    passLineEdit2->setEchoMode(QLineEdit::Password);
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
    groupRow3->hide();
    tool_layout->addWidget(groupRow3);
    //row4
     vlayout=new QVBoxLayout();
     show_entrance=new QGroupBox("Entrance Information");
     table=new QTableWidget(0,2,this);
     inputHeader=new QTableWidgetItem("Entrance");
     outputHeader=new QTableWidgetItem("Exit");
     table->setColumnWidth(0,200);
     table->setColumnWidth(1,200);
     table->setFixedWidth(460);
     table->setHorizontalHeaderItem(0,inputHeader);
     table->setHorizontalHeaderItem(1,outputHeader);
     table->setEditTriggers(QAbstractItemView::NoEditTriggers);


     vlayout->addWidget(table);
     show_entrance->setLayout(vlayout);
     show_entrance->hide();
     tool_layout->addWidget(show_entrance);


     mainLayout->addLayout(tool_layout);
          mainLayout->addLayout(rightlayout);

         setLayout(mainLayout);
         setWindowTitle("user");
         setFixedSize(600,400);

    //row1
    connect(accountRequestBottom,SIGNAL(clicked()),this,SLOT(accountRequestBottom_clicked()));
    connect(accountlistBottom,SIGNAL(clicked()),this,SLOT(listOfAccounts()));
    connect(entrancelistBottom,SIGNAL(clicked()),this,SLOT(entrance()));
    connect(logoutpbt,SIGNAL(clicked()),this,SLOT(logOutBottom_clicked()));
    //row2
    connect(sendRequestBottom,SIGNAL(clicked()),this,SLOT(requestAccount()));
    connect(cancelRequestBottom,SIGNAL(clicked()),this,SLOT(requestcanceled()));
    connect(row2Cmb,SIGNAL(currentIndexChanged(int)),this,SLOT(corporateAccount(int)));
    connect(num_ok_boottom,SIGNAL(clicked()),this,SLOT(num_clicked()));
    //row3
    connect(editProfileBottom,SIGNAL(clicked()),this,SLOT(editProfileBottom_clicked()));
    connect(edit_ok,SIGNAL(clicked()),this,SLOT(ok_clicked()));
    connect(edit_cancel,SIGNAL(clicked()),this,SLOT(cancel_clicked()));
    connect(showPass,SIGNAL(stateChanged(int)),this,SLOT(showPass_sl(int)));
}

void user::showEdit()
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
void user::changProfile()
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
//row1
void user::accountRequestBottom_clicked()
{
    if(groupRow2->isHidden()){
        corporateBox->hide();
        other_user_box->hide();
        groupRow3->hide();
        show_entrance->hide();
        creditLineEdit->clear();
        row2Cmb->setCurrentIndex(0);
        showEdit();
        groupRow2->show();
    }
    /*else{
      groupRow2->hide();
    }*/
    this->adjustSize();
}
void user::editProfileBottom_clicked()
{
    if(groupRow3->isHidden())
    {
        groupRow2->hide();
        show_entrance->hide();
        showEdit();
        groupRow3->show();
    }
    /*else
    {
     groupRow3->hide();
    }*/
    row2Cmb->setCurrentIndex(0);
    creditLineEdit->clear();
    this->adjustSize();
}
void user::logOutBottom_clicked()
{
    temp = new struct log ;
    temp->entrance = *enteranceDateTime;
    temp->exit = QDateTime::currentDateTime();
    oUsers[index]->getLogActivity().push_back(*temp);
    this->close();
    emit logout();
}

//row2
void user::corporateAccount(int a)
{
    m=a;
    if(a==2)
    {
        corporateBox->show();
        numLineEdit->clear();
        numLineEdit->setReadOnly(false);
        num_ok_boottom->setEnabled(true);
    }
    else
    {
        other_user_box->hide();
        corporateBox->hide();
        numLineEdit->clear();
    }
     this->adjustSize();
}
void user::num_clicked()
{
    num=numLineEdit->text().toInt();
    if(num>4)
    {
        QMessageBox::warning(this,"warning","max other users count is 4");
        numLineEdit->clear();
        return;
    }
    layoutRow2->addWidget(other_user_box,2,0,1,2);
    numLineEdit->setReadOnly(true);
    num_ok_boottom->setEnabled(false);
    p=new QLabel[num];
    l=new QLineEdit[num];
    form =new QFormLayout();
    for(int i=0;i<num;i++)
    {
        p[i].setText(tr("user \'%1\' name: ").arg(i+1));
        form->addRow(&p[i],&l[i]);
    }
    other_user_box->setLayout(form);
    other_user_box->show();

}

void user::backAgain()
{
  groupRow1->show();
  this->show();
  this->adjustSize();
}

void user::showPass_sl(int _state)
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
void user::requestAccount()
{
    if(m==2)
    {
        for(int i=0;i<num;i++)
       {     QString text = l[i].text();
             if (text.isEmpty())
             {
                 QMessageBox::information(this, tr("Empty Field"),
                     tr("please enter user \'%1\' username. ").arg(i+1));
                 return;
             }
             int finder=findUser(l[i].text());
             if(finder==-1 || finder==index)          //find?
             {
                 QMessageBox::information(this, tr("Invalid Field"),
                     tr("Ivalid input for field \'%1\' ").arg(i+1));
                 return;
             }
        }
    }
    QString text = creditLineEdit->text();

        if (text.isEmpty())
        {
            QMessageBox::information(this, tr("Empty Field"),
                tr("Please enter a primary credit."));
            return;
        }
        else
    {
     QMessageBox::StandardButton reply=QMessageBox::question(this,"send a request","Are you sure you want to send this request?",QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        QMessageBox::information(this,"sent","your request sent");
        if(row2Cmb->currentIndex()==2)
        {
            accreq temp;
            for(int i=0;i<num;i++)
            {
            temp.others.push_back(l[i].text());
            }
            temp.balance=creditLineEdit->text().toInt();
            temp.accType=row2Cmb->currentText();
            oUser::getAccountRequestList().insert(oUsers[index]->getUsername(),temp);
        }
        else
        {
            accreq temp;
            temp.accType=row2Cmb->currentText();
            temp.balance=creditLineEdit->text().toInt();
            temp.others.push_back("");
            oUser::getAccountRequestList().insert(oUsers[index]->getUsername(),temp);

        }
        oUsers[index]->setAccountReqStatus(true);
        creditLineEdit->clear();
        row2Cmb->setCurrentIndex(0);
        //groupRow2->hide();
        other_user_box->hide();
        this->adjustSize();
    }
}
}
void user:: requestcanceled()
{
    creditLineEdit->clear();
    row2Cmb->setCurrentIndex(0);
    //groupRow2->hide();
    other_user_box->hide();
    this->adjustSize();
}
void user::listOfAccounts()
{
    ////make_account();////////////////////////////////////////////////////

        if(oUsers[index]->getAccounts().size())
        {
            accounts_dialog=new accountofthisuser(index,true);
            this->hide();
            accounts_dialog->show();
            connect(accounts_dialog,SIGNAL(backToUser_Sig()),this,SLOT(backAgain()));
        }
        else
        {
            if(oUser::getAccountRequestList().contains(oUsers[index]->getUsername()))
            {
                QMessageBox::warning(this,tr("Error"),tr("There is some unconfirmed account request please call admin!!!"));
                return;
            }
            else
            {
                QMessageBox::warning(this,tr("Error"),tr("All of your requests are rejected!!!"));
                return;
            }

        }

}
void user::ok_clicked()
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
       //groupRow3->hide();
       this->adjustSize();
   }
        }
}
void user::cancel_clicked()
{
    showEdit();
    //groupRow3->hide();
    this->adjustSize();
}
void user::entrance()
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
        groupRow2->hide();
        groupRow3->hide();
        show_entrance->show();
        showEdit();
    }
   /* else
    {
        show_entrance->hide();
    }*/

        creditLineEdit->clear();
        row2Cmb->setCurrentIndex(0);
        this->adjustSize();
}

