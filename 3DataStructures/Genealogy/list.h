/***********************************************************************
* Header:
*    Node
* Summary:
*   Contains the class definition of the List.
*
*    This will contain the class definition of:
*        List         : A class that is used in linked lists
* Author
*    Lance Bunch
************************************************************************/
#ifndef LIST_H
#define LIST_H

using namespace std;

/************************************************
 * CLASS :: NODE
 * A class that represents links in the linked list
 ***********************************************/
template <class T>
class Node
{
public:
   T data;
   Node<T> *pNext;
   Node<T> *pPrev;
   Node()
   {
      pNext = NULL;
      pPrev = NULL;
   }
   Node(T data)
   {
      this->data = data;
      pNext = NULL;
      pPrev = NULL;
   }
};

/************************************************
 * FREEDATA
 * Frees the allocated memory
 ***********************************************/
template <class T>
Node<T> *freeData(Node<T> *&pHead)
{
   if (pHead == NULL)
   {
      return NULL;
   }
   freeData(pHead->pNext);
   delete pHead;
   pHead = NULL;
}

// Prototype for ListIterator
template <class T>
class ListIterator;

/************************************************
 * LIST
 * A class that begins a linked list of nodes holding data
 ***********************************************/
template <class T>
class List
{
private:
   Node<T> *head; // pointer to the head of the list
   Node<T> *tail; // pointer to the tail of the list
   int numItems;  // how many items are currently listed
public:
   // default constructor
   List() : numItems(0), head(NULL), tail(NULL) {}

   // copy constructor
   List(List<T> &rhs) throw(const char *);

   // destructor
   ~List() { freeData(head); }

   // assignment operator overload
   List<T> &operator=(List<T> &rhs) throw(const char *);

   // return whether or not the list is empty
   bool empty() const { return numItems == 0; }

   // removes the amount of items and frees used memory
   void clear()
   {
      if (head != NULL)
         freeData(head);
      tail = NULL;
      numItems = 0;
   }

   // return how many items are in the list
   int size() const { return numItems; }

   // puts an item on the back of the list
   void push_back(const T &t) throw(const char *);

   // puts an item on the front of the list
   void push_front(const T &t) throw(const char *);

   // returns the item currently at the front of the list
   T &front() const { return head->data; }

   // returns the item currently at the back of the list
   T &back() const { return tail->data; }

   // inserts an item in the middle of a list
   ListIterator<T> insert(ListIterator<T> &it, const T &t) throw(const char *);

   // removes an item from the middle of a list
   void remove(ListIterator<T> it) throw(const char *);

   // return an iterator to the beginning of the list
   ListIterator<T> begin() { return ListIterator<T>(head); }

   // return an iterator to the last element in the list
   ListIterator<T> rbegin() { return ListIterator<T>(tail); }

   // return an iterator referring to the past-the-end element
   ListIterator<T> end() { return ListIterator<T>(NULL); }

   // return an iterator referring to the past-the-front element
   ListIterator<T> rend() { return ListIterator<T>(NULL); }
};

/**************************************************
 * LIST ITERATOR
 * An iterator through LIST
 *************************************************/
template <class T>
class ListIterator
{
public:
   // default constructor
   ListIterator() : p(NULL) {}

   // initialize to direct p to some item
   ListIterator(Node<T> *p) : p(p) {}

   // not equals operator
   bool operator!=(const ListIterator &rhs) const
   {
      return rhs.p != this->p;
   }

   bool operator==(const ListIterator &rhs) const
   {
      return rhs.p == this->p;
   }

   // dereference operator
   T &operator*()
   {
      return p->data;
   }

   // prefix increment
   ListIterator<T> &operator++()
   {
      p = p->pNext;
      return *this;
   }

   // postfix increment
   ListIterator<T> operator++(int postfix)
   {
      ListIterator tmp(*this);
      p = p->pNext;
      return tmp;
   }

   // prefix decrament
   ListIterator<T> operator--()
   {
      p = p->pPrev;
      return *this;
   }

   // postfix decrament
   ListIterator<T> operator--(int postfix)
   {
      ListIterator tmp(*this);
      p = p->pPrev;
      return tmp;
   }

