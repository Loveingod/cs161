/*********************************************************************
** Author:  Marc Clinedinst
** Date:  22 February 2015
** Description:  This file contains the class implementation details
for the Sphere class. Specifically, this file contains the
definitions of the constructors and public member functions for the
Sphere class. Each of these constructors and functions is described
in detail below.
*********************************************************************/
#include <cmath>
#include "Sphere.hpp"

const double PI = 3.14159;

/*********************************************************************
				Sphere Class Method Implementations

** Description:  This is the default constructor for the Sphere class,
which sets the radius to 0.0.  This constructor calls the setRadius
function.
** Parameters:  This constructor takes no parameters.
*********************************************************************/
Sphere::Sphere() {
	setRadius(0.0);
}

/*********************************************************************
** Description:  This constructor creates an object of the Sphere
class using a double value representing the radius.  This constructor
calls the setRadius function and passes a double value provided by the user.
** Parameters:  This constructor takes a double value representing the
radius of a sphere.
*********************************************************************/
Sphere::Sphere(double r) {
	setRadius(r);
}

void Sphere::setRadius(double r) {
	if (r >= 0) {
		radius = r;
	} else {
		radius = 0;
	}
}

/*********************************************************************
** Description:  This function returns the current value of the radius
private member variable.
** Parameters:  This function accepts no parameters.
*********************************************************************/
double Sphere::getRadius() {
	return radius;
}

/*********************************************************************
** Description:  This function calculates and returns the volume of
a sphere.  
** Parameters:  This function accepts no parameters.
*********************************************************************/
double Sphere::getVolume() {
	return ((4.0/3.0) * PI * pow(radius, 3.0));
}