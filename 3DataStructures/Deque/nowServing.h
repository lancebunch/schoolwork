/***********************************************************************
 * Header:
 *    NOW SERVING
 * Summary:
 *    This will contain just the prototype for nowServing(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Lance Bunch
 ************************************************************************/

#ifndef NOW_SERVING_H
#define NOW_SERVING_H

#include <iostream>
#include <string>
#include "deque.h"     // for DEQUE

using namespace std;

// the interactive nowServing program
void nowServing();

struct Info
{
   string course;
   string name;
   int neededTime = 0;
   bool emergency = false;
};

#endif // NOW_SERVING_H

