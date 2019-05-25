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


// int transcodeCtoI(char letter); //transcodes char into int from chart

int main () {

	char letter; // used to hold letter from 7 letter word to be transcoded
	string phoneNumber = "";
	int number;
	ifstream in; //needed to continue getting data from file


	// Grabbing text file with phone numbers
	ifstream infile;
	infile.open("oldPhone.txt");
	if(!infile){
		cerr << "Error opening file. --- Terminating Program. " << endl << endl;
		exit (1106);
	} // end if
	
	
	//while(!in.eof()){
	
	
		while(infile.getline >> ){
			
			letter = toupper(letter);
		
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
			
			phoneNumber = number;

			}// end while

	//    }//end while

		phoneNumber = static_cast<char>(number) + phoneNumber;

			cout << endl;


		return 0;
}