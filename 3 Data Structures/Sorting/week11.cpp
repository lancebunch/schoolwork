/***********************************************************************
* Program:
*    Week 11, Sorting
*    Brother Ercanbrack, CS 235
* Author:
*    xxx
* Summary: 
*
************************************************************************/

#include <iostream> // for CIN and COUT
#include <cstring>  // for strcmp
#include <iomanip>  // for SETW
#include <fstream>
#include <vector>
#include "heap.h"
#include "merge.h"

using namespace std;

/**********************************************************************
 * MAIN
 * Gets the sort type and filename from the command line. If the sort type
 * or filename are not entered on the command line, the user will be
 * prompted for the sort type and/or filename.
 * Call the appropriate sort to sort the data contained in the vector or
 * linked list and display the sorted data to the console.
 ***********************************************************************/
int main(int argc, const char *argv[])
{
   int nums;
   vector<int> numVector;
   list<int> numList;
   char sortType[10];
   char fileName[50];
   if (argc == 1)
   {
      cout << "Which sort merge or heap? ";
      cin >> sortType;
      cout << "Enter name of file to sort: ";
      cin >> fileName;
   }
   else if (argc == 2)
   {
      strcpy(sortType, argv[1]);
      cout << "Enter name of file to sort: ";
      cin >> fileName;
   }
   else if (argc == 3)
   {
      strcpy(sortType, argv[1]);
      strcpy(fileName, argv[2]);
   }

   if (strcmp(sortType, "heap") == 0)
   {
      // TO DO: read the file into a vector
      //        call your heapsort passing the vector as a parameter
      //        output the sorted vector to the console.
      ifstream fin(fileName);

      // error handling if the file fails to be read
      if (fin.fail())
      {
         cout << "ERROR: cannot read file...terminating program...\n";
         fin.ignore();
         fin.clear();
         return 0;
      }

      // pushing a 0 on the front of the vector for ease of heap sort
      numVector.push_back(0);

      // reading the file into the vector one number at a time
      while (fin >> nums)
      {
         numVector.push_back(nums);
      }

      // close the file
      fin.close();

      // call the heapSort function
      heapSort(numVector);

      // display the vector in order with a width of three
      // and a new line after every 10th number
      for (int i = 1; i < numVector.size(); i++)
      {
         cout << setw(3) << numVector[i];
         if (i % 10 == 0)
            cout << endl;
      }
   }
   else if (strcmp(sortType, "merge") == 0)
   {
      // TO DO: read the file into a linked list
      //        call your natural merge sort
      //        output the sorted linked list to the console.
      ifstream fin(fileName);

      // error handling if the file fails
      if (fin.fail())
      {
         cout << "ERROR: cannot read file...terminating program...\n";
         fin.ignore();
         fin.clear();
         return 0;
      }

      // storing the file of numbers into a list
      while (fin >> nums)
      {
         numList.push_back(nums);
      }

      // close the file
      fin.close();

      // call the mergeSort function
      mergeSort(numList);

      int i = 1;
      typename list<int>::iterator it = numList.begin();
      for (it; it != numList.end(); it++)
      {
         cout << setw(3) << *it;
         if (i % 10 == 0)
            cout << endl;
         i++;
      }
   }
   else
   {
      cout << "\nInvalid sort name - must be 'heap' or 'merge'" << endl;
   }

   return 0;
}
