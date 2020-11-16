/***********************************************************************
* Program:
*    Assignment 14, Matthew 18:21-22
*    Sister Hansen, CS124
* Author:
*    Lance Bunch
* Summary: 
*    This program will address Peter's question to the Lord in 
*    Matthew 18:21-22
*
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
*     I am still struggling figuring out the purposes of each funtion, so it was difficult trying to figure out which funtions to use.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* You are not allowed to change MAIN in any way; just implement the two
* functions: questionPeter() and responseLord()
***********************************************************************/
void questionPeter()
{
   cout << "Lord, how oft shall my brother sin against me,";
   cout << " and I forgive him?\n" << "Till seven times?" << endl;
}

int responseLord()
{
   int num = 7 * 70;
   return num;
}
int main()
{
   // ask Peter's question
   questionPeter();

   // the first part of the Lord's response
   cout << "Jesus saith unto him, I say not unto thee, Until seven\n";
   cout << "times: but, Until " << responseLord() << ".\n";

   return 0;
}
