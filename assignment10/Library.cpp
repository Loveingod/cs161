#include <iostream>
#include <iomanip>
#include <string>
#include "Book.hpp"
#include "Patron.hpp"
#include "Library.hpp"

using namespace std;

string getStringInput(string, string);

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

Library::Library() {
	holdings.reserve(100);
	members.reserve(100);
	currentDate = 0;
}

void Library::addBook() {
	cout << "----------Add New Book----------" << endl;
	Book book(getStringInput("ID", "book"), getStringInput("title", "book"), getStringInput("author", "book"));

	for (int index = 0; index < holdings.size(); index++) {
		if (holdings[index].getIdCode() == book.getIdCode()) {
			cout << "Error: Book with ID " << book.getIdCode() << " already exists." << endl;
			return;
		}
	}

	holdings.push_back(book);
}

void Library::addMember() {
	cout << "----------Add New Patron----------" << endl;
	Patron patron(getStringInput("ID", "patron"), getStringInput("name", "patron"));

	for (int index = 0; index < members.size(); index++) {
		if (members[index].getIdNum() == patron.getIdNum()) {
			cout << "Error:  Member with ID " << patron.getIdNum() << " already exists." << endl;
			return;
		}
	}

	members.push_back(patron);
}

void Library::checkOutBook(string patronID, string bookID) {
	int patronIndex = -1, 
		bookIndex = -1;

	for (int index = 0; index < members.size(); index++) {
		if (members[index].getIdNum() == patronID) {
			patronIndex = index;
			break;
		}
	}

	if (patronIndex == -1) {
		cout << "Error:  Patron not found." << endl;
		return;
	}
	
	for (int index = 0; index < holdings.size(); index++) {
		if (holdings[index].getIdCode() == bookID) {
			bookIndex = index;
			break;
		}
	}

	if (bookIndex == -1) {
		cout << "Error:  Book not found." << endl;
		return;
	}

	if (holdings[bookIndex].getLocation() == CHECKED_OUT) {
		cout << "Error:  Book already checked out." << endl;
		return;
	}

	if ((holdings[bookIndex].getLocation() == ON_HOLD_SHELF) && (holdings[bookIndex].getRequestedBy()->getIdNum() != patronID)) {
		cout << "Error:  Book requested by another patron." << endl;
		return;
	}

	members[patronIndex].addBook(&holdings[bookIndex]);
	holdings[bookIndex].setCheckedOutBy(&members[patronIndex]);
	holdings[bookIndex].setDateCheckedOut(currentDate);
	holdings[bookIndex].setLocation(CHECKED_OUT);
	holdings[bookIndex].setRequestedBy(NULL);

	cout << holdings[bookIndex].getTitle() << " checked out by " << members[patronIndex].getName() << endl;
}

void Library::returnBook(string bookID) {
	int bookIndex = -1;

	for (int index = 0; index < holdings.size(); index++) {
		if (holdings[index].getIdCode() == bookID) {
			bookIndex = index;
			break;
		}
	}

	if (bookIndex == -1) {
		cout << "Error:  Book not found." << endl;
		return;
	}

	if (holdings[bookIndex].getLocation() != CHECKED_OUT) {
		cout << "Error:  This book is not checked out." << endl;
		return;
	}

	holdings[bookIndex].getCheckedOutBy()->removeBook(&holdings[bookIndex]);

	if (holdings[bookIndex].getRequestedBy()) {
		holdings[bookIndex].setLocation(ON_HOLD_SHELF);
	} else {
		holdings[bookIndex].setLocation(ON_SHELF);
	}

	holdings[bookIndex].setCheckedOutBy(NULL);

	cout << holdings[bookIndex].getTitle() << " has been returned." << endl;
}

