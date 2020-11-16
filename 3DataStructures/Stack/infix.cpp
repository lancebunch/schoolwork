/***********************************************************************
 * Module:
 *    Week 02, Stack
 *    Brother Helfrich, CS 235
 * Author:
 *    Lance Bunch
 * Summary:
 *    This program will implement the testInfixToPostfix()
 *    and testInfixToAssembly() functions
 ************************************************************************/

#include <iostream>    // for ISTREAM and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stack.h"     // for STACK
using namespace std;

/*****************************************************
 * CONVERT INFIX TO POSTFIX
 * Convert infix equation "5 + 2" into postifx "5 2 +"
 *****************************************************/
string convertInfixToPostfix(const string & infix)
{
   // create my stack
   Stack <char> op;

   // for testbed purposes
   string postfix = " ";
   try
   {
      for (int i = 0; i < infix.size(); i++)
      {
         switch (infix[i])
         {
            // lowest priority case
            case '+':
            case '-':
               postfix += " ";
               // if the stack is empty...
               if (op.empty())
               {
                  // ...just go ahead and throw it on
                  op.push(infix[i]);
               }
               // if it isn't empty...
               else
               {
                  // and while the existent top isn't any other symbol
                  while (!op.empty() && (op.top() == '+' || op.top() == '-' || op.top() == '*' ||
                         op.top() == '/' || op.top() == '%' || op.top() == '^'))
                  {
                     // place the top into the postfix string
                     postfix += op.top();
                     postfix += " ";
                     // delete the top
                     op.pop();
                  }
                  // the operator is now ready to go on the stack
                  op.push(infix[i]);
               }
               break;
            // medium priority case
            case '*':
            case '/':
            case '%':
               postfix += " ";
               // is the stack is empty...
               if (op.empty())
               {
                  // ...go ahead and chuck the operator on
                  op.push(infix[i]);
               }
               // if it isn't empty...
               else
               {
                  // ...and while there isn't any of the following operators on the stack...
                  while (!op.empty() && (op.top() == '*' || op.top() == '/' || op.top() == '%' ||
                        op.top() == '^'))
                  {
                     // add the top of the stack to the postfix string
                     postfix += op.top();
                     postfix += " ";
                     // delete the top of the stack
                     op.pop();             
                  }
                  // ...go ahead and throw the operator on the top of the stack
                  op.push(infix[i]);
               }
               break;
            // higher priority operator
            case '^':
               postfix += " ";
               // same logic being applied, if the stack is empty...
               if (op.empty())
               {
                  // add the operator on top of it
                  op.push(infix[i]);
               }
               // and if it isn't...
               else
               {
                  // ...and while the top of the stack is a '^' operator
                  while (!op.empty() && (op.top() == '^'))
                  {
                     // add the top of the stack to the postfix string, then delete the top
                     postfix += op.top();
                     postfix += " ";
                     op.pop();              
                  }
                  op.push(infix[i]);
               }              
               break;
            // highester priority
            case '(':
               op.push(infix[i]);
               break;
            // if you see this, unload everything on the stack until you see a '('
            case ')':
               postfix += " ";
               while (!op.empty() && op.top() != '(')
               {
                  postfix += op.top();
                  op.pop();
               }
               break;
            case ' ':
               break;
            default:
               postfix += infix[i];
         }
      }
      // finish it off by adding the last operators from the stack
      while (!op.empty())
      {
         // but ignore putting it on there if it is a '(' symbol
         if (op.top() == '(')
         {
            op.pop();
         }
         else
         {
            postfix += " ";
            postfix += op.top();
            op.pop();
         }
      }
   }
   catch (const char * sError)
   {
      cout << sError << endl;
   }   
   return postfix;
}

/*****************************************************
 * TEST INFIX TO POSTFIX
 * Prompt the user for infix text and display the
 * equivalent postfix expression
 *****************************************************/
void testInfixToPostfix()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";
   
   do
   {
      // prompt for infix
      cout << "infix > ";
      getline(cin, input);
      
      // handle errors
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }
      // generate postfix
      if (input != "quit")
      {
         string postfix = convertInfixToPostfix(input);
         cout << "\tpostfix: " << postfix << endl << endl;
      }
   }
   while (input != "quit");
}

/**********************************************
 * CONVERT POSTFIX TO ASSEMBLY
 * Convert postfix "5 2 +" to assembly:
 *     LOAD 5
 *     ADD 2
 *     STORE VALUE1
 **********************************************/
string convertPostfixToAssembly(const string & postfix)
{
   string assembly;

   return assembly;
}

/*****************************************************
 * TEST INFIX TO ASSEMBLY
 * Prompt the user for infix text and display the
 * resulting assembly instructions
 *****************************************************/
void testInfixToAssembly()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";

   do
   {
      // handle errors
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }
      
      // prompt for infix
      cout << "infix > ";
      getline(cin, input);
      
      // generate postfix
      if (input != "quit")
      {
         string postfix = convertInfixToPostfix(input);
         cout << convertPostfixToAssembly(postfix);
      }
   }
   while (input != "quit");
      
}
