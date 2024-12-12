#pragma once
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>

class Transaction
{
private:
    float amount;
    std::string transaction_type;
    std::string date;
    std::string title;
public:
    Transaction(float amount);
    Transaction(float amount, std::string title);
    float get_amount();
    std::string get_date();
    std::string get_title();
};