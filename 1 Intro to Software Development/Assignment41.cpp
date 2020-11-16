/************************************************************
 * Program:
 *    Assignment 41, Allocating Memory
 *    Sister Hansen, CS 124
 * Author:
 *    Lance Bunch
 * Summary:
 * 
 *    Estimated: 0.0 hrs
 *    Actual:    0.0 hrs
 * 
 * **********************************************************/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int numChar = 0;
    char text[256];

    cout << "Number of characters: ";
    cin >> numChar;

    if(numChar > 0)
    {
        cout << "Enter Text: ";
        cin.ignore();
        cin.getline(text, 256);
        
        cout << "Text: ";
        for (int i = 0; i < numChar; i++)
            cout << text[i];
        cout << endl;
       
    }
    else
        cout << "Allocation failure!\n";
        return 0;
    return 0;
}