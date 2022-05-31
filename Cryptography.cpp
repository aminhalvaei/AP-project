#include "Cryptography.h"

int Cryptography::prime1;
int Cryptography::prime2;
int Cryptography::eta;
int Cryptography::phi;
long Cryptography::e_key;
long Cryptography::d_key;
int Cryptography::count = 0;

int Cryptography::prime_maker() {
    std::time_t now = std::time(0);
    boost::random::mt19937 gen{static_cast<std::uint32_t>(now)};

    while (1) {
        boost::random::uniform_int_distribution<> dist(100, 200);
        int temp = dist(gen);
        if (isPrime(temp) == true)
            return temp;
    }
}
long Cryptography::cd(long n)
{
    long temp = 1;
    while (1) {
        temp += phi;
        if (temp%n == 0)
            return temp/n;
    }
}
void Cryptography::key_maker()
{
    prime1 = prime_maker();
    while (1) {
        prime2 = prime_maker();
        if (prime1 != prime2)
            break;
    }

    //Secure keys
    //prime1 = 7; prime2 = 13;

    eta = prime1 * prime2;
    phi = (prime1 - 1) * (prime2 - 1);

    for (int i = 2; i < phi; i++) {
        if (phi%i == 0) continue;
        if (isPrime(i) == true && i != prime1 && i != prime2) {
            e_key = i;
            if (cd(e_key) > 0) {
                d_key = cd(e_key);
                return;
            }
        }
    }
}
bool Cryptography::isPrime(long prime) const
{
    int j = sqrt(prime);
    for (int i = 2; i <= j; i++) {
        if (prime%i == 0)
            return false;
    }
    return true;
}

Cryptography::Cryptography(QString _string) : string(_string)
{
    if (count == 0) {
        key_maker();
        count++;
    }
}
Cryptography::Cryptography(QString _string, int _prime1, int _prime2)
    : string(_string)
{
    count++;
    prime1 = _prime1;
    prime2 = _prime2;

    eta = prime1 * prime2;
    phi = (prime1 - 1) * (prime2 - 1);

    for (int i = 2; i < phi; i++) {
        if (phi%i == 0) continue;
        if (isPrime(i) == true && i != prime1 && i != prime2) {
            e_key = i;
            if (cd(e_key) > 0) {
                d_key = cd(e_key);
                return;
            }
        }
    }
}

QString Cryptography::getString() const {return string;}

void Cryptography::encrypt()
{
    long pt, k;
    for (int i = 0; i < string.size(); i++) {
        pt = (int)string.at(i).toLatin1();
        pt -= 96;
        k = 1;
        for (auto j = 0; j < e_key; j++) {
            k *= pt;
            k %= eta;
        }
        temp.append(k);
        string[i] = (int)k + 96;
    }
}
void Cryptography::decrypt()
{
    long ct, k;
    for (int i = 0; i < string.size(); i++) {
       ct = temp[i];
       k = 1;
       for(int j = 0; j < d_key; j++)
       {
          k *= ct;
          k %= eta;
       }
       string[i] = (int)k + 96;
    }
}

int Cryptography::getPrime1() {return prime1;}
int Cryptography::getPrime2() {return prime2;}

QVector<long> Cryptography::getTemp() const {return temp;}
void Cryptography::setTemp(const QVector<long>& value) {temp = value;}
