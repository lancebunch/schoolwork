/***********************************************************************
* Program:
*    Week 11, Sorting
*    Brother Ercanbrack, CS 235
*
* Author:
*   Lance Bunch   
* Summary: 
*
************************************************************************/
#include <list>

using namespace std;

/*************************************************************************
* This function sorts a linked list using a Natural Merge Sort.
* Input:  data -  linked list of data to be sorted.
* Output: data -  sorted linked list
**************************************************************************/
template <class T>
void mergeSort(list<T> &data)
{
   // creating two lists for splitting purposes
   list<T> l1;
   list<T> l2;

   // boolean for swapping purposes later
   bool b = true;

   // iterators to goe through data's data
   typename list<T>::iterator it1 = data.begin();
   typename list<T>::iterator it2 = data.begin();

   // setting the second iterator ahead of the first
   it2++;

   // loop through with the data's frist iterator
   while (it1 != data.end())
   {
      // while on and odd sublist
      if (b)
      {
         // if we have found the end of a sublist
         if (*it1 > *it2)
         {
            // put that in the first split list
            l1.push_back(*it1);
            // switch which list is going to have data pushed onto it
            b = false;
         }
         else
         {
            // if you haven't found the end of the sublist put the numebr on
            l1.push_back(*it1);
         }
      }
      // while on an even sublist
      else
      {
         // once again, if we have found the end of a sublist
         if (*it1 > *it2)
         {
            // push the last piece of data on and switch to a different list
            l2.push_back(*it1);
            b = true;
         }
         // otherwise just put the data in the second list
         else
         {
            l2.push_back(*it1);
         }
      }
      // incrementing the iterators for further comparisons
      it1++;
      it2++;
   }

   // subiterators for the split lists
   typename list<T>::iterator fit1 = l1.begin();
   typename list<T>::iterator fit2 = l1.begin();
   typename list<T>::iterator sit1 = l2.begin();
   typename list<T>::iterator sit2 = l2.begin();

   // get rid of what is in data
   data.clear();

   // if there isn't anything left in the second list...
   if (l2.empty())
   {
      // then just go ahead and throw the rest of the first list on data
      while (fit1 != l1.end())
      {
         data.push_back(*fit1);
         fit1++;
      }
      // cleaning up data and done with the sorting
      l1.clear();
      return;
   }

   // while we are not at the end of either list...
   while (fit1 != l1.end() && sit1 != l2.end())
   {
      // if data at l1's iteration is less than the data at l2's iteration
      if (*fit1 <= *sit1)
      {
         // put that into the main list and increment iterations
         data.push_back(*fit1);
         fit1++;
         fit2++;
      }
      // otherwise put l2's data into the main list's data
      else if (*sit1 <= *fit1)
      {
         data.push_back(*sit1);
         sit1++;
         sit2++;
      }
   }

   // comparing sublists of first list again
   if (*fit1 < *fit2)
   {
      // if we aren't at the end of a sublist just put it in main list
      while (*sit1 < *sit2)
      {
         data.push_back(*sit1);
         sit1++;
         sit2++;
      }
   }
   // comparing sublists of second list again
   else if (*sit1 < *sit2)
   {
      // if we aren't at the end of a sublist just put it in main list
      while (*fit1 < *fit2)
      {
         data.push_back(*fit1);
         fit1++;
         fit2++;
      }
   }

   // if we are at the end of l1's list...
   if (fit1 == l1.end() && sit1 != l2.end())
   {
      // put the rest of l2's data in main list
      while (sit1 != l2.end())
      {
         data.push_back(*sit1);
         sit1++;
      }
   }
   // otherwise if we are at the end of l2's list
   else if (sit1 == l2.end() && fit1 != l1.end())
   {
      // put the rest of l1's data in main list
      while (fit1 != l1.end())
      {
         data.push_back(*fit1);
         fit1++;
      }
   }

   // clear everything and start over with recursion
   l1.clear();
   l2.clear();
   mergeSort(data);
}
