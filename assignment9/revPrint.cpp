/*********************************************************************
** Author:  Marc Clinedinst
** Date:  8 March 2015
** Description:  This program uses a recursive function to print
backwards an array of integers.  Specifically, the program asks the
user to indicate the number of integers that they would like to enter.
The user is then prompted to enter that many numbers.  Once the user
has finished entering numbers, the program prints out the numbers in
reverse order.
*********************************************************************/
#include <iostream>

using namespace std;

/*********************************************************************
					"Helper" Function Prototypes
*********************************************************************/
void printProgramDescription();
void getNumValues(int *);
void revPrint(int [], int);

/*********************************************************************
					"Helper" Function Implementations

** Description:  This function prints a description of the program to
the user when the program is first run.
** Parameters:  This function takes no parameters.
*********************************************************************/
void printProgramDescription() {
	cout << "This program will print an array in reverse order.  The program will" << endl;
	cout << "ask the user to indicate the number of integers they would like to" << endl;
	cout << "enter and then the user will be prompted to enter that many values." << endl;
	cout << "Once the values have been intered, the program will print them in" << endl;
	cout << "reverse order." << endl << endl;;
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
** Description:  This function prints out the elements of an array in
reverse order.  It uses a recursive algorithm to accomplish this task.
** Parameters:  This function takes an integer array and an integer
value representing the index of the current value to be printed.
*********************************************************************/
void revPrint(int array[], int index) {
	if (index == 0) {						// this is the base case--there are no elements to be printed
		cout << endl;
		return;
	} else {
		cout << array[index - 1] << " ";	// print out the element at the current index; call the function again
		revPrint(array, index - 1);			// with the same array and the index value decremented by 1
	}
}

int main() {
	int *values,						// integer pointer which will store values entered by user
		numValues;						// number of values user would like to enter

	printProgramDescription();			// print description of program to user

	getNumValues(&numValues);			// get and store total number of values user would like to enter

	if (numValues > 0) {
		values = new int[numValues];	// dynamically allocate memory for array of size user indicates

		cout << "Enter your values below." << endl;
		for (int index = 0; index < numValues; index++) {		// get values from user and store in array
			cout << "Enter value " << (index + 1) << "\n> ";
			cin >> values[index];
		}

		cout << endl;
		cout << "The values in reverse order are: ";
		revPrint(values, numValues);							// print elements in reverse order

		delete [] values;										// free up dynamically allocated memory
		values = 0;
	} else {
		cout << "Number of values must be greater than 0. Program terminating." << endl;
		cout << "Re-run program and input value greater than 0." << endl;
	}

	return 0;
}