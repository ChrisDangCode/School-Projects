//******************************************************************************
//
//  Programmer: Chris Dang			Class: CSCI 1106 Fall 2014
// 
//  Description: This program will check if a user entered number is a prime 
//  number or not. The program will then display the number entered as well 
//	as whether the number is prime or not.
//
//******************************************************************************

#include <iostream>
#include <string>
#include <cmath> // needed for sqrt
using namespace std;

const string pleaseEnter = "Please enter a positive integer: " ;

const string header = "This program will take in a positive integer and "
 "determine if it is prime.\n" ;

bool valPos (int num) ;					      // validates if num is postive
bool numIsEven(int num) ;					  // checks for conditions
bool numIsGreaterThanTwo (int num) ;		  
bool numIsNotDivisibleBySqrtOrLess (int num) ;
bool IsNumIsOne (int num) ;

int main () {

int num ;

cout << header ; // starting info
cout << pleaseEnter;
cin >> num ;

if ((valPos(num)) == true) { // program won't continue if num is zero or less


	if (IsNumIsOne(num) == true || numIsEven(num) == true && numIsGreaterThanTwo(num) == true
		 || numIsNotDivisibleBySqrtOrLess (num) == false) {
		cout << "\nNumber entered: " << num << endl << 
		num << " is not a prime number. \n\n" ;

	}
	else
		cout << "\nNumber entered: " << num << endl << 
		num << " is a prime number. \n\n" ;


} // end val


return 0 ;
} // End main


//******************************************************************************
// Function: valPos
//
// Description: Validates if input is a positive number.
//
// Pre: The parameter must contain a number
//
// Post: Returns false if it is not a positive number.
//		 Will return true if it is a positive number.
//
//******************************************************************************
bool valPos(int num) {
	if (num <= 0) { // If num is less than or equal to zero, it is not positive
		cout << "\nNumber entered must be positive number.\n" ;
		return false;}
	else
		return true;
} // end valPos


//******************************************************************************
// Function: numIsEven
//
// Description: Checks if a number is even
//
// Pre: The parameter must be a positive integer.
//
// Post: Returns true if number is even, and 
// returns false if number is not even
//
//******************************************************************************
bool numIsEven(int num) {
	num = num % 2 ;
	if (num == 0) {
		return true ;
	}
	else
		return false ;
	
} // end greaterThanTwoAndEven

//******************************************************************************
// Function: numIsGreaterThanTwo
//
// Description: Checks if a number is greater than the number Two (2)
//
// Pre: The parameter must be a positive integer.
//
// Post: Returns true if number is greater than 2, and 
// returns false if number is two or less.
//
//******************************************************************************
bool numIsGreaterThanTwo (int num) {
	if (num > 2)
		return true;
	else
		return false;
} // end numIsGreaterThanTwo

//******************************************************************************
// Function: numIsNotDivisibleBySqrtOrLess
//
// Description: Checks if a number is divisible by the square root of itself or
// integer values less than the root.
//
// Pre: The parameter must be a positive integer.
//
// Post: Returns false if divisible by a number equal to or less than the 
// square root of the number. Otherwise it will return true.
// 
//******************************************************************************
bool numIsNotDivisibleBySqrtOrLess (int num) {
	bool truth ;
	int root = sqrt(num) ;
	for ( int i = root; i > 1; i-- ) {
		int quotient = num ; //refreshes testVal back to original number
		quotient =  quotient % i ;
		if (quotient == 0)
			return false ;
	} // end for

	return true;

} // end numIsNotDivisibleBySqrtOrLess

//******************************************************************************
// Function: IsNumIsOne
//
// Description: Checks if number is one (1)
// 
// Pre: The parameter must be a positive integer.
//
// Post: Returns true if the number is one, and returns false if it is not one
// 
// 
//******************************************************************************
bool IsNumIsOne (int num) {
	if (num == 1)
		return true ;
	else
		return false ;
}
