/***********************************************************************
* Program:
*    Assignment 40, Multidimensional Arrays
*    Sister Hansen, CS 124
* Author:
*    Lance Bunch
* Summary: 
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      
************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

void getWriteFileName(char fileName[])
{
   cout << "Enter destination filename: ";
   cin.getline(fileName, 256);

   return;
}

void getReadFileName(char fileName[])
{
   cout << "Enter source filename: ";
   cin.getline(fileName, 256);

   return;
}


bool readFile(char fileName[], int board[][3])
{
   ifstream fin(fileName);

   if (fin.fail())
   {
      cout << "File does not exist.\n";
      return false;
   }

   int col = 0;
   int row = 0;
   for (row = 0; row < 3; row++)
   {
      for (col = 0; col < 3; col++)
      {
         fin >> board[row][col];
      }
   }

   fin.close();
   return true;
}


bool writeFile(char fileName[], int board[][3])
{
   ofstream fout(fileName);

   if (fout.fail())
   {
      cout << "Unable to read file.";
      return false;
   }

   int col = 0;
   int row = 0;
   for (row = 0; row < 3; row++)
   {
      for (col = 0; col < 3; col++)
      {
         fout << board[row][col];
         fout << (col != 2 ? " " : "");
      }
      fout << endl;
   }

   fout.close();
   cout << "File written\n";
   return true;
}

void boardDisplay(int board[][3])
{
   int col = 0;
   int row = 0;
   for (row = 0; row < 3; row++)
   {
      cout << row + 1 << "  ";
      for (col = 0; col < 3; col++)
      {
         if (board[row][col] == 0)
            cout << " ";
         else
            cout << board[row][col];
         cout << (col != 2 ? (col == 1 || col == 3 ? "|" : " ") : "");
      }
      cout << endl;
      if (row == 2 || row == 5)
         cout << "   ---+---+---\n";
   }
   cout << endl;
}


int main()
{
    int board[3][3];
    char fileName[256];
    getReadFileName(fileName);
    readFile(fileName, board);

    boardDisplay(board);

    getWriteFileName(fileName);
    writeFile(fileName, board);
}


