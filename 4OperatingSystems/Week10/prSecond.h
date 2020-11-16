/***********************************************************************
* Component:
*    Page Replacement Second Chance
* Author:
*    <your name>
* Summary: 
*    This is the DERRIVED class to implement Second
************************************************************************/

#ifndef PR_SECOND
#define PR_SECOND

#include "pr.h"   // for the PageReplacementAlgorithm base-class

#include <iostream>
using namespace std;

/****************************************************
 * Second Chance
 * The least-recently-used Approximation page replacement
 * algorithm known as Second Chance
 ***************************************************/
class PageReplacementSecond : public PageReplacementAlgorithm
{
public:
   /*****************************************************
    * CONSTRUCTOR
    * initialize the data structures specific to Second
    *****************************************************/
   PageReplacementSecond(int numSlots) : PageReplacementAlgorithm(numSlots)
   {
      //////////////////// YOUR CODE HERE //////////////////////
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

      // to place "pageNumber" in page 0
      pageFrame[0] = pageNumber;

      // for no page fault
      // PageReplacementAlgorithm::record(pageNumber, false /*no fault*/);

      // for a page fault
      PageReplacementAlgorithm::record(pageNumber, true /*page fault*/);
      return;
   }

private:
   //////////////////// YOUR CODE HERE //////////////////////
};

#endif // PR_SECOND
