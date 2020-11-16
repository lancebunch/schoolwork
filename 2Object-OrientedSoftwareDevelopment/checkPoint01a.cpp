/***********************************************************************
* Program:
*    Checkpoint 01a, C++ Basics          (e.g. Checkpoint 01a, review)  
*    Brother Macbeth, CS165
* Author:
*    Lance Bunch
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   string firstName;
   int age;

   cout << "Hello CS 165 World!" << endl;
   cout << "Please enter your first name: ";
   cin >> firstName;
   cout << "Please enter your age: ";
   cin >> age;
   cout << endl;
   cout << "Hello " << firstName << ", you are " 
        << age << " years old." << endl;
   return 0;
}
