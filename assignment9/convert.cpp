/*********************************************************************
** Author:  Marc Clinedinst
** Date:  8 March 2015
** Description:  This program allows the user to convert decimal
numbers to binary numbers and vice versa.  The user is prompted to
choose the type of conversion that they would like the program to
perform.  After selecting the type of conversion that should occur,
the user is then prompted to enter a number in the format that is to
be converted.  The program verifies that the number is in the correct
format, performs the conversion, and then outputs the number in the
new format.  This program uses a recursive function to perform each
type of conversion.
*********************************************************************/
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string>

using namespace std;

/*********************************************************************
					"Helper" Function Prototypes
*********************************************************************/
void printProgramDescription();
int getChoice();
void processChoice(int);
bool isInt(int);
int getDecimalNumber();
bool isBinary(string);
string getBinaryNumber();
string reverse(string);
void decimalToBinary(int, string *);
int binaryToDecimal(string, int);

/*********************************************************************
					"Helper" Function Implementations

** Description:  This function prints a description of the program to
the user when the program is first run.
** Parameters:  This function takes no parameters.
*********************************************************************/
void printProgramDescription() {
	cout << "This program allows users to convert decimal numbers" << endl;
	cout << "to binary numbers, and binary numbers to decimal numbers." << endl;
	cout << "The user will be prompted to choose which conversion they" << endl;
	cout << "would like to do; the program will then perform that type" << endl;
	cout << "of conversion." << endl;
}

/*********************************************************************
** Description:  This function gets and verifies an integer value 
representing the choice that the user would like to perform.  Valid 
choices are 1, 2, and 3.  The function verifies that the input entered
by the user is a valid choice; if so, the function returns the choice.
Otherwise, the function loops until the user has entered a valid
choice.
** Parameters:  This function takes no parameters.
*********************************************************************/
int getChoice() {
	int choice;

	cout << endl;
	cout << "----------Program Menu----------" << endl;
	cout << "1. Convert Decimal to Binary" << endl;
	cout << "2. Convert Binary to Decimal" << endl;
	cout << "3. Quit Program" << endl << endl;;

	do {
		cout << "Enter your choice:\n> ";							// get the choice from the user
		cin >> choice;
		cin.ignore();
		cout << endl;

		if ((choice < 1) || (choice > 3)) {							// if choice is invalid, print an informative
			cout << "Error:  Invalid entry." << endl;				// error message
			cout << "Choice must be 1, 2, or 3." << endl;
			cout << endl;
		}
	} while ((choice < 1) || (choice > 3));							// loop until choice is in valid range

	return choice;
}

/*********************************************************************
** Description:  This function processes the choice entered by the
user, when the choice is either 1 or 2.  If the choice is 1, the 
function sets up the necessary variables to convert a decimal number
to a binary number, performs the conversion, and outputs the result.
Likewise, if the choice is 2, then the function sets up the necessary
variables to convert a binary number to decimal, performs the conversion,
and outputs the result.
** Parameters:  This function accepts an integer value representing
a valid choice provided by the user.  The function assumes that the
choice is either 1 or 2, which are the choices for the number
conversion that needs to occur.
*********************************************************************/
void processChoice(int choice) {
	if (choice == 1) {
		int number = getDecimalNumber();		// get and store decimal number
		string binary = "";						// stores binary version of number
		decimalToBinary(number, &binary);		// converts number to binary
		binary = reverse(binary);				// binary will hold backwards value; this puts it in correct order
		cout << endl;
		cout << number << " converted to binary is " << binary << endl;
	} else {
		string binary = getBinaryNumber();		// get and store binary number
		int decimal = binaryToDecimal(binary, binary.length() - 1);		// convert binary number to decimal
		cout << endl;
		cout << binary << " converted to decimal is " << decimal << endl;
	}
}

/*********************************************************************
** Description:  This function accepts a string representing which can
potentially be converted to an integer.  The function loops through
each character in the string and verfies that each character is a 
numeric digit.  If the function encounters a non-digit character, then
the function returns false.  Otherwise, once the loop is complete, the
function returns true.
** Parameters:  This function accepts a string value representing a
number which needs to be checked to see if it can be converted to an
integer.
*********************************************************************/
bool isInt(string value) {
	for (int index = 0; index < value.length(); index++) {			// loop through each character and make sure
		char character = value[index];								// that it is a digit

		if ((character < '0') || (character > '9')) {				// if a non-digit character is encountered,
			return false;											// return false
		}
	}

	return true;
}

/*********************************************************************
** Description:  This function gets a decimal number from the user.
Specifically, the function reads in a string value and verifies that
it can be converted to a decimal number.  If the number can be 
converted, then the function performs the conversion and returns the 
converted value.  Otherwise, the function calls itself again, 
prompting the user to enter a new value.  The recursion occurs until 
a valid value is entered.
** Parameters:  This function accepts no parameters.
*********************************************************************/
int getDecimalNumber() {
	string value;

	cout << "Enter a decimal number to be converted to a binary number:\n> ";
	getline(cin, value);

	if (!isInt(value)) {
		cout << endl;
		cout << "Error: this is not an acceptable integer." << endl;
		cout << endl;
		return getDecimalNumber();						// if the number cannot be converted to an int, then
	}													// call the getDecimalNumber function again

	return atoi(value.c_str());
}

