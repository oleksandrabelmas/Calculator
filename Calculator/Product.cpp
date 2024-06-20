#include "Product.h"

using namespace std;


string Product:: get_name() { return name; }
double Product::get_weight() { return weight; }
double Product::get_calories() { return calories; }
double Product::get_proteins() { return proteins; }
double Product::get_carbohydrates() { return carbohydrates; }
double Product::get_fat() { return fat; }


void Product::set_name(string n) { name = n; }
void Product::set_weight(double w) { weight = w; }
void Product::set_calories(double c) { calories = c; }
void Product::set_proteins(double p) { proteins = p; }
void Product::set_carbohydrates(double carbs) { carbohydrates = carbs; }
void Product::set_fat(double f) { fat = f; }