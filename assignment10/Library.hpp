/*********************************************************************
** Author:  Marc Clinedinst
** Date:  15 March 2015
** Description:  This file contains the Library class specification. A
Library object represents a library, which consists mainly of books and
patrons.  An instace of the Library object has a list of books, a list
of members, and a current date.  There are a number of public member
functions, each of which will be described briefly below and in more
detail in the implementation file named Library.cpp.
*********************************************************************/
#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <string>
#include <vector>

using namespace std;

class Patron;
class Book;

class Library {
private:
    vector<Book> holdings;                      // list of books owned by library
    vector<Patron> members;                     // list of patrons who are registered at the library
    int currentDate;                            // the current date for library; used to determine due dates and fines
public:
    Library();                                  // creates a new library object with default values
    void addBook();                             // adds a new book to the library's book list
    void addMember();                           // adds a new patron to the library's member list
    void checkOutBook(string, string);          // checks out particular book for particular patron
    void returnBook(string);                    // returns particular book that is currently checked out
    void requestBook(string, string);           // requests a particular book for a particular patron
    void incrementCurrentDate();                // increases the date and calculates fines based on new date
    void payFine(string, double);               // pays fine for a particular patron; fine amount can be any amount
    void viewPatronInfo(string);                // shows data associated with a particular patron
    void viewBookInfo(string);                  // shows data associated with a particular book
};

#endif