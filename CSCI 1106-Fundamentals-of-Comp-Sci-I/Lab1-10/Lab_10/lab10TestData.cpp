//******************************************************************************
//
//  Programmer: Chris Dang			Class: CSCI 1106 Fall 2014
// 
//  Description: Test data for lab 10
//
//
//
//
//******************************************************************************

#include <iostream>
using namespace std;
//int x;        	     // a global variable 
int printVariable(int x);  // prototype

int main(void){

int x = 300;

cout<< "main before printVariable: The value in the variable x is " << x <<endl;

x = printVariable(x);

cout<< "main after  printVariable: The value in the variable x is " << x <<endl;
return 0;
}

//
// This function produces a side effect
//
int printVariable(int x){

cout<< "print_var before assignment: The value in the variable x is " << x <<endl;

   x = 2 * x + 7;

cout<< "print_var after  assignment: The value in the variable x is " << x <<endl;

return x;
}
