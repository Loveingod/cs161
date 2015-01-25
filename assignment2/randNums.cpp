/*********************************************************************
** Author:  Marc Clinedinst
** Date:  14 January 2015
** Description:  This program makes use of the cstdlib file to
generate random numbers within a range specified by the end user.
More specifically, the user is asked to provide two integers--
a lower bound and an upper bound.  The program then generates
five separate random integers between the lower bound and upper
bound (inclusive) and outputs these random numbers to the user.
Further, this program generates a seed from the time() function
to make sure that each run of the program produces a more
random set of numbers.
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

	/*
		The lines below provide a description of the program and provide a prompt
		to the user indicating the required input with clearly indicated data
		types for the input.
	*/
	cout << "This program will generate a random number in the range of a lower" << endl;
	cout << "bound and an upper bound provided by the user." << endl;
	cout << "Please enter the lower bound as an integer:\n> ";
	cin >> lower;
	cout << "Please enter the upper bound as an integer:\n> ";
	cin >> upper;

	/*
		The following lines generate five random numbers using the upper and lower
		bounds provided by the user.  More specifically, these lines generate random
		numbers such that the number meets the following specifications:
		lower <= randomNumber# <= upper.
	*/
	randomNumber1 = lower + (rand() % (upper - lower + 1));
	randomNumber2 = lower + (rand() % (upper - lower + 1));
	randomNumber3 = lower + (rand() % (upper - lower + 1));
	randomNumber4 = lower + (rand() % (upper - lower + 1));
	randomNumber5 = lower + (rand() % (upper - lower + 1));

	/*
		The lines below simply reiterate the lower and upper bounds of the random numbers
		and list each random number on a separate line.
	*/
	cout << "The random numbers between " << lower << " and " << " upper " << " are: " << endl;
	cout << randomNumber1 << endl;
	cout << randomNumber2 << endl;
	cout << randomNumber3 << endl;
	cout << randomNumber4 << endl;
	cout << randomNumber5 << endl;

	return 0;
}