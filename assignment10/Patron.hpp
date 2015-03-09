/*********************************************************************
** Author:  Marc Clinedinst
** Date:  15 March 2015
** Description:  This file contains the Patron class specification. A
Patron object represents a patron who visits a library to check out,
request, or return books.  An instance of the Patron object has an ID
number, a name, a list of books they have checked out, and a fine
amount that is due to be paid to the library.There are a number of
public member functions which get and set the values mentioned above.
There are also functions which add and remove books from the patron's
list of checked out books.
*********************************************************************/
#ifndef PATRON_HPP
#define PATRON_HPP

#include <string>
#include <vector>

using namespace std;

class Book;

class Patron
{
private:
    string idNum;                           // the ID number for a Patron (must be unique--it's the "primary key")
    string name;                            // name of the Patron, not necessarily unique
    vector<Book*> checkedOutBooks;          // list of books checked out by user
    double fineAmount;                      // amount owed to library for overdue books
public:
    Patron();                               // we omit comments for most of these functions, since they're typical
    Patron(string, string);                 // get and set functions; further details are in Patron.cpp
    string getIdNum();
    string getName();
    vector<Book*> getCheckedOutBooks();
    void addBook(Book*);                    // adds book to list of books checked out by patron
    void removeBook(Book*);                 // removes book from list of books checked out patron
    double getFineAmount();
    void amendFine(double);
};

#endif
