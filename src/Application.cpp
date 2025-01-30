#include "Application.h"

Application::Application()
{
    this->read_all();
}

Application::~Application()
{
    this->save_all();
	for (auto& c : this->customers){
		for (auto& a : c->get_accounts()){
			for (auto& t : a->get_transactions())
				delete t;
            a->get_transactions().clear();
			delete a;
		}
		c->get_accounts().clear();
	}
    this->customers.clear();
}

void Application::run()
{
    bool running = true;
    while (running){
        running = this->main_menu();
        while (this->current_user != nullptr){
            this->logged_user();
            while (this->selected_account != nullptr)
                this->logged_account();
        }
    }
}

bool Application::main_menu()
{
    clear();
    std::cout << "==========BANKING SYSTEM==========" << std::endl;
    std::cout << std::endl;
    std::cout << "Welcome!" << std::endl;
    std::cout << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "1. Log in" << std::endl;
    std::cout << "2. Sign up" << std::endl;
    std::cout << std::endl;
    do{
        std::cout << "Choice: ";
        std::cin >> this->choice;
    }while (this->choice < 0 || this->choice >= NUM_OF_MENU_OPTIONS);
    clear();
    switch (this->choice){
        case EXIT:
            std::cout << "Bye!" << std::endl;
            sleep(1);
            return false;
        break;
        case LOG_IN:
            this->log_in();
        break;
        case SIGN_UP:
            this->sign_up();
        break;
    }
}

void Application::log_in()
{
    std::string input_l, input_p;
    bool found_login = false;
    clear();
    while (true){
		found_login = false;
        std::cout << "Your login: ";
        std::cin >> input_l;
        std::cout << "Your password: ";
        std::cin >> input_p;
        std::cout << std::endl;
        for (auto& c : this->customers){
			if (c->verify_passes(input_l, input_p) == 1){
				clear();
				std::cout << "Success! You are now logged in as " << c->get_name() << " " << c->get_surname() << "!" << std::endl;
				sleep(1);
				clear();
				this->current_user = c;
				return;
			}else if (c->verify_passes(input_l, input_p) == -1){
				found_login = true;
				std::cout << "Incorrect password!" << std::endl;
				sleep(1);
				clear();
				break;
			}
        }
        if (!found_login){
            std::cout << "Incorrect login!" << std::endl;
            sleep(1);
            clear();
        }
    }
}

void Application::sign_up()
{
    clear();
	char choice;
	std::cout << "Are you from Poland? (Y/N): ";
    std::string l, p, n, s, d, ps, a, c, pc, pn, m;
    std::cin >> choice;
    sleep(1);
    clear();
    if (choice == 'Y' || choice == 'y'){
        PolishCustomer* new_client = new PolishCustomer();
        while (std::getchar() != '\n');
        std::cout << "Your login: ";
        std::getline(std::cin, l);
        new_client->set_login(l);
        std::cout << "Your password: ";
        std::getline(std::cin, p);
        new_client->set_password(p);
        std::cout << "Your name: ";
        std::getline(std::cin, n);
        new_client->set_name(n);
        std::cout << "Your surname: ";
        std::getline(std::cin, s);
        new_client->set_surname(s);
        std::cout << "Your date of birth (DD-MM-YYYY): ";
        std::getline(std::cin, d);
        if (!new_client->set_date_of_birth(d)){
            std::cout << "Invalid date of birth!" << std::endl;
			delete new_client;
            sleep(1);
            return;
        }
        std::cout << "Your PESEL: ";
        std::getline(std::cin, ps);
        if (!new_client->set_id(ps)){
            std::cout << "Invalid PESEL!" << std::endl;
            delete new_client;
            sleep(1);
            return;
        }
        std::cout << "Your address: ";
        std::getline(std::cin, a);
        new_client->set_address(a);
        std::cout << "Your postal code (XX-XXX): ";
        std::getline(std::cin, pc);
        if (!new_client->set_postal_code(pc)){
            std::cout << "Invalid postal code!" << std::endl;
            delete new_client;
            sleep(1);
            return;
        }
        std::cout << "Your city: ";
        std::getline(std::cin, c);
        new_client->set_city(c);
        std::cout << "Your phone number (+48 XXXXXXXXX): ";
        std::getline(std::cin, pn);
        if (!new_client->set_phone_number(pn)){
            std::cout << "Invalid phone number!" << std::endl;
            delete new_client;
            sleep(1);
            return;
        }
        std::cout << "Your mail: ";
        std::getline(std::cin, m);
        if (!new_client->set_mail(m)){
            std::cout << "Invalid mail!" << std::endl;
            delete new_client;
            sleep(1);
            return;
        }
        this->customers.push_back(new_client);
    }else if (choice == 'N' || choice == 'n'){
        ForeignCustomer* new_client = new ForeignCustomer();
        while (std::getchar() != '\n');
        std::cout << "Your login: ";
        std::getline(std::cin, l);
        new_client->set_login(l);
        std::cout << "Your password: ";
        std::getline(std::cin, p);
        new_client->set_password(p);
        std::cout << "Your name: ";
        std::getline(std::cin, n);
        new_client->set_name(n);
        std::cout << "Your surname: ";
        std::getline(std::cin, s);
        new_client->set_surname(s);
        std::cout << "Your date of birth (DD-MM-YYYY): ";
        std::getline(std::cin, d);
        if (!new_client->set_date_of_birth(d)){
            std::cout << "Invalid date of birth!" << std::endl;
            delete new_client;
            sleep(1);
            return;
        }
        std::cout << "Your passport (LLDDDDDDD): ";
        std::getline(std::cin, ps);
        if (!new_client->set_id(ps)){
            std::cout << "Invalid passport!" << std::endl;
			delete new_client;
            sleep(1);
            return;
        }
        std::cout << "Your address: ";
        std::getline(std::cin, a);
        new_client->set_address(a);
        std::cout << "Your postal code (XX-XXX): ";
        std::getline(std::cin, pc);
        if (!new_client->set_postal_code(pc)){
            std::cout << "Invalid postal code!" << std::endl;
			delete new_client;
            sleep(1);
            return;
        }
        std::cout << "Your city: ";
        std::getline(std::cin, c);
        new_client->set_city(c);
        std::cout << "Your phone number (+XXXXXXXXXXX): ";
        std::getline(std::cin, pn);
        if (!new_client->set_phone_number(pn)){
            std::cout << "Invalid phone number!" << std::endl;
            delete new_client;
            sleep(1);
            return;
        }
        std::cout << "Your mail: ";
        std::getline(std::cin, m);
        if (!new_client->set_mail(m)){
            std::cout << "Invalid mail!" << std::endl;
            delete new_client;
            sleep(1);
            return;
        }
        this->customers.push_back(new_client);
    }
    else{
        std::cout << "Invalid choice!" << std::endl;
        sleep(1);
        return;
    }
    std::cout << "Successfully created account!" << std::endl;
    sleep(1);
    clear();
}

