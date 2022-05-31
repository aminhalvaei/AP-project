#ifndef USER_H
#define USER_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QComboBox>
#include <QMessageBox>
#include <accountofthisuser.h>
#include <QFormLayout>
#include <QDate>
#include <QDateEdit>
#include <QTableWidget>
#include <QCheckBox>
#include "structures.h"
#include <QToolButton>
#include <QCloseEvent>
#include <QEvent>
using namespace str;
class user : public QWidget
{
    Q_OBJECT

    void closeEvent(QCloseEvent* event)
    {
        emit logoutpbt->clicked();
        event->accept();
    }

    QDateTime* enteranceDateTime;
    struct log* temp;
    QHBoxLayout *mainLayout;
    QPixmap* logouser;
    int index;
    //right
        QVBoxLayout *rightlayout;
        QToolButton *logoutpbt;
        QLabel *piclabel;
        QLabel *namelabel;

        //tool
        QVBoxLayout *tool_layout;
    //row1
    QGroupBox *groupRow1;
    QHBoxLayout *layoutRow1;
    QToolButton *accountRequestBottom;
    QToolButton *accountlistBottom;
    QToolButton *editProfileBottom;
    QToolButton *entrancelistBottom;

    //row2
    QGroupBox *groupRow2;
    QGridLayout *layoutRow2;
    QLabel *pickLable;
    QComboBox *row2Cmb;
    QGroupBox *corporateBox;
    QVBoxLayout *corporateLayout;
    //
    QHBoxLayout *hlayout;
    QLabel *num_label;
    QLineEdit *numLineEdit;
    QPushButton *num_ok_boottom;
    QLabel *p;
    QLineEdit *l;
    QFormLayout *form;
    int num;
    QGroupBox *other_user_box;
    //
    QLabel *creditLabel;
    QLineEdit *creditLineEdit;
    QHBoxLayout *bottomlayout;
    QPushButton *sendRequestBottom;
    QPushButton *cancelRequestBottom;
    int m;

    //row3
    QVBoxLayout *mainLayoutRow3;
    QGroupBox *groupRow3;
    QHBoxLayout *bottomlayout3;
    QGridLayout *layoutRow3;
    QLabel *NCLable;
    QLineEdit *NCLineEdit;
    QLabel *nameLable;
    QLineEdit *nameineEdit;
    QLabel *lastNameLable;
    QLineEdit *lastNameineEdit;
    QLabel *birthdateLable;
    QDateEdit* dateEdit;
    QLabel *userLable;
    QLineEdit *userLineEdit;
    QCheckBox* showPass;
    QLabel *passLable;
    QLineEdit *passLineEdit;
    QLabel *passLable2;
    QLineEdit *passLineEdit2;
    QLabel* phonenumberLabel;
    QLineEdit* phonenumberled;
    QLineEdit* emailLineEdit;
    QLabel* emailLabel;
    QPushButton *edit_ok;
    QPushButton *edit_cancel;


    accountofthisuser *accounts_dialog;
   //row4
    QVBoxLayout* vlayout;
    QGroupBox *show_entrance;
    QTableWidgetItem* inputHeader;
    QTableWidgetItem* outputHeader;
    QTableWidget* table;

public:
    explicit user(QString);
    void showEdit();
    void changProfile();
signals:
    void logout();
public slots:
    void requestAccount();
    void requestcanceled();
    void listOfAccounts();
    void ok_clicked();
    void cancel_clicked();
    void entrance();
    void accountRequestBottom_clicked();
    void editProfileBottom_clicked();
    void logOutBottom_clicked();
    void corporateAccount(int);
    void num_clicked();
    void backAgain();
    void showPass_sl(int);
};
#endif // USER_H
