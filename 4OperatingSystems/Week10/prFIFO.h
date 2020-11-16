/***********************************************************************
* Component:
*    Page Replacement FIFO
* Author:
*    Lance Bunch
* Summary: 
*    This is the DERRIVED class to implement the FIFO algorithm
************************************************************************/

#ifndef PR_FIFO
#define PR_FIFO

#include "pr.h" // for the PageReplacementAlgorithm base-class
#include <iostream>
using namespace std;

/****************************************************
 * FIFO
 * The first-in, first-out page replacement algorithm
 ***************************************************/
class PageReplacementFIFO : public PageReplacementAlgorithm
{
public:
   /*****************************************************
    * CONSTRUCTOR
    * initialize the data structures specific to FIFO
    *****************************************************/
   PageReplacementFIFO(int numSlots) : PageReplacementAlgorithm(numSlots)
   {
      tracker = 0;
   }

   /****************************************************
    * RUN
    * Implement the FIFO algorithm here. Thus function will get
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

      // Since we didn't find the pageNumber in our frame, we
      // are just going to go ahead and insert into our frame
      // at the location designated by our tracker
      pageFrame[tracker] = pageNumber;
      if (tracker == (getNumSlots() - 1))
         tracker = 0;
      else
         tracker++;

      // If we had to change the frame in any way then it was
      // a page fault.
      PageReplacementAlgorithm::record(pageNumber, true /*page fault*/);
      return;
   }

private:
   // This is used to keep track of which pageNumber
   // has been in the vector the longest
   int tracker;
};

#endif // PR_BASIC
