/*********************************************************************
** Author:  Marc Clinedinst
** Date:  1 March 2015
** Description:  This program calculates the volume of a sphere using
a value for a sphere's radius provided by the user.  More specifically,
the program asks the user to enter a double value representing the
sphere of a radius.  The program then creates a Sphere object using
this value.  The program then calculates and outputs the volume of the
sphere.
*********************************************************************/
#include <iostream>
#include <iomanip>
#include "Sphere.hpp"

using namespace std;

/*********************************************************************
					"Helper" Function Prototypes
*********************************************************************/
void printProgramDescription();					// print description of program to user
double getRadius();								// get and validate radius provided by user
void printSphereInfo(Sphere *);					// print the radius and volume of a sphere

/*********************************************************************
					"Helper" Function Implementations

** Description:  This function prints a description of the program to
the user when the program is first run.
** Parameters:  This function takes no parameters.
*********************************************************************/
void printProgramDescription() {
	cout << "This program computes and prints the volume of a sphere using" << endl;
	cout << "a double value representing a radius that is provided by the" << endl;
	cout << "user. The user will be asked to enter the value of the radius" << endl;
	cout << "and then the program will calculate and output the result to" << endl;
	cout << "the user." << endl << endl;
}

/*********************************************************************
** Description:  This function gets and validates a double value 
representing the radius of a sphere.  More specifically, the function 
requires that the user enter a non-zero value for the radius.
** Parameters:  This function takes no parameters.
*********************************************************************/
double getRadius() {
	double radius;

	cout << "Enter the radius of a sphere:\n> ";
	cin >> radius;

	if (radius < 0) {
		cout << "Error: radius must be positive." << endl;
		return getRadius();
	}

	return radius;
}

/*********************************************************************
** Description:  This functin prints out the radius and volume of a
Sphere object.  Each of these values is printed to two significant 
digits.
** Parameters:  This function takes a pointer to a Sphere object.
*********************************************************************/
void printSphereInfo(Sphere *sphere) {
	cout << endl;
	cout << setprecision(6);
	cout << "----------Sphere Data----------" << endl;
	cout << "Radius: " << sphere->getRadius() << endl;
	cout << "Volume: " << sphere->getVolume() << endl;
}

int main() {
	printProgramDescription();

	Sphere sphere;

	sphere.setRadius(getRadius());

	printSphereInfo(&sphere);

	return 0;
}