/***********************************************************************
* Component:
*    Page Replacement LRU
* Author:
*    <your name>
* Summary: 
*    This is the DERRIVED class to implement LRU
************************************************************************/

#ifndef PR_LRU
#define PR_LRU

#include "pr.h" // for the PageReplacementAlgorithm base-class
#include <vector>
#include <iostream>
using namespace std;

/****************************************************
 * SRL
 * The least-recently-used page replacement algorithm
 ***************************************************/
class PageReplacementLRU : public PageReplacementAlgorithm
{
public:
   /*****************************************************
    * CONSTRUCTOR
    * initialize the data structures specific to LRU
    *****************************************************/
   PageReplacementLRU(int numSlots) : PageReplacementAlgorithm(numSlots)
   {
      int LRUTracker = 0;
      int frameTracker = 0;
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
      // is pageNumber currently being used?
      for (int i = 0; i < getNumSlots(); i++)
         if (pageFrame[i] == pageNumber)
         {
            // If it is then we don't need to add another pageNumber,
            // and we don't have a page fault
            PageReplacementAlgorithm::record(pageNumber, false /*no fault*/);
            return;
         }

      pageFrame[frameTracker] = pageNumber;
      if (frameTracker == (getNumSlots() - 1))
         frameTracker = 0;
      else
         frameTracker++;

      LRU[LRUTracker] = pageNumber;
      if (LRUTracker == (getNumSlots() - 1))
         LRUTracker = 0;
      else
         LRUTracker++;

      // If we had to change the frame in any way then it was
      // a page fault.
      PageReplacementAlgorithm::record(pageNumber, true /*page fault*/);
      return;
   }

private:
   vector<int> LRU;
   int LRUTracker;
   int frameTracker;
};

#endif // PR_LRU
