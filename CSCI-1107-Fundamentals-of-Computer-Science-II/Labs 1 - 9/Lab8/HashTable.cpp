/*--- HashTable.cpp ------------------------------------------------------------
		Written by: Chris Dang			
		Written for: CSCI 1107
Implement file for Hash Table Class
------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

#include "HashTable.h"

HashTable::~HashTable() {
	// inserts empty nodes to force linked list destructor
	for (int i = 0; i < tableSize; i++) {
		hashTable[i].insert(0, "");
		hashTable[i].insert(0, "");
	}// end for
} // end destructor 

void HashTable::hash(string &str) {

	int index = 0;
	for (int i = 0; i < hashSize; i++) 
		index = index + str[i] ;

	index = index % tableSize ;

	// any hash will be added to the front of the list as order does not matter
	hashTable[index].insert(0, str) ;

	//cout << str << " has now been stored in the hash table.\n" ;
} // end hash

void HashTable::display(ostream &out) const {

	for (int i = 0; i < tableSize; i++) 
	out << "Index " << i << " hash: " << hashTable[i] << endl ;

} // end display

// Non-member functions
ostream &operator<<(ostream &out, const HashTable &hashTable) {
	hashTable.display(out) ;
	return out ;
}//end overloaded insertation operator 