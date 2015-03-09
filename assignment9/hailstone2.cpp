/*********************************************************************
** Author:  Marc Clinedinst
** Date:  8 March 2015
** Description:  This program determines the number of steps in the
hailstone sequence for a particular positive integer provided by the
user.  The hailstone sequence has to basic rules:
		1.  If the number is even, divide by 2 to get the next number.
		2.  If the number is odd, multiply by 3 and add 1 to get the
			next number.
Unlike the previous implementation of this program during Assignment 4,
this implementation uses a recursive algorithm.  The base case for this
algorithm occurs when the number 1 is reach; at this point the recusive
calls stop and the function returns to the part of the program that 
called it.
*********************************************************************/
#include <iostream>

using namespace std;

/*********************************************************************
					"Helper" Function Prototypes
*********************************************************************/
void printProgramDescription();
int getNumber();
void hailstone(int, int *);

/*********************************************************************
					"Helper" Function Implementations

** Description:  This function prints a description of the program to
the user when the program is first run.
** Parameters:  This function takes no parameters.
*********************************************************************/
void printProgramDescription() {
	cout << "This program determines the number of steps in a hailstone sequence for" << endl;
	cout << "a positive integer provided by the user. The user will be asked to enter" << endl;
	cout << "an integer, and the program will provide the number of steps in the" << endl;
	cout << "hailstone sequence." << endl << endl;
}

/*********************************************************************
** Description:  This function gets and validates a number entered by
the user.  For this particular program, the value input by the user
must be positive, so the function will accept and return only those
values that are greater than or equal to 1.  The function has a loop
which runs until the user inputs a valid value.
** Parameters:  This function takes no parameters.
*********************************************************************/
int getNumber() {
	int number;

	do {
		cout << "Enter an integer greater than 0:\n> ";
		cin >> number;
		if (number < 1) {
			cout << "Error:  number must be greater than 0." << endl << endl;
		}
	} while (number < 1);

	cout << endl;
	return number;	
}

/*********************************************************************
** Description:  This function performs the bulk of the work for this 
program.  Unlike the previous implementation of this function during
Assignment 4, this is a recursive implementation.  As a result, there
are three cases to consider for the recursive function:
		1.  Base Case:  If the current number is 1, then recursion is
			over, and we return from this portion of the function.
		2.  Recursive Case:  Since the current number is not 1, 
			increment the number of steps by 1.  Then check if the
			number is evenly divisible by 1.  If so, call the hailstone
			function again with the current number divided by 2 and the
			address of steps as its parameters.  Otherwise, call the
			hailstone function with the number * 2 + 1 and the address
			of steps as its prameters. 
** Parameters:  This program has an integer variable representing the
current number and a pointer to an integer varible containing the
number of steps.  This function returns no particular value, but there
is a return statement which halts recursion when the current number
is equal to 1.
*********************************************************************/
void hailstone(int number, int *steps) {
	cout << number << " ";
	if (number == 1) {
		return;
	} else {
		*steps += 1;
		if (number % 2 == 0) {
			hailstone((number / 2), steps);
		} else {
			hailstone((number * 3 + 1), steps);
		}
	}
}

int main() {
	int steps = 0,							// initialize steps to 0
		number;

	printProgramDescription();				// print description of program to user

	number = getNumber();					// get and store number input by user

	cout << "Hailstone sequence for number " << number << ": ";
	hailstone(number, &steps);										// output each number in the hailstone sequence and calculate steps
	cout << endl << endl;

	cout << "For integer " << number << " there are " << steps << " steps in the hailstone sequence." << endl;	// output number of steps in sequence

	return 0;
}