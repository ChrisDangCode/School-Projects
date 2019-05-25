//******************************************************************************
//  Programmer: Chris Dang			Class: CSCI 1106 Fall 2014
// 
//  Description: This is a reduced ticket master program designed to allow the 
//  purchase of tickets.
//                                                                             |
//******************************************************************************

#include <iostream>
#include <iomanip>	// for ticket prices
#include <fstream>  // for reading in prices & seat chart and write to chart
#include <string> 
using namespace std;

const int ROW_SIZE = 30 ; // number of seats per row
const int COL_SIZE = 15 ; // number of rows
const char EMPTY_SEAT_ICON = '#' ;
const char SOLD_SEAT_ICON = '*' ;

const string TITLE = "Reduced Ticket Master Application" ;
const string MENU_HEADER = "Select an option:" ;
const string MENU1 = "1: View Seating Chart" ;
const string MENU2 = "2: Purchase Tickets" ;
const string MENU3 = "3: View Total Ticket Sales" ;
const string MENU4 = "4: Exit Program" ;
const string MENU_SELECTION = "Enter selection : " ;
const string SEAT_NUMBERS = "123456789012345678901234567890" ;
const string TICKET_HEADER = "How many tickets would you like to purchase?" ;
const string ROW_HEADER = "Which row would you like your seat? (1-15)" ;
const string COL_HEADER = "Which seat nuumber would you like?  (1-30)" ;
const string ROW_SELECTION = "Enter row: " ;
const string COL_SELECTION = "Enter seat number: " ;

void getTicketPrices(double seatPrices[]) ;
void createSeatChart(bool seats[ROW_SIZE][COL_SIZE]) ;
void getSeatChart(bool seats[ROW_SIZE][COL_SIZE]) ;
void displayMenu() ;
void displaySeatChart(bool seats[ROW_SIZE][COL_SIZE]) ;
int getMenuChoice() ;
int getNumOfTickets() ;
int getRow() ;
int getSeatNum() ;
void storeSeatChoice(int getSeatNum, int getRow, bool seats[ROW_SIZE][COL_SIZE], double seatPrices[]) ;
void purchaseTicket(int seatNum, int row, bool seats[ROW_SIZE][COL_SIZE], double seatPrices[]) ;

int main () {
	

	bool seats[ROW_SIZE][COL_SIZE];

	double seatPrices[COL_SIZE];

	getTicketPrices(seatPrices) ;

	getSeatChart(seats) ;


//	Echo seat chart
	for (int i = 0; i < COL_SIZE; i++) {
		for (int j = 0; j < ROW_SIZE; j++){
			cout << seats[i][j] << "   " ;
		}// end for
	}// end for

	displaySeatChart(seats) ;


	cout << TITLE << endl << endl ;

	int userChoice = getMenuChoice() ;
	while (userChoice != 4) {

		switch(userChoice){
		case 1: displaySeatChart(seats) ;
				break ;
		case 2: purchaseTicket(getSeatNum(), getRow() ,seats, seatPrices) ;

		} // end switch

		userChoice = getMenuChoice() ;
	}// end while

	

	/* Testing infile
	for (int i = 0; i < COL_SIZE; i++) {
		cout << "   " << seatPrices[i] ;
		} // end for ;
	*/

	
	
	
	

return 0;		
}// end main








//******************************************************************************
// Function: getTicketPrices
//
// Description: Reads in ticket prices from text file and enters them into array
//
// Pre: seatPrice.txt must be in source folder to be read.
// 		The array that contains the prices must be declared beforehand.
//		
//
// Post: Returns false if read correctly.
//		 Returns true if problem occurs.
//******************************************************************************
void getTicketPrices(double seatPrices[COL_SIZE]) {

	ifstream infile ;
	infile.open("seatPrice.txt") ;
	if(!infile){
		cerr << "Error opening file. --- Terminating Program. " << endl <<
		endl ;
		exit (1106);
	} // end if
	
	for (int i = 0; i < COL_SIZE; i++) {
	
		double price = 0 ;

		infile >> price ;

		seatPrices[i] = price ;
	
	} // end for
	
}// end getTicketPrices
	
