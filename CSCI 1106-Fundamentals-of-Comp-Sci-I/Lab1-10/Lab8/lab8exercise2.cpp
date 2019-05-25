//******************************************************************************
//
//  Programmer: Chris Dang			Class: CSCI 1106 Fall 2014
// 
//  Description: This program will simulate a constant number of games and will
//  calculate the batting average and slugging percentage.
//
//
//******************************************************************************

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int GAMES = 1000; // number of games to be simulated

int main () {

	srand(time(NULL)); //seed the random # generator

	int batting; //batting chance variable, stores generatored random number 
	int out = 0, walk = 0, hit = 0, singleHit = 0, doubleHit = 0, tripleHit = 0, homeRunHit = 0;
	double battingAvg;
	double sluggingPercent;

	for (int i = 0; i < GAMES; i++) // Runs simulatution for the number of GAMES
	{
		batting = 1 + rand() % 100; // At bat, chances are measured from 1 to 100

		if (batting <= 35)								//chance 1-35, out
			out++;
		else if (batting >= 36 && batting <= 51)		//chance 36-51, walk
			walk++;
		else if (batting >= 52 && batting <= 71){		//chance 52-71, single hit
			hit++;
			singleHit++;
		}
		else if (batting >= 72 && batting <= 86){		//chance 72-86, double hit
			hit++;
			doubleHit++;
		}
		else if (batting >= 87 && batting <= 95){		//chance 87-95, triple hit
			hit++;
			tripleHit++;
		}
		else if (batting >= 96){						//chance 95-100, home run
			hit++;
			homeRunHit++;
		}

	}//end for

	battingAvg = hit / (static_cast<double>(GAMES) - walk); 
	//promoted GAMES to double to prevent integer division

	// Calculates slugging percentage, e.i., average number of bases gained from a hit
	sluggingPercent = (singleHit + doubleHit * 2 + tripleHit * 3 + homeRunHit * 4) /
		(static_cast<double>(GAMES) - walk); 
	//promoted GAMES to double to prevent integer division

	cout << setprecision(2) << fixed << showpoint;
	
	cout << "      # of outs:" << setw(4) << out << endl;
	cout << "     # of walks:" << setw(4) << walk << endl;
	cout << "   # of singles:" << setw(4) << singleHit << endl;
	cout << "   # of doubles:" << setw(4)<< doubleHit << endl;
	cout << "   # of triples:" << setw(4) << tripleHit << endl;
	cout << "  # of homeruns:" << setw(4) << homeRunHit << endl;
	cout << "# of total hits:" << setw(4) << hit << endl << endl;
	
	cout << " Batting average is: " << battingAvg << "%\n";
	cout << "Slugging percent is: " << sluggingPercent << "%\n\n";

	return 0;
}//end main