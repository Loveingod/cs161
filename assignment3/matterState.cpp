/*********************************************************************
** Author:  Marc Clinedinst
** Date:  24 January 2015
** Description:  This program asks the user to provide a temperature
in Fahrenheit, and then the program determines the state of matter
of the following substances when they are at that temperature:
ethyl alcohol, mercury, oxygen, and water.  This program makes use
of constants to store the values of the freezing points and melting
points of each of these substance.  This program also makes use
of if/else if/else constructs to determine the state of matter of
each of the substances.  This program will clarify the use of these
techniques where they arise in the source code.
*********************************************************************/
#include <iostream>
#include <string>

using namespace std;

int main() {
	const int ETHYL_ALCOHOL_FREEZING_POINT = -173;        // In lines 12 through 19, we declare integer constants
	const int ETHYL_ALCOHOL_BOILING_POINT = 172;          // to represent the freezing and boiling points of
	const int MERCURY_ALCOHOL_FREEZING_POINT = -38;       // ethyl alcohol, mercury, oxygen, and water.  These
	const int MERCURY_BOILING_POINT = 676;                // values are governed by physics, so they're not
	const int OXYGEN_FREEZING_POINT = -362;               // likely to change.  Giving them names also helps
	const int OXYGEN_BOILING_POINT = -306;                // with readability.
	const int WATER_FREEZING_POINT = 32;
	const int WATER_BOILLING_POINT = 212;
	int temperature;                                      // The temperature variable will be used to collect
	                                                      // the temperature from the user.
	string ethylAlcoholState,                             // The variables in lines 22 through 25 will be used
		   mercuryState,                                  // to store the state of each substance based on
		   oxygenState,                                   // the temperature provided by the user.
		   waterState;

	cout << "This program will ask the user for an integer representing a" << endl;
	cout << "temperature in Fahrenheit. This program will then determine" << endl;
	cout << "the states of matter of ethyl alcohol, mercury, oxygen," << endl;
	cout << "and water when these substances are at that temperature." << endl;

	cout << endl;
	cout << "Please enter a Fahrenheit temperature as an integer:\n> ";
	cin >> temperature;

	if (temperature <= ETHYL_ALCOHOL_FREEZING_POINT) {             // Use the current temperature to determine the
		ethylAlcoholState = "solid";                               // state of matter of ethyl alcohol and assign
	} else if (temperature >= ETHYL_ALCOHOL_BOILING_POINT) {       // it to the ethylAlcholState variable.
		ethylAlcoholState = "gas";
	} else {
		ethylAlcoholState = "liquid";
	}

	if (temperature <= MERCURY_ALCOHOL_FREEZING_POINT) {           // Use the current temperature to determine the
		mercuryState = "solid";                                    // state of matter of mercury and assign it to
	} else if (temperature >= MERCURY_BOILING_POINT) {             // the mercuryState variable.
		mercuryState = "gas";
	} else {
		mercuryState = "liquid";
	}

	if (temperature <= OXYGEN_FREEZING_POINT) {                    // Use the current temperature to determine the
		oxygenState = "solid";                                     // state of matter of oxygen and assign it to
	} else if (temperature >= OXYGEN_BOILING_POINT) {              // the oxygenState variable.
		oxygenState = "gas";
	} else {
		oxygenState = "liquid";
	}

	if (temperature <= WATER_FREEZING_POINT) {                     // Use the current temperature to determine the
		waterState = "solid";                                      // state of matter of water and assign it to
	} else if (temperature >= WATER_BOILLING_POINT) {              // the waterState variable.
		waterState = "gas";
	} else {
		waterState = "liquid";
	}

	cout << endl;                                                  // These lines display a properly-aligned table
	cout << "Ethyl Alcohol State: " << ethylAlcoholState << endl;  // of each substance and its state based on
	cout << "Mercury State      : " << mercuryState << endl;       // the temperature.
	cout << "Oxygen State       : " << oxygenState << endl;
	cout << "Water State        : " << waterState << endl; 

	return 0;	
}