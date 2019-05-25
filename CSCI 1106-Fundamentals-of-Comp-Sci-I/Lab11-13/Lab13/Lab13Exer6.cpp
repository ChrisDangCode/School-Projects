//******************************************************************************
//                                                                             |
//  Programmer: Chris Dang			Class: CSCI 1106 Fall 2014
// 
//  Description: Program will ask user input for number of test scores and then
//  dynamically allocate memory as their are test scores and then display the 
//  scores, sort the scores, and then take the average of the scores which will
//  then be displayed.
//                                                                             |
//******************************************************************************

#include <iostream>
#include <iomanip> // need this for displaying averages
#include <ctime>   // need this for random number generator
using namespace std;

const int LOW_TEST_SCORE = 1 ;	 // Lowest score on test is 1
const int HIGH_TEST_SCORE = 20 ; // Highest score on test is 20


void displayArray(int a[], int numOfTests) ;	// Displays the scores
void loadArray(int *ptr, int numOfTests) ;		// Loads the array with scores
void bubbleSort(int *ptr, int numOfTests) ;		// Sorts the scores
double calculateAvg (int *ptr, int numOfTests) ;// Calculates average of scores

int main () {

	//~~~~~~~~~~~~~Seed for Random Number Generator ~~~~~~~~~~~~~~
	srand(time(NULL));
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	int numOfTests ;
	double avgScore ;
	int *ptr ;

	//Get number of test scores///////////////////////////////
	cout << "Please enter number of number of tests scores: " ;
	cin >> numOfTests ;
	while (numOfTests < 1) { //Validates input so that tests are > 1
		cout << "Number of tests must be 1 or more.\n" ;
		cout << "Please enter number of number of tests scores: " ;
		cin >> numOfTests ;
	}
	//////////////////////////////////////////////////////////
	

	//****Ask OS for memory locations**********************
	ptr = new int [numOfTests] ; 
	if (ptr == NULL) {
		cout<< "\n\n Error allocating memory --- terminating\n\n" ;
		exit (1106) ;
	} // end if
	//*****************************************************

	loadArray(ptr, numOfTests) ;

	cout << "\nThe test scores are:\n" ;
	displayArray(ptr, numOfTests) ;

	bubbleSort (ptr, numOfTests) ;

	cout << "\nTest scores after sorting are:\n" ;
	displayArray(ptr, numOfTests) ;

	avgScore = calculateAvg( ptr, numOfTests) ;


	cout << fixed << showpoint << setprecision(2) ;
	cout << "\nThe average test score is: " << avgScore << endl << endl ;


	delete [] ptr ; // kill process to stop memory leak

return 0 ;
}

//******************************************************************************
// Function: displayArray
//
// Description: displays a 1D pointer array
//
// Pre: The parameters are the pointer array that has dynamically allocated  
//		memory and the integer number of tests
//******************************************************************************
void displayArray(int *ptr, int numOfTests) {

	for(int i = 0 ; i < numOfTests; i++) {

		cout << setw(4) << *(ptr + i) ;

	} // end for
	cout << endl ;

} // end displayArray

//******************************************************************************
// Function: loadArray
//
// Description: loads a 1D pointer array with random numbers
//
// Pre: The parameters are the pointer array that has dynamically allocated  
//		memory and the integer number of tests
//******************************************************************************

void loadArray(int *ptr, int numOfTests) {

	for (int i = 0; i < numOfTests; i++) {
		*(ptr + i) = LOW_TEST_SCORE + rand() % HIGH_TEST_SCORE ;
	}// end for
} // end loadArray

//******************************************************************************
// Function: bubbleSort
//
// Description: sorts a 1D pointer array
//
// Pre: The parameters are the pointer array that has dynamically allocated  
//		memory and the integer number of tests
//******************************************************************************
void bubbleSort(int *ptr, int numOfTests) {
	
	bool swap ;
	int temp ;

	do {
		swap = false ;
		for (int i = 0; i < (numOfTests - 1); i++) {

			// compares memory location i to location i + 1
			if ( *(ptr + i) > *(ptr + i + 1)) {

				temp = *(ptr + i) ;
				*(ptr + i)  = *(ptr + i + 1) ;
				*(ptr + i + 1) = temp ;
				swap = true ;
			} // end if
		} // end for
	} while (swap) ;
}// end bubbleSort

//******************************************************************************
// Function: calculateAvg
//
// Description: calculates the average of a pointer array
//
// Pre: The parameters are the pointer array that has dynamically allocated  
//		memory and the integer number of tests
//
// Post: Returns the averge of the numbers from the pointer array
//******************************************************************************

double calculateAvg (int *ptr, int numOfTests) {
	
	int total = 0 ;
	double average = 0 ;

	for (int i = 0; i < numOfTests; i++) {
		total = total + *(ptr + i) ;
	}// end for

	average = total / static_cast<double>(numOfTests) ;

	return average ;
} // end calculateAvg