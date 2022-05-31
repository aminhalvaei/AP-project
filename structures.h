#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <QDateTime>
namespace str {
struct transaction{
    int accountId;
    int amount;
    QDateTime dateTransaction;
};
struct log{
    QDateTime entrance;
    QDateTime exit;
};

struct accreq{
    QString accType;
    int balance;
    QStringList others;
};
struct cardreq{
    QString accType;
    int accountId;
};

}

#endif // STRUCTURES_H
