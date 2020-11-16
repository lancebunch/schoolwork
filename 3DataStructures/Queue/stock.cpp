/***********************************************************************
 * Implementation:
 *    STOCK
 * Summary:
 *    This will contain the implementation for stocksBuySell() as well
 *    as any other function or class implementation you need
 * Author
 *    Lance Bunch
 **********************************************************************/

#include <iostream>    // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stock.h"     // for STOCK_TRANSACTION
#include "queue.h"     // for QUEUE
using namespace std;

/************************************************
 * TRANSACTION
 * Handles the math for calculating stocks bought
 * vs stocks sold
 ***********************************************/
void transaction(Queue <Stock> & bought, Queue <Stock> & sold, Stock temp)
{
   // if the bought stocks are more than the selling stocks
   if (bought.front().stockCount > temp.stockCount)
   {
      // profit equals the selling price - bought price * the selling stock count
      temp.profit = (temp.price - bought.front().price) * temp.stockCount;

      // reset the leftover stocks in bought
      bought.front().stockCount = bought.front().stockCount - temp.stockCount;

      // throw the data from the temporary struct onto the selling queue
      sold.push(temp);
   }
   // if the bought stocks are equal to the stocks being sold...
   else if (bought.front().stockCount == temp.stockCount)
   {
      // follow the same procedure but...
      temp.profit = (temp.price - bought.front().price) * temp.stockCount;

      // get rid of the data at the front of the queue
      bought.pop();
      sold.push(temp);
   }
   // otherwise
   else
   {
      // creat an integer equal to the stock count of those being sold
      int remainder = temp.stockCount;

      // while the bought stock count on the front 
      // of the queue is less than the remaining stocks...
      while (bought.front().stockCount <= remainder)
      {
         // similar logic as before
         temp.profit = (temp.price - bought.front().price) * bought.front().stockCount;

         // keep track of how many stocks have been sold
         remainder -= bought.front().stockCount;

         // you just sold remaining stocks at that price for that profit
         // so keep track of it
         temp.stockCount = bought.front().stockCount;

         // remove the most recent data
         bought.pop();

         // save the data
         sold.push(temp);
      }

      // once the front of the bought stocks are greater than the 
      // stacks about to be sold

      // save the remaining stocks left to sell
      temp.stockCount = remainder;

      // we know this logic
      temp.profit = (temp.price - bought.front().price) * remainder;

      // keep track of the stocks left at the front of the queue
      bought.front().stockCount -= remainder;
      sold.push(temp);

   }
}

/************************************************
 * DISPLAY
 * Displays the amount of stocks bought at what price,
 * the amount of stocks sold at what price for
 * a type of proceed.
 ***********************************************/
void displayStocks (Queue <Stock> bought, Queue <Stock> sold) 
{
   Dollars proceeds = 0;
   if (!bought.empty())
   {
      cout << "Currently held:" << endl;
      int size = bought.size();
      for (int i = 0; i < size; i++)
      {
         cout << "\tBought " << bought.front().stockCount 
               << " shares at " << bought.front().price << endl;
         bought.pop(); 
      }
   }
   if (!sold.empty())
   {
      
      cout << "Sell History:\n";
      int size2 = sold.size();
      for (int j = 0; j < size2; j++)
      {
         cout << "\tSold " << sold.front().stockCount
              << " shares at " << sold.front().price
              << " for a profit of " << sold.front().profit << endl;
         proceeds += sold.front().profit;
         sold.pop();
      }
   }
   cout << "Proceeds: " << proceeds << endl;
   return;
}

/************************************************
 * STOCKS BUY SELL
 * The interactive function allowing the user to
 * buy and sell stocks
 ***********************************************/
void stocksBuySell()
{
   // instructions
   cout << "This program will allow you to buy and sell stocks. "
        << "The actions are:\n";
   cout << "  buy 200 $1.57   - Buy 200 shares at $1.57\n";
   cout << "  sell 150 $2.15  - Sell 150 shares at $2.15\n";
   cout << "  display         - Display your current stock portfolio\n";
   cout << "  quit            - Display a final report and quit the program\n";

   // your code here...
   Queue <Stock> bought;
   Queue <Stock> sold;

   string instruction;
   int stockQ = 0;
   Dollars price;

   do
   {
      // simple input handling
      cout << "> ";
      cin >> instruction;
      if (instruction == "buy")
      {
         Stock temp;
         cin >> stockQ;
         cin >> price;
         temp.stockCount = stockQ;
         temp.price = price;
         bought.push(temp);
      }
      else if (instruction == "sell")
      {
         Stock temp;
         cin >> stockQ;
         cin >> price;
         temp.stockCount = stockQ;
         temp.price = price;
         transaction(bought, sold, temp);
      }
      else if (instruction == "display")
      {
         displayStocks(bought, sold);
      }
      else if (instruction == "quit")
      {
      }
      else
      {
         cout << "Invalid Command...\n";
      }
   } while (instruction != "quit");
   
   
}


