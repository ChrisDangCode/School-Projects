/*--- geology.cpp ---------------------------------------------------
  A program to model rocks.
 
  Written by:   Larry R. Nyhoff
  Written for:  Lab Manual for ADTs, Data Structures, and Problem
                Solving with C++, 2E

                     Lab #2.2  and  Project #2.2	

  Modified by Chris Dang			Class 1107
  
---------------------------------------------------------------------*/

#include <iostream>
#include <string>

using namespace std;
#include "Rock.h" 



int main()
{
  /***** PART 1 ******/

  // Declare a variable to store a rock


  Rock sample;

  // Input and display various rocks

  for(;;)
  {
    cout << "Enter a rock (" << ROCK_OVERFLOW << " to stop): ";
	int temp ;
    cin >> temp;
	sample = Rock(temp);
    if (sample == ROCK_OVERFLOW) break;
    cout << "Rock is: " << sample << endl;
  }

  for(bool flag = false; flag != true; ){
	cout << "Enter a rock to find its type (" << ROCK_OVERFLOW << " to stop): ";
	int temp ;
    cin >> temp;
	sample = Rock(temp);
	if (sample != ROCK_OVERFLOW)
		cout << "Rock is: " << kind(sample) << endl;
	else 
		flag = true ;

    }// end for

  /***** PART 2 ******/

  // Display all the rock names

  cout << "\nList of rocks:\n";
  for (Rock rockVal = BASALT; rockVal < ROCK_OVERFLOW; rockVal = nextRock(rockVal))
    cout << rockVal << "  ";
  cout << endl;
}

