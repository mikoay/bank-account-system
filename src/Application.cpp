#include "Application.h"

void Application::run()
{
    Database *database=new Database(DB_NAME);
    this->customers.push_back(new Customer("Mikolaj", "Dlugolecki", "16.02.2003", "03221606235", "Rajgrod 8a", "Mrocza", "89-115", "698960087", "mikolaj.dlug@gmail.com", "mikolaj1602", "test"));
    while (true)
    {
        this->menu();
        while (this->current_user != nullptr)
        {
            this->personalized();
        }
    }
    delete database;
}

void Application::menu()
{
    std::cout << "==========BANKING SYSTEM==========" << std::endl;
    std::cout << std::endl << "Welcome!" << std::endl << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "1. Log in" << std::endl;
    std::cout << "2. Sign up" << std::endl;
    std::cout << std::endl;
    do
    {
        std::cout << "Choice: ";
        std::cin >> this->choice;
    } while (this->choice < 0 || this->choice >=NUM_OF_MENU_OPTIONS);
    switch (this->choice)
    {
    case EXIT:
        std::cout << "Bye!" << std::endl;
        exit(0);
        break;
    case LOG_IN:
        this->logIn();
        break;
    case SIGN_UP:
        this->signUp();
        break;
    }
}

void Application::logIn()
{
    std::string input_l, input_p;
    bool logged = false;
    while (!logged)
    {
        std::cout << "Your login: ";
        std::cin >> input_l;
        std::cout << "Your password: ";
        std::cin >> input_p;
        for (auto& c : this->customers)
        {
            if (c->verify_login(input_l) && c->verify_password(input_p))
            {
                std::cout << "Success! You are now logged in as " << c->get_name() << " " << c->get_surname() << std::endl;
                this->current_user = c;
                logged = true;
                return;
            }
            else if (c->verify_login(input_l))
            {
                std::cout << "Incorrect password!" << std::endl;
                break;
            }
        }
        std::cout << "Incorrect login!" << std::endl;
    }
}

void Application::signUp()
{
    std::string l, p, n, s, d, ps, a, c, pc, pn, m;
    std::cout << "Your login: ";
    std::cin >> l;
    std::cout << "Your password: ";
    std::cin >> p;
    std::cout << "Your name: ";
    std::cin >> n;
    std::cout << "Your surname: ";
    std::cin >> s;
    std::cout << "Your date of birth (DD-MM-YYYY): ";
    std::cin >> d;
    std::cout << "Your PESEL: ";
    std::cin >> ps;
    std::cout << "Your address: ";
    std::cin >> a;
    std::cout << "Your city: ";
    std::cin >> c;
    std::cout << "Your postal code (XX-XXX): ";
    std::cin >> pc;
    std::cout << "Your phone number: ";
    std::cin >> pn;
    std::cout << "Your mail: ";
    std::cin >> m;
    this->customers.push_back(new Customer(n, s, d, ps, a, c, pc, pn, m, l, p));
    std::cout << "Success!" << std::endl;
}

void Application::personalized()
{
    unsigned int choice = 0;
    std::cout << "Hello " << this->current_user->get_name() << "!" << std::endl;
    std::cout << "0. Log out" << std::endl;
    std::cout << "1. Open new account" << std::endl;
    std::cout << "2. Close accout" << std::endl;
    std::cout << "3. Select account" << std::endl;
    std::cout << std::endl;
    do 
    {
        std::cout << "Choice: ";
        std::cin >> choice;
    } while (choice < 0 or choice >= NUM_OF_ACCOUNT_OPTIONS);
    switch (choice)
    {
    case LOG_OUT:
        std::cout << "Bye!" << std::endl;
        this->current_user = nullptr;
        break;
    case OPEN:
        this->current_user->open_account();
        break;
    case CLOSE:
        this->current_user->close_account();
        break;
    case SELECT:
        std::cout << std::endl << "Your accounts: " << std::endl;
        if (this->current_user->get_accounts().size() == 0)
        {
            std::cout << "No opened accounts" << std::endl;
        }
        else
        {
            for (auto& acc : this->current_user->get_accounts())
            {
                std::cout << "Account" << std::endl;
            }
        }
        break;
    }
}
