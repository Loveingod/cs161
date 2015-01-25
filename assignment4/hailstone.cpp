/*********************************************************************
** Author:  Marc Clinedinst
** Date:  25 January 2015
** Description:  This program determines the number of steps in the
hailstone sequence for a particular positive integer provided by the
user.  The hailstone sequence has to basic rules:
		1.  If the number is even, divide by 2 to get the next number.
		2.  If the number is odd, multiply by 3 and add 1 to get the
			next number.
This program generates and outputs the numbers in the hailstone
sequence for a particular number; it also calculates and outputs
the number of steps in the hailstone sequence for a particular integer.
*********************************************************************/
#include <iostream>

using namespace std;

int getNumber();
int numSteps(int number);

int main() {
	int number,
		steps;

	cout << "This program determines the number of steps in a hailstone sequence for" << endl;
	cout << "a positive integer provided by the user. The user will be asked to enter" << endl;
	cout << "an integer, and the program will provide the number of steps in the" << endl;
	cout << "hailstone sequence." << endl << endl;
	
	number = getNumber();			// get and store positive integer from user

	steps = numSteps(number);		// calculate and store steps in hailstone sequence for given number

	cout << "For integer " << number << " there are " << steps << " steps in the hailstone sequence." << endl;

	return 0;
}

/*********************************************************************
** Description:  This simple function gets a positive integer from
the user and returns it to the part of the programm that called it.
There is a loop in this function that is used to validate the input
from the user; specifically, the loop repeats until the user enters a
positive integer.
** Parameters:  This function takes no arguments and returns an
integer value that is generated from user input.
*********************************************************************/
int getNumber() {
	int number;

	do {
		cout << "Enter an integer greater than 0:\n> ";
		cin >> number;
		if (number < 1) {
			cout << "Error:  number must be greater than 0." << endl;
		}
	} while (number < 1);

	return number;	
}

/*********************************************************************
** Description:  This function performs the bulk of the work for this
program.  Specifically, it takes an integer, outputs the numbers in
the hailstone sequence for that number, and ccomputes and returns the
number of steps in that sequence.  
** Parameters:  This program has an integer paramater; the argument
for this parameter should be a positive integer.  This function
returns an integer value representing the number of steps used in
the hailstone sequence for a given integer.
*********************************************************************/
int numSteps(int number) {
	int steps = 0;

	cout << endl;
	cout << "Hailstone sequence for number " << number << ": " << number << " ";

	while (number != 1) {						// This loop generates the next step
		if (number % 2 == 0) {					// in the hailstone sequence for the
			number /= 2;						// given integer and keeps track of
			steps++;							// the number of steps taken in the
		} else {								// sequence.  It also outputs each
			number = (number * 3) + 1;			// value in the hailstone sequence.
			steps++;
		}
		cout << number << " ";
	}

	cout << endl;

	return steps;								// return the number of steps in the sequence
}