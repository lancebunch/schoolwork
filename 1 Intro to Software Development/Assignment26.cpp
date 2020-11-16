/***********************************************************************
* Program:
*    Assignment 26, Files
*    Sister Hansen, CS124
* Author:
*    Lance Bunch
* Summary:     
*       This is to use a basic file to compute a basic math situation
*   
*    Estimated:  1.0 hrs   
*    Actual:     0.5 hrs
*     The most difficult part was figuring out the correct wording for each statement. 
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

void getFileName(char fileName[])
{

   cout << "Please enter the filename: ";
   cin >> fileName;
   return;
}

float readFile(char fileName[])
{
   ifstream fin(fileName);
   if(fin.fail())          //.fail() is a preset function that runs its own tests
      return -1;

   int count = 0;
   float total = 0;
   float grade;

   while (fin >> grade)
   {
      total += grade;
      count++;
   }

   if(count != 10)
      return -1;
   else
      return total / count;
}

void display(float average, char fileName[])
{
   cout.setf(ios::fixed);
   
   cout.precision(0);
   
   if (average == -1)
      cout << "Error reading file \"" << fileName << "\"" << endl;
   else
      cout << "Average Grade: " << average << "%" << endl;
   return;
}
/**********************************************************************
 *The main function calls the computeTax function and executes each line of code individually, then returns the outcome of the computeTax function.
 ***********************************************************************/
int main()
{
   char fileName[256];
   getFileName(fileName);
   float average = readFile(fileName);
   display(average, fileName);
   return 0;
}
