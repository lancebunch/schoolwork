/***********************************************************************
# Program:
#     Week 10, Word Count
#     Brother Ercanbrack, CS235
# Author:
#     Lance Bunch
# Summary:
#     
# Time:
#     5.0 Hrs
*************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <fstream>
using namespace std;

/***********************************************************************
* MAIN
* Procedurally reads a file into a map, sorts it, and displays most common
*  words in the file
*************************************************************************/
int main()
{
   // variable declaration for later use
   string fileName;
   string words;
   map<string, int> wordCount;
   multimap<int, string> countOrder;
   int totalWords;

   // getting name of file and testing if it failed
   cout << "Enter filename: ";
   cin >> fileName;

   ifstream fin(fileName.c_str());

   if (fin.fail())
   {
      cout << "ERROR: cannot read file...terminating program...\n";
      fin.ignore();
      fin.clear();
      return 0;
   }

   // reading the file in
   while (fin >> words)
   {
      // loop to lowercase all letters, delete all punctuation
      // besides '-', and keep track of words read
      for (int i = 0; i < words.length(); i++)
      {
         if (isalpha(words[i]))
         {
            words[i] = tolower(words[i]);
         }
         else
         {
            if (words[i] == '-')
            {
            }
            else
            {
               words.erase(i, 1);
               i--;
            }
         }
      }

      // increment the integer of the key that is read into the map
      wordCount[words]++;
      totalWords++;
   }

   fin.close();

   cout << endl;
   cout << "Number of words processed: " << totalWords << endl;
   cout << "100 most common words found and their frequencies:\n";

   // sorting the map into a multimap for repeated keys
   for (map<string, int>::reverse_iterator it = wordCount.rbegin(); it != wordCount.rend(); ++it)
   {
      countOrder.insert(make_pair(it->second, it->first));
   }

   // displaying the multimap
   multimap<int, string>::reverse_iterator it = countOrder.rbegin();
   for (int i = 0; i < 100 && it != countOrder.rend(); i++)
   {
      cout << setw(23) << it->second << " - " << it->first << endl;
      it++;
   }

   return 0;
}