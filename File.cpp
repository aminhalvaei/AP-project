#include "File.h"

QVector<QString> ID;

void LoadAdmin()
{
    QFile file("admin.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (file.isOpen()) {
        QJsonParseError JsonParseError;
        QJsonDocument JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
        file.close();
        QJsonObject RootObject = JsonDocument.object();
        if (RootObject.length() == 0)
            return;
        if (adminptr != nullptr)
            delete adminptr;
        adminptr = new administrator();
        adminptr->setName(RootObject.value("Name").toString());
        adminptr->setlastName(RootObject.value("Last Name").toString());
        adminptr->setNationalCode(RootObject.value("National Code").toInt());
        adminptr->setUsername(RootObject.value("Username").toString());

        QJsonArray array = RootObject.value(" ").toArray();
        QVector<long> key;
        for (int i = 2; i < array.size(); i++)
            key.append(array[i].toInt());
        Cryptography c(RootObject.value("Password").toString(), array[0].toInt(), array[1].toInt());
        c.setTemp(key);
        c.decrypt();
        adminptr->setPassword(c.getString());

        QDate date;
        adminptr->setBirthdate(date.fromString(RootObject.value("Birth Date").toString()));
        adminptr->setPhonenumber(RootObject.value("Phone Number").toString());
        adminptr->setEmail(RootObject.value("E-Mail").toString());
    }
}
void SaveAdmin()
{
    QJsonObject RootObject;
    RootObject["Name"] = adminptr->getName();
    RootObject["Last Name"] = adminptr->getlastName();
    RootObject["National Code"] = adminptr->getNationalCode();
    RootObject["Username"] = adminptr->getUsername();

    Cryptography c(adminptr->getPassword());
    c.encrypt();
    QVector<long> key = c.getTemp();
    key.push_front(c.getPrime1());
    key.push_front(c.getPrime2());
    QJsonArray array;
    for (int i = 0; i < key.size(); i++) {
        QJsonValue value((int)key[i]);
        array.append(value);
    }
    RootObject[" "] = array;
    RootObject["Password"] = c.getString();

    RootObject["Birth Date"] = adminptr->getBirthdate().toString();
    RootObject["Phone Number"] = adminptr->getPhonenumber();
    RootObject["E-Mail"] = adminptr->getEmail();
    QJsonDocument JsonDocument;
    JsonDocument.setObject(RootObject);
    QFile file("admin.json");
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    if (file.isOpen()) {
        file.write(JsonDocument.toJson());
        file.close();
    }
}

