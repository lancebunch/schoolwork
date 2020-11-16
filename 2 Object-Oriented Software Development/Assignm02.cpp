/***********************************************************************
* Program:
*    Assignment 02, Digital Forensics
*    Brother Macbeth, CS165
* Author:
*    Lance Bunch
* Summary: 
*    This code is designed to take in a file, read it, and display its 
*    in an organized chart between a given time frame.
*
*    Estimated:  4.0 hrs   
*    Actual:     4.5 hrs
*      What has been the hardest part so far is figuring out why not
*      all of the contents are read into my variable from the file. I
*      still haven't been able to figure out exactly what is going on.
*   Update: I figured out I had two different increments of 'i' in my
*           displayTable function so I was skipping over every other
*           record in the file.
************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Record
{
   string userName;
   string fileName;
   long timeStamp;
};

/**********************************************************************
 * Function: getFile
 * Purpose: To prompt the user for their file
 * ********************************************************************/
void getFile(string &recordFile)
{
   cout << "Enter the access record file: ";
   getline(cin, recordFile);
   cout << endl;
}

/**********************************************************************
 * Function: readFile
 * Purpose: To read the given file and store it into an array of structs
 * ********************************************************************/
void readFile(const string &recordFile, Record records[], int &reports)
{
   ifstream fin(recordFile.c_str());

   if (fin.fail())
   {
      throw string ("Error opening file!\n");
   }
   while (fin >> records[reports].fileName
              >> records[reports].userName
              >> records[reports].timeStamp)
   {
      reports++;
   }
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

   readFile(recordFile, records, reports);

   displayTable(records, reports);

   return 0;
}
