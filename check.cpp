#include "check.h"
bool check_username(QString _username,QWidget* _this)
{
    if(_username.size()>4)
    {
            if(findUser(_username)==-1 )
            {
                return 1;
            }
            else
            {
                QMessageBox::warning(_this,"Warning","This username already exists in list!");
                return 0;
            }
    }
    else
    {
        QMessageBox::warning(_this,"Warning","This username is to short!");
        return 0;
    }
}
bool password_strength(QString _password,int* _powerPass)
{
        int i;
        int s = 0;

        for (i = 0; i<_password.size(); i++)
        {
            if ('A' <= _password[i] && _password[i] <= 'Z')
            {
                s = s + 4;
            }
            else if ('a' <= _password[i] &&_password[i] <= 'z')
            {
                s = s + 2;
            }
            else if ('0' <= _password[i] && _password[i] <= '9')
            {
                s = s + 3;
            }
            else if (_password[i] == ' ')
            {
                s = s + 1;
            }
            else
            {
                s = s + 8;
            }
            if(_password.count(_password[i])>3)
            {
                return 1;
            }
        }
        *_powerPass=s;
        if (s > 100 || s < 33)
        {
            return 1;
        }
        return 0;

}
