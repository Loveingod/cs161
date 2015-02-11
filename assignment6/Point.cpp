/*********************************************************************
** Author:  Marc Clinedinst
** Date:  15 February 2015
** Description:  This file contains the implementation code for the
Point class.  Specifically, it contains the definitions of the
public member functions for the Point class.  We define the
constructors, accessor and mutator methods, and the distanceTo
public member functions.  These will be used in the 
*********************************************************************/

#include "Point.hpp"
#include <iostream>
#include <cmath>

using namespace std;

/*********************************************************************
					Point Class Method Implementations

** Description:  This is the default constructor, which is used when
a Point object is created without initial values.  This default
constructor creates a point with x- and y-coordinates of 0.
** Parameters:  This constructor takes  no parameters.
*********************************************************************/
Point::Point() {
	setXCoord(0.0);
	setYCoord(0.0);
}

/*********************************************************************
** Description:  This constructor sets initial values for the xCoord
and yCoord public member variables using double values provided by
the programmer.  It calls the setXCoord and setYCoord public member
functions to accomplish this task.
** Parameters:  This constructor accepts two double values
representing the x-coordinate and y-coordinate of a geometrical point.
*********************************************************************/
Point::Point(double x, double y) {
	setXCoord(x);
	setYCoord(y);
}

/*********************************************************************
** Description:  This function sets the value for the xCoord public
member variable using a double value provided by the user.  
** Parameters:  This function accepts a double value representing the
x-coordinate of a point object.
*********************************************************************/
void Point::setXCoord(double x) {
	xCoord = x;
}

/*********************************************************************
** Description:  This function returns the current value of the xCoord
public member variable.
** Parameters:  This function accepts no parameters.
*********************************************************************/
double Point::getXCoord() const {
	return xCoord;
}

/*********************************************************************
** Description:  This function sets the value for the yCoord public
member variable using a double value provided by the user.  
** Parameters:  This function accepts a double value representing the
y-coordinate of a point object.
*********************************************************************/
void Point::setYCoord(double y) {
	yCoord = y;
}

/*********************************************************************
** Description:  This function returns the current value of the yCoord
public member variable.
** Parameters:  This function accepts no parameters.
*********************************************************************/
double Point::getYCoord() const {
	return yCoord;
}

/*********************************************************************
** Description:  This function calculates the distance between the
current point and another point provided by the programmer calling
the function.  This function uses the following formula to calculate
the distance:
				d = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2))
After calculating this value, the function returns to this value to
the part of the program that called the function. 
** Parameters:  This function accepts a constant reference to another
point object.
*********************************************************************/
double Point::distanceTo(const Point &other) {
	return sqrt(pow((xCoord - other.getXCoord()), 2) + pow((yCoord - other.getYCoord()), 2));
}