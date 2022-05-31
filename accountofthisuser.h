#ifndef ACCOUNTOFTHISUSER_H
#define ACCOUNTOFTHISUSER_H

#include <QWidget>
#include <QPushButton>
#include <account_panel.h>
#include <QFormLayout>
class accountofthisuser : public QWidget
{
    Q_OBJECT
    account_panel *panel_dialog;
    int user_index;
    bool isUser;
    QPixmap* logoAccounts;
    QString title;
    //row1
    QGridLayout* gridlayout;
    QVector<QFormLayout*>innerlayout;
    QVector<QGroupBox*>group;
    QVector<QLabel*>balancelbl;
    QVector<QLabel*>balanceval;
    QVector<QLabel*>accountIdlbl;
    QVector<QLabel*>accountIdval;
    QVector<QLabel*>opendatelbl;
    QVector<QLabel*>opendateval;
    QVector<QLabel*>statuslbl;
    QVector<QLabel*>statusval;
    QVector<QLabel*> otherUserIdlbl;
    QVector<QLabel*> otherUserIdval;
    QVector<QPushButton*> panelBottom;
    QVector<QPushButton*> removepbn;
    QVector<QPushButton*> statuspbn;
    QVector<QHBoxLayout*> pbnsLayout;
    QPushButton* backToUserPanel;
    QVBoxLayout* pbnlayout;
    QVBoxLayout* mainlayout;
public:
    explicit accountofthisuser(int,bool);

signals:
   void backToUser_Sig();
   void backToAdmin_Sig();
   void pbn_sig(QString);
   void refreshAccsPage();
public slots:
   void backTo();
   void slTopbn();
   void pbn_sl(QString);
};

#endif // ACCOUNTOFTHISUSER_H
