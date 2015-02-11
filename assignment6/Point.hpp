/*********************************************************************
** Author:  Marc Clinedinst
** Date:  15 February 2015
** Description:  This file contains the Point class specification.  A
Point object represents a geometrical point with an x- and y-
coordinate.  For instance, the point (1, 2) would have an x-
coordinate of 1 and a y-coordinate of 2.  The class specification
provides methods for getting and setting these attributes and for
calculating the distance from one point to another.  This file does not
contain any of the definitions for the member functions, as these will
be defined separately in the Point.cpp file which will use his
specification.
*********************************************************************/
#ifndef POINT_HPP
#define POINT_HPP

class Point {
	private:
		double xCoord;							// represents the x-coordinate in a point, i.e. (x, y)
		double yCoord;							// represents the y-coordinate in a point, i.e. (x, y)

	public:
		Point();								// default constructor--creates a Point with coordinates (0,0)
		Point(double, double);					// constructor that creates a Point with coordinates provided by user
		void setXCoord(double);					// mutator method for setting value of x coordinate
		double getXCoord() const;				// accessor method that returns current value of x coordinate
		void setYCoord(double);					// mutator method for setting value of y coordinate
		double getYCoord() const;				// accessor method that returns current value of y coordinate
		double distanceTo(const Point &);		// calculates and returns distance between to points
};

#endif