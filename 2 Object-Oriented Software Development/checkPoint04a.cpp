/***********************************************************************
* Program:
*    Checkpoint 04a, Classes
*    Brother Macbeth, CS165
* Author:
*    Lance Bunch
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;
#ifndef BOOK_H
#define BOOK_H

class Book
{
   private:
      string title;
      string author;
   public:
      void promptBook();
      void displayBook();
};

#endif

void Book::promptBook()
{
   cout << "Title: ";
   getline(cin, title);
   cout << "Author: ";
   getline(cin, author);

}

void Book::displayBook()
{
   cout << "\"" << title << "\" by " << author << endl;
}


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   Book book;

   book.promptBook();

   book.displayBook();

   return 0;
}
