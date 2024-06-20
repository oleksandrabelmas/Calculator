#pragma once
#include <iostream>
#include <string>

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

class User
{
protected:
	string name;
	string password;
	unsigned age;
	char sex;
	double weight;
	double height;

	int user_products;

public:

	User() : name(" "), password(" "), age(0), sex('M'), weight(0), height(0) {};

	User(string n, string p, unsigned a, char s, double w, double h) : name(n), password(p), age(a), sex(s), weight(w), height(h) {}

	~User() {}


	// geters
	string get_name();
	string get_password();
	unsigned get_age();
	char get_sex();
	double get_weight();
	double get_height();


	// setters
	void set_username(string username);
	void set_password(string password);
	void set_age(int age);
	void set_sex(char sex);
	void set_weight(double weight);
	void set_height(double height);


	void add_user();
	bool login(User user);
};

