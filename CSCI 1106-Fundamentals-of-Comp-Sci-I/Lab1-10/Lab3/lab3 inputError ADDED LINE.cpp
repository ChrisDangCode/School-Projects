//*******************************************************************
// Programmer: Tim Wrenn
//
// Description: Potential problems caused by mixing the
//              extraction operator and the get method together 
//              in one program. NOTE: You are not allowed to change
//				any of the original statements.
//
//*******************************************************************

#include <iostream>
using namespace std;

int main(){

     int intVar;

     char ch;

     cout << "Enter an integer: " ; 
     cin >> intVar;


	 //my SINGLE added statement
	 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 cin.ignore(80, '\n'); 
	 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

     cout << "\nEnter a character: " ;
     cin.get(ch);

     cout << "The value in intVar is " << intVar << endl
          << "The value in ch is " << ch << endl
          << "The ascii value of ch is " << static_cast<int>(ch) 
          << endl;

     return 0;
}// end main


