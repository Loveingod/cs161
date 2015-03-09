/*********************************************************************
** Author:  Marc Clinedinst
** Date:  15 March 2015
** Description:  This file contains the class implementation details
for the Book class.  Specifically, this file contains the definitions
of the constructors and public member functions for the Book class.
Each of these constructors and functions is described in detail below.
*********************************************************************/
#include <iostream>
#include <string>
#include "Book.hpp"

using namespace std;

/*********************************************************************
				Book Class Method Implementations

** Description:  This is the default constructor for the Book class. It
creates an "empty" book, with its string values being set to the empty
string and other values being set to null or 0.
** Parameters:  This constructor takes no parameters.
*********************************************************************/
Book::Book() {
	setIdCode("");
	title = "";
	author = "";
	setLocation(ON_SHELF);
	setCheckedOutBy(NULL);
	setRequestedBy(NULL);
	setDateCheckedOut(0);
}

/*********************************************************************
** Description:  This constructor creates a Book object using an ID
code, title, and author provided the the programmer when the constructor
is called.  It also initially sets the book to being on the shelf.  It
indicates that no one has yet checked out the book, and no one has yet
requested the book.  FInally, it sets the date checked out to 0.
** Parameters:  This constructor takes three string parameters 
representing the ID code, title, and author of a book.
*********************************************************************/
Book::Book(string idc, string t, string a) {
	setIdCode(idc);
	title = t;
	author = a;
	setLocation(ON_SHELF);
	setCheckedOutBy(NULL);
	setRequestedBy(NULL);
	setDateCheckedOut(0);
}

/*********************************************************************
** Description:  This function sets the ID code for a book using a
string value provided by the user.  This ID code is expected to be
unique, but this input validation is handled in the Library.cpp
implementation file.
** Parameters:  This function accepts a string value representing 
the ID code for a book.
*********************************************************************/
void Book::setIdCode(string idc) {
	idCode = idc;
}

/*********************************************************************
** Description:  This function returns the ID code of a book.
** Parameters:  This function accepts no parameters.
*********************************************************************/
string Book::getIdCode() {
	return idCode;
}

/*********************************************************************
** Description:  This function returns the title for a book.
** Parameters:  This function accepts no parameters.
*********************************************************************/
string Book::getTitle() {
	return title;
}

/*********************************************************************
** Description:  This function returns the author for a book.
** Parameters:  This function accepts no parameters.
*********************************************************************/
string Book::getAuthor() {
	return author;
}

/*********************************************************************
** Description:  This function returns the location for a book.
** Parameters:  This function accepts no parameters.
*********************************************************************/
Locale Book::getLocation() {
	return location;
}

/*********************************************************************
** Description:  This function sets the location for a book using a
Locale value provided by the user.  This location value will either
be on the shelf, on the hold shelf, or checked out.
** Parameters:  This function accepts a Locale value representing a
location for the book.
*********************************************************************/
void Book::setLocation(Locale lo) {
	location = lo;
}

/*********************************************************************
** Description:  This function returns the patron who has checked out
a book.
** Parameters:  This function accepts no parameters.
*********************************************************************/
Patron* Book::getCheckedOutBy() {
	return checkedOutBy;
}

/*********************************************************************
** Description:  This function is used to indicate that a book has
been checked out by a particular patron.
** Parameters:  This function accepts a pointer to a Patron object. It
returns no values.
*********************************************************************/
void Book::setCheckedOutBy(Patron* p) {
	checkedOutBy = p;
}

/*********************************************************************
** Description:  This function returns the patron who has requested a
book.
** Parameters:  This function accepts no parameters.
*********************************************************************/
Patron* Book::getRequestedBy() {
	return requestedBy;
}

/*********************************************************************
** Description:  This function is used to indicate that a book has
been requested by a particular patron.
** Parameters:  This function accepts a pointer to a Patron object. It
returns no values.
*********************************************************************/
void Book::setRequestedBy(Patron* p) {
	requestedBy = p;
}

/*********************************************************************
** Description:  This function returns the date a book was checked
out.
** Parameters:  This function accepts no parameters.
*********************************************************************/
int Book::getDateCheckedOut() {
	return dateCheckedOut;
}

/*********************************************************************
** Description:  This function sets the check out date for a book.
** Parameters:  This function accepts a pointer to an integer value
representing the date that a book has been checked out.
*********************************************************************/
void Book::setDateCheckedOut(int d) {
	dateCheckedOut = d;
}