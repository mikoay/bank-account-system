#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Account.h"

class Customer
{
public:
    // CONSTRUCTORS
    Customer();
    Customer(std::string input_name, std::string input_surname, std::string input_date_of_birth, std::string input_pesel, std::string input_address, std::string input_city, std::string input_postal_code, std::string input_phone_number, std::string input_mail);
    Customer(std::string input_name, std::string input_surname, std::string input_date_of_birth, std::string input_pesel, std::string input_address, std::string input_city, std::string input_postal_code, std::string input_phone_number, std::string input_mail, std::string input_login, std::string input_password);
    // DESTRUCOTR
    ~Customer();
    // SETTERS
    void set_name(std::string input_name);
    void set_surname(std::string input_surname);
    void set_date_of_birth(std::string input_date_of_birth);
    void set_pesel(std::string input_pesel);
    void set_address(std::string input_address);
    void set_city(std::string input_city);
    void set_postal_code(std::string input_postal_code);
    void set_phone_number(std::string input_phone_number);
    void set_mail(std::string input_mail);
    void set_login(std::string input_login);
    void set_password(std::string input_password);
    // GETTERS
    std::string get_name();
    std::string get_surname();
    std::string get_date_of_birth();
    std::string get_pesel();
    std::string get_address();
    std::string get_city();
    std::string get_postal_code();
    std::string get_phone_number();
    std::string get_mail();
    std::vector<Account*> get_accounts();
    // CUSTOMER'S ACCOUNTS' OPERATIONS
    void open_account();
    void close_account();
    void list_accounts();
    // OTHER
    bool verify_login(std::string input_login) const;
    bool verify_password(std::string input_password) const;
private:
    // CUSTOMER INFO
    std::string login, password;
    std::string name, surname, date_of_birth, pesel, address, city, postal_code, phone_number, mail;
    // CUSTOMER ACCOUNTS
    std::vector<Account*> accounts;
};