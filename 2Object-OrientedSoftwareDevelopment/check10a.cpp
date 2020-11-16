/***********************************************************************
* Program:
*    Checkpoint 10a, Vectors
*    Brother Macbeth, CS165
* Author:
*    Lance Bunch
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;



/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   int number = 1;
   vector<int> intVector;

   do 
   {
      cout << "Enter int: ";
      cin >> number;
      if(number != 0)
      {
         intVector.push_back(number);
      }
   }
   while (number != 0);

   cout << "Your list is:" << endl;

   for (int i = 0 ; i < intVector.size(); i++)
   {
      cout << intVector[i] << endl;
   }

   cout << endl;

   string word;
   vector<string> strVector;
   
   do
   {
      cout << "Enter string: ";
      cin >> word;
      if (word != "quit")
      {
         strVector.push_back(word);
      }
   }
   while (word != "quit");

   cout << "Your list is:" << endl;

   for (int i = 0; i < strVector.size(); i++)
   {
      cout << strVector[i] << endl;
   }
   
   return 0;
}


