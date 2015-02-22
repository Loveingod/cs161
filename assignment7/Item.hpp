/*********************************************************************
** Author:  Marc Clinedinst
** Date:  22 February 2015
** Description:  This file contains the Item class specification. The
Item class represents an item that a customer might buy while shopping.
An instance of the Item class has a name, a price, and a quantity.
There are get and set public member functions for each of these
variables.  Together, the variables and functions represent the
data and actions associated with an Item object.
*********************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using namespace std;

class Item {
	private:
		string name;					// represents the name of an item
		double price;					// represents the cost of the item
		int quantity;					// represents the number of the item

	public:
		Item();							// default constructor for item
		Item(string, double, int);		// constructor that creates item using values provided by user
		void setName(string);			// mutator method for setting name of item
		string getName();				// returns name of item
		void setPrice(double);			// mutator method for setting price of item
		double getPrice();				// returns price of item
		void setQuantity(int);			// mutator method for setting quantity of item
		int getQuantity();				// returns quantity of item
};

#endif