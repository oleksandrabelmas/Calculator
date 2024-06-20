#include "Dish.h"


double Dish::calculate_weight()
{
	double sum = 0;
	for (auto prd = product_list.begin(); prd != product_list.end(); ++prd)
	{
		sum += (*prd).get_weight();
	}

	return sum;
}

double Dish::calculate_calories()
{
	double sum = 0;
	for (auto prd = product_list.begin(); prd != product_list.end(); ++prd)
	{
		sum += (*prd).get_calories();
	}

	return sum;
}

double Dish::calculate_proteins()
{
	double sum = 0;
	for (auto prd = product_list.begin(); prd != product_list.end(); ++prd)
	{
		sum += (*prd).get_proteins();
	}

	return sum;
}

double Dish::calculate_carbohydrates()
{
	double sum = 0;
	for (auto prd = product_list.begin(); prd != product_list.end(); ++prd)
	{
		sum += (*prd).get_carbohydrates();
	}

	return sum;
}

double Dish::calculate_fat()
{
	double sum = 0;
	for (auto prd = product_list.begin(); prd != product_list.end(); ++prd)
	{
		sum += (*prd).get_fat();
	}

	return sum;
}