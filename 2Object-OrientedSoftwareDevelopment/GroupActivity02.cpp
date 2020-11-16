/**********************************************************************
 * File: ta03.cpp
 * Author: Lance Bunch
 *
 * Description: Use this file as a starting point for Team Activity 03.
 *    You do not need to "submit" your code, but rather, answer the
 *    questions in the I-Learn assessment.
 **********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

/***********************************************************************
 * Struct: Scripture
 * Description: Holds the reference to a scripture (book, chapter, verse
 ***********************************************************************/
struct Scripture
{
   string book;
   int chapter;
   int Startverse;
   int endVerse;
};

/***********************************************************************
 * Function: display
 * Description: Displays the passed scripture.
 ***********************************************************************/
void display(const Scripture &newScripture)
{
   cout << newScripture.book << " ";
   cout << newScripture.chapter << ":";
   cout << newScripture.Startverse << endl;

   if (newScripture.endVerse > 0)
   {
      cout << "-" << newScripture.endVerse;
   }
}

/***********************************************************************
 * 
 * 
 * *********************************************************************/
void parseLine(string line, Scripture &newScripture)
{
   stringstream buffer(line);

   buffer >> newScripture.book;

   if (buffer.fail())
   {
      cout << "Error processing line: " << line << endl;
   }

   buffer >> newScripture.book;
   buffer >> newScripture.chapter;
   buffer >> newScripture.Startverse;

   if (buffer.fail())
   {
      newScripture.endVerse = 0;
   }
}

/***********************************************************************
 * Function: parseFile 
 * Purpose: To get together the file and read it  
 * ********************************************************************/
void parseFile(const string &fileName)
{
   //stringstream ss

   ifstream fin(fileName.c_str());

   if (fin.fail())
   {
      throw string ("Error opening file.");
   }

   string line;
   while (getline(fin, line))
   {
      Scripture newScripture;
      parseLine(line, newScripture);

      display(newScripture);
      cout << endl;
   }

   fin.close();
}


/***********************************************************************
 * Function: main
 * Description: The driver for the program.
 ***********************************************************************/
int main()
{
   string fileName;
   // Insert your code here to prompt for the name of a file
   // and pass it to a readFile function
   cout << "Please enter the file name: ";
   cin >> fileName;

   try
   {
      parseFile(fileName);
   }
   catch(const string &error)
   {
      cout << error << endl;
   }
   
   return 0;
}
