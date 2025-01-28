#include "Transaction.h"

Transaction::Transaction(float amount)
{
    this->amount=amount;
    this->title="Transfer";
}

Transaction::Transaction(float amount, std::string title)
{
    this->amount=amount;
    this->title=title;
}

float Transaction::get_amount() const
{
    return this->amount;
}

std::string Transaction::get_date() const
{
    return this->date;
}

std::string Transaction::get_title() const
{
    return this->title;
}