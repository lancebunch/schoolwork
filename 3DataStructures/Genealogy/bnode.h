#ifndef BNODE_H
#define BNODE_H

#include <iostream>
#include <cassert>
#include <string>
#include <iomanip>
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
   BinaryNode() : pMother(NULL), pFather(NULL), pChild(NULL) /*, pNext(NULL), pPrev(NULL)*/ {}

   // Non-Default Constructor
   BinaryNode(const T &t)
   {
      pMother = NULL;
      pFather = NULL;
      pChild = NULL;
      // pNext = NULL;
      // pPrev = NULL;
      data = t;
   }

   // return size (i.e. number of nodes in tree)
   int size() const
   {
      return 1 +
             (pMother == NULL ? 0 : pMother->size()) +
             (pFather == NULL ? 0 : pFather->size());
   }

   // add a node with data to the left
   void addLeft(BinaryNode<T> *pNode);

   // add a node with data to the right
   void addRight(BinaryNode<T> *pNode);

   // add a node to the pNext pointer
   // void addNext(BinaryNode<T> *pNode);

   // create a node and add it to the left
   void addLeft(const T &t) throw(const char *);

   // create a node and add it to the right
   void addRight(const T &t) throw(const char *);

   // create a node and add it to the next pointer
   // void addNext(const T &t) throw(const char *);

   // level order traversal to display a binary tree
   void level();

   // since no validation is done, everything is public
   BinaryNode<T> *pMother;
   BinaryNode<T> *pFather;
   BinaryNode<T> *pChild;
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
      this->pMother = NULL;
   }
   else
   {
      this->pMother = pNode;
      pNode->pChild = this;
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
      this->pFather = NULL;
   }
   else
   {
      this->pFather = pNode;
      pNode->pChild = this;
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
      this->pMother = pTemp;
      pTemp->pChild = this;
   }
   catch (const std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a node\n";
   }
}

/**********************************************************
 * ADDRIGHT (data)
 * creates a new node with data passed in and attaches it
 * to the right of the node in the tree
 **********************************************************/
template <class T>
void BinaryNode<T>::addRight(const T &t) throw(const char *)
{
   try
   {
      BinaryNode<T> *pTemp = new BinaryNode<T>(t);
      this->pFather = pTemp;
      pTemp->pChild = this;
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
   if (pNode->pMother != NULL)
   {
      deleteBinaryTree(pNode->pMother);
   }
   else if (pNode->pFather != NULL)
   {
      deleteBinaryTree(pNode->pFather);
   }
   delete pNode;
   pNode = NULL;
}

/*************************************************************
* Method :: LEVEL
* Doing a level order traversal to display a family tree
**************************************************************/
template <class T>
void BinaryNode<T>::level()
{
   const int MAX = 150;
   BinaryNode<T> *queue[MAX];
   BinaryNode<T> *temp;
   int front = 0;
   int back = 0;
   int newGen = 0;
   int generations = 1;

   queue[back++] = this;
   newGen = 1;

   while (front != back)
   {
      temp = queue[front];
      front = (front + 1) % MAX;
      if (temp != NULL)
      {
         if (newGen == back)
         {
            if (generations == 1)
            {
               cout << "The Ancestors of Gregory Lawrence Cameron:\n";
            }
            if (generations == 2)
            {
               cout << "Parents:\n";
            }
            if (generations == 3)
            {
               cout << "Grandparents:\n";
            }
            if (generations == 4)
            {
               cout << "Great Grandparents:\n";
            }
            if (generations == 5)
            {
               cout << "2nd Great Grandparents:\n";
            }
            if (generations == 6)
            {
               cout << "3rd Great Grandparents:\n";
            }
            if (generations == 7)
            {
               cout << "4th Great Grandparents:\n";
            }
            if (generations == 8)
            {
               cout << "5th Great Grandparents:\n";
            }
         }
         // visit
         if (generations != 1)
            cout << "        " << temp->data;
         // end Visit
         queue[back] = temp->pFather;
         back = (back + 1) % MAX;
         queue[back] = temp->pMother;
         back = (back + 1) % MAX;
      }
      if (front == newGen)
      {
         newGen = back;
         generations++;
      }
   }
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
      cout << rhs->pMother;
      cout << rhs->data << ' ';
      cout << rhs->pFather;
   }
   return cout;
}

#endif // BNODE_H
