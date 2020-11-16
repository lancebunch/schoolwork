/***********************************************************************
* Program:
*    Checkpoint 01b, C++ Basics            
*    Brother Macbeth, CS165
* Author:
*    Lance Bunch
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

/***********************************************************************
* Funtion: getSize
* Purpose: prompt use for list size, return in to main. 
***********************************************************************/
int getSize()
{
   int sizeList;
   cout << "Enter the size of the list: ";
   cin >> sizeList;
   return sizeList;
}

/***********************************************************************
 * Function: getList
 * Purpose: Ask user for the numbers in each index of the list
 * *********************************************************************/
int getList(int sizeList[], const int size)
{
   for (int i = 0; i < size; i++)
   {
      cout << "Enter number for index " << i << ": ";

      cin >> sizeList[i];
   }
}

/**********************************************************************
 * Funtion: displayMultiples
 * Purpose: To Evaluate given numbers if they are divisible by 3
 * *******************************************************************/
void displayMultiples(int sizeList[], const int size)
{
   cout << "\n";
   cout << "The following are divisible by 3:\n";
   for(int i = 0; i < size; i++)
   {
      if(sizeList[i] % 3 == 0)
         cout << sizeList[i] << endl;
   }
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   int size = getSize();

   int sizeList[20];

   getList(sizeList, size);

   displayMultiples(sizeList, size);
   
   return 0;
}