//******************************************************************************
// Function: createSeatChart
//
// Description: Function will create an empty seat chart. 
//
// Pre: Two global int constants (ROW_SIZE and COL_SIZE) for the 
// size of the chart must be initialized. Global const char EMPTY_SEAT_ICON
// must be initialized as well.
// fstream library is needs to be included.
//
// Post: Returns nothing
//
//******************************************************************************
void createSeatChart() {

	ofstream outfile;
	outfile.open("seatChart.txt");
	if(!outfile){
		cerr << "Error writing file. --- Terminating Program. " << endl << 
		endl;
		exit (1106);
	} // end if

	for (int i = 0; i < COL_SIZE; i++){
		for (int j = 0; j < ROW_SIZE; j++) {
			outfile << EMPTY_SEAT_ICON ;
		}// end for
		outfile << endl;
	}// end for
}// end createSeatChart

//******************************************************************************
// Function: createSeatChart
//
// Description: Function will check for seatChart.txt. If the chart isn't found
// it will call createSeatChart and pull from the new chart.
//
// Pre: Two global int constants (ROW_SIZE and COL_SIZE) for the 
// size of the chart must be initialized. Global const char EMPTY_SEAT_ICON
// must be initialized as well.
// fstream library is needs to be included.
// A 2 Dimension bool array must be declared in main.
//
// Post: Returns nothing
//
//******************************************************************************
void getSeatChart(bool seats[ROW_SIZE][COL_SIZE]) {

	char seat;

	ifstream infile;
	infile.open("seatChart.txt");
	if(!infile){
		createSeatChart() ;
	} // end if

	for (int i = 0; i < COL_SIZE; i++) {
		for (int j = 0; j < ROW_SIZE; j++) {
			infile >> seat ;
			if (seat == EMPTY_SEAT_ICON) 
				seats[i][j] = false;
			else
				seats[i][j] = true;
		} //end for
	} // end for
} // end getSeatChart

//******************************************************************************
// Function: displayMenu
//
// Description: Function will display a menu with a header and four menu options
//
// Pre: Global string constants for the MENU_HEADER, MENU1, MENU2, MENU3, MENU4
//      must be intialized beforehand.
//
// Post: Returns nothing
//
//******************************************************************************
void displayMenu() {

	cout << MENU_HEADER << endl << MENU1 << endl << MENU2 << endl << MENU3
		 << endl << MENU4 << endl << endl << MENU_SELECTION ;

}// end displayMenu

//******************************************************************************
// Function: getMenuChoice
//
// Description: Function will get the menu choice from the user
//
// Pre: displayMenu function must be able to be called.
//
// Post: Returns choice as an integer
//
//******************************************************************************
int getMenuChoice() {

	int choice ;

	displayMenu() ;
	cin >> choice ;

	while (choice != 1 && choice != 2 && choice != 3 && choice != 4){
		cout << "Error:\n" ;
		cout << "Please enter menu choice 1, 2, 3, or 4\n" ;
		displayMenu() ;
		cin >> choice ;
	} // end while

	

	return choice ;
}// end getMenuChoice

//******************************************************************************
// Function: displaySeatChart
//
// Description: Function will display the seat chart from 
//				2 Dimension array seats
//
// Pre: 2-Dimension bool array seats must be initialized beforehand.
// 		global char constants EMPTY_SEAT_ICON and SOLD_SEAT_ICON must be 
//		initialized.
//
// Post: Returns nothing
//
//******************************************************************************
void displaySeatChart(bool seats[ROW_SIZE][COL_SIZE]) {

	cout << "Seats\n" << SEAT_NUMBERS << endl;

	for (int i = 0; i < COL_SIZE; i++) {
		cout << "Row " << setw(2) << (i + 1) << setw(2); // displays Row number 
		for (int j = 0; j < ROW_SIZE; j++) {
			if (seats[i][j] == false)
				cout << EMPTY_SEAT_ICON ;
			else if (seats[i][j] == true)
				cout << SOLD_SEAT_ICON ;
		} // end for
		cout << endl ;     // output formatting
	}// end for

	cout << endl << endl ; // output formatting

} // end displaySeatChart


