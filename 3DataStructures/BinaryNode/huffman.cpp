/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    Lance Bunch
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/
#include "huffman.h" // for HUFFMAN() prototype
#include <algorithm>
using namespace std;

// typedefs for ease of variable declaration
typedef Pair<string, float> HuffPair;
typedef BinaryNode<HuffPair> *pHuffNode;
typedef BinaryNode<HuffPair> HuffNode;
typedef list<pHuffNode> HuffList;

/*******************************************
 * ENCODINGHUFFMAN
 * ecodes the tree with frequency of characters
 *******************************************/
void encodingHuffman(pHuffNode &root, string code, string table[], int &i)
{
   // if we are at a leaf of the tree...
   if (root->pLeft == NULL && root->pRight == NULL)
   {
      // put that leaf's cod with the letter it is associated with on the table
      table[i] = root->data.first + " = " + code;
      i++;
   }
   else
   {
      // recursive function to generate codes
      encodingHuffman(root->pLeft, code + "0", table, i);
      encodingHuffman(root->pRight, code + "1", table, i);
   }
}
/*******************************************
 * HUFFMAN
 * Driver program to exercise the huffman generation code
 *******************************************/
void huffman(string fileName)
{
   // declaring variables for storage and sorting
   HuffPair pair;
   list<HuffPair> letterIndex;
   HuffList nodeList;
   int count = 0;

   // creating a filereading variable
   ifstream fin(fileName);

   // while there are things to read...
   while (fin >> pair)
   {
      // push them onto the back of my list of pairs
      letterIndex.push_back(pair);

      // keeps track of how big of a file we read in
      count++;
   }

   // close the file
   fin.close();

   // create an iterator starting at the beginning of my list of pairs
   list<HuffPair>::iterator it = letterIndex.begin();
   for (it; it != letterIndex.end(); it++)
   {
      // create a new BinaryNode with the data of the iterator in it
      BinaryNode<HuffPair> *root = new BinaryNode<HuffPair>(*it);

      // push that new node onto the back of the BinaryNode list
      nodeList.push_back(root);
   }

   // lambda overloading the stl list.sort function
   nodeList.sort([](pHuffNode node1, pHuffNode node2) {
      if (node1->data.second == node2->data.second)
      {
         return node2->data < node1->data;
      }
      return node1->data < node2->data;
   });

   while (nodeList.size() > 1)
   {
      // create a BinaryNode pointer that holds a pair
      pHuffNode temp = new HuffNode;

      // make its frequency equal to the frequency of the numbers
      temp->data.second += nodeList.front()->data.second;

      // the left node is the letter with smaller number
      temp->addLeft(nodeList.front());

      // remove the front item
      nodeList.pop_front();

      // do it again
      temp->data.second += nodeList.front()->data.second;

      // the right node is the letter with higher number
      temp->addRight(nodeList.front());

      // remove the front most node
      nodeList.pop_front();

      // put that new node onto the list
      nodeList.push_back(temp);

      // sort the list
      nodeList.sort([](pHuffNode node1, pHuffNode node2) {
         if (node1->data.second == node2->data.second)
         {
            return node2->data < node1->data;
         }
         return node1->data < node2->data;
      });
   }

   // getting the variables ready for encoding
   string code = "";
   string table[count];
   int i = 0;

   // call the encodingHuffman function passing the root of tree
   encodingHuffman(nodeList.front(), code, table, i);

   // sorts the array
   sort(table, table + count);

   // display the table
   for (int j = 0; j < count; j++)
   {
      cout << table[j] << endl;
   }
   return;
}
