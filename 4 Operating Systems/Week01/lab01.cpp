/***********************************************************************
* Program:
*    Lab 01, Submission Lab
*    Brother Ball, CS345
* Author:
*    Lance Bunch
* Summary: 
*    This is a quick lab to make sure I know how to submit code on the linux
*    server. What is does is takes input and counts the number of times input
*    is received.
************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

/**********************************************************************
 * Quick and easy program to accept input and keep track of how many time
 * that input was given
 ***********************************************************************/
int main()
{
   // declaring variables to let them enter integers and keep track of numbers
   int numEntries = 0;
   // double long to let them have more variety in what number they enter
   double long number = 1;

   // since number is declared as '1' we will always enter the loop until
   // the user enters 0.
   while (number)
   {
      cout << "Enter an integer: ";
      cin >> number;
      // Program aborts if they enter anything other than an integer
      assert(!(isdigit(number)));
      numEntries++;
   }

   // Since we will always go through the loop at least once, numEntries
   // will always increment at least once. In the case this is done at
   // the beginning then we make sure to let the user know.
   if (numEntries == 1)
   {
      cout << "No non-zero integers were entered.\n";
   }
   else
   {
      // Simple logic to inform them on the number of entries
      // Handles grammar in case they only enter one number
      cout << "You entered " << numEntries - 1 << " integer";
      (numEntries == 2) ? cout << "" : cout << "s";
      cout << "." << endl;
   }

   return 0;
}
