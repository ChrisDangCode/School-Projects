//******************************************************************************
//
//  Programmer: Chris Dang			Class: CSCI 1106 Fall 2014
// 
//  Description: Testing data for lab 13 in CSCI 1106
//
//******************************************************************************

#include <iostream>
using namespace std;

int pointerFun (int *numX, int *numY) ;

int main () {

	/*
	int *ptr ;
	ptr = new int [2] ; // request OS to give 20 storage locations
	if (ptr == NULL) {
		cout << "\n\n Error allocating memory --- terminating\n\n";
		exit (1106) ;
	} // end if

	for (int i = 0; i < 2; i++){
		cout << "Please enter integer values to be stored in the array: " ;
		cin >> ptr[i] ;
	} // end for

	for (int i = 0; i < 25; i++){
		cout << "   " << *(ptr + i) ;
	} // end for

	delete [] ptr ;

	*/
	int x, y, newNum ;
	int *numX, *numY ;

	cout << "Please enter value for x: " ;
	cin >> x ;

	cout << "Please enter value for y: " ;
	cin >> y ;

	cout << "The values entered:\n" <<
		    "X is: " << x << endl << 
		    "Y is: " << y << endl << endl ;

	numX = &x ;
	numY = &y ;

	newNum = pointerFun( numX , numY ) ;

	cout << "The number after pointerFun is: " << newNum << endl << endl;

	return 0 ;
} // end main

int pointerFun (int *numX, int *numY) {

	int temp = *numX ;
	*numY = temp * 10 ;

	return *numX + *numY ;

} // end pointerFun