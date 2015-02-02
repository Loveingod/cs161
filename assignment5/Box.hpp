/*********************************************************************
** Author:  Marc Clinedinst
** Date:  1 February 2015
** Description:  This file contains the Box class specification.  The
Box represents a 3D rectangular prism, which has a length, width,
and height.  The class specification provides methods for setting these
attributesand calculating the volume and surface area. This file does 
not contain any of the definitions for the member function, as these 
will be defined separately in the Box.cpp file which will use this 
specification.
*********************************************************************/
#ifndef BOX_HPP
#define BOX_HPP

class Box {
	private:
		double length;						// length of rectangular prism
		double width;						// width of rectangular prism
		double height;						// height of rectangular prism
	public:
		Box();								// default constructor sets length, width, and height to 1
		Box(double, double, double);		// constructor that sets length, width, and height to specific values
		void setLength(double);				// mutator method for setting length to specific value
		void setWidth(double);				// mutator method for setting width to specific value
		void setHeight(double);				// mutator method for setting height to specific value
		double getVolume();					// calculates volume of rectangular prism
		double getSurfaceArea();			// calculates surface area of rectangular prism
};

#endif