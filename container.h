#ifndef CONTAINER_H
#define CONTAINER_H

#include "ouser.h"
#include "administrator.h"
#include "card.h"
#include <QMessageBox>
extern QVector<oUser*> oUsers;
extern administrator* adminptr;
extern QVector<account*> accounts;
extern QMap<QString,card*> cards;
int findAccount(QString);
int findAccount(QVector<account*>,QString);
int findUser(QString);
void calculateBalance(int,int,int,QWidget*);
void make_account(void); ///test
#endif // CONTAINER_H
