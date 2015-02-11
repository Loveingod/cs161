/*********************************************************************
** Author:  Marc Clinedinst
** Date:  15 February 2015
** Description:  This file contains the Car class specification. The
Car class represents an automobile represented by a make, model,
and speed.  This class specification provides the names of the private
member variables as well as the public member functions associated
with the class.  Together, the variables and functions represent the
data associated with a LineSegment and the types of actions that can
be performed with this data type.
*********************************************************************/

#ifndef CAR_HPP
#define CAR_HPP

#include <string>

using namespace std;

class Car {
	private:
		int year;						// represents the year a car was made
		string make;					// represents the company that made the car
		int speed;						// represents the speed of the car

	public:
		Car();							// default constructor which sets year to 0, make to "", and speed to 0
		Car(int, string, int);			// constructor that sets year, make, and speed to values set by user
		void setYear(int);				// mutator method for setting value of year to value provided by user
		void setMake(string);			// mutator method for setting value of make to value provided by user
		void setSpeed(int);				// mutator method for setting value of speed to value provided by user
		int getSpeed();					// returns current speed of car
		void accelerate();				// adds 10 to the current speed of the car
		void brake();					// subtracts 10 from the current speed of the car
};

#endif