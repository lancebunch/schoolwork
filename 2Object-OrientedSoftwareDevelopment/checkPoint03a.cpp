/***********************************************************************
* Program:
*    Checkpoint 03a, Exceptions    
*    Brother Macbeth, CS165
* Author:
*    Lance Bunch
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


/**********************************************************************
 * Function: promptNumber
 * Purpose: Receives the users number and throws a string in the case
 *          it doesn't work as planned.
 * *******************************************************************/
void promptNumber(int &number)
{
   cout << "Enter a number: ";
   cin >> number;
   if (number < 0)
   {
      throw string("The number cannot be negative.");
   }
   else if (number > 100)
   {
      throw string("The number cannot be greater than 100.");
   }
   else if (number % 2 != 0)
   {
      throw string("The number cannot be odd.");
   }

}


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   int number = 0;

   try
   {
      promptNumber(number);
      cout << "The number is " << number << "." << endl;
   }
   catch(const string &error)
   {
      cout << "Error: " << error << endl;
   }


   return 0;
}
