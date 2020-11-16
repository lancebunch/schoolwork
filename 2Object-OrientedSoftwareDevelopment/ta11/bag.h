#ifndef BAG_H
#define BAG_H

/***********************************************************
 * Class: Bag
 * Description: Holds ints...for now
 ***********************************************************/
class Bag
{
private:
   int capacity;
   int size;
   int currentAddIndex;
   int* data;

public:
   Bag(); // Default constructor
				
   // Getters
   int getCapacity();
   int getCount();

   int getItem(int index);
   void addItem(int item);
};

#endif

Bag::Bag()
{

   data = new int[5];
   capacity = 5;
   size = 0;
   currentAddIndex = 0;
}

int Bag::getCount()
{
   return size;
}

int Bag::getCapacity()
{
   return capacity;
}

void Bag::getItem(int index)
{
   return *data[index];
}

void Bag::addItem(int value)
{
   if (currentAddIndex != capacity)
   {
      data[currentAddIndex] = value;
      currentAddIndex++;
      size++;
   }
}