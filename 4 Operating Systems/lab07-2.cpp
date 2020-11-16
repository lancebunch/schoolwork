/***********************************************************************
 * Program:
 *    Lab 06, Producer and Consumer
 * Author:
 *    <your name here>
 * Summary:
 *    This program will allow us to simulate the production run
 *    at McLaren Cars. It would be cool if it simulated the cars
 *    themselves, but that might be an assignment for another day
 *
 *    Note that you must compile this with the -lpthread switch:
 *        g++ -lpthread lab06.cpp
 ************************************************************************/

#include <iostream>      // for COUT
#include <cassert>       // for ASSERT
#include <string>        // for STRING
#include <sstream>       // for STRINGSTREAM
#include <queue>         // for QUEUE
#include <ctime>         // for time(), part of the random process
#include <unistd.h>      // for usleep()
#include <stdlib.h>      // for rand() and srand()
#include "cars.h"        // for everything dealing with McLaren Cars
#include <semaphore.h>   // for the below semaphore.
using namespace std;
// Mutex locks
pthread_mutex_t serialNumberLock;
pthread_mutex_t inventoryLock;
pthread_mutex_t productionCompleteLock;
// Semaphore
sem_t semaphore;
// This variable represents the shared memory between the parent thread
// and all the children. Recall from the reading how the main way for
// threads to communicate is through shared memory. This shared memory
// needs to be global.
bool productionComplete = false;
// This variable indicates whether the inventory is empty.
bool inventoryEmpty = false;
/***********************************************
 * PRoDUCER_ARGS
 * This stores arguments for the "producer" function.
 ***********************************************/
struct ProducerArgs
{
   const char *model;
   int producerNumber=0;
   Inventory *inventory;
   int beginningSerialNumber=0;
   int endingSerialNumber=0;
};
/***********************************************
 * CONSUMER_ARGS
 * This stores arguments for the "consumer" function.
 ***********************************************/
struct ConsumerArgs
{
   const char* retailer;
   Inventory *inventory;
};

void   *  producer(void *args);   // you may need to change this
void * consumer(void *args);   // you may need to change this also

int getNumber(const char * prompt, int max);

