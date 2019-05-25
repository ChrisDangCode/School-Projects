//******************************************************************************
//
//  Programmer: Chris Dang			Class: CSCI 1106 Fall 2014
// 
//  Description: Program takes 7 letter words from a text file and will turn 
//  them into numbers that are associated under a 10 digit phone numpad. 
//  They will then be outputted into a file.
//
//******************************************************************************


/*
Chart: Comes from standard 10 digit numbpad on phones
Letter:   Digit:
ABC		  2
DEF       3
GHI		  4
JKL		  5
MNO		  6
PQRS 	  7
TUV		  8
WXYZ	  9
*/


#include <iostream>
#include <fstream> // Needed for in-file / out-file
#include <cctype>  // Needed for toupper
#include <string>
using namespace std;

int main () {

	char letter;
	int number;

	string oldNumber;

	// Grabbing text file with phone numbers
	ifstream infile;
	infile.open("oldPhone.txt");
	if(!infile){
		cerr << "Error opening file. --- Terminating Program. " << endl <<
		endl;
		exit (1106);
	} // end if

	// Outputting the new number file
	ofstream outfile;
	outfile.open("newPhone.txt");
	if(!outfile){
		cerr << "Error writing file. --- Terminating Program. " << endl << 
		endl;
		exit (1106);
	} // end if
	
		
	while(infile >> oldNumber){ //Grabs info from file


		for (int i = 0; i < 7; i++) { //counter loop for outputting '-' and endl
			//loop runs on values 0 to 6. There are 7 values for the 7 digits
			//in the phone number.
		
			letter = toupper(oldNumber.at(i)); //simplifies the input for the
											   // switch
			
			switch (letter){				
				case 'A':
				case 'B':
				case 'C': number = 2;
						break;
				case 'D':
				case 'E':
				case 'F': number = 3;
						break;
				case 'G':
				case 'H':
				case 'I': number = 4;
						break;
				case 'J':
				case 'K':
				case 'L': number = 5;
						break;
				case 'M':
				case 'N':
				case 'O': number = 6;
						break;
				case 'P':
				case 'Q':
				case 'R': 
				case 'S': number = 7;
						break;
				case 'T':
				case 'U':
				case 'V': number = 8;
						break;
				default: 
						number = 9;
						break;
			}// end switch

			outfile << number; // outputs number by number to the file
			if (i == 2)		   // if the third value is outfiled, add '-'
			outfile << '-';
			if (i == 6)        // if the last (7th) value is outfiled, add endl
			outfile << endl;
			
			
		}// end for
	
	} //  end while;

    cout << "Output file has been processed." << endl << endl ;

	// closes the in file and out file.
	infile.close();
	outfile.close();
			
		return 0;
}