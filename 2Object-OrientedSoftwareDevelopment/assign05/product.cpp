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
 * Default Constructor
 * Purpose: Sets name, description, basePrice, and weight to default settings
 * **************************************************************/
Product :: Product()
{
	setName("none");
	setDescription("");
	setBasePrice(0);
	setWeight(0);
}

/*****************************************************************
 * Non-Default Constructor
 * Purpose: Takes in input for name, description, basePrice, and weight
 * **************************************************************/
Product :: Product(string name, string description, double basePrice, float weight)
{
	setName(name);
	setDescription(description);
	setBasePrice(basePrice);
	setWeight(weight);
}

/*****************************************************************
 * Mutator: setName
 * Purpose: sets the name to whatever is inputed
 * **************************************************************/
void Product :: setName(string name)
{
	this->name = name;
}

/*****************************************************************
 * Mutator: setDescription
 * Purpose: sets description to whatever is inputed
 * **************************************************************/
void Product :: setDescription(string description)
{
	this->description = description;
}

/*****************************************************************
 * Mutator: setBasePrice
 * Purpose: sets the BasePrice to whatever is inputed
 * **************************************************************/
void Product :: setBasePrice(double basePrice)
{
	this->basePrice = basePrice;
}

/*****************************************************************
 * Mutator: setWeight
 * Purpose: sets the weight to whatever is inputed
 * **************************************************************/
void Product :: setWeight(float weight)
{
	this->weight = weight;
}

/*****************************************************************
 * Function: getSalesTax
 * Purpose: preforms basic calculation to determine the sales Tax
 * **************************************************************/
double Product::getSalesTax()
{
	float salesTax = (basePrice / 100.00) * 6.00;

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

	return shippingCost;
	
}

/*****************************************************************
 * Function: getTotalPrice
 * Purpose: adds together the basePrice, salesTax, and shippingCost,
 * 			and displays it accordingly.
 * **************************************************************/
double Product::getTotalPrice()
{
	float salesTax = getSalesTax();
	float shippingCost = getShippingCost();

	float totalPrice = basePrice + salesTax + shippingCost;

	return totalPrice;
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

	cout << "  Sales tax:" << setw(6) 
		  << "$" << setw(8) 
		  << getSalesTax() << endl;

	cout << "  Shipping cost: $" << setw(8) 
		  << getShippingCost() << endl;

	cout << "  Total:" << setw(10) 
		  << "$" << setw(8) 
		  << getTotalPrice() << endl;

	getTotalPrice();
}