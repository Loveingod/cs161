/*********************************************************************
** Author:  Marc Clinedinst
** Date:  22 February 2015
** Description:  This file contains the implementation details for the
ShoppingCart class.  Specifically, it contains definitions of all of
public member functions.  It also contains the defintions of "helper" 
functions used by the main function to interact with the ShoppingCart
object. Finally, this program also contains a main function, which
handles the flow of the program.
*********************************************************************/
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "Item.hpp"
#include "ShopCart.hpp"

using namespace std;

/*********************************************************************
				"Helper" Function Prototypes
*********************************************************************/
void displayProgramDescription();				// display program description to user
void displayMenu();								// display menu of choices to user
int getChoice();								// gets the menu choice from user and verifies that it is in valid range
Item createItem();								// creates an item using the mutator functions of the Item class
string getItemName();							// gets and validates item name
bool isDouble(string);							// checks a string input to make sure that it can be converted to a double
double getItemPrice();							// gets and validates an item price, making sure that it is a double
bool isInt(string);								// checks a string input to make sure that it can be converted to an int
int getItemQuantity();							// gets and validates an item quantity, making sure that it is an int


/*********************************************************************
			Shopping Cart Class Method Implementations

** Description:  This function adds an item object to the shopping 
cart.  More specifically, it adds a new item at the "back" of the
list, so that items are ordered base on how they were added to the 
cart.
** Parameters:  This function takes an Item object as a parameter.
*********************************************************************/
void ShoppingCart::addItem(Item item) {
	items.push_back(item);
}

/*********************************************************************
** Description:  This function lists all of the items currently in
the shopping cart based on the order in which they were added to the
cart.  This function lists the name, price, and quantity for each
item.  
** Parameters:  This function takes no parameters.
*********************************************************************/
void ShoppingCart::listContents() {
	cout << endl;
	if (items.size() > 0) {
		cout << "----------Shopping Cart Contents----------" << endl;
		for (int index = 0; index < items.size(); index++) {
			cout << fixed << showpoint << setprecision(2);
			cout << "Name    : " << items[index].getName() << endl;
			cout << "Price   : $" << items[index].getPrice() << endl;
			cout << "Quantity: " << items[index].getQuantity() << endl;
			cout << endl;
		}
	} else {
		cout << "The shopping cart is empty!" << endl;
	}
}

/*********************************************************************
** Description:  This function calculates the total of all items in
the shopping cart.  More specifically, there is a for loop that
iterates through every item and adds the price times the quanity
for each item to a running total.  This function then returns the
value to the part of the program that called it.
** Parameters:  This function takes no parameters.
*********************************************************************/
double ShoppingCart::totalPrice() {
	double total = 0;
	for (int index = 0; index < items.size(); index++) {
		total += items[index].getPrice() * items[index].getQuantity();
	}

	return total;
}

/*********************************************************************
					"Helper" Function Definitions

** Description:  This function displays a description of the program
to the user, so that the user understand the purpose of the program.
** Parameters:  This function takes no parameters.
*********************************************************************/
void displayProgramDescription() {
	cout << "This program simulates a shopping cart, to which the user can" << endl;
	cout << "add items. Each item has a name, a price, and a quantity.  The" << endl;
	cout << "program also allows the user to print a list of every item in" << endl;
	cout << "the cart.  Finally the user can also print the total of all" << endl;
	cout << "items in the cart." << endl;
}

/*********************************************************************
** Description:  This function displays a menu of options to the user.
The user can choose to add an item to the shopping cart, list all of
the items currently in the shopping cart, print the total for the
items, or quit the program.
** Parameters:  This function takes no parameters.
*********************************************************************/
void displayMenu() {
	cout << endl;
	cout << "Shopping Cart Options" << endl;
	cout << "1. Add Item to Shopping Cart" << endl;
	cout << "2. List Contents of Shopping Cart" << endl;
	cout << "3. Print Total for Items in Shopping Cart" << endl;
	cout << "4. Quit Program" << endl;
}

/*********************************************************************
** Description:  This program gets and validates the choice provided
by the user.  The user's choice must be between 1 and 4 inclusive
** Parameters:  This function takes no parameters.  It returns an int
representing the user's choice from the user menu.
*********************************************************************/
int getChoice() {
	int choice;

	cout << endl;
	cout << "What would you like to do? (Valid Choices: 1, 2, 3, or 4)\n> ";
	cin >> choice;
	cin.ignore();

	if ((choice < 1) || (choice > 4)) {
		cout << "Error:  Invalid entry. Choice must be between 1 and 4 inclusive." << endl << endl;
		displayMenu();
		return getChoice();
	}

	return choice;
}

/*********************************************************************
** Description:  This program gets and validates the choice provided
by the user.  The user's choice must be between 1 and 4 inclusive.
** Parameters:  This function takes no parameters.  It returns an int
representing the user's choice from the user menu.
*********************************************************************/
string getItemName() {
	string name;

	cout << endl;
	cout << "Enter the name of the item:\n> ";
	getline(cin, name);

	if (name.length() == 0) {
		cout << "Error: name must be at least one character long." << endl << endl;
		return getItemName();
	}

	return name;
}

