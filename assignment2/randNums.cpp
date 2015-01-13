/*********************************************************************
** Author:  Marc Clinedinst
** Date:  9 January 2015
** Description:  
*********************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int lower, 
		upper, 
	    randomNumber1,
	    randomNumber2,
	    randomNumber3,
	    randomNumber4,
	    randomNumber5;
	unsigned seed = time(0);
	srand(seed);

	cout << "This program will generate a random number in the range of a lower" << endl;
	cout << "bound and an upper bound provided by the user." << endl;

	cout << "Please enter the lower bound:\n> ";
	cin >> lower;

	cout << "Please enter the upper bound:\n> ";
	cin >> upper;

	randomNumber1 = lower + (rand() % (upper - lower + 1));
	randomNumber2 = lower + (rand() % (upper - lower + 1));
	randomNumber3 = lower + (rand() % (upper - lower + 1));
	randomNumber4 = lower + (rand() % (upper - lower + 1));
	randomNumber5 = lower + (rand() % (upper - lower + 1));

	cout << "The random numbers between " << lower << " and " << " upper " << " are: " << endl;
	cout << randomNumber1 << endl;
	cout << randomNumber2 << endl;
	cout << randomNumber3 << endl;
	cout << randomNumber4 << endl;
	cout << randomNumber5 << endl;

	return 0;
}