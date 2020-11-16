/***********************************************************************
* Component:
*    DISK SCHEDULING SSTF
* Author:
*    Lance Bunch
* Summary: 
*    This is the DERRIVED class to implement the SSTF algorithm
************************************************************************/

#ifndef DS_SSTF
#define DS_SSTF

#include "ds.h" // for the DiskSchedulingAlgorithm base-class

// using namespace std;

/****************************************************
 * SSTF
 * The Sortest-Seek-Time-First disk scheduling algorithm
 ***************************************************/
class DiskSchedulingSSTF : public DiskSchedulingAlgorithm
{
public:
   /*****************************************************
    * CONSTRUCTOR
    * initialize the data structures specific to SSTF
    *****************************************************/
   DiskSchedulingSSTF(const ScheduleProblem &problem) : DiskSchedulingAlgorithm(problem)
   {
      // make a copy of the list of disk requests which will be
      // consumed as the simulation runs
      requests = problem.requests;
      requests.sort();
   }

   /****************************************************
    * RUN
    * Implement the algorithm here. This function will only
    * be called once and will need to complete the entire
    * simulation.
    *
    * Each time a disk request is made by setting currentLocation,
    * call record() to save that.
    ***************************************************/
   void run()
   {

      return;
   }

private:
   std::list<int> requests; // a copy of the list of disk requests
};

#endif // DS_SSTF
