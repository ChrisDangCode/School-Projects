//*******************************************************************
// Programmer: Chris Dang		Class: CSCI 1106 Fall 2014
//
// Description: This program will calculate the amount charged
//		after inputting the time the vehicle entered the
//		parking lot, and exit time based on what kind of	
//		vehicle the user was driving.
//	
//*******************************************************************


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


double CAR_RATE_1 = 0.00;		//Car is $1.50 per hour before 3 hours (hours < 3)
double CAR_RATE_2 = 1.50;		//Car is $1.50 per hour after 3 hours (hours > 3)
double TRUCK_RATE_1 = 1.00;		//Truck is $1.00 per hour before 2 hours (hours < 2)
double TRUCK_RATE_2 = 2.30;		//Truck is $2.30 per hour after 2 hours (hours > 2)
double BUS_RATE_1 = 2.00;		//Bus is $2.00 per hour before 1 hour (hours < 1)
double BUS_RATE_2 = 3.70;		//Bus is $3.70 per hour after 1 hour (hours > 1)

int CAR_FIRST_RATE_HOURS = 3;	//These are the times for how long the first rate
int TRUCK_FIRST_RATE_HOURS = 2;	//will apply for each kind of vehicle
int BUS_FIRST_RATE_HOURS = 1;



int main () {

	
	char inputVehicle;
	int timeInHour, timeInMinute, timeOutHour, timeOutMinute;
	int outputHour, outputMinute, roundedTotal, recordHourIn;
	int recordMinuteIn, recordHourOut, recordMinuteOut, inTimeOfDay, outTimeOfDay;
	double charge;
	string outputVehicle;


	cout << "What vehicle did you park?: ";
	cin >> inputVehicle;
	
	cout << "What hour did it enter the lot?: ";
	cin >> timeInHour;
	recordHourIn = timeInHour;
	inTimeOfDay = timeInHour;

	cout << "What minute did it enter the lot?: ";
	cin >> timeInMinute; 
	recordMinuteIn = timeInMinute;

	cout << "What hour did it exit the lot?: ";
	cin >> timeOutHour; 
	recordHourOut = timeOutHour;
	outTimeOfDay = timeOutHour;

	cout << "What minute did it exit the lot?: ";
	cin >> timeOutMinute;
	recordMinuteOut	= timeOutMinute;

// calculates parking time///////////////////
	if (timeOutMinute < timeInMinute)
	{
	timeOutHour -= 1;		//subtract 1 hour to
	timeOutMinute += 60; 	//add 60 minutes so that minute subtraction results in positive number
	}

if (timeOutHour < timeInHour)
	timeOutHour += 24;		//add 24 hours so that hour subtraction results in positive number

outputMinute = timeOutMinute - timeInMinute;

outputHour = timeOutHour - timeInHour;

// end calculations ////////////////////////


// rounding ************************************************
if (outputMinute > 0)						// rounds parking time up to full hour
	roundedTotal = outputHour + 1;		// if the parking time is not a whole hour 
else
	roundedTotal = outputHour;
// end round *************************************************

// Military to Convential Time Conversion
if (recordHourIn > 12)
	recordHourIn -= 12;

if (recordHourOut > 12)
	recordHourOut -= 12;
// end conversation 

//%%%%%%%%%%%%%%%%%% calculates the Charge for parking time %%%%%%%%%%%%%%%%%%%%%%%%%%%
if (inputVehicle == 'C')
{
	outputVehicle = "Car";
	
	if (roundedTotal > CAR_FIRST_RATE_HOURS)
	{
		charge = (roundedTotal - CAR_FIRST_RATE_HOURS) * CAR_RATE_2;
	}
	else
		charge = CAR_RATE_1;
}

if (inputVehicle == 'T')
{
	outputVehicle = "Truck";
	
	if (roundedTotal > TRUCK_FIRST_RATE_HOURS)
		charge = (TRUCK_RATE_1 * TRUCK_FIRST_RATE_HOURS) + ((roundedTotal - TRUCK_FIRST_RATE_HOURS) * TRUCK_RATE_2);
	else
		charge = TRUCK_RATE_1 * roundedTotal;
}

if (inputVehicle == 'B')
{
	outputVehicle = "Bus";
	
	if (roundedTotal > BUS_FIRST_RATE_HOURS)
		charge = (BUS_RATE_1 * BUS_FIRST_RATE_HOURS) + ((roundedTotal - BUS_FIRST_RATE_HOURS) * BUS_RATE_2);
	else
		charge = BUS_RATE_1 * roundedTotal;
}
//%%%%%%%%%%%%%%%%%%%%%%%%% end charge calculations %%%%%%%%%%%%%%%%%%%%%%%%%%%%%


cout << fixed << setprecision(2) << showpoint << endl << endl;

cout << "   Your vehicle parked is: " << outputVehicle << endl;
cout << "                  Time-in: " << recordHourIn << ":" ;

	if(recordMinuteIn < 10)				// adds 0 before single digit minutes (from 4:4 to 4:04)
		cout << '0' << recordMinuteIn ;
	else
		cout << recordMinuteIn;

	//used to determine and display the time of day (A.M. or P.M.)
	if (inTimeOfDay > 0 && inTimeOfDay < 12)
	cout << " A.M." ;
else
	cout << " P.M." ;

	cout << endl;


	cout << "                 Time-out: " << recordHourOut << ":" ;
		if(recordMinuteOut < 10)
			cout << '0' << recordMinuteOut ;
		else
			cout << recordMinuteOut ;

if (outTimeOfDay > 0 && outTimeOfDay < 12)
	cout << " A.M." ;
else
	cout << " P.M." ;

cout << endl;
	
cout<< endl;
cout << "                           ------"  << endl;

cout << "             Parking Time: " << outputHour << ":" ;

		if(outputMinute < 10)
			cout << '0' << outputMinute;
		else
			cout << outputMinute ;

cout << endl;
cout << "            Rounded Total: " << roundedTotal  << endl << endl;
cout << "             Total Charge: $" << setw(5) << charge << endl << endl;


return 0;
}
//end main

