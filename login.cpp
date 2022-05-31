#include "login.h"
#include"container.h"
administrator* adminptr=nullptr;

login::login(QWidget *parent)
    : QWidget(parent)

{
    Server server(this);

    LoadData();

    mainlayout= new QVBoxLayout();


     logo = new QPixmap(":/resource/image/faraz2.png");
     setWindowIcon(*logo);

    piclabel= new QLabel();
    piclabel->setPixmap(QPixmap(":/resource/image/faraz_s.jpg"));

    userName_lable= new QLabel("Username: ");
    password_lable= new QLabel("Password: ");
    userLineEdit= new QLineEdit;
    passLineEdit= new QLineEdit;
    passLineEdit->setEchoMode(QLineEdit::Password);
    layout1= new QHBoxLayout();
    layout1->addWidget(userName_lable);
    layout1->addWidget(userLineEdit);
    layout2= new QHBoxLayout();
    layout2->addWidget(password_lable);
    layout2->addWidget(passLineEdit);

    combo_lable= new QLabel();
    radioUser=new QRadioButton("User");
    radioUser->setChecked(true);
    radioManager=new QRadioButton("Manager");

    layout3= new QHBoxLayout();
    layout3->addWidget(combo_lable);
    layout3->addWidget(radioUser);
    layout3->addWidget(radioManager);

    loginBottom= new QPushButton("Login");
    loginBottom->setDefault(true);
    loginBottom->setStyleSheet("color:blue");

    forgotButton= new QPushButton("forgot password?");
    forgotButton->setFlat(true);
    layout5= new QHBoxLayout();
    layout5->addWidget(forgotButton,0,Qt::AlignLeft);

    signup_lable= new QLabel("Dont have an account?");
    signupBottom= new QPushButton("Signup!");
    layout4= new QHBoxLayout();
    layout4->addWidget(signup_lable);
    layout4->addWidget(signupBottom);

    layout= new QVBoxLayout();

    layout->addWidget(piclabel,0,Qt::AlignHCenter);
    layout->addLayout(layout1);
    layout->addLayout(layout2);
    layout->addLayout(layout3);
    layout->addWidget(loginBottom);
    layout->addLayout(layout5);
    layout->addLayout(layout4);
    loginbox= new QGroupBox();
    loginbox->setLayout(layout);


    mainlayout->addWidget(loginbox);


    connect(loginBottom,SIGNAL(clicked()),this,SLOT(login_clicked()));
    //signup
    mainLayoutRow3=new QVBoxLayout();
    groupRow3=new QGroupBox("please fill the boxes");
    bottomlayout3=new QHBoxLayout();

    layoutRow3=new QFormLayout();
    NCLable=new QLabel("NationalCode: ");
    NCLineEdit=new QLineEdit();
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
    connect(newpassLineEdit, SIGNAL(editingFinished()),this,SLOT(showPassStrong()));
    connect(emailLineEdit, SIGNAL(returnPressed()),ok,SIGNAL(clicked()));
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

    mainlayout->addWidget(groupRow3);
    mainlayout->QLayout::setSizeConstraint(QLayout::SetFixedSize);
    setLayout(mainlayout);
    setWindowTitle("Log In");
    connect(signupBottom,SIGNAL(clicked()),this,SLOT(signupBottom_clicked()));
    connect(ok,SIGNAL(clicked()),this,SLOT(ok_clicked()));
    connect(cancel,SIGNAL(clicked()),this,SLOT(cancel_clicked()));
    connect(forgotButton,SIGNAL(clicked()),this,SLOT(forgotButton_clicked()));
}
void login::addUser(QString _NC, QString _name, QString _lastname, QDate _date, QString _username, QString _password, QString _phonenumber, QString _email)
{
    oUser* tempNewUser=new oUser(_name,_lastname,_NC.toInt(),_username,_password,_date,_phonenumber,_email);
    oUsers.push_back(tempNewUser);
}
void login::signupBottom_clicked()
{
    bool isUser=radioUser->isChecked();
    if(adminptr)
    {
        if(isUser)
        {
            groupRow3->show();
            userLineEdit->clear();
            passLineEdit->clear();
            radioUser->setChecked(true);
            loginbox->hide();
            this->adjustSize();
        }
        else
        {
           QMessageBox::warning(this,tr("Warning"),tr("This system can have one admin."));
        }
    }
    else
    {
        if(isUser)
        {
            QMessageBox::warning(this,tr("Warning"),tr("There is no admin yet!!!"));
        }
        else
        {
           groupRow3->show();
           userLineEdit->clear();
           passLineEdit->clear();
           radioManager->setChecked(true);
           loginbox->hide();
           this->adjustSize();
        }
    }
}
void login::login_clicked()
{
    bool isUser=radioUser->isChecked();
    QString text = userLineEdit->text();
    QString text2 = passLineEdit->text();
        if (text.isEmpty()|text2.isEmpty())
        {
            QMessageBox::information(this, tr("Empty Field"),
                tr("Please enter username and password."));
            return;
        }
        else
            {
                if(isUser)
                {
                    if(adminptr)
                    {
                        int index=findUser(userLineEdit->text());
                        if(index!=-1)
                        {
                           if(oUsers[index]->getPassword()==passLineEdit->text())
                            {
                               if(oUsers[index]->getStatus())
                               {
                                   user_dialog=new user(text);
                                   this->hide();
                                   user_dialog->show();
                                   connect(user_dialog,SIGNAL(logout()),this,SLOT(new_window()));
                               }
                               else
                               {
                                   QMessageBox::critical(this, tr("Error"),tr("Your account is not active,call admin."));
                               }
                            }
                            else
                            {
                                QMessageBox::critical(this, tr("Error"),tr("Username and Password doesnt match."));
                            }
                        }
                        else
                        {
                            QMessageBox::critical(this, tr("Error"),tr("There is no a user with this username!"));

                        }
                    }
                    else
                    {
                        QMessageBox::critical(this, tr("Error"),tr("Admin should register first."));
                    }

                }
                /////admin dialog
                else
                {
                    if(!adminptr)
                    {
                        QMessageBox::critical(this, tr("Error"),tr("There is no admin yet!!!"));
                    }
                    else
                    {
                        if(text!=adminptr->getUsername())
                        {
                             QMessageBox::critical(this, tr("Error"),tr("Wrong Username for admin!!!"));
                        }
                        else
                        {
                            if(adminptr->getPassword()==passLineEdit->text())
                            {
                                admin_dialog=new admin(text);
                                this->hide();
                                admin_dialog->show();
                                connect(admin_dialog,SIGNAL(logout()),this,SLOT(new_window()));
                            }
                            else
                            {
                                 QMessageBox::critical(this, tr("Error"),tr("Username and Password doesnt match."));
                            }
                        }
                    }
                }
            }

    userLineEdit->clear();
    passLineEdit->clear();

}
void login::ok_clicked()
{
    bool isUser=radioUser->isChecked();
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
            QMessageBox::information(this, tr("successful"),
                tr("you are registered now"));
            if(!isUser)
            {
                adminptr= new administrator(text2,text3,text1.toInt(),text5,text6,text4,text8,emailLineEdit->text());
                this->hide();
                admin_dialog=new admin(text5);
                admin_dialog->show();
                connect(admin_dialog,SIGNAL(logout()),this,SLOT(new_window()));
            }
            else
            {
                addUser(text1,text2,text3,text4,text5,text6,text8,emailLineEdit->text());
                this->hide();
                user_dialog=new user(text5);
                user_dialog->show();
                connect(user_dialog,SIGNAL(logout()),this,SLOT(new_window()));
            }
        }
}
void login:: cancel_clicked()
{
    groupRow3->hide();
    userLineEdit->clear();
    passLineEdit->clear();
    radioUser->setChecked(true);
    loginbox->show();
    this->adjustSize();
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
void login::new_window()
{
    userLineEdit->clear();
    passLineEdit->clear();
    radioUser->setChecked(true);
    loginbox->show();
    groupRow3->hide();
    NCLineEdit->clear();
    nameineEdit->clear();
    lastNameineEdit->clear();
    birthDateEdit->clear();
    newuserLineEdit->clear();
    newpassLineEdit->clear();
    newpasslineEdit2->clear();
    phonenumberLineEdit->clear();
    emailLineEdit->clear();
    powerPercentagelb->hide();
    powerPercentage->hide();
    this->adjustSize();
    this->show();
}
void login::showPassStrong()
{
    password_strength(newpassLineEdit->text(),&powerPass);
    powerPercentage->setText(QString::number(powerPass)+"%");
    powerPercentagelb->show();
    powerPercentage->show();
    newpasslineEdit2->setFocus();
}
void login::forgotButton_clicked()
{
    QString text = userLineEdit->text();
        if (text.isEmpty())
        {
            QMessageBox::information(this, tr("Empty Field"),
                tr("Please enter username"));
            return;
        }
        //search kone in username bashe
    QMessageBox::StandardButton reply=QMessageBox::question(this,"forgot password","Do you want to receive an email ,so you can see your password?");
    if (reply == QMessageBox::Yes)
    {
    QMessageBox::information(this,"sent","we sent an email to your email address.");
    }
}
