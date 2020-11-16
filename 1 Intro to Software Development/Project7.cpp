/***********************************************************************
* Program:
*    Project07, Calendar Project
*    Sister Hansen, CS124
* Author:
*    Lance Bunch
* Summary:     
*  This takes a users year and month to display a calendar
*  of the iven month in the given year.
*    Estimated:  3.0 hrs   
*    Actual:     4.0 hrs
*   The hardest part of this project was at first the
*  computeOffset function, but once I got that figured
*  out the hardest part was just figuring out the leapYear.
*  Not because I didn't understand the logic, but because
*  I didn't understand leap years.
**************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

//Prototypes so each function can call their necessary functions
int getMonth();
int getYear();
int computeOffset(int month, int year);
int numDaysInYear(int year);
int numDaysInMonth(int year, int month);
bool isLeapYear(int year);
void display(int year, int month, int offset);
void displayHeader(int month, int year);
void displayTable(int numDays, int offset);



/**********************************************************************
 *getMonth prompts and ensures a valid month of the year.
 ***********************************************************************/
int getMonth()
{
   int month;
   cout << "Enter a month number: ";
   cin >> month;
   while (month < 1 || month > 12)
   {
      cout << "Month must be between 1 and 12.\n";
      cout << "Enter a month number: ";
      cin >> month;
   }
   return month;
}

/*******************************************************
 * getYear prompts and ensures a valid year.
 ******************************************************/
int getYear()
{
   int year;
   cout << "Enter year: ";
   cin >> year;
   while (year < 1753)
   {
      cout << "Year must be 1753 or later.\n";
      cout << "Enter year: ";
      cin >> year;
   }
   return year;
}

/*************************************************************************
 *Runs through how many days have passed since January 1st, 1753
 ************************************************************************/
int computeOffset(int month, int year)
{
   int numDays = 0;
   int yearCount;

   for (yearCount = 1753; yearCount < year; yearCount++) 
      numDays += (numDaysInYear(yearCount));

   int monthCount;
   for (monthCount = 1; monthCount < month; monthCount++)
      numDays += (numDaysInMonth(year, monthCount));
   
   return (numDays % 7);
}

/*******************************************************************
 *numDaysInYear calls isLeapYear to test if it needs to return 365 or 366
 ******************************************************************/
int numDaysInYear(int year)
{
   bool leapYear = isLeapYear(year);

   if (leapYear)
      return 366;
   else
      return 365;
}

/**************************************************************************
 *numDaysInMonth returns a certain number of days based off the month
 *************************************************************************/
int numDaysInMonth(int year, int month)
{
   bool leapYear = isLeapYear(year);

   if (month == 1)
      return 31;
   if (month == 2)
   {
      if (leapYear)
         return 29;
      else
         return 28;
   }
   if (month == 3)
      return 31;
   if (month == 4)
      return 30;
   if (month == 5)
      return 31;
   if (month == 6)
      return 30;
   if (month == 7 || month == 8)
      return 31;
   if (month == 9)
      return 30;
   if (month == 10)
      return 31;
   if (month == 11)
      return 30;
   if (month == 12)
      return 31;
}

/*************************************************************************
 *isLeapYear tests if a given year is a leap year or not
 ************************************************************************/
bool isLeapYear(int year)
{
   if (year % 4 != 0)
      return false;
   else if (year % 100 != 0)
      return true;
   else if (year % 400 != 0)
      return false;
   else
      return true;
}

/*************************************************************************
 *Calls other functions to display everything together.
 ************************************************************************/
void display(int year, int month, int offset)
{
   displayHeader(month, year);
   int numDays = numDaysInMonth(year, month);
   displayTable(numDays, offset);
}

/************************************************************************
 *Displays the header before the calendar in an orderly fashion.
 ***********************************************************************/
void displayHeader(int month, int year)
{
   cout << endl;
   if (month == 1)
      cout << "January";
   if (month == 2)
      cout << "February";
   if (month == 3)
      cout << "March";
   if (month == 4)
      cout << "April";
   if (month == 5)
      cout << "May";
   if (month == 6)
      cout << "June";
   if (month == 7)
      cout << "July";
   if (month == 8)
      cout << "August";
   if (month == 9)
      cout << "September";
   if (month == 10)
      cout << "October";
   if (month == 11)
      cout << "November";
   if (month == 12)
      cout << "December";
   cout << ", " << year << endl;
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa" << endl;
}

/***********************************************************************
 *Gathers all the info together to display a calendar.
 **********************************************************************/
void displayTable(int numDays, int offset)
{
   if (offset < 6)
   {
      int i = 0;
      cout << setw(4);
      for (i = 0; i<= offset; i++)
         cout << "  " << setw(4);
   }
   offset++;

   for (int i = 1; i <= numDays; i++)
   {
      cout << setw(4) << i;
      if ((i + offset) % 7 == 0 || i == numDays)
         cout << endl;
   }
}

/***********************************************************************
 *Initiates the program by promting the user for the month and year.
 **********************************************************************/
int main()
{
  int month = getMonth();
  int year = getYear();
  int offset = computeOffset(month, year);
  display(year, month, offset);
  return 0;
}
