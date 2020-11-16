/****************
 * smartphone.h
 ****************/

#ifndef SMARTPHONE_H
#define SMARTPHONE_H

#include "phone.h"
#include <iostream>
#include <string>

using namespace std;


// TODO: Put your SmartPhone definition here
class SmartPhone : public Phone
{
   private:
      string email;
   public:
      void prompt();
      void display();
};
#endif
