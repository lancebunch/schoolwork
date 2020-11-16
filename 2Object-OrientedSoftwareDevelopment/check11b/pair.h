/*****************************************************
 * File: pair.h
 *
 * Purpose: Defines a Pair template class that can hold
 *   two items of arbitrary data types.
 ******************************************************/

#ifndef PAIR_H
#define PAIR_H

#include <iostream>

using namespace std;
// TODO: Fill in this class
// Put all of your method bodies right in this file
template<class T1, class T2>
class Pair
{
   private:
      T1 first;
      T2 second;

   public:
      T1 getFirst()  const { return first; }
      T2 getSecond() const { return second; }

      void setFirst(const T1 &first)   { this->first = first; }
      void setSecond(const T2 &second) { this->second = second; }

      void display() const;
};

template<class T1, class T2>
void Pair<T1,T2>::display() const
{
   cout << first << " - " << second;
}

#endif // PAIR_H
