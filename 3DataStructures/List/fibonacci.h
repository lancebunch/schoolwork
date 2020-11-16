/***********************************************************************
 * Header:
 *    FIBONACCI
 * Summary:
 *    This will contain just the prototype for fibonacci(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Lance Bunch
 ************************************************************************/
#include "list.h"
#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <iostream>

// the interactive fibonacci program
void fibonacci();

class WholeNumber
{
   public:
      List <unsigned int> bigNum;

      // default constructor
      WholeNumber() { bigNum.push_back(0); }

      // non-default passing in unsigned int
      WholeNumber(unsigned int data) { fibAdd(data, bigNum.rbegin()); }

      // non-default constructor
      // WholeNumber(List <unsigned int> data) { this->bigNum = data; }

      // Copy Constructor
      WholeNumber(WholeNumber & rhs)  { bigNum = rhs.bigNum; }

      // implements how to add two WholeNumber objects
      WholeNumber & fibAdd(unsigned int i, ListIterator <unsigned int> it);

      // += operator overload
      WholeNumber & operator +=(WholeNumber & rhs);

      // = operator overload
      WholeNumber & operator =(WholeNumber & rhs);

      friend std::ostream & operator <<(std::ostream & out, WholeNumber i);
};

#endif // FIBONACCI_H