//
// An array manipulation example
// Programmer: Chris Dang
// Subject: CSCI 1106 
//

#include <iostream>
#include <iomanip>
using namespace std;

const int MAXELEMENTS = 8;

typedef int integerArray[MAXELEMENTS];		// create an alias for a one dimensional 
  											// array containing integers
int main(){

	integerArray prime = {2, 3, 5, 7};

	for(int i = 0; i < MAXELEMENTS ; i++)
		cout << setw(3) << "prime[" << i <<"] = " << prime[i] << endl;
	
 return 0;
}// end main
