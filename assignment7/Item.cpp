/*********************************************************************
** Author:  Marc Clinedinst
** Date:  22 February 2015
** Description:  This file contains the class specification details
for the Item class.  Specifically, this file contains the definitions
of the constructors and public member functions for the Item class.  
Each of these constructors and functions is described in detail below.
*********************************************************************/
#include <iostream>
#include <string>
#include "Item.hpp"

using namespace std;

/*********************************************************************
				Item Class Method Implementations

** Description:  This is the default constructor for the Item class,
which sets the name to the empty string, the price to 0, and the
quantity to 0.  This constructor calls the setName, setPrice, and
setQuantity functions.
** Parameters:  This constructor takes no parameters.
*********************************************************************/
Item::Item() {
	setName("");
	setPrice(0.0);
	setQuantity(0);
}

/*********************************************************************
** Description:  This constructor creates an oject using a string 
value representing the name, a double value representing the price and
and integer value representing the quantity.  These values are
provided by the programmer calling the function.
** Parameters:  This constructor takes a string representing a name,
a double representing a price, and in integer representing a quantity.
*********************************************************************/
Item::Item(string n, double p, int q) {
	setName(n);
	setPrice(p);
	setQuantity(q);
}

/*********************************************************************
** Description:  This function sets the value for the name private
member variable.
** Parameters:  This function accepts a string value representing the
name of an item.
*********************************************************************/
void Item::setName(string n) {
	name = n;
}

/*********************************************************************
** Description:  This function returns the current value of the name
private member variable.
** Parameters:  This function accepts no parameters.
*********************************************************************/
string Item::getName() {
	return name;
}

/*********************************************************************
** Description:  This function sets the value for the price private
member variable.
** Parameters:  This function accepts a double value representing the
price of an item.
*********************************************************************/
void Item::setPrice(double p) {
	price = p;
}

/*********************************************************************
** Description:  This function returns the current value of the price
private member variable.
** Parameters:  This function accepts no parameters.
*********************************************************************/
double Item::getPrice() {
	return price;
}

/*********************************************************************
** Description:  This function sets the value for the quantity private
member variable.
** Parameters:  This function accepts an integer value representing 
the quantity.
*********************************************************************/
void Item::setQuantity(int q) {
	quantity = q;
}

/*********************************************************************
** Description:  This function returns the current value of the 
quantity private member variable.
** Parameters:  This function accepts no parameters.
*********************************************************************/
int Item::getQuantity() {
	return quantity;
}