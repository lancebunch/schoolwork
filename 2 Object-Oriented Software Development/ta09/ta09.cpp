#include <iostream>
#include <string>
using namespace std;

class Employee
{
   protected:
      string name;
   public:
      void setName(string name) { this->name = name; }
      string getName() { return name; }

      //displays the name
      virtual void display() { cout << name << endl; }
};

class HourlyEmployee: public Employee
{
   private:
      int hourlyWage;
   public:
      void setHourlyWage(int hourlyWage) { this->hourlyWage = hourlywage; }
      int getHourlyWage() { return hourlyWage; }

      //should override the display function to "John - $8/hour"
      virtual void display(); 
};

class SalaryEmployee: public Employee
{
   private:
      int salary;
   public:
      void setSalary(int salary) { this->salary = salary; }
      int getSalary() { return salary; }

      //override display format to "John - $50000/year"
      virtual void display();
};

main()
{

}