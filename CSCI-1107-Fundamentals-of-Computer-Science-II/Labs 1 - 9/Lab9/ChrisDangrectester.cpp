/*--- rectester.cpp -------------------------------------------------------
  Program to test a recursive Fibonacci function.
   
  Written by:   Larry R. Nyhoff
   
  Written for:  Lab Manual for ADTs, Data Structures, and Problem
                Solving with C++, 2E

                            Lab #8.1
                                                          
  Add your name here and other info requested by your instructor.
  
 --------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

//-- PUT THE GLOBAL VARIABLE DECLARATIONS HERE
const int BASE_CASE = 2 ;
const int BASE_VAL = 1 ;


// PUT PROTOTYPE OF recFibonacci HERE
int recFibonacci(int val) ;
int f(int n) ;
/*-----------------------------------------------------------
  recFibonacci is a recursive Fibonacci number calculator.
 
  Precondition:  The parameter n is a positive integer.
  Postcondition: The n-th Fibonacci number is returned.
 ------------------------------------------------------------*/

int main()
{
  int number;

  for (;;)
  {
    cout << "\nPlease enter a positive integer (or 0 to stop): ";
    cin >> number;

    if (number <= 0) break;

    cout << "The " << number << "-th Fibonacci number is "
         << recFibonacci(number) << endl;

	/*cout << "\n\nSTUFFFFFFFF\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" ;
	int x = f(12) ;
	cout << "x is: " << x ;*/
  }
}

// DEFINE recFibonacci() HERE
int recFibonacci(int val) {      // 1
	cout << val << "-try\n" ;    
	if (val <= BASE_CASE)		 // 2
		return BASE_VAL ;        // 3
	return recFibonacci(val - BASE_CASE) + recFibonacci(val - BASE_VAL) ;  // 4
}// end recFibonacci

int f(int n)
{
	if (n < 2)
		return 0 ;
	return 1 + f(n/2) ;
}