void Application::logged_user()
{
    clear();
    std::cout << "Hello " << this->current_user->get_name() << "!" << std::endl;
    std::cout << std::endl;
    std::cout << "0. Log out" << std::endl;
    std::cout << "1. Open account" << std::endl;
    std::cout << "2. Close account" << std::endl;
    std::cout << "3. Select account" << std::endl;
	std::cout << "4. About you" << std::endl;
    std::cout << std::endl;
    do{
        std::cout << "Choice: ";
        std::cin >> choice;
    }while (choice < 0 or choice >= NUM_OF_ACCOUNT_OPTIONS);
    clear();
    switch (choice){
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
            if (this->current_user->get_accounts().size() == 0){
                std::cout << "No opened accounts" << std::endl;
                sleep(1);
            }else{
                std::cout << "Your accounts: " << std::endl;
                this->current_user->list_accounts();
                do{
                    std::cout << "Choice: ";
                    std::cin >> choice;
                    choice--;
                }while (choice < 0 || choice >= this->current_user->get_accounts().size());
                this->selected_account = this->current_user->get_accounts()[choice];
                this->logged_account();
            }
            clear();
        break;
        case INFO:
            this->current_user->info();
            std::cout << std::endl;
            pause();
        break;
    }
}

void Application::logged_account()
{
    float amount = 0;
    int tmp = 0;
    clear();
    std::cout << "Hello " << this->current_user->get_name() << "!" << std::endl;
    std::cout << std::endl;
    std::cout << "Account: " << this->selected_account->get_custom_name() << std::endl;
    std::cout << "Type: " << this->selected_account->get_type() << std::endl;
    std::cout << "Balance: " << this->selected_account->get_balance() << "$" << std::endl;
	if (this->selected_account->get_type() == "Savings")
		std::cout << "Interest rate: " << dynamic_cast<SavingsAccount*>(this->selected_account)->interest_rate << " %" << std::endl;
    else if (this->selected_account->get_type() == "Company"){
		std::cout << "Company name: " << dynamic_cast<CompanyAccount*>(this->selected_account)->company_name << std::endl;
		std::cout << "Company NIP: " << dynamic_cast<CompanyAccount*>(this->selected_account)->company_nip << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Operations:" << std::endl;
    std::cout << std::endl;
    std::cout << "0. Change account" << std::endl;
    std::cout << "1. Deposit" << std::endl;
    std::cout << "2. Withdraw" << std::endl;
    std::cout << "3. Transfer" << std::endl;
	std::cout << "4. List transactions" << std::endl;
	if (this->selected_account->get_type() == "Savings"){
		std::cout << "5. Calculate interest" << std::endl;
        std::cout << std::endl;
        do{
            std::cout << "Choice: ";
            std::cin >> choice;
        }while (choice < 0 || choice >= NUM_OF_ACCOUNT_OPERATIONS);
	}else{
		std::cout << std::endl;
        do{
            std::cout << "Choice: ";
            std::cin >> choice;
        }while (choice < 0 || choice >= NUM_OF_ACCOUNT_OPERATIONS - 1);
    }
    clear();
    switch (choice){
        case CHANGE_ACCOUNT:
            this->selected_account = nullptr;
            return;
        break;
        case DEPOSIT:
            this->deposit();
        break;
        case WITHDRAW:
            this->withdraw();
        break;
        case TRANSFER:
            this->transfer();
        break;
	    case LIST_TRANSACTIONS:
		    this->selected_account->list_transactions();
        break;
	    case CALCULATE_INTEREST:
            this->calculate_interest();
        break;
    }
    clear();
}

void Application::deposit()
{
    float amount;
    std::cout << "How much money would you like to deposit? ";
    std::cin >> amount;
    this->selected_account->deposit(amount);
    sleep(1);
    clear();
    std::cout << "Successfully deposited " << amount << "$ to your account!" << std::endl;
    sleep(1);
}

void Application::withdraw()
{
    float amount;
    std::cout << "How much money would you like to withdraw? ";
    std::cin >> amount;
    sleep(1);
    clear();
    if (this->selected_account->withdraw(amount))
        std::cout << "Successfully withdrawed " << amount << "$ from your account!" << std::endl;
    sleep(1);
}

void Application::transfer()
{
    float amount = 0;
    int current_user_index = 0, desired_user_index = 0, choice = 0;
    std::cout << "Who do you want to transfer money to? " << std::endl << std::endl;
    for (int i = 0; i < this->customers.size(); i++){
        if (this->customers[i] == this->current_user){
            current_user_index = i;
            continue;
        }
        std::cout << i + 1 << ". " << this->customers[i]->get_name() << " " << this->customers[i]->get_surname() << std::endl;
    }
    std::cout << std::endl;
    do{
        std::cout << "Choice: ";
        std::cin >> choice;
    }while ((choice - 1 < 0 || choice - 1 >= this->customers.size()) && choice - 1 != current_user_index);
    desired_user_index = choice - 1;
    std::cout << std::endl;
    if (this->customers[desired_user_index]->get_accounts().size() == 0){
        std::cout << "Selected user has no opened accounts" << std::endl;
        sleep(1);
        return;
    }
    std::cout << "To which account do you want to transfer money?" << std::endl;
    this->customers[desired_user_index]->list_accounts();
    do{
        std::cout << "Choice: ";
        std::cin >> choice;
    }while ((choice - 1 < 0 || choice - 1 >= this->customers[desired_user_index]->get_accounts().size()));
    std::string title = "";
    std::cout << std::endl;
    std::cout << "What is the title of the transfer (leave blank for default title)? ";
    while (std::getchar() != '\n');
    std::getline(std::cin, title);
    if (title == "")
        title = "Transfer";
    std::cout << "How much money would you like to transfer? ";
    std::cin >> amount;
    if (this->selected_account->withdraw(amount, title)){
        this->customers[desired_user_index]->get_accounts()[choice - 1]->deposit(amount, title);
        std::cout << "Successfully transfered " << amount << "$ to " << this->customers[desired_user_index]->get_name() << " " << this->customers[desired_user_index]->get_surname() << "!" << std::endl;
    }
    sleep(2);
}

void Application::calculate_interest()
{
    float interest_rate = dynamic_cast<SavingsAccount*>(this->selected_account)->interest_rate;
	std::cout << "Your interest rate is: " << interest_rate << " %" << std::endl;
    std::cout << "How many months would you like to calculate interest for? ";
	int months;
	std::cin >> months;
	float interest = std::round(this->selected_account->get_balance() * interest_rate / 100 * months / 12 * 100.0f) / 100.0f;
	std::cout << "After " << months << " months you will have " << this->selected_account->get_balance() + interest << "$ in total (interest: " << interest << "$)" << std::endl;
    std::cout << std::endl;
    pause();
}

void Application::read_all()
{
    this->read_customers();
    this->read_accounts();
	this->read_transactions();
}

void Application::read_customers()
{
    std::vector<Customer*> c;
    std::vector<std::string> data;
    std::string line = "", s = "";
    std::fstream file(customers_file, std::ios::in | std::ios::binary);
    while (std::getline(file, line)){
        data.clear();
        std::stringstream ss(line);
        while (std::getline(ss, s, delimiter))
            data.push_back(s);
        if (stoi(data[0]) == 0){
			PolishCustomer* new_customer = new PolishCustomer();
			new_customer->set_name(data[1]);
			new_customer->set_surname(data[2]);
			new_customer->set_date_of_birth(data[3]);
			new_customer->set_id(data[4]);
			new_customer->set_address(data[5]);
			new_customer->set_city(data[6]);
			new_customer->set_postal_code(data[7]);
			new_customer->set_phone_number(data[8]);
			new_customer->set_mail(data[9]);
			new_customer->set_login(data[10]);
			new_customer->set_password(data[11]);
			c.push_back(new_customer);
		}else if (stoi(data[0]) == 1){
            ForeignCustomer* new_customer = new ForeignCustomer();
            new_customer->set_name(data[1]);
            new_customer->set_surname(data[2]);
            new_customer->set_date_of_birth(data[3]);
            new_customer->set_id(data[4]);
            new_customer->set_address(data[5]);
            new_customer->set_city(data[6]);
            new_customer->set_postal_code(data[7]);
            new_customer->set_phone_number(data[8]);
            new_customer->set_mail(data[9]);
            new_customer->set_login(data[10]);
            new_customer->set_password(data[11]);
            c.push_back(new_customer);
        }
    }
    file.close();
    this->customers = c;
    c.clear();
}

void Application::read_accounts()
{
    std::fstream file(accounts_file, std::ios::in | std::ios::binary);
    std::vector<std::string> data;
    std::string line = "", s = "";
	std::string owner_name = "", owner_surname = "";
    while (std::getline(file, line)){
        data.clear();
        std::stringstream ss(line);
        while (std::getline(ss, s, delimiter))
            data.push_back(s);
		owner_name = data[1];
		owner_surname = data[2];
		for (auto& customer : this->customers){
			if (customer->get_name() == owner_name && customer->get_surname() == owner_surname){
                if (data[0] == "Regular")
                    customer->load_account(new RegularAccount(data[3], stof(data[4])));
                else if (data[0] == "Savings")
                    customer->load_account(new SavingsAccount(data[3], stof(data[4]), stof(data[5])));
                else if (data[0] == "Company")
                    customer->load_account(new CompanyAccount(data[3], stof(data[4]), data[5], data[6]));
				break;
			}
		}
    }
    file.close();
}

void Application::read_transactions()
{
    std::fstream file(transactions_file, std::ios::in | std::ios::binary);
    std::vector<std::string> data;
    std::string line = "", s = "";
    std::string owner_name = "", owner_surname = "", account_name = "";
    while (std::getline(file, line)){
        data.clear();
        std::stringstream ss(line);
        while (std::getline(ss, s, delimiter))
            data.push_back(s);
        owner_name = data[0];
        owner_surname = data[1];
		account_name = data[2];
		for (auto& customer : this->customers){
			if (customer->get_name() == owner_name && customer->get_surname() == owner_surname){
				for (auto& account : customer->get_accounts()){
					if (account->get_custom_name() == account_name){
						account->load_transaction(new Transaction(data[3], data[4], stof(data[5])));
						break;
					}
				}
				break;
			}
		}
    }
    file.close();
}

void Application::save_all()
{
    this->save_customers();
    this->save_accounts();
    this->save_transactions();
}

void Application::save_customers()
{
    std::fstream file(customers_file, std::ios::out | std::ios::binary);
    for (auto& customer : this->customers){
        file << customer->type << delimiter;
        file << customer->get_name() << delimiter;
        file << customer->get_surname() << delimiter;
        file << customer->get_date_of_birth() << delimiter;
		file << customer->get_id() << delimiter;
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

void Application::save_accounts()
{
    std::fstream file(accounts_file, std::ios::out | std::ios::binary);
    for (auto& customer : this->customers){
        for (auto& account : customer->get_accounts()){
            file << account->get_type() << delimiter;
            file << customer->get_name() << delimiter;
            file << customer->get_surname() << delimiter;
            file << account->get_custom_name() << delimiter;
            file << account->get_balance();
            if (account->get_type() == "Savings")
                file << delimiter << dynamic_cast<SavingsAccount*>(account)->interest_rate;
            else if (account->get_type() == "Company"){
                file << delimiter << dynamic_cast<CompanyAccount*>(account)->company_name;
                file << delimiter << dynamic_cast<CompanyAccount*>(account)->company_nip;
            }
            file << std::endl;
        }
    }
    file.close();
}

void Application::save_transactions()
{
    std::fstream file(transactions_file, std::ios::out | std::ios::binary);
    for (auto &customer : this->customers){
        for (auto &account : customer->get_accounts()){
            for (auto& transaction : account->get_transactions()){
				file << customer->get_name() << delimiter;
				file << customer->get_surname() << delimiter;
				file << account->get_custom_name() << delimiter;
				file << transaction->get_date() << delimiter;
				file << transaction->get_title() << delimiter;
                file << transaction->get_amount() << std::endl;
            }
        }
    }
    file.close();
}