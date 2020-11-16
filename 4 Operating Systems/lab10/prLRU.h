/***********************************************************************
* Component:
*    Page Replacement LRU
* Author:
*     Jacob Smith
* Summary: 
*    This is the DERRIVED class to implement LRU
************************************************************************/

#ifndef PR_LRU
#define PR_LRU

#include "pr.h"   // for the PageReplacementAlgorithm base-class

#include <iostream>
using namespace std;

/****************************************************
 * SRL
 * The least-recently-used page replacement algorithm
 ***************************************************/
class PageReplacementLRU: public PageReplacementAlgorithm
{
public:
   /*****************************************************
    * CONSTRUCTOR
    * initialize the data structures specific to LRU
    *****************************************************/
   PageReplacementLRU(int numSlots) : PageReplacementAlgorithm(numSlots)
   {
      //////////////// YOUR CODE HERE ////////////////////      
      useTracker = new int[getNumSlots()];
      for (int i = getNumSlots(); i < 0; i--)
         useTracker[i - 1] = i * -1;
      counter = 0;
   }

   /****************************************************
    * RUN
    * Implement the LRU algorithm here. Thus function will get
    * called several times, each time requesting "pageNumber"
    * from memory. You are to assign that page to a "pageFrame"
    * and then call the base-class to record the results.
    ***************************************************/
   void run(int pageNumber)
   {
      /////////////// YOUR CODE HERE ////////////////////
      // is pageNumber currently being used?
      for (int i = 0; i < getNumSlots(); i++)
         if (pageFrame[i] == pageNumber)
         {
            useTracker[i] = counter++;
            PageReplacementAlgorithm::record(pageNumber, false /*no fault*/);
            return;
         }
      
      int leastRecentlyUsed = 0;
      for (int i = 1; i < getNumSlots(); i++)
         if (useTracker[i] < useTracker[leastRecentlyUsed])
            leastRecentlyUsed = i;

      pageFrame[leastRecentlyUsed] = pageNumber;

      // for a page fault
      PageReplacementAlgorithm::record(pageNumber, true /*page fault*/);
      return;      
   }

private:
   //////////////////// YOUR CODE HERE //////////////////////
   int * useTracker;
   int counter;
};

#endif // PR_LRU
