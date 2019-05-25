/****************************************************************************
 Programmer: Tim Wrenn			Class: CSCI 1107

 Basic Operations:

	constructor: constructs an empty Queue
	empty	   : checks if the Queue is empty
	enqueue    : Inserts an element into the Queue
	front	   : Returns the top queue element
	dequeue	   : deletes the top element from the Queue
	display    : Displays the entire Queue

	Note: Program does not terminate if error conditions are met.

	 Chris Dang			CSCI 1107
****************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

#ifndef CIRCULARQ_H
#define CIRCULARQ_H

template <typename qElement>

class CircularQ{

private:
	class Node{
	public:
		qElement data;
		Node * next;

		Node(qElement d){
			data = d;
			next = NULL;
		}// end Node Constructor
	};
public:
   
	typedef Node * NodePointer;

	CircularQ(){ last = NULL; }				// Create an empty Q
/*****************************************************************************
Default Constructor creates an empty Queue

Pre: None

Post: An empty Queue is created and the last pointer is initialized to NULL
******************************************************************************/
	
	
/*****************************************************************************
Display the entire Queue

Pre: Ostream out is open.

Post: Outputs the contents of the Queue in FIFO order
******************************************************************************/
	void display(ostream &out) const{     // Helper method
			
	NodePointer first;			// Need a pointer
	
	if (last == NULL)
		cout << "Queue is empty \n\n" ;
	else{
	
		first = last->next;			// no, intialize to first item in the list
		do{
			out << first->data << "  ";		// output the item
			first = first->next;	// move along
		}while(first != last->next);	// have we traversed the entire list?
	}// end else

}//display method

/*****************************************************************************
Copy Constructor: creates a copy of the original Queue

Pre: Original is the Queue to be copied and is received as a const reference
     parameter

Post: A copy of the original has been constructed
******************************************************************************/
	CircularQ(const CircularQ &origQ){ // Copy constructor

	if(origQ.last != NULL){

		NodePointer origLast = origQ.last,
			origFirst = origLast->next,
			newNode;

		last = new Node(origFirst->data);	
		last->next = last;

		origFirst = origFirst ->next;

		while(origFirst != origLast->next){

			newNode = new Node(origFirst->data);
			newNode->next = last -> next;
			last->next = newNode;
			last = newNode;
			origFirst = origFirst ->next;
		}// end while

	}// end if
}//end copy constructor
					
/*****************************************************************************
Destructor: deletes the Queue

Pre: None
     
Post: The queue is destroyed and empty queue is created
******************************************************************************/
	~CircularQ(){               // Destructor
	
	NodePointer first;

	if(last != NULL){				// empty list?
		first = last->next;			// no, intialize to first item in the list
		while(first != last){
			last->next = first -> next; // avoid memory leak
			delete first;				// get rid of first node	
			first = last->next;				// adjust to the first node.
		}// end while
		delete first;				// make sure the last node is gone
		last = NULL;				// set to an empty list
	}// end if

}// end destructor
	
/*****************************************************************************
Overloaded Assignment Operator: Mimics the assignment operator

Pre: Original is the Queue to be copied and is received as a const reference
     parameter

Post: The current Queue is replaced by a copy of the Queue of rhs and 
	  a reference to it is returned.
******************************************************************************/
	CircularQ &operator=(const CircularQ &rhs){

	if(this != &rhs){

		this->~CircularQ();

		if(rhs.last != NULL){

			NodePointer rhsLast = rhs.last,
				rhsFirst = rhsLast->next,
				newNode;

			last = new Node(rhsFirst->data);	
			last->next = last;

			rhsFirst = rhsFirst ->next;

			while(rhsFirst != rhsLast->next){
				newNode = new Node(rhsFirst->data);
				newNode->next = last -> next;
				last->next = newNode;
				last = newNode;
				rhsFirst = rhsFirst ->next;
			}// end while

		}// end if
	}

	return *this;

}// end assignment operator
			
/*****************************************************************************
enqueue: Inserts an item into the front of the Queue.

Pre: Queue must exist and the parameter item must be initialized.
  
Post: The item is inserted into the Queue.
	  
******************************************************************************/
	template <typename qElement>
	void enqueue(qElement item){

		NodePointer newNode = new Node(item); // Need a node for the Q
		
		if(last == NULL){ // empty Q
			last = newNode; // start constructing the Q
			last->next = last; // pointer to itself since one item
		}
		else{
			newNode->next = last->next; // Chain it 
			last->next = newNode;
			last = newNode;
		}
}// end enqueue
	
/*****************************************************************************
front: Returns the first item in the queue.

Pre: Queue must exist
  
Post: Either an error message will be displayed if the Queue is empty or
	  the front of the Queue is returned.	  
******************************************************************************/

qElement front(){

	//Element garbage = -9999999999999999;
	
	if(empty()){
		cout << "Queue is empty returning garbage" << endl;
		return *new qElement;
	}
	NodePointer first = last->next;
	return (first->data);

}// return front of Q

/*****************************************************************************
dequeue: Deletes the item located in the front of the Queue.

Pre: Checks to see if the Queue is empty
  
Post: Displays an error message if the Queue is empty otherwise the element
	  at the front of the Queue is deleted.	  
******************************************************************************/
	void dequeue(){

	if(empty())
		cout << "Error ----- Cannot delete an item from an empty Queue" 
			 << endl << endl;
	else{

		NodePointer first = last->next;
		if(first == last)
			last = NULL;			// Queue will be empty
		else
			last->next = first->next;
		
		delete first;				// eliminate the node
	}
}// end dequeue

/*****************************************************************************
empty: Checks to see if the Queue is empty

Pre: A queue must be created
  
Post: Returns either true if the Queue is empty, false otherwise.
******************************************************************************/
	bool empty(){return last == NULL;}

private:
	NodePointer last;
};

// Non-member functions
/*****************************************************************************
operator<<: Overloaded operator which allows you to display the contents
			of the entire Queue

Pre: ostream must be opened and the const parameter is passed by reference
  
Post: Calls the method display that displays the entire Queue.
	  
******************************************************************************/
template <typename qElement>
ostream &operator<<(ostream& out, const CircularQ<qElement> &q){
	q.display(out);
	return out;
}// end operator<<

/*****************************************************************************
join: Appends q2 to the end of q1

Pre: Must pass in Circular q1 and q2
  
Post: Returns an appended circular queue 
******************************************************************************/
template <typename qElement>
CircularQ<qElement> join(CircularQ<qElement> q1, CircularQ<qElement> q2) {

	while(!q2.empty()) {
		q1.enqueue(q2.front()) ;
		q2.dequeue() ;
	} // end while

	return q1 ;
}// end join

#endif