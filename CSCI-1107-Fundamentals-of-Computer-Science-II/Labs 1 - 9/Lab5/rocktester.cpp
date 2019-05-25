/*--- rocktester.cpp ----------------------------------------------------
  A program for testing type Rock.

  Written by:   Larry R. Nyhoff
  Written for:  Lab Manual for ADTs, Data Structures, and Problem
                Solving with C++, 2E

                      Lab #4.1 & Project #4.1

  Add your name here and other info requested by your instructor.
  
 ----------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <iomanip>

#include "Rock.h"

using namespace std;


//----- Testing redeclaration prevention


int main()
{

	
//-------- BEGIN PART 0 ----------
  cout << "\n=============================================\n"
          "    PART 0:  Testing placement of enumeration"
          "\n=============================================\n";
  cout << GRANITE << endl;

//--------- END PART 0  ----------

  

  cout << "\n=======================================\n"
          "    PART 2:  Testing the constructor(s)"
          "\n=======================================\n";

  Rock sample ,	//default constructor
       rockVal(GRANITE);	// explicit value constructor


  cout << "\n===========================================\n"
          "    PART 3:  Testing function member display()"
          "\n===========================================\n";
  cout << "Value of\n"
       << "  sample is....";
  sample.display(cout);
  cout << endl;
  cout << "  rockVal is...";
  rockVal.display(cout);
  cout << endl;

  cout << "\n========================================\n"
          "    PART 4:  Testing the output operator"
          "\n========================================\n";
  cout << "Value of\n"
       << "  sample is...." << sample << endl
       << "  rockVal is..." << rockVal << endl;






  cout << "\n=========================================\n"
           "     PART 5:  Testing the input operator"
           "\n=========================================\n";

  cout << "Enter two rock names: ";
  cin >> sample >> rockVal;
  cout << "First rock is...." << sample << endl
       << "Second rock is..." << rockVal << endl;





  cout << "\n=============================================\n"
          "     PART 6:  Testing the rock-kind operator"
          "\n=============================================\n";

  char response;
  do
  {
    cout << "Enter a rock name: ";
    cin >> sample;
    cout << "Kind of " << sample << " is " << sample.kind() << endl;
    cout << "More rocks (Y or N)? ";
    cin >> response;
  }
  while (response == 'Y' || response == 'y');





  cout << "\n================================================\n"
          "     PART 7:  Testing the rock-texture operator"
          "\n================================================\n";
  do
  {
    cout << "Enter a rock name: ";
    cin >> sample;
    cout << "Texture of " << sample << " is " << sample.texture() << endl;
    cout << "More rocks (Y or N)? ";
    cin >> response;
  }
  while (response == 'Y' || response == 'y');






	// ********Project 4.1 begins here *******************************

  //decplaration in middle of program is for the sake of the lab
  //declation is normally added to the top with rest of declarations
	Rock myName ;

	cout << "Enter a rock for myName: " ;
	cin >> myName ;
	cout << "myName contains: " << myName << endl ;




  cout << "\n=====================================================\n"
          "     PART 9:  Testing == and < with two Rock objects"
          "\n=====================================================\n";

  Rock rock1(GRANITE),
       rock2(MARBLE),
       rock3(MARBLE);

  cout << "rock1 = " << rock1 << "  rock2 = " << rock2
       << "  rock3 = " << rock3 << endl;
  cout << boolalpha;                                                            
  cout << "rock1 < rock2? " << (rock1 < rock2) << endl;                         
  cout << "rock1 == rock2? " << (rock1 == rock2) << endl;                       
  cout << "rock2 < rock3? " << (rock2 < rock3) << endl;                        
  cout << "rock2 == rock3? " << (rock2 == rock3) << endl;                    



  cout << "\n============================================================\n"
          "     PART 10:  Testing == and < with a Rock and a RockName"
          "\n============================================================\n";

  cout << "rock1 = " << rock1 << endl;
  cout << "rock1 < MARBLE? " << (rock1 < MARBLE ? "Yes" : "No")  << endl;
  cout << "rock1 == GRANITE? " << (rock1 == GRANITE ? "Yes" : "No")  << endl;



  //~~~~~~~~~ Begin bar graph generator~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  ifstream infile ;
  infile.open("Rockfile.txt") ;
  if(!infile){
	  cerr << "Error opening file. --- Terminating. " << endl << endl;
	  exit(1107) ;
  } // end if

  //There are 10 varieties of rock
  int count[ROCK_OVERFLOW] = {0} ;
  

  Rock r ;

  while (infile >> r) {
	  for (; r < ROCK_OVERFLOW; r.nextOne()) {

		switch(r.name()) {
			case BASALT    : count[BASALT] += 1 ;
							 r = ROCK_OVERFLOW ;
							 break ;
			case DOLOMITE  : count[DOLOMITE] += 1 ;
							 r = ROCK_OVERFLOW ;
							 break ;
			case GRANITE   : count[GRANITE] += 1 ;
							 r = ROCK_OVERFLOW ;
							 break ;
			case GYPSUM    : count[GYPSUM] += 1 ;
							 r = ROCK_OVERFLOW ;
							 break ;
			case LIMESTONE : count[LIMESTONE] += 1 ;
							 r = ROCK_OVERFLOW ;
							 break ;
			case MARBLE    : count[MARBLE] += 1 ;
							 r = ROCK_OVERFLOW ;
							 break ;
			case OBSIDIAN  : count[OBSIDIAN] += 1 ;
							 r = ROCK_OVERFLOW ;
							 break ;
			case QUARTZITE : count[QUARTZITE] += 1 ;
							 r = ROCK_OVERFLOW ;
							 break ;
			case SANDSTONE : count[SANDSTONE] += 1 ;
							 r = ROCK_OVERFLOW ;
							 break ;
			case SHALE     : count[SHALE] += 1 ;
							 r = ROCK_OVERFLOW ;
							 break ;
			default : r = ROCK_OVERFLOW ;
		}// end switch

	  }// end for
  }//end while

  
	for (Rock rocks = BASALT ; rocks < ROCK_OVERFLOW ; rocks = rocks.nextOne()) {

		cout << setw(10) << rocks << ": " ;
		for (int i = 0 ; i < count[rocks.name()]; i++)
			cout << 'X' ;
		cout << "  (" << count[rocks.name()] << ")\n" ;
	}// end for
	
} // end main
