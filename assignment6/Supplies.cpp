/*********************************************************************
** Author:  Marc Clinedinst
** Date:  15 February 2015
** Description:  In this program, the user is prompted to enter the
number of thingamajigs, watchamacallits, and framistats.  The program
then creates a Supplies object representing the current inventory of
these parts.  The user is then prompted to enter a choice to print
a parts order report (the number of each part required to return the
part values to the default level), to produce a thing1, to produce a
thing2, or to quit the program.  
*********************************************************************/
#include <iostream>
#include "Supplies.hpp"

using namespace std;

/*********************************************************************
				Supplies Class Method Implementations

** Description:  This is the default constructor for the Car class,
which sets numThingamajigs to 100, numWatchamacallits to 70, and 
numFramistats to 50.  This constructor calls the setNumThingamajigs, 
setNumWatchamacallits, and setNumFramistats functions to set the 
values for the created object.
** Parameters:  This constructor takes  no parameters.
*********************************************************************/
Supplies::Supplies() {
	setNumThingamajigs(100);
	setNumWatchamacallits(70);
	setNumFramistats(50);
}

/*********************************************************************
** Description:  This constructor creates a Supplies object using
values representing the number of thingamajigs, watchamacallits, and
framistats provided by the user.  This constructor calls the
setNumThingamajigs, setNumWatchamacallits, and setNumFramistats
functions to set the values for the created object.
** Parameters:  This constructor takes three integer values
representing the number of thingamajigs, watchamacallits, and 
framistats.
*********************************************************************/
Supplies::Supplies(int t, int w, int f) {
	setNumThingamajigs(t);
	setNumWatchamacallits(w);
	setNumFramistats(f);
}

/*********************************************************************
** Description:  This function sets the value for the numThingamajigs
private member variable.
** Parameters:  This function accepts an integer value representing 
the number of thingamajigs.
*********************************************************************/
void Supplies::setNumThingamajigs(int t) {
	numThingamajigs = t;
}

/*********************************************************************
** Description:  This function sets the value for the 
numWatchamacallits private member variable.
** Parameters:  This function accepts an integer value representing 
the number of watchamacallits.
*********************************************************************/
void Supplies::setNumWatchamacallits(int w) {
	numWatchamacallits = w;
}

/*********************************************************************
** Description:  This function sets the value for the numFramistats
private member variable.
** Parameters:  This function accepts an integer value representing 
the number of framistats.
*********************************************************************/
void Supplies::setNumFramistats(int f) {
	numFramistats = f;
}

/*********************************************************************
** Description:  This function prints out how many of each part needs
to be ordered to bring what is in stock up to the default amounts. The
default amounts are listed below:
			thingamajigs: 100
			watchamacallits:  70
			framistats:  50
** Parameters:  This function takes no parameters.
*********************************************************************/
void Supplies::printPartsOrder() {
	cout << "Thingamajigs required to return to default levels:    ";
	if ((100 - numThingamajigs) > 0) {
		cout << (100 - numThingamajigs) << endl;
	} else {
		cout << 0 << endl;
	}

	cout << "Watchamacallits required to return to default levels: ";
	if ((70 - numWatchamacallits) > 0) {
		cout << (70 - numWatchamacallits) << endl;
	} else {
		cout << 0 << endl;
	}

	cout << "Framistats required to return to default levels:      ";
	if ((50 - numFramistats) > 0) {
		cout << (50 - numFramistats) << endl;
	} else {
		cout << 0 << endl;
	}
}

