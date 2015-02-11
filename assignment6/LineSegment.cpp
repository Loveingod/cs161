/*********************************************************************
** Author:  Marc Clinedinst
** Date:  15 February 2015
** Description:  In this program, the user is prompted to provide the
x- and y-coordinates for two different points representing the start
and end of a line segment.  The program then calculates the length
and slope of this line segment.  The program then outputs the values
of these calculations to the user.
*********************************************************************/
#include <cmath>
#include <iostream>
#include <string>
#include "Point.hpp"
#include "LineSegment.hpp"

using namespace std;

/*********************************************************************
					"Helper" Function Prototypes
*********************************************************************/
void displayProgramDescription();						// shows description of program to user
double getUserInput(string description);				// general function for accepting input from user


/*********************************************************************
				LineSegment Class Method Implementations

** Description:  This is the default constructor, which is used when a
LineSegment object is created without initial values.  This default
constructor creates a LineSegment object with a begin point of (0,0)
and an end point of (0,0).
** Parameters:  This constructor takes  no parameters.
*********************************************************************/
LineSegment::LineSegment() {
	setEnd1(Point());				
	setEnd2(Point());
}

/*********************************************************************
** Description:  This constructor creates a LineSegment object using
Point objects provided by the user at the time the object is created.
** Parameters:  This constructor takes two Point objects, representing
the begin and end point of a LineSegment.
*********************************************************************/
LineSegment::LineSegment(Point p1, Point p2) {
	setEnd1(p1);
	setEnd2(p2);
}

/*********************************************************************
** Description:  This function sets the value for the end1 public
member variable using a Point object provided by the user.  
** Parameters:  This function accepts a Point object representing the
begin point of a line segment.
*********************************************************************/
void LineSegment::setEnd1(Point point) {
	end1 = point;
}

/*********************************************************************
** Description:  This function returns the current value of the end1
public member variable.
** Parameters:  This function accepts no parameters.
*********************************************************************/
Point LineSegment::getEnd1() {
	return end1;
}

/*********************************************************************
** Description:  This function sets the value for the end2 public
member variable using a Point object provided by the user.  
** Parameters:  This function accepts a Point object representing the
end point of a line segment.
*********************************************************************/
void LineSegment::setEnd2(Point point) {
	end2 = point;
}

/*********************************************************************
** Description:  This function returns the current value of the end2
public member variable.
** Parameters:  This function accepts no parameters.
*********************************************************************/
Point LineSegment::getEnd2() {
	return end2;
}

/*********************************************************************
** Description:  This function calculates and returns the length of 
the LineSegment object by using the distanceTo public member function
of the Point class. This function calls the distanceTo function using
the end1 and end2 private member variables.
** Parameters:  This function accepts no parameters.
*********************************************************************/
double LineSegment::length() {
	return end1.distanceTo(end2);
}

/*********************************************************************
** Description:  This function calculates and returns the slope of 
the LineSegment object by using the following formula for slope:
				m = (y1 - y2) / (x1 - x2)
Once the function calculates this value, it returns the value to the
part of the program that called this function.
** Parameters:  This function accepts no parameters.
*********************************************************************/
double LineSegment::slope() {
	return (end1.getYCoord() - end2.getYCoord()) / (end1.getXCoord() - end2.getXCoord());
}

/*********************************************************************
					"Helper" Function Implementations

** Description:  This function prints a description of the program to
the user when the program is first run.
** Parameters:  This function takes no parameters.
*********************************************************************/
void displayProgramDescription() {
	cout << "In this program, the user will be asked to enter the x and y" << endl;
	cout << "coordinates for two points, which represent the start and end" << endl;
	cout << "of the line segment.  Using these values, the program calculates" << endl;
	cout << "and outputs the length and slope of the line segment." << endl;
}

/*********************************************************************
** Description:  This function generalizes the process of collecting
and input from the user.  Since this action needs to be completed four
times to get the x and y values of two different points, this function
is created to enable code re-use.
** Parameters:  This function takes a string description of the 
required input.  It returns a double value.
*********************************************************************/
double getUserInput(string inputDescription) {
	double value;

	cout << endl;
	cout << "Enter the " << inputDescription << " as a double:\n> ";
	cin >> value;

	return value;
}

int main() {
	double x1, y1, x2, y2, length, slope;

	displayProgramDescription();

	x1 = getUserInput("x coordinate for Point 1");				// Here, we get and store the values for x1, y1,
	y1 = getUserInput("y coordinate for Point 1");				// y1, and y2.
	x2 = getUserInput("x coordinate for Point 2");
	y2 = getUserInput("y coordinate for Point 2");

	LineSegment lineSegment(Point(x1, y1), Point(x2, y2));		// Create a LineSegment object using the coordinates
	length = lineSegment.length();								// Calculate and store the length of the line segment
	slope = lineSegment.slope();								// Calculate and store the slope of the line segment

	cout << endl;
	cout << "-----Line Segment Characteristics-----" << endl;
	cout << "Length: " << length << endl;
	cout << "Slope : ";

	if (isinf(slope)) {											// if value returned by slope is infinity, then output
		cout << "none (line is vertical)" << endl;				// that line is vertical
	} else if (isnan(slope)) {									// if value returned by slope is not a number, then
		cout << "none (this is a point)" << endl;				// output that this is a point
	} else {													// otherwise, output value of slope
		cout << slope << endl;
	}

	return 0;
}