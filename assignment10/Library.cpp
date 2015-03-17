/*********************************************************************
** Author:  Marc Clinedinst
** Date:  15 March 2015
** Description:  This file contains the class implementation details for
the Library class.  Specifically, this file contains the definitions
of the constructors and public member functions for the Libraryy class.
Each of these constructors and functions is described in detail below.
*********************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include "Book.hpp"
#include "Patron.hpp"
#include "Library.hpp"

using namespace std;

/*********************************************************************
					"Helper" Function Prototype
*********************************************************************/
string getStringInput(string, string);

/*********************************************************************
					"Helper" Function Implementation

** Description:  This is a general function for getting and validating
string input that will be used to create Book and Patron objects. The
function expects string values representing the value being collected
and the name of the type for which the data is being collected. This
function verifies that the length of the string input by the user is
at least 1 character long.  Once such a string has been input, the
function returns the validated value.
** Parameters:  This function takes two string parameters, representing
the value and the type of the value.  The function returns a validated
string value entered by the user.
*********************************************************************/
string getStringInput(string value, string type) {
	string input;

	do {
		cout << "Enter the " << value << " for the " << type << ":\n> ";
		getline(cin, input);
		if (input.length() < 1) {
			cout << "Invalid input." << endl;
			cout << value << " must be at least 1 character long." << endl;
		}
	} while (input.length() < 1);

	return input;
}

/*********************************************************************
				Library Class Method Implementations

** Description:  This is the default constructor for the Library class.
It creates an empty library, reserving 100 spaces for books and 100
spaces for members.  It sets the current date to 0.
** Parameters:  This constructor takes no parameters.
*********************************************************************/
Library::Library() {
	holdings.reserve(100);
	members.reserve(100);
	currentDate = 0;
}

/*********************************************************************
** Description:  This function prompts the user for book information
and creates a new book using the information provided by the user.
Specifically, the program gets the ID, title, and author for the book
(these values are validated by the getStringInput function), and creates
a new book object so long as the ID is unique.
** Parameters:  This function takes no parameters.
*********************************************************************/
void Library::addBook() {
	cout << "----------Add New Book----------" << endl;
	Book book(getStringInput("ID", "book"), getStringInput("title", "book"), getStringInput("author", "book"));

	/*
		In the loop below, we search through holdings to make sure that no book with the
		provided ID exists.  If one does, we do not create a new book with the duplicate
		ID.  Instead, we print an appropriate error message and go back to the menu.
	*/
	for (int index = 0; index < holdings.size(); index++) {										
		if (holdings[index].getIdCode() == book.getIdCode()) {									
			cout << "Error: Book with ID " << book.getIdCode() << " already exists." << endl;	
			return;
		}
	}

	holdings.push_back(book);			// no duplicate found; add new book to holdings
}

/*********************************************************************
** Description:  This function prompts the user for patron information
and creates a new patron using the information provided by the user.
Specifically, the program gets the ID, and name of the patron (these
values are validated by the getStringInput function), and creates a new
patron object so long as the ID is unique.
** Parameters:  This function takes no parameters.
*********************************************************************/
void Library::addMember() {
	cout << "----------Add New Patron----------" << endl;
	Patron patron(getStringInput("ID", "patron"), getStringInput("name", "patron"));
	/*
		In the loop below, we search through members to make sure that no patron with the provided
		id already exists.  If one does, we do not create a new book with the duplicate ID.  Instead,
		we print an appropriate error message and go back to the menu.
	*/
	for (int index = 0; index < members.size(); index++) {											
		if (members[index].getIdNum() == patron.getIdNum()) {										
			cout << "Error:  Member with ID " << patron.getIdNum() << " already exists." << endl;	
			return;																					
		}
	}

	members.push_back(patron);		// no duplicate found; add new patron to members
}

