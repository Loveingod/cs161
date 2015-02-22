/*********************************************************************
** Author:  Marc Clinedinst
** Date:  22 February 2015
** Description:  This file contains the ShoppingCart class
specification.  A ShoppingCart object represents a shopping cart a
customer might use when shopping on an online store.  An instance of
the ShoppingCart class has a vector object, which contains all of the
items that are currently in the shopping cart.  Additionally, a
ShoppingCart object can add additional items, list all of the items
currently in the shopping car, and calculate the price of all items
in the shopping cart.
*********************************************************************/
#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP

#include <vector>

class ShoppingCart {
	private:
		vector<Item> items;			// a container object for holding all of the items added to the shopping cart

	public:
		void addItem(Item);			// allows "shopper" to add additional items to the shopping cart
		void listContents();		// lists all of the items currently in the shopping cart
		double totalPrice();		// calculates the total price of all of the items in the shopping cart
};

#endif