/*********************************************************************
** Author:  Marc Clinedinst
** Date:  8 March 2015
** Description:  This program uses a recursive function to calculate
the sum of an array of doubles.  Specifically, the program asks the
user to indicate the number of doubles that they would like to enter.
The user is then prompted to enter that many doubles.  Once the user
has finished entering numbers, the program pcalculates and prints the
sum of the doubles.
*********************************************************************/
#include <iostream>

using namespace std;

/*********************************************************************
					"Helper" Function Prototypes
*********************************************************************/
void printProgramDescription();
void getNumValues(int *);
double recSum(double [], int);


/*********************************************************************
					"Helper" Function Implementations

** Description:  This function prints a description of the program to
the user when the program is first run.
** Parameters:  This function takes no parameters.
*********************************************************************/
void printProgramDescription() {
	cout << "This program will calculate the sum of an array of doubles provided" << endl;
	cout << "by the user.  The program will ask the user to indicate the number" << endl;
	cout << "of doubles they would like to enter, and then the user will be" << endl;
	cout << "prompted to enter that many doubles. Once the user has done so," << endl;
	cout << "the program calculates and displays the sum of the values." << endl << endl;
}

/*********************************************************************
** Description:  This function gets an integer representing the number
of values the user would like to enter and stores it in a pointer to
an integer variable.
** Parameters:  This function takes an integer pointer.  This pointer
is used to update the number of values that the user would like to
enter.
*********************************************************************/
void getNumValues(int *numValues) {
	cout << "How many values would you like to enter?\n> ";
	cin >> *numValues;
	cout << endl;
}

/*********************************************************************
** Description:  This function calculates the sum of all of the
double values stored in an array.  It uses a recursive algoritm to
accomplish this task.
** Parameters:  This function takes an integer array and an integer
value representing the index of the current value to be added to the
total.
*********************************************************************/
double recSum(double array[], int index) {
	if (index == 0) {			// no values left to add to sum
		return 0;
	} else {
		return array[index - 1] + recSum(array, index - 1);		// add current element to total
	}
}

int main() {
	double *values;							// integer pointer which will be used to store values entered by user
	int numValues;							// number of values user will enter

	printProgramDescription();				// print program description to user

	getNumValues(&numValues);				// get and store total number of values user would like to enter

	if (numValues > 0) {
		values = new double[numValues];		// dynamically allocate space for array

		cout << "Enter your values below." << endl;						// get and store values in array
		for (int index = 0; index < numValues; index++) {
			cout << "Enter value " << (index + 1) << ":\n> ";
			cin >> values[index];
		}

		cout << endl;
		cout << "The sum of the values is " << recSum(values, numValues) << endl;	// calculate and print total

		delete [] values;				// free up dynamically allocated memory
		values = 0;
	} else {
		cout << "Number of values must be greater than 0. Program terminating." << endl;
		cout << "Please re-run program and inter non-negative number of values." << endl;
	}

	return 0;
}