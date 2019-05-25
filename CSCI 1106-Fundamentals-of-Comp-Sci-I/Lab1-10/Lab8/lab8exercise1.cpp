//******************************************************************************
//
//  Programmer: Chris Dang			Class: CSCI 1106 Fall 2014
// 
//  Description: This program will read population data from a file and will
//  output the population (represented as * per 1000) alongside the year.
//
//
//******************************************************************************

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main () {

	int year = 1900, population;

	ifstream infile;					//Grabs people file from source code
	infile.open("people.txt");
	if(!infile){						//Error in case people file is not opened
		cerr << "Error opening file. --- Terminating program. " << endl << endl;
		exit(1106);
	}// end if


	cout << "Praireville Population Growth\n" ; // seperated for readbility
	cout << "(each * represents 1,000)\n" ;

	while(infile >> population) {		// as the file data is being inputted into population,
		cout << year << " ";			// the year will be outputted. 
		for(int star = 0; population > 0; star++) {
			population -= 1000;			// population is having every 1000 people represented
			cout << '*';				// as stars in the output.
		} // end for
		year += 20;
		cout << endl;
	} // end while;




	return 0;
}