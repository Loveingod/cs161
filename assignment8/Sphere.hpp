/*********************************************************************
** Author:  Marc Clinedinst
** Date:  1 March 2015
** Description:  This file contains the Sphere class specification.
Sphere class represents a three dimensional sphere often encountered
in geometry.  An instace of the Sphere class has a radius for a public
member variable.  There are also get and set methods for this public
member variable.  Finally, there is a public member function that
calculates and returns the volume.
*********************************************************************/

#ifndef SPHERE_HPP
#define SPHERE_HPP

class Sphere {
	private:
		double radius;						// represents radius of sphere

	public:
		Sphere();							// default constructor that sets radius to 0
		Sphere(double);						// constructor that creates Sphere object with specific radius
		void setRadius(double);				// sets value of the radius public member variable
		double getRadius();					// returns current value of radius
		double getVolume();					// calculates and returns volume of Sphere object
};

#endif