//******************************************************************************
// Function: getNumOfTickets
//
// Description: Function will get the number of tickets they want to purchase
//				from the user
//
// Pre: const string TICKET_HEADER must be initialized.
//
// Post: Returns int tickets
//
//******************************************************************************
int getNumOfTickets() {

	int tickets ;
	cout << TICKET_HEADER << endl 
		 << "Tickets: " ;
	cin >> tickets ;

	while (tickets < 1) { //makes sure user enters more than 1 ticket
		cout << "\nError: Please request 1 or more tickets\n\n" <<
			 TICKET_HEADER << endl <<
			 "Tickets: " ;
	}// end while
	return tickets ;

} // end getNumOfTickets

//******************************************************************************
// Function: getRow
//
// Description: Function will get the row number for the seat the user wants
//
// Pre: const string ROW_HEADER must be initialized.
//		const string ROW_SELECTION must be initialized.
//
// Post: Returns int row
//
//******************************************************************************
int getRow() {

	int row ;
	cout << ROW_HEADER << endl 
		 << ROW_SELECTION ;
	cin >> row ;

	while (row < 1 || row > COL_SIZE) {
		cout << "\nError: Row does not exist\n\n" <<
		ROW_HEADER << endl <<
		ROW_SELECTION ;
		cin >> row ;
	}// end while

	return row ;
}// end getRow

//******************************************************************************
// Function: getSeatNum
//
// Description: Function will get the seat number for the seat the user wants
//
// Pre: const string COL_HEADER must be initialized.
//		const string COL_SELECTION must be initialized.
//
// Post: Returns int row
//
//******************************************************************************
int getSeatNum() {

	int seatNum ;
	cout << COL_HEADER << endl 
		 << COL_SELECTION ;
	cin >> seatNum ;

	while (seatNum < 1 || seatNum > ROW_SIZE) {
		cout << "\nError: Seat number does not exist\n\n" <<
		COL_HEADER << endl <<
		COL_SELECTION ;
		cin >> seatNum ;
	}// end while

	return seatNum ;
}// end getRow

//******************************************************************************
// Function: storeSeatChoice
//
// Description: Function will stire the seat number for the seat the user wants
//
// Pre: must be able to use getSeatNum function
//		2-Dimension bool array seats[][] must be initialzed
//		getSeatNum must have been used
//		getRow must have been used
//
// Post: Returns nothing
//
//******************************************************************************
void storeSeatChoice(int seatNum, int row, bool seats[ROW_SIZE][COL_SIZE]) {

	seats[seatNum][row] = true ;
}

//******************************************************************************
// Function: checkIfSeatSold
//
// Description: Function will check if the seat has been sold
//
// Pre: 2-Dimension bool array seats[][] must be initialized and passed in
//		getSeatNum must be able to be used
//		getRow must be able to be used
//		const int ROW_SIZE must be initialized
//		const int COL_SIZE must be initialized
//
// Post: Returns true if seat has been sold. Returns false if open.
//
//******************************************************************************
bool checkIfSeatSold(int getSeatNum, int getRow, bool seats[ROW_SIZE][COL_SIZE]){

	if (seats[getSeatNum][getRow] == true) {
		cout << "\nSeat has been sold. It is not available for purchase\n\n" ;
		return true ;
	}// end if
	return false ;
}// end checkIfSeatSold


void purchaseTicket(int seatNum, int row, bool seats[ROW_SIZE][COL_SIZE], double seatPrices[]) {

	int tickets = getNumOfTickets() ;
	double total = 0;

	int *ticketPrices = new int [tickets] ;
	if(ticketPrices == NULL) {
		cout << "\n\n Error allocating memory --- Terminating\n\n" ;
		exit(1106) ;
	}// end if

	for (int i = 0; i < tickets; i++) {

		//getRow() ;
		//getSeatNum() ;
		while (checkIfSeatSold(seatNum, row, seats) == true)
			getSeatNum() ;

		ticketPrices[i] = seatPrices[getRow()] ;
		seats[seatNum][row] = true ;
	} // end for

	for (int i = 0; i < tickets; i++)
		total = total + *(ticketPrices + i) ;

	cout << "The total for the tickets is: " << total << endl << endl ;

}// end purchaseTicket