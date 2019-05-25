/*--- HashDriver.cpp --------------------------------------------------------
	Chris Dang			Class: CSCI 1107
   Driver file to test hash table.
 --------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Hashlink.h"
#include "HashTable.h"

int main() {

	// file input
	ifstream infile;
	infile.open("DearMarlin.txt") ;
	if (!infile) {
		cerr << "Error opening file. --- Terminating program\n\n" ;
		exit(1107) ;
	} // end if

	string str = "Hello";
	string str2 = "How are you?" ;
	string str3 = "I turn strings into hash" ;
	string word ;
	HashTable testHash, dearMarlin ;
	

	cout << "Entering Test strings\n" ;
	
	testHash.hash(str) ;
	testHash.hash(str2) ;
	testHash.hash(str3) ;

	cout  << "Now displaying hash:\n" 
		  << "--------------------------\n"; 
	cout << testHash ;

	cout << "\nNow adding Dear Marlin letter\n" ;

	while (infile >> word) 
		dearMarlin.hash(word) ;

	cout  << "Now displaying hash for Dear Marlin letter:\n" 
		  << "--------------------------\n";

	cout << dearMarlin ;

	infile.close() ; // close the file

	// destructors are called in due to loss of scope of has tables

	return 0 ;

} // end main