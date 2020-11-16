// File: order.cpp

#include "order.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Put your the method bodies for your order class here
/*****************************************************************
 * Default Constructor
 * Purpose: sets the BasePrice to whatever is inputed
 * **************************************************************/
Order :: Order()
{
    setQuantity(0);
}

/*****************************************************************
 * Non Default Constructor
 * Purpose: sets the Product, quantity, and Customer
 * **************************************************************/
Order :: Order(Product product, int quantity, Customer customer)
{
    setProduct(product);
    setQuantity(quantity);
    setCustomer(customer);
}

/*****************************************************************
 * Mutator: setProduct
 * Purpose: sets the Product to whatever is inputed
 * **************************************************************/
void Order :: setProduct(Product product)
{
    this->product = product;
}

/*****************************************************************
 * Mutator: setQuantity
 * Purpose: sets the quantity to whatever is inputed
 * **************************************************************/
void Order :: setQuantity(int quantity)
{
    this->quantity = quantity;
}

/*****************************************************************
 * Mutator: setCustomer
 * Purpose: sets the Customer to whatever is inputed
 * **************************************************************/
void Order :: setCustomer(Customer customer)
{
    this->customer = customer;
}

/*****************************************************************
 * Function: getShippingZip
 * Purpose: accesses the zip code from the customer's address
 * **************************************************************/
string Order :: getShippingZip()
{
    return customer.getAddress().getZip();
}

/*****************************************************************
 * Function: getTotalPrice
 * Purpose: Gets the total price of the product
 * **************************************************************/
double Order :: getTotalPrice()
{
	double totalPrice = 0;
   totalPrice = quantity * product.getTotalPrice();
	return totalPrice;
}

/*****************************************************************
 * Function: displayShippingLabel
 * Purpose: Calls the customer's display method
 * **************************************************************/
void Order :: displayShippingLabel()
{
    customer.display();
}

/*****************************************************************
 * Function: displayInformation
 * Purpose: Displays the customer's name, 
 *          the product's name, and the total price
 * **************************************************************/
void Order :: displayInformation()
{
   cout.setf(ios::fixed); 
	cout.setf(ios::showpoint); 
	cout.precision(2);
   cout << customer.getName() << endl 
        << product.getName() << endl
        << "Total Price: $" << getTotalPrice() << endl;
}