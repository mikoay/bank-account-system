#include "Database.h"

Database::Database(const char *input_db_name)
{
    this->db_name=input_db_name;
    this->connect();
    this->get_all_customers();
}

Database::~Database()
{
    this->close();
}

int Database::connect()
{
    if(sqlite3_open(this->db_name, &this->db))
        return -1;
    else
        return 0;
}

int Database::exec_query(const char *input_query)
{
    this->rc=sqlite3_exec(this->db, input_query, nullptr, nullptr, &this->err_msg);
    if(this->rc!=SQLITE_OK)
    {
        std::cerr<<"SQL error: "<<this->err_msg<<std::endl;
        sqlite3_free(this->err_msg);
        return -1;
    }
    return 0;
}

int Database::exec_select_query(const char *input_query)
{
    this->rc=sqlite3_exec(this->db, input_query, this->callback, nullptr, &this->err_msg);
    if(this->rc!=SQLITE_OK)
    {
        std::cerr<<"SQL error: "<<this->err_msg<<std::endl;
        sqlite3_free(this->err_msg);
        return -1;
    }
    return 0;
}

void Database::close()
{
    sqlite3_close(this->db);
}

int Database::callback(void* data, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

int Database::get_all_customers()
{
    this->rc=sqlite3_exec(this->db, "SELECT * FROM customers;", this->get_customers_from_db_wrapper, this, &this->err_msg);
    if(this->rc!=SQLITE_OK)
    {
        std::cerr<<"SQL error: "<<this->err_msg<<std::endl;
        sqlite3_free(this->err_msg);
        return -1;
    }
    return 0;
}

int Database::create_customer()
{
    std::string n, s, d, p, a, c, pc, pn, m;
    std::cout<<"Name: ";
    std::getline(std::cin, n);
    std::cout<<"Surame: ";
    std::getline(std::cin, s);
    std::cout<<"Date of birth: ";
    std::getline(std::cin, d);
    std::cout<<"PESEL: ";
    std::getline(std::cin, p);
    std::cout<<"Address: ";
    std::getline(std::cin, a);
    std::cout<<"City: ";
    std::getline(std::cin, c);
    std::cout<<"Postal Code: ";
    std::getline(std::cin, pc);
    std::cout<<"Phone number: ";
    std::getline(std::cin, pn);
    std::cout<<"Mail: ";
    std::getline(std::cin, m);
    this->customers.push_back(new Customer(n, s, d, p, a, c, pc, pn, m));
    if(this->add_customer_to_db(this->customers.back()));
        return 0;
    return -1;
}

int Database::add_customer_to_db(Customer * new_customer)
{
    std::string data="('"+new_customer->get_name()+"', '"+new_customer->get_surname()+"', '"+new_customer->get_date_of_birth()+"', '"+new_customer->get_pesel()+"', '"+new_customer->get_address()+"', '"+new_customer->get_city()+"', '"+new_customer->get_postal_code()+"', '"+new_customer->get_phone_number()+"', '"+new_customer->get_mail()+"');";
    std::string query="INSERT INTO customers (name, surname, date_of_birth, pesel, address, city, postal_code, phone_number, mail) VALUES ";
    query.append(data); 
    if(this->exec_query(query.c_str()))
        return 0;
    return -1;
}

int Database::update_db()
{
    for(auto &customer : customers)
    {

    }
    return 0;
}

int Database::get_customers_from_db(int argc, char **argv, char **azColName)
{
    this->customers.push_back(new Customer(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9]));
    return 0;
}

int Database::get_customers_from_db_wrapper(void* data, int argc, char** argv, char** azColName)
{
        Database* db = reinterpret_cast<Database*>(data);
        return db->get_customers_from_db(argc, argv, azColName);
}