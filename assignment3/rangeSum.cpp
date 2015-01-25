/*********************************************************************
** Author:  Marc Clinedinst
** Date:  24 January 2015
** Description:  This program prompts the user to inter a lower bound
and an upper bound (both of which are stored in integer variables),
and then finds the sum of the numbers between and including the upper
and lower bounds.  This program makes use of the if/else construct
to determine which if the numbers provided by the user is larger.
The program also makes use of a for loop to loop from the lower
bound to the upper bound and add all of the numbers.  We will clarify
these techniques where they arise within the program.
*********************************************************************/
#include <iostream>

using namespace std;

int main() {
	int integer1,                  // integer1 and integer2 store the initial inputs by the user.
		integer2,
		lower,                     // lower and upper will be used in determining the lower and
		upper,                     // upper bound to be used in the for loop.
		total = 0;                 // We initialize total to 0 so that we can later add numbers
		                           // to this variable in order to form a running total.

	cout << "This program will asks the user to provide two integers. The program will" << endl;
	cout << "then find the sum of all of the integers between the lower number and higher" << endl;
	cout << "number inclusive.  The user may enter the integers an any order; the program" << endl;
	cout << "will determine which is smaller and which is larger." << endl;

	cout << endl;                                      // Here, we collect lower and upper bounds from
	cout << "Please enter the first integer:\n> ";     // the user; these can be entered in any order.
	cin >> integer1;
	cout << "Please enter the second integer:\n> ";
	cin >> integer2;

	if (integer1 > integer2) {                         // Here we determine the lower and upper bounds
		upper = integer1;                              // from the inputs for integer1 and integer2.
		lower = integer2;                              // The user is not required to enter these in
	} else {                                           // a particular order, so we use an if/else
		upper = integer2;                              // construct to detrmine the larger and smaller
		lower = integer1;                              // value.
	}

	for (int number = lower; number <= upper; number++) {  // Here, we loop through the values between
		total += number;                                   // the upper and lower values, and keep a 
	}                                                      // running total of the values between
	                                                       // the lower and upper bound.  If the lower
	                                                       // and upper bounds are the same, the loop
	                                                       // still executes once to add the value to
	                                                       // total.

	cout << "The sum of the numbers between " << lower << " and " << upper << " inclusive is " << total << endl;

	return 0;
}