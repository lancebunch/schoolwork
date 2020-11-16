/***********************************************************************
 * Program:
 *    Lab 07, Producer and Consumer
 * Author:
 *    Tanner Troumbley
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
#include "cars.h"      // for everything dealing with McLaren Cars
#include <semaphore.h> // for SEM_T and related methods.

using namespace std;

// This variable represents the shared memory between the parent thread
// and all the children. Recall from the reading how the main way for
// threads to communicate is through shared memory. This shared memory
// needs to be global.
bool productionComplete = false;
sem_t semaphore;                 //Counting semaphore
void *producer(void *parameter); // you may need to change this
void *consumer(void *parameter); // you may need to change this also

int getNumber(const char *prompt, int max);

//Thread Parameters used to pass the Inventory and other information as needed.
struct ThreadParameters
{
   Inventory inventory;
   const char *model;
   const char *retailer;
};
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

   // produce the cars. Note that this code needs to change. We will
   // need to launch one thread per producer here
   Car car;

   //create a max number of threads equal to the total number of producers.
   pthread_t threadsProducers[numProducer];

   //create mutex lock with the max number of thread that can be in the
   //ciritical section at once being equal to the numConsumers pluse numProducers.
   int maxDepth = numConsumer + numProducer;
   ThreadParameters p;

   sem_init(&semaphore, 0, maxDepth);

   for (int i = 0; i < numProducer; i++)
   {

      //This uses each thread for every producer. It passes the car
      //and inventory to  the function producer
      p.model = models[i];

      pthread_create(threadsProducers, NULL,
                     producer,
                     &p);
   }

   // sell the cars. Note that this code also needs to change.
   cout << "\nThe cars sold from the various retailers:\n\n";

   //Create consumer thread for each consumer.
   pthread_t threadsConsumers[numConsumer];

   for (int i = 0; i < numConsumer; i++)
   {
      //Uses the threads created and passes the retailers[i] and inventory to
      //consumer
      p.retailer = retailers[i];

      pthread_create(threadsConsumers, NULL,
                     consumer,
                     &p);
   }

   //Wrap up the producer threads
   for (int i = 0; i < numProducer; i++)
      pthread_join(threadsProducers[i], NULL);

   //Wrap up the consumer threads.
   for (int i = 0; i < numConsumer; i++)
      pthread_join(threadsConsumers[i], NULL);

   // final report
   cout << "Maximum size of the inventory: "
        << p.inventory.getMax()
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
void *producer(void *parameter)
{
   ThreadParameters *p = (ThreadParameters *)parameter;

   Car car;
   car.model = p->model;

   static int serialNumberNext = 0;

   // continue as long as we still need to produce cars in this run
   while (serialNumberNext < NUM_CARS)
   {
      //Critival section
      //Wait if there are no open slots.
      sem_wait(&semaphore);

      // add the car to our inventory if we still need to
      if (serialNumberNext < NUM_CARS)
      {
         car.serialNumber = ++serialNumberNext;
         p->inventory.makeCar(car);
      }

      //We're done.
      sem_post(&semaphore);
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
void *consumer(void *parameter)
{

   ThreadParameters *r = (ThreadParameters *)parameter;

   // collect our sales history into one string
   stringstream sout;
   sout << r->retailer << ":\n";
   Car car;

   // continue while there are still customers floating around
   while (!(productionComplete && r->inventory.empty()))
   {

      //wait for an open slot.
      sem_wait(&semaphore);

      // do we have one to sell
      if (!r->inventory.empty())
      {
         car = r->inventory.sellCar();
         sout << "\t" << car << endl;
      }

      //Wer'e done.
      sem_post(&semaphore);
   }

   // done
   string *report = new string(sout.str());
   pthread_exit(report);
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
