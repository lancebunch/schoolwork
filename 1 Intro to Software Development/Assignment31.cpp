/***********************************************************************
* Program:
*    Assignment 31, Array Design
*    Sister Hansen, cs 124
* Author:
*    Lance Bunch
* Summary: 
*   
*    Estimated:  1.0 hrs   
*    Actual:     0.0 hrs
*   
************************************************************************/

#include <iostream>
#include <iomanip> //Allows me to use the setw() function
using namespace std;



/**********************************************************************
 * The main runs everything in the program since there isn't any other funtions.
 ***********************************************************************/
void getGrades(int grades[], int num)
{
   for (int i = 0; i < num; i++)
   {
      cout << "Grade " << i + 1 << ": ";
      cin >> grades[i];
   }
}

void averageGrades(int grades[], int num)
{
   int avg = 0;
   int count = 0;
   for (int i = 0; i < num; i++)
   {
      if (grades[i] > 0)
      {
         avg += grades[i];
         count++;
      }
   }
   if(count == 0)
      cout << "Average Grade: ---%\n";
   else
      cout << "Average Grade: " << avg/count << "%\n";
}

int main()
{
   int grades[10];
   getGrades(grades, 10);

   averageGrades(grades, 10);
}
