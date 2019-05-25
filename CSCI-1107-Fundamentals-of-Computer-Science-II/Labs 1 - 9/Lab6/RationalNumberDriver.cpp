//#include <iostream>
using namespace std ;
#include "RationalNumberHeader.h" 

int main() {

	char ch ;
	RationalNumber test1, test2 ;

	/*
	cout << "Before initialization: " << test << endl 
		 << "Please enter a value for test:" ;
	cin >> test1 ;
	cout << "After initialization: " << test << endl ;
	*/

	
	// testing addition
	cout << "Testing addition op:" ;
	cin >> test1 >> ch >> test2 ;

	if (ch == '+')
		cout << test1 + test2 << endl ;
	else if (ch == '-')
		cout << test1 - test2 << endl ;
	else if (ch == '*')
		cout << test1 * test2 << endl ;
	else if (ch == '/')
		cout << test1 / test2 << endl ;
	else if (ch == 'l' || ch == 'L')
		cout << "LCD is: " << test1.lcd(test2) << endl ;

	//else if (ch == 'r' || ch == 'R') 
	//	cout << test1.reduce() ;
	




	/* testing invert op
	cout << "Testing inverse op:" ;
	cin >> test1 >> ch ;
	cout << "before invert: " << test1 << endl ; 
	if (ch == 'i' || ch == 'I')
		test1 = test1.invert() ;
	cout << "after invert: " << test1 << endl ;
	*/

	/*		Testing GCD op
	cout << "Testing GCD op:" ;
	cin >> test1 >> ch ;
	if (ch == 'g' || ch == 'G')
		cout << "Greatest Common Divisor is: " << test1.greatestCommonDiv() << endl ;
	*/


	return 0 ;

}// end main