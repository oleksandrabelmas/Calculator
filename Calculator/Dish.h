#pragma once

#include <vector>

#include "Product.h"

class Dish : public Product
{
protected:
	vector<Product> product_list;
	double weight;
	double calories;
	double proteins;
	double carbohydrates;
	double fat;

public:

	Dish(vector<Product> pList) : product_list(pList) {}

	~Dish() {}


	double calculate_weight();
	double calculate_calories();
	double calculate_proteins();
	double calculate_carbohydrates();
	double calculate_fat();

};

