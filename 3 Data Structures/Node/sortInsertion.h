/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Lance Bunch
 ************************************************************************/

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "node.h"

/***********************************************
 * INSERTION SORT
 * Sort the items in the array
 **********************************************/
template <class T>
void sortInsertion(T array[], int num)
{
   Node <T> * last = new Node <T> (array[0]);
   Node <T> * pStart = last;

   for (int i = 1; i < num; i++)
   {
      if (array[i] < pStart->data)
      {
         insert(array[i], pStart, true);
      }
      else
      {
         Node <T> * trav = pStart;
         while (trav->pNext != NULL)
         {
            if(trav->pNext->data > array[i])
            {
               insert(array[i], trav);
               break;
            }
            trav = trav->pNext;
         }
         if (trav->pNext == NULL)
         {
            insert(array[i], trav);
         }
      }   
   }
   cerr << pStart << endl;

   last = pStart;
   for (int j = 0; j < num; j++)
   {
      array[j] = last->data;
      last = last->pNext;
   }
   freeData(pStart);
}

#endif // INSERTION_SORT_H

