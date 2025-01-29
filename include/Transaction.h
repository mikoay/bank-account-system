#pragma once

#include <iostream>

#include "utils.h"

class Transaction
{
public:
    Transaction(float amount);
    Transaction(float amount, std::string title);
    float get_amount() const;
    std::string get_date() const;
    std::string get_title() const;
private:
    std::string date;
    std::string title;
    float amount;
};