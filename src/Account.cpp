#include "Account.h"

Account::Account()
{
    this->balance=0.0f;
}

void Account::set_balance(float new_balance)
{
    this->balance=new_balance;
}

float Account::get_balance()
{
    return this->balance;
}

void Account::deposit(float amount)
{
    if(amount>0)
        this->balance+=amount;
}

void Account::withdraw(float amount)
{
    if(amount>0)
        this->balance-=amount;
}