#pragma once
#include <iostream>

using namespace std;


class Product
{
protected:
	string name;
	double weight;
	double calories;
	double proteins;
	double carbohydrates;
	double fat;

public:
	Product(string n, double w, double c, double p, double carbs, double f)
		: name(n), weight(w), calories(c), proteins(p), carbohydrates(carbs), fat(f) {}

	Product() : name(""), weight(0), calories(0), proteins(0), carbohydrates(0), fat(0) {}

	~Product() {}


	// Encapsulation Methods
	string get_name();
	double get_weight();
	double get_calories();
	double get_proteins();
	double get_carbohydrates();
	double get_fat();


	void set_name(string n);
	void set_weight(double w);
	void set_calories(double c);
	void set_proteins(double p);
	void set_carbohydrates(double carbs);
	void set_fat(double f);
};

