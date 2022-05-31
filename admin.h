#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QTableWidget>
#include <QLabel>
#include <user_panel.h>
#include <QFormLayout>
#include <QComboBox>
#include "corporate.h"
#include "check.h"
#include <QGridLayout>
#include <QToolButton>
#include <QCloseEvent>
#include <QEvent>

class admin : public QWidget
{

    void closeEvent(QCloseEvent* event)
    {
        emit logoutpbt->clicked();
        event->accept();
    }

  QHBoxLayout *mainlayout;
  QPixmap* logoAdmin;
  //right
  QVBoxLayout *rightlayout;
  QToolButton *logoutpbt;
  QLabel *piclabel;
  QLabel *namelabel;

  //tool
  QVBoxLayout *tool_layout;

  //row0
  QGroupBox *row0box;
  QHBoxLayout *row0layout;
  QToolButton *manage_usersButton;
  QToolButton *request_accountButton;
  QToolButton *request_cardButton;
  QToolButton *transaction_listButton;

  //row1  user
  //base
  QGroupBox *row11box;
  QVBoxLayout *row11layout;
  QGroupBox *row1box;
  QVBoxLayout *row1layout;
  QGridLayout *searchlayout;
  QLabel *search_label;
  QComboBox *search_combo;
  QLineEdit *search_lineEdit;
  QPushButton *find_userButton;
  QPushButton *add_userButton;
  QTableWidget *user_table;
  QVector<QPushButton*> user_panelButton;
  QVector<QLabel*> user_label;
  QTableWidgetItem *header1;
  QTableWidgetItem *header2;
  user_panel *panel;
  //add
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

  //row2 account requests
  QGroupBox *row2box;
  QVBoxLayout *row2layout;
  QTableWidget *request_account_table;
  QVector<QPushButton*> acceptButton;
  QVector<QPushButton*> rejectButton;
  QVector<QHBoxLayout*> buttonlayout;
  QVector<QGroupBox*> button_box;
  QTableWidgetItem *header21;
  QTableWidgetItem *header22;
  QTableWidgetItem *header23;
  QTableWidgetItem *header24;

  //row3 card requests
  QGroupBox *row3box;
  QVBoxLayout *row3layout;
  QTableWidget *request_card_table;
  QVector<QPushButton*>acceptButton3;
  QVector<QPushButton*>rejectButton3 ;
  QVector<QHBoxLayout*>buttonlayout3;
  QVector<QGroupBox*>button_box3;

  QTableWidgetItem *header31;
  QTableWidgetItem *header32;
  QTableWidgetItem *header33;
  QTableWidgetItem *header34;

  //row4 transaction list
  QGroupBox *row4box;
  QVBoxLayout *row4layout;
  QTableWidget *transactin_list_table;
  QTableWidgetItem *header41;
  QTableWidgetItem *header42;
  QTableWidgetItem *header43;
  QTableWidgetItem *header44;

  QLabel* powerPercentagelb;
  QLabel* powerPercentage;
  int powerPass;
    Q_OBJECT

public:
    admin(QString);
    void showEdit();

signals:
    void logout();
    void clickedPanel_sig(int);
    void clickedAccAndReq_sig(QString);
    void clickedAccAndReq3_sig(QString);

public slots:
    void manage_users_clicked();
    void refreshTable();
    void user_panelButton_clicked(int);
    void find_userButton_clicked();
    void add_userButton_clicked();
    void ok_clicked();
    void cancel_clicked();
    void request_accountButton_clicked();
    void clickedAccAndRej_sl();
    void AcceptAndReject_Clicked(QString);
    void request_cardButton_clicked();
    void clickedAccAndRej3_sl();
    void AcceptAndReject3_Clicked(QString);
    void transaction_listButton_clicked();
    void logout_sl();
    void clickedPanel_sl();
    void showPassStrong();
    void showAdminAgain();
    void refreshCardRequestTable();
    void refreshAccountRequestTable();
};
#endif // ADMIN_H
