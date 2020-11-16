/***********************************************************************
* Program:
*    Checkpoint 02b, Complex Numbers
*    Brother Macbeth, CS165
* Author:
*    Lance Bunch
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

// TODO: Define your Complex struct here
struct Complex
{
   double realNum;
   double imaginaryNum;
};

/**********************************************************************
 * Function: promptComplex
 * Purpose: To take in the real and imaginary numbers and store it in
 *          corresponding Complex Structs C1 and C2
 * *******************************************************************/
void promptComplex(Complex &complex)
{
   cout << "Real: ";
   cin >> complex.realNum;
   cout << "Imaginary: ";
   cin >> complex.imaginaryNum;
}

/**********************************************************************
 * Function: addComplex
 * Purpose: Adds two complex numbers together and returns the sum.
 ***********************************************************************/
Complex addComplex(const Complex &C1, const Complex &C2)
{
   Complex SUM;

   SUM.realNum = C1.realNum + C2.realNum;
   SUM.imaginaryNum = C1.imaginaryNum + C2.imaginaryNum;

   return SUM;
}
/***********************************************************************
 * Function: display
 * Purpose: Display the contents of the Struct SUM
 * ********************************************************************/
void display(const Complex &SUM)
{
   cout << SUM.realNum << " + " << SUM.imaginaryNum << "i";
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare two Complex objects, c1 and c2
   Complex C1;
   Complex C2;
   // Call your prompt function twice to fill in c1, and c2 
   promptComplex(C1);
   promptComplex(C2);
   // Declare another Complex for the sum
   Complex SUM;
   // Call the addComplex function, putting the result in sum;
   SUM = addComplex(C1, C2);
   
   cout << "\nThe sum is: ";
   display(SUM);
   cout << endl;
 
   return 0;
}


