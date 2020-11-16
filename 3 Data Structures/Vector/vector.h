/***********************************************************************
* Header:
*    Vector
* Summary:
*    This class contains the notion of a vector: a bucket to hold
*    data for the user. This is just a starting-point for more advanced
*    constainers such as the vector, set, stack, queue, deque, and map
*    which we will build later this semester.
*
*    This will contain the class definition of:
*        Vector         : A class that holds stuff
*        VectorIterator : An interator through Vector
* Author
*    Br. Helfrich
*    Modified by Lance Bunch
************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>

// forward declaration for VectorIterator
template <class T>
class VectorIterator;

/************************************************
 * VECTOR
 * A class that holds stuff
 ***********************************************/
template <class T>
class Vector
{
public:
   // default constructor : empty and kinda useless
   Vector() : numItems(0), cap(0), data(NULL) {}

   // copy constructor : copy it
   Vector(const Vector & rhs) throw (const char *);
   
   // non-default constructor : pre-allocate
   Vector(int capacity) throw (const char *);
   
   // destructor : free everything
   ~Vector()           { if (cap == 0) delete [] data; }
   
   // is the vector currently empty
   bool empty() const  { return numItems == 0;         }

   // remove all the items from the vector
   void clear()        {  numItems = 0;                }

   // how many items are currently in the vector?
   int size() const    { return numItems;              }

   // how many items can the vector hold?
   int capacity() const { return cap;                  }

   // adds a new piece of data at the back of the vector
   void push_back(const T & t) throw (const char *);

   // add an item to the vector
   void insert(const T & t) throw (const char *);

   // overloading square bracket operators
   T & operator[](int index) const throw (const char*);
   T & operator[](int index) throw (const char*);

   Vector <T> & operator=(const Vector <T> & rhs) throw (const char*);
   
   // return an iterator to the beginning of the list
   VectorIterator <T> begin() { return VectorIterator<T>(data); }

   // return an iterator to the end of the list
   VectorIterator <T> end() { return VectorIterator<T>(data + numItems);}
   
private:
   T * data;          // dynamically allocated array of T
   int numItems;      // how many items are currently in the Vector?
   int cap;           // how many items can I put on the Vector before full?
};

/**************************************************
 * VECTOR ITERATOR
 * An iterator through Vector
 *************************************************/
template <class T>
class VectorIterator
{
  public:
   // default constructor
  VectorIterator() : p(NULL) {}

   // initialize to direct p to some item
  VectorIterator(T * p) : p(p) {}


   // not equals operator
   bool operator != (const VectorIterator & rhs) const
   {
      return rhs.p != this->p;
   }

   // dereference operator
   T & operator * ()
   {
      return *p;
   }

   // prefix increment
   VectorIterator <T> & operator ++ ()
   {
      p++;
      return *this;
   }

   // postfix increment
   VectorIterator <T> operator++(int postfix)
   {
      VectorIterator tmp(*this);
      p++;
      return tmp;
   }
   
  private:
   T * p;
};

/*******************************************
 * VECTOR :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Vector <T> :: Vector(const Vector <T> & rhs) throw (const char *)
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
 * VECTOR : NON-DEFAULT CONSTRUCTOR
 * Preallocate the vector to "capacity"
 **********************************************/
template <class T>
Vector <T> :: Vector(int capacity) throw (const char *)
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
      throw "ERROR: Unable to allocate buffer";
   }

      
   // copy over the stuff
   this->cap = capacity;
   this->numItems = 0;

   // initialize the vector by calling the default constructor
   for (int i = 0; i < capacity; i++)
      data[i] = T();
}

/***************************************************
 * VECTOR :: push_back
 * places data at the back of the vector
 **************************************************/
template <class T>
void Vector <T> :: push_back(const T & t) throw (const char *)
{
   try
   {
      assert(cap >= 0 && numItems <= cap);

      // if there is no more room in the vector...
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

         // allocate and increase data's capacity
         data = new T[cap];

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
      throw "Unable to allocate a new buffer for Vector";
   }

}

/***************************************************
 * VECTOR :: INSERT
 * Insert an item on the end of the vector
 **************************************************/
template <class T>
void Vector <T> :: insert(const T & t) throw (const char *)
{
   // do we have space?
   if (cap == 0 || cap == numItems)
      throw "ERROR: Insufficient space";
   
   // add an item to the end
   data[numItems++] = t;
}

/***************************************************
 * VECTOR :: OPERATOR[]
 * overloads the [] operator as a const
 **************************************************/
template <class T>
T & Vector <T> :: operator[](int index) const throw (const char*)
{
   if (index < 0 || index >= numItems)
      throw "ERROR: Invalid index";
   return data[index];
}

/***************************************************
 * VECTOR :: OPERATOR[]
 * overloads the [] operator
 **************************************************/
template <class T>
T & Vector <T> :: operator[](int index) throw (const char*)
{
   if (index < 0 || index >= numItems)
      throw "ERROR: Invalid index";
   return data[index];
}

/***************************************************
 * VECTOR :: OPERATOR =
 * overloads the = operator
 **************************************************/
template <class T>
Vector <T> & Vector <T> :: operator=(const Vector <T> & rhs) throw (const char*)
{
   try
   {
      // if nothing has been allocated..
      if (rhs.data == NULL)
      {
         // ...data then has no allocation
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
      throw "Unable to allocate a new buffor for Vector";
   }
}


#endif // VECTOR_H
