//******************************************************************************
//
//  Programmer: Chris Dang			Class: CSCI 1106 Fall 2014
// 
//  Description: This program will create the user entered number of terms to
//  a sequence.
//
//
//
//
//
//******************************************************************************

#include <iostream>
#include <string>
using namespace std;


void headerDsc(void) ;
void promptIpt (void) ;
int grabInput(void) ;

int main () {

	headerDsc() ;
	grabInput() ;

	
return 0 ;

} // end main ;

void headerDsc(void) { // Top Description

	string header  =
		"*****************************************************************\n"
		"This program will display the nth number of terms of a sequence\n"
		"based upon the value entered.\n"
		"*****************************************************************\n\n" ;

	cout << header ;
} // end headerDsc

void promptIpt(void) {

	string header = "Please enter a value: " ;

	cout << header ;

} // promptIpt

int grabInput (void) {

	promptIpt() ;

	int nTerms ;

	cin >> nTerms ;

	return nTerms ;

} // end grabInput