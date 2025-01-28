#include "Account.h"

Account::Account()
{
}

Account::Account(std::string input_name)
{
    this->balance = 0.0f;
    this->set_custom_name(input_name);
}

void Account::set_balance(float new_balance)
{
    this->balance=new_balance;
}

void Account::set_custom_name(std::string input_name)
{
    this->custom_name = input_name;
}

float Account::get_balance()
{
    return this->balance;
}

std::string Account::get_custom_name()
{
    return this->custom_name;
}

void Account::deposit(float amount)
{
    if (amount > 0)
    {
        this->balance += amount;
		this->transactions_history.push_back(new Transaction(amount, "Deposit"));
    }
}

void Account::deposit(float amount, std::string title)
{
    if (amount > 0)
    {
        this->balance += amount;
        this->transactions_history.push_back(new Transaction(amount, title));
    }
}

bool Account::withdraw(float amount)
{
	if (amount <= 0)
	{
		return false;
	}
    if (this->balance < amount) {
        std::cout << "Not enough money on your account!" << std::endl;
        return false;
    }
    this->balance -= amount;
    this->transactions_history.push_back(new Transaction(-amount, "Withdraw"));
    return true;
}

bool Account::withdraw(float amount, std::string title)
{
    if (amount <= 0)
    {
        return false;
    }
    if (this->balance < amount) {
        std::cout << "Not enough money on your account!" << std::endl;
        return false;
    }
    this->balance -= amount;
    this->transactions_history.push_back(new Transaction(-amount, title));
    return true;
}

CompanyAccount::CompanyAccount(std::string input_n, std::string input_cn, std::string input_cnip)
{
    this->set_balance(0.0f);
    this->set_custom_name(input_n);
    this->company_name = input_cn;
    this->company_nip = input_cnip;
}

std::string CompanyAccount::get_type()
{
    return "Company";
}

std::string RegularAccount::get_type()
{
    return "Regular";
}

std::string SavingsAccount::get_type()
{
    return "Savings";
}
