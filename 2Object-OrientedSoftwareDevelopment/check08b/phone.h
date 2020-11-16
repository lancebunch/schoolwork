/***************
 * phone.h
 ***************/

#ifndef PHONE_H
#define PHONE_H

// TODO: Put your phone class definition here...
class Phone
{
   protected:
      int areaCode;
      int prefix;
      int suffix;
   public:
      void promptNumber();
      void display();
};
#endif
