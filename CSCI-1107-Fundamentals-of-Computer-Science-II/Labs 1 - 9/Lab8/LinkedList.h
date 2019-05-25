/*--- LinkedList.h --------------------------------------------------------
  This header file contains the declarations of LinkedList, a class for
  singly-linked lists.
 
  Written by:   Larry R. Nyhoff
  Written for:  Lab Manual for ADTs, Data Structures, and Problem
                Solving with C++, 2E

                    Lab #5.1 and Projects 5.1 & 5.2
                              
   Add a list of the basic operations including brief descriptions.
   
	Chris Dang			Class: CSCI 1107
   
 --------------------------------------------------------------------------*/

#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
using namespace std;

	typedef int ElementType ;


class LinkedList
{
 public:
   //------ LinkedList OPERATIONS
	

     // Precondition:  None.
     // Postcondition: This list's data members have been initialized 
     // for an empty list.
	 LinkedList(){first = NULL; mySize = 0;} ;

  // Prototype and document the size() operation here
	//Function: size
	//Precondition: none
	//Postcondition: returns size of linked list as an integer
	 int size() const ;

  // Prototype and document display() here
	 //Function: display
	 //Precondition: ostream object must be used
	 //Postcondition: contents of current node are insirted into ostream object
	 void display(ostream &out) const ;
 
  // Prototype insert() here
  /*----------------------------------------------------------------------
     Insert a value into a LinkedList at a given index.

     Precondition:  The first parameter, index, is an unsigned value with
         0 <= index <= mySize; the second parameter, dataValue, is an  
         ElementType value.  index = 0 denotes insertion at the beginning
         of the list, and index = mySize denotes insertion at the end 
         (after the current last element).
     Postcondition: dataValue has been inserted into this LinkedList
         object at the position determined by index (provided index 
         is a legal position).
  -----------------------------------------------------------------------*/
	 void insert(int index, int dataValue) ;
  // Prototype erase() here
  
  /*----------------------------------------------------------------------
     erase() removes a value from a LinkedList at a given index.

     Precondition:  The parameter index, an unsigned value, satisfies
                              0 <= index < mySize.  
     Postcondition: The data value at the position determined by index
         (provided index is a legal position) has been removed from 
         this LinkedList object. 
  -----------------------------------------------------------------------*/
	void erase(int index) ;
 
   // Prototype and document the destructor here
	~LinkedList() ;
  
  // Prototype and document the copy constructor here
	LinkedList(const LinkedList & origList) ;

  // Prototype and document the assignment operator here
	LinkedList operator=(const LinkedList & origList) ;

private:
  class Node
  {
    public:

		ElementType data ;
		Node *next ;

     //------ Node OPERATIONS

     // Prototype the Node constructor here

     /* --- The Node class constructor initializes a Node's data members.

        Precondition:  None
        Receive:       dataValue, an ElementType value;
        Postcondition: The data and next members have been set to
                       dataValue and 0, respectively.
     -------------------------------------------------------------------*/
		Node(ElementType dataValue ){data = dataValue, next = NULL ;};
   }; //--- end of Node class


//------ DATA MEMBERS OF LinkedList
   // declare first as a pointer to a Node and declare mySize

	Node *first ;
	int mySize ;

   typedef Node *NodePointer;
   

}; //--- end of LinkedList class

// Put prototype of operator<<() here
//-------------Non-member function -------------

ostream &operator<<(ostream &out, const LinkedList &List) ;

#endif
