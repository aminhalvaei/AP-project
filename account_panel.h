#ifndef ACCOUNT_PANEL_H
#define ACCOUNT_PANEL_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QComboBox>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QFormLayout>
#include <QFileDialog>
#include <QTextStream>
#include <QTimer>
#include <QTextDocument>
#include <QPainter>
#include <QPdfWriter>
#include <QTextLine>
#include "timedeposit.h"
#include "corporate.h"
#include <QToolButton>
class account_panel : public QWidget
{
    Q_OBJECT
    QHBoxLayout *mainLayout;
    int user_index;
    int accounts_index;
    bool isUser;
    int account_oUsers_index;
    QPixmap* logoAccountPanel;
    //right
       QVBoxLayout *rightlayout;
       QLabel *piclabel;
       QLabel *namelabel;
       QToolButton *backToListOfAccs;

       //tool
       QVBoxLayout *tool_layout;
    //row1
    QGroupBox *groupRow1;
    QHBoxLayout *layoutRow1;

    QVBoxLayout *mainbottomLayout;
    QHBoxLayout *mainlayout;
    QToolButton *balanceBottom;
    QToolButton *transactionBottom;
    QToolButton *transactionListBottom;
    QToolButton *cardBottom;
    QToolButton *dynamicPasswordBottom;

    //row2
    QGroupBox *groupRow2;
    QGridLayout *hlayout;
    QLabel *balance_lable;
    QLabel *balance_lable2;
    QPushButton *backBottom;

    //row3
    QLabel* destinationAccountIdlbl;
    QLabel* amountlbl;
    QLineEdit* amountled;
    QLineEdit* destinationAccountIdled;
    QPushButton* submitpbt;
    QPushButton* cancelpbt;

    QHBoxLayout *accountIdslayout;
    QHBoxLayout *fieldslayout;
    QHBoxLayout* pbtslayout;
    QVBoxLayout *mainLayoutRow3;
    QGroupBox *groupRow3;

    //row4
    QGroupBox *groupRow4;
    QTableWidget* transTable;
    QTableWidgetItem* desAccountId;
    QTableWidgetItem* sorAccountId;
    QTableWidgetItem* transDate;
    QTableWidgetItem* amount;
    QPushButton* backpbt;
    QPushButton* pdfButton;
    QHBoxLayout* hpbnsLayout;
    QVBoxLayout* vlayout;
    //row5
    QGroupBox *groupRow5;
    QPushButton* requestCardBottom;
    QFormLayout* cardFormLayout;
    QLabel* cardIdlbl;
    QLabel* cardIdlbl2;
    QLabel* cvv2lbl;
    QLabel* cvv2lbl2;
    QLabel* datelbl;
    QLabel* datelbl2;
    QLabel* userNamelbl;
    QLabel* userNamelbl2;
    QLabel* accountIdlbl;
    QLabel* accountIdlbl2;
    QPushButton* backpbn;
    //Admin
    QPushButton* removepbn;
    QPushButton* statuspbn;
    QHBoxLayout* pbnsLayout;

    //Row6
    QGroupBox* dynamicGroup;
    QGridLayout* dynamicGrid;
    QLabel* dynamiclb;
    QLabel* dynamicPasslb;
    QLabel* timerlb;
    QLabel* timerNumber;
    QTimer* dynamic_timer;
    QPushButton* backDynamicBottom;
    int timerInt;


public:
    explicit account_panel(int,int,int,bool,QString);

signals:
    void backToAccs_sig();
public slots:
     void get_balance();
     void cancel_sl();
     void submit_sl();
     void card_clicked();
     void transaction_clicked();
     void back_clicked();
     void show_transaction_list();
     void remove_clicked();
     void status_clicked();
     void backFromCard_clicked();
     void backToAccs_clicked();
     void pdf_dialog();
     void backpbt_sl();
     void dynamicShow_sl();
     void showDynamicPass_sl();
     void backDynamic_clicked();
};

#endif // ACCOUNT_PANEL_H
