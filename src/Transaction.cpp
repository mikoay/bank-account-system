#include "Transaction.h"

Transaction::Transaction(float amount)
{
    this->amount=amount;
    this->title="Transfer";
    //this->date=this->get_current_date();
}

Transaction::Transaction(float amount, std::string title)
{
    this->amount=amount;
    this->title=title;
    //this->date=this->get_current_date();
}

float Transaction::get_amount()
{
    return this->amount;
}

std::string Transaction::get_date()
{
    return this->date;
}

std::string Transaction::get_title()
{
    return this->title;
}