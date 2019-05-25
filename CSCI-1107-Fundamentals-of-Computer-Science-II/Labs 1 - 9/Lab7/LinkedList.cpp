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
		out << ptr -> data ;
		ptr = ptr -> next ;
	}// end while
}// end display ;

void LinkedList::insert(int index, int dataValue) {
	Node *nPtr = new(nothrow) Node(dataValue) ;

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
		for (int i = 1; i < index - 1; i++) 
			predPtr = predPtr -> next ;
		nPtr -> next = predPtr -> next ;
		predPtr -> next = nPtr ;
	}// end else 

	++mySize ;

}//end insert

ostream &operator<<(ostream &out, const LinkedList &List) {

	List.display(out) ;
	return out ;
}//end overloaded insertation operator ;