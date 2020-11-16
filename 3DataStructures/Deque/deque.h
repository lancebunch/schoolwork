/***********************************************************************
* Header:
*    Deque
* Summary:
*    This class contains the notion of a Deque: a bucket to hold
*    data for the user. This is just a starting-point for more advanced
*    constainers such as the vector, set, stack, queue, deque, and map
*    which we will build later this semester.
*
*    This will contain the class definition of:
*        Deque         : A class that holds stuff
* Author
*    Br. Helfrich
*    Modified by Lance Bunch
************************************************************************/

#ifndef DEQUE_H
#define DEQUE_H

#include <cassert>

/************************************************
 * Deque
 * A class that holds stuff
 ***********************************************/
template <class T>
class Deque
{
public:
   // default constructor : empty and kinda useless
   Deque() : numItems(0), cap(0), first(0), last(0), data(NULL) {}

   // copy constructor : copy it
   Deque(const Deque & rhs) throw (const char *);
   
   // non-default constructor : pre-allocate
   Deque(int capacity) throw (const char *);
   
   // destructor : free everything
   ~Deque()           { if (cap == 0) delete [] data; }
   
   // is the Deque currently empty
   bool empty() const  { return numItems == 0;         }

   // remove all the items from the deque
   void clear()        
   {  
      numItems = 0;
      first = 0;
      last = 0;
   }

   // how many items are currently in the deque?
   int size() const    { return numItems;              }

   // how many items can the deque hold?
   int capacity() const { return cap;                  }

   // adds a new piece of data to the back of the deque
   void push_back(const T & t);

   // adds a new piece of data to the front of the deque
   void push_front(const T & t);

   // removes an item from the back of the deque
   void pop_back();

   // Removes an item from the head of the deque
   void pop_front();

   // shows the data at the back of the deque
   T & back() const;

   // show the data at the front of the deque
   T & front() const;

   // overloads the assignment operator to only assign data no addresses
   Deque <T> & operator=(const Deque <T> & rhs) throw (const char*);


private:
   T * data;          // dynamically allocated array of T
   int numItems;      // how many items are currently in the Deque?
   int cap;           // how many items can I put on the Deque before full?
   int first;         // where is the front of the deque?
   int last;          // where is the back of the deque?
};

/*******************************************
 * DEQUE :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Deque <T> :: Deque(const Deque <T> & rhs) throw (const char *)
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
      throw "ERROR: Unable to allocate new buffer for deque";
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
 * DEQUE : NON-DEFAULT CONSTRUCTOR
 * Preallocate the deque to "capacity"
 **********************************************/
template <class T>
Deque <T> :: Deque(int capacity) throw (const char *)
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

   // initialize the deque by calling the default constructor
   for (int i = 0; i < capacity; i++)
      data[i] = T();
}

/***************************************************
 * DEQUE :: push_back
 * places data at the top of the deque
 **************************************************/
template <class T>
void Deque <T> :: push_back(const T & t)
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

      // add the incoming data onto the deque
      data[last] = t;
      last = (last + 1) % cap;
      numItems++;

      // NOTE: No need to free up copyData's space because
      //       it will be used again the next time numItems
      //       is the same as cap
   }
   catch (std::bad_alloc)
   {
      throw "Unable to allocate a new buffer for Deque";
   }

}

/***************************************************
 * DEQUE :: push_front
 * places data at the top of the deque
 **************************************************/
template <class T>
void Deque <T> :: push_front(const T & t)
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

      // add the incoming data onto the front of the deque
      first = first - 1;
      if (first < 0)
      {
         first = cap - 1;
      }
      data[first] = t;
      numItems++;

      // NOTE: No need to free up copyData's space because
      //       it will be used again the next time the cap
      //       is met
   }
   catch (std::bad_alloc)
   {
      throw "Unable to allocate a new buffer for Deque";
   }
}

/***************************************************
 * DEQUE :: pop_back
 * Removes an item from the end of the deque
 **************************************************/
template <class T>
void Deque <T> :: pop_back() 
{
   if (numItems > 0)
   {
      last = last - 1;
      if (last < 0)
      {
         last = last + cap;
      }
      numItems--;
   }
   else
   {
      throw "ERROR: unable to pop from the back of empty deque";
   }
}

/***************************************************
 * DEQUE :: pop_front
 * Removes an item from the end of the deque
 **************************************************/
template <class T>
void Deque <T> :: pop_front() 
{
   if (numItems > 0)
   {
      first = (first + 1) % cap;
      numItems--;
   }
   else
   {
      throw "ERROR: unable to pop from the front of empty deque";
   }
}

/***************************************************
 * DEQUE :: back
 * Return the item at the back of the deque
 **************************************************/
template <class T>
T & Deque <T> :: back() const 
{
   // if there is nothing in the deque...
   if (data == NULL || numItems == 0)
   {
      // leave the function and throw the error
      throw "ERROR: unable to access data from an empty deque";
   }
   else if (last == 0)
   {
      // otherwise show the last item on the deque
      return data[cap - 1];
   }
   else
   {
      return data[last - 1];
   }
   
}

/***************************************************
 * DEQUE :: front
 * Return the item at the front of the deque
 **************************************************/
template <class T>
T & Deque <T> :: front() const
{
   if (data == NULL || numItems == 0)
   {
      // leave the function and throw the error
      throw "ERROR: unable to access data from an empty deque";
   }
   else
   {
      // otherwise show the first item on the deque
      return data[first];
   }
}

/***************************************************
 * DEQUE :: OPERATOR =
 * overloads the = operator
 **************************************************/
template <class T>
Deque <T> & Deque <T> :: operator=(const Deque <T> & rhs) throw (const char*)
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
      throw "ERROR: Unable to allocate a new buffer for Deque";
   }
}


#endif // DEQUE_H
