#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


//testing data for problem 2
/*
int main () {

	int var1;
	char ch;
	string str;

	cout << "Type in an integer: " ;
	cin >> var1;
	getline (cin,str);

	cout << "Integer is: " << var1 <<'\n' ;
	cout << " String is: " << str <<'\n';

	return 0;


}
*/
//end main

//Problem 3


int main() {

	const int CANDY_BAR_TICKET_PRICE = 10;
	const int GUMBALL_TICKETS_PRICE = 3;
	int tickets, gumballTickets, gumballs, candybars;

	cout << "Enter number of tickets: ";
	cin >> tickets;

	gumballTickets = tickets % CANDY_BAR_TICKET_PRICE;
	gumballs = gumballTickets / 3;
	candybars = (tickets - gumballTickets) / 10;
	
	cout << "Candy bars you can get: " << candybars << '\n';
	cout << "  Gumballs you can get: "<< gumballs << '\n';

	return 0;

}