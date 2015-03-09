/*********************************************************************
** Author:  Marc Clinedinst
** Date:  15 March 2015
** Description:  This program simulates a library's inventory
management.  Specifically, it allows a library to add new books, add
new library patrons, check out books, return books, request books,
track and resolve fines, view the current status of books, and view 
the current status of patrons.  This program makes use of three objects
to perform these tasks:  Book, Patron, and Library.  These objects are
defined and implemented in separate files.  This file simply contains
the menu that controls the flow of the program.
*********************************************************************/
#include <iostream>
#include <string>
#include "Book.hpp"
#include "Patron.hpp"
#include "Library.hpp"

using namespace std;

/*********************************************************************
					"Helper" Function Prototypes
*********************************************************************/
void displayProgramDescription();				// print a description of the program to the user
void displayMenu();								// display a menu of options to the user
int getChoice();								// get and validate menu choice
string getEntityId(string);						// general function for getting Patron ID or Book ID
double getPaymentAmount();						// get and return payment amount

/*********************************************************************
					"Helper" Function Implementations

** Description:  This function prints a description of the program to
the user when the program is first run.
** Parameters:  This function takes no parameters.
*********************************************************************/
void displayProgramDescription() {
	cout << "Welcome to Marc's Public Library Management System!" << endl;
	cout << "Below, you will find a menu of options that you can" << endl;
	cout << "use to add, read, and update information in the" << endl;
	cout << "library's database. You can quit any time by choosing" << endl;
	cout << "the final option in the menu. I hope you enjoy your time!" << endl;
}

/*********************************************************************
** Description:  This function prints a menu of options to the user.
** Parameters:  This function takes no parameters.
*********************************************************************/
void displayMenu() {
	cout << "----------Library Management System Choices----------" << endl;
	cout << "1.  Add Book" << endl;
	cout << "2.  Add Patron" << endl;
	cout << "3.  Check Out Book" << endl;
	cout << "4.  Return Book" << endl;
	cout << "5.  Request Book" << endl;
	cout << "6.  Increment Current Date" << endl;
	cout << "7.  Pay Fine" << endl;
	cout << "8.  View Patron Information" << endl;
	cout << "9.  View Book Information" << endl;
	cout << "10. Quit" << endl;
}

/*********************************************************************
** Description:  This function prompts the user to enter an integer
representing a choice from the menu.  The function validates that the
input falls in an acceptable range and return the valid option once it
has been entered.
** Parameters:  This function takes no parameters. It returns an 
integer representing a choice in the menu.
*********************************************************************/
int getChoice() {
	int choice;
	do {
		cout << "Enter your choice:\n> ";
		cin >> choice;
		cin.ignore();
		if ((choice < 1) || (choice > 10)) {
			cout << "Error:  Invalid choice." << endl;
			cout << "Choice must be between 1 and 10." << endl;
		}
	} while ((choice < 1) || (choice > 10));
	return choice;
}

/*********************************************************************
** Description:  This is a general function for getting and validating
an ID number associated with an object stored in the library's 
database.  This function accepts a string value representing the type
of object for which the ID is to be collected.  The function then
prompts the user for that type of object, validates the user's input,
and then returns the value once it has been verified.
** Parameters:  This function accepts a string representing the type
of entity for which the function is collecting an ID.  The function
returns a string value representing an ID.
*********************************************************************/
string getEntityId(string entity) {
	string value;
	do {
		cout << "Enter the " << entity << " ID:\n> ";
		getline(cin, value);
		if (value.length() < 1) {
			cout << "Error:  " << entity << " ID must have length greater than 0." << endl;
		}
	} while (value.length() < 1);
	cout << endl;
	return value;
}

/*********************************************************************
** Description:  This function gets a double value representing a
payment amount.  
** Parameters:  This function accepts no parameters.  It returns a
double value representing a payment ammount.
*********************************************************************/
double getPaymentAmount() {
	double value;
	cout << "Enter the payment amount:\n> ";
	cin >> value;
	cin.ignore();
	cout << endl;
	return value;
}

/*********************************************************************
					Main Function
*********************************************************************/
int main() {
	Library library;
	int choice;

	displayProgramDescription();

	do {
		cout << endl;
		displayMenu();							// display menu to user
		cout << endl;
		choice = getChoice();					// get and validate choice
		/*
			The switch statement below processes the choice entered by the user.  There are
			10 valid options.  The program responds by calling the appropriate library
			function, or by quitting the program.
		*/
		switch(choice) {
			case 1:						// Add a new book
				cout << endl;
				library.addBook();
				break;
			case 2:						// Add a new member
				cout << endl;
				library.addMember();
				break;
			case 3:						// Check out a particular book for a particular patron
				cout << endl;
				library.checkOutBook(getEntityId("Patron"), getEntityId("Book"));
				break;
			case 4:						// Return a particular book
				cout << endl;
				library.returnBook(getEntityId("Book"));
				break;
			case 5:						// Request a particular book for a particular patron
				cout << endl;
				library.requestBook(getEntityId("Patron"), getEntityId("Book"));
				break;
			case 6:						// Increase the current date by 1
				library.incrementCurrentDate();
				break;
			case 7:						// Pay fine for a particular user
				cout << endl;
				library.payFine(getEntityId("Patron"), getPaymentAmount());
				break;
			case 8:						// View the information for a particular patron
				cout << endl;
				library.viewPatronInfo(getEntityId("Patron"));
				break;
			case 9:						// View the information for a particular book
				cout << endl;
				library.viewBookInfo(getEntityId("Book"));
				break;
			case 10:					// Quit the program
				cout << endl;
				cout << "Sorry to see you go!" << endl;
				break;
			default:
				cout << "Option Not Yet Available." << endl;
		}
	} while (choice != 10);


	return 0;
}