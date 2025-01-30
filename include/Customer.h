#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <regex>

#include "Account.h"
#include "utils.h"

class Customer
{
public:
    int type;
    Customer();
    ~Customer();
    void set_name(std::string input_name);
    void set_surname(std::string input_surname);
    bool set_date_of_birth(std::string input_date_of_birth);
	virtual bool set_id(std::string input_id) = 0;
    void set_address(std::string input_address);
    void set_city(std::string input_city);
    bool set_postal_code(std::string input_postal_code);
    virtual bool set_phone_number(std::string input_phone_number) = 0;
    bool set_mail(std::string input_mail);
    void set_login(std::string input_login);
    void set_password(std::string input_password);
    std::string get_name() const;
    std::string get_surname() const;
    std::string get_date_of_birth() const;
	virtual std::string get_id() const = 0;
    std::string get_address() const;
    std::string get_city() const;
    std::string get_postal_code() const;
    virtual std::string get_phone_number() const = 0;
    std::string get_mail() const;
    std::string get_login() const;
    std::string get_password() const;
    std::vector<Account*> get_accounts() const;
    void open_account();
    void close_account();
    void list_accounts() const;
	void load_account(Account* account);
	int verify_passes(std::string input_login, std::string input_password) const;
	virtual void info() const = 0;
private:
    std::string login;
    std::string password;
    std::string name;
    std::string surname;
	std::string date_of_birth;
	std::string address;
	std::string city;
	std::string postal_code;
	std::string mail;
    std::vector<Account*> accounts;
    bool verify_login(std::string input_login) const;
    bool verify_password(std::string input_password) const;
};

class PolishCustomer
    : public Customer
{
public:
    PolishCustomer();
    bool set_id(std::string input_id) override;
	bool set_phone_number(std::string input_phone_number) override;
	std::string get_id() const override;
	std::string get_phone_number() const override;
	void info() const override;
private:
	std::string pesel;
    std::string phone_number;
};

class ForeignCustomer
    : public Customer
{
public:
	ForeignCustomer();
	bool set_id(std::string input_id) override;
	bool set_phone_number(std::string input_phone_number) override;
    std::string get_id() const override;
	std::string get_phone_number() const override;
	void info() const override;
private:
	std::string passport;
	std::string phone_number;
};