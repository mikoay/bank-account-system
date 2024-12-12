#pragma once
#include <sqlite3.h>
#include <iostream>
#include <vector>

#include "Customer.h"
#include "Transaction.h"

class Database
{
private:
    const char *db_name;
    sqlite3 *db;
    char *err_msg=nullptr;
    int rc;
    static int get_customers_from_db_wrapper(void* data, int argc, char** argv, char** azColName);
    static int callback(void *data, int argc, char **argv, char **azColName);
    int get_customers_from_db(int argc, char **argv, char **azColName);
    int get_all_customers();
    int add_customer_to_db(Customer * new_customer);
public:
    std::vector<Customer*> customers;
    std::vector<Account*> accounts;
    std::vector<Transaction*> transactions;
    Database(const char *input_db_name);
    ~Database();
    // DATABASE OPERATIONS
    int connect();
    int exec_query(const char *input_query);
    int exec_select_query(const char *input_query);
    void close();
    // CUSTOMER 
    int create_customer();
    int update_db();
};
