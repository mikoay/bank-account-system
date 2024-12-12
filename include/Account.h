#pragma once
#include <iostream>

class Account
{
public:
    // CONSTRUCTORS 
    Account();
    // SETTERS
    void set_balance(float new_balance);
    // GETTERS
    float get_balance();
    std::string custom_name;
    void deposit(float amount);
    void withdraw(float amount);
private:
    float balance;
};

class SavingsAccount
    : public Account
{
public:
    float interest_rate;
};

class CompanyAccount
    : public Account
{
public:
    std::string company_name;
};