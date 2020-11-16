// File: customer.h

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "address.h"
#include <string>
#include <iostream>
using namespace std;

// put your Customer class here
class Customer
{
	private:
		string name;
		Address address;
	public:
		Customer();
		Customer(string name, Address address);

		string getName() const { return name; }
		Address getAddress() const { return address; }

		void setName(string name);
		void setAddress(Address address);

		void display();
};
#endif
