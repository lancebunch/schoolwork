/***********************************************************************
* Program:
*    Assignment 03, Digital Forensics With Corrupt Files
*    Brother Macbeth, CS165
* Author:
*    Lance Bunch
* Summary: 
*    This program takes in a file name and reads it. If some parts of the
*     file are corrupt or aren't in the right place, error handling takes 
*     care of it and moves on to the next part of the file.
*    Estimated:  4.0 hrs   
*    Actual:     0.75 hrs
*      What seemed most difficult was transferring the fin function to read
*      everything into the stingstream function and reading everything in the
*      same way. However once that was figured out everything went relatively
*      smoothly.
************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

/************************************************************************
 * This states my struct Record as a variable type to pass info more simply
 * *********************************************************************/
struct Record
{
   string userName;
   string fileName;
   long timeStamp;
};

/**********************************************************************
 * Function: parseFile
 * Purpose: To go through my line string and parse through each bit of
 *          info and test to see if it is valid or not.
 * *******************************************************************/
void parseLine(const string &line, Record records[], const int &reports)
{
   stringstream ss(line);

   ss >> records[reports].fileName;
   ss >> records[reports].userName;
   ss >> records[reports].timeStamp;
   if (ss.fail())   //if an unexpected entry occurs, stop running and
   {                //   inform the console
      throw string("Error parsing line: " + line);
   }
   if (records[reports].timeStamp < 1000000000 || 
      records[reports].timeStamp > 10000000000)
   {
      throw string("Error parsing line: " + line);
   }      
}



/**********************************************************************
 * Function: getFile
 * Purpose: To prompt the user for their file
 * ********************************************************************/
void getFile(string &recordFile)
{
   cout << "Enter the access record file: ";
   getline(cin, recordFile);
}

/**********************************************************************
 * Function: readFile
 * Purpose: To read the given file and store it into an array of structs
 * ********************************************************************/
void readFile(const string &recordFile, Record records[], int &reports)
{
   string line;
   ifstream fin(recordFile.c_str());

   if (fin.fail())
   {
      throw string ("Error opening file!\n");
   }
   while (getline(fin, line))
   {
      try
      {
         parseLine(line, records, reports);
         reports++;
      }
      catch(const string &error)
      {
         cout << error << endl;
      }
   }
   cout << endl;
   fin.close();
}

/**********************************************************************
 * Function: displayTable
 * Purpose: Dispay and organized chart of users logged in the given time
 * ********************************************************************/
void displayTable(const Record records[], const int &reports)
{
   long startTime = 0;
   long endTime = 0;

   cout << "Enter the start time: ";
   cin >> startTime;
   cout << "Enter the end time: ";
   cin >> endTime;
   cout << endl;

   cout << "The following records match your criteria:\n";
   cout << endl;

   cout << setw(16) << "Timestamp " << setw(20) << "File " << setw(19) 
        << "User" << endl
        << "--------------- ------------------- -------------------\n";

   int i = 0;
   for (int i = 0; i < reports; i++)
   {
      if (startTime <= records[i].timeStamp && records[i].timeStamp <= endTime)
      {
         cout << setw(15) << records[i].timeStamp
              << setw(20) << records[i].fileName
              << setw(20) << records[i].userName << endl;
      }
   }
   cout << "End of records\n";
}

/**********************************************************************
 * Function: main
 * Purpose: Being the driver program, this function calls each other
 *          other function in the correct order and passes the variables
 *          around to make sure everything runs smoothly.
 ***********************************************************************/
int main()
{
   string recordFile;
   Record records[500];
   int reports = 0;

   getFile(recordFile);

   try
   {
      readFile(recordFile, records, reports);
   }
   catch(const string &problem)
   {
      cout << problem << endl;
   }

   displayTable(records, reports);

   return 0;
}
