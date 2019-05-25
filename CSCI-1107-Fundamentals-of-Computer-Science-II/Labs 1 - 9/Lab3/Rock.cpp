//***Rock.cpp*****************************************************************************
// An implementation file for an enumerated data type Rock that models rocks of 
// various types (Basalt, dolomite, granite, gypsum, limestone, 
// marble, obsidian, quartzie, sandstone, and shale)
//
// Operations are:
//	next() : A successor function
//
//	Written by: Chris Dang							Anoka-Ramsey Community College
//  Written for: CSCI 1107							Januray 27, 2015
//****************************************************************************************

#include <iostream>
#include <string>
using namespace std ;

#include "Rock.h"

// nextRock will recieve a Rock value and then return the next rock type following
Rock nextRock(Rock rockVal) {

	switch(rockVal) {
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
	default : cout << "\n\nRock Value is not valid\n\n" ;
				  return ROCK_OVERFLOW ;
	}// end switch
}// end next()


// Returns the kind of rock that each rock type is categorized as given:
//Basalt, granite, and obsidian are igneous.
//Marble, and quartzite are metamorphic.
//Dolomite, limestone, gypsum, sandstone, and shale are sedimentary.


string kind(Rock rockVal) {

	switch(rockVal) {
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
	case ROCK_OVERFLOW : return "" ;
	default : return "\n\nRock Value is not valid\n\n" ;
	}// switch

}// end kind()
