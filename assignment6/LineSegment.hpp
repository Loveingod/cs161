/*********************************************************************
** Author:  Marc Clinedinst
** Date:  15 February 2015
** Description:  This file contains the LineSegment class specification.
The LineSegment class represents a line segment with a start and end
point, each of which are represented by point objects.  This class
specification provides the names of the private member variables as
well as the public member functions associated with the class. Together,
the variables and fuctions represent the data associated with a
a LineSegment and the types of actions that can be performed with this
data type.
*********************************************************************/
#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP

class LineSegment {
	private:
		Point end1;						// represents the begin point of a line segment
		Point end2;						// represents the end point of a line segment

	public:
		LineSegment();					// default constructor--sets begin and end point to (0,0)
		LineSegment(Point, Point);		// constructor that creates a line segment with points provided by user
		void setEnd1(Point);			// sets the begin point of a line segment
		Point getEnd1();				// returns current value of begin point of line segment
		void setEnd2(Point);			// sets the end point of a line segment
		Point getEnd2();				// returns current value of end point of line segment
		double length();				// calculates and returns length of line segment
		double slope();					// calculates and returns slope of line segment
};

#endif