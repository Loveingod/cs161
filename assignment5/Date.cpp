/*********************************************************************
** Author:  Marc Clinedinst
** Date:  1 February 2015
** Description:  This file is the "implementation" code for the
Date class.  It contains definitions for all of the methods of the
date class and includes a main method which uses the Date class to
format dates provided by the user.  The main method asks the user to
enter as integer values the month, day, and year for a particular
date.  The program then creates a date object from these values.
Next, the program asks the user to indicate their preferred 
format for the date, and the program outputs the date in that format.
*********************************************************************/
#include <iostream>
#include <string>
#include "Date.hpp"

using namespace std;

/*********************************************************************
					"Helper" Function Prototypes
*********************************************************************/
int getInputFromUser(int, int, string);
string monthConversion(int);
int setInvalidDateValue(int, int);
void printProgramDescription();

/*********************************************************************
					Date  Class Method Implementations

** Description:  This is the default constructor for the Date class.
When a Date object is created and no parameters are passed, the
default constructor creates a date with an initial value of 1
January 2001.  The constructor calls the setMonth, setDay, and
setYear functions to set these values.
** Parameters:  This function takes no parameters.
*********************************************************************/
Date::Date() {
	setMonth(1);			// Set month to January
	setDay(1);				// Set day to 1
	setYear(2001);			// Set year to 2001
}

/*********************************************************************
** Description:  This is a constructor which creates a  Date object
using month, day, and year values provided by the programmer calling
the  method.  This function uses the setMonth, setDay, and setYear
methods to create the Date object with the values provided.
** Parameters:  This function accepts three integer arguments, which
represent the month, day, and year for a particular date.
*********************************************************************/
Date::Date(int m, int d, int y) {
	setMonth(m);
	setDay(d);
	setYear(y);
}

/*********************************************************************
** Description:  This function accepts an integer value representing
a month and sets the month private member variable month to that value,
as long as it is valid.  The method will accept integers in the range
1 to 12 (corresponding to the integers that are commonly used to
represent months).  If the integer provided is not in that range,
then month defaults to 1, which represents January.
** Parameters:  This function accepts an integer argument which
represents a particular month.
*********************************************************************/
void Date::setMonth(int m) {
	if ((m < 1) || (m > 12)) {
		month = 1;
	} else  {
		month = m;
	}
}

/*********************************************************************
** Description:  This function accepts an integer argument which
represents a day and sets the private member variable day to that value
assuming it is valid.  Since every month has a different number of days
the method verifies that the date is a valid entry before storing it
in the private member variable day.  If the day is determined not to be
valid, then the method sets day to a default value of 1. February is
an "edge case" since it can either have 28 or 29 days depending on
whether the  year is a leap year, but this program allows days in
February to have either 28 or 29 days without addressing the case of
leap years.
** Parameters:  This function accepts an integer argument which 
represents a day.
*********************************************************************/
void Date::setDay(int d) {
	switch (month) {
		case 1:			// January, March, May, July, August, October, and December
		case 3:         // have 31 days; if one of these months is entered, then these
		case 5:         // cases verify that the day is between 1 and 31.
		case 7:
		case 8:
		case 10:
		case 12:
			if ((d < 1) || (d > 31)) {
				day = setInvalidDateValue(month, d);
			} else {
				day = d;
			}
			break;
		case 4:			// April, June, September, and November have 30 days; if one of these
		case 6:			// months is entered, then these cases verify that the day is between
		case 9:         // 1 and 30.
		case 11:
			if ((d < 1) || (d >  30)) {
				day = setInvalidDateValue(month, d);
			} else {
				day = d;
			}
			break;
		case 2:			// February has 28 or 29 days; this case verifies the day is in range 1 to 29
			if ((d < 1) || (d > 29)) {
				day = setInvalidDateValue(month, d);
			} else {
				day = d;
			}
		default:		// If month is not in range 1 to 12, set day to 1.
			day = 1;
			break;
	}
}

/*********************************************************************
** Description:  This function accepts an integer argument representing
a year.  As long as the year is greater than or equal to 1, then the
method sets the value of the private member variable year to the
provided year.  Otherwise, the year defaults to 2001.
** Parameters:  This function accepts an integer argument which 
represents a year.
*********************************************************************/
void Date::setYear(int y) {
	if (y < 1) {
		year = 2001;
	} else {
		year = y;
	}
}

/*********************************************************************
** Description:  This function prints a date object in the MM/DD/YYYY
format.
** Parameters:  This function takes no parameters.
*********************************************************************/
void Date::print1() {
	cout << endl;
	cout << month << "/" << day << "/" << year << endl;
	cout << endl;
}

/*********************************************************************
** Description:  This function prints a date object in the
MONTH DAY, YEAR format.
** Parameters:  This function takes no parameters.
*********************************************************************/
void Date::print2() {
	cout << endl;
	cout << monthConversion(month) << " " << day << ", " << year << endl;
	cout << endl;
}

