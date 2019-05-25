/*--- linktester.cpp --------------------------------------------------
  A program for testing class LinkedList.
 
  Written by:   Larry R. Nyhoff
  Written for:  Lab Manual for ADTs, Data Structures, and Problem
                Solving with C++, 2E

                    Lab #5.1 and Projects 5.1
   
   Chris Dang			Class: CSCI 1107
   
  ---------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "LinkedList.h"

int main()
{
   LinkedList intList;       // TEST THE CONSTRUCTOR
   cout << "Constructing intList\n";

// ---- PART 1 ---- TEST SIZE OPERATION

   cout << "Size of intList is " << intList.size() << endl; 

//---- END PART 1 ----


// ---- PART 2A ---- TEST OUTPUT OF EMPTY LIST USING display()
   cout << "Empty List (using display): \n";
   intList.display(cout);
   cout << endl; 
//---- END PART 2A ----

// ---- PART 2B ---- TEST OUTPUT OF EMPTY LIST USING <<
   cout << "Empty List (using <<): \n"
        << intList << endl;
//---- END PART 2B ----*/


// ---- PART 3 ---- TEST INSERT OPERATION
   for (int i = 0; i < 9; i++)
   {                                    
      intList.insert(i/2, 10*i);          //  -- insert 10*i at position i/2
      cout << intList << endl ;            // test output
   }

  //-- Test insert at end of list:
  intList.insert(intList.size(), 999);
  cout << "\ninsert 999 at end of list:\n" 
       << intList << endl;

  //-- Test for illegal inserts
  cout << "Try inserting at positions -1 and 20:\n";
  intList.insert(-1, -99);
  intList.insert(20, 200);

//---- END PART 3 ----*/

// ---- PART 4 ---- TEST ERASE OPERATION
  cout << "\nRemove last node:\n";
  intList.erase(intList.size() - 1);
  cout << intList << endl;

  cout << "\nRemove first node:\n";
  intList.erase(0);
  cout << intList << endl;

  cout << "\nRemove node at position 4:\n";
  intList.erase(4);
  cout << intList << endl;

  //-- Test for illegal deletes
  cout << "Try deleting at positions -1 and 20\n"; 
  intList.erase(-1); 
  intList.erase(20); 

/*---- END PART 4 ----*/

// ---- PART 5 ---- TEST DESTRUCTOR
   {
      LinkedList anotherList ;
      for (int i = 0; i < 5; i++)
         anotherList.insert(i, 20 * i);
      cout << "\nHere's another list:\n" << anotherList << endl;
      cout << "Now destroying this list\n";
   }
   cout << "*** If the destructor was called, anotherList was destroyed ***\n";
/*---- END PART 5 ----*/

// ---- PART 6 ---- TEST COPY CONSTRUCTOR
   cout << "\n\nTesting copy constructor" << endl;
   cout << LinkedList(intList);

   cout << "\n\nOriginal list:";          // output the original to make sure
   cout << intList << endl;               // it hasn't been changed.

//---- END PART 6 ----*/

// ---- PART 7 ----

   //creates linked list with values 11, 22, 33, 44, and 55
   LinkedList var , test ;
   for (int i = 0; i < 5; i++) 
	   var.insert(i, 11 * (i + 1)) ; 
   //creates linked list with values 22, 44, 66, and 88
   for (int i = 0; i < 4; i++) 
	   test.insert(i, 22 * (i + 1)) ;

	cout << "\nTest list var contains:\n" << var << endl ;
	cout << "\nTesting self assignement. var before:\n" 
		 << var << endl ;

	var = var ;

	cout << "\nvar after self assignment:\n"
		 << var << endl 
	     << "\nTesting assignment of var = test\n" ;

	var = test ;

	cout << "var after assignment of test is now:\n" 
		 << var ;
		 

// ---- END PART 7 ----

}
