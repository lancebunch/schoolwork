/***********************************************************************
* Program:
*    Project 04, Monthly Budget
*    Sister Hansen, CS124 
* Author:
*    Lance Bunch
* Summary: 
*    This is just a simple program to take a users input of budget and display it nicely and uniformly in a table that I set up. With that I need to make sure that I specify that it is an integer that I am getting from the user. I created my own variable names and sotred them for use later in the table itself.
*    Estimated: 4.0 hrs   
*    Actual:     3.0 hrs
*      The most difficult part was getting the aligning right. It took a couple different tries before I got everything under control.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 The function main runs everything in the program since there isn't any other functions to run.
It was really fun to put together. Especailly as I am starting to understand more what each command/function
does. I am excited to see where else this class will take me.
 ***********************************************************************/
double getIncome()
{
   double monthIn;
   cout << "\tYour monthly income: ";
   cin >> monthIn;
   return monthIn;
}

double getBudgetLiving()
{
   double budLiv;
   cout << "\tYour budgeted living expenses: ";
   cin >> budLiv;
   return budLiv;
}

double getActualLiving()
{
   double actLiv;
   cout << "\tYour actual living expenses: ";
   cin >> actLiv;
   return actLiv;
}

double getActualTax()
{
   double actTax;
   cout << "\tYour actual taxes withheld: ";
   cin >> actTax;
   return actTax;
}

double getActualTithing()
{
   double actTith;
   cout << "\tYour actual tithe offerings: ";
   cin >> actTith;
   return actTith;
}

double getActualOther()
{
   double othExp;
   cout << "\tYour actual other expenses: ";
   cin >> othExp;
   return othExp;
}

double actDiff(double monthIn, double actLiv, double actTax, double actTith, double othExp)
{
   return double(monthIn - actLiv - actTax - actTith - othExp);
}

double computeTax(double monthIn)
{
   double yearlyIncome;
   double yearlyTax;
   double monthlyTax;
  
   
   yearlyIncome = monthIn * 12;

   if (0 <= yearlyIncome && yearlyIncome < 15100)
      yearlyTax = yearlyIncome * 0.10;
   else if (15100 <= yearlyIncome && yearlyIncome < 61300)
      yearlyTax = 1510 + 0.15 * (yearlyIncome - 15100);
   else if (61300 <= yearlyIncome && yearlyIncome < 123700)
      yearlyTax = 8440 + 0.25 *(yearlyIncome - 61300);
   else if (123700 <= yearlyIncome && yearlyIncome < 188450)
      yearlyTax = 24040 + 0.28 * (yearlyIncome - 123700);
   else if (188450 <= yearlyIncome && yearlyIncome < 336550)
      yearlyTax = 42170 + 0.33 * (yearlyIncome - 188450);
   else if (336550 <= yearlyIncome)
      yearlyTax = 91043 + 0.35 * (yearlyIncome - 336550);
   monthlyTax = yearlyTax / 12;
   return monthlyTax;
}

int main()
{
   cout.setf(ios::fixed);
   cout.precision(2);

   //This sets all my variables as large integers
   double monthIn;
   double budLiv;
   double actLiv;
   double actTax;
   double actTith;
   double othExp;
   
   //output instructions to user
   cout << "This program keeps track of your monthly budget\n"
        << "Please enter the following:\n";
   monthIn = getIncome(); 
   budLiv = getBudgetLiving();
   actLiv = getActualLiving();
   actTax = getActualTax();
   actTith = getActualTithing();
   othExp = getActualOther();
   cout << "\nThe following is a report on your monthly expenses\n";
   cout << "\tItem                  Budget          Actual\n";
   cout << "\t=============== =============== ===============\n";
   cout << "\tIncome          $" << setw(11) << monthIn
        << "    $" << setw(11) << monthIn << endl;
   cout << "\tTaxes           $" << setw(11) << computeTax(monthIn)
        << "    $" << setw(11) << actTax << endl;
   cout << "\tTithing         $" << setw(11) << monthIn/10
        << "    $" << setw(11) << actTith << endl;
   cout << "\tLiving          $" << setw(11) << budLiv
        << "    $" << setw(11) << actLiv << endl;
   cout << "\tOther           $" << setw(11)
        << (monthIn - (monthIn/10) - budLiv - computeTax(monthIn))
        << "    $" << setw(11) << othExp << endl;
   cout << "\t=============== =============== ===============\n";
   cout << "\tDifference      $" << setw(11) << 0.00
        << "    $" << setw(11) << actDiff(monthIn, actTax, actTith, actLiv, othExp) << endl;
   
   return 0;
}