/*********************************************************************
** Description:  This function prints a date object in the
DAY MONTH YEAR format.
** Parameters:  This function takes no parameters.
*********************************************************************/
void Date::print3() {
	cout << endl;
	cout << day << " " << monthConversion(month) << " " << year << endl;
	cout << endl;
}

/*********************************************************************
					"Helper" Function Definitions

** Description:  This function converts a integer value representing a
month to a string value containing the name of that month. The function
handles the integer values 1 through 12 and converts these values to
the month name that is commonly associated with the integer value
(for instance, 1 = January, 2 = February, etc.). 
** Parameters:  This function takes an integer value representing a
month and returns the string value commonly associated with that 
integer.
*********************************************************************/
string monthConversion(int month) {
	switch (month) {
		case 1:
			return "January";
		case 2:
			return "February";
		case 3:
			return "March";
		case 4:
			return "April";
		case 5:
			return "May";
		case 6:
			return "June";
		case 7:
			return "July";
		case 8:
			return "August";
		case 9:
			return "September";
		case 10:
			return "October";
		case 11:
			return "November";
		case 12:
			return "December";
		default:
			return "Month Does Not Exist";
	}
}

/*********************************************************************
** Description:  This function helps the setDay member function of the
Date class.  Specifically, it indicates that an invalid day was entered
for a particular month because that day is not in the range for that 
month.  It returns the integer 1, which will serve as the default value
for day, since an incorrect value was provided.
** Parameters:  This function takes two integer values representing a
month and day respectively.  It returns the value 1, which is stored
as a default value for day.
*********************************************************************/
int setInvalidDateValue(int month, int day) {
	cout << day << " is not a valid day for " << monthConversion(month) << "." << endl;
	cout << "Defaulting day to 1." <<  endl;

	return 1;
}

/*********************************************************************
** Description:  This function displays the program description that
will be displayed at the start of the program.  We chose to encapsulate
this in a function so that we could provide a name for the block of
code and to keep our main function shorter.
** Parameters:  This function takes no parameters.
*********************************************************************/
void printProgramDescription() {
	cout << "This program prompts the user to enter integer values" <<  endl;
	cout << "representing the day, month, and year for a particular" << endl;
	cout << "date.  The program then prompts the user to indicate how" << endl;
	cout << "the date should be formatted.  The program then formats" << endl; 
	cout << "the date according to the indicated format." <<  endl;
	cout << endl;
}

/*********************************************************************
** Description:  This function displays a menu of formatting options,
as well as the option to quit the program.
** Parameters:  This function takes no parameters.
*********************************************************************/
void displayMenu() {
	cout << endl;
	cout << "How would you like to format the date?" << endl;
	cout << "1. MM/DD/YYYY       (Example: 3/15/2013)" << endl;
	cout << "2. MONTH DAY, YEAR  (Example: March 15, 2013)" << endl;
	cout << "3. DAY MONTH YEAR   (Example: 15 March 2013)" << endl;
	cout << "4. Quit" << endl;
	cout << endl;
}

/*********************************************************************
** Description:  This is a general function which is used to get the
month, day, year, and choice inputs from the user.  It checks that the
input value falls in the range of acceptable inputs for the type of
input.   The function loops until an appropriate value is entered; it
then returns the validated value to the part of the program that
called it.
** Parameters:  This function takes two integer values representing
a lower and an upper bound for acceptable values.  It also accepts
a string which indicates the type of input required.
*********************************************************************/
int getInputFromUser(int lower, int upper, string typeOfInput) {
	int userInput;
	do {
		cout << "Enter " << typeOfInput << " as an integer:\n> ";
		cin >> userInput;
		if ((userInput < lower) || (userInput > upper) ) {
			cout << "Error:  Input must be between " << lower << " and " << upper << "." << endl;
		}
	} while ( (userInput < lower) || (userInput > upper) );

	return userInput;
}

/*********************************************************************
					Main Function
*********************************************************************/
int main() {
	int month, day, year;
	int choice;

	printProgramDescription();						
	month = getInputFromUser(1, 12, "month");		// Use getInputFromUser to collect and validate
	day = getInputFromUser(1, 31, "day");			// month, day, and year values.
	year = getInputFromUser(1, 9999, "year");

	Date userDate = Date(month, day, year);			// Create a date object with the validated values.

	do {
		displayMenu();
		choice = getInputFromUser(1, 4, "choice");	// Use the getInputFromUser to collect and validate choice
		if ((choice < 1) || (choice > 4)) {
			cout << "Invalid choice.  Choice must be 1, 2, 3, or 4." << endl << endl;
		}
	} while ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4));

	switch (choice) {
		case 1:
			userDate.print1();				// output date in MM/DD/YYYY format
			break;
		case 2:
			userDate.print2();				// output date in MONTH DAY, YEAR format
			break;
		case 3:
			userDate.print3();				// output date in DAY MONTH YEAR format
			break;
		default:
			cout << "Sorry to see you go!" << endl;
	}

	return 0;
}