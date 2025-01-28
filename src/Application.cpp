#include "Application.h"

void Application::save_customers()
{
    std::fstream file(customers_file, std::ios::out | std::ios::binary);
    for (auto& customer : this->customers)
    {
        file << customer->get_name() << delimiter;
        file << customer->get_surname() << delimiter;
        file << customer->get_date_of_birth() << delimiter;
        file << customer->get_pesel() << delimiter;
        file << customer->get_address() << delimiter;
        file << customer->get_city() << delimiter;
        file << customer->get_postal_code() << delimiter;
        file << customer->get_phone_number() << delimiter;
        file << customer->get_mail() << delimiter;
        file << customer->get_login() << delimiter;
        file << customer->get_password() << std::endl;
    }
    file.close();
}

void Application::save_accounts(std::vector<Account*> accounts)
{
    std::fstream file(accounts_file, std::ios::out | std::ios::binary);
    file.close();
}

void Application::save_transactions(std::vector<Transaction*> transactions)
{
    std::fstream file(transactions_file, std::ios::out | std::ios::binary);
    file.close();
}

void Application::run()
{
    this->read_customers();
    //this->customers.push_back(new Customer("Mikolaj", "Dlugolecki", "16-02-2003", "03221606235", "Rajgrod 8a", "Mrocza", "89-115", "698960087", "mikolaj.dlug@gmail.com", "mikolaj1602", "test"));
    while (true)
    {
        this->menu();
        while (this->current_user != nullptr)
        {
            this->personalized();
            while (this->selected_account != nullptr)
            {
                this->selectedAccount();
            }
        }
    }
    this->save_customers();
}

