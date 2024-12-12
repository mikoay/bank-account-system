#pragma once
#include "Database.h"
#include "Customer.h"

constexpr auto DB_NAME = "bank.db";

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

class Application
{
private:
    std::vector<Customer*> customers;
    unsigned short int choice;
    Customer* current_user;
public:
    void run();
    void menu();
    void logIn();
    void signUp();
    void personalized();
};