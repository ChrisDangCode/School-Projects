//Written By Chris Dang
//Class: Computer Science 1106
//Lab 2 Program
//Program to convert Fahrenheit temperature to centigrade

#include <iostream>
#include <iomanip>
using namespace std;

int main(){

	double		tempCentigrade, //temperature in centigrade
				tempFahrenheit; //temperature in Fahrenheit

	//Request input from user


	cout << "\nPlease enter the temperature in Fahrenheit that "
		<< "you wish to convert: ";
	cin >> tempFahrenheit;

	//Perform conversion
	tempCentigrade = (tempFahrenheit - 32) * 5/9;

	//Display Results
	cout << "\n\n" << tempFahrenheit << " degrees Fahrenheit is equal to ";
	cout << fixed << showpoint << setprecision(1);
	cout << tempCentigrade << " degrees centigrade.\n\n";

	return 0;
}