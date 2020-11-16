/***********************************************************************
* Program:
*    Checkpoint 08a, Inheritance
*    Brother Macbeth, CS165
* Author:
*    Lance Bunch
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// For this assignment, for simplicity, you may put all of your classes
// in this file.

// TODO: Define your Book class here
class Book
{
   protected:
      string title;
      string author;
      int publicationYear;
   public:
      void promptBookInfo()
      {
         cout << "Title: ";
         getline(cin, title);
         cout << "Author: ";
         getline(cin, author);
         cout << "Publication Year: ";
         cin >> publicationYear;
         cin.ignore();
      }

      void displayBookInfo()
      {
         cout << title 
              << " (" << publicationYear << ") by " 
              << author;
      }

};

// TODO: Define your TextBook class here
class TextBook : public Book
{
   private:
      string subject;
   public:
      void promptSubject()
      {
         cout << "Subject: ";
         getline(cin, subject);
      }
      
      void displaySubject()
      {
         cout << "Subject: " << subject;
      }
};

// TODO: Add your PictureBook class here
class PictureBook : public Book
{
   private:
      string illustrator;
   public:
      void promptIllustrator()
      {
         cout << "Illustrator: ";
         getline(cin, illustrator);
      }

      void displayIllustrator()
      {
         cout << "Illustrated by " << illustrator;
      }
};



/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare a Book object here and call its methods
   Book book;

   book.promptBookInfo();
   cout << endl;
   book.displayBookInfo();
   cout << endl << endl;

   // Declare a TextBook object here and call its methods
   TextBook textBook;

   textBook.promptBookInfo();
   textBook.promptSubject();
   cout << endl;
   textBook.displayBookInfo();
   cout << endl;
   textBook.displaySubject();
   cout << endl << endl;

   // Declare a PictureBook object here and call its methods
   PictureBook pictureBook;

   pictureBook.promptBookInfo();
   pictureBook.promptIllustrator();
   cout << endl;
   pictureBook.displayBookInfo();
   cout << endl;
   pictureBook.displayIllustrator();
   cout << endl;


   return 0;
}


