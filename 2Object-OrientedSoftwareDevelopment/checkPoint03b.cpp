/***********************************************************************
* Program:
*    Checkpoint 03b, Exceptions    
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
void promptNumber(int &number, bool &valid)
{

   cout << "Enter a number: ";
   cin >> number;
   if (cin.fail())
   {
      cin.clear();
      cin.ignore(100, '\n');
      valid = true;
      throw string("Invalid input.");
   }

}


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   int number = 0;
   bool valid;

   do
   {
       try
   {
      promptNumber(number, valid);
      cout << "The number is " << number << "." << endl;
      valid = false;
   }
   catch(const string &error)
   {
      cout << error << endl;
   }
   } while (valid);
   
  


   return 0;
}
