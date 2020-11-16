/***********************************************************************
 * Program:
 *    Lab 06, Producer and Consumer
 * Author:
 *    Lance Bunch
 * Summary:
 *    This program will allow us to simulate the production run
 *    at McLaren Cars. It would be cool if it simulated the cars
 *    themselves, but that might be an assignment for another day
 *
 *    Note that you must compile this with the -lpthread switch:
 *        g++ -lpthread lab06.cpp
 ************************************************************************/

#include <iostream>    // for COUT
#include <cassert>     // for ASSERT
#include <string>      // for STRING
#include <sstream>     // for STRINGSTREAM
#include <queue>       // for QUEUE
#include <ctime>       // for time(), part of the random process
#include <unistd.h>    // for usleep()
#include <stdlib.h>    // for rand() and srand()
#include <pthread.h>   // for PTHREAD_T and the PTHREAD functions
#include <semaphore.h> // for SEM_T and related methods
#include "cars.h"      // for everything dealing with McLaren Cars

using namespace std;

// This variable represents the shared memory between the parent thread
// and all the children. Recall from the reading how the main way for
// threads to communicate is through shared memory. This shared memory
// needs to be global.
sem_t lock;
sem_t semaphore; // counting semaphore
bool productionComplete = false;
Inventory inventory;

void *producer(void *model);    // Prototype
void *consumer(void *retailer); // Prototype

int getNumber(const char *prompt, int max);

/***********************************************
 * MAIN
 * This will serve to prompt the user for the number
 * of models and the number of retailers. It will then
 * begin the simulation
 ***********************************************/
int main(int argc, char **argv)
{
   // set up the random number generator
   srand(argc == 1 ? time(NULL) : (int)argv[1][1]);

   // determine how many producer and consumer threads
   int numProducer = getNumber("How many models?    ", numModels());
   int numConsumer = getNumber("How many retailers? ", numRetailers());
   int numThreads = numProducer + numConsumer;

   // sell the cars.
   cout << "\nThe cars sold from the various retailers:\n\n";

   // set up the mutex lock
   sem_init(&lock, 0 /*for thread safety, not process*/, 1 /*initial value*/);

   // produce the cars and sell the cars. Need a thread
   // for each producer and each conumer
   pthread_t threadsP[numProducer];
   pthread_t threadsC[numConsumer];

   // launch the Producers
   for (int i = 0; i < numProducer; i++)
      pthread_create(threadsP + i, NULL, producer, (void *)models[i]);

   // launch the consumers
   for (int i = 0; i < numConsumer; i++)
      pthread_create(threadsC + i, NULL, consumer, (void *)retailers[i]);

   // get everyone back together
   for (int i = 0; i < numProducer; i++)
      pthread_join(threadsP[i], NULL);
   for (int i = 0; i < numConsumer; i++)
      pthread_join(threadsC[i], NULL);

   // final report
   cout << "Maximum size of the inventory: "
        << inventory.getMax()
        << endl;

   return 0;
}

/***********************************************************
 * PRODUCER
 * Create those cars.
 * This function is not currently thread safe. You will need
 * to introduce a critical section in such a way that we do
 * not compromise the queue nor produce two cars with the
 * same serial number.
 **********************************************************/
void *producer(void *model)
{
   static int serialNumberNext = 0;

   // a car to be added to the inventory
   Car car;
   car.model = (char *)model;

   // continue as long as we still need to produce cars in this run
   while (serialNumberNext < NUM_CARS)
   {
      // now that we decided to build a car, it takes some time
      usleep(rand() % 150000);

      // add the car to our inventory if we still need to
      if (serialNumberNext < NUM_CARS)
      {
         sem_wait(&lock);
         car.serialNumber = ++serialNumberNext;
         inventory.makeCar(car);
         sem_post(&lock);
      }
   }

   // all done!
   productionComplete = true;

   pthread_exit(NULL);
}

/***********************************************************
 * CONSUMER
 * Sell those cars.
 * This function is not currently thread safe. You will need
 * to introduce a critical section in such a way that we
 * do not compromise the queue nor sell the same car twice.
 **********************************************************/
void *consumer(void *retailer)
{
   // collect our sales history into one string
   stringstream sout;
   sout << (char *)retailer << ":\n";

   // continue while there are still customers floating around
   while (!(productionComplete && inventory.empty()))
   {
      // the car to sell
      Car car;

      // it takes time to sell our car
      usleep(rand() % 150000);

      // do we have one to sell
      if (!inventory.empty())
      {
         sem_wait(&lock);
         car = inventory.sellCar();
         sem_post(&lock);
         sout << "\t" << car << endl;
      }
   }

   // done
   string *report = new string(sout.str());
   cout << *report << endl;
   delete report;
   pthread_exit(NULL);
}

/*********************************************
 * GET NUMBER
 * Generic prompt function with error checking
 ********************************************/
int getNumber(const char *prompt, int max)
{
   int value = -1;
   assert(cin.good());     // better not already be in error mode
   assert(prompt != NULL); // the prompt better be a valid c-string
   assert(max > 0);        // it better be possible for valid data to exist

   // continue prompting until we have valid data
   while (value <= 0 || value > max)
   {
      cout << prompt;
      cin >> value;

      // if the user typed a non-integer value, reprompt.
      if (cin.fail())
      {
         cin.clear();
         cin.ignore();
         cout << "Error: non-integer value specified\n";
      }

      // if the user typed a valid outside the range, reprompt
      else if (value <= 0 || value > max)
         cout << "Error: value must be between 1 and "
              << max
              << endl;
   }

   return value;
}
