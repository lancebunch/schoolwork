/***********************************************************************
* Component:
*    Scheduler SJF
* Author:
*    Lance Bunch
* Summary: 
*    This is the base-class that enables various schedule algorithms
*    to simulate CPU Scheduling
************************************************************************/

#ifndef SCHEDULER_SJF
#define SCHEDULER_SJF
#include "schedule.h"
#include <bits/stdc++.h>
#include <ctime>
#include <functional>
/****************************************************
 * SJF
 * The Shortest Job First scheduler
 ***************************************************/
using namespace std;
class SchedulerSJF : public Disbatcher
{
public:
   SchedulerSJF() : Disbatcher() {}
   // a new process has just been executed
   void startProcess(int pid)
   {
      readyQueue.push_back(pid);
      prioritizeProcesses();
   }

   // execute one clock cycle
   bool clock()
   {
      // Is the current process finished or is no process being run?
      if (pidCurrent == PID_NONE || processes[pidCurrent].isDone())
      {
         // if there is something on the ready queue, then take the front
         // element. When we do this, we remove the item from the ready queue
         // and place it in pidCurrent.
         if (readyQueue.size())
         {
            pidCurrent = readyQueue.front();
            readyQueue.erase(readyQueue.begin());
            assert(pidCurrent >= 0 && pidCurrent <= processes.size());
         }
         // if there is nothing in the ready queue, then set pidCurrent
         // to none. This means nothing is currently executing in the queue
         else
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
      stable_sort(this->readyQueue.begin(), this->readyQueue.end(), [this](int first, int second) {
         return this->processes[first].getTimeLeft() < this->processes[second].getTimeLeft();
      });
   };
};

#endif // SCHEDULE_SJF
