/*********************************************************************
** Author:  Marc Clinedinst
** Date:  25 January 2015
** Description:  This program uses the following equation to determine
the distance that an object falls due to gravity during a certain time
interval:
			d = 0.5 * g * t^2
where d is the distance fallen, g represents standard gravity, and
t is the length of time.  More specifically, the program prompts the 
user to enter the amount of time that an object falls.  Once this 
information has been provided, the program computes the distance the
object falls in that amount of time.
*********************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

double fallDistance(double fallingTime);

const double STANDARD_GRAVITY = 9.8;

int main() {
	double fallingTime,
		   distanceFallen;

	cout << "This program calculates the distance an object falls" << endl;
	cout << "due to gravity during a specific period of time. The" << endl;
	cout << "program will prompt the user to enter the amount of" << endl;
	cout << "time in seconds that an object falls. The program" << endl;
	cout << "will then calculate the distance that the object" << endl;
	cout << "falls.  The program will then output this value" << endl;
	cout << "to the user." << endl;

	do {																// In lines 35 through 42, we valildate that the
		cout << endl;													// user enters a positive number since an object
		cout << "Enter the amount of time that an object falls:\n> ";   // cannot fall for a negative amount of time.
		cin >> fallingTime;
		if (fallingTime < 0) {
			cout << "Error:  time cannot be negative." << endl;
		}
	} while (fallingTime < 0);

	distanceFallen = fallDistance(fallingTime);							// Call the fallDistance function by passing in
																	    // the amount of time the object has fallen;
																		// store the result in distanceFallen.

	cout << "In " << fallingTime << " seconds the object will fall " << distanceFallen << " meters." << endl;

	return 0;
}

/*********************************************************************
** Description:  This function computes the distance an object falls
due to gravity when given the amount of time that the object has
been falling.  The function then returns this value so that it can
be stored for later use.
** Parameters:  This function requires that a double value be passed
into the function.  This double value represents the amount of time
that an object has fallen.  The function returns a double value to
the part of the program where it was called.
*********************************************************************/
double fallDistance(double fallingTime) {
	return (0.5 * STANDARD_GRAVITY * pow(fallingTime, 2.0));
}