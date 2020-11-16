/***********************************************************************
 * Implementation:
 *    FIBONACCI
 * Summary:
 *    This will contain the implementation for fibonacci() as well as any
 *    other function or class implementations you may need
 * Author
 *    Lance Bunch
 **********************************************************************/

#include <iostream>
#include <iomanip>
#include "fibonacci.h"   // for fibonacci() prototype
#include "list.h"        // for LIST
using namespace std;

/************************************************
 * FIBONACCI
 * The interactive function allowing the user to
 * display Fibonacci numbers
 ***********************************************/
void fibonacci()
{

// The first and second parts of this can probably be implemented similarily

   // show the first serveral Fibonacci numbers
   int number;
   cout << "How many Fibonacci numbers would you like to see? ";
   cin  >> number;
   // Code to display a sequence of fibonacci numbers goes here.
   // loop until "number", calling your fibonacci number display function for each fibonacci # from 1 to "number".

   WholeNumber n1(1);
   WholeNumber n2(0);
   WholeNumber n3(1);

   for (int i = 1; i <= number; i++)
   {
      cout << "\t" << n1 << endl;
      n1 += n2;
      n2 = n3;
      n3 = n1;  
   }

   // prompt for a single large Fibonacci
   cout << "Which Fibonacci number would you like to display? ";
   cin  >> number;
   // your code to display the <number>th Fibonacci number

   WholeNumber b1(1);
   WholeNumber b2(0);
   WholeNumber b3(1);
   for (int i = 2; i <= number; i++)
   {
      b1 += b2;
      b2 = b3;
      b3 = b1;  
   }
   cout << "\t" << b1 << endl;
}

/************************************************
 * FIBADD
 * Handles adding two fibonacci numbers
 ***********************************************/
WholeNumber & WholeNumber :: fibAdd(unsigned int i, ListIterator <unsigned int> it)
{
   if (it == bigNum.rend())
   {
      bigNum.push_front(0);
      it = bigNum.begin();
   }

   unsigned int sum = (i + *it);

   unsigned int carry = sum/1000;

   sum %= 1000;
   *it = sum;

   if (carry)
   {
      fibAdd(carry, --it);
   }
   else
   {
      return *this;
   }
}

/************************************************
 * OPERATOR :: +=
 * Specifies the += operator for a Fibonacci approach
 ***********************************************/
WholeNumber & WholeNumber :: operator +=(WholeNumber & rhs)
{
   ListIterator <unsigned int> it1 = bigNum.rbegin();
   ListIterator <unsigned int> it2 = rhs.bigNum.rbegin();
   for (it1; it2 != rhs.bigNum.rend(); it1--, it2--)
   {
      fibAdd(*it2, it1);
   }
   return *this;
}

/************************************************
 * OPERATOR :: =
 * Makes sure assignment operator is specific to Fibonacci logic
 ***********************************************/
WholeNumber & WholeNumber :: operator =(WholeNumber & rhs)
{
   bigNum.clear();
   this->bigNum = rhs.bigNum;
   return *this;
}


/************************************************
 * OPERATOR :: <<
 * displays the fibonacci number
 ***********************************************/
ostream & operator << (ostream & out, WholeNumber rhs)
{
   ListIterator <unsigned int> it = rhs.bigNum.begin();
   for (it; it != rhs.bigNum.end(); it++)
   {
      if (it != rhs.bigNum.begin())
      {
         out << ',';
         out << setfill('0') << setw(3) << *it;
      }
      else
      {
         out << *it;
      }
   }
   return out;   
}
