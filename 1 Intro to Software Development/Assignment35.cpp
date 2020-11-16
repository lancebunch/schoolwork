/***********************************************************************
* Program:
*    Assignment 35, Advanced Conditionals 
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


char computeLetterGrade(int numGrade)
{
   char letterGrade;
   
   switch (numGrade / 10)
   {
      case 10:
      case 9:
         letterGrade = 'A';
         break;
      case 8:
         letterGrade = 'B';
         break;
      case 7:
         letterGrade = 'C';
         break;
      case 6:
         letterGrade = 'D';
         break;
      default:
         letterGrade = 'F';
   }
   return letterGrade;
}


char computeGradeSign(int numGrade)
{
   char symbol;
   if (numGrade > 93)
      symbol = '*';
   else if (numGrade < 60)
      symbol = '*';
   else switch (numGrade % 10)
      {
         case 9:
         case 8:
         case 7:
            symbol = '+';
            break;
         case 6:
         case 5:
         case 4:
         case 3:
            symbol = '*';
            break;
         default:
            symbol = '-';
      }
   return symbol;
}


int main()
{
   int numGrade;
   cout << "Enter number grade: ";
   cin >> numGrade;

   char letterGrade = computeLetterGrade(numGrade);

   char plusMinus = computeGradeSign(numGrade);

   cout << numGrade << "% is " << letterGrade;
   if (plusMinus != '*')
      cout << plusMinus;
   cout << endl;
}
