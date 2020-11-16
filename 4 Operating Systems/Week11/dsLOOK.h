/***********************************************************************
* Component:
*    DISK SCHEDULING LOOK
* Author:
*    <your name here>
* Summary: 
*    This is the DERRIVED class to implement the LOOK algorithm
************************************************************************/

#ifndef DS_LOOK
#define DS_LOOK

#include "ds.h" // for the DiskSchedulingAlgorithm base-class
#include <algorithm>

using namespace std;

/****************************************************
 * SCAN
 * The LOOK (SCAN with lookahead) disk scheduling algorithm
 ***************************************************/
class DiskSchedulingLOOK : public DiskSchedulingAlgorithm
{
public:
   /*****************************************************
    * CONSTRUCTOR
    * initialize the data structures specific to SCAN
    *****************************************************/
   DiskSchedulingLOOK(const ScheduleProblem &problem) : DiskSchedulingAlgorithm(problem)
   {
      requests = problem.requests;
      requests.sort();
      increasing = problem.increasing;
      accesser = requests.end();
      accesser--;
      highLocation = *accesser;
      accesser = requests.begin();
      lowLocation = *accesser;
   }

   /*****************************************************
    * ITERATECURRENTLOCATION
    * Runs through our requests and records the ones that
    * have been serviced.
    *****************************************************/
   int iterateCurrentLocation()
   {
      int endLocation;
      if (increasing)
      {
         // Setting our endLocation variable
         endLocation = highLocation;

         // Iterate through all possible locations in ascending order.
         for (currentLocation = currentLocation; currentLocation < endLocation; currentLocation++)
         {
            // Try to find currentLocation in requests.
            auto iterator = find(requests.begin(), requests.end(), currentLocation);
            // If our iterator equals something other than the end of our list,
            // it is equal to our current location. This means we found a
            // request.
            if (iterator != requests.end())
            {
               // delete that request since it has been serviced
               requests.erase(iterator);
               // record our find.
               record();
            }
         }
      }
      else
      {
         // Setting our endLocation function
         endLocation = lowLocation;
         // Iterate through all possible locations in descending order.
         for (currentLocation = currentLocation; currentLocation > endLocation; currentLocation--)
         {
            // Try to find currentLocation in requests.
            auto iterator = find(requests.begin(), requests.end(), currentLocation);
            // If our iterator equals something other than the end of our list,
            // it is equal to our current location. This means we found a
            // request.
            if (iterator != requests.end())
            {
               // delete that request since it has been serviced
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
         if (increasing && (currentLocation == highLocation))
            increasing = false;
         else if (!increasing && (currentLocation == lowLocation))
            increasing = true;
      }
      return;
   }

private:
   std::list<int> requests; // a copy of the list of disk requests
   bool increasing;
   int highLocation; // The highest location the disk will go.
   int lowLocation;  // The lowest location the disk will go.
   std::list<int>::iterator accesser;
};

#endif // DS_LOOK
