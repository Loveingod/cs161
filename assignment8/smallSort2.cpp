/*********************************************************************
** Author:  Marc Clinedinst
** Date:  1 March 2015
** Description:  This program prompts the user to enter three
integers.  The program then outputs the numbers to the user in the
order in which they were originally entered.  The program then sorts
the integers into ascending order and outputs the integers to the 
user in the sorted order.  This program relies heaily on functions,
particularly those that use reference parameters.
*********************************************************************/
#include <iostream>
#include <string>

using namespace std;

/*********************************************************************
					"Helper" Function Prototypes
*********************************************************************/
void displayProgramDescription();						// displays description of program to user
void getInt(int *);										// used to get integer input from user
void showOrder(string, int, int, int);					// shows current order of three integer values
void swap(int *, int *);								// switches the values of two integers 
void sortThreeValues(int *, int *, int *);				// sorts three values into ascending order

/*********************************************************************
					"Helper" Function Implementations

** Description:  This function prints a description of the program to
the user when the program is first run.
** Parameters:  This function takes no parameters.
*********************************************************************/
void displayProgramDescription() {
	cout << "This program sorts three integers provided by the user" << endl;
	cout << "into ascending user. The program first prompts the user" << endl;
	cout << "to enter three integers.  The program then outputs the" << endl;
	cout << "integers in the original order provided by the user." << endl;
	cout << "The program then sorts the integers and outputs them" << endl;
	cout << "in ascending order." << endl << endl;
}

/*********************************************************************
** Description:  This function gets integer input from the user and
stores it in a memory address passed to the function as a pointer.
** Parameters:  This function takes a pointer to an integer value as
a parameter.  The function returns no values.
*********************************************************************/
void getInt(int *integer) {
	cout << "Enter an integer:\n> ";
	cin >> *integer;
}

/*********************************************************************
** Description:  This function outputs the current order of the
integers stored in three variables, first, second, and third.
** Parameters:  This function accepts a string variable representing
a description of the order of three integer alues.  The function also
accepts the integer values first, second, and third.
*********************************************************************/
void showOrder(string description, int first, int second, int third) {
	cout << description << " order:" << endl;
	cout << first << endl;
	cout << second << endl;
	cout << third << endl;
	cout << endl;
}

/*********************************************************************
** Description:  This function swaps the values stored in two integer
variables.
** Parameters:  This function accepts pointers to two different
integer variables.  The function returns no values.
*********************************************************************/
void swap(int *first, int *second) {
	int temp = *first;
	*first = *second;
	*second = temp;
}

/*********************************************************************
** Description: This is the "meat" of this program.  In other words,
this function performs the main purpose of the program, which is that
of sorting three integers into ascending order.  For example, if the
integers 3, 1, and 2 were passed to this function in this order, they
would be ordered as 1, 2, and 3 by the completion of the function.
This function makes use of the swap function described earlier to
swap the values in two different pointer variables.  
** Parameters:  This function takes three integer pointer parameters
--num1, num2, and num3.  Since these are pointer parameters, this
function will alter the values of the arguments passed to the function.
Although this is a void function and there is therefore no return
value, this function makes use of the return statement at several
parts to exit the function once the function has determined the
appropriate swaps that need to occur.
*********************************************************************/
void sortThreeValues(int *first, int *second, int *third) {
	if ( (*first <= *second) && (*second <= *third) ) {  // If the numbers are already sorted, do nothing.
		return;
	}
	if ( (*first <= *third) && (*third <= *second) ) {  // If the numbers are in *first <= *third <= *second,
		swap(*second, *third);                          // swap *second and *third to get *first <= *second <= *third.
		return;
	}
	if ( (*second <= *first) && (*first <= *third) ) {  // If the numbers are in *second <= *first <= *third,
		swap(*first, *second);                          // swap *first and *second to get *first <= *second <= *third.
		return;
	}
	if ( (*second <= *third) && (*third <= *first) ) {  // If the numbers are in *second <= *third <= *first,
		swap(*first, *second);                          // swap *first and *second and then *second and *third
		swap(*second, *third);                          // to get *first <= *second <= *third
		return;
	}
	if ( (*third <= *first) && (*first <= *second) ) {  // If the numbers are in *third <= *first <= *second,
		swap(*first, *third);					        // swap *first and *third and then *second and *third
		swap(*second, *third);                          // to get *first <= *second <= *third
		return;
	}
	if ( (*third <= *second) && (*second <= *first) ) {   // If the numbers are in *third <= *second <= *first,
		swap(*first, *third);                             // swap *first and *third to get *first <= *second <= *second
		return;
	}
}

int main() {
	int x, y, z;

	displayProgramDescription();					// display the program description

	getInt(&x);										// get the three integer values to be sorted
	getInt(&y);
	getInt(&z);

	cout << endl;

	showOrder("original", x, y, z);					// show the order the values were entered

	sortThreeValues(&x, &y, &z);					// sort the values into ascending order

	showOrder("sorted", x, y, z);					// show the sorted order of the values
	
	return 0;
}