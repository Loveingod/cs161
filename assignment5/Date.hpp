/*********************************************************************
** Author:  Marc Clinedinst
** Date:  1 February 2015
** Description:  This file contains the Date class specification.
More specifically, this file contains the names of the member variables
and member functions for the Date class, which represents a date in the
past, present, or future. This file does not contain any of the 
definitions for the member function, as these will be defined separately 
in the Date.cpp file which will use this specification.
*********************************************************************/
#ifndef DATE_HPP
#define DATE_HPP

class Date {
	private:
		int day;					// day of the month
		int month;					// month of the year
		int year;					// year for the date

	public:
		Date();						// default constructor which creates date of January 1, 2001
		Date(int, int, int);		// constructor used to create Date with specific values
		void setMonth(int);			// mutator method for setting month private member variable
		void setDay(int);			// mutator method for setting day private member variable
		void setYear(int);			// mutator method for setting year private member variable
		void print1();				// outputs date in MM/DD/YYYY format
		void print2();				// outputs date in MONTH DAY, YEAR format
		void print3();				// outputs date in DAY MONTH YEAR format
};

#endif