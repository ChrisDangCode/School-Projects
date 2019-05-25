//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	RockImplement.cpp Implementation file					Chris Dang
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <string>
#include <cctype>
#include "Rock.h"
using namespace std;



void Rock::display(ostream &out) const{

	switch(myName) {
	case BASALT    : out << "BASALT" ;
		break ;
	case DOLOMITE  : out << "DOLOMITE" ;
		break ;
	case GRANITE   : out << "GRANITE" ;
		break ;
	case GYPSUM    : out << "GYPSUM" ;
		break ;
	case LIMESTONE : out << "LIMESTONE" ;
		break ;
	case MARBLE    : out << "MARBLE" ;
		break ;
	case OBSIDIAN  : out << "OBSIDIAN" ;
		break ;
	case QUARTZITE : out << "QUARTZITE" ;
		break ;
	case SANDSTONE : out << "SANDSTONE" ;
		break ;
	case SHALE     : out << "SHALE" ;
		break ;
	case ROCK_OVERFLOW : out << "ROCK_OVERFLOW" ;
		break ;
	default : out << "\n\nRock Value is not valid\n\n" ;
		}// end switch

}// end display()

Rock Rock::read(istream &in) {

	string str ;
	Rock rockVal ;

	in >> str ;
	for (unsigned i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]) ;

	if (str == "BASALT")
		return BASALT ;
	else if (str == "DOLOMITE")
		return DOLOMITE ;
	else if (str == "GRANITE")
		return GRANITE ;
	else if (str == "GYPSUM")
		return GYPSUM ;
	else if (str == "LIMESTONE")
		return LIMESTONE ;
	else if (str == "MARBLE")
		return MARBLE ;
	else if (str == "OBSIDIAN")
		return OBSIDIAN ;
	else if (str == "QUARTZITE")
		return QUARTZITE ;
	else if (str == "SANDSTONE")
		return SANDSTONE ;
	else if (str == "SHALE")
		return SHALE ;
	else 
		return ROCK_OVERFLOW ;

}// end read()

string Rock::kind() {

	switch(myName) {
	case BASALT    : return "Igneous" ;
	case DOLOMITE  : return "Sedimentary" ;
	case GRANITE   : return "Igneous" ;
	case GYPSUM    : return "Sedimentary" ;
	case LIMESTONE : return "Sedimentary" ;
	case MARBLE    : return "Metamorphic" ;
	case OBSIDIAN  : return "Igneous" ;
	case QUARTZITE : return "Metamorphic" ;
	case SANDSTONE : return "Sedimentary" ;	
	case SHALE     : return "Sedimentary" ;
	case ROCK_OVERFLOW : return "Not a Rock" ;
	default : return "\n\nRock Value is not valid\n\n" ;
	}// switch

}// end kind()

string Rock::texture() {

	switch(myName) {
	case BASALT    : return "Intermediate" ;
	case DOLOMITE  : return "Coarse" ;
	case GRANITE   : return "Coarse" ;
	case GYPSUM    : return "Coarse" ;
	case LIMESTONE : return "Coarse" ;
	case MARBLE    : return "Fine" ;
	case OBSIDIAN  : return "Fine" ;
	case QUARTZITE : return "Intermediate" ;
	case SANDSTONE : return "Coarse" ;	
	case SHALE     : return "Fine" ;
	case ROCK_OVERFLOW : return "Not a Rock" ;
	default : return "\n\nRock Value is not valid\n\n" ;
	}// switch

}// end texture()

RockName Rock::name() const {

	return myName ;

}// end kind()

Rock Rock::nextOne() {

	switch(myName) {
	case BASALT    : return DOLOMITE ;
	case DOLOMITE  : return GRANITE ;
	case GRANITE   : return GYPSUM ;
	case GYPSUM    : return LIMESTONE ;
	case LIMESTONE : return MARBLE ;
	case MARBLE    : return OBSIDIAN ;
	case OBSIDIAN  : return QUARTZITE ;
	case QUARTZITE : return SANDSTONE ;
	case SANDSTONE : return SHALE ;
	case SHALE     : return ROCK_OVERFLOW ;
	case ROCK_OVERFLOW : return ROCK_OVERFLOW ;
	default : return ROCK_OVERFLOW ;
	}// end switch
}// end nextOne()

Rock Rock::operator++() {

	switch(myName) {
	case BASALT    : return DOLOMITE ;
	case DOLOMITE  : return GRANITE ;
	case GRANITE   : return GYPSUM ;
	case GYPSUM    : return LIMESTONE ;
	case LIMESTONE : return MARBLE ;
	case MARBLE    : return OBSIDIAN ;
	case OBSIDIAN  : return QUARTZITE ;
	case QUARTZITE : return SANDSTONE ;
	case SANDSTONE : return SHALE ;
	case SHALE     : return ROCK_OVERFLOW ;
	case ROCK_OVERFLOW : return ROCK_OVERFLOW ;
	default : return ROCK_OVERFLOW ;
	}// end switch
}// end overloaded prefix increment operator

Rock Rock::operator++(int) {

	switch(myName) {
	case BASALT    : return DOLOMITE ;
	case DOLOMITE  : return GRANITE ;
	case GRANITE   : return GYPSUM ;
	case GYPSUM    : return LIMESTONE ;
	case LIMESTONE : return MARBLE ;
	case MARBLE    : return OBSIDIAN ;
	case OBSIDIAN  : return QUARTZITE ;
	case QUARTZITE : return SANDSTONE ;
	case SANDSTONE : return SHALE ;
	case SHALE     : return ROCK_OVERFLOW ;
	case ROCK_OVERFLOW : return ROCK_OVERFLOW ;
	default : return ROCK_OVERFLOW ;
	}// end switch
}// end overloaded postfix increment operator



//*************************************************************
// non-member functions
//*************************************************************

ostream &operator<<(ostream &out, const Rock &RockVal){

	RockVal.display(out);

	return out;
}// end overloaded insertion operator

istream &operator>>(istream &in, Rock &RockVal) {

	RockVal = RockVal.read(in) ;

	return in;

}// end overloaded extraction operator

bool &operator<(const Rock &aRock1, const Rock &aRock2) {

	bool b = (aRock1.name() < aRock2.name()) ;
	return b ;

}// end overloaded less-than relational operator

bool &operator==(const Rock &aRock1, const Rock &aRock2) {

	bool b = (aRock1.name() == aRock2.name()) ;
	return b ;

}// end overloaded equality relational operator