/*********************************************************************
** Description:  This function checks out a particular book for a 
particular patron, provided that the book is not already checked out
or requested by another patron.  If the book is already on checked out
or requested by another patron, then the function prints out the
appropriate message and returns to the menu.  Otherwise, the function
checks out the book for the patron.  The particular details of this
will be addressed in comments below.
** Parameters:  This function accepts two string values, one of which
represents the ID associated with a patron and another of which 
represents the ID associated with a book.
*********************************************************************/
void Library::checkOutBook(string patronID, string bookID) {
	int patronIndex = -1, 
		bookIndex = -1;

	for (int index = 0; index < members.size(); index++) {		// look to see if member is in the member list 
		if (members[index].getIdNum() == patronID) {
			patronIndex = index;								// member found; keep track of member index
			break;
		}
	}

	if (patronIndex == -1) {									// member not found; return to menu
		cout << "Error:  Patron not found." << endl;
		return;
	}
	
	for (int index = 0; index < holdings.size(); index++) {		// look to see if book is in holdings
		if (holdings[index].getIdCode() == bookID) {
			bookIndex = index;									// book found; keep track of book index
			break;
		}
	}

	if (bookIndex == -1) {										// book not found; return to menu
		cout << "Error:  Book not found." << endl;
		return;
	}

	if (holdings[bookIndex].getLocation() == CHECKED_OUT) {		// if book is already checked out, return to menu
		cout << "Error:  Book already checked out." << endl;
		return;
	}

	if ((holdings[bookIndex].getLocation() == ON_HOLD_SHELF) && (holdings[bookIndex].getRequestedBy()->getIdNum() != patronID)) {
		cout << "Error:  Book requested by another patron." << endl;	// book is on hold shelf for another patron;
		return;															// return to menu
	}

	members[patronIndex].addBook(&holdings[bookIndex]);			 // we get to this point only if the book can be
	holdings[bookIndex].setCheckedOutBy(&members[patronIndex]);	 // checked out by the current user; in this case, we
	holdings[bookIndex].setDateCheckedOut(currentDate);			 // add the book to the patron's list, indicate that the 
	holdings[bookIndex].setLocation(CHECKED_OUT);				 // book is checked out by this user, update the date
	holdings[bookIndex].setRequestedBy(NULL);					 // book was checked out, update the location, and
																 // reset the requested by variable
	cout << holdings[bookIndex].getTitle() << " checked out by " << members[patronIndex].getName() << endl;
}

/*********************************************************************
** Description:  This function returns a checked out book to the shelf
if the book is indeed already checked out by a user.  If the book is
not checked out, then the function prints the appropriate message and
returns to the menu.  Otherwise, the function removes the book from
the patron's list, and places it on the hold shelf it his been requested
by another patron or back in the stacks if it is not on request.
** Parameters:  This function takes a string variable representing the
ID for a book.
*********************************************************************/
void Library::returnBook(string bookID) {
	int bookIndex = -1;

	for (int index = 0; index < holdings.size(); index++) {			// check to see if this book is owned by
		if (holdings[index].getIdCode() == bookID) {				// the library; maybe it belongs to some
			bookIndex = index;										// other library, and we do not want to rob
			break;													// them of their books
		}
	}

	if (bookIndex == -1) {								// book not owned by library; return to menu
		cout << "Error:  Book not found." << endl;
		return;
	}

	if (holdings[bookIndex].getLocation() != CHECKED_OUT) {				// if book is not checked out, print
		cout << "Error:  This book is not checked out." << endl;		// appropriate error message
		return;
	}

	/*
		It might be a bit cryptic for someone who hasn't read the program description, so we'll explain 
		a bit.  We have already verified that the book exists and that it is checked out.  In the line 
		below, we look at the book and figure out by whom it is currently checked out; we then remove it 
		from that user's list of checked out books.
	*/
	holdings[bookIndex].getCheckedOutBy()->removeBook(&holdings[bookIndex]);

	if (holdings[bookIndex].getRequestedBy()) {					// if someone has requested the book, then place
		holdings[bookIndex].setLocation(ON_HOLD_SHELF);			// the book on the hold shelf
	} else {												
		holdings[bookIndex].setLocation(ON_SHELF);				// otherwise, place the book back on the shelf
	}

	holdings[bookIndex].setCheckedOutBy(NULL);					// free up the book to be checked out agian

	cout << holdings[bookIndex].getTitle() << " has been returned." << endl;
}

