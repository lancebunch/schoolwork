/***********************************************************************
* Component:
*    Page Replacement FIFO
* Author:
*    Shawn Phillips
* Summary: 
*    This is the DERRIVED class to implement the FIFO algorithm
************************************************************************/

#ifndef PR_FIFO
#define PR_FIFO

#include "pr.h"   // for the PageReplacementAlgorithm base-class

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
      //////////////// YOUR CODE HERE ////////////////////
      pageFrame.resize(numSlots, -1);
   }

   /****************************************************
    * RUN
    * Implement the Basic algorithm here. Thus function will get
    * called several times, each time requesting "pageNumber"
    * from memory. You are to assign that page to a "pageFrame"
    * and then call the base-class to record the results.
    ***************************************************/
   void run(int pageNumber)
   {
      /////////////// YOUR CODE HERE ////////////////////
      // is pageNumber currently being used?
      for (int i = 0; i < getNumSlots(); i++)
      {
         if (pageFrame[i] == pageNumber)
         {
            PageReplacementAlgorithm::record(pageNumber, false /*no fault*/);
            return;
         }
      }

      // to place "pageNumber" in page 0
      pageFrame[0] = pageNumber;
      
      // for a page fault
      PageReplacementAlgorithm::record(pageNumber, true /*page fault*/);
      return;
   }

private:
   //////////////////// YOUR CODE HERE //////////////////////
    int iNextVictim;
};

#endif // PR_BASIC











/***********************************************************************
* Component:
*    Page Replacement Second Chance
* Author:
*    Shawn Phillips
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
      // seed the random number generator
      srand (time(NULL));
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
      for (int i = 0; i < pageFram.size(); i++)
      {
         if (pageFrame[i] < pageNumber)
         {
            PageReplacementAlgorithm::record(pageNumber, false /*no fault*/);
            return;
         }
      }


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









/***********************************************************************
* Component:
*    Page Replacement LRU
* Author:
*    Shawn Phillips
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
      // seed the random number generator
      srand (time(NULL));
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
      {
         if (pageFrame[i] == pageFrame.size())
         {
            PageReplacementAlgorithm::record(pageNumber, false /*no fault*/);
            return;
         }
      }
     
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
   int iNextVictim;
};

#endif // PR_LRU
