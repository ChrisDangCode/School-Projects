//******************************************************************************
//
//  Programmer: Chris Dang			Class: CSCI 1106 Fall 2014
// 
//  Description: This program will get the a character from the user 
//  (the character will represent the first letter of color of a compressed gas
//  tank), the program will output the contents of the tank based on the  
//  character.
//
//  The program will continue to run until the user exits by entering E or e
//
//******************************************************************************

#include <iostream>
#include <string>
using namespace std;



int main () {


	char color;
	string content;

	// Priming the loop; initilizes color
	cout << "To determine contents held inside of tank,\nplease enter the first letter of the color of the tank. \nEnter the letter E to exit: ";
	cin >> color;


	while (color != 'e' && color != 'E'){

		cout << endl; // seperates the contents descrption from the question; for readbility

		switch (color){
			 case 'O': //Orange
			 case 'o':
						cout << "Contents: Ammonia";
						break;

			 case 'Y': // Yellow
			 case 'y':
						cout << "Contents: Hydrogen";
						break;

			 case 'B': // Brown
			 case 'b':
						cout << "Contents: Carbon Monoxide";
						break;

			 case 'G': // Green
			 case 'g':
						cout << "Contents: Oxygen";
						break;

			 default:
						cout << "Contents unknown";

		}//end switch (color)

		cout << endl; // seperates content description from next prompt; for readibility

		if (color != 'e' && color != 'E'){
			cout << endl << "To determine contents held inside of tank,\nplease enter the first letter of the color of the tank. \nEnter the letter E to exit: ";
			cin >> color;
		}// end if
	


	} //end while

	return 0;

}