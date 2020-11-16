/***********************************************************************
* Program:
*    Week 13, Genealogy
*    Brother Ercanbrack, CS 235
* Author:
*    Lance Bunch
* Summary: 
*    This program builds a genealogical tree based off of a ged file
************************************************************************/

#include "bnode.h"
#include "list.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

/*************************************************************
* Struct :: personalInfo
* Uased as the data type for the BinaryNode class
**************************************************************/
struct personalInfo
{
   string givenName;
   string surName;
   string bDay;
   string id;
   bool hasBday = false;
};

/*************************************************************
* Operator :: <<
* Insertion operator overloading for the personanlInfo Struct
**************************************************************/
ostream &operator<<(ostream &out, const personalInfo &rhs)
{
   out << rhs.givenName;
   if ((!rhs.givenName.empty()) && (!rhs.surName.empty()))
      out << " ";
   out << rhs.surName;
   if (rhs.hasBday)
   {
      out << ", b. " << rhs.bDay;
   }
   out << endl;
   return out;
}

/*************************************************************
* sortNStore
* uses an Insertion sort to store the new data onto the list
**************************************************************/
void sortNStore(List<BinaryNode<personalInfo>> &familyTree, personalInfo &tempInfo)
{
   // if there isn't anything in the tree yet then just throw the data on
   if (familyTree.size() == 0)
   {
      familyTree.push_back(BinaryNode<personalInfo>(tempInfo));
      return;
   }

   // temporary variable to compare lowercase strings
   personalInfo lowerTemp = tempInfo;
   transform(lowerTemp.surName.begin(), lowerTemp.surName.end(), lowerTemp.surName.begin(), ::tolower);
   transform(lowerTemp.givenName.begin(), lowerTemp.givenName.end(), lowerTemp.givenName.begin(), ::tolower);

   // otherwise it is time to see where this data goes
   ListIterator<BinaryNode<personalInfo>> it = familyTree.begin();
   for (it; it != familyTree.end(); it++)
   {
      // temporary variable to compare lowercase strings
      personalInfo lowerSecure = (*it).data;
      transform(lowerSecure.surName.begin(), lowerSecure.surName.end(), lowerSecure.surName.begin(), ::tolower);
      transform(lowerSecure.givenName.begin(), lowerSecure.givenName.end(), lowerSecure.givenName.begin(), ::tolower);

      // if the last name of data to be inserted comes
      // before the last name of the location the iterator is at
      if (lowerTemp.surName < lowerSecure.surName)
      {
         // put it before the place of the iterator
         familyTree.insert(it, BinaryNode<personalInfo>(tempInfo));
         return;
      }
      // if the last name of data to be inserted
      // is the same as the name of the iterators last name
      else if (lowerTemp.surName == lowerSecure.surName)
      {
         // time to do the same with the first name
         if (lowerTemp.givenName < lowerSecure.givenName)
         {
            familyTree.insert(it, BinaryNode<personalInfo>(tempInfo));
            return;
         }
         // and if the first names are the same
         else if (lowerTemp.givenName == lowerSecure.givenName)
         {
            // then check if they have a birthday
            if (lowerTemp.hasBday && lowerSecure.hasBday)
            {
               // and if they do only look at the years in the birthdays
               string tempdate = tempInfo.bDay.substr(tempInfo.bDay.size() - 4);
               string secureDate = (*it).data.bDay.substr((*it).data.bDay.size() - 4);

               // then if the date to be inserted is less than
               // the iterator's date
               if (tempdate < secureDate)
               {
                  familyTree.insert(it, BinaryNode<personalInfo>(tempInfo));
                  return;
               }
            }
         }
      }
   }

   // if we never did anything with that data then put it on
   // the back of the list
   familyTree.push_back(BinaryNode<personalInfo>(tempInfo));
}

/*************************************************************
* buildTree
* Builds my family tree from the list
**************************************************************/
void buildTree(List<BinaryNode<personalInfo>> &familyTree, string momID, string dadID, string childID)
{
   BinaryNode<personalInfo> *pMom = NULL;
   BinaryNode<personalInfo> *pDad = NULL;
   BinaryNode<personalInfo> *pChild = NULL;

   ListIterator<BinaryNode<personalInfo>> it = familyTree.begin();
   for (it; it != familyTree.end(); it++)
   {
      if ((*it).data.id == momID)
      {
         pMom = &(*it);
      }
      if ((*it).data.id == dadID)
      {
         pDad = &(*it);
      }
      if ((*it).data.id == childID)
      {
         pChild = &(*it);
      }
   }
   if (pChild != NULL)
   {
      pChild->pFather = pDad;
      pChild->pMother = pMom;
   }
}