void LoadUsersList()
{
    QFile file("users.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (file.isOpen()) {
        QJsonParseError JsonParseError;
        QJsonDocument JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
        file.close();
        QJsonObject RootObject = JsonDocument.object();
        if (RootObject.length() == 0)
            return;
        if (oUsers.isEmpty() == false)
            oUsers.clear();
        QJsonObject::iterator Jitr;
        oUsers.fill(new oUser(), RootObject.length());
        int i = 0;
        for (Jitr = RootObject.begin(); Jitr != RootObject.end(); Jitr++) {
            oUsers[i]->setName(Jitr.value().toObject().value("Name").toString());
            oUsers[i]->setlastName(Jitr.value().toObject().value("Last Name").toString());
            oUsers[i]->setNationalCode(Jitr.value().toObject().value("National Code").toInt());

            QJsonArray uuid_array = Jitr.value().toObject().value("uuid_k").toArray();
            QVector<long> uuid_k;
            for (int i = 2; i < uuid_array.size(); i++)
                uuid_k.append(uuid_array[i].toInt());
            Cryptography uuid_c(Jitr.value().toObject().value("uuid").toString(), uuid_array[0].toInt(),
                                uuid_array[1].toInt());
            uuid_c.setTemp(uuid_k);
            uuid_c.decrypt();
            oUsers[i]->setId(uuid_c.getString());

            oUsers[i]->setUsername(Jitr.value().toObject().value("Username").toString());

            QJsonArray array = Jitr.value().toObject().value(" ").toArray();
            QVector<long> key;
            for (int i = 2; i < array.size(); i++)
                key.append(array[i].toInt());
            Cryptography c(Jitr.value().toObject().value("Password").toString(), array[0].toInt(), array[1].toInt());
            c.setTemp(key);
            c.decrypt();
            oUsers[i]->setPassword(c.getString());

            QDate date;
            oUsers[i]->setBirthdate(date.fromString(Jitr.value().toObject().value("Birth Date").toString()));
            oUsers[i]->setPhonenumber(Jitr.value().toObject().value("Phone Number").toString());
            oUsers[i]->setEmail(Jitr.value().toObject().value("E-Mail").toString());

            oUsers[i]->setStatus(Jitr.value().toObject().value("Status").toBool());
            oUsers[i]->setAccountReqStatus(Jitr.value().toObject().value("Req. Status").toBool());

            i++;
        }
    }
}
void SaveUsersList()
{
    if (oUsers.isEmpty() == true) return;

    QJsonObject RootObject;
    for (int i = 0; i < oUsers.size(); i++) {
        QJsonObject j;
        j["Name"] = oUsers[i]->getName();
        j["Last Name"] = oUsers[i]->getlastName();
        j["National Code"] = oUsers[i]->getNationalCode();

        boost::uuids::uuid uuid = boost::uuids::random_generator()();
        std::string _id = to_string(uuid);
        QString id = QString::fromStdString(_id);
        Cryptography uuid_c(id);
        uuid_c.encrypt();
        QVector<long> uuid_k = uuid_c.getTemp();
        uuid_k.push_front(uuid_c.getPrime1());
        uuid_k.push_front(uuid_c.getPrime2());
        QJsonArray uuid_array;
        for (int i = 0; i < uuid_k.size(); i++) {
            QJsonValue value((int)uuid_k[i]);
            uuid_array.append(value);
        }
        j["uuid_k"] = uuid_array;
        j["uuid"] = uuid_c.getString();

        j["Username"] = oUsers[i]->getUsername();

        Cryptography c(oUsers[i]->getPassword());
        c.encrypt();
        QVector<long> key = c.getTemp();
        key.push_front(c.getPrime1());
        key.push_front(c.getPrime2());
        QJsonArray array;
        for (int i = 0; i < key.size(); i++) {
            QJsonValue value((int)key[i]);
            array.append(value);
        }
        j[" "] = array;
        j["Password"] = c.getString();

        j["Birth Date"] = oUsers[i]->getBirthdate().toString();
        j["Phone Number"] = oUsers[i]->getPhonenumber();
        j["E-Mail"] = oUsers[i]->getEmail();

        j["Status"] = oUsers[i]->getStatus();
        j["Req. Status"] = oUsers[i]->getAccountReqStatus();

        QJsonObject J; J["JSON"]=j;
        RootObject.insert(oUsers[i]->getUsername(), J.value("JSON"));
    }
    QJsonDocument JsonDocument;
    JsonDocument.setObject(RootObject);
    QFile file("users.json");
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    file.write(JsonDocument.toJson());
    file.close();
}

void LoadCards()
{
    QFile file("cards.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (file.isOpen()) {
        QJsonParseError JsonParseError;
        QJsonDocument JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
        file.close();
        QJsonObject RootObject = JsonDocument.object();
        if (RootObject.length() == 0)
            return;
        if (cards.isEmpty() == false)
            cards.clear();
        QJsonObject::iterator Jitr;
        for (Jitr = RootObject.begin(); Jitr != RootObject.end(); Jitr++) {
            int accID = Jitr.value().toObject().value("Account ID").toInt();
            QString userID = Jitr.value().toObject().value("User ID").toString();
            card* temp = new card(accID, userID);
            temp->setCardId(Jitr.value().toObject().value("Card ID").toString());
            temp->setCVV2(Jitr.value().toObject().value("CVV2").toInt());

            QDate date;
            temp->setExpirationDate(date.fromString(Jitr.value().toObject().value("Exp. Date").toString()));
            temp->setStatus(Jitr.value().toObject().value("Status").toBool());
            cards.insert(temp->getCardId(), temp);
        }
    }
}
void SaveCards()
{
    if (cards.isEmpty() == true) return;

    QJsonObject RootObject;
    QMap<QString, card*>::iterator itr;
    for (itr = cards.begin(); itr != cards.end(); itr++) {
        QJsonObject j;
        j["Account ID"] = itr.value()->getOAccountId();
        j["User ID"] = itr.value()->getOUserId();
        j["Card ID"] = itr.key();
        j["CVV2"] = itr.value()->getCVV2();
        j["Status"] = itr.value()->getStatus();
        j["Exp. Date"] = itr.value()->getExpirationDate().toString();

        QJsonObject J; J["JSON"]=j;
        RootObject.insert(itr.key(), J.value("JSON"));
    }
    QJsonDocument JsonDocument;
    JsonDocument.setObject(RootObject);
    QFile file("cards.json");
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    file.write(JsonDocument.toJson());
    file.close();
}

