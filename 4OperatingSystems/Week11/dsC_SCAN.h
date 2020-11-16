/***********************************************************************
* Component:
*    DISK SCHEDULING C-SCAN
* Author:
*    <your name here>
* Summary: 
*    This is the DERRIVED class to implement the C-SCAN algorithm
************************************************************************/

#ifndef DS_C_SCAN
#define DS_C_SCAN

#include "ds.h" // for the DiskSchedulingAlgorithm base-class

//using namespace std;

/****************************************************
 * C-SCAN
 * The C-SCAN disk scheduling algorithm
 ***************************************************/
class DiskSchedulingC_SCAN : public DiskSchedulingAlgorithm
{
public:
   /*****************************************************
    * CONSTRUCTOR
    * initialize the data structures specific to C-SCAN
    *****************************************************/
   DiskSchedulingC_SCAN(const ScheduleProblem &problem) : DiskSchedulingAlgorithm(problem)
   {
      requests = problem.requests;
      requests.sort();
      increasing = problem.increasing;
   }

   /*****************************************************
    * ITERATECURRENTLOCATION
    * Runs through our requests and records the ones that
    * have been serviced.
    *****************************************************/
   int iterateCurrentLocation()
   {
      int endLocation; // The ending location of the disk head.
      if (increasing)
      {
         // Setting our endLocation function
         endLocation = getDiskSize() - 1;
         // Iterate through all possible locations in ascending order.
         for (currentLocation = currentLocation; currentLocation <= endLocation; currentLocation++)
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
            // Need to record if we have reached the end of our disk
            if (currentLocation == endLocation && requests.size())
            {
               record();
            }
         }
      }
      else
      {
         // Setting our endLocation function
         endLocation = 0;
         // Iterate through all possible locations in descending order.
         for (currentLocation = currentLocation; currentLocation >= endLocation; currentLocation--)
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
            // Need to record if we have reached the end of our disk
            if (currentLocation == endLocation && requests.size())
            {
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
    * simulation. With file location, send the results to record().
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
         if (increasing)
            currentLocation = 0;
         else
            currentLocation = getDiskSize() - 1;
         record();
      }
      return;
   }

private:
   std::list<int> requests; // a copy of the list of disk requests
   bool increasing;
};

#endif // DS_C_SCAN
