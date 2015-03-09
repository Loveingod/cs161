/*********************************************************************
** Author:  Marc Clinedinst
** Date:  1 March 2015
** Description:  This program finds the mode of a data set entered
by the user.  At the beginning of the program, the user is asked to
indicate the total number of values in the data set.  The user is then
prompted to enter that many values.  After entering these values, the
program sorts the values into ascending orders.  The program then
processes the data to determine the mode.  Finally, the program outputs
the mode to the user.
*********************************************************************/
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

/*********************************************************************
					"Helper" Function Prototypes
*********************************************************************/
void printProgramDescription();					// print description of program to user
void getNumValues(int *);						// get number of data set values from user
void printValues(int [], int);					// print values in current order
int getLongestSequence(int [], int);			// get the longest sequence from the data set
void printModes(int [], int, int);				// determines and prints the mode of a data set

/*********************************************************************
					"Helper" Function Implementations

** Description:  This function prints a description of the program to
the user when the program is first run.
** Parameters:  This function takes no parameters.
*********************************************************************/
void printProgramDescription() {
	cout << "This program determines the mode, or most frequently occurring data" << endl;
	cout << "point in a data set.  The user is asked to provide the number of data" << endl;
	cout << "points in a data set.  The user is then prompted to enter that many" << endl;
	cout << "values.  Once all of the values have been entered, the program" << endl;
	cout << "determines and outputs the mode." << endl << endl;
}

/*********************************************************************
** Description:  This function gets the number of values that are in
the data set from the user and stores it in a pointer variable passed
to the function.
** Parameters:  This function accepts a pointer variable, which
refernces a variable containing the number of values in a data set.
*********************************************************************/
void getNumValues(int *numValues) {
	cout << "How many values would you like to enter?\n> ";
	cin >> *numValues;
	cout << endl;
}

/*********************************************************************
** Description:  This function loops through an array and prints each
value in the current order in which the values appear in the array.
If the array is empty, the function prints that there are no values
present.
** Parameters:  This function accepts a string representing the 
descirption of the order (original vs. sorted).  The function also
takes an array of integers and an integer representing the size of
the array.
*********************************************************************/
void printValues(string description, int values[], int size) {
	cout << description;
	if (size > 0) {
		for (int index = 0; index < size; index++) {
			cout << values[index] << ((index < (size - 1)) ? ", " : "");
		}
	} else {
		cout << "No Values Entered";
	}
	cout << endl;
}

/*********************************************************************
** Description:  This function assumes that it has received a sorted
array of integers.  The function loops through each value in the array
and keeps track of the longest sequence of integers that exists 
within the array.  Once the loop has finished iterating through each
element of the array, the function returns the longest sequence that
was encountered in the array.
** Parameters:  This function accepts an array of integers as well as
an integer value which indicates the size of the array.
*********************************************************************/
int getLongestSequence(int values[], int size) {
	int longestSequence = 0,						// tracks longest sequence
		currentNum = values[0],						// tracks value for current sequence
		currentSequence = 0;						// tracks length of current sequence

	for (int index = 0; index < size; index++) {		// if the value at the current index is equal to the 
		if (values[index] == currentNum) {				// current number, increment current sequence
			currentSequence++;
		} else {
			if (currentSequence > longestSequence) {	// value at current index no longer matches current num;
				longestSequence = currentSequence;		// check if it is the longest sequence
			}											// change value at current index to the new number to
			currentNum = values[index];					// check; reset current sequence to 1
			currentSequence = 1;
		}
	}
	if (currentSequence > longestSequence) {			// these lines are needed to avoid an "off by 1" error
		longestSequence = currentSequence;
	}
	return longestSequence;								// return value of longest sequnece
}

/*********************************************************************
** Description:  This function assumee that it has received a sorted
array of integers.  The function then loops through each value in the
array and determines whether or not a particular value is a "mode";
that is, whether it is the most frequently occurring value in a data
set. The function uses the longestSequence parameter to determine
this.  As the function loops through the array, it prints out any
values that are modes.
** Parameters:  This function accepts an array of integers, as well as
an integer value which indicates the size of the array and an integer
representing the length of the longest sequence.
*********************************************************************/
void printModes(int values[], int size, int longestSequence) {
	int currentNum = values[0],						// tracks current number
		currentSequence = 0,						// tracks length of current sequence
		index = 0;									// tracks index of current value
	
	cout << "Mode(s): ";
	for (index; index < size; index++) {				// this loop goes through each element of the sorted
		if (values[index] == currentNum) {				// array and determines whether a value is a mode
			currentSequence++;							// by determining if it has enough occurrences to
		} else {										// match the length of the longest sequence; if so,
			if (currentSequence== longestSequence) {	// the loop prints out the value as a mode
				cout << values[index - 1] << " ";
			}
			currentNum = values[index];
			currentSequence = 1;
		}
	}

	if (currentSequence == longestSequence) {			// these lines avoid an "off by one" error
		cout << values[index-1];
	}

	cout << endl;
}

int main() {
	int *values,							// represents the data set 
		numValues,							// the total number of values in the data set
		longestSequence,					// length of the longest sequence
		currentNum,							// the current number in the current sequence
		currentSequence;					// length of the current sequence

	printProgramDescription();

	getNumValues(&numValues);

	if (numValues > 0) {
		values = new int[numValues];							// dynamically allocate memory for array

		cout << "Enter each value below." << endl;				// get number of data points indicated by
		for (int index = 0; index < numValues; index++) {		// user
			cout << "Enter value #" << (index + 1) << "\n> ";
			cin >> values[index];
		}

		cout << endl;

		printValues("Original Order: ", values, numValues);			// print data points in original order

		sort(values, values + numValues);							// sort data points

		printValues("Sorted Order: ", values, numValues);			// print data poinnts in sorted order

		longestSequence = getLongestSequence(values, numValues);	// get and store the longest sequence

		printModes(values, numValues, longestSequence);				// find and print mode

		delete [] values;											// clear out dynamically allocated memory
		values = 0;
		return 0;
	} else {
		if (numValues == 0) {
			cout << "There is no mode when 0 values are entered." << endl;
		} else {
			cout << "Invalid entry.  Number of values cannot be negative." << endl;
		}
		cout << "Program terminating." << endl;
		cout << "Please re-run with valid input." << endl;
	}

	cout << endl;

	return 0;
}