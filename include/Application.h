#pragma once

#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <windows.h>

#include "Customer.h"
#include "Account.h"
#include "Transaction.h"
#include "utils.h"

constexpr auto customers_file = "customers.dat";
constexpr auto accounts_file = "accounts.dat";
constexpr auto transactions_file = "transactions.dat";

constexpr auto delimiter = ':';

enum main_menu_options 
{
    EXIT = 0,
    LOG_IN,
    SIGN_UP,
    NUM_OF_MENU_OPTIONS
};

enum logged_user_options
{
    LOG_OUT = 0,
    OPEN,
    CLOSE,
    SELECT,
    INFO,
    NUM_OF_ACCOUNT_OPTIONS
};

enum logged_account_options
{
    CHANGE_ACCOUNT = 0,
    DEPOSIT,
    WITHDRAW,
    TRANSFER,
    LIST_TRANSACTIONS,
	CALCULATE_INTEREST,
    NUM_OF_ACCOUNT_OPERATIONS
};

class Application
{
public:
    Application();
    ~Application();
    void run();
private:
    std::vector<Customer*> customers;
    unsigned short int choice;
    Customer* current_user;
    Account* selected_account;
    void main_menu();
    void log_in();
    void sign_up();
    void logged_user();
    void logged_account();
    void deposit();
    void withdraw();
    void transfer();
	void calculate_interest();
    void read_all();
    void read_customers();
    void read_accounts(); // TODO
	void read_transactions(); // TODO
    void save_all();
    void save_customers();
	void save_accounts(); // TODO
	void save_transactions(); // TODO
};