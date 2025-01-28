#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Customer.h"
#include "Account.h"
#include "Transaction.h"
#include "utilities.h"
#include <windows.h>

constexpr auto customers_file = "customers.dat";
constexpr auto accounts_file = "accounts.dat";
constexpr auto transactions_file = "transactions.dat";

constexpr auto delimiter = ':';

enum menu_options 
{
    EXIT = 0,
    LOG_IN,
    SIGN_UP,
    NUM_OF_MENU_OPTIONS
};

enum account_options
{
    LOG_OUT = 0,
    OPEN,
    CLOSE,
    SELECT,
    NUM_OF_ACCOUNT_OPTIONS
};

enum account_operations
{
    CHANGE_ACCOUNT = 0,
    DEPOSIT,
    WITHDRAW,
    TRANSFER,
    NUM_OF_ACCOUNT_OPERATIONS
};

class Application
{
private:
    std::vector<Customer*> customers;
    unsigned short int choice;
    Customer* current_user;
    Account* selected_account;
    void save_customers();
    void save_accounts(std::vector<Account*> accounts);
    void save_transactions(std::vector<Transaction*> transactions);
public:
    void run();
    void menu();
    void logIn();
    void signUp();
    void personalized();
    void selectedAccount();
    void transfer();
    void save(std::vector<Customer*> customers, std::vector<Account*> accounts, std::vector<Transaction*> transactions);
    void read_customers();
    void read_accounts();
    void read_transactions();
};