void LoadLogs()
{
    for (int i = 0; i < oUsers.size(); i++) {
        QString fileName = oUsers[i]->getId(); fileName += "_log.json";
        QFile file(fileName);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        if (file.isOpen()) {
            QJsonParseError JsonParseError;
            QJsonDocument JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
            file.close();
            QJsonObject RootObject = JsonDocument.object();
            if (RootObject.length() == 0)
                break;
            QJsonObject::iterator Jitr;
            QVector<struct log> temp(RootObject.size());
            int t = 0;
            for (Jitr = RootObject.begin(); Jitr != RootObject.end(); Jitr++) {
                temp[t].entrance.fromString(Jitr.value().toObject().value("Login").toString());
                temp[t].exit.fromString(Jitr.value().toObject().value("Log").toString());
                t++;
            }
            oUsers[i]->setLogActivity(temp);
        }
    }
}
void SaveLogs()
{
    for (int i = 0; i < oUsers.size(); i++) {
        QJsonObject RootObject;
        for (int t = 0; t < oUsers[i]->getLogActivity().size(); t++) {
            QJsonObject j;
            j["Login"] = oUsers[i]->getLogActivity()[t].entrance.toString();
            j["Logout"] = oUsers[i]->getLogActivity()[t].exit.toString();

            QJsonObject J; J["JSON"]=j;
            RootObject.insert(QString::number(t), J.value("JSON"));
        }
        QJsonDocument JsonDocument;
        JsonDocument.setObject(RootObject);
        QString fileName = oUsers[i]->getId(); fileName += "_log.json";
        QFile file(fileName);
        file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
        file.write(JsonDocument.toJson());
        file.close();
    }
}

void LoadAccountReq()
{
    if (oUser::getAccountRequestList().isEmpty() == false)
        oUser::getAccountRequestList().clear();

    for (int i = 0; i < oUsers.size(); i++) {
        QString fileName = oUsers[i]->getId(); fileName += "_acc_req.json";
        QFile file(fileName);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        if (file.isOpen()) {
            QJsonParseError JsonParseError;
            QJsonDocument JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
            file.close();
            QJsonObject RootObject = JsonDocument.object();
            if (RootObject.length() == 0)
                break;
            QJsonObject::iterator Jitr;
            for (Jitr = RootObject.begin(); Jitr != RootObject.end(); Jitr++) {
                struct accreq temp;
                temp.accType = Jitr.value().toObject().value("Account Type").toString();
                temp.balance = Jitr.value().toObject().value("Balance").toInt();

                QJsonArray array = Jitr.value().toObject().value("Others").toArray();
                QList<QString> list;
                for (int j = 0; j < array.size(); j++)
                    list.append(array[j].toString());
                temp.others = list;

                oUser::getAccountRequestList().insert(oUsers[i]->getUsername(), temp);
            }
        }
    }
}
void SaveAccountReq()
{
    for (int i = 0; i < oUsers.size(); i++) {
        QJsonObject RootObject;
        QMultiMap<QString, accreq>::iterator itr = oUser::getAccountRequestList().find(oUsers[i]->getUsername());
        for (int t = 0; itr != oUser::getAccountRequestList().end() && itr.key() == oUsers[i]->getUsername(); itr++) {
            QJsonObject j;
            j["Account Type"] = itr.value().accType;
            j["Balance"] = itr.value().balance;

            QJsonArray array;
            for (int x = 0; x < itr.value().others.size() ; x++) {
                QJsonValue value(itr.value().others[x]);
                array.append(value);
            }
            j["Others"] = array;

            QJsonObject J; J["JSON"]=j;
            RootObject.insert(QString::number(t), J.value("JSON"));
            t++;
        }
        QJsonDocument JsonDocument;
        JsonDocument.setObject(RootObject);
        QString fileName = oUsers[i]->getId(); fileName += "_acc_req.json";
        QFile file(fileName);
        file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
        file.write(JsonDocument.toJson());
        file.close();
    }
}

