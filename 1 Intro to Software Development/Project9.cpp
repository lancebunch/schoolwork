/***********************************************************************
* Program:
*    Project 09, Mad Lib
*    Sister Hansen, CS124 
* Author:
*    Lance Bunch
* Summary:
*   This program simply reads a file and diplays back to the user what info
*   They need to input.
*    Estimated:  3.0 hrs   
*    Actual:     3.0 hrs
*    The hardest part was figuring out what loops to use to make sure I can 
*    get all the necessary info.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

/**********************************************************************
 * These are my prototypes to make sure everything can be passed correctly
 ***********************************************************************/
char getFileName(char fileName[]);
int readFile(char fileName[], char text[][32]);
bool askQuestions(int word, char text[][32]);
void displayStory();
bool isSpaceAfter();
char playAgain();


/*********************************************************************
 * This first function prompts the user for the filename.
 ********************************************************************/
char getFileName(char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;

   return fileName[256];
}


/********************************************************************
 * This takes the fileName and reads it.
 *******************************************************************/
int readFile(char fileName[], char text[][32])
{
   ifstream fin(fileName);

   if (fin.fail())
      return 0;

   int i = 0;
   while (fin >> text[i] && i < 256)
   {   
      if (!askQuestions(i, text))
      {
         fin.close();
         return-1;
      }
      i++;    
   }   

   return i;
}


/********************************************************************
 * This reads different parts of the mad lib,displays back what info it needs
 *******************************************************************/
bool askQuestions(int word, char text[][32])
{
   if (text[word][0] != '<' || !isalpha(text[word][1]))
      return true;

   for (int i = 2; text[word][i] != '>'; i++)
   {
      if (text[word][i] != '_'
         && !isalpha(text[word][i])
         && text[word][i] != '('
         && text[word][i] != ')')
      {
         cerr << "Error: Your questions are not formatted correctly"
              << endl;
         return false;
      }    
   }
   cout << "\t" << (char) toupper(text[word][1]);

   for (int i = 2; text[word][i] != '>'; i++)
   {
      if (text[word][i] == '_')
         cout << " ";
      else
         cout << (char) tolower(text[word][i]);
   }

   cout << ": ";
   cin.getline(text[word], 32);
   return true;

}


/*********************************************************************
 * makes sure all other logic and functions are called at the right time
 ********************************************************************/
int main()
{
   //Gets the name of the file and stores it in an array
   char fileName[256];
   getFileName(fileName);
   cin.ignore();

   //reads the fileName
   char text[256][32];
   readFile(fileName, text);

   cout << "Thank you for playing.\n";
   
} 
