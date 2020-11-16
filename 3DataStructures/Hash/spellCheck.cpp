/***********************************************************************
 * Module:
 *    Week 12, Spell Check
 *    Brother Helfrich, CS 235
 * Author:
 *    Lance Bunch
 * Summary:
 *    This program will implement the spellCheck() function
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "spellCheck.h"
#include "hash.h"
using namespace std;

/****************************************
 * SpellHASH
 * A simple hash of strings
 ****************************************/
class SpellHash : public Hash<string>
{
public:
   SpellHash(int numBuckets) throw(const char *) : Hash<string>(numBuckets) {}
   SpellHash(const SpellHash &rhs) throw(const char *) : Hash<string>(rhs) {}

   /*
      The logic is to add the ascii value of 3 parts of a word.
      This will make more specific indexes to return to the 
      insert or find function. The modulous 100 is to handle
      clusting and try to use as much of the allocated space
      as possible.   
    */
   int hash(const string &value) const
   {
      int ascii = 0;
      ascii += int(value[0]);
      ascii += int(value[value.size() / 2]);
      ascii += int(value[value.size() - 1]);
      return ascii % 100;
   }
};

/*****************************************
 * SPELL CHECK
 * Prompt the user for a file to spell-check
 ****************************************/
void spellCheck()
{
   SpellHash hTable(100);
   string fileName;
   string words;
   string misspelled;

   ifstream lin("/home/cs235e/week12/dictionary.txt");

   // fille error checking
   if (lin.fail())
   {
      cout << "ERROR: cannot read hardcoded file...terminating program...\n";
      lin.ignore();
      lin.clear();
      lin.close();
      return;
   }

   // reading in lowercase versions of each word
   while (lin >> words)
   {

      for (int i = 0; i < words.size(); i++)
      {
         words[i] = tolower(words[i]);
      }
      hTable.insert(words);
   }

   // closing the file
   lin.close();

   // testBed satisfiers
   cout << "What file do you want to check? ";
   cin >> fileName;

   ifstream fin(fileName);

   // error handling if the file fails to be read
   if (fin.fail())
   {
      cout << "ERROR: cannot read file...terminating program...\n";
      fin.ignore();
      fin.clear();
      fin.close();
      return;
   }

   // tolowering temporary word to compare with dictionary
   while (fin >> words)
   {
      string tempWord = words;
      for (int i = 0; i < words.size(); i++)
      {
         tempWord[i] = tolower(tempWord[i]);
      }
      if (!hTable.find(tempWord))
      {
         misspelled += words + ", ";
      }
   }

   // if there were spelling errors then display them
   if (misspelled.length() > 0)
   {
      misspelled.erase(misspelled.end() - 2, misspelled.end());
      cout << "Misspelled: " << misspelled << endl;
   }
   else
   {
      cout << "File contains no spelling errors\n";
   }

   fin.close();
}
