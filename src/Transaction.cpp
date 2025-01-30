#include "Transaction.h"

Transaction::Transaction(float amount)
{
    this->amount = amount;
    this->title = "Transfer";
	this->date = get_current_date();
}

Transaction::Transaction(float amount, std::string title)
{
    this->amount=amount;
    this->title=title;
	this->date = get_current_date();
}

Transaction::Transaction(std::string input_date, std::string input_title, float input_amount)
{
	this->date = input_date;
	this->title = input_title;
	this->amount = input_amount;
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