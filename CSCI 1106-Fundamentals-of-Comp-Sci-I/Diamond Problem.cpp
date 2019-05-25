//******************************************************************************
//
//  Programmer: Chris Dang			Class: CSCI 1106 Fall 2014
// 
//  Description: Asks user for an odd integer, then creates a diamond based on 
//  integer that the user entered.
//
//******************************************************************************

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int userSize;

int main () {


	
/*
cout << "Please enter a positive, odd number integer: ";
cin >> userSize;


for (int space = ((userSize -1) / 2); space > -1; space--){
	cout << setw(space);
	for (int star = 0, count = 1; star < count; star++)
		cout << '*';
	cout << endl;
}

return 0;
}
*/		




/*
cout << "1234567" << endl;

for(int row = 1; row < (userSize + 1); row++){
	for(int space = ((userSize +1) / 2); space > 0; space--){
		cout << setw(space);
	
	//for(int plusSign = 0; plusSign < row; plusSign++)
		//cout  << '+' ;
	cout << endl;
	}
} //end for
*/




/*
cout << "Please enter a positive, odd number integer: " << endl;
cin >> userSize;

for(int row = 1; row <= userSize; row++){    //for loop to add rows until rows == user input
	for(int star = 0; star < ((userSize + 1) / 2 ); star++)
		cout << '*';
	cout << setw(userSize) << endl;
}

*/
	
	//work in progrss
	
cout << "Please enter a positive, odd number integer: ";
cin >> userSize;

int column = ((userSize + 1) / 2);
int star = 1;

cout << left;

cout << "1234567" << endl;

while (star <= userSize){
	for (; column <= userSize; column++){
		cout << setw(column);
		for (int count = 1; count <= star; count++)
			cout << "*/";
		cout << endl;
		star += 2;
	}
	

}


return 0;
}


	/*
	cout << "Please enter a positive, odd number integer: ";
cin >> userSize;

int column = ((userSize + 1) / 2);
int row = 1;


cout << "1234567" << endl;

while (row <= userSize){
	for (; column <= userSize; column++){
		cout << setw(column);
		for (int star = 1; star <= userSize; star++){
			for (int spaces = ((userSize - 1) / 2); spaces > 0; spaces--) {
				cout << '*';
			}
		
			cout << endl;
		}
	}
	row++;

}
*/







