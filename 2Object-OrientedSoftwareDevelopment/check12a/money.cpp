/***********************
 * File: money.cpp
 ***********************/

#include <iostream>
#include <iomanip>
using namespace std;

#include "money.h"

/*****************************************************************
 * Function: prompt
 * Purpose: Asks the user for values for dollars and cents
 *   and stores them.
 ****************************************************************/
void Money :: prompt()
{
   int dollars;
   int cents;

   cout << "Dollars: ";
   cin >> dollars;

   cout << "Cents: ";
   cin >> cents;

   setDollars(dollars);
   setCents(cents);
}

/*****************************************************************
 * Function: display
 * Purpose: Displays the value of the money object.
 ****************************************************************/
void Money :: display() const 
{
   cout << "$" << dollars << ".";
   cout << setfill('0') << setw(2) << cents;
}

bool operator==(const Money &lhs, const Money &rhs)
{
   return ((lhs.dollars == rhs.dollars) && (lhs.cents == rhs.cents));
}

bool operator!=(const Money &lhs, const Money &rhs)
{
   return !(lhs == rhs);
}

ostream& operator <<(ostream &lhs, const Money &rhs)
{
   float money = rhs.dollars + (rhs.cents / 100.00);
   lhs << "$" << money;
   return lhs;
}