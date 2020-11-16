/***************************************************************
 * File: ta04.cpp
 * Author: Lance Bunch
 * Purpose: Contains the main function to test the Rational class.
 ***************************************************************/

#include <iostream>
#include <string>
using namespace std;

#include "rational.h"

int main()
{
   // Declare your Rational object here
   Rational number;
   // Call your prompt function here
   number.prompt();
   // Call your display functions here
   number.display();
   number.displayDecimal();


   return 0;
}
