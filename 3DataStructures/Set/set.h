/***********************************************************************
* Header:
*    Set
* Summary:
*    This class contains the notion of a set: a bucket to hold
*    data for the user. This is just a starting-point for more advanced
*    constainers such as the vector, set, stack, queue, deque, and map
*    which we will build later this semester.
*
*    This will contain the class definition of:
*        Set         : A class that holds stuff
*        SetIterator : An interator through Set
* Author
*    Br. Helfrich
*    Modified by Lance Bunch
************************************************************************/

#ifndef SET_H
#define SET_H

#include <cassert>
using namespace std;

// forward declaration for SetIterator
template <class T>
class SetIterator;

/************************************************
 * SET
 * A class that holds stuff
 ***********************************************/
template <class T>
class Set
{
public:
   // default constructor : empty and kinda useless
   Set() : numItems(0), cap(0), data(NULL) {}

   // copy constructor : copy it
   Set(const Set & rhs) throw (const char *);
   
   // non-default constructor : pre-allocate
   Set(int capacity) throw (const char *);
   
   // destructor : free everything
   ~Set()           { if (cap == 0) delete [] data; }
   
   // is the set currently empty
   bool empty() const  { return numItems == 0;         }

   // remove all the items from the set
   void clear()        {  numItems = 0;                }

   // how many items are currently in the set?
   int size() const    { return numItems;              }

   // how many items can the set hold?
   int capacity() const { return cap;                  }

   // used to give new space if needed
   void realloc();

   // essentially a binary search
   int find(const T & t);

   // add an item to the set
   void insert(const T & t) throw (const char *);

   // deletes an element in the set
   void erase(int index) throw (const char*);

   // insertion operator
   Set <T> & operator=(const Set <T> & rhs) throw (const char*);

   // The intersection operator
   Set <T> operator&&(const Set <T> & rhs) throw (const char*);

   // The union operator
   Set <T> operator||(const Set <T> & rhs) throw (const char*);

   void display(int i)
   {
     cout << data[i];
   }
   
   // return an iterator to the beginning of the list
   SetIterator <T> begin() { return SetIterator<T>(data); }

   // return an iterator to the end of the list
   SetIterator <T> end() { return SetIterator<T>(data + numItems);}
   
private:
   T * data;          // dynamically allocated array of T
   int numItems;      // how many items are currently in the Set?
   int cap;           // how many items can I put on the Set before full?
};

/**************************************************
 * SET ITERATOR
 * An iterator through SET
 *************************************************/
template <class T>
class SetIterator
{
  public:
   // default constructor
   SetIterator() : p(NULL) {}

   // initialize to direct p to some item
   SetIterator(T * p) : p(p) {}


   // not equals operator
   bool operator != (const SetIterator & rhs) const
   {
      return rhs.p != this->p;
   }

   // dereference operator
   T & operator * ()
   {
      return *p;
   }

   // prefix increment
   SetIterator <T> & operator ++ ()
   {
      p++;
      return *this;
   }

   // postfix increment
   SetIterator <T> operator++(int postfix)
   {
      SetIterator tmp(*this);
      p++;
      return tmp;
   }
   
  private:
   T * p;
};

/*******************************************
 * SET :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Set <T> :: Set(const Set <T> & rhs) throw (const char *)
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
 * SET : NON-DEFAULT CONSTRUCTOR
 * Preallocate the set to "capacity"
 **********************************************/
template <class T>
Set <T> :: Set(int capacity) throw (const char *)
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

   // initialize the set by calling the default constructor
   for (int i = 0; i < capacity; i++)
      data[i] = T();
}

/**********************************************
 * SET : REALLOC
 * Reallocated data if necessary. Called everytime
 *    insert is called.
 **********************************************/
template <class T>
void Set <T> :: realloc()
{
   // if there is no more room in the set...
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
   // NOTE: No need to free up copyData's space because
   //       it will be used again the next time numItems
   //       is the same as cap
}

/**********************************************
 * SET : FIND
 * A binary search to find where to place data
 **********************************************/
template <class T>
int Set <T> :: find (const T & t)
{
   int iBegin = 0;
   int iEnd = numItems - 1;
   int iMiddle = 0;

   while (iBegin <= iEnd)
   {
      iMiddle = (iBegin + iEnd)/2;
      if (t == data[iMiddle])
      {
         return iMiddle;
      }
      else if (t < data[iMiddle])
      {
         iEnd = iMiddle - 1;
      }
      else
      {
         iBegin = iMiddle + 1;
      }
   }
   return -1;
}

