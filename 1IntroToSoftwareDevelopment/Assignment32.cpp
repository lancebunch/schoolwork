/***********************************************************************
* Program:
*    Assignment 32, Strings
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
char countLetters(char text[], char letter)
{
   int count = 0;
   for (int i = 0; text[i]; i++)
   {
      if (text[i] == letter)
         count++;
   }
   cout << "Number of '" << letter << "'s: " << count << endl;
}


int main()
{
   char text[256];
   char letter;
   cout << "Enter a letter: ";
   cin >> letter;
   cin.ignore();
   cout << "Enter text: ";
   cin.getline(text, 256);
   countLetters(text, letter);
}
