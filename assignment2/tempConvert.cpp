/*********************************************************************
** Author:  Marc Clinedinst
** Date:  9 January 2015
** Description:   
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

	fahrenheit = (9.0 / 5.0) * celsius + 32;

	cout << endl;
	cout << celsius << " degrees Celcius is equal to " << fahrenheit << " degrees Fahreneit." << endl;

	return 0;
}