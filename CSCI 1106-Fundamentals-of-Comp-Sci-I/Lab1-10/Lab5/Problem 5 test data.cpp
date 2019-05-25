#include <iostream>
using namespace std;


const int PASS_EXAM = 60;
const int PASS_PROG = 10;

int main() {

int programs;
int exams;

cout << "Enter Progs: ";
cin >> programs;

cout << "Enter Exams: ";
cin >> exams;

if (programs >= PASS_PROG && exams >= PASS_EXAM) 

	//if (exams >= PASS_EXAM)
	cout << "Passed" << endl ;

else
	cout << "Failed" << endl ;

}
//end main