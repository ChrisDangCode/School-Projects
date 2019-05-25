//*Rational Number Class Implment***********************************************
//   Chris Dang							CSCI 1107
//******************************************************************************
//#include <iostream>
using namespace std ;
#include "RationalNumberHeader.h"


int RationalNumber::getTop() {

	return numerator ;
}// end getBot ;
int RationalNumber::getBot() {

	return denominator ;
}// end getBot ;

RationalNumber RationalNumber::invert() {

	RationalNumber ratNum(denominator, numerator) ;
	return ratNum ;
}

int RationalNumber::gcd() {

	//Greatest Common Divider function (GCD)

	int remainder, dividend, divisor ;

	if (numerator > denominator) {
		dividend = numerator ;
		divisor = denominator ;
	}//end if

	if (numerator < denominator) {
		dividend = denominator ;
		divisor = numerator ;
	}//end if

	while (divisor != 0) {

		remainder = dividend % divisor ;
		dividend = divisor ;
		divisor = remainder ;
	}// end while

	return dividend ;
}//end greatestCommonDiv

RationalNumber RationalNumber::reduce() {

	int div = gcd() ;
	
	numerator = numerator / div ;
	denominator = denominator / div ;

	RationalNumber ratNum(numerator, denominator) ;
	return ratNum ;
}// end reduce

int RationalNumber::lcd(RationalNumber &ratNum2) {

	//Lowest Common Denominator function (LCD)
	
	int store1, store2, lowComBot ;
	int temp1 = getBot() ;				//Get denominators of the two 
	int temp2 = ratNum2.getBot() ;		//rational numbers so the GCD can be
										//found. Once found, the product of
	RationalNumber tempRat(temp1, temp2) ;//the denominators is divided by 
	store1 = tempRat.gcd() ;			//the GCD to find the LCD
	store2 = temp1 * temp2 ;
	lowComBot = store2 / store1 ;
	
	return lowComBot ;
}// end lowestCommonBot

RationalNumber RationalNumber::operator+(RationalNumber &ratNum2) {

	int numer1 = numerator ;
	int numer2 = ratNum2.getTop() ;
	int denom1 = denominator ;
	int denom2 = ratNum2.getBot() ;

	int top1 = denom1 * numer2 ;
	int top2 = denom2 * numer1 ;
	numerator = top1 + top2 ;
	denominator = denom1 * denom2 ;

	RationalNumber ratNum(numerator, denominator) ;

return ratNum.reduce() ;
}//_________end overloaded + op__________ 

RationalNumber RationalNumber::operator-(RationalNumber &ratNum2) {

	int numer1 = numerator ;
	int numer2 = ratNum2.getTop() ;
	int denom1 = denominator ;
	int denom2 = ratNum2.getBot() ;

	int top1 = denom1 * numer2 ;

	int top2 = denom2 * numer1 ;

	numerator = top2 - top1 ;

	denominator = denom1 * denom2 ;

	RationalNumber ratNum(numerator, denominator) ;

return ratNum.reduce() ;
}//_________end overloaded - op__________ 

RationalNumber RationalNumber::operator*(RationalNumber &ratNum2) {

	numerator = numerator * ratNum2.getTop() ;
	denominator = denominator * ratNum2.getBot() ;

	RationalNumber ratNum(numerator, denominator) ;

	return ratNum.reduce() ;

}//_________end overloaded * op__________ 

RationalNumber RationalNumber::operator/(RationalNumber &ratNum2) {

	ratNum2 = ratNum2.invert() ;

	numerator = numerator * ratNum2.getTop() ;
	denominator = denominator * ratNum2.getBot() ;

	RationalNumber ratNum(numerator, denominator) ;

	return ratNum.reduce() ;

}//_________end overloaded / op__________ 

void RationalNumber::display(ostream &out) const{

	if (denominator != 1 )
		out << numerator << '/' << denominator ;
	else 
		out << numerator ;

}//end display

RationalNumber RationalNumber::read (istream &in) {

	
	int num1, num2 ;
	char ch ;
	//string temp = "";

	in >> num1 ; 
	if (in.peek() == '/') {
		in >> ch ;
		if(isdigit(in.peek()))
			in >> num2 ;
	}// end if

	if(num2 == 0) {
		cout << "Error: Denominator cannot be zero" << endl <<
			 "Terminating Program" ;
		exit(1107) ;
	}//end if

	numerator = num1 ;
	denominator = num2 ;

	RationalNumber ratNum(numerator, denominator) ;
	
	return ratNum ;

	
}//end read function

//----------non-member functions --------------------------------------

ostream &operator<<(ostream &out, const RationalNumber &Rational){

	Rational.display(out);

	return out;
}// end overloaded insertion operator

istream &operator>>(istream &in, RationalNumber &Rational) {

	Rational = Rational.read(in) ;

	return in ;
}// end overloaded extraction operator
