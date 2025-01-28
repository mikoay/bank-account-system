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
    std::string date; // TODO
    std::string title;
public:
    Transaction(float amount);
    Transaction(float amount, std::string title);
    float get_amount() const;
    std::string get_date() const;
    std::string get_title() const;
};