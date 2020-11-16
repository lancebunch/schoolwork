/***************************************************************
 * File: rational.cpp
 * Author: (your name here)
 * Purpose: Contains the method implementations for the Rational class.
 ***************************************************************/
#include <iostream>
using namespace std;

#include "rational.h"

void Rational::prompt()
{
    cout << "Top: ";
    cin >> numerator;
    cout << "Bottom: ";
    cin >> den;
}

void Rational::display() const
{
    cout << numerator << "/" << den << endl;
}

void Rational::displayDecimal() const
{
    float decimal = 0;
    decimal = (float)numerator/den;
    cout << decimal << endl;
}