/*********************************************************************
** Description:  This function takes a string value which needs to be
tested to see if it can be converted to a double.  More specifically,
the function loops through each character in the string and makes sure
that the current character can be converted to a double.  Valid 
examples of values that can be converted to doubles are as follows:  
2, 2.0, .2, etc.  If an input value contains more than one decimal
point, such as 2.00.2, the function returns false.  Likewise, if
a value contains any non-numeric character, it returns false.
** Parameters:  This function takes a string value representing a 
potential double; if the value can be converted to a double the
function returns true--otherwise, it returns false.
*********************************************************************/
bool isDouble(string value) {
	int numDecimals = 0;

	for (int index = 0; index < value.length(); index++) {
		char character = value[index];

		if (character == '.') {
			if (numDecimals >= 1) {
				return false;
			} else {
				numDecimals++;
				continue;
			}
		}

		if ((character < '0') || (character > '9')) {
			return false;
		}
	}

	return true;
}

/*********************************************************************
** Description:  This function gets a value from the user and verifies
that it can be converted to a double.  If the value can be converted
to a double, then the function converts the value to a double.  The
function then makes sure that the double value is greater than 0, in
which case the value can be considered a valid price. At this point, 
the function returns the price to the part of the program that called
this function.
** Parameters:  This function accepts no parameters and returns a
double value representing a price.
*********************************************************************/
double getItemPrice() {
	string value;

	cout << endl;
	cout << "Enter the price of the item:\n> $";
	getline(cin, value);

	if (!isDouble(value)) {
		cout << "Error: this is not an acceptable double value." << endl;
		return getItemPrice();
	}

	double price = atof(value.c_str());

	if (price < 0) {
		cout << "Error: price cannot be negative." << endl << endl;
		return getItemPrice();
	}

	return price;
}

/*********************************************************************
** Description:  This function takes a string value which needs to be
tested to see if it can be converted to an int.  More specifically,
the function loops through each character to make sure that is a digit
between 0 and 9.  If we encounter a character that is not a digit, the
function returns false to indicate that it is not an int.  Otherwise,
the function returns true.
** Parameters:  This function takes a string value representing a 
potential int; if the value can be converted to a int the
function returns true--otherwise, it returns false.
*********************************************************************/
bool isInt(string value) {
	for (int index = 0; index < value.length(); index++) {
		char character = value[index];

		if ((character < '0') || (character > '9')) {
			return false;
		}
	}

	return true;
}

/*********************************************************************
** Description:  This function gets a value from the user and verifies
that it can be converted to a integer.  If the value can be converted,
the funciton then converts the value to a double. The function then 
makes sure that the double value is greater than 0, in which case the 
value can be considered a valid quantity. At this point,  the function 
returns the price to the part of the program that called this function.
** Parameters:  This function accepts no parameters and returns a
int value representing a quantity
*********************************************************************/
int getItemQuantity() {
	string value;

	cout << endl;
	cout << "Enter the quantity of the item:\n> ";
	getline(cin, value);

	if (!isInt(value)) {
		cout << "Error: this is not an acceptable integer." << endl;
		return getItemQuantity();
	}

	int quantity = atoi(value.c_str());

	if (quantity < 0) {
		cout << "Error: quantity cannot be negative." << endl << endl;
		return getItemQuantity();
	}

	return quantity;
}

/*********************************************************************
** Description:  This function creates and returns an Item object. 
Specifically, the program creates an instance of the Item class with 
the default constructor.  The program then calls the mutator functions
using the getItemName, getItemPrice, and getItemQuantity functions to
set the values of the item.  The function then returns the item.
** Parameters:  This function accepts no parameters and returns an
item object.
*********************************************************************/
Item createItem() {
	Item item;

	item.setName(getItemName());
	item.setPrice(getItemPrice());
	item.setQuantity(getItemQuantity());

	return item;
}

/*********************************************************************
						main function definition
** Description:  The main function handles the primary logic of this
program.  Specifically, we create an instance of the ShoppingCart
class and a variable to store the user's choice.  We then display a
program description and a menu of options.  The user selects the
option and provides the required information for that option.  The
program then responds appropriately by calling the appropriate 
object methods.
** Parameters:  This function accepts no parameters and returns a
value of 0 once the user quits the program.
*********************************************************************/
int main() {
	ShoppingCart shoppingCart;
	int choice;

	displayProgramDescription();

	do {
		displayMenu();
		choice = getChoice();
		switch (choice) {
			case 1:
				{
					Item item = createItem();
					shoppingCart.addItem(item);
					break;
				}
			case 2:
				{
					shoppingCart.listContents();
					break;
				}
			case 3:
				{
					cout << endl;
					cout << fixed << showpoint << setprecision(2);
					cout << "Current Total: $" << shoppingCart.totalPrice() << endl << endl;
					break;
				}
			case 4:
				{
					cout << "Sorry to see you go!" << endl << endl;
					break;
				}
		}
	} while (choice != 4);

	return 0;
}