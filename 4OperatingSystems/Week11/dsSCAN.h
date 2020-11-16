/***********************************************************************
* Component:
*    DISK SCHEDULING SCAN
* Author:
*    Lance Bunch
* Summary: 
*    This is the DERRIVED class to implement the SCAN algorithm
************************************************************************/

#ifndef DS_SCAN
#define DS_SCAN

#include "ds.h" // for the DiskSchedulingAlgorithm base-class
#include <algorithm>
// using namespace std;

/****************************************************
 * SCAN
 * The SCAN (aka Elevator) disk scheduling algorithm
 ***************************************************/
class DiskSchedulingSCAN : public DiskSchedulingAlgorithm
{
public:
   /*****************************************************
    * CONSTRUCTOR
    * initialize the data structures specific to SCAN
    *****************************************************/
   DiskSchedulingSCAN(const ScheduleProblem &problem) : DiskSchedulingAlgorithm(problem)
   {
      // make a copy of the list of disk requests which will be
      // consumed as the simulation runs
      requests = problem.requests;
      requests.sort();
      increasing = problem.increasing;
   }

   /*****************************************************
    * CONSTRUCTOR
    * initialize the data structures specific to C-SCAN
    *****************************************************/
   int iterateCurrentLocation()
   {
      int endLocation; // The ending location of the disk head.
      if (increasing)
      {
         endLocation = getDiskSize() - 1;
         // Iterate through all possible locations in ascending order.
         for (currentLocation = currentLocation; currentLocation <= endLocation; currentLocation++)
         {
            // Try to find currentLocation in requests.
            auto iterator = find(requests.begin(), requests.end(), currentLocation);
            // If currentLocation is found in requests,
            if (iterator != requests.end())
            {
               requests.erase(iterator);
               // record our find.
               record();
            }
         }
      }
      else
      {
         endLocation = 1;
         // Iterate through all possible locations in descending order.
         for (currentLocation = currentLocation; currentLocation >= endLocation; currentLocation--)
         {
            // Try to find currentLocation in requests.
            auto iterator = find(requests.begin(), requests.end(), currentLocation);
            if (iterator != requests.end())
            {
               requests.erase(iterator);
               // record our find.
               record();
            }
         }
      }
      return endLocation;
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
      // Lets keep going as long as there is a request waiting
      while (requests.size())
      {
         // Function implementing logic
         iterateCurrentLocation();
         // We don't want to do anything else if we just deleted
         // the last request in our list, so leave the function.
         if (!requests.size())
            return;
         if (increasing && (currentLocation == getDiskSize() - 1))
            increasing = false;
         else
            increasing = true;
         record();
      }
      return;
   }

private:
   std::list<int> requests; // a copy of the list of disk requests
   bool increasing;
};

#endif // DS_SCAN
