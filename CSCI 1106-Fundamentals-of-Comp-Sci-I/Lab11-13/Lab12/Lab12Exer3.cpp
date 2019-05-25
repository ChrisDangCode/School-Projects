//******************************************************************************
//
//  Programmer: Chris Dang			Class: CSCI 1106 Fall 2014
// 
//  Description: This program displays an employees ID number and will then ask
//	for the number of hours worked, followed by the pay rate for the employee.
//	The program will then calculate the gross wage, and then display all of the 
//	employee's ID's along with their wage.
//
//******************************************************************************

#include <iostream>
#include <iomanip> 	// for formatting 
#include <string>
using namespace std;

const int NUM_EMPLOYEES = 7 ;
const double MIN_WAGE = 15.00 ; //minumum wage is $15
//Employee ID numbers:
const long emp1 = 5658845, emp2 = 4520125, emp3 = 7895122, emp4 = 8777541,
		   emp5 = 8451277, emp6 = 1302850, emp7 = 7580489 ;

const string ENTER_HOURS = 
"Please enter the number of hours worked for employee #" ;

const string ENTER_PAY = 
"Please enter the pay rate for employee #" ;
		   
int main () {

long empId[NUM_EMPLOYEES] = {emp1, emp2, emp3, emp4, emp5, emp6, emp7} ;
double hours[NUM_EMPLOYEES] ;
double payRate[NUM_EMPLOYEES] ;
double wages[NUM_EMPLOYEES] ;

// Loops the get input cycles
for (int i = 0; i < NUM_EMPLOYEES; i++) {

	cout << ENTER_HOURS << empId[i] << ": ";
	cin >> hours[i] ;
		// input validating while. Traps user until non-negative number is entered
		while (hours[i] < 0) { 
			cout << "Hours cannot be less than 0.\n" << ENTER_HOURS << empId[i] 
			<< ": " ;
			cin >> hours[i] ;
		} // end while
	cout << ENTER_PAY << empId[i] << ": ";
	cin >> payRate[i] ;
		// input validating while. Traps user until wage is >= $15
		while (payRate[i] < MIN_WAGE) {
			cout << "Pay rate cannot be less than 15.\n" << ENTER_PAY << empId[i]
			<< ": " ;
			cin >> payRate[i] ;
		} // end while

		//calculates gross wage
		wages[i] = hours[i] * payRate[i] ;
} // end for

//displays employee number and gross wage
cout << setprecision(2) << fixed << showpoint << "Gross pay for each employee is:\n";
for (int i = 0; i < NUM_EMPLOYEES; i++) {
	cout << "Employee #" << empId[i] << ": $" << wages[i] << endl ;
} // end for

return 0;
}