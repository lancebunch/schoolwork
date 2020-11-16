/***********************************************************************
* Program:
*    Checkpoint 02a, Structs    
*    Brother Macbeth, CS165
* Author:
*    Lance Bunch
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

struct Student
{
   string firstName;
   string lastName;
   int idNum;
};

/**********************************************************************
 * Function: getInfo
 * Purpose: To retreive user's info and store it in the corresponding 
 *           part of the struct
 * *******************************************************************/
void getInfo(Student &USER)
{
   cout << "Please enter your first name: ";
   cin >> USER.firstName;
   cout << "Please enter your last name: ";
   cin >> USER.lastName;
   cout << "Please enter your id number: ";
   cin >> USER.idNum;
   cout << endl;
}

/**********************************************************************
 * 
 * 
 * *******************************************************************/
void displayInfo(const Student &USER)
{
   cout << "Your information:" << endl;
   cout << USER.idNum << " - " << USER.firstName << " " << USER.lastName
        << "\n";
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   Student USER;

   getInfo(USER);

   displayInfo(USER);

   return 0;
}