/*********************************************************************
** Description:  This function requests a book for a particular patron
if the book is not already requested by another user.  If the book is
not requested by another user, then the function updates the request
status for the book to reflect the particular patron's desire to check
out the book.  If the book is not already checked out by another user,
then the function moves the book to the hold shelf until the patron
checks out the book.  There is some other business logic involved in
this function, but it is described in detail below.
** Parameters:  This function takes a string value representing the ID
for a patron and a string value representing the ID for a book.
*********************************************************************/
void Library::requestBook(string patronID, string bookID) {
	int patronIndex = -1,
		bookIndex = -1;

	for (int index = 0; index < members.size(); index++) {			// check to see that the provided ID is for
		if (members[index].getIdNum() == patronID) {				// a member of the library
			patronIndex = index;
			break;
		}
	}

	if (patronIndex == -1) {
		cout << "Error:  Patron not found." << endl;				// if no member is found, return to menu
		return;
	}

	for (int index = 0; index < holdings.size(); index++) {			// check to see that the provided ID is for a
		if (holdings[index].getIdCode() == bookID) {				// book in the library
			bookIndex = index;
			break;
		}
	}

	if (bookIndex == -1) {							
		cout << "Error:  Book not found." << endl;					// if no book is found, return to menu
		return;
	}

	/*
		Check the current request status for the book.  If it is already requested, figure out who
		has requested the book--another patron or the current patron.  In either case, print the
		appropriate error message and return to the menu.
	*/
	if (holdings[bookIndex].getRequestedBy()) {
		if (holdings[bookIndex].getRequestedBy()->getIdNum() != members[patronIndex].getIdNum()) {
			cout << "Error:  Book already requested by another patron." << endl;
		} else {
			cout << "Error:  Book already requested by this patron." << endl;
		}
		return;
	}

	/*
		Check to see if the book is already checked out.  If the book is already checked out, see 
		if the book is checked out by the current patron.  If so, indicate that the book is already
		checked out by the current user and return to the menu.

	*/
	if (holdings[bookIndex].getCheckedOutBy()) {
		if (holdings[bookIndex].getCheckedOutBy()->getIdNum() == members[patronIndex].getIdNum()) {
			cout << "Error:  Book already checked out by this patron." << endl;
			return;
		}
	}

	holdings[bookIndex].setRequestedBy(&members[patronIndex]); 	// update the book to indicate it is requested by
																// current patron
	if (holdings[bookIndex].getLocation() == ON_SHELF) {		// move book from stacks to hold shelf
		holdings[bookIndex].setLocation(ON_HOLD_SHELF);
	}

	cout << holdings[bookIndex].getTitle() << " requested by " << members[patronIndex].getName() << "." << endl;
}

/*********************************************************************
** Description:  This function increments the current date.  In
addition, it examines each book in each patron's list of checked out
books to see if the user has one or more books that are overdue.  For
each book that is overdue, $0.10 is added to the user's current fine.
** Parameters:  This function accepts no parameters.
*********************************************************************/
void Library::incrementCurrentDate() {
	currentDate++;

	/*
		There's a lot going on in this loop, so we will break it down a bit.  In the first for statement,
		we loop through each patron in the member list.  In the second for loop, we go through each book
		in the patron's list of checked out books.  If the current book is currently overdue (i.e., it has
		been checked out for more than the maximum check out length), we add $0.10 to the amount owed
		for the fine.
	*/
	for (int patronIndex = 0; patronIndex < members.size(); patronIndex++) {
		for (int bookIndex = 0; bookIndex < members[patronIndex].getCheckedOutBooks().size(); bookIndex++) {
			int daysUntilDue = Book::CHECK_OUT_LENGTH - (currentDate - members[patronIndex].getCheckedOutBooks()[bookIndex]->getDateCheckedOut());
			if (daysUntilDue < 0) {
				members[patronIndex].amendFine(0.10);
			}
		}
	}
}

/*********************************************************************
** Description:  This function pays a fine for a particular patron. It 
makes sure that the the patron is a member of the library and then
applies the payment to the patron's fine.
** Parameters:  This function accepts a string value representing the
ID for a patron and a double amount representing a payment.
*********************************************************************/
void Library::payFine(string patronID, double payment) {
	int patronIndex = -1;

	for (int index = 0; index < members.size(); index++) {			// check that the patron is a member of the
		if (members[index].getIdNum() == patronID) {				// library
			patronIndex = index;
		}
	}

	if (patronIndex == -1) {										// if patron is not a member, return to menu;
		cout << "Error:  Patron not found." << endl;				// I don't get why a library is not accepting
		return;														// free money, though, but whatever
	}

	members[patronIndex].amendFine(-payment);		// this line is a little weird because positive values for amendFine
													// would increase the value of the fine; we must negate the value
	cout << fixed << showpoint << setprecision(2);
	cout << "The fines for " << members[patronIndex].getName() << " are now $" << members[patronIndex].getFineAmount() << endl;  
}

