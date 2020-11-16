// File: customer.cpp

#include "customer.h"
#include <string>
#include <iostream>
using namespace std;

// Put the method bodies for your customer class here
/*****************************************************************
 * Default Constructor
 * Purpose: Sets the name to unspecified and uses the 
 * 			address's default constructor
 * **************************************************************/
Customer :: Customer()
{
	setName("unspecified");
}

/*****************************************************************
 * Non Default Constructor
 * Purpose: sets the Product, quantity, and Customer
 * **************************************************************/
Customer :: Customer(string name, Address address)
{
	setName(name);
	setAddress(address);
}

/*****************************************************************
 * Mutator: setName
 * Purpose: sets the name to information given
 * **************************************************************/
void Customer :: setName(string name)
{
	this->name = name;
}

/*****************************************************************
 * Mutator: setAddress
 * Purpose: sets the Address to information given
 * **************************************************************/
void Customer :: setAddress(Address address)
{
	this->address = address;
}

/*****************************************************************
 * Function: display
 * Purpose: displays the name, then calls the address's dipslay method
 * **************************************************************/
void Customer :: display()
{
	cout << name << endl;
	address.display();
}
