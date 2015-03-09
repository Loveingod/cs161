/*********************************************************************
** Author:  Marc Clinedinst
** Date:  15 March 2015
** Description:  This file contains the class implementation details
for the Patron class.  Specifically, this file contains the definitions
of the constructors and public member functions for the Patron class.
Each of these constructors and functions is described in detail below.
*********************************************************************/
#include <iostream>
#include <string>
#include "Book.hpp"
#include "Patron.hpp"

using namespace std;

/*********************************************************************
				Patron Class Method Implementations

** Description:  This is the default constructor for the Patron class. 
It creates an "empty" Patron, with its string values being set to the 
empty string and other values being set to 0.
** Parameters:  This constructor takes no parameters.
*********************************************************************/
Patron::Patron() {
	idNum = "";
	name = "";
	fineAmount = 0.0;
}

/*********************************************************************
** Description:  This is the constructor accepts two strings, one
representing the ID number for a Patron and the other representing the
Patron's name.  The function creates a new Patron object using these
values and sets its fine amount to 0.
** Parameters:  This constructor takes a string representing an ID
number and a string representing a name.
*********************************************************************/
Patron::Patron(string idn, string n) {
	idNum = idn;
	name = n;
	fineAmount = 0.0;	
}

/*********************************************************************
** Description:  This function returns the ID number associated with
a Patron.
** Parameters:  This function takes no parameters.
*********************************************************************/
string Patron::getIdNum() {
	return idNum;
}

/*********************************************************************
** Description:  This function returns the name number associated with
a Patron.
** Parameters:  This function takes no parameters.
*********************************************************************/
string Patron::getName() {
	return name;
}

/*********************************************************************
** Description:  This function returns the list of books that a Patron
has checked out.
** Parameters:  This function takes no parameters.
*********************************************************************/
vector<Book*> Patron::getCheckedOutBooks() {
	return checkedOutBooks;
}

/*********************************************************************
** Description:  This function adds a book to the list of books that
the user has checked out.
** Parameters:  This function accepts a pointer to a Book object.
*********************************************************************/
void Patron::addBook(Book* b) {
	checkedOutBooks.push_back(b);
}

/*********************************************************************
** Description:  This function searches through the list of books that
a user has checked out, looking for a particular book.  If the function
finds the book, then the function removes it from the list of books.
** Parameters:  This function accepts a pointer to a Book object.
*********************************************************************/
void Patron::removeBook(Book* b) {
	for (int index = 0; index < getCheckedOutBooks().size(); index++) {
		if (getCheckedOutBooks()[index]->getTitle() == b->getTitle()) {
			checkedOutBooks.erase(checkedOutBooks.begin() + index);
			break;
		}
	}
}

/*********************************************************************
** Description:  This function returns the amount that the Patron owes
for books kept past their due date.
** Parameters:  This function accepts no parameters.
*********************************************************************/
double Patron::getFineAmount() {
	return fineAmount;
}

/*********************************************************************
** Description:  This function amends a fine by an amount provided by
the programmer.  Positive amounts increase the fine amount, and negative
amounts decrease the fine amount.
** Parameters:  This function accepts no parameters.
*********************************************************************/
void Patron::amendFine(double amount) {
	fineAmount += amount;
}