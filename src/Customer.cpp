#include "Customer.h"


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
    this->set_login(input_login);
    this->set_password(input_password);
}

Customer::~Customer()
{
	for (auto& account : this->accounts){
		delete account;
	}
	this->accounts.clear();
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

void Customer::set_login(std::string input_login)
{
    this->login = input_login;
}

void Customer::set_password(std::string input_password)
{
    this->password = input_password;
}

std::string Customer::get_name() const
{
    return this->name;
}

std::string Customer::get_surname() const
{
    return this->surname;
}

std::string Customer::get_date_of_birth() const
{
    return this->date_of_birth;
}

std::string Customer::get_pesel() const
{
    return this->pesel;
}

std::string Customer::get_address() const
{
    return this->address;
}

std::string Customer::get_city() const
{
    return this->city;
}

std::string Customer::get_postal_code() const
{
    return this->postal_code;
}

std::string Customer::get_phone_number() const
{
    return this->phone_number;
}

std::string Customer::get_mail() const
{
    return this->mail;
}

std::string Customer::get_login() const
{
    return this->login;
}

std::string Customer::get_password() const
{
    return this->password;
}

std::vector<Account*> Customer::get_accounts() const
{
    return this->accounts;
}

void Customer::open_account()
{
    unsigned int choice = 0;
    std::string name = "";
    std::cout << "Which account would you like to open?"<< std::endl;
    std::cout << "1. Regular account" << std::endl;
    std::cout << "2. Savings account" << std::endl;
    std::cout << "3. Company account" << std::endl;
    do {
        std::cout << "Choice: ";
        std::cin >> choice;

    } while (choice < 1 || choice >= NUM_OF_ACCOUNT_TYPES + 1);
    clear();
    std::cout << "Your account's custom name:" << std::endl;
	while (getchar() != '\n');
	std::getline(std::cin, name);
    switch (choice - 1)
    {
    case REGULAR:
        this->accounts.push_back(new RegularAccount(name));
        std::cout << "Successfully created regular account!" << std::endl;
        break;
    case SAVINGS:
        this->accounts.push_back(new SavingsAccount(name));
        std::cout << "Successfully created savings account!" << std::endl;
        break;
    case COMPANY:
        std::string company_name, company_nip;
        std::cout << "Company name:" << std::endl;
        std::cin >> company_name;
        std::cout << "Company NIP: ";
        std::cin >> company_nip;
        this->accounts.push_back(new CompanyAccount(name, company_name, company_nip));
        std::cout << "Successfully created company account!" << std::endl;
        break;
    }
    sleep(1);
    clear();
}

void Customer::close_account()
{
    unsigned int choice;
    clear();
    if (this->get_accounts().size() == 0)
    {
        std::cout << "No opened accounts" << std::endl;
        sleep(1);
        return;
    }
    std::cout << "Your accounts: " << std::endl;
    this->list_accounts();
    do {
        std::cout << "Choice: ";
        std::cin >> choice;
        choice--;
    } while (choice < 0 || choice >= this->get_accounts().size());
    delete this->accounts[choice];
    this->accounts.erase(this->accounts.begin() + choice);
}

void Customer::list_accounts()
{
    for (size_t i = 0; i < this->get_accounts().size(); i++)
    {
        std::cout << i + 1 << ". " << this->get_accounts()[i]->get_custom_name() << " - " << this->get_accounts()[i]->get_type() << " Account" << std::endl;
    }
    std::cout << std::endl;
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
