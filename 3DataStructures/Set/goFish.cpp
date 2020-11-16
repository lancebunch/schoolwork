/***********************************************************************
* Program:
*    Assignment 01, Go Fish
*    Brother Helfrich, CS 235
* Author:
*    Lance Bunch
* Summary: 
*    This is all the functions necessary to play Go Fish!
*
*    Estimated:  6.0 hrs   
*    Actual:     10.5 hrs
*      The binary search was kinda complicated along with the union
*      and intersection functions.
************************************************************************/

#include <iostream>
#include <fstream>
#include "set.h"
#include "card.h"
#include "goFish.h"
using namespace std;

/******************************************
 * DISPLAY
 * Display the contents of the set
 *****************************************/
// template <class T>
// ostream & operator << (ostream & out, Set <T> & rhs)
// {
//    SetIterator <T> it;
//    for (it = rhs.begin(); it != rhs.end(); ++it)
//    {
//       if (it < rhs.end())
//       {
//         out << *it;
//       }
//       else
//       {
//          out << *it << ", ";
//       }
      
//    }
//    return out;
// }

/**********************************************************************
 * GO FISH
 * The function which starts it all
 ***********************************************************************/
void goFish()
{
   cout << "We will play 5 rounds of Go Fish.  Guess the card in the hand\n";
   
   Card card;
   Set <Card> hand;
   int tries = 1;
   int matches = 0;
   Card guess;

   ifstream fin("/home/cs235e/week05/hand.txt");

   while (fin >> card)
   {
      hand.insert(card);
   }

   fin.close();

   while (tries <= 5)
   {
      cout << "round " << tries << ": ";
      cin >> guess;
      int itFind = hand.find(guess);
      if (itFind >= 0)
      {
         cout << "\tYou got a match!\n";
         hand.erase(itFind);
         matches++;
      }
      else
      {
         cout << "\tGo Fish!\n";
      }
      tries++;
   }
   cout << "You have " << matches << " matches!\n";

   cout << "The remaining cards: ";
   hand.display(0);
   cout << ", ";
   hand.display(1);
   cout << ", ";
   hand.display(2);
   cout << ", ";
   hand.display(3);
   cout << endl;
   return ;
}
