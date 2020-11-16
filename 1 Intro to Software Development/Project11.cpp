/***********************************************************************
* Program:
*    Project 12, Sudoku Project
*    Sister Hansen, CS124 
* Author:
*    Lance Bunch
* Summary: 
*  This program lets the user input a filename to play and interact with
*  a Sudoku board.
*    Estimated:  10.0 hrs
*    Actual:     8.0 hrs
*   The hardest part of this was the juggling the user coordinates 
*   With the computer coordinates to make sure everything goes smoothly   
************************************************************************/
//makes sure I can use whatever library I need
#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
using namespace std;

/******************************************************************************
 * This allows the user to overwrite the progress they've made on their board
 * ***************************************************************************/
void getWriteFileName(char fileName[])
{
   cout << "What file would you like to write your board to: ";
   cin.getline(fileName, 256);

   return;
}

/******************************************************************************
 * This prompts the user for the location of the sudoku board
 * ***************************************************************************/

void getReadFileName(char fileName[])
{
   cout << "Where is your board located? ";
   cin.getline(fileName, 256);

   return;
}

/******************************************************************************
 * reads the number of the board and places it in the right row and column
 * ***************************************************************************/
bool readFile(char fileName[], int board[][9][2])
{
   ifstream fin(fileName);

   if (fin.fail())
   {
      cout << "File does not exist.\n";
      return false;
   }

   int col = 0;
   int row = 0;
   for (row = 0; row < 9; row++)
   {
      for (col = 0; col < 9; col++)
      {
         fin >> board[row][col][0];
         board[row][col][1] = (board[row][col][0] != 0 ? 0 : 1);
      }
   }

   fin.close();
   return true;
}

/******************************************************************************
 * Overwrites the previous info into a new file.
 * ***************************************************************************/
bool writeFile(char fileName[], int board[][9][2])
{
   ofstream fout(fileName);

   if (fout.fail())
   {
      cout << "Unable to read file.";
      return false;
   }

   int col = 0;
   int row = 0;
   for (row = 0; row < 9; row++)
   {
      for (col = 0; col < 9; col++)
      {
         fout << board[row][col][0];
         fout << (col != 8 ? " " : "");
      }
      fout << endl;
   }

   fout.close();
   cout << "Board written successfully\n";
   return true;
}

/******************************************************************************
 * Simply displays the menu
 * ***************************************************************************/
void displayMenu()
{
    cout << "Options:\n"
         << "   ?  Show these instructions\n"
         << "   D  Display the board\n"
         << "   E  Edit one square\n"
         << "   S  Show the possible values for a square\n"
         << "   Q  Save and Quit\n"
         << endl;
    return;
}

/******************************************************************************
 * displays the board piece for the users convenience
 * ***************************************************************************/
void boardDisplay(int board[][9][2])
{
   cout << "   A B C D E F G H I\n";
   int col = 0;
   int row = 0;
   for (row = 0; row < 9; row++)
   {
      cout << row + 1 << "  ";
      for (col = 0; col < 9; col++)
      {
         if (board[row][col][0] == 0)
            cout << " ";
         else
            cout << board[row][col][0];
         cout << (col != 8 ? (col == 2 || col == 5 ? "|" : " ") : "");
      }
      cout << endl;
      if (row == 2 || row == 5)
         cout << "   -----+-----+-----\n";
   }
   cout << endl;
}

/******************************************************************************
 * Gets the coordinates, passes them back by reference.
 * ***************************************************************************/
void getCoordinates(int &row, int &col)
{
   char tempCol;
   cout << "What are the coordinates of the square: ";
   cin >> tempCol >> row;
   row--;
  switch (toupper(tempCol))
  {
     case 'A':
        col = 0;
        break;
     case 'B':
        col = 1;
        break;
     case 'C':
        col = 2;
        break;
     case 'D':
        col = 3;
        break;
     case 'F':
        col = 4;
        break;
     case 'G':
        col = 5;
        break;
     case 'H':
        col = 6;
        break;
     case 'I':
        col = 7;
        break;
     case 'J':
        col = 8;
        break;
     default:
     {
        if (row > 8 || row < 0 || col > 8 || col < 0)
           cout << "ERROR: Square '" << tempCol << (char) row 
                << "' is invalid\n";
        break;
     }
   }
}

/******************************************************************************
 * Takes the row/col and converts to user friendly directions
 * ***************************************************************************/
void displayCoordinates(int row, int col)
{
   switch(col)
   {
      case 0:
         cout << 'A';
         break;
      case 1:
         cout << 'B';
         break;
      case 2:
         cout << 'C';
         break;
      case 3:
         cout << 'D';
         break;
      case 4:
         cout << 'E';
         break;
      case 5:
         cout << 'F';
         break;
      case 6:
         cout << 'G';
         break;
      case 7:
         cout << 'H';
         break;
      case 8:
         cout << 'I';
         break;      
   }
   cout << ++row;
}

/******************************************************************************
 * Takes user input and replaces the value on the board.
 * ***************************************************************************/
void editBoard(int board[][9][2], int row, int col)
{
   if (!board[row][col][1])
   {
      cout << "ERROR: Square '"; 
      displayCoordinates(row, col);
      cout << "' is filled\n\n";
      return;
   }

   int value = 0;
   cout << "What is the value at '";
   displayCoordinates(row, col);
   cout << "': ";
   cin >> value;
   cout << endl;
   board[row][col][0] = value;
}

/******************************************************************************
 * This function allows the user to interact with the board.
 * ***************************************************************************/
void playGame(int board[][9][2])
{
   displayMenu();
   boardDisplay(board);
   int row = 0;
   int col = 0;
   char input;
   bool done = false;
   do
   {
      cout << "> ";
      cin >> input;

      switch (toupper(input))
      {
         case '?':
            displayMenu();
            cout << endl;
            break;
         case 'D':
            boardDisplay(board);
            break;
         case 'E':
            cin.ignore();
            getCoordinates(row, col);
            editBoard(board, row, col);
            break;
         case 'S':
            cin.ignore();
            getCoordinates(row, col);
            //displayPossible(board, row, col);
            break;
         case 'Q':
            done = true;
            break;
         default:
            cout << "ERROR: Invalid command\n";
            break;
      }
   }
   while(!done);

   return;
}


/**********************************************************************
 * Runs all other functions in order to make sure it goes smoothly.
 ***********************************************************************/
int main()
{
   int board[9][9][2];
   char fileName[256];
   getReadFileName(fileName);
   readFile(fileName, board);

   playGame(board);

   cin.ignore();
   getWriteFileName(fileName);
   writeFile(fileName, board);

   return 0;
}
