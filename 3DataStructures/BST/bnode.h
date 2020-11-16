#ifndef BNODE_H
#define BNODE_H

#include <iostream>
#include <cassert>
using namespace std;

/*****************************************************************
 * BINARY NODE
 * A single node in a binary tree.  Note that the node does not know
 * anything about the properties of the tree so no validation can be done.
 *****************************************************************/
template <class T>
class BinaryNode
{
public:
   // Default Constructor
   BinaryNode() : pLeft(NULL), pRight(NULL), pParent(NULL) {}

   // Non-Default Constructor
   BinaryNode(const T &t)
   {
      pLeft = NULL;
      pRight = NULL;
      pParent = NULL;
      data = t;
   }

   // return size (i.e. number of nodes in tree)
   int size() const
   {
      return 1 +
             (pLeft == NULL ? 0 : pLeft->size()) +
             (pRight == NULL ? 0 : pRight->size());
   }

   // add a node with data to the left
   void addLeft(BinaryNode<T> *pNode);

   // add a node with data to the right
   void addRight(BinaryNode<T> *pNode);

   // create a node and add it to the left
   void addLeft(const T &t) throw(const char *);

   // create a node and add it to the right
   void addRight(const T &t) throw(const char *);

   // since no validation is done, everything is public
   BinaryNode<T> *pLeft;
   BinaryNode<T> *pRight;
   BinaryNode<T> *pParent;
   T data;
};

/**********************************************************
 * ADDLEFT (Node)
 * Adds a previously created node to the left of node in tree
 **********************************************************/
template <class T>
void BinaryNode<T>::addLeft(BinaryNode<T> *pNode)
{
   if (pNode == NULL)
   {
      this->pLeft = NULL;
   }
   else
   {
      this->pLeft = pNode;
      pNode->pParent = this;
   }
}

/**********************************************************
 * ADDRIGHT (Node)
 * Adds a previously created node to the right of node in tree
 **********************************************************/
template <class T>
void BinaryNode<T>::addRight(BinaryNode<T> *pNode)
{
   if (pNode == NULL)
   {
      this->pRight = NULL;
   }
   else
   {
      this->pRight = pNode;
      pNode->pParent = this;
   }
}

/**********************************************************
 * ADDLEFT (data)
 * creates a new node with data passed in and attaches it
 * to the left of the node in the tree
 **********************************************************/
template <class T>
void BinaryNode<T>::addLeft(const T &t) throw(const char *)
{
   try
   {
      BinaryNode<T> *pTemp = new BinaryNode<T>(t);
      this->pLeft = pTemp;
      pTemp->pParent = this;
   }
   catch (const std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a node\n";
   }
}

/**********************************************************
 * ADDRIGHT
 * creates a new node with data passed in and attaches it
 * to the right of the node in the tree
 **********************************************************/
template <class T>
void BinaryNode<T>::addRight(const T &t) throw(const char *)
{
   try
   {
      BinaryNode<T> *pTemp = new BinaryNode<T>(t);
      this->pRight = pTemp;
      pTemp->pParent = this;
   }
   catch (const std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a node\n";
   }
}

/**********************************************************
 * DELETEBINARYTREE
 * deletes the node passed in and it's children
 **********************************************************/
template <class T>
void deleteBinaryTree(BinaryNode<T> *pNode)
{
   if (pNode->pLeft != NULL)
   {
      deleteBinaryTree(pNode->pLeft);
   }
   else if (pNode->pRight != NULL)
   {
      deleteBinaryTree(pNode->pRight);
   }
   delete pNode;
   pNode = NULL;
}

/**********************************************************
 * OPERATOR <<
 * Overloaded to display a Binary Tree
 **********************************************************/
template <class T>
ostream &operator<<(ostream &cout, BinaryNode<T> *rhs)
{
   if (rhs != NULL)
   {
      cout << rhs->pLeft;
      cout << rhs->data << ' ';
      cout << rhs->pRight;
   }
   return cout;
}

#endif // BNODE_H
