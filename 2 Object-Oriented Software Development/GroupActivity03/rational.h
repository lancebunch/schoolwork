/***************************************************************
 * File: rational.h
 * Author: (your name here)
 * Purpose: Contains the definition of the Rational class
 ***************************************************************/
#ifndef RATIONAL_H
#define RATIONAL_H

// put your class definition here
class Rational
{
   private:
		int numerator;
		int den;
	public:
		void prompt();
		void display() const;
		void displayDecimal() const;
};
#endif
