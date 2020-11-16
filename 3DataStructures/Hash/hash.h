/***********************************************************************
* Header:
*    hash.h
* Summary:
*   Contains the class definition of the Hash.
*
*    This will contain the class definition of:
*        Hash         : A class that is used in hash tables
* Author
*    Lance Bunch
************************************************************************/
#ifndef HASH_H
#define HASH_H
#include <vector>

using namespace std;

/******************************************************************
 * Class :: HASH
 * Conatins the elements and proptypes for the Hash class
 *****************************************************************/
template <class T>
class Hash
{
private:
   int numElements;
   int numBuckets;
   vector<vector<T>> table;

public:
   // Sets the number of buckets
   Hash(int numBuckets) throw(const char *);

   // Copy constructor
   Hash(const Hash<T> &rhs) throw(const char *);

   // Assignment Operator
   Hash<T> &operator=(Hash<T> &rhs) throw(const char *);

   // Determines whether the cureent Hash is empty
   bool empty() { return numElements == 0; }

   // Return the number of elements in the Hash
   int size() { return numElements; }

   // Returns the number of buckets in the Hash
   int capacity() const { return numBuckets; }

   // Clear the Hash, elements are removed and everything is set to 0
   void clear();

   // Used to find an element, returns true if found, false if not
   bool find(T &t);

   // Puts a new item in the Hash
   void insert(const T t);

   //
   virtual int hash(const T &t) const = 0;
};

/******************************************************************
 * Non-Default Constructor
 * Sets numBuckets equal to the data passed in
 *****************************************************************/
template <class T>
Hash<T>::Hash(int numBuckets) throw(const char *)
{
   try
   {
      this->numBuckets = numBuckets;
      numElements = 0;
      table.resize(numBuckets);
   }
   catch (const std::exception &e)
   {
      throw "ERROR: Unable to allocate memory for the hash";
   }
}

/******************************************************************
 * Copy Constructor
 * Creates a new Hash and makes it the same as the Hash passed in
 *****************************************************************/
template <class T>
Hash<T>::Hash(const Hash<T> &rhs) throw(const char *)
{
   try
   {
      numBuckets = rhs.numBuckets;
      numElements = rhs.numElements;
      table = rhs.table;
   }
   catch (const std::exception &e)
   {
      throw "ERROR: Unable to allocate memory for the hash";
   }
}

/******************************************************************
 * Operator :: =
 * Assigns a current Hash the values of another Hash
 *****************************************************************/
template <class T>
Hash<T> &Hash<T>::operator=(Hash<T> &rhs) throw(const char *)
{
   clear();
   numBuckets = rhs.numBuckets;
   numElements = rhs.numElements;
   table = rhs.table;
}

/******************************************************************
 * Function :: CLEAR
 * Clears the contents of Hash
 *****************************************************************/
template <class T>
void Hash<T>::clear()
{
   numElements = 0;
   table.clear();
}

/******************************************************************
 * Function :: FIND
 * A bool to tell if the value passed in exists in the Hash or not
 *****************************************************************/
template <class T>
bool Hash<T>::find(T &t)
{
   int i = hash(t);

   for (int j = 0; j < table[i].size(); j++)
   {
      if (table[i][j] == t)
      {
         return true;
      }
   }
   return false;
}

/******************************************************************
 * Function :: INSERT
 * Places another value on the Hash
 *****************************************************************/
template <class T>
void Hash<T>::insert(const T t)
{
   int i = hash(t);
   table[i].push_back(t);
   numElements++;
}

#endif