/*********************************************************************
** Description:  This function looks up and prints all of the relevant
information for a particular patron.  Specifically, this function prints
the patron ID, patron name, a list of the books that are currently
checked out, and the current fines associated with the user.
** Parameters:  This function accepts a string value representing a
patron ID.  
*********************************************************************/
void Library::viewPatronInfo(string patronID) {
	int patronIndex = -1;

	for (int index = 0; index < members.size(); index++) {			// look up patron to see if they are in
		if (members[index].getIdNum() == patronID) {				// the database
			patronIndex = index;
			break;
		}
	}

	if (patronIndex == -1) {										// if user is not found, print error message
		cout << "Error:  patron not found." << endl;				// and return to menu
		return;
	}

	/*
		Below, we print out the information that is associated with the specified user.  Specifically,
		we print out the patron's ID, their name, the books they have checked out, and the total that
		is due for their fines.
	*/
	cout << "Patron ID:         " << members[patronIndex].getIdNum() << endl;
	cout << "Patron Name:       " << members[patronIndex].getName() << endl;
	cout << "Books Checked Out: ";
	for (int index = 0; index < members[patronIndex].getCheckedOutBooks().size(); index++) {
		cout << members[patronIndex].getCheckedOutBooks()[index]->getTitle();
		if (index != (members[patronIndex].getCheckedOutBooks().size() - 1)) {
			cout << ", ";
		}
	}
	cout << endl;
	cout << fixed << showpoint << setprecision(2);		// currency formatting
	cout << "Current Fines:     $" << members[patronIndex].getFineAmount() << endl;
}

/*********************************************************************
** Description:  This function prints out all of the information for a
particular book if the book is found in the database.  Specifically,
fhis function prints out the book ID, the book title, the book author,
the book location, by whom the book is requested, and by whom the book
is checked out, and how many days the book has left until it is overdue
or whether it is already overdue.
** Parameters:  This function accepts a string value representing a
book ID.
*********************************************************************/
void Library::viewBookInfo(string bookID) {
	int bookIndex = -1;

	for (int index = 0; index < holdings.size(); index++) {				// look up book to make sure it is in
		if (holdings[index].getIdCode() == bookID) {					// the holdings
			bookIndex = index;
			break;
		}
	}

	if (bookIndex == -1) {												// if book is not found, return to menu
		cout << "Error:  Book not found." << endl;
		return;
	}

	/*
		Print out the following information:
			Book ID (Always)
			Book Title (Always)
			Book Author (Always)
			Book Location (Always)
			Requested By (Only if it has been requested by someone)
			Checked Out By (Only if it is currently checked out)
			Days Until Due (Always)

	*/
	cout << "Book ID:            " << holdings[bookIndex].getIdCode() << endl;
	cout << "Book Title:         " << holdings[bookIndex].getTitle() << endl;
	cout << "Book Author:        " << holdings[bookIndex].getAuthor() << endl;
	cout << "Book Location:      ";
	if (holdings[bookIndex].getLocation() == ON_SHELF) {
		cout << "On Shelf" << endl;
	} else if (holdings[bookIndex].getLocation() == ON_HOLD_SHELF) {
		cout << "On Hold Shelf" << endl;
	} else {
		cout << "Checked Out" << endl;
	}
	if ((holdings[bookIndex].getLocation() == ON_HOLD_SHELF) || (holdings[bookIndex].getRequestedBy())) {
		cout << "Requested By:       " << holdings[bookIndex].getRequestedBy()->getName() << endl;
	}
	if (holdings[bookIndex].getLocation() == CHECKED_OUT) {
		cout << "Checked Out By:     " << holdings[bookIndex].getCheckedOutBy()->getName() << endl;
		// the line below is commented out because it worked on my version of Ubuntu, but not on the flip server
		//int daysUntilDue = holdings[bookIndex].CHECK_OUT_LENGTH - (currentDate - holdings[bookIndex].getDateCheckedOut());
		// I had to rewrite it as follows to get it to work on flip
		int daysUntilDue = Book::CHECK_OUT_LENGTH - (currentDate - holdings[bookIndex].getDateCheckedOut());
		cout << "Days Until Due:     ";
		if (daysUntilDue >= 0) {
			cout << daysUntilDue << endl;
		} else {
			cout << "Overdue" << endl;
		}
	}
}