/***********************************************************************
* Program:
*    Project 10, Mad Lib
*    Sister Hansen, CS124 
* Author:
*    Lance Bunch
* Summary:
*   This Program takes in a file, reads it, prompts the user at certain times
*   and displays everything back in a mad lib form. 
*    Estimated:  4.0 hrs   
*    Actual:     3.0 hrs
*   The hardest part was figuring out all the spaces.
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
void displayStory(char text[][32], int count);
bool playAgain();


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

   if(fin.fail())
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
 * This function reads the file and asks the user for the necessary info
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


/******************************************************************************
 * Considers what to convert certain characters to and displays spaces
 * ***************************************************************************/
void displayStory(char text[][32], int count)
{
   cout << endl;
   int i = 0;
   for (int i; i < count; i++)
   {
      if (text[i][0] == '<')
      {
         switch (text[i][1])
         {
            case '#':
               cout << "\n";
               break;
            case '{':
               if (i > 0)
               if (text[i-1][1] != '#')
                  cout << " ";
                  cout << "\"";
                  break;
            case '}':
               cout << "\"";
               if (isalpha(text[i + 1][0]))
                  cout << " ";
                  break;
            case '[':
               if (i > 0)
               if (text[i-1][1] != '#')
                  cout << " ";
                  cout << "\'";
                  break;
            case ']':
               cout << "\'";
               if (isalpha(text[i + 1][0]))
                  cout << " ";
                  break;
         }
      }
      else
      {
         cout << text[i];
         if (isalpha(text[i + 1][0]))
         cout << " ";
      }
        
   }
   cout << endl;
}


/******************************************************************************
 * This function asks if the user wants to try again.
 * ***************************************************************************/
bool playAgain()
{
   char answer;
   cout << "Do you want to play again (y/n)? ";
   cin >> answer;

   switch (answer)
   {
       case 'Y':
       case 'y':
           return true;
           break;
       case 'N':
       case 'n':
           return false;
           break;
   }
}


/*********************************************************************
 * makes sure all other logic and functions are called at the right time
 ********************************************************************/
int main()
{
    do
    {
        //Gets the name of the file and stores it in an array
        char fileName[256];
        getFileName(fileName);
        cin.ignore();

        //reads the fileName
        char text[256][32];
        int count = readFile(fileName, text);

        //Considers different characters in the story
        displayStory(text, count);
    }
    while (playAgain());

    cout << "Thank you for playing.\n";

    return 0;
   
}
