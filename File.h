#pragma once

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>
#include <QResource>

#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "Cryptography.h"
#include "container.h"
#include "timedeposit.h"
#include "corporate.h"

extern QVector<QString> ID;

void LoadAdmin();
void SaveAdmin();

void LoadUsersList();
void SaveUsersList();

void LoadCards();
void SaveCards();

void LoadLogs();
void SaveLogs();

void LoadAccountReq();
void SaveAccountReq();

void LoadAccounts();
void SaveAccounts();

void ConnectAccounts_to_Users();

void LoadTransactions();
void SaveTransactions();

void ConnectTransactions_to_Users();

void LoadCardReq();
void SaveCardReq();

void LoadData();
void SaveData();
