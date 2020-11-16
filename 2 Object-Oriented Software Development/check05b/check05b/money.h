/******************
 * File: money.h
 ******************/
#ifndef MONEY_H
#define MONEY_H

using namespace std;

class Money
{
private:
   int dollars;
   int cents;

public:
   Money();
   Money(const int dollars);
   Money(const int dollars, const int cents);
   
   void prompt();

   int getDollars() const { return dollars; }
   int getCents() const { return cents; }

   void setDollars(int dollars);
   void setCents(int cents);

   void display() const;
};

#endif
