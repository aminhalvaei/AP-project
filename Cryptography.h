#pragma once

#include <QString>
#include <QVector>

#include <ctime>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

class Cryptography
{
private:
    QString string;

    static int prime1;
    static int prime2;
    static int eta;
    static int phi;
    static long e_key;
    static long d_key;
    static int count;
    QVector<long> temp;

    int prime_maker();
    long cd(long);
    void key_maker();
    bool isPrime(long) const;

public:
    Cryptography(QString);
    Cryptography(QString, int, int);

    QString getString() const;

    void encrypt();
    void decrypt();

    static int getPrime1();
    static int getPrime2();

    QVector<long> getTemp() const;
    void setTemp(const QVector<long>& value);
};
