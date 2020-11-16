/***********************************************************************
* Header:
*    Node
* Summary:
*   Contains the class definition of the Node. Also incorporates
*   non-member functions to help traverse and make a linked list.
*
*    This will contain the class definition of:
*        Node         : A class that is used in linked lists
* Author
*    Lance Bunch
************************************************************************/

#ifndef NODE_H
#define NODE_H

using namespace std;

template <class T>
class Node
{

   public:
      T data;
      Node <T> * pNext;
      Node() { pNext = NULL; }
      Node(T data) { this->data = data; this->pNext = NULL; }
      Node(T data, Node <T> * pNext) { this->data = data;
                                       this->pNext = pNext; }
};


/**********************************************************************
 * COPY
 * Copies the source link to a new link
 ***********************************************************************/
template <class T>
Node <T> * copy(const Node <T> * pSource)
{
   // if there isn't anything in pSource...
   if (pSource == NULL)
   {
      return NULL;
   }

   // create a new node class somewhere in memory, and make
   // the data of that first node equal to the first node
   // of the source node's data
   Node <T> * copyNode = new Node <T>(pSource->data);

   // create another node and set it equal to the copyNode
   // so we can have the beginning of the link to return
   Node<T> * pHead = copyNode;

   // to keep track of adding on new nodes to the link
   Node <T> * prev = copyNode;

   // as long as the address of the next node of the Source
   // doesn't equal nothing...
   while (pSource->pNext != NULL)
   { 
      // create a new node with the source's next data, and
      // assign it to copyNode
      copyNode = new Node <T> (pSource->pNext->data);

      // Link the address of the new node to the prev node
      prev->pNext = copyNode;

      // move on to the next node in the source's list
      pSource = pSource->pNext;

      // prev is now ready to link another new node
      prev = copyNode;
   }
   // return the head of the newly created link
   return pHead;
}

/**********************************************************************
 * INSERT
 * Adds another item onto the linked list
 * Also handles replacing first item
 ***********************************************************************/
template <class T>
void insert(const T & t, Node <T> * & pSource, bool pHead = false)
{
   Node <T> * newNode = new Node <T>;
   newNode->data = t;
   if (pHead || pSource == NULL)
   {
      newNode->pNext = pSource;
      pSource = newNode;
   }
   else
   {
      newNode->pNext = pSource->pNext;
      pSource->pNext = newNode;
   }
}

/**********************************************************************
 * FIND
 * Finds something in the linked list
 ***********************************************************************/
template <class T>
Node <T> * find(Node <T> * pHead, const T & t)
{
   Node <T> * current = pHead;
   while (current != NULL && current->data != t)
   {
      current = current->pNext;
   }
   return current;
}

/**********************************************************************
 * OPERATOR :: <<
 * Organizes how to display a linked list
 ***********************************************************************/
template <class T>
ostream & operator << (ostream & out, Node <T> * rhs)
{
   if (rhs == NULL)
   {
      return out;
   }

   out << rhs->data;
   if(rhs->pNext == NULL)
   {
      out << "";
   }
   else
   {
      out << ", ";
   }
   out << rhs->pNext;

   return out;
}

/**********************************************************************
 * FREEDATA
 * Deletes all of the memory in a list
 ***********************************************************************/
template <class T>
Node <T> * freeData(Node <T> * & pHead)
{
   if (pHead == NULL)
   {
      return NULL;
   }
   freeData(pHead->pNext);
   delete pHead;
   pHead = NULL;
}
// p1 = p2
//    this makes the address of p1 the same as p2

// *p1 = *p2
//    this makes the node of p1 the same as the node of p2

#endif