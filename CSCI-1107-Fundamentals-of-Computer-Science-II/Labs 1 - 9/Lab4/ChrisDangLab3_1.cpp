//******************************************************************************
//		Programmer: Chris Dang					Class: CSCI 1107
//								Lab3.1
//******************************************************************************

#include <iostream>
#include <iomanip>

using namespace std ;

typedef int IntegerArray[16] ;
typedef char CharArray[10] ;

int main()
{
	/*
	IntegerArray prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47} ;
	for(int i = 0; i < 15; i++)
		cout << prime[i] << endl ; 
		*/
	/*
	char animal[10] = "zebra" ;
	for(int i = 0; i < 10; i++)
	cout << animal[i] << i+1 << "  ";
		*/

	IntegerArray first = {0, 0, 0, 0,
						  0, 0, 0, 0,
						  0, 0, 0, 0, 
						  0, 0, 0, 0} ;
	IntegerArray arr =   {1, 1, 1, 1,
						  1, 1, 1, 1, 
						  1, 1, 1, 1, 
						  1, 1, 1, 1} ;
	IntegerArray last =  {2, 2, 2, 2,
						  2, 2, 2, 2,
					      2, 2, 2, 2, 
						  2, 2, 2, 2} ;

	/*
	cout << first << endl 
		 << arr << endl 
		 << last << endl << endl 
		 << sizeof(first) << " Bytes are in first[]\n\n" 
		 << "arr[2] is at: " << &arr[2] << endl
		 << "arr[3] is at: " << &arr[3] << endl << endl ;

	for (int i = 0; i < 16; i++)
		cout << "&arr[" << i << "] is " << &arr[i] << endl ;
	cout << endl << endl ;

	cout << "*********Subset notation: ********\n" ;
	for (int i = 0; i < 16; i++)
		cout << arr[i]  ;
	cout << endl << endl ;

	cout << "********Pointer notation: ********\n" ;
	for (int i = 0; i < 16; i++)
		cout << *arr + i << endl ;
	cout << endl << endl ;
	*/

	/*
	// add to display for question 17 of lab
	arr[-10] = -999 ;
	arr[20] = 999 ;

	cout << "*********contents of first: ********\n" ;
	for (int i = 0; i < 16; i++)
		cout << first[i] << endl ;
	cout << endl << endl ;

	cout << "***********contents of arr: ********\n" ;
	for (int i = 0; i < 16; i++)
		cout << arr[i]  << endl;
	cout << endl << endl ;

	cout << "***********contents of last: *******\n" ;
	for (int i = 0; i < 16; i++)
		cout << last[i] << endl ;
	cout << endl << endl ;

	cout << "\narr[-10]...arr[20]:\n";
        for (int i = -10; i <= 20; i++)
        cout << arr[i] << "  " ;
		*/

		int mat[3][4] = { {11, 22, 33, 44},
						  {55, 66, 77, 88},
						  {-1, -2, -3, -4} } ;
				

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++)
				cout << setw(5) << mat[i][j] ;
			cout << endl ;
		}// end for

		cout << mat << endl ;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++)
				cout  << &mat[i][j] << "  ";
			cout << endl ;
		}// end for

		cout << "\n\nFor question 21\n" ;
		for (int i = 0; i < 3; i++)
			cout << *(mat + i) << "  " ;
		cout << endl ;

		for (int i = 0; i < 3; i++)
			cout << **(mat + i) << "  " ;
		cout << endl ;

		for (int i = 0; i < 3; i++)
			cout << *(*mat + i) << "  " ;
		cout << endl ;

		for (int i = 0; i < 3; i++)
			cout << *(*(mat + 1) + i) << "  " ;
		cout << endl ;
}
