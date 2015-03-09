/*********************************************************************
** Author:  Marc Clinedinst
** Date:  15 March 2015
** Description:  This file contains the Book class specification. A
Book object represents a typical book that a person might encounter
in the real world.  An instance of the Book class has an ID code,
a title, an author, an a location.  A book can be checked out or
requested by a Patron.  If a book has been checked out, it also has
a date which it was checked out. There are a number of public member
functions which get and set the values mentioned above.
*********************************************************************/
#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>

using namespace std;

class Patron;  

enum Locale {ON_SHELF, ON_HOLD_SHELF, CHECKED_OUT};

class Book {
    private:
        string idCode;                              // the ID code for a book (it's "primary key"--must be unique)
        string title;                               // title of book
        string author;                              // author of book
        Locale location;                            // location--either on shelf, on hold shelf, or checked out
        Patron* checkedOutBy;                       // the patron who has checked out the book
        Patron* requestedBy;                        // the patron who has requested the book
        int dateCheckedOut;                         // the date on which the book was checked out
    public:
        static const int CHECK_OUT_LENGTH = 21;     // maximum number of days a book can be checked out without being
        Book();                                     // considered overdue            
        Book(string, string, string);
        void setIdCode(string);
        string getIdCode();
        string getTitle();
        string getAuthor();
        Locale getLocation();                       // the rest of these functions are described in further detail in
        void setLocation(Locale);                   // Book.cpp implementation file--these are mostly straight-forward
        Patron* getCheckedOutBy();                  // get and set functions
        void setCheckedOutBy(Patron*);
        Patron* getRequestedBy();
        void setRequestedBy(Patron*);
        int getDateCheckedOut();
        void setDateCheckedOut(int);
};

#endif