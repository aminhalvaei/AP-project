#ifndef USER_PANEL_H
#define USER_PANEL_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QTableWidget>
#include <QLabel>
#include <QDateEdit>
#include <QLineEdit>
#include <QMessageBox>
#include <QCheckBox>
#include "accountofthisuser.h"
#include "saveaccount.h"
#include "corporate.h"
#include <QToolButton>
class user_panel : public QWidget
{
    QHBoxLayout *mainlayout;
    int index;
    QPixmap* logoUserPanel;
    //right
        QVBoxLayout *rightlayout;
        QLabel *piclabel;
        QLabel *namelabel;
        QToolButton *delete_userButton;
        QToolButton *backpbt;

        //tool
        QVBoxLayout *tool_layout;
    //row0
    QGroupBox *row0box;
    QHBoxLayout *row0layout;
    QToolButton *accountRequestBottom;
    QToolButton *user_profileButton;
    QToolButton *list_of_accountsButton;
    QToolButton *user_entranceButton;
    QToolButton *createBottom;
    //row1
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

    //row2
    accountofthisuser* listOfAccount;

    //row3
    QVBoxLayout* vlayout;
    QGroupBox *show_entrance;
    QTableWidgetItem* inputHeader;
    QTableWidgetItem* outputHeader;
    QTableWidget* table;


    Q_OBJECT
public:
    explicit user_panel(int);
    void showEdit();
    void changProfile();
signals:
       void backToAdminPanel_sig();
public slots:
        void user_profileButton_clicked();
        void user_entranceButton_clicked();
        void delete_userButton_clicked();
        void list_of_accountsButton_clicked();
        void backToAdminPanel_sl();
        void showPass_sl(int);
        void cancel_clicked();
        void ok_clicked();
       // void accountRequestBottom_clicked();
      //  void requestcanceled();
       // void createAccount();
       // void corporateAccount(int);
       // void num_clicked();
};

#endif // USER_PANEL_H