void Application::menu()
{
    clear();
    for (auto& customer : this->customers)
    {
        std::cout << customer->get_name() << std::endl;
    }
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
    clear();
    switch (this->choice)
    {
    case EXIT:
        this->save_customers();
        std::cout << "Bye!" << std::endl;
        sleep(1);
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
    clear();
    while (!logged)
    {
        std::cout << "Your login: ";
        std::cin >> input_l;
        std::cout << "Your password: ";
        std::cin >> input_p;
        std::cout << std::endl;
        for (auto& c : this->customers)
        {
            if (c->verify_login(input_l) && c->verify_password(input_p))
            {
                std::cout << "Success! You are now logged in as " << c->get_name() << " " << c->get_surname() << "!" << std::endl;
                sleep(1);
                clear();
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
        std::cout << "Incorrect login!" << std::endl; //???
    }
}

void Application::signUp()
{
    clear();
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
    std::cout << "Successfully created account!" << std::endl;
    sleep(1);
    clear();
}

void Application::personalized()
{
    clear();
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
    clear();
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
        clear();
        if (this->current_user->get_accounts().size() == 0)
        {
            std::cout << "No opened accounts" << std::endl;
            sleep(1);
        }
        else
        {
            std::cout << "Your accounts: " << std::endl;
            this->current_user->list_accounts();
            do {
                std::cout << "Choice: ";
                std::cin >> choice;
                choice--;
            } while (choice < 0 || choice >= this->current_user->get_accounts().size());
            this->selected_account = this->current_user->get_accounts()[choice];
            this->selectedAccount();
        }
        clear();
        break;
    }
}

void Application::selectedAccount()
{
    float amount = 0;
    int tmp = 0;
    clear();
    std::cout << "Hello " << this->current_user->get_name() << "!" << std::endl;
    std::cout << std::endl;
    std::cout << "Account: " << this->selected_account->get_custom_name() << std::endl;
    std::cout << "Type: " << this->selected_account->get_type() << std::endl;
    std::cout << "Balance: " << this->selected_account->get_balance() << "$" << std::endl;
    std::cout << std::endl;
    std::cout << "Operations:" << std::endl;
    std::cout << "0. Change account" << std::endl;
    std::cout << "1. Deposit" << std::endl;
    std::cout << "2. Withdraw" << std::endl;
    std::cout << "3. Transfer" << std::endl;
    std::cout << std::endl;
    do {
        std::cout << "Choice: ";
        std::cin >> choice;
    } while (choice < 0 || choice >= NUM_OF_ACCOUNT_OPERATIONS);
    clear();
    switch (choice)
    {
    case CHANGE_ACCOUNT:
        this->selected_account = nullptr;
        return;
        break;
    case DEPOSIT:
        std::cout << "How much money would you like to deposit? ";
        std::cin >> amount;
        this->selected_account->deposit(amount);
        std::cout << std::endl << "Successfully deposited " << amount << "$ to your account!" << std::endl;
        sleep(1);
        break;
    case WITHDRAW:
        std::cout << "How much money would you like to withdraw? ";
        std::cin >> amount;
        this->selected_account->withdraw(amount);
        std::cout << std::endl << "Successfully withdrawed " << amount << "$ from your account!" << std::endl;
        sleep(1);
        break;
    case TRANSFER:
		this->transfer();
        break;
    }
    clear();
}

void Application::transfer()
{
    float amount = 0;
    int current_user_index = 0, desired_user_index = 0, choice = 0;
    std::cout << "Who do you want to transfer money to? " << std::endl << std::endl;
    for (int i = 0; i < this->customers.size(); i++)
    {
        if (this->customers[i] == this->current_user)
        {
            current_user_index = i;
            continue;
        }
        std::cout << i + 1 << ". " << this->customers[i]->get_name() << " " << this->customers[i]->get_surname() << std::endl;
    }
    do
    {
        std::cout << "Choice: ";
        std::cin >> choice;
    } while ((choice - 1 < 0 || choice - 1 >= this->customers.size()) && choice - 1 != current_user_index);
    desired_user_index = choice - 1;
	if (this->customers[desired_user_index]->get_accounts().size() == 0)
	{
		std::cout << "Selected user has no opened accounts" << std::endl;
		sleep(1);
		return;
	}
    std::cout << "To which account do you want to transfer money?" << std::endl;
    this->customers[desired_user_index]->list_accounts();
    do
    {
        std::cout << "Choice: ";
        std::cin >> choice;
    } while ((choice - 1 < 0 || choice - 1 >= this->customers[desired_user_index]->get_accounts().size()));
    std::string title = "";
    std::cout << "What is the title of the transfer (leave blank for default title)?" << std::endl;
    while (std::getchar() != '\n');
    std::getline(std::cin, title);
    if (title == "")
    {
        title = "Transfer";
    }
    std::cout << "How much money would you like to transfer? " << std::endl;
    std::cin >> amount;
    if (this->selected_account->withdraw(amount, title))
    {
        this->customers[desired_user_index]->get_accounts()[choice - 1]->deposit(amount, title);
        std::cout << "Successfully transfered " << amount << "$ to " << this->customers[desired_user_index]->get_name() << " " << this->customers[desired_user_index]->get_surname() << "!" << std::endl;
    }
    sleep(2);
}

void Application::save(std::vector<Customer*> customers, std::vector<Account*> accounts, std::vector<Transaction*> transactions)
{
    this->save_customers();
    this->save_accounts(accounts);
    this->save_transactions(transactions);
}

void Application::read_customers()
{
    std::vector<Customer*> c;
    std::vector<std::string> data;
    std::string line = "", s="";
    std::fstream file(customers_file, std::ios::in | std::ios::binary);
    while (std::getline(file, line))
    {
        data.clear();
        std::stringstream ss(line);
        while (std::getline(ss, s, delimiter))
        {
            data.push_back(s);
        }
        c.push_back(new Customer(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8], data[9], data[10]));
    }
    file.close();
    this->customers = c;
    c.clear();
}

void Application::read_accounts()
{
    std::fstream file(accounts_file, std::ios::in | std::ios::binary);
    // TODO
    file.close();
}

void Application::read_transactions()
{
    std::fstream file(transactions_file, std::ios::in | std::ios::binary);
	// TODO
    file.close();
}