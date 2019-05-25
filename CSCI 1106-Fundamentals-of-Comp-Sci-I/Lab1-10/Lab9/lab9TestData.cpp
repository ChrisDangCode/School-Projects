	#include <iostream>
using namespace std;
	int multiply(int, int);
	int main(){
	int multiplier,multiplicand,product;

	cout<< "Enter the first number ===> " ;
	cin>> multiplier;
	cout<< "Enter the second number ===> " ;
	cin>> multiplicand;

	      product = multiply(multiplier, multiplicand);
	cout<< "Product of " << multiplier << " & " << multiplicand <<" is " << product;

	return 0;

	}// end main

	//
	// Multiply two numbers and return their product
	// Pre: num1 and num2 contain the values to be multiplied.
	// Post: The product of num1 and num2.

	int multiply(int num1, int num2){
	       return (num1 * num2);
	}
