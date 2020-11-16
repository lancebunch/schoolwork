/***********************************************************************
* Program:
*    Assignment 43, Command Line
*    Sister Hansen, CS 124
* Author:
*    Lance Bunch
* Summary: 
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      
************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char ** argv)
{
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(1);

    char text[] = "0.3048";
    double conversion;
    conversion = atof(text);
    for (int i = 1; i < argc; i++)
    {
        cout << atof(argv[i]) 
             << " feet is " 
             << atof(argv[i]) * conversion
             << " meters\n";
    }
}


