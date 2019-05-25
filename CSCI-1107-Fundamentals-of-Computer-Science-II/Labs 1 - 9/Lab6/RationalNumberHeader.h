//*Rational Number Class Header*************************************************
//   Chris Dang							CSCI 1107
//******************************************************************************
#include <iostream>
#include <sstream>
#include <string>
#include <cctype> 
using namespace std ;

class RationalNumber
{
	public:
		
		//get denominator and numerator, respectively
		int getBot() ;
		int getTop() ;

		RationalNumber invert() ;
		int gcd() ;
		RationalNumber reduce() ;
		int lcd(RationalNumber &ratNum2) ;

		RationalNumber operator+(RationalNumber &ratNum2) ; 
		RationalNumber operator-(RationalNumber &ratNum2) ;   
		RationalNumber operator*(RationalNumber &ratNum2) ;	
		RationalNumber operator/(RationalNumber &ratNum2) ;

		//default constructor
		RationalNumber(){numerator = 1; denominator = 2;} ;
		//explicit value constructor
		RationalNumber(int num, int den){numerator = num, denominator= den;} ;

		void display(ostream &out) const ;
		RationalNumber read(istream &in) ;
		
	private:
	
		int numerator, denominator ;
		
}; // end Rational Number class

//non-member functions

ostream &operator<<(ostream &out, const RationalNumber &Rational) ;

istream &operator>>(istream &in, RationalNumber &Rational) ;

