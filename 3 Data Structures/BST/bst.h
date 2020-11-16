/***********************************************************************
 * Component:
 *    Week 09, Binary Search Tree (BST)
 *    Brother Ercanbrack, CS 235
 * Author:
 *    Br. Helfrich
 *    Modified by Scott Ercanbrack - removed most of the the BST class functions,
 *                                   but left BST Iterator class.
 *    Modified further by Lance Bunch
 * 
 * Summary:
 *    Create a binary search tree
 ************************************************************************/

#ifndef BST_H
#define BST_H

#include "bnode.h" // for BinaryNode
#include "stack.h" // for Stack

// forward declaration for the BST iterator
template <class T>
class BSTIterator;

/*****************************************************************
 * BINARY SEARCH TREE
 * Create a Binary Search Tree
 *****************************************************************/
template <class T>
class BST
{
public:
   // constructor
   BST() : root(NULL){};

   // copy constructor
   BST(const BST &rhs);

   ~BST() { clear(); }

   int size() const { return empty() ? 0 : root->size(); } // BinaryNode class needs a size function

   // determine if the tree is empty
   bool empty() const
   {
      return (!root) ? true : false;
   }

   // remove all the nodes from the tree.  Makes an empty tree.
   void clear()
   {
      if (root)
         deleteBinaryTree(root);
      root = NULL;
   }

   // recursively calls itself to create a copy of a binary tree
   BinaryNode<T> *copyTree(BinaryNode<T> *root);

   // overloaded assignment operator
   BST &operator=(const BST &rhs) throw(const char *)
   {
      clear();
      root = copyTree(rhs.root);
   }

   // insert an item
   void insert(const T &t) throw(const char *);

   // remove an item
   void remove(BSTIterator<T> &it);

   // find a given item
   BSTIterator<T> find(const T &t);

   // the usual iterator stuff
   BSTIterator<T> begin() const;
   BSTIterator<T> end() const { return BSTIterator<T>(NULL); }
   BSTIterator<T> rbegin() const;
   BSTIterator<T> rend() const { return BSTIterator<T>(NULL); }

private:
   BinaryNode<T> *root;
};

/*********************************************************
* copy constructor
**********************************************************/
template <class T>
BST<T>::BST(const BST &rhs)
{
   root = copyTree(rhs.root);
}

/*****************************************************
 * BST :: COPYTREE
 * Works recursively to copy a new tree from one passed
 ****************************************************/
template <class T>
BinaryNode<T> *BST<T>::copyTree(BinaryNode<T> *root)
{
   if (root == NULL)
   {
      return NULL;
   }
   BinaryNode<T> *nodeTemp = new BinaryNode<T>(root->data);
   if (root->pLeft)
   {
      nodeTemp->pLeft = copyTree(root->pLeft);
      if (nodeTemp->pLeft != NULL)
         nodeTemp->pLeft->pParent = nodeTemp;
   }
   if (root->pRight)
   {
      nodeTemp->pRight = copyTree(root->pRight);
      if (nodeTemp->pRight != NULL)
         nodeTemp->pRight->pParent = nodeTemp;
   }
   return nodeTemp;
}

/*****************************************************
 * BST :: BEGIN
 * Return the first node (left-most) in a binary search tree
 ****************************************************/
template <class T>
BSTIterator<T> BST<T>::begin() const
{
   Stack<BinaryNode<T> *> nodes;

   nodes.push(NULL);
   nodes.push(root);
   while (nodes.top() != NULL && nodes.top()->pLeft)
      nodes.push(nodes.top()->pLeft);

   return BSTIterator<T>(nodes);
}

/*****************************************************
 * BST :: RBEGIN
 * Return the last node (right-most) in a binary search tree
 ****************************************************/
template <class T>
BSTIterator<T> BST<T>::rbegin() const
{
   Stack<BinaryNode<T> *> nodes;

   nodes.push(NULL);
   nodes.push(root);
   while (nodes.top() != NULL && nodes.top()->pRight)
      nodes.push(nodes.top()->pRight);

   return BSTIterator<T>(nodes);
}

/*****************************************************
 * BST :: INSERT
 * Insert a node at a given location in the tree
 ****************************************************/
