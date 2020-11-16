/********************************************************************
 * File: date.cpp
 * Purpose: Holds the implementation of the Date class methods.
 ********************************************************************/
#include <iostream>
using namespace std;
#include "date.h"

// Put your method bodies here...
void Date::set()
{
   cout << "Month: ";
	cin >> month;

	cout << "Day: ";
	cin >> day;

	cout << "Year: ";
	cin >> year;
}

void Date::displayAmerican() const
{
   cout << month << "/" << day << "/" << year << endl;
}

void Date::displayEuropean() const
{
   cout << day << "/" << month << "/" << year << endl;
}

void Date::displayISO() const
{
   cout << year << "-" << month << "-" << day << endl;
}
