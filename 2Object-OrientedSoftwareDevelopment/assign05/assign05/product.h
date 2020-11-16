/***************************************************************
 * File: product.h
 * Author: Lance Bunch
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
   public:
      //Constructors
      Product();
      Product(string name, string description, 
               double basePrice, float weight);

      //Accessors
      string getName() const { return name; }
      string getDescription() const { return description; }
      double getBasePrice() const { return basePrice; }
      float getWeight() const { return weight; }

      //Mutators
      void setName(string name);
      void setDescription(string description);
      void setBasePrice(double basePrice);
      void setWeight(float weight);

      //Method Functions
      double getSalesTax();
      double getShippingCost();
      double getTotalPrice();
      void adProfile();
      void invLineItem();
      void receipt();
};
#endif