void LoadAccounts()
{
    QFile file("accounts.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (file.isOpen()) {
        QJsonParseError JsonParseError;
        QJsonDocument JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
        file.close();
        QJsonObject RootObject = JsonDocument.object();
        if (RootObject.length() == 0)
            return;
        if (accounts.isEmpty() == false)
            accounts.clear();
        QJsonObject::iterator Jitr;
        if (ID.isEmpty() == false)
            ID.clear();
        for (Jitr = RootObject.begin(); Jitr != RootObject.end(); Jitr++) {
            int type = Jitr.value().toObject().value("Type").toInt();
            account* temp;
            switch (type) {

            case 1:
                temp = new saveAccount();
                break;

            case 2:
                temp = new shortTerm();
                break;

            case 3:
                temp = new corporate();
                break;

            case 4:
                temp = new timeDeposit();
                break;

            }

            QJsonArray uuid_array = Jitr.value().toObject().value("uuid_k").toArray();
            QVector<long> uuid_k;
            for (int i = 2; i < uuid_array.size(); i++)
                uuid_k.append(uuid_array[i].toInt());
            Cryptography uuid_c(Jitr.value().toObject().value("ID").toString(), uuid_array[0].toInt(),
                                uuid_array[1].toInt());
            uuid_c.setTemp(uuid_k);
            uuid_c.decrypt();
            ID.append(uuid_c.getString());

            temp->setBalance(Jitr.value().toObject().value("Balance").toInt());
            temp->setAccountId(Jitr.value().toObject().value("Account ID").toInt());
            QDateTime date;
            temp->setOpenDate(date.fromString(Jitr.value().toObject().value("Open Date").toString()));
            temp->setControlInterest(Jitr.value().toObject().value("Control Interest").toInt());
            temp->setStatus(Jitr.value().toObject().value("Status").toBool());
            temp->setOUserUsername(Jitr.value().toObject().value("Username").toString());

            saveAccount* p = nullptr;
            if (type != 4) {
                p = reinterpret_cast<saveAccount*>(temp);
                p->setMyCardNULL();
                QMap<QString, card*>::iterator itr;
                for (itr = cards.begin(); itr != cards.end(); itr++)
                    if (itr.value()->getOAccountId() == temp->getAccountId())
                        p->setMyCard(itr.value());
                p->setCardReqStatus(Jitr.value().toObject().value("Card Req. Status").toBool());
            }
            corporate* q = nullptr;
            if (type == 3) {
                q = reinterpret_cast<corporate*>(p);
                QJsonArray array = Jitr.value().toObject().value("Partners").toArray();
                QVector<QString> partners;
                for (int i = 0; i < array.size(); i++)
                    partners.append(array[i].toString());
                q->setOtherUsers(partners);
            }
            switch (type) {

            case 1:
                accounts.append(p);
                break;

            case 2:
                accounts.append(p);
                break;

            case 3:
                accounts.append(q);
                break;

            case 4:
                accounts.append(temp);
                break;

            }
        }
    }
}
void SaveAccounts()
{
    if (accounts.isEmpty() == true) return;

    QJsonObject RootObject;
    ID.clear();
    for (int i = 0; i < accounts.size(); i++) {
        QJsonObject j;
        j["Type"] = accounts[i]->getTYPE();
        j["Balabce"] = accounts[i]->getBalance();
        j["Account ID"] = accounts[i]->getAccountId();
        j["Open Date"] = accounts[i]->getOpenDate().toString();
        j["Control Intrest"] = accounts[i]->getControlInterest();
        j["Status"] = accounts[i]->getStatus();
        j["Username"] = accounts[i]->getOUserUsername();

        boost::uuids::uuid uuid = boost::uuids::random_generator()();
        std::string _id = to_string(uuid);
        ID.append(QString::fromStdString(_id));
        Cryptography uuid_c(ID.last());
        uuid_c.encrypt();
        QVector<long> uuid_k = uuid_c.getTemp();
        uuid_k.push_front(uuid_c.getPrime1());
        uuid_k.push_front(uuid_c.getPrime2());
        QJsonArray uuid_array;
        for (int k = 0; k < uuid_k.size(); k++) {
            QJsonValue value((int)uuid_k[k]);
            uuid_array.append(value);
        }
        j["uuid_k"] = uuid_array;
        j["ID"] = uuid_c.getString();

        if (accounts[i]->getTYPE() != 4) {
            saveAccount* p = reinterpret_cast<saveAccount*>(accounts[i]);
            j["Card Req. Status"] = p->getCardReqStatus();
        }

        if (accounts[i]->getTYPE() == 3) {
            corporate* q = reinterpret_cast<corporate*>(accounts[i]);
            QJsonArray array;
            for (int k = 0; k < q->getOtherUsers().size(); k++) {
                QJsonValue value(q->getOtherUsers()[k]);
                array.append(value);
            }
            j["Partners"] = array;
        }

        QJsonObject J; J["JSON"]=j;
        RootObject.insert(QString::number(accounts[i]->getAccountId()), J.value("JSON"));
    }
    QJsonDocument JsonDocument;
    JsonDocument.setObject(RootObject);
    QFile file("accounts.json");
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    file.write(JsonDocument.toJson());
    file.close();
}

void ConnectAccounts_to_Users()
{
    for (int i = 0; i < accounts.size(); i++)
        for (int j = 0; j < oUsers.size(); j++)
            if (accounts[i]->getOUserUsername() == oUsers[i]->getUsername())
                oUsers[i]->getAccounts().append(accounts[i]);
}