/***************************************************
 * SET :: insert
 * uses binary search to place incoming data in correct order
 **************************************************/
template <class T>
void Set <T> :: insert(const T & t) throw (const char *)
{
   try
   {
      assert(cap >= 0 && numItems <= cap);

      int iInsert = find(t);

      realloc();

      if (iInsert == -1)
      {
         int i = numItems - 1;

         while (i >= 0 && data[i] > t)
         {
            data[i + 1] = data[i];
            i--;
         }
         data[i + 1] = t;
         numItems++;
      }
   }
   catch (std::bad_alloc)
   {
      throw "Unable to allocate a new buffer for Set";
   }

}

/***************************************************
 * SET :: erase
 * uses given index to shift everything up by one
 **************************************************/
template <class T>
void Set <T> :: erase(int index) throw (const char*)
{
   if (index > 0)
   {
      int i = numItems - 1;

      while (index < i)
      {
         data[index] = data[index + 1];
         index++;
      }
      numItems--;
   }
}

/***************************************************
 * SET :: OPERATOR =
 * overloads the = operator
 **************************************************/
template <class T>
Set <T> & Set <T> :: operator=(const Set <T> & rhs) throw (const char*)
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
      throw "Unable to allocate a new buffor for Set";
   }
}


/***************************************************
 * SET :: OPERATOR &&
 * makes an intersection operator
 *    set of elements that two sets share in common
 **************************************************/
template <class T>
Set <T> Set <T> :: operator&&(const Set <T> & rhs) throw (const char*)
{
   Set <T> setReturn;

   for (int iLhs = 0; iLhs < this->numItems; iLhs++)
   {
      for (int iRhs = 0; iRhs < rhs.numItems;)
      {
         if (this->data[iLhs] == rhs.data[iRhs])
         {
            setReturn.insert(this->data[iLhs]);
         }
         iRhs++;
      }
   }
   return setReturn;
// This is the more efficient way, though it doesn't work quite yet
   // int iLhs = 0;
   // int iRhs = 0;
   // while (iLhs < this->numItems || iRhs < rhs.numItems)
   // {
   //    if (iLhs == this->numItems)
   //    {
   //       return setReturn;
   //    }
   //    else if (iRhs == rhs.numItems)
   //    {
   //       return setReturn;
   //    }
   //    else if (this->data[iLhs] == rhs.data[iRhs])
   //    {
   //       setReturn.insert(this->data[iLhs]);
   //       iLhs++;
   //       iRhs++;
   //    }
   //    else if (this->data[iLhs] < rhs.data[iRhs])
   //    {
   //       iLhs++;
   //    }
   //    else
   //    {
   //       iRhs++;
   //    }
   //    return setReturn;
   // }
}

/***************************************************
 * SET :: OPERATOR ||
 * Make a union operator
 *    consists of elements either in lhs or rhs
 **************************************************/
template <class T>
Set <T> Set <T> :: operator||(const Set <T> & rhs) throw (const char*)
{
   // create a temporary copy set from 'setA' and insert
   // items from the rhs into the copied set. Then return that set.
   Set <T> setReturn;

   for (int iLhs = 0; iLhs < this->numItems; iLhs++)
   {
      for (int iRhs = 0; iRhs < rhs.numItems;)
      {
         if (this->data[iLhs] == rhs.data[iRhs])
         {
            iRhs++;
         }
         else
         {
            setReturn.insert(this->data[iLhs]);
            setReturn.insert(rhs.data[iRhs]);
            iRhs++;
         }
      }
   }
   return setReturn;
// This is the more efficient way, though it doesn't work quite yet
   // int iLhs = 0;
   // int iRhs = 0;
   // while (iLhs < this->numItems || iRhs < rhs.numItems)
   // {
   //    if (iLhs == this->numItems)
   //    {
   //       setReturn.insert(rhs.data[iRhs++]);
   //    }
   //    else if (iRhs == rhs.numItems)
   //    {
   //       setReturn.insert(this->data[iLhs++]);
   //    }
   //    else if (this->data[iLhs] == rhs.data[iRhs])
   //    {
   //       setReturn.insert(this->data[iLhs]);
   //       iLhs++;
   //       iRhs++;
   //    }
   //    else if (this->data[iLhs] < rhs.data[iRhs])
   //    {
   //       setReturn.insert(this->data[iLhs++]);
   //    }
   //    else
   //    {
   //       setReturn.insert(rhs.data[iRhs++]);
   //    }
   //    return setReturn;
   // }
}
   
#endif // SET_H
