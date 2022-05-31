#ifndef PERSON_H
#define PERSON_H
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <QString>
#include <QDateTime>
class  person
{
    QString name;
    QString lastName;
    int nationalCode;
    QString id;
    QString username;
    QString password;
    QDate birthdate;
    QString phonenumber;
    QString email;
public:
    person() {}
    person(QString _name,QString _lastName,int _natioalCode,QString _userName,QString _password,QDate _birthdate,QString _phonenumber,QString _email){
        name = _name;
        lastName = _lastName;
        nationalCode = _natioalCode;
        boost::uuids::uuid uuid = boost::uuids::random_generator()();
        std::string _id = to_string(uuid);
        id = QString::fromStdString(_id);
        username = _userName;
        password = _password;
        birthdate = _birthdate;
        phonenumber = _phonenumber;
        email = _email;
    }
    QString getName(){return name;}
    QString getlastName(){return lastName;}
    int getNationalCode(){return nationalCode;}
    QString getId(){return id;}
    QString getUsername(){return username;}
    QString getPassword(){return password;}
    QDate getBirthdate(){return birthdate;}
    QString getPhonenumber(){return phonenumber;}
    QString getEmail(){return email;}
    void setName(QString _name){name =_name;}
    void setlastName(QString _lastName){lastName =_lastName;}
    void setNationalCode(int _nationalCode){nationalCode = _nationalCode;}
    void setUsername(QString _userName){ username =_userName;}
    void setPassword(QString _password){password = _password;}
    void setBirthdate(QDate _birthdate){birthdate =_birthdate;}
    void setPhonenumber(QString _phonenumber){phonenumber =_phonenumber;}
    void setEmail(QString _email){email = _email;}
    virtual ~person()=0;
    void setId(const QString &value);
};

#endif // PERSON_H
