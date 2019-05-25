//-LinkList.cpp Implementation File-----------------------------
//   Written by: Chris Dang			Class: CSCI 1107
//-------------------------------------------------------------

#include <iostream>
using namespace std;

#include "LinkedList.h"

int LinkedList::size() const {
	return mySize ;
}//end size getter

void LinkedList::display(ostream &out) const {

	LinkedList::NodePointer ptr = first ;
	while (ptr != NULL) {
		out << ptr -> data << " " ;
		ptr = ptr -> next ;
	}// end while
}// end display ;

void LinkedList::insert(int index, int dataValue) {

	Node *nPtr = new(nothrow) Node(dataValue) ;

	//error checking: if index to be passed in is out of bounds of list,
	//the index isn't used, the linked list remains unchanged, 
	//and exectution continues
	if (index < 0 || index > mySize)
		cerr << "Index " << index << " is not a valid index.\n" ;

	else {

		//if trying to insert new node to first of the list,
		//this if will handle the inseration
		if (index == 0) {
			nPtr -> next = first;
			first = nPtr ;
		}//end if

		//if trying to insert somewhere else in the list
		//other than first position, this else will will handle the insertation
		else {
			Node *predPtr = first ;
			for (int i = 1; i <= index - 1; i++) 
				predPtr = predPtr -> next ;
			nPtr -> next = predPtr -> next ;
			predPtr -> next = nPtr ;
		}// end else 

	++mySize ;
	
	}// end else

}//end insert

void LinkedList::erase(int index) {

	//error checking: if index to be passed in is out of bounds of list,
	//the index isn't used, the linked list remains unchanged, 
	//and exectution continues
	if (index < 0 || index > mySize)
		cerr << "Index " << index << " is not a valid index.\n" ;

	else {

		//if trying to erase node at beginning of list
		//this if will handle the erase
		if (index == 0) {
			Node *ptr = first ;
			first = first -> next ;
			delete ptr ;
		}// end if

		else {
			Node *predPtr = first ;
			Node *ptr = first -> next ;

			for (int i = 1; i < index; i++) {
				predPtr = ptr ;
				ptr = ptr -> next ;
			}//end for
			predPtr -> next = ptr -> next ;
			delete ptr ;

			//if deleting the last node from list, 
			//this will handle setting a new last node by setting
			//the next pointer to null
			if (index == mySize - 1)
				predPtr -> next = NULL ;

		}// end else

		--mySize ;

	}//end else 
}// end erase 

LinkedList::~LinkedList() {

	// creates ptr and points toward first node in list
	NodePointer ptr = first -> next ;

	// traverses list, reassigns first of the list, and
	// deletes nodes in traversal
	for (int i = 1; i < mySize; i++) {
		first = ptr -> next ;
		delete ptr ;
		ptr = first ;
	} // end for

	if (first == 0) 
		cout << "List destroyed\n" ;
	else 
		cout << "List not destroyed\n" ;
} // end destructor 

LinkedList::LinkedList(const LinkedList & origList) {

	// copies size of original list to new list
	mySize = origList.mySize ;

	// if original list is emtpy, first is set to NULL pointer
	if (origList.first -> next == NULL)
		first = NULL ;

	else {
		NodePointer origPtr, lastPtr ;
		origPtr = origList.first -> next ;

		Node *nPtr = new(nothrow) Node(origList.first -> data) ;
		lastPtr = nPtr ;

		first = lastPtr ;

		// traverses the original list, constructing nodes based of the
		// originial list and adding them to the new list
		for (int i = 1; i < mySize ; i++) {
			Node *nPtr = new(nothrow) Node(origPtr -> data) ;
			lastPtr -> next = nPtr ;
			lastPtr = lastPtr -> next ;
			origPtr = origPtr -> next ;
		} // end for ;
	} // end else
} // end copy constructor

LinkedList LinkedList::operator=(const LinkedList & origList) {

	// checks to see if this is a self assignemnet
	// if it is a self assignment, returns itself
	if (this != &origList) {

		// destroys value of left hand side of assignment
		// to avoid memory leak
		this -> ~LinkedList() ;
		
		// copies size of original list to new list
	mySize = origList.mySize ;

	// if original list is emtpy, first is set to NULL pointer
	if (origList.first -> next == NULL)
		first = NULL ;

	// creates a copy of the rhs list to the left hand side
	else {
		NodePointer origPtr, lastPtr ;
		origPtr = origList.first -> next ;

		Node *nPtr = new(nothrow) Node(origList.first -> data) ;
		lastPtr = nPtr ;

		first = lastPtr ;

		// traverses the original list, constructing nodes based of the
		// originial list and adding them to the new list
		for (int i = 1; i < mySize ; i++) {
			Node *nPtr = new(nothrow) Node(origPtr -> data) ;
			lastPtr -> next = nPtr ;
			lastPtr = lastPtr -> next ;
			origPtr = origPtr -> next ;
		} // end for ;
	} // end else
		
	}// end if

	return *this ;

} // end overloaded assignment operator 

// Non-member functions
ostream &operator<<(ostream &out, const LinkedList &List) {
	List.display(out) ;
	return out ;
}//end overloaded insertation operator 