   friend ListIterator<T> List<T>::insert(ListIterator<T> &it, const T &t) throw(const char *);
   friend void List<T>::remove(ListIterator<T> t) throw(const char *);

   Node<T> *p;
};

/************************************************
 * LIST
 * Copy Constructor
 ***********************************************/
template <class T>
List<T>::List(List<T> &rhs) throw(const char *)
{
   try
   {
      // if there isn't anything in rhs...
      if (rhs.head == NULL)
      {
         // don't copy anything over and exit the Constructor
         return;
      }

      // make sure head and tail are set to NULL to start
      head = NULL;
      tail = NULL;

      // iterate through the list and push it onto a new list
      for (ListIterator<T> temp = rhs.begin(); temp != rhs.end(); temp++)
      {
         this->push_back(*temp);
      }

      // make sure the number of items are the same
      numItems = rhs.numItems;
   }
   catch (bad_alloc)
   {
      throw "ERROR: Unable to allocate a new node for list\n";
   }
}

/************************************************
 * OPERATOR :: =
 * Overloading the assignment operator
 ***********************************************/
template <class T>
List<T> &List<T>::operator=(List<T> &rhs) throw(const char *)
{
   try
   {
      freeData(this->head);

      this->head = NULL;
      this->tail = NULL;
      for (ListIterator<T> temp = rhs.begin(); temp != rhs.end(); temp++)
      {
         this->push_back(*temp);
      }
      numItems = rhs.numItems;
   }
   catch (bad_alloc)
   {
      throw "ERROR: unable to allocate a new node for a list";
   }
}

/************************************************
 * PUSH_BACK
 * Puts a new node at the back of the list
 ***********************************************/
template <class T>
void List<T>::push_back(const T &t) throw(const char *)
{
   try
   {
      if (head == NULL)
      {
         head = new Node<T>(t);
         tail = head;
      }
      else
      {
         Node<T> *temp = new Node<T>(t);
         temp->pPrev = tail;
         tail->pNext = temp;
         tail = temp;
      }
      numItems++;
   }
   catch (bad_alloc)
   {
      throw "ERROR: unable to allocate a new node for a list";
   }
}

/************************************************
 * PUSH_FRONT
 * Puts a new node at the front of the list
 ***********************************************/
template <class T>
void List<T>::push_front(const T &t) throw(const char *)
{
   try
   {
      if (head == NULL)
      {
         head = new Node<T>(t);
         tail = head;
      }
      else
      {
         Node<T> *temp = new Node<T>(t);
         head->pPrev = temp;
         temp->pNext = head;
         head = temp;
      }
      numItems++;
   }
   catch (bad_alloc)
   {
      throw "ERROR: unable to allocate a new node for a list";
   }
}

/************************************************
 * INSERT
 * Puts data in a determined area in the list
 ***********************************************/
template <class T>
ListIterator<T> List<T>::insert(ListIterator<T> &it, const T &t) throw(const char *)
{
   Node<T> *temp = new Node<T>(t);
   if (head == NULL)
   {
      head = temp;
      tail = temp;
   }
   else if (it.p == NULL)
   {
      tail->pNext = temp;
      temp->pPrev = tail;
      tail = temp;
   }
   else if (it.p == head)
   {
      temp->pNext = head;
      head->pPrev = temp;
      head = temp;
   }
   else
   {
      temp->pNext = it.p;
      temp->pPrev = it.p->pPrev;
      it.p->pPrev = temp;
      temp->pPrev->pNext = temp;
   }
   numItems++;
   return ListIterator<T>(temp);
}

/************************************************
 * REMOVE
 * Removes certain data from the list
 ***********************************************/
template <class T>
void List<T>::remove(ListIterator<T> it) throw(const char *)
{
   if (head == NULL)
   {
      return;
   }
   else if (it.p == tail)
   {
      tail = tail->pPrev;
      tail->pNext = NULL;
      delete tail->pNext;
   }
   else if (it.p == head)
   {
      head = head->pNext;
      head->pPrev = NULL;
      delete head->pPrev;
   }
   else
   {
      it.p->pPrev->pNext = it.p->pNext;
      it.p->pNext->pPrev = it.p->pPrev;
      delete it.p;
   }
}

#endif