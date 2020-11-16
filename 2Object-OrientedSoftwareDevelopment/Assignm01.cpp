/***********************************************************************
* Program:
*    Assignment 01, Genetic Genealogy          
*    Brother Macbeth, CS165
* Author:
*    Lance Bunch
* Summary: 
*  This code is made to receive a user's DNA sequence and compare it with
*  a list of potential relatives that they enter. 
*    Estimated:  2.0 hrs   
*    Actual:     4.0 hrs
* What was hard to implement in this code was the comparator between
* the two DNA sequences. It took some trial and error and probably isn't
* the prettiest way to do it but it works well enough. What would be nice
* to implement later is make sure the user can't input any numbers into
* their DNA sequence and in fact only be able to add the characters
* 'A', 'T', 'G', 'C', or if they enter them lowercase the code could
* uppercase their input for them to make sure their isn't any erros when
* comparing the sequences.
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/**********************************************************************
 * Function: dnaSequence
 * Purpose: Retrive the user's DNA sequence
 * *******************************************************************/
char getDNASequence(string &mySequence)
{
   cout << "Enter your DNA sequence: ";
   cin >> mySequence;
}

/**********************************************************************
 * Function: numRelatives
 * Purpose: Know the amount of relatives they think they have
 * *******************************************************************/
int numRelatives()
{
   int myRelatives = 0;
   cout << "Enter the number of potential relatives: ";
   cin >> myRelatives;
   return myRelatives;
}

/**********************************************************************
 * Function: getRelativeNames
 * Purpose: Obtain name of relatives
 * *******************************************************************/
void getRelativeNames(string relativeNames[], const int myRelatives)
{
   cout << endl;
   for (int i = 0; i < myRelatives; i++)
   {
      cout << "Please enter the name of relative #" 
           << i + 1 
           << ": ";
      cin >> relativeNames[i];
   }
}

/**********************************************************************
 * Function: getRelativeDNA
 * Purpose: Take in and save the DNA sequence of each relative
 * *******************************************************************/
void getRelativeDNA(const string relativeNames[], string relativeDNA[], 
                        const int myRelatives)
{
   cout << endl;
   for (int i = 0; i < myRelatives; i++)
   {
      cout << "Please enter the DNA sequence for " 
           << relativeNames[i]
           << ": ";
      cin >> relativeDNA[i];
   }

}

/**********************************************************************
 * Function: compareDNA
 * Purpose: Compare the DNA of the user and their Relatives
 * ********************************************************************/
void compareDNA(const string &mySequence, const string relativeNames[], 
                  const string relativeDNA[], const int myRelatives)
{
   cout << endl;
   for (int i = 0; i < myRelatives; i++)
   {
      cout << "Percent match for " << relativeNames[i]
           << ": ";
      int percent = 0;  //this resets percent to make sure it starts at 0 again
      for (int c = 0; c < 10; c++)
      {

         if (mySequence[c] == relativeDNA[i][c])
            percent++;  //if the sequences match then add 1 to percent
      }
      cout << percent * 10 << "%" << endl;  
   }

}

/**********************************************************************
 * Main i the driver function for everything. You will see that all my 
 * variables are declared here and each function is run in the order that 
 * it was intended too. It filters in and out information that is passed 
 * between the functions as well.
 ***********************************************************************/
int main()
{
   string mySequence; //declaring string for the user's DNA sequence
   
   getDNASequence(mySequence);   //prompts and takes in user DNA sequence

   int myRelatives = numRelatives();   //receives the number of relatives

   string relativeNames[50];   //Declaration of Strings
   string relativeDNA[50];

   getRelativeNames(relativeNames, myRelatives);   //gathers and stores names

   getRelativeDNA(relativeNames, relativeDNA, myRelatives);   //gathers DNA sequence 
                                                              //  of each relative
   
   compareDNA(mySequence, relativeNames, relativeDNA, myRelatives);

   return 0;
}