/*************************************************************
* ParseFile
* Opens a file, reads it, and stores data accordingly
**************************************************************/
void parseFile(string fileName, List<BinaryNode<personalInfo>> &familyTree)
{
   // temporary variables for use in this class
   string data;

   ifstream fin(fileName.c_str());

   // error handling file opening
   if (fin.fail())
   {
      cout << "ERROR: cannot read file...Terminating Program...\n";
      fin.ignore();
      fin.clear();
      fin.close();
      return;
   }

   // while not at the end of the file...
   while (!fin.eof())
   {
      // get each line one by one if we haven't found an id
      if ((!(data[2] == '@' && data[3] == 'I')))
      {
         getline(fin, data);
      }

      // bool to know when you are at the end of a new person
      bool newPerson = true;
      bool newFamily = true;

      // if you are at the end of the file then get out of there
      if (fin.eof())
      {
         fin.close();
         return;
      }

      // if we find a new person from the file...
      if (data[2] == '@' && data[3] == 'I')
      {
         personalInfo tempInfo;

         // erase from the beginning and end of line to give to my list
         data.erase(0, 3);
         if (data.length() == 8)
         {
            data.erase(2, data.size());
         }
         else if (data.length() == 9)
         {
            data.erase(3, data.size());
         }
         else if (data.length() == 10)
         {
            data.erase(4, data.size());
         }
         tempInfo.id = data;

         // while we are still in this new persons' info...
         while (newPerson)
         {
            getline(fin, data);

            // if you have found a given name...
            if (data[2] == 'G' && data[3] == 'I')
            {
               data.erase(0, 7);
               tempInfo.givenName = data;
            }
            // if you have found a surname...
            else if (data[2] == 'S' && data[3] == 'U')
            {
               data.erase(0, 7);
               tempInfo.surName = data;
            }
            // if you have found a birthday...
            else if (data[2] == 'B' && data[3] == 'I')
            {
               // get the following line
               getline(fin, data);
               if (data[2] == 'D' && data[3] == 'A')
               {
                  data.erase(0, 7);
                  tempInfo.bDay = data;
                  tempInfo.hasBday = true;
               }

               // find where it goes in the list and throw it on
               sortNStore(familyTree, tempInfo);

               newPerson = false;
            }
            // if you have found another person
            else if (data[2] == '@' && data[3] == 'I')
            {
               // find where it goes in the list and throw it on
               sortNStore(familyTree, tempInfo);

               newPerson = false;
            }
         }
      }
      // otherwise if we have found a new family tag
      else if (data[2] == '@' && data[3] == 'F')
      {
         // create some temp strings to stand as the id for each family member
         string dadID = "";
         string momID = "";
         string childID = "";
         // while we are sill at this current family
         while (newFamily)
         {
            // get the next line
            getline(fin, data);

            // make sure we aren't at the end of the file
            if (fin.eof())
            {
               fin.close();
               return;
            }

            // if we have found a husband
            if (data[2] == 'H' && data[3] == 'U')
            {
               data.erase(0, 8);
               if (data.size() == 3)
               {
                  data.erase(2, 2);
               }
               else if (data.size() == 4)
               {
                  data.erase(3, 3);
               }
               else if (data.size() == 5)
               {
                  data.erase(4, 4);
               }
               dadID = data;
            }
            // if we have found a wife
            else if (data[2] == 'W' && data[3] == 'I')
            {
               data.erase(0, 8);
               if (data.size() == 3)
               {
                  data.erase(2, 2);
               }
               else if (data.size() == 4)
               {
                  data.erase(3, 3);
               }
               else if (data.size() == 5)
               {
                  data.erase(4, 4);
               }
               momID = data;
            }
            // if we have found a child
            else if (data[2] == 'C' && data[3] == 'H')
            {
               data.erase(0, 8);
               if (data.size() == 3)
               {
                  data.erase(2, 2);
               }
               else if (data.size() == 4)
               {
                  data.erase(3, 3);
               }
               else if (data.size() == 5)
               {
                  data.erase(4, 4);
               }
               childID = data;
               // build the tree
               buildTree(familyTree, momID, dadID, childID);

               // using children as anchor to decide if we are at
               // the end of the family tag
               newFamily = false;
            }
         }
      }
   }

   fin.close();
}

/*************************************************************
* Main
* Grabs commands off of console to read and build files with
* a ged file
**************************************************************/
int main(int argc, const char *argv[])
{
   char fileName[50];
   List<BinaryNode<personalInfo>> familyTree;
   if (argc == 1)
   {
      cout << "What file would you like to read? ";
      cin >> fileName;
   }
   else
   {
      strcpy(fileName, argv[1]);
   }

   parseFile(fileName, familyTree);

   ofstream fout("sorted.dat");

   ListIterator<BinaryNode<personalInfo>> it = familyTree.begin();
   for (it; it != familyTree.end(); it++)
   {
      fout << (*it).data;
   }

   fout.close();

   // ListIterator<BinaryNode<personalInfo>> it2 = familyTree.begin();
   // for (it2; it2 != familyTree.end(); it2++)
   // {
   //    cerr << (*it2).data;
   // }

   ListIterator<BinaryNode<personalInfo>> it3 = familyTree.begin();
   for (it3; it3 != familyTree.end(); it3++)
   {
      if ((*it3).data.givenName == "Gregory Lawrence")
      {
         (*it3).level();
         break;
      }
   }
   return 0;
}