#include <iostream>
#include <conio.h> 

#include "Product.h"
#include "User.h"

using namespace std;


void creating_tables()
{
    try
    {
        //starting connection
        sql::Driver* driver = get_driver_instance();
        sql::Connection* conn = driver->connect("tcp://127.0.0.1:3306", "root", "root");
        conn->setSchema("porno");

        sql::Statement* stmt = conn->createStatement();

        string create_user_table_query = "CREATE TABLE IF NOT EXISTS users ( \
                                    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY, \
                                    username VARCHAR(255) NOT NULL, \
                                    password VARCHAR(255) NOT NULL, \
                                    age INT NOT NULL, \
                                    sex VARCHAR(1) NOT NULL, \
                                    weight FLOAT NOT NULL, \
                                    height FLOAT NOT NULL);";
        stmt->execute(create_user_table_query);

        string create_user_products_table_query = "CREATE TABLE IF NOT EXISTS user_products ( \
                                            user_id INT NOT NULL, \
                                            product_id INT NOT NULL, \
                                            weight FLOAT NOT NULL, \
                                            FOREIGN KEY(user_id) REFERENCES Users(id), \
                                            FOREIGN KEY(product_id) REFERENCES Products(id), \
                                            PRIMARY KEY(user_id, product_id));";
        stmt->execute(create_user_products_table_query);

        delete stmt;
        delete conn;
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


int main()
{
    //create tables users and users_products
    creating_tables();

    // main menu
    cout << "Hello! It's calculator calories \nLets start! \nYou need register or log in\n\n";

    char choice;
    bool check = true;

    cout << "Press 1 for Registration" << endl;
    cout << "Press 2 for Log in" << endl;
    cout << "Press 'q' to Quit" << endl;

    choice = _getch();

    User user;

    if (choice == 'q') return 0;

    // regrstration
    if (choice == '1')
    {
        system("cls");
        
        cout << "Type your username: ";
        string username; cin >> username;

        cout << "\nCreate password: ";
        string password; cin >> password;

        cout << "\nType your age: ";
        int age; cin >> age;

        // check 'M' and 'F'
        // Огорнути в цикл
        cout << "\Type your sex: ";
        char sex; cin >> sex;
        if (sex == 'm' || sex == 'M') user.set_sex('M');
        else if (sex == 'f' || sex == 'F') user.set_sex('F');
        else cout << "incorect input" << endl;

        cout << "\nType your weight: ";
        double weight; cin >> weight;

        cout << "\nType your height: ";
        double height; cin >> height;

        // create and add user
        user.set_username(username);
        user.set_password(password);
        user.set_age(age);
        user.set_weight(weight);
        user.set_height(height);

        user.add_user();

    }
    // login
    else if (choice == '2')
    {
        // обернути в цикл
        system("cls");
        cout << "Type your username: ";
        string username; cin >> username;
        user.set_username(username);

        cout << "\nType password: ";
        string password; cin >> password;
        user.set_password(password);


        if (user.login() == 1)
        {
            cout << "Login was successful\n";
        }
        else if (user.login() == 2)
        {
            // додати можливість зареєструватися після цього кроку(винести реєстрацію в окрему функцію)
            cout << "login was incorrect. Maybe you want to register?\n";
            check = false;
        }
        else
        {
            cout << "Password was incorrect\n";
            check = false;
        }
    }

    _getch(); 

    // second menu, user account
    if (check)
    {
        system("cls");
        cout << "Hello " << user.get_name() << ", good to see you!\n";
        cout << "Press 1 for calculator" << endl;
        cout << "Press 2 your profile" << endl;
        cout << "Press 'q' to Quit" << endl;

        choice = _getch();

        if (choice == '1')
        {
            try
            {
                //starting connection
                sql::Driver* driver = get_driver_instance();
                sql::Connection* conn = driver->connect("tcp://127.0.0.1:3306", "root", "root");
                conn->setSchema("porno");

                sql::Statement* stmt = conn->createStatement();
                // get all positions
                string get_products_query = "SELECT * FROM products;";
                sql::ResultSet* all_products = stmt->executeQuery(get_products_query);
                system("cls");

                cout << "Choose a product from the list (write number):" << endl;
                // showing all positions to user
                while (all_products->next())
                {
                    cout << all_products->getString(1) << " " << all_products->getString(2) << ";" << endl;
                }

                unsigned int product_id;
                cin >> product_id;
                if (product_id <= all_products->rowsCount())
                {
                    system("cls");

                    // find an product with id
                    sql::ResultSet* find_product = stmt->executeQuery("SELECT * FROM products \
                        WHERE id = '" + to_string(product_id) + "';");

                    if (find_product->next())
                    {
                        cout << "How much grams of " << find_product->getString(2) << " do you want to add? (in grams) ";
                        cout << '\n' << find_product->getString(2) << "   " << find_product->getString(3);
                        double weight;
                        cin >> weight;

                        //string product_name = find_product->getString(2);
                        //double calories = stod(find_product->getString(3));
                        //double proteins = stod(find_product->getString(4));
                        //double carbohydrates = stod(find_product->getString(5));
                        //double fat = stod(find_product->getString(6));

                        //Product product(product_name, weight, calories, proteins, carbohydrates, fat);

                        // get user id
                        //string find_user_id = "SELECT * FROM users WHERE username = '" + user.get_name() + "';";
                        //sql::ResultSet *user_id = stmt->executeQuery(find_user_id);

                        //string insert_user_product_query = "INSERT INTO user_products (user_id, product_id, weight) VALUES (" + to_string(2) + ", " + to_string(product_id) + ", " + to_string(weight) + ");";
                        //stmt->executeUpdate(insert_user_product_query);

                        // clearing
                        delete find_product;
                        delete all_products;
                        delete stmt;
                        delete conn;
                    }
                    else
                    {
                        cout << "Product with ID " << product_id << " not found." << endl;
                    }
                }
                else
                {
                    cout << "Invalid product ID." << endl;
                }
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
        // user account
        else if (choice == '2')
        {
            system("cls");
        }
    }
    else
    {
        cout << "Problem with auth\n";
    }

    cout << "Bye Bye";

    return 0;
}