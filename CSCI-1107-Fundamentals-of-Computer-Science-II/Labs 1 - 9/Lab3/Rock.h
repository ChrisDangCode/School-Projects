//***Rock.h*******************************************************************************
// A header file for an enumerated data type Rock that models rocks of various types
// (Basalt, dolomite, granite, gypsum, limestone, marble, obsidian, quartzie, 
// sandstone, and shale)
//
// Operations are:
//	next() : A successor 
//
//	Written by: Chris Dang							Anoka-Ramsey Community College
//  Written for: CSCI 1107							Januray 27, 2015
//****************************************************************************************

#include <iostream>
#include <string>
using namespace std;


enum Rock {BASALT, DOLOMITE, GRANITE, GYPSUM, LIMESTONE, MARBLE, 
	OBSIDIAN, QUARTZITE, SANDSTONE, SHALE, ROCK_OVERFLOW} ;

Rock nextRock(Rock rockVal) ;

string kind(Rock rockVal) ;