void Library::requestBook(string patronID, string bookID) {
	int patronIndex = -1,
		bookIndex = -1;

	for (int index = 0; index < members.size(); index++) {
		if (members[index].getIdNum() == patronID) {
			patronIndex = index;
			break;
		}
	}

	if (patronIndex == -1) {
		cout << "Error:  Patron not found." << endl;
		return;
	}

	for (int index = 0; index < holdings.size(); index++) {
		if (holdings[index].getIdCode() == bookID) {
			bookIndex = index;
			break;
		}
	}

	if (bookIndex == -1) {
		cout << "Error:  Book not found." << endl;
		return;
	}

	if (holdings[bookIndex].getRequestedBy()) {
		if (holdings[bookIndex].getRequestedBy()->getIdNum() != members[patronIndex].getIdNum()) {
			cout << "Error:  Book already requested by another patron." << endl;
		} else {
			cout << "Error:  Book already requested by this patron." << endl;
		}
		return;
	}

	if (holdings[bookIndex].getCheckedOutBy()) {
		if (holdings[bookIndex].getCheckedOutBy()->getIdNum() == members[patronIndex].getIdNum()) {
			cout << "Error:  Book already checked out by this patron." << endl;
			return;
		}
	}

	holdings[bookIndex].setRequestedBy(&members[patronIndex]);

	if (holdings[bookIndex].getLocation() == ON_SHELF) {
		holdings[bookIndex].setLocation(ON_HOLD_SHELF);
	}

	cout << holdings[bookIndex].getTitle() << " requested by " << members[patronIndex].getName() << "." << endl;
}

void Library::incrementCurrentDate() {
	currentDate++;

	for (int patronIndex = 0; patronIndex < members.size(); patronIndex++) {
		for (int bookIndex = 0; bookIndex < members[patronIndex].getCheckedOutBooks().size(); bookIndex++) {
			int daysUntilDue = Book::CHECK_OUT_LENGTH - (currentDate - members[patronIndex].getCheckedOutBooks()[bookIndex]->getDateCheckedOut());
			if (daysUntilDue < 0) {
				members[patronIndex].amendFine(0.10);
			}
		}
	}
}

void Library::payFine(string patronID, double payment) {
	int patronIndex = -1;

	for (int index = 0; index < members.size(); index++) {
		if (members[index].getIdNum() == patronID) {
			patronIndex = index;
		}
	}

	if (patronIndex == -1) {
		cout << "Error:  Patron not found." << endl;
		return;
	}

	members[patronIndex].amendFine(-payment);

	cout << fixed << showpoint << setprecision(2);
	cout << "The fines for " << members[patronIndex].getName() << " are now $" << members[patronIndex].getFineAmount() << endl;  
}

void Library::viewPatronInfo(string patronID) {
	int patronIndex = -1;

	for (int index = 0; index < members.size(); index++) {
		if (members[index].getIdNum() == patronID) {
			patronIndex = index;
			break;
		}
	}

	if (patronIndex == -1) {
		cout << "Error:  patron not found." << endl;
		return;
	}

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
	cout << fixed << showpoint << setprecision(2);
	cout << "Current Fines:     $" << members[patronIndex].getFineAmount() << endl;
}

void Library::viewBookInfo(string bookID) {
	int bookIndex = -1;

	for (int index = 0; index < holdings.size(); index++) {
		if (holdings[index].getIdCode() == bookID) {
			bookIndex = index;
			break;
		}
	}

	if (bookIndex == -1) {
		cout << "Error:  Book not found." << endl;
		return;
	}

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
		//int daysUntilDue = holdings[bookIndex].CHECK_OUT_LENGTH - (currentDate - holdings[bookIndex].getDateCheckedOut());
		int daysUntilDue = Book::CHECK_OUT_LENGTH - (currentDate - holdings[bookIndex].getDateCheckedOut());
		cout << "Days Until Due:     ";
		if (daysUntilDue >= 0) {
			cout << daysUntilDue << endl;
		} else {
			cout << "Overdue" << endl;
		}
	}
}