int numProducer;

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
   numProducer = getNumber("How many models?    ", numModels());
   int numConsumer = getNumber("How many retailers? ", numRetailers());

   // produce the cars. Note that this code needs to change. We will
   // need to launch one thread per producer here
   Inventory inventory;
   
   // Divide the work among the threads.
   int numCars[4];
   int numCarsPerProducer = NUM_CARS / numProducer;
   int remainderCarsPerProducer = NUM_CARS % numProducer;
   for (int i=0; i < numProducer; i++)
      numCars[i] = numCarsPerProducer;
   if (remainderCarsPerProducer > 0)
      numCars[0] += remainderCarsPerProducer;
   int beginningSerialNumber=1;
   int endingSerialNumber=0;
   ProducerArgs *producerArgs = new ProducerArgs[numProducer];
   // Distribute the work equally across threads.
   pthread_t producerThreads[4];
   for (int i = 0; i < numProducer; i++)
   {  
      ProducerArgs *pArgs = &(producerArgs[i]);
      pArgs->model = models[i];
      pArgs->inventory = &inventory;
      pArgs->producerNumber = i;
      pArgs->beginningSerialNumber = beginningSerialNumber;
      endingSerialNumber += numCars[i];
      pArgs->endingSerialNumber = endingSerialNumber;
      assert(pArgs->endingSerialNumber <= numProducer * NUM_CARS);
      beginningSerialNumber = endingSerialNumber + 1;
      pthread_t *producerThread = &producerThreads[i];
      assert(pthread_create(
                           producerThread,
                           NULL,
                           producer,
                           producerArgs
                           ) == 0);
   }
   assert(endingSerialNumber == 50);
   // sell the cars. Note that this code also needs to change.
   cout << "\nThe cars sold from the various retailers:\n\n";
   ConsumerArgs *consumerArgs = new ConsumerArgs[numConsumer];
   pthread_t *consumerThreads = new pthread_t[numConsumer];
   for (int i = 0; i < numConsumer; i++)
   {
      ConsumerArgs *args = &(consumerArgs[i]);
      args->retailer = retailers[i];
      args->inventory = &inventory;
      assert(pthread_create(
                           &(consumerThreads[i]),
                           NULL,
                           consumer,
                           args
                           ) == 0);
      
   };
   for (int i=0; i < numConsumer; i++)
   {
      void *retVal;
      pthread_join(consumerThreads[i],&retVal);
      string report = *(string *)retVal;
      cout << report << endl;
   };
   // final report
   cout << "Maximum size of the inventory: "
        << inventory.getMax()
        << endl;
   // Remove arrays from heap.
   delete producerArgs;
   delete consumerArgs;
   delete consumerThreads;
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
void *producer(void *args)
{
   ProducerArgs *producerArgsArray = (ProducerArgs *)args;
   for (int i=0; i<numProducer; i++)
   {
      ProducerArgs *producerArgs = &(producerArgsArray[i]);
      int producerNumber = producerArgs->producerNumber;
      const char *model = producerArgs->model;
      Inventory *inventory = producerArgs->inventory;
      static int serialNumberNext = producerArgs->beginningSerialNumber;
   
      // continue as long as we still need to produce cars in this run
      while (serialNumberNext <= producerArgs->endingSerialNumber)
      {
         // now that we decided to build a car, it takes some time
         usleep(rand() % 150000);
         // a car to be added to the inventory
         Car car;
         car.model = model;
         car.serialNumber = serialNumberNext;
         // add the car to our inventory if we still need to
         pthread_mutex_lock(&inventoryLock);
         inventory->makeCar(car);
         pthread_mutex_unlock(&inventoryLock);
         serialNumberNext++;
      }
      // all done!
      pthread_mutex_lock(&productionCompleteLock);
      productionComplete = true;
      pthread_mutex_unlock(&productionCompleteLock);
      // Signal to the consumer threads that production is complete.
      sem_post(&semaphore);
   }
}

/***********************************************************
 * CONSUMER
 * Sell those cars.
 * This function is not currently thread safe. You will need
 * to introduce a critical section in such a way that we
 * do not compromise the queue nor sell the same car twice.
 **********************************************************/
void *consumer(void *args)
{
   sem_wait(&semaphore);
   ConsumerArgs *consumerArgs = (ConsumerArgs *)args;
   const char *retailer = consumerArgs->retailer;
   Inventory *inventory = consumerArgs->inventory;
   // collect our sales history into one string
   stringstream sout;
   sout << retailer << ":\n";
   // continue while there are still customers floating around
   pthread_mutex_lock(&productionCompleteLock);
   while (!(productionComplete && inventoryEmpty))
   {
      pthread_mutex_unlock(&productionCompleteLock);
      // do we have one to sell
      pthread_mutex_lock(&inventoryLock);
      inventoryEmpty = inventory->empty();
      pthread_mutex_unlock(&inventoryLock);
      // it takes time to sell our car
      usleep(rand() % 150000);
      if (!inventoryEmpty)
      {
         Car car = inventory->sellCar();
         sout << car << endl;
      }
      else
         break;
      
   }

   // done
   string * report = new string(sout.str());
   return (void *)report;
}

/*********************************************
 * GET NUMBER
 * Generic prompt function with error checking
 ********************************************/
int getNumber(const char * prompt, int max)
{
   int value = -1;
   assert(cin.good());       // better not already be in error mode
   assert(prompt != NULL);   // the prompt better be a valid c-string
   assert(max > 0);          // it better be possible for valid data to exist

   // continue prompting until we have valid data
   while (value <= 0 || value > max)
   {
      cout << prompt;
      cin  >> value;

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
