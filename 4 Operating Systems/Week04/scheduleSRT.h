/***********************************************************************
* Component:
*    Scheduler SRT
* Author:
*    Lance Bunch
* Summary: 
*    This is the base-class that enables various schedule algorithms
*    to simulate CPU Scheduling
************************************************************************/

#ifndef SCHEDULER_SRT
#define SCHEDULER_SRT

#include "schedule.h"
#include <algorithm>

/****************************************************
 * SRT
 * The Shortest Remaining Time Scheduler
 ***************************************************/
using namespace std;
class SchedulerSRT : public Disbatcher
{
public:
   SchedulerSRT() : Disbatcher() {}
   // a new process has just been executed
   void startProcess(int pid)
   {
      readyQueue.push_back(pid);
   }

   // execute one clock cycle
   bool clock()
   {
      // Check if a process was just run, and is done
      if ((pidCurrent != PID_NONE) && (processes[pidCurrent].isDone()))
      {
         readyQueue.erase(remove(readyQueue.begin(), readyQueue.end(), pidCurrent));
      }
      // if there is something on the ready queue...
      if (readyQueue.size())
      {
         // Organize the Queue based off of what process has the shortest time remaining
         prioritizeProcesses();
         // Set the current process equal to the front of the queue, or in other words,
         // set the current process as the process with the shortest remaining run time
         pidCurrent = readyQueue.front();
         assert(pidCurrent >= 0 && pidCurrent <= processes.size());
      }
      // Otherwise make sure to let the program know that there are no other processes to run
      else
      {
         pidCurrent = PID_NONE;
      }
      return Disbatcher::clock();
   }

private:
   vector<int> readyQueue; // Queue of ready pids.

   /****************************************************
      * PRIORITIZEPROCESSES
      * Sorts the process IDs in the ready queue by time left,
      * with the process having the shortest time left first.
      ****************************************************/
   void prioritizeProcesses()
   {
      stable_sort(readyQueue.begin(), readyQueue.end(), [this](int first, int second) {
         return processes[first].getTimeLeft() < processes[second].getTimeLeft();
      });
   };
};

#endif // SCHEDULE_SRT
