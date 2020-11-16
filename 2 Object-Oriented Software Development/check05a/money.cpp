/***********************
 * File: money.cpp
 ***********************/

#include <iostream>
#include <iomanip>
using namespace std;

#include "money.h"

/*****************************************************************
 * Function: setDollars
 * Purpose: Sets Dollars and makes positive if enterd negitive
 * **************************************************************/
void Money :: setDollars(int dollars)
{
   this->dollars = dollars;
   if (dollars < 0)
   {
      this->dollars = dollars * -1;
   }
}

/*****************************************************************
 * Function: setCents
 * Purpose: Sets the cents and makes it positive if entered negitive
 * **************************************************************/
void Money :: setCents(int cents)
{
   this->cents = cents;
   if (cents < 0)
   {
      this->cents = cents * -1;
   }
}


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
   cout << "$" << getDollars() << ".";
   cout << setfill('0') << setw(2) << getCents();
}
