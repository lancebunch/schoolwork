// File: address.h

#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
#include <iostream>
using namespace std;

// Put your Address class here
class Address
{
	private:
		string street;
		string city;
		string state;
		string zip;
	public:
		Address();
		Address(string street, string city, string state, string zip);

		string getStreet() const { return street; }
		string getCity() const { return city; }
		string getState() const { return state; }
		string getZip() const { return zip; }

		void setStreet(string street);
		void setCity(string city);
		void setState(string state);
		void setZip(string zip);

		void display();
};
#endif
