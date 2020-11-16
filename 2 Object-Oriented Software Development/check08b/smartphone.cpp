/*******************
 * smartphone.cpp
 *******************/

#include "smartphone.h"
#include <iostream>
#include <string>

using namespace std;

// TODO: Put your SmartPhone methods here
void SmartPhone :: prompt()
{
   Phone :: promptNumber();
   cout << "Email: ";
   cin >> email;
   cin.ignore();
}

void SmartPhone :: display()
{
   Phone :: display();
   cout << email << endl;
}