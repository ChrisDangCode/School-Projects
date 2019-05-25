/*--- LQueue.cpp ----------------------------------------------------------
             This file implements LQueue member functions.
			 Chris Dang			CSCI 1107
-------------------------------------------------------------------------*/
 
#include <new>
using namespace std;

#include "LQueue.h"

//--- Definition of Queue constructor
Queue::Queue()
: myBack(0)
{}

//--- Definition of Queue copy constructor
Queue::Queue(const Queue & original)
{
   myBack = 0;
   if (!original.empty())
   {
	   Queue::NodePointer first ;
      // Copy first node
      first = myBack = new Queue::Node(original.front());
	  Queue::NodePointer origPtr ;
      // Set pointer to run through original's linked list
	  if (original.myBack->next != 0)			// if there is more than 1 item in original
		origPtr = original.myBack->next;
	  else										// if there is only 1 item in original;
		origPtr = original.myBack;
      while (origPtr != 0)
      {
         myBack->next = new Queue::Node(origPtr->data);
         myBack = myBack->next;
         origPtr = origPtr->next;
      }
   }
}

//--- Definition of Queue destructor
Queue::~Queue()
{ 
  // Set pointer to run through the queue
  Queue::NodePointer prev, ptr ;
	  
	  if (myBack == myBack)
		prev = myBack ;
	  else
		prev = myBack->next ;
	  
  while (prev != 0)
    {
	if (ptr != myBack)
		ptr = prev->next;
      delete prev;
	  if (ptr != NULL)
		prev = ptr;
	  else 
		  prev = 0 ;
    }
}

//--- Definition of assignment operator
const Queue & Queue::operator=(const Queue & rightHandSide)
{
   if (this != &rightHandSide)         // check that not q = q
   {
      this->~Queue();                  // destroy current linked list
      if (rightHandSide.empty())       // empty queue
         myBack = 0;
      else
      {                                // copy rightHandSide's list
		  Queue::NodePointer first ;
         // Copy first node
         first = myBack = new Queue::Node(rightHandSide.front());

         // Set pointer to run through rightHandSide's linked list
         Queue::NodePointer rhsPtr = rightHandSide.myBack->next;
         while (rhsPtr != rightHandSide.myBack)
         {
           myBack->next = new Queue::Node(rhsPtr->data);
           myBack = myBack->next;
           rhsPtr = rhsPtr->next;
         }
		 myBack->next = first ;		// sets back to point to first in list
      }
   }
   return *this;
}

//--- Definition of empty()
bool Queue::empty() const
{ 
   return (myBack == 0); 
}

//--- Definition of enqueue()
void Queue::enqueue(const QueueElement & value)
{
   Queue::NodePointer newptr = new Queue::Node(value);
   if (empty()) {    // if list is empty
      myBack = newptr;
	  myBack->next = myBack ;
   }
   else {
	   NodePointer first ;
	   if (myBack->next == myBack)
		   first = myBack ;
	   else 
		   first = myBack->next ;

      myBack->next = newptr;
      myBack = newptr;
	  myBack->next = first ;
   }
   //cout << myBack ;
}

//--- Definition of display()
void Queue::display(ostream & out) const {
	if (!empty()){
		
		Queue::NodePointer ptr = myBack -> next;
	
		do { // outputs all data except last element
		 out << ptr->data << "  \n";
		 ptr = ptr -> next ;
		} while (ptr != myBack);	
		if (myBack->next != myBack)		//if only 1 item in list, list it once
			out << myBack->data	; //outputs last element
	}
}

//--- Definition of front()
QueueElement Queue::front() const
{
   if (!empty()) {
	   if (myBack->next != myBack)			// if there is more than 1 item in original
		return (myBack->next->data);
	  else								// if there is only 1 item in original;
		return (myBack->data);
   }
   else
   {
      cerr << "*** Queue is empty "
              " -- returning garbage ***\n";
      QueueElement * temp = new(QueueElement);  
      QueueElement garbage = *temp;     // "Garbage" value
      delete temp;
      return garbage;
   }
}

//--- Definition of dequeue()
void Queue::dequeue()
{
	NodePointer first ;		
   if (!empty()) {
      Queue::NodePointer ptr = myBack->next;		// points to node that is to be deleted
	 
		  first = ptr->next ;		// get a new front of list
	 // cout << "\nDeleting ptr: " << ptr->data << endl ;
      delete ptr;
      if (!empty())									
         myBack->next = first ;
	  
	  if (myBack->next == myBack) {					// if there is more than 1 item in list,
		  myBack = 0 ;}
   }   
   else
      cerr << "*** Queue is empty -- can't remove a value ***\n";
}