void LoadTransactions()
{
    for (int i = 0; i < accounts.size(); i++) {
        QString fileName = ID[i]; fileName += "_transaction.json";
        QFile file(fileName);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        if (file.isOpen()) {
            QJsonParseError JsonParseError;
            QJsonDocument JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
            file.close();
            QJsonObject RootObject = JsonDocument.object();
            if (RootObject.length() == 0)
                break;
            QJsonObject::iterator Jitr;
            QVector<transaction> temp(RootObject.size());
            int t = 0;
            for (Jitr = RootObject.begin(); Jitr != RootObject.end(); Jitr++) {
                temp[t].accountId = Jitr.value().toObject().value("to Account ID").toInt();
                temp[t].amount = Jitr.value().toObject().value("Amount").toInt();
                temp[t].dateTransaction.fromString(Jitr.value().toObject().value("Date").toString());
                t++;
            }
            accounts[i]->setTransactions(temp);
        }
    }
}
void SaveTransactions()
{
    for (int i = 0; i < accounts.size(); i++) {
        QJsonObject RootObject;
        for (int t = 0; t < accounts[i]->getTransactions().size(); t++) {
            QJsonObject j;
            j["to Account ID"] = accounts[i]->getTransactions()[t].accountId;
            j["Amount"] = accounts[i]->getTransactions()[t].amount;
            j["Date"] = accounts[i]->getTransactions()[t].dateTransaction.toString();

            QJsonObject J; J["JSON"]=j;
            RootObject.insert(QString::number(t), J.value("JSON"));
        }
        QJsonDocument JsonDocument;
        JsonDocument.setObject(RootObject);
        QString fileName = ID[i]; fileName += "_transaction.json";
        QFile file(fileName);
        file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
        file.write(JsonDocument.toJson());
        file.close();
    }
}

void ConnectTransactions_to_Users()
{
    oUser::getAllTransactions().clear();
    for (int i = 0; i < accounts.size(); i++)
        for (int j = 0; j < accounts[i]->getTransactions().size(); j++)
            oUser::getAllTransactions().insert(accounts[i]->getAccountId(), accounts[i]->getTransactions()[j]);
}

void LoadCardReq()
{
    if (saveAccount::getCardRequestList().isEmpty() == false)
        saveAccount::getCardRequestList().clear();

    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getTYPE() != 4) {
            QString fileName = ID[i]; fileName += "_card_requests.json";
            QFile file(fileName);
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            if (file.isOpen()) {
                QJsonParseError JsonParseError;
                QJsonDocument JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
                file.close();
                QJsonObject RootObject = JsonDocument.object();
                if (RootObject.length() == 0)
                    break;
                QJsonObject::iterator Jitr;
                for (Jitr = RootObject.begin(); Jitr != RootObject.end(); Jitr++) {
                    struct cardreq temp;
                    temp.accType = Jitr.value().toObject().value("Account Type").toString();
                    temp.accountId = Jitr.value().toObject().value("Account ID").toInt();

                    saveAccount::getCardRequestList().insert(accounts[i]->getOUserUsername(), temp);
                }
            }
        }
    }
}
void SaveCardReq()
{
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getTYPE() != 4) {
            QJsonObject RootObject;
            QMultiMap<QString, cardreq>::iterator itr = saveAccount::getCardRequestList().find(accounts[i]->getOUserUsername());
            for (int t = 0; itr != saveAccount::getCardRequestList().end() && itr.key() == accounts[i]->getOUserUsername(); itr++) {
                QJsonObject j;
                j["Account Type"] = itr.value().accType;
                j["Account ID"] = itr.value().accountId;

                QJsonObject J; J["JSON"]=j;
                RootObject.insert(QString::number(t), J.value("JSON"));
                t++;
            }
            QJsonDocument JsonDocument;
            JsonDocument.setObject(RootObject);
            QString fileName = ID[i]; fileName += "_card_requests.json";
            QFile file(fileName);
            file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
            file.write(JsonDocument.toJson());
            file.close();
        }
    }
}

void LoadData()
{
    LoadAdmin();
    LoadUsersList();
    LoadCards();
    LoadLogs();
    LoadAccountReq();
    LoadAccounts();
    ConnectAccounts_to_Users();
    LoadTransactions();
    ConnectTransactions_to_Users();
    LoadCardReq();
}
void SaveData()
{
    SaveAdmin();
    SaveUsersList();
    SaveCards();
    SaveLogs();
    SaveAccountReq();
    SaveAccounts();
    SaveTransactions();
    SaveAccountReq();
}
