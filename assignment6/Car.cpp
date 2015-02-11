/*********************************************************************
** Author:  Marc Clinedinst
** Date:  15 February 2015
** Description:  In this program, the user is prompted to enter the
year and make of a car.  The program then creates a Car object based
on those values and sets the car's initial speed to 0.  The program
then allows the user to either accelerate or decelerate the car. The
car has a maximum speed of 80 and a minimum speed of 0; the program
will not allow the car to exceed the maximum or go below the minimum.
*********************************************************************/
#include <iostream>
#include "Car.hpp"

using namespace std;

/*********************************************************************
				Car Class Method Implementations

** Description:  This is the default constructor for the Car class,
which sets the year to 0, the make to an empty string, and the speed to
0.  This constructor calls the setYear, setMake, and setSpeed methods.
** Parameters:  This constructor takes  no parameters.
*********************************************************************/
Car::Car() {
	setYear(0);
	setMake("");
	setSpeed(0);
}

/*********************************************************************
** Description:  This constructor creates a Car object using values 
representing year, make, and speed provided by the user.  This
constructor calls the setYear, setMake, and setSpeed methods to set 
these values for the created object.
** Parameters:  This constructor takes an integer value representing
year, a string value representing make, and an integer value
represetning speed.
*********************************************************************/
Car::Car(int y, string m, int s) {
	setYear(y);
	setMake(m);
	setSpeed(s);
}

/*********************************************************************
** Description:  This function sets the value for the year private
member variable. 
** Parameters:  This function accepts an integer value representing a
calendar year.
*********************************************************************/
void Car::setYear(int y) {
	year = y;
}

/*********************************************************************
** Description:  This function sets the value for the make private
member variable.
** Parameters:  This function accepts a string variable representing
the name of an auto maker.
*********************************************************************/
void Car::setMake(string m) {
	make = m;
}

/*********************************************************************
** Description:  This function sets the value for the speed private
member variable. 
** Parameters:  This function accepts an integer variable representing
the speed of the car.
*********************************************************************/
void Car::setSpeed(int s) {
	speed = s;
}

/*********************************************************************
** Description:  This function returns the current value of the speed
private member variable.
** Parameters:  This function accepts no parameters.
*********************************************************************/
int Car::getSpeed() {
	return speed;
}

/*********************************************************************
** Description:  This function accelerates the car by 10 miles per
hour, provided that it has not already reached the maximum speed of
80 miles per hour.  
** Parameters:  This function accepts no parameters.
*********************************************************************/
void Car::accelerate() {
	if ((speed + 10) > 80) {
		cout << endl;
		cout << "Maximum speed of 80 mph reached." << endl;
		setSpeed(80);
	} else {
		cout << endl;
		cout << "Accelerating vehicle..." << endl;
		setSpeed(speed + 10);
	}
}

/*********************************************************************
** Description:  This function decelerates the car by 10 miles per
hour, provided that it has not already reached the minimum speed of
0 miles per hour.  
** Parameters:  This function accepts no parameters.
*********************************************************************/
void Car::brake() {
	if ((speed - 10) < 0) {
		cout << endl;
		cout << "Minimum speed of 0 mph reached." << endl;
		setSpeed(0);
	} else {
		cout << endl;
		cout << "Braking vehicle..." << endl;
		setSpeed(speed - 10);
	}
}

/*********************************************************************
					"Helper" Function Implementation

** Description:  This function prints a description of the program to
the user when the program is first run.
** Parameters:  This function takes no parameters.
*********************************************************************/
void displayProgramDescription() {
	cout << "In this program, the user will be asked to enter the year and" << endl;
	cout << "make of a car.  The program will then set these values for a " << endl;
	cout << "car with an initial speed of the zero.  The program will then " << endl;
	cout << "cause the car to accelerate 9 times.  The program will then " << endl;
	cout << "cause the car to brake 10 times." << endl;
}

int main() {
	int year, speed, choice;
	string make;
	Car car;										// create car using default constructor

	displayProgramDescription();

	cout << endl;									// collect the values for year and make of car
	cout << "Enter the year of the car:\n> ";
	cin >> year;
	cin.ignore();
	cout << endl;
	cout << "Enter the make of the car:\n> ";
	getline(cin, make);

	car.setYear(year);								// adjust values for year and make to match values
	car.setMake(make);								// provided by user

	do {
		cout << endl;
		cout << "The car is currently going " << car.getSpeed() << " mph." << endl << endl;
		cout << "What would you like to do?" << endl;
		cout << "1. Accelerate" << endl;
		cout << "2. Brake" << endl;
		cout << "3. Quit" << endl;
		cout << "> ";
		cin >> choice;
		if ((choice < 1) || (choice > 3)) {							// make sure user input is 1, 2, or 3
			cout << "Error:  Choice must be 1, 2, or 3." << endl;
		} else {
			switch (choice) {
				case 1:												// accelerate car when user choice is 1
					car.accelerate();
					break;
				case 2:												// brake car when user choice is 2
					car.brake();
					break;
				case 3:	
					cout << endl;									// quit program and output current speed of car
					cout << "Car's final speed: " << car.getSpeed() << endl;
					break;
				default:	
					cout << endl;									// user has entered invalid input
					cout << "Invalid entry." << endl;
					break;
			}
		}
	} while ((choice != 3));										// loop until user quits

	return 0;
}