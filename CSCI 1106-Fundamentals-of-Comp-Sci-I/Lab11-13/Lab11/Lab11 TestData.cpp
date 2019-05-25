//******************************************************************************
//
//  Programmer: Chris Dang			Class: CSCI 1106 Fall 2014
// 
//  Description: Tests info from Lab 11
//
//
//******************************************************************************

#include <iostream>
using namespace std;

double fun2(int, double ) ;

int main () {

	double x = 3.1, y = 3.2;

	fun2(x , fun2(x,y));

} // end main

double fun2(int x, double y ){

	y = 5.9999;
cout << "int x is: " << x << endl;
cout << "double y is: " << y << endl;

return y;

} // end fun1