/*********************************************************************
** Description:  This function accepts a string value which can
potentially be considered a binary number.  The function loops through
each character in the string and verifies that each character is either
a 0 or a 1.  If the function encounters a value that is not 0 or 1,
then the function returns false.  Otherwise, once the loop is complete,
the function returns true.
** Parameters:  This function accepts a string value representing a
number which needs to be checked to see if it can be converted to a
binary number.
*********************************************************************/
bool isBinary(string value) {
	for (int index = 0; index < value.length(); index++) {			// loop through each character in the
		char character = value[index];								// string and verify that it is 1 or 0
		if ((character != '0') && (character != '1')) {
			return false;
		}
	}

	return true;
}

/*********************************************************************
** Description:  This function gets a binary number from the user.
Specifically, the function reads in a string value and verifies that
it can be converted to a binary number.  If the number can be
converted, then the function performs the conversion and returns the
converted value.  Otherwise, the function calls itself again, prompting
the user to enter a new value.  The recursion occurs until a valid
value is entered.
** Parameters:  This function accepts no parameters.
*********************************************************************/
string getBinaryNumber() {
	string value;

	cout << "Enter a binary number to be converted to a decimal number:\n> ";
	getline(cin, value);

	if(!isBinary(value)) {
		cout << endl;
		cout << "Error: this is not an acceptable binary value." << endl;
		cout << endl;
		return getBinaryNumber();
	}

	return value;
}

/*********************************************************************
** Description:  This function reverses a string.  Specifically, it
accepts a string value in its original order, and then returns a 
version of that string that is in the reverse order.
** Parameters:  This function accepts a string value, which needs to
be reversed.
*********************************************************************/
string reverse(string original) {
	string reversed = "";

	for (int index = original.length() - 1; index >= 0; index--) {		// create new string that is reverse of
		reversed += original[index];									// original
	}

	return reversed;
}


/*********************************************************************
** Description:  This function converts a decimal number to a binary
number.  This function is recursive in nature.  With each call of the
function, we first check the base case.  That is, we check to see if
we have reached a integer that is equal to 0 or 1.  If so, we add this
value to the string representing the binary number. For the recursive 
step of this function, we determine whether the remainder of the decimal 
number divided by 2 is 0 or 1; we then concatenate 0 or 1 to the 
binary number according to the remainder.  We then call the function 
again with the decimal number divided by 2. 
** Parameters:  This function accepts in integer variable that needs
to be converted to a binary number and an address to a string variable
where the resulting binary string will be stored.
*********************************************************************/
void decimalToBinary(int decimal, string *binary) {
	if (decimal == 0) {						// if decimal is equal to 0, concatenate "0" to binary
		*binary += "0";
		return;
	} else if (decimal == 1) {				// if decimal is equal to 1, concatenate "1" to binary
		*binary += "1";
		return;
	} else {
		if (decimal % 2 == 0) {				// if decimal is divisible by 2, concatenate "0" to binary
			*binary += "0";
		} else {
			*binary += "1";					// if decimal is odd, concatenate "1" to binary
		}
		decimalToBinary(decimal / 2, binary);	// call function again with number divided by 2
	}
}

/*********************************************************************
** Description:  This function converts a binary number to a decimal
number. For our base case for this function, we check to see if the 
length of the binary number is 1; if so, we return 0 if the length is 
0, or 2 to the power of the position of the number.  If the length of 
the binary number is longer than 1, we consider two cases.  If the 
number at the current index is 0, then we return the sum of 0 and a 
call to the binaryToDecimal function, to which we pass a version of 
the binary string which is one shorter than the current binary number.  
Otherwise, we return the sum of 2 to the power of the position of the 
number and a call to the binaryToDecimal function, to which we pass 
a version of the binary string which is one shorter than the current 
binary number.
** Parameters:  This function accepts a string representing a binary 
number and in integer variable representing the current index.
*********************************************************************/
int binaryToDecimal(string binary, int index) {				// base cases:
	if (index == 0) {
		if (binary[index] == '0') {							// if binary string is length 1 and equal to "0"
			return 0;										// return 0
		} else {
			return pow(2, binary.length() - 1);				// otherwise, return 2 to power of position of 
		}													// current character
	} else {
		if (binary[index] == '0') {							// recursive case:  if string longer than 1, and current
			return 0 + binaryToDecimal(binary, index - 1);	// char is equal to 0, return 0 + string 1 smaller
		} else {											// otherwise return 2 to power of current position
			return pow(2, binary.length() - index - 1) + binaryToDecimal(binary, index - 1); // + string 1 smaller
		}
	}
}

int main() {
	int choice;
															// the main function of this program is very simple;
	printProgramDescription();								// we simply get the choice from the user, and then
															// "process" the choice--our helper functions do
	do {													// all of the work.
		choice = getChoice();								// i tried my best this week to fully embrace the
		if (choice != 3) {									// idea of functional decomposition. 
			processChoice(choice);							// i hope i didn't go too overboard. :D
		} else {
			cout << "Sorry to see you go!" << endl;
		}
	} while (choice != 3);

	return 0;
}