/***********************************************************************
* Program:
*    Assignment 33, Pointers
*    Sister Hansen, cs 124
* Author:
*    Lance Bunch
* Summary: 
*   
*    Estimated:  1.0 hrs   
*    Actual:     0.5 hrs
*   
************************************************************************/

#include <iostream>
#include <iomanip> //Allows me to use the setw() function
using namespace std;



/**********************************************************************
 * The main runs everything in the program since there isn't any other funtions.
 ***********************************************************************/
int main()
{
   float sam;
   float sue;
   float dinner;
   float movie;
   float iceCream;
   cout << "What is Sam's balance? ";
   cin >> sam;
   cout << "What is Sue's balance? ";
   cin >> sue;
   cout << "Cost of the date:\n";
   cout << "\tDinner:    ";
   cin >> dinner;
   cout << "\tMovie:     ";
   cin >> movie;
   cout << "\tIce cream: ";
   cin >> iceCream;

   float * higher;
   if (sam >= sue)
      higher = &sam;
   else
      higher = &sue;
   *higher -= dinner + movie + iceCream;

   cout << "Sam's balance: $" << sam << endl;
   cout << "Sue's balance: $" << sue << endl; 
}
