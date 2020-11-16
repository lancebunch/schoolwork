/***********************************************************************
* Program:
*    Assignment 25, Loop Design
*    Sister Hansen, CS124
* Author:
*    Lance Bunch
* Summary:     
*  
*   
*    Estimated:  1.0 hrs   
*    Actual:     0.5 hrs
*   
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 *Main runs everythin gin the function.
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   int days;
   int offset;
   
   cout << "Number of days: ";
   cin >> days;
   cout << "Offset: ";
   cin >> offset;

   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   if (offset < 6)
   {
      int i = 0;
      cout << setw(4);
      for (i = 0; i <= offset; i++)
         cout << "  " << setw(4);
   }
   offset++;

   for (int i = 1; i <= days; i++)
   {
      cout << setw(4) << i;
      if ((i + offset) % 7 == 0 || i == days)
         cout << endl;
   }
   
   return 0;
}
   


