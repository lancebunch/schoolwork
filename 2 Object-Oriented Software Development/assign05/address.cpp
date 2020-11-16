// File: address.cpp

#include "address.h"
#include <string>
#include <iostream>
using namespace std;

// Put your method bodies for the address class here
/*****************************************************************
 * Default Constructor
 * Purpose: Sets the street to unkown, zip to 00000, and other data members
 *          to nothing
 * **************************************************************/
Address :: Address()
{
	setStreet("unknown");
	setCity("");
	setState("");
	setZip("00000");
}

/*****************************************************************
 * Non-Default Constructor
 * Purpose: Sets the information to what is inputted
 * **************************************************************/
Address :: Address(string street, string city, string state, string zip)
{
	setStreet(street);
	setCity(city);
	setState(state);
	setZip(zip);
}

/*****************************************************************
 * Mutator: setStreet
 * Purpose: sets the street function
 * **************************************************************/
void Address :: setStreet(string street)
{
	this->street = street;
}

/*****************************************************************
 * Mutator: setCity
 * Purpose: sets the city function
 * **************************************************************/
void Address :: setCity(string city)
{
	this->city = city;
}

/*****************************************************************
 * Mutator: setState
 * Purpose: sets the state function
 * **************************************************************/
void Address :: setState(string state)
{
	this->state = state;
}

/*****************************************************************
 * Mutator: setZip
 * Purpose: sets the zip function
 * **************************************************************/
void Address :: setZip(string zip)
{
	this->zip = zip;
}

/*****************************************************************
 * Function: display
 * Purpose: displays the information in a nice formate
 * **************************************************************/
void Address :: display()
{
	cout << street << endl
		  << city << ", " 
		  << state << " "
		  << zip << endl;
}

