#pragma once

#include <iostream>
#include <vector>

#include "Transaction.h"

enum account_types
{
    REGULAR = 0,
    SAVINGS,
    COMPANY,
    NUM_OF_ACCOUNT_TYPES
};

class Account
{
public:
    Account();
    Account(std::string input_name, float input_balance);
    Account(std::string input_name);
    void set_balance(float new_balance);
    void set_custom_name(std::string input_name);
    float get_balance() const;
    std::string get_custom_name() const;
	std::vector<Transaction*> get_transactions() const;
    void deposit(float amount);
	void deposit(float amount, std::string title);
    bool withdraw(float amount);
	bool withdraw(float amount, std::string title);
	void load_transaction(Transaction* transaction);
	void list_transactions();
    virtual std::string get_type() = 0;
private:
    std::string custom_name;
    float balance;
    std::vector<Transaction*> transactions_history;
};

class RegularAccount
    : public Account
{
public:
    using Account::Account;
    std::string get_type();
};

class SavingsAccount
    : public Account
{
public:
	SavingsAccount();
	SavingsAccount(std::string input_name);
	SavingsAccount(std::string input_name, float input_balance, float input_interest_rate);
    float interest_rate;
    std::string get_type();
};

class CompanyAccount
    : public Account
{
public:
    CompanyAccount(std::string input_n, std::string input_cn, std::string cnip);
	CompanyAccount(std::string input_n, float input_balance, std::string input_cn, std::string cnip);
    std::string company_name;
    std::string company_nip;    
    std::string get_type();
};