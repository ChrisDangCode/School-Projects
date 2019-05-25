//*******************************************************************************
// Programmer: Chris Dang
//
// Description: This program will ask the user for the two sides of a right 
//				triangle and determine the length of the hypotenuse.
//*******************************************************************************

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main(){

	double side1,				// one of the legs of the triangle
		   side2,				// one of the legs of the triangle
		   hypotenuse;			// the hypotenuse of the triangle

	cout << setprecision(2) << fixed << showpoint;		// format the output

	cout << "Enter the length of one side of the triangle " ;

	//Write the input statement that brings in side1

	cin >> side1;

	//Prompt the user for the second side

	cout << "Enter the length of the second side. " << endl;
	
	//Write the input statement that brings in side2

	cin >> side2;

	
	//Write the assignment statement to calculate the hypotenuse

	hypotenuse = sqrt (pow(side1, 2.0) + pow(side2 , 2.0));

	//Write an output statement to display the legs of the triangle and the hypotenuse of the triangle.

	cout << "         The Length of leg 1 is: " << setw(7) << side1 << endl;
	cout << "         The Length of leg 2 is: " << setw(7) << side2 << endl;
	cout << "The Length of the hypotenuse is: " << setw(7) << hypotenuse << endl;

	//All output should be in column format (appropriately labeled) with all decimal points lining up. 

	return 0;
}// end main