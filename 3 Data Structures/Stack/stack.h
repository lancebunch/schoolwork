/***********************************************************************
* Header:
*    Stack
* Summary:
*    This class contains the notion of a stack: a bucket to hold
*    data for the user. This is just a starting-point for more advanced
*    constainers such as the stack, set, stack, queue, deque, and map
*    which we will build later this semester.
*
*    This will contain the class definition of:
*        Stack         : A class that holds stuff
* Author
*    Br. Helfrich
*    Modified by Lance Bunch
************************************************************************/

#ifndef STACK_H
#define STACK_H

#include <cassert>

/************************************************
 * STACK
 * A class that holds stuff
 ***********************************************/
template <class T>
class Stack
{
public:
   // default constructor : empty and kinda useless
   Stack() : numItems(0), cap(0), data(NULL) {}

   // copy constructor : copy it
   Stack(const Stack & rhs) throw (const char *);
   
   // non-default constructor : pre-allocate
   Stack(int capacity) throw (const char *);
   
   // destructor : free everything
   ~Stack()           { if (cap == 0) delete [] data; }
   
   // is the stack currently empty
   bool empty() const  { return numItems == 0;         }

   // remove all the items from the stack
   void clear()        {  numItems = 0;                }

   // how many items are currently in the stack?
   int size() const    { return numItems;              }

   // how many items can the stack hold?
   int capacity() const { return cap;                  }

   // adds a new piece of data at the top of the stack
   void push(const T & t);

   // moves the stack back by one
   void pop();

   // shows the top most piece of data
   T & top() const;

   // overloads the assignment operator to only assign data no addresses
   Stack <T> & operator=(const Stack <T> & rhs) throw (const char*);


private:
   T * data;          // dynamically allocated array of T
   int numItems;      // how many items are currently in the Stack?
   int cap;           // how many items can I put on the Stack before full?
};

/*******************************************
 * STACK :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Stack <T> :: Stack(const Stack <T> & rhs) throw (const char *)
{
   assert(rhs.cap >= 0);
      
   // do nothing if there is nothing to do
   if (rhs.cap == 0)
   {
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
      throw "ERROR: Unable to allocate buffer";
   }
   
   // copy over the capacity and size
   assert(rhs.numItems >= 0 && rhs.numItems <= rhs.cap);
   cap = rhs.cap;
   numItems = rhs.numItems;

   // copy the items over one at a time using the assignment operator
   for (int i = 0; i < numItems; i++)
      data[i] = rhs.data[i];

   // the rest needs to be filled with the default value for T
   for (int i = numItems; i < cap; i++)
      data[i] = T();
}

/**********************************************
 * STACK : NON-DEFAULT CONSTRUCTOR
 * Preallocate the stack to "capacity"
 **********************************************/
template <class T>
Stack <T> :: Stack(int capacity) throw (const char *)
{
   assert(capacity >= 0);
   
   // do nothing if there is nothing to do
   if (capacity == 0)
   {
      this->cap = this->numItems = 0;
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

   // initialize the stack by calling the default constructor
   for (int i = 0; i < capacity; i++)
      data[i] = T();
}

/***************************************************
 * STACK :: push
 * places data at the top of the stack
 **************************************************/
template <class T>
void Stack <T> :: push(const T & t)
{
   try
   {

      // if there is no more room in the stack...
      if (numItems >= cap)
      {
         // if the cap is less than 1, set to 1, otherwise double cap
         cap < 1 ? (cap = 1) : (cap += cap);

         // allocate space for a copy array
         T * copyData = new T[cap];

         // copy everything into the new array
         for (int i = 0; i < numItems; i++)
         {
            copyData[i] = data[i];
         }

         // free up data's space
         delete [] data;

         // recopy data into the original array
         data = copyData;
      }

      // place incoming data into the array
      data[numItems++] = t;

      // NOTE: No need to free up copyData's space because
      //       it will be used again the next time numItems
      //       is the same as cap
   }
   catch (std::bad_alloc)
   {
      throw "Unable to allocate a new buffer for Stack";
   }

}

/***************************************************
 * STACK :: pop
 * Removes an item from the end of the stack
 **************************************************/
template <class T>
void Stack <T> :: pop() 
{
   // if there is nothing in the stack...
   if (data == NULL || numItems == 0)
   {
      // ...leave the function and throw and error
      throw "ERROR: Unable to pop from an empty Stack";
   }
   else
   {
      // otherwise remove the top most pice of data
      data[--numItems];
   }
   
}

/***************************************************
 * STACK :: top
 * Return the item at the top of the stack
 **************************************************/
template <class T>
T & Stack <T> :: top() const 
{
   // if there is nothing in the stack...
   if (data == NULL || numItems == 0)
   {
      // leave the function and throw the error
      throw "ERROR: Unable to reference the element from an empty Stack";
   }
   else
   {
      // otherwise show the last item on the stack
      return data[numItems - 1];
   }
}

/***************************************************
 * STACK :: OPERATOR =
 * overloads the = operator
 **************************************************/
template <class T>
Stack <T> & Stack <T> :: operator=(const Stack <T> & rhs) throw (const char*)
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
      throw "ERROR: Unable to allocate a new buffer for Stack";
   }
}


#endif // STACK_H
