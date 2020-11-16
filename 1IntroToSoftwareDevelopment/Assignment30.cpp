/***********************************************************************
* Program:
*    Assignment 30, Array Syntax
*    Sister Hansen, cs 124
* Author:
*    Lance Bunch
* Summary: 
*   
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
   for (int i = 0; i < num; i++)
      avg += grades[i];
   cout << "Average Grade: " << avg / 10 << "%" << endl;
}

int main()
{
   int grades[10];
   getGrades(grades, 10);

   averageGrades(grades, 10);
}
