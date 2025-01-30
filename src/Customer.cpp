#include "Customer.h"

Customer::Customer()
{
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

bool Customer::set_date_of_birth(std::string input_date_of_birth)
{
    std::regex pattern(R"(^\d{2}-\d{2}-\d{4}$)");
    if (std::regex_match(input_date_of_birth, pattern))
    {
        this->date_of_birth = input_date_of_birth;
        return true;
    }
    return false;
}

void Customer::set_address(std::string input_address)
{
    this->address=input_address;
}

void Customer::set_city(std::string input_city)
{
    this->city=input_city;
}

bool Customer::set_postal_code(std::string input_postal_code)
{
    std::regex pattern(R"(^\d{2}-\d{3}$)");
	if (std::regex_match(input_postal_code, pattern))
	{
		this->postal_code = input_postal_code;
		return true;
	}
    return false;
}

bool Customer::set_mail(std::string input_mail)
{
    std::regex pattern(R"(^[^@]+@[^@]+\.[^@]+$)");
	if (std::regex_match(input_mail, pattern))
	{
		this->mail = input_mail;
		return true;
	}
    return false;
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
    std::cout << std::endl;
    std::cout << "1. Regular account" << std::endl;
    std::cout << "2. Savings account" << std::endl;
    std::cout << "3. Company account" << std::endl;
    std::cout << std::endl;
    do {
        std::cout << "Choice: ";
        std::cin >> choice;

    } while (choice < 1 || choice >= NUM_OF_ACCOUNT_TYPES + 1);
    clear();
    std::cout << "Your account's custom name: ";
	while (getchar() != '\n');
	std::getline(std::cin, name);
    sleep(1);
	clear();
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

void Customer::list_accounts() const
{
    for (size_t i = 0; i < this->get_accounts().size(); i++)
    {
        std::cout << i + 1 << ". " << this->get_accounts()[i]->get_custom_name() << " - " << this->get_accounts()[i]->get_type() << " Account" << std::endl;
    }
    std::cout << std::endl;
}

void Customer::load_account(Account* account)
{
	this->accounts.push_back(account);
}

int Customer::verify_passes(std::string input_login, std::string input_password) const
{
    if (this->verify_login(input_login) && this->verify_password(input_password))
    {
        return 1;
    }
    else if (this->verify_login(input_login))
    {
        return -1;
    }
    return 0;
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

PolishCustomer::PolishCustomer()
{
    this->type = 0;
}

bool PolishCustomer::set_id(std::string input_id)
{
	if (input_id.length() == 11)
	{
		this->pesel = input_id;
		return true;
	}
    return false;
}

bool PolishCustomer::set_phone_number(std::string input_phone_number)
{
	if (input_phone_number.length() == 9)
	{
		this->phone_number = input_phone_number;
		return true;
	}   
    return false;
}

std::string PolishCustomer::get_id() const
{
    return this->pesel;
}

std::string PolishCustomer::get_phone_number() const
{
    return this->phone_number;
}

void PolishCustomer::info() const
{
    std::cout << "You are registered as a Polish customer" << std::endl;
    std::cout << std::endl;
	std::cout << "Your name: " << this->get_name() << std::endl;
	std::cout << "Your surname: " << this->get_surname() << std::endl;
	std::cout << "Your date of birth: " << this->get_date_of_birth() << std::endl;
	std::cout << "Your PESEL: " << this->get_id() << std::endl;
	std::cout << "Your address: " << this->get_address() << std::endl;
	std::cout << "Your postal code: " << this->get_postal_code() << std::endl;
	std::cout << "Your city: " << this->get_city() << std::endl;
	std::cout << "Your phone number: " << this->get_phone_number() << std::endl;
	std::cout << "Your mail: " << this->get_mail() << std::endl;
}

ForeignCustomer::ForeignCustomer()
{
	this->type = 1;
}

bool ForeignCustomer::set_id(std::string input_id)
{
	if (input_id.length() == 9)
	{
		for (int i = 0; i < 2; i++)
		{
			if (!isalpha(input_id[i]))
				return false;
		}
		for (int i = 2; i < input_id.length(); i++)
		{
			if (!isdigit(input_id[i]))
				return false;
		}
		this->passport = input_id;
		return true;
	}
    return false;
}

bool ForeignCustomer::set_phone_number(std::string input_phone_number)
{
    if (input_phone_number[0] == '+' && input_phone_number.length() == 12)
    {
		for(int i = 1; i < input_phone_number.length(); i++)
	    {
		    if (!isdigit(input_phone_number[i]))
			    return false;
	    }
		this->phone_number = input_phone_number;
		return true;
    }
    return false;
}

std::string ForeignCustomer::get_id() const
{
    return this->passport;
}

std::string ForeignCustomer::get_phone_number() const
{
    return this->phone_number;
}

void ForeignCustomer::info() const
{
    std::cout << "You are registered as a foreign customer" << std::endl;
    std::cout << std::endl;
	std::cout << "Your name: " << this->get_name() << std::endl;
	std::cout << "Your surname: " << this->get_surname() << std::endl;
	std::cout << "Your date of birth: " << this->get_date_of_birth() << std::endl;
	std::cout << "Your passport: " << this->get_id() << std::endl;
	std::cout << "Your address: " << this->get_address() << std::endl;
	std::cout << "Your postal code: " << this->get_postal_code() << std::endl;
	std::cout << "Your city: " << this->get_city() << std::endl;
	std::cout << "Your phone number: " << this->get_phone_number() << std::endl;
	std::cout << "Your mail: " << this->get_mail() << std::endl;
}