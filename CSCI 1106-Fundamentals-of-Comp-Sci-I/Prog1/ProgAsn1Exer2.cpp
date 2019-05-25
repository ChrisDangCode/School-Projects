//******************************************************************************
//
//  Programmer: Chris Dang			Class: CSCI 1106 Fall 2014
// 
//  Description: Program reads in Gettysburg Address file. It will then process
//  the file and display the number of alpabetical characters, number of 
//  uppercase characters, number of punctuation marks, and number of white
//  spaces.
//
//******************************************************************************

#include <iostream>
#include <cctype>  // Needed for character processing
#include <fstream> // Needed for in-file / out-file
#include <string>
using namespace std;

int main () {

	char character;
	int alpCount = 0, uppCount = 0, pncCount = 0, spcCount = 0;
	// alphabetical,  uppercase,    punctuation,  white space


// Opening text file with Gettysburg Address
	ifstream infile;
	infile.open("gettysburgAddress.txt");
	if(!infile){
		cerr << "Error opening file. --- Terminating Program. " << endl << endl;
		exit (1106);
	} // end if
	

        while (infile.get(character)) { //grabs character from file
	    
	        if (isalpha(character)){   //bracketing for efficiency; isupper
		        alpCount++ ;           //only runs if isalpha runs because
	            if (isupper(character))//if !alpha, then character cannot
		            uppCount++ ;       // be an upper character.
			}
	        if (ispunct(character))
		        pncCount++ ;
	        if (isspace(character))
		        spcCount++ ;
		} // end while


    cout << "   The number of alphabet characters is: " << alpCount << endl;
    cout << "  The number of uppercase characters is: " << uppCount << endl;
    cout << " The number of punctionan characters is: " << pncCount << endl;
    cout << "The number of white space characters is: " << spcCount << endl;

    infile.close();

return 0;
}
