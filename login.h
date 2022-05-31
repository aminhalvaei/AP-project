#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
//#include <QDate>
//#include <QTime>
#include <QDateTime>
#include <user.h>
#include <QPixmap>
#include <QValidator>
#include "admin.h"
#include "check.h"
#include <QRadioButton>
#include "File.h"
#include "Server.h"
#include <QCloseEvent>
#include <QEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QWidget
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    void addUser(QString,QString,QString,QDate,QString,QString,QString,QString);
private:

    void closeEvent(QCloseEvent* event)
    {
        SaveData();
        event->accept();
    }

   user *user_dialog;
   admin* admin_dialog;
   QPixmap* logo;
   QLabel *piclabel;

   QGroupBox *loginbox;
   QLabel *userName_lable;
   QLineEdit *userLineEdit;
   QHBoxLayout *layout1;

   QLabel *password_lable;
   QLineEdit *passLineEdit;
   QHBoxLayout *layout2;

   QLabel *combo_lable;
   //QComboBox *combo;
   QRadioButton *radioUser;
   QRadioButton *radioManager;
   QHBoxLayout *layout3;

   QPushButton *loginBottom;
   QVBoxLayout *layout;//loginlayout

   QLabel *forgot_lable;
   QPushButton *forgotButton;
   QHBoxLayout *layout5;

   QLabel *signup_lable;
   QPushButton *signupBottom;
   QHBoxLayout *layout4;

   QVBoxLayout *mainlayout;

    //signup
   QVBoxLayout *mainLayoutRow3;
   QGroupBox *groupRow3;
   QHBoxLayout *bottomlayout3;
   QFormLayout *layoutRow3;
   QLabel *NCLable;
   QLineEdit *NCLineEdit;
   QLabel *nameLable;
   QLineEdit *nameineEdit;
   QLabel *lastNameLable;
   QLineEdit *lastNameineEdit;
   QLabel *birthdateLable;
   QDateEdit* birthDateEdit;
   QLabel *userLable;
   QLineEdit *newuserLineEdit;
   QLabel *passLable;
   QLabel* passlable2;
   QLineEdit *newpassLineEdit;
   QLineEdit* newpasslineEdit2;

   QLabel* phonenumberLabel;
   QLineEdit* phonenumberLineEdit;

   QLabel* emailLabel;
   QLineEdit* emailLineEdit;

   QPushButton *ok;
   QPushButton *cancel;
   QLabel* powerPercentagelb;
   QLabel* powerPercentage;
   int powerPass;

public slots:
  void login_clicked();
  void ok_clicked();
  void cancel_clicked();
  void signupBottom_clicked();
  void new_window();
  void showPassStrong();
  void forgotButton_clicked();
};
#endif // LOGIN_H