/*********************************************************************
** Description:  This function uses the available parts to produce
a certain number of thing1s as long as an adequate number of parts 
is available. To make a thing1, 1 thingamajig, 2 watchamacallits, 
and 1 framistats are required.  If these are available, then a thing1 
is produced and the appropriate number of parts are deducted from the
number of parts.
** Parameters:  This function takes an integer representing the number
of thing1s to be created.
*********************************************************************/
void Supplies::produceThing1(int quantity) {
	if ((numThingamajigs - (1 * quantity) > 0) && (numWatchamacallits - (2 * quantity)) && (numFramistats - (1 * quantity))) {
		setNumThingamajigs(numThingamajigs - (1 * quantity));
		setNumWatchamacallits(numWatchamacallits - (2 * quantity));
		setNumFramistats(numFramistats - (1 * quantity));		
	} else {
		cout << "Error:  insufficient parts to produce thing1." << endl;
	}
}

/*********************************************************************
** Description:  This function uses the available parts to produce
a certain number of thing2s as long as an adequate number of parts 
is available. To make a thing2, 2 thingamajigs and 1 framistats are 
required.  If these are available, then a thing1 is produce and the 
appropriate number of parts are deducted from the number of parts.
** Parameters:  This function takes an integer representing the number
of thing2s to be created.
*********************************************************************/
void Supplies::produceThing2(int quantity) {
	if ((numThingamajigs - (2 * quantity) > 0) && (numFramistats - (1 * quantity))) {
		setNumThingamajigs(numThingamajigs - (2 * quantity));
		setNumFramistats(numFramistats - (1 * quantity));		
	} else {
		cout << "Error:  insufficient parts to produce thing1." << endl;
	}
}

/*********************************************************************
					"Helper" Function Implementation

** Description:  This function prints a description of the program to
the user when the program is first run.
** Parameters:  This function takes no parameters.
*********************************************************************/
void displayProgramDescription() {
	cout << "This program, the user will be asked to enter the current number of" << endl;
	cout << "thingamajigs, watchamacallits, and framistats owned by a factory." << endl;
	cout << "The user will then be asked whether the program should print a parts" << endl;
	cout << "order (the number of each part required to return the number of each" << endl;
	cout << "part needed to return to default levels), to produce thing1, to " << endl;
	cout << "produce a thing2, or to quit the program." << endl;
}

int main() {
	int thingamajigs, watchamacallits, framistats, choice, quantity;
	Supplies suppliesHelper;

	displayProgramDescription();

	cout << endl;
	cout << "Enter the number of thingamajigs:\n> ";				// get and store the number of thingamajigs,
	cin >> thingamajigs;											// watchamacallits, and framistats
	cout << "Enter the number of watchamacallits:\n> ";
	cin >> watchamacallits;
	cout << "Enter the number of framistats:\n> ";
	cin >> framistats;

	suppliesHelper.setNumThingamajigs(thingamajigs);				// set the number of thingamajigs,
	suppliesHelper.setNumWatchamacallits(watchamacallits);			// watchamacallits, and framistats for the
	suppliesHelper.setNumFramistats(framistats);					// Supplies object

	cout << endl;

	do {
		cout << "What would you like to do?" << endl;
		cout << "1. Print Parts Order" << endl;
		cout << "2. Produce Thing1" << endl;
		cout << "3. Produce Thing2" << endl;
		cout << "4. Quit" << endl;
		cout << "> ";
		cin >> choice;

		if ((choice < 1) || (choice > 4)) {								// make sure choice is valid (is 1, 2, 3, or 4)
			cout << "Error:  Invalid input." << endl;
			cout << "Choice must be 1, 2, 3, or 4." << endl << endl;
		} else {
			switch(choice) {
				case 1:													// print out parts order if 1 is selected
					cout << endl;
					suppliesHelper.printPartsOrder();
					cout << endl;
					break;
				case 2:													// create thing1
					cout << endl;
					cout << "How many thing1s would you like to produce?\n> ";
					cin >> quantity;
					suppliesHelper.produceThing1(quantity);
					break;
				case 3:													// create thing2
					cout << endl;
					cout << "How many thing2s would you like to produce?\n> ";
					cin >> quantity;
					suppliesHelper.produceThing2(quantity);
					break;
				case 4:													// quit program
					cout << "Program terminating." << endl;
					break;
			}
		}
	} while (choice != 4);

	return 0;
}