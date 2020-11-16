/***************************************************************
 * File: product.h
 * Author: (your name here)
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>
using namespace std;
/***************************************************************
 * Class: Product
 * Purpose: Defines a class with its member variable and
 *          Prototype functions.
 * ************************************************************/
class Product
{
   private:
      string name;
      double basePrice;
      float weight;
      string description;
      void formatting();
   public:
      void prompt();
      double getSalesTax();
      double getShippingCost();
      void getTotalPrice();
      void adProfile();
      void invLineItem();
      void receipt();
};
#endif
