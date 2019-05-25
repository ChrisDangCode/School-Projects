//******************************************************************************
//  Programmer: Chris Dang			Class: CSCI 1107 Spring 2015
// 
//  Description: This program takes in a post fix expression and evaulates
//  the expression while showing the process of pushing to and popping from 
//  the stack.
//                                                                             |
//******************************************************************************

#include <iostream>
#include <string>
using namespace std;

#include "LStack.h"

const string TOKEN = "  Token = " ;
const string PUSH  = "   Push " ;
const string POP   = "   Pop  " ;

int main() {

	
	Stack st ;					// initialize empty stack for operators
	string expression ;

	cout << "Please enter a postfix expression: " ;
	getline(cin, expression) ;		// get expression into string

	// loop through expression from start to end
	for (int i = 0; expression[i] != expression[expression.size()]; i++) {
		int token = expression[i] ;	// holds a character for processing

		if (token != 32) {			// skips spaces

		// 48 is the ascii value of 0, and 57 is the ascii value of 9
		if (token >= 48 && token <= 57) {	// if token is operand
			token -= '0' ;					// subtract ascii val 48 to get 
			cout << TOKEN << token ;		// true integer value
			st.push(token) ;                // push operands to stack
			cout << PUSH << token  ;
		}// end if

		else if (token == '+') {
			cout << TOKEN << static_cast<char>(token) ; // Display operator
			cout << POP << st.top()  ;				    // Display operand 1
			int sum = st.top()  ;						// get operand 1
			st.pop() ;								    // pop op 1
			cout << POP << st.top()  ;					// Display operand 2
			sum += st.top() ;							// add operand 2
			st.pop() ;								    // pop op 2
			st.push(sum) ;								// push sum 
			cout << PUSH << sum ;						// Display sum
		} // end else if addition operator

		else if (token == '-') {
			cout << TOKEN << static_cast<char>(token) ; // Display operator
			cout << POP << st.top();				    // Display operand 2
			int op2 = st.top() ;						// get operand 2
			st.pop() ;							   	    // pop op 2
			cout << POP << st.top() ;				    // Display operand 1
			int op1 = st.top();						    // get operand 1
			st.pop() ;								    // pop op 1
			op1 -= op2 ;							    // subtract op2 from op1
			st.push(op1) ;							    // push the difference
			cout << PUSH << op1 ;						// Display difference
		} // end else if subtraction operator

		else if (token == '*') {
			cout << TOKEN << static_cast<char>(token) ; // Display operator
			cout << POP << st.top();					// Display operand 1
			int total = st.top();						// get operand 1
			st.pop() ;								    // pop op 1
			cout << POP << static_cast<int>(st.top()) ;	// Display operand 2
			total *= st.top() ;							// mult operand 2
			st.pop() ;									// pop op 2
			st.push(total) ;							// push total
			cout << PUSH << total ;						// Display total
		} // end else if multiplication operator

		else if (token == '/') {
			cout << TOKEN << static_cast<char>(token) ; // Display operator
			cout << POP << st.top() ;				    // Display operand 2
			int op2 = st.top() ;						// get operand 2
			st.pop() ;						   		    // pop op 2
			cout << POP << st.top() ;					// Display operand 1
			int op1 = st.top() ;						// get operand 1
			st.pop() ;								    // pop op 1
			op1 /= op2 ;								// divide op 1 by op 2
			st.push(op1) ;								// push the quotient
			cout << PUSH << op1 ;						// Display quotient
		} // end else if division operator

		cout << endl ;

		} // end if
	} // end for

	// Display final pop
	cout << TOKEN << ' ' << POP << static_cast<int>(st.top()) << endl ;

	return 0 ;
} // end main ;