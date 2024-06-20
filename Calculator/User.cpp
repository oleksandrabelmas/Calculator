#include "User.h"


string User::get_name() { return name; }
string User::get_password() { return password; }
unsigned User::get_age() { return age; }
char User::get_sex() { return sex; }
double User::get_weight() { return weight; }
double User::get_height() { return height; }


void User::set_username(string username) { this->name = username; }
void User::set_password(string password) { this->password = password; }
void User::set_age(int age) { this->age = age; }
void User::set_sex(char sex) { this->sex = sex; }
void User::set_weight(double weight) { this->weight = weight; }
void User::set_height(double height) { this->height = height; }


void User::add_user() 
{
    try
    {
        //starting connection
        sql::Driver* driver = get_driver_instance();
        sql::Connection* conn = driver->connect("tcp://127.0.0.1:3306", "root", "root");
        conn->setSchema("porno");

        sql::Statement* stmt = conn->createStatement();

        string add_user_query = "INSERT INTO users (username, password, age, sex, weight, height) VALUES ('" + \
                                this->name + "', '" + \
                                this->password + "', " + \
                                to_string(this->age) + ", '" +\
                                this->sex + "', " + \
                                to_string(this->weight) + ", " + \
                                to_string(this->height) + \
                                ")";

        stmt->executeUpdate(add_user_query);

    }
    catch (sql::SQLException& e)
    {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line "
            << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}

int User::login()
{
    try
    {
        //starting connection
        sql::Driver* driver = get_driver_instance();
        sql::Connection* conn = driver->connect("tcp://127.0.0.1:3306", "root", "root");
        conn->setSchema("porno");

        sql::Statement* stmt = conn->createStatement();

        string check_user_query = "SELECT * FROM Users WHERE username = '" + this->name + "';";

        sql::ResultSet *res = stmt->executeQuery(check_user_query);

        // 2 means incorect login; 0 means incorect password; 1 ok;
        if (res->next())
        {
            return res->getString("password") == this->password;
        }
        else return 2;

    }
    catch (sql::SQLException& e)
    {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line "
            << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}