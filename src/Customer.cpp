#include "Customer.h"

Customer::Customer()
{
    // TODO
}

Customer::Customer(std::string input_name, std::string input_surname, std::string input_date_of_birth, std::string input_pesel, std::string input_address, std::string input_city, std::string input_postal_code, std::string input_phone_number, std::string input_mail)
{
    this->set_name(input_name);
    this->set_surname(input_surname);
    this->set_date_of_birth(input_date_of_birth);
    this->set_pesel(input_pesel);
    this->set_address(input_address);
    this->set_city(input_city);
    this->set_postal_code(input_postal_code);
    this->set_phone_number(input_phone_number);
    this->set_mail(input_mail);
}

Customer::Customer(std::string input_name, std::string input_surname, std::string input_date_of_birth, std::string input_pesel, std::string input_address, std::string input_city, std::string input_postal_code, std::string input_phone_number, std::string input_mail, std::string input_login, std::string input_password)
{
    this->set_name(input_name);
    this->set_surname(input_surname);
    this->set_date_of_birth(input_date_of_birth);
    this->set_pesel(input_pesel);
    this->set_address(input_address);
    this->set_city(input_city);
    this->set_postal_code(input_postal_code);
    this->set_phone_number(input_phone_number);
    this->set_mail(input_mail);
    this->login = input_login;
    this->password = input_password;
}

Customer::~Customer()
{
    // TODO
}

void Customer::set_name(std::string input_name)
{
    this->name=input_name;
}

void Customer::set_surname(std::string input_surname)
{
    this->surname=input_surname;
}

void Customer::set_date_of_birth(std::string input_date_of_birth)
{
    this->date_of_birth=input_date_of_birth;
}

void Customer::set_pesel(std::string input_pesel)
{
    if(input_pesel.length()==11)
        this->pesel=input_pesel;
}

void Customer::set_address(std::string input_address)
{
    this->address=input_address;
}

void Customer::set_city(std::string input_city)
{
    this->city=input_city;
}

void Customer::set_postal_code(std::string input_postal_code)
{
    this->postal_code=input_postal_code;
}

void Customer::set_phone_number(std::string input_phone_number)
{
    if(input_phone_number.length()==9)
        this->phone_number=input_phone_number;
}

void Customer::set_mail(std::string input_mail)
{
    this->mail=input_mail;
}

std::string Customer::get_name()
{
    return this->name;
}

std::string Customer::get_surname()
{
    return this->surname;
}

std::string Customer::get_date_of_birth()
{
    return this->date_of_birth;
}

std::string Customer::get_pesel()
{
    return this->pesel;
}

std::string Customer::get_address()
{
    return this->address;
}

std::string Customer::get_city()
{
    return this->city;
}

std::string Customer::get_postal_code()
{
    return this->postal_code;
}

std::string Customer::get_phone_number()
{
    return this->phone_number;
}

std::string Customer::get_mail()
{
    return this->mail;
}

std::vector<Account*> Customer::get_accounts()
{
    return this->accounts;
}

void Customer::open_account()
{
    this->accounts.push_back(new Account());
}

void Customer::close_account()
{
    // TODO
}

bool Customer::verify_login(std::string input_login) const
{
    if (input_login == this->login)
        return true;
    return false;
}

bool Customer::verify_password(std::string input_password) const
{
    if (input_password == this->password)
        return true;
    return false;
}
