/*********************************************************************
** Author:  Marc Clinedinst
** Date:  1 February 2015
** Description:  This file contains the "implementation" code for the
DiceCup class.  Specifically, this file contains all all of the
definitions of public member functions for the DiceCup class.  It also
contains a main method which uses an instance of the DiceCup class
to simulate rolling dice.  Specifically, the main function asks
the user for a number of dice and a number of faces for each die.  It
uses these values to create a DiceCup object with those values.  It
then asks the user how many times it would like to roll the dice in
the cup, and prints  out the values for that many rolls.
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include "DiceCup.hpp"

using namespace std;

/*********************************************************************
					"Helper" Function Prototypes
*********************************************************************/
void displayProgramDescription();				// shows description of program to user at beginning of program
int getUserInput(string inputDescription);		// general function for getting and validating input

/*********************************************************************
					DiceCup Class Method Implementations

** Description:  This is the default constructor, which is used when
a DiceCup object is created without initial values.  This default
constructor creates a cup containing a single coin with two faces.
** Parameters:  This constructor takes  no parameters.
*********************************************************************/
DiceCup::DiceCup() {
	setNumDice(1);					
	setNumFaces(2);
}

/*********************************************************************
** Description:  This constructor takes two integer values, one 
representing the number of dice in the cup and another representing
how many faces each die has.  This constructor then sets these values
for the number of dice and number of faces for each dice.
** Parameters:  This constructor takes two integer values representing
the number of dice and the number of faces for each die.
*********************************************************************/
DiceCup::DiceCup(int dice, int faces) {
	setNumDice(dice);
	setNumFaces(faces);
}

/*********************************************************************
** Description:  This mutator method sets the number of dice in the cup.
If the number is less than 0, the value of numDice defaults to 0 and
an error message is displayed.
** Parameters:  This method takes an integer argument reperesenting
the number of dice.
*********************************************************************/
void DiceCup::setNumDice(int dice) {
	if (dice < 0) {
		numDice = 0;
		cout << "Invalid input for number of dice." << endl;
	} else {
		numDice = dice;
	}
}

/*********************************************************************
** Description:  This mutator method sets the number of faces on each
die in the cup.  If the number is less than 0, then the value of
numFaces defaults to 0 and an error message is displayed.
** Parameters:  This method takes an integer argument representing
the number of dice.
*********************************************************************/
void DiceCup::setNumFaces(int faces) {
	if (faces < 0) {
		numFaces = 0;
		cout << "Invallid input for number of faces." << endl;
	} else {
		numFaces = faces;
	}
}

/*********************************************************************
** Description:  This function simulates rolling the dice in the cup.
Mor specifically, the function "rolls" each of the dice in the cup
by generating a separate random number for each die in the cup.  The
function also keeps track of the total value of the cup roll by adding
up the value of each roll.
** Parameters:  This function takes no parameters, but it does return
the value of the total for the roll.
*********************************************************************/
int DiceCup::rollDice() {
	int total = 0;
	int dieValue;

	cout << "Rolling " << numDice << " which have " << numFaces << " face" << (numFaces > 1 ? "s" : "") << ": " << endl;
	for (int die = 1; die <= numDice; die++) {
		dieValue = rand() % numFaces + 1;		// generate a random number for each die
		total += dieValue;						// keep running total of values for each die
		cout << "Die #" << die << ": " << dieValue << endl;;
	}
	cout << "Total from roll: " << total << endl << endl;

	return total;
}

/*********************************************************************
					"Helper" Function Implementations

** Description:  This function prints a description of the program to
the user when the program is first run.
** Parameters:  This function takes no parameters.
*********************************************************************/
void displayProgramDescription() {
	cout << "This program simulates rolling a cup containing an arbitrary" << endl;
	cout << "number of dice with an arbitrary number of faces. The user" << endl;
	cout << "will be asked to provide a number of dice, a number of faces" << endl;
	cout << "and a number of times to roll the dice in the cup. The program" << endl;
	cout << "will show the value of each dice per roll, as well as the title" << endl;
	cout << "of each roll. Finally, the program will keep a running total of" << endl;
	cout << "all rolls and display this at the end." << endl;
}

/*********************************************************************
** Description:  This function generalizes the process of collecting
and validating input in the program.  All values colllected as input
must non-negative.  This function takes a description of the input, asks
the user for that input, validates the input, and then returns the
input once a valid input has been given.
** Parameters:  This function takes a string description of the 
required input.  It returns a validated integer value.
*********************************************************************/
int getUserInput(string inputDescription) {
	int value;
	do {
		cout << endl;
		cout << "Enter " << inputDescription << " as an integer:\n> ";
		cin >> value;
		if (value < 0) {
			cout << "Error:  value must be greater than 0." << endl << endl;;
		}
	} while (value < 0);
	return value;
}

/*********************************************************************
					Main Function
*********************************************************************/
int main() {
	unsigned seed = time(NULL);						// create seed to ensure unique random rolls
	srand(seed);
	int numFaces, numDice, numRolls, total = 0;
	DiceCup cup;

	displayProgramDescription();

	numFaces = getUserInput("number of faces on each die");	 // get and validate number of faces and number of dice
	numDice = getUserInput("number of dice");
	cup.setNumFaces(numFaces);
	cup.setNumDice(numDice);

	numRolls = getUserInput("number of times to roll the dice");

	for (int roll = 1; roll <= numRolls; roll++) {						// perform as many rolls as user specifies
		cout << "----------Roll #" << roll << "----------" << endl;
		total += cup.rollDice();										// roll dice and keep running total
		cout << "Current Total: " << total << endl <<  endl;
	}

	cout << "Total from " << numRolls << " rolls: " << total << endl;

	return 0;
}