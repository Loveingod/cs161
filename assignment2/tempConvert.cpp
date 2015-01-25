/*********************************************************************
** Author:  Marc Clinedinst
** Date:  14 January 2015
** Description:  This program converts a Celsius temperature to a
Fahrenheit temperature.  More specifically, the program asks
the user to enter a number representing a Celsius temperature, 
which is accepted as a floating-point number, and then uses a formula 
to convert the temperature to Fahrenheit, which is also a floating-
point number. Once the conversion is complete, the program outputs
the fahrenheit temperature to the user.
*********************************************************************/

#include <iostream>

using namespace std;

int main() {
	double celsius,
		   fahrenheit;

	cout << "This program will convert a Celsius temperature provided" << endl;
	cout << "by the user to a Fahrenheit temperature." << endl;
	cout << endl;

	cout << "Enter a Celcius temperature to convert:\n> ";
	cin >> celsius;

	/*
		The bulk of this program is self-documenting, but the line below 
		may require some explanation.  The formula for converting Celsius
		formulas to Fahrenheith is as follows: F = (9/5) * C + 32.  Below,
		we have used this formula to convert the user's input for the
		Celsius temperature to Fahrenheit.  Note that we used 9.0 / 5.0
		to avoid integer division and produce a floating-point number;
		if we had used 9/5 as in the original equation, this would have
		produced an integer value and the input would not be as accurate.
	*/
	fahrenheit = (9.0 / 5.0) * celsius + 32;

	cout << endl;
	cout << celsius << " degrees Celcius is equal to " << fahrenheit << " degrees Fahreneit." << endl;

	return 0;
}