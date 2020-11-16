/***********************************************************************
* Component:
*    Page Replacement Second Chance
* Author:
*     Jacob Smith
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
      refernceBits = new bool[getNumSlots()];
      refernceBits = { 0 };
      nextVictim = 0;
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
            refernceBits[i] = 1;
            PageReplacementAlgorithm::record(pageNumber, false /*no fault*/);
            return;
         }
 
      while(refernceBits[nextVictim % getNumSlots()])
      {
         refernceBits[nextVictim++ % getNumSlots()] = 0;
      }

      pageFrame[nextVictim++ % getNumSlots()] = pageNumber;

      // for a page fault
      PageReplacementAlgorithm::record(pageNumber, true /*page fault*/);
      return;
   }

private:
   //////////////////// YOUR CODE HERE //////////////////////
   bool * refernceBits;
   int nextVictim;
};

#endif // PR_SECOND
