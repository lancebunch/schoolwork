// File: order.h

#ifndef ORDER_H
#define ORDER_H

#include "product.h"
#include "customer.h"
#include <string>
#include <iostream>
using namespace std;

// Put your Order class here
class Order
{
    private:
        Product product;
        int quantity;
        Customer customer;
    public:
        //Constructors
        Order();
        Order(Product product, int quantity, Customer customer);

		  //Accessors
        Product getProduct() const { return product; }
        int getQuantity() const { return quantity; }
        Customer getCustomer() const { return customer; }
		  
		  //Mutators
        void setProduct(Product product);
        void setQuantity(int quantity);
        void setCustomer(Customer customer);

        string getShippingZip();
        double getTotalPrice();
        void displayShippingLabel();
        void displayInformation();

};

#endif
