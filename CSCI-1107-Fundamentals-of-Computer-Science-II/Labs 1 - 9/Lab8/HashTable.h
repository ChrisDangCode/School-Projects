/*--- HashTable.h -------------------------------------------------------------
		Written by: Chris Dang		
		Written for: CSCI 1107
Header file for Hash Table Class
------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;

#include "Hashlink.h"

const int tableSize = 13 ;
const int hashSize = 3 ;

class HashTable 
{
	public:
		// default constructor
		// pre: LinkedList.h must be included, tableSize must be definced as
		//      a global constant.
		// post: A HashTable with linked list array will be created.
		HashTable(){} ;


		// destructor
		// pre: none
		// post: deletes linked lists in HashTable
		~HashTable() ;
	
		// function: hash
		// pre: must pass in a string object
		// post: stores string into hash table
		void hash(string &str) ;

		void display(ostream &out) const ;

private:

	LinkedList hashTable[tableSize] ;


} ; // end HashTable


// Non-member functions
ostream &operator<<(ostream &out, const HashTable &hashTable) ;