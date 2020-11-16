/*********************************************************************
 * File: check04b.cpp
 * Purpose: contains the main method to exercise the Date class.
 *********************************************************************/

#include "date.h"

#include <iostream>
using namespace std;

int main()
{
   // create a Date object
   Date date;
   // set its values
   date.set();
   cout << endl;
   // call each display function
   date.displayAmerican();

   date.displayEuropean();

   date.displayISO();

   return 0;
}
