/***********************************************************************
 * Implementation:
 *    NOW SERVING
 * Summary:
 *    This will contain the implementation for nowServing() as well as any
 *    other function or class implementations you may need
 * Author
 *    <your names here>
 **********************************************************************/

#include <iostream>     // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>       // for STRING
#include <cassert>      // for ASSERT
#include "nowServing.h" // for nowServing() prototype
#include "deque.h"      // for DEQUE
using namespace std;

/************************************************
 * DISPLAY
 * Displays who is being helped and how much more
 * time they have after each command
 ***********************************************/
void display(Info & NowServing)
{
   // if there is an emergency
   if (NowServing.emergency)
   {    
      // let them know
      cout << "\tEmergency for ";
   }
   else
   {
      // otherwise just display 
      cout << "\tCurrently serving ";
   }

   cout << NowServing.name 
         << " for class " << NowServing.course
         << ". Time left: " << NowServing.neededTime << endl;
   // make sure to decrement their needed time so we know when to move on
   NowServing.neededTime--;
}

/************************************************
 * NOW SERVING
 * The interactive function allowing the user to
 * handle help requests in the Linux lab
 ***********************************************/
void nowServing()
{
   // instructions
   cout << "Every prompt is one minute.  The following input is accepted:\n";
   cout << "\t<class> <name> <#minutes>    : a normal help request\n";
   cout << "\t!! <class> <name> <#minutes> : an emergency help request\n";
   cout << "\tnone                         : no new request this minute\n";
   cout << "\tfinished                     : end simulation\n";

   // Stating some variables
   string instruction;
   int timeSpent = 0;
   Deque <Info> deque;
   Info NowServing;
   Info temp;

   // just as long as the user isn't finished
   while (instruction != "finished")
   {
      cout << "<" << timeSpent << "> ";
      cin >> instruction;
      if (instruction == "!!")
      {
         cin >> temp.course;
         cin >> temp.name;
         cin >> temp.neededTime;
         temp.emergency = true;
         deque.push_front(temp);
      }
      else if (instruction == "none")
      {

      }
      else if (instruction == "finished")
      {
         cout << "End of simulation\n";
      }
      else
      {
         temp.course = instruction;
         cin >> temp.name;
         cin >> temp.neededTime;
         temp.emergency = false;
         deque.push_back(temp);
      }
      // if there is someone who needs more time
      if (NowServing.neededTime > 0)
      {
         // display who it is 
         display(NowServing);
      }
      else
      {
         // otherwise as long as the deque isn't empty
         if (!deque.empty())
         {
            // move onto the next person on the deque and 
            // take them off of the deque
            NowServing.name = deque.front().name;
            NowServing.course = deque.front().course;
            NowServing.neededTime = deque.front().neededTime;
            NowServing.emergency = deque.front().emergency;
            deque.pop_front();
            display(NowServing);
         }
      }
      timeSpent++;
   }
}


