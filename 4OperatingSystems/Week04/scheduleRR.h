/***********************************************************************
* Component:
*    Scheduler RR
* Author:
*    Lance Bunch
* Summary: 
*    This is the base-class that enables various schedule algorithms
*    to simulate CPU Scheduling
************************************************************************/

#ifndef SCHEDULER_RR
#define SCHEDULER_RR

#include "schedule.h"

using namespace std;

/****************************************************
 * RR
 * The Round Robin scheduler
 ***************************************************/
class SchedulerRR : public Disbatcher
{
public:
   SchedulerRR(int q) : Disbatcher(),
                        timeQuantaDuration(q), timeQuantaRemaining(q) {}

   // a new process has just been executed
   void startProcess(int pid)
   {
      readyQueue.push(pid);
   }

   // execute one clock cycle. Here we will determine whether we need
   // to switch to a new process
   bool clock()
   {
      // is the current process finished or is there no process selected?
      if (pidCurrent == PID_NONE ||
          processes[pidCurrent].isDone())
      {
         // if there is something on the ready queue, then take the front
         // element. When we do this, we remove the item from the ready queue
         // and place it in pidCurrent.
         if (readyQueue.size())
         {
            // Get the next item on the gueue ready for processing
            pidCurrent = readyQueue.front();
            readyQueue.pop();
            // Make sure the remaining time duration is reset to what is alloted
            timeQuantaRemaining = timeQuantaDuration;
            assert(pidCurrent >= 0 && pidCurrent <= processes.size());
         }
         else
         {
            pidCurrent = PID_NONE;
         }
      }
      // is there still a process going on but the time interval is up?
      else if (!timeQuantaRemaining)
      {
         // Push the process to the back of the queue
         readyQueue.push(pidCurrent);
         // Set the current process as the item in the front of the queue
         pidCurrent = readyQueue.front();
         // Keep track of what will then be next in line
         readyQueue.pop();
         // Reset the remaining time to the time interval specified
         timeQuantaRemaining = timeQuantaDuration;
      }

      // Decrament the alloted time druation
      timeQuantaRemaining--;

      return Disbatcher::clock();
   }

private:
   int timeQuantaDuration;
   int timeQuantaRemaining;
   queue<int> readyQueue;
};

#endif // SCHEDULE_RR
