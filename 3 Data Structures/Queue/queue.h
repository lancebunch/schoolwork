/***********************************************************************
* Header:
*    Queue
* Summary:
*    This class contains the notion of a queue: a bucket to hold
*    data for the user. This is just a starting-point for more advanced
*    constainers such as the vector, set, stack, queue, deque, and map
*    which we will build later this semester.
*
*    This will contain the class definition of:
*        Queue         : A class that holds stuff
* Author
*    Br. Helfrich
*    Modified by Lance Bunch
************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include <cassert>

/************************************************
 * QUEUE
 * A class that holds stuff
 ***********************************************/
template <class T>
class Queue
{
public:
   // default constructor : empty and kinda useless
   Queue() : numItems(0), cap(0), first(0), last(0), data(NULL) {}

   // copy constructor : copy it
   Queue(const Queue & rhs) throw (const char *);
   
   // non-default constructor : pre-allocate
   Queue(int capacity) throw (const char *);
   
   // destructor : free everything
   ~Queue()           { if (cap == 0) delete [] data; }
   
   // is the queue currently empty
   bool empty() const  { return numItems == 0;         }

   // remove all the items from the queue
   void clear()        
   {  
      numItems = 0;
      first = 0;
      last = 0;
   }

   // how many items are currently in the queue?
   int size() const    { return numItems;              }

   // how many items can the queue hold?
   int capacity() const { return cap;                  }

   // adds a new piece of data to the queue
   void push(const T & t);

   // Removes an item from the head of the queue
   void pop();

   // shows the data at the back of the queue
   T & back() const;

   // show the data at the front of the queue
   T & front() const;

   // overloads the assignment operator to only assign data no addresses
   Queue <T> & operator=(const Queue <T> & rhs) throw (const char*);


private:
   T * data;          // dynamically allocated array of T
   int numItems;      // how many items are currently in the Queue?
   int cap;           // how many items can I put on the Queue before full?
   int first;         // where is the front of the queue?
   int last;          // where is the back of the queue?
};

/*******************************************
 * QUEUE :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Queue <T> :: Queue(const Queue <T> & rhs) throw (const char *)
{
   assert(rhs.cap >= 0);
      
   // do nothing if there is nothing to do
   if (rhs.cap == 0)
   {
      first = 0;
      last = 0;
      cap = 0;
      numItems = 0;
      data = NULL;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[rhs.cap];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate new buffer for queue";
   }
   
   // copy over the capacity and size
   assert(rhs.numItems >= 0 && rhs.numItems <= rhs.cap);
   cap = rhs.cap;
   numItems = rhs.numItems;
   first = rhs.first;
   last = rhs.last;

   // copy the items over one at a time using the assignment operator
   for (int i = 0; i < cap; i++)
      data[i] = rhs.data[i];

   // // the rest needs to be filled with the default value for T
   // for (int i = numItems; i < cap; i++)
   //    data[i] = T();
}

/**********************************************
 * QUEUE : NON-DEFAULT CONSTRUCTOR
 * Preallocate the queue to "capacity"
 **********************************************/
template <class T>
Queue <T> :: Queue(int capacity) throw (const char *)
{
   assert(capacity >= 0);
   
   // do nothing if there is nothing to do
   if (capacity == 0)
   {
      this->cap = this->numItems = this->first = this->last = 0;
      this->data = NULL;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[capacity];
   }
   catch (std::bad_alloc)
   {
      throw "Unable to allocate buffer";
   }

      
   // copy over the stuff
   this->cap = capacity;
   this->numItems = 0;
   this->first = 0;
   this->last = 0;

   // initialize the queue by calling the default constructor
   for (int i = 0; i < capacity; i++)
      data[i] = T();
}

/***************************************************
 * QUEUE :: push
 * places data at the top of the queue
 **************************************************/
template <class T>
void Queue <T> :: push(const T & t)
{
   try
   {
      // if nothing has been allocated...
      if (cap == 0)
      {
         cap = 1;
         // ...allocate it
         data = new T[cap];
      }
      // if the capacity has been met...
      else if (numItems == cap)
      {
         // allocate memory for a new array twice as big as the current array
         T * copyArray = new T[cap * 2];

         int j = first;

         // this loop copies the old data into the copy array 
         for (int i = 0; i < numItems; i++, j = (j + 1) % cap)
         {
            copyArray[i] = data[j];
         }

          // free old - smaller array
         delete [] data;

         // copy the new array's address to the object's pointer variable    
         data = copyArray;

         // set new front
         first = 0;    

         // set new back       
         last = numItems;

         // doubble capacity   
         cap *= 2;
      }

      // add the incoming data onto the queue
      data[last] = t;
      last = (last + 1) % cap;
      numItems++;

      // NOTE: No need to free up copyData's space because
      //       it will be used again the next time numItems
      //       is the same as cap
   }
   catch (std::bad_alloc)
   {
      throw "Unable to allocate a new buffer for Queue";
   }

}

/***************************************************
 * QUEUE :: pop
 * Removes an item from the end of the queue
 **************************************************/
template <class T>
void Queue <T> :: pop() 
{
   if (numItems > 0)
   {
      first = (first + 1) % cap;
      numItems--;
   }
   else
   {
      throw "ERROR: attempting to pop from an empty queue";
   }
}

/***************************************************
 * QUEUE :: back
 * Return the item at the back of the queue
 **************************************************/
template <class T>
T & Queue <T> :: back() const 
{
   // if there is nothing in the queue...
   if (data == NULL || numItems == 0)
   {
      // leave the function and throw the error
      throw "ERROR: attempting to access an item in an empty queue";
   }
   else if (last == 0)
   {
      // otherwise show the last item on the queue
      return data[cap - 1];
   }
   else
   {
      return data[last - 1];
   }
   
}

/***************************************************
 * QUEUE :: front
 * Return the item at the front of the queue
 **************************************************/
template <class T>
T & Queue <T> :: front() const
{
   if (data == NULL || numItems == 0)
   {
      // leave the function and throw the error
      throw "ERROR: attempting to access an item in an empty queue";
   }
   else
   {
      // otherwise show the first item on the queue
      return data[first];
   }
}

/***************************************************
 * QUEUE :: OPERATOR =
 * overloads the = operator
 **************************************************/
template <class T>
Queue <T> & Queue <T> :: operator=(const Queue <T> & rhs) throw (const char*)
{
   try
   {
      // if nothing has been allocated..
      if (rhs.data == NULL)
      {
         // ...data then has no allocation
         delete [] data;
         data = NULL;
         return *this;
      }

      // if the numItems are the same for both sides...
      if (numItems == rhs.numItems && cap == rhs.cap)
      {
         // copy the data at each index of the rhs to the same index
         // on the lhs
         for (int i = 0; i < rhs.size(); i++)
         {
            data[i] = rhs.data[i];
         }
      }
      else
      {
         // deallocate memory
         delete [] data;

         // reallocate memory with the same capacity as the rhs
         data = new T[rhs.cap];

         // make sure the numItems are the same on each side
         numItems = rhs.numItems;
         first = rhs.first;
         last = rhs.last;

         // make the capacity the same as the rhs
         cap = rhs.cap;
         for (int i = 0; i < rhs.size(); i++)
         {
            data[i] = rhs.data[i];
         }
      }
      // return "me"
      return *this;
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for Queue";
   }
}


#endif // QUEUE_H
