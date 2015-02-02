/*********************************************************************
** Author:  Marc Clinedinst
** Date:  1 February 2015
** Description:  This program calculates the volume and surface area
of a rectangular prism.  The user is prompted to enter the length,
width, and height of a rectangular prism.  The program then calculates
and outputs volume and surface area of the given rectangular prism.
*********************************************************************/
#include <iostream>
#include <string>
#include "Box.hpp"

using namespace std;

/*********************************************************************
					"Helper" Function Prototypes
*********************************************************************/
void displayProgramDescription();						// shows description of program to user at beginning of program
double getUserInput(string inputDescription);			// general function for getting and validating input

/*********************************************************************
					Box Class Method Implementations

** Description:  This is the default constructor, which is used when
a Box object is created without initial values.  This default
constructor creates a rectangular prism with a length, height, and
width of all 1.
** Parameters:  This constructor takes  no parameters.
*********************************************************************/
Box::Box() {
	setLength(1);										
	setWidth(1);
	setHeight(1);
}

/*********************************************************************
** Description:  This constructor creates a Box object with values
for length, height, and with thatare  provided by the programmer. It
calls the setLength, setWidth, and setHeight methods, which validate
and set the values.
** Parameters:  This constructor double values representing the
length, width, and height of a rectangular prism.
*********************************************************************/
Box::Box(double l, double w, double h) {
	setLength(l);										
	setWidth(w);
	setHeight(h);
}

/*********************************************************************
** Description:  This class method sets the length of a Box object,
so long as the value provided is non-negative.  If the value is
negative, then an error message is displayed in the console, and length
is set to 0.
** Parameters:  This method takes a double representing the length
of a rectangular prism.
*********************************************************************/
void Box::setLength(double l) {							
	if (l < 0) {										
		length = 0;
		cout << "Invalid input for length." << endl;
	} else {
		length = l;
	}
}

/*********************************************************************
** Description:  This class method sets the width of a Box object,
so long as the value provided is non-negative.  If the value is
negative, then an error message is displayed in the console, and width
is set to 0.
** Parameters:  This method takes a double representing the width
of a rectangular prism.
*********************************************************************/
void Box::setWidth(double w) {				
	if (w < 0) {
		width = 0;
		cout << "Invalid input for width." << endl;
	} else {
		width = w;
	}
}

/*********************************************************************
** Description:  This class method sets the height of a Box object,
so long as the value provided is non-negative.  If the value is
negative, then an error message is displayed in the console, and height
is set to 0.
** Parameters:  This method takes a double representing the height
of a rectangular prism.
*********************************************************************/
void Box::setHeight(double h) {
	if (h < 0) {
		height = 0;
		cout << "Invalid input for height." << endl;
	} else {
		height = h;
	}
}

/*********************************************************************
** Description:  This class method calculates the volumearea of a
rectangular prism using the common formula for calculating this value.
The method then returns this value to the part of the program where
this method was called.
** Parameters:  This method takes no arguments.
*********************************************************************/
double Box::getVolume() {
	return length * width * height;
}

/*********************************************************************
** Description:  This class method calculates the surface are of a
rectangular prism using the common formula for calculating this value.
The method then returns this value to the part of the program where
this method was called.
** Parameters:  This method takes no arguments.
*********************************************************************/
double Box::getSurfaceArea() {
	return 2 * ((width * length) + (height * length) + (height * width));
}

/*********************************************************************
					"Helper" Function Implementations

** Description:  This function prints a description of the program to
the user when the program is first run.
** Parameters:  This function takes no parameters.
*********************************************************************/
void displayProgramDescription() {
	cout << "This program calculates the volume and surface area of a rectangular" << endl;
	cout << "prism.  The user will be prompted to enter the length, width, and height" << endl;
	cout << "of a rectangular prism.  The program will then calculate and display the" << endl;
	cout << "volume and surface area." << endl;
}

/*********************************************************************
** Description:  This function generalizes the process of collecting
and validating input in the program.  All values colllected as input
must non-negative.  This function takes a description of the input, asks
the user for that input, validates the input, and then returns the
input once a valid input has been given.
** Parameters:  This function takes a string description of the 
required input.  It returns a validated integer value.
*********************************************************************/
double getUserInput(string inputDescription) {
	double value;
	do {
		cout << endl;
		cout << "Enter " << inputDescription << " as a double:\n> ";
		cin >> value;
		if (value < 0) {
			cout << "Error:  value must be greater than 0." << endl << endl;;
		}
	} while (value < 0);
	return value;
}

int main() {
	double length, width, height;
	Box rectangularPrism;

	length = getUserInput("length");			// get and validate input for length, width, and height
	width = getUserInput("width");				// of rectangularPrism
	height = getUserInput("height");

	rectangularPrism.setLength(length);			// set values of length, width, and height of rectangularPrism
	rectangularPrism.setWidth(width);			// using values provided by user
	rectangularPrism.setHeight(height);

	cout << endl;
	cout << "Volume      : " << rectangularPrism.getVolume() << endl;		// output results of volume and
	cout << "Surface Area: " << rectangularPrism.getSurfaceArea() << endl; 	// surface area calculations

	return 0;
}