template <class T>
void BST<T>::insert(const T &t) throw(const char *)
{
   // create a new Binary node and give it the data passed in
   BinaryNode<T> *pTemp = new BinaryNode<T>(t);

   // there isn't a tree started...
   if (root == NULL)
   {
      // make the root the same as the new node created
      root = pTemp;
   }
   else
   {
      // create a new BinaryNode pointer and make it the same as root
      BinaryNode<T> *p = root;

      // p will never equal NULL, but this is for finding location
      while (p != NULL)
      {
         // if the data being passed in is less than p's data
         if (pTemp->data <= p->data)
         {
            // if there isn't anything less than p's data...
            if (p->pLeft == NULL)
            {
               // then we found a spot for the data!
               p->pLeft = pTemp;
               pTemp->pParent = p;
               return;
            }
            // otherwise move left and start the loop over
            else
            {
               p = p->pLeft;
            }
         }
         // if the data being passed in is more than p's data
         else
         {
            // if there isn't anything greater than p's data...
            if (p->pRight == NULL)
            {
               // then we found the spot for the data!
               p->pRight = pTemp;
               pTemp->pParent = p;
               return;
            }
            // otherwise move to the right branch of the tree
            else
            {
               p = p->pRight;
            }
         }
      }
   }
}

/*************************************************
 * BST :: REMOVE
 * Remove a given node as specified by the iterator
 ************************************************/
template <class T>
void BST<T>::remove(BSTIterator<T> &it)
{
   BinaryNode<T> *p = it.getNode();

   // Case 1: no children
   if (p->pRight == NULL && p->pLeft == NULL)
   {
      if (p->pParent != NULL && p->pParent->pRight == p)
      {
         p->pParent->pRight = NULL;
      }
      if (p->pParent != NULL && p->pParent->pLeft == p)
      {
         p->pParent->pLeft = NULL;
      }
      delete p;
   }

   // Case 2: One child

   // child on the left side of node to be deleted
   else if (p->pRight == NULL && p->pLeft != NULL)
   {
      p->pLeft->pParent = p->pParent;
      if (p->pParent != NULL && p->pParent->pRight == p)
      {
         p->pParent->pRight = p->pLeft;
      }
      if (p->pParent != NULL && p->pParent->pLeft == p)
      {
         p->pParent->pLeft = p->pLeft;
      }
      delete p;
   }
   // child on the right side of node to be deleted
   else if (p->pLeft == NULL && p->pRight != NULL)
   {
      p->pRight->pParent = p->pParent;
      if (p->pParent != NULL && p->pParent->pRight == p)
      {
         p->pParent->pRight = p->pRight;
      }
      if (p->pParent != NULL && p->pParent->pLeft == p)
      {
         p->pParent->pLeft = p->pRight;
      }
      delete p;
   }

   // Case 3: two children
   else if (p->pLeft != NULL & p->pRight != NULL)
   {
      BinaryNode<T> *copy = p;

      p = p->pRight;

      while (p->pLeft)
      {
         p = p->pLeft;
      }

      copy->data = p->data;
      p->pRight->pParent = p->pParent;
      if (p->pParent != NULL && p->pParent->pRight == p)
      {
         p->pParent->pRight = p->pRight;
      }
      if (p->pParent != NULL && p->pParent->pLeft == p)
      {
         p->pParent->pLeft = p->pRight;
      }
      delete p;
   }
}

/****************************************************
 * BST :: FIND
 * Return the node corresponding to a given value
 ****************************************************/
template <class T>
BSTIterator<T> BST<T>::find(const T &t)
{
   if (root == NULL)
   {
      return BSTIterator<T>(NULL);
   }
   else
   {
      BinaryNode<T> *p = root;
      for (int i = 0; i < this->size(); i++)
      {
         if (p == NULL)
         {
            return BSTIterator<T>(NULL);
         }
         if (p->data == t)
         {
            return BSTIterator<T>(p);
         }
         else if (p->data < t)
         {
            p = p->pRight;
         }
         else if (p->data > t)
         {
            p = p->pLeft;
         }
      }
   }
}

/**********************************************************
 * BINARY SEARCH TREE ITERATOR
 * Forward and reverse iterator through a BST
 *********************************************************/
template <class T>
class BSTIterator
{
public:
   // constructors
   BSTIterator(BinaryNode<T> *p = NULL) { nodes.push(p); }
   BSTIterator(Stack<BinaryNode<T> *> &s) { nodes = s; }
   BSTIterator(const BSTIterator<T> &rhs) { nodes = rhs.nodes; }

   // assignment
   BSTIterator<T> &operator=(const BSTIterator<T> &rhs)
   {
      // need an assignment operator for the Stack class.
      nodes = rhs.nodes;
      return *this;
   }

   // compare
   bool operator==(const BSTIterator<T> &rhs) const
   {
      // only need to compare the leaf node
      return rhs.nodes.const_top() == nodes.const_top();
   }
   bool operator!=(const BSTIterator<T> &rhs) const
   {
      // only need to compare the leaf node
      return rhs.nodes.const_top() != nodes.const_top();
   }

   // de-reference. Cannot change because it will invalidate the BST
   T &operator*()
   {
      return nodes.top()->data;
   }

   // iterators
   BSTIterator<T> &operator++();
   BSTIterator<T> operator++(int postfix)
   {
      BSTIterator<T> itReturn = *this;
      ++(*this);
      return itReturn;
   }
   BSTIterator<T> &operator--();
   BSTIterator<T> operator--(int postfix)
   {
      BSTIterator<T> itReturn = *this;
      --(*this);
      return itReturn;
   }

   // must give friend status to remove so it can call getNode() from it
   friend void BST<T>::remove(BSTIterator<T> &it);

private:
   // get the node pointer
   BinaryNode<T> *getNode() { return nodes.top(); }

   // the stack of nodes
   Stack<BinaryNode<T> *> nodes;
};

/**************************************************
 * BST ITERATOR :: INCREMENT PREFIX
 * advance by one
 *************************************************/
template <class T>
BSTIterator<T> &BSTIterator<T>::operator++()
{
   // do nothing if we have nothing
   if (nodes.top() == NULL)
      return *this;

   // if there is a right node, take it
   if (nodes.top()->pRight != NULL)
   {
      nodes.push(nodes.top()->pRight);

      // there might be more left-most children
      while (nodes.top()->pLeft)
         nodes.push(nodes.top()->pLeft);
      return *this;
   }

   // there are no right children, the left are done
   assert(nodes.top()->pRight == NULL);
   BinaryNode<T> *pSave = nodes.top();
   nodes.pop();

   // if the parent is the NULL, we are done!
   if (NULL == nodes.top())
      return *this;

   // if we are the left-child, got to the parent.
   if (pSave == nodes.top()->pLeft)
      return *this;

   // we are the right-child, go up as long as we are the right child!
   while (nodes.top() != NULL && pSave == nodes.top()->pRight)
   {
      pSave = nodes.top();
      nodes.pop();
   }

   return *this;
}

/**************************************************
 * BST ITERATOR :: DECREMENT PREFIX
 * advance by one
 *************************************************/
template <class T>
BSTIterator<T> &BSTIterator<T>::operator--()
{
   // do nothing if we have nothing
   if (nodes.top() == NULL)
      return *this;

   // if there is a left node, take it
   if (nodes.top()->pLeft != NULL)
   {
      nodes.push(nodes.top()->pLeft);

      // there might be more right-most children
      while (nodes.top()->pRight)
         nodes.push(nodes.top()->pRight);
      return *this;
   }

   // there are no left children, the right are done
   assert(nodes.top()->pLeft == NULL);
   BinaryNode<T> *pSave = nodes.top();
   nodes.pop();

   // if the parent is the NULL, we are done!
   if (NULL == nodes.top())
      return *this;

   // if we are the right-child, got to the parent.
   if (pSave == nodes.top()->pRight)
      return *this;

   // we are the left-child, go up as long as we are the left child!
   while (nodes.top() != NULL && pSave == nodes.top()->pLeft)
   {
      pSave = nodes.top();
      nodes.pop();
   }

   return *this;
}

#endif // BST_H
