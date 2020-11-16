/***************************************************************
 * File: product.cpp
 * Author: Lance Bunch
 * Purpose: Contains the method implementations for the Product class.
 ***************************************************************/

#include "product.h"

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/*****************************************************************
 * Function: prompt
 * Purpose: receives the name, description, weight, and base price
 * 			of the product.
 * **************************************************************/
void Product::prompt()
{
	weight = 0.0;
	basePrice = 0.00;

	cout << "Enter name: ";
	getline(cin, name);

	cout << "Enter description: ";
	getline(cin, description);

	do
	{
		cout << "Enter weight: ";
		cin >> weight;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while(weight <= 0.0);

	do
	{
		cout << "Enter price: ";
		cin >> basePrice;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while(basePrice <= 0.0);
}

/*****************************************************************
 * Function: getSalesTax
 * Purpose: preforms basic calculation to determine the sales Tax
 * **************************************************************/
double Product::getSalesTax()
{
	float salesTax = (basePrice / 100.00) * 6.00;

	cout << "  Sales tax:" << setw(6) 
		  << "$" << setw(8) 
		  << salesTax << endl;

	return salesTax;
}

/*****************************************************************
 * Function: getShippingCost
 * Purpose: Calculated
 * **************************************************************/
double Product::getShippingCost()
{
	float shippingCost = 0;

	if (weight <= 5.00)
	{
		shippingCost = 2.00;
	}
	else
	{
		shippingCost = 2.00 + ((weight - 5.00) * 0.10); 
	}

	cout << "  Shipping cost: $" << setw(8) 
		  << shippingCost << endl;
	return shippingCost;
	
}

/*****************************************************************
 * Function: getTotalPrice
 * Purpose: adds together the basePrice, salesTax, and shippingCost,
 * 			and displays it accordingly.
 * **************************************************************/
void Product::getTotalPrice()
{
	float salesTax = getSalesTax();
	float shippingCost = getShippingCost();

	float totalPrice = basePrice + salesTax + shippingCost;

	cout << "  Total:" << setw(10) 
		  << "$" << setw(8) 
		  << totalPrice << endl;
}


/*****************************************************************
 * Function: adProfile
 * Purpose: Gets the right precision and displays the
 * 			advertising profile
 * **************************************************************/
void Product::adProfile()
{
	cout.setf(ios::fixed); 
	cout.setf(ios::showpoint); 
	cout.precision(2);
	cout << name << " - $" << basePrice << endl 
		  << "(" << description << ")" << endl;
}

/*****************************************************************
 * Function: invLineItem
 * Purpose: Displays the item how it would appear on the inventory
 * **************************************************************/
void Product::invLineItem()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout << "$" << std::setprecision(2) << basePrice 
		  << " - " << name 
		  << " - " << std::setprecision(1) 
		  << weight
		  << " lbs" << endl;
}

/*****************************************************************
 * Function: receipt
 * Purpose: Organizes and displays the Price, tax, shipping, and total
 * **************************************************************/
void Product::receipt()
{
	cout.setf(ios::fixed); 
	cout.setf(ios::showpoint); 
	cout.precision(2);
	cout << name << endl
		  << "  Price:" << setw(10) << "$" 
		  << setw(8) << basePrice << endl;

	getTotalPrice();
}