/*********************************************************************
** Author:  Marc Clinedinst
** Date:  24 January 2015
** Description:  This program asks the user to provide a toal number
of double values that they would like to enter.  The program then 
allows the user to enter that many values.  As the user enters these
values, the program keeps track of the smallest and largest value
entered.  Once the user has finished providing values, the program
displays the lowest and highest values intered.
*********************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int numberOfDoubles;             // Stores the number of doubles the user would like to enter
	double minimum,                  // Stores the minimum value entered by user
		   maximum,                  // Stores the maximum value entered by user
		   current;                  // Stores the most recent value entered by user; will update
		                             // with each iteration of the loop

	cout << "This program will prompt the user to provide how many" << endl;
	cout << "numbers she would like to enter.  The program will then" << endl;
	cout << "collect that number of values from the user as doubles." << endl;
	cout << "The program will then determine the smallest and largest." << endl;
	cout << "value entered by the user." << endl;

	cout << endl;
	cout << "Please indicate how many numbers you would like to enter:\n> ";
	cin >> numberOfDoubles;

	cout << endl;

	if (numberOfDoubles > 0) {  // Validates that the number of values is greater than 0; otherwise, skip to line 54.
		for (int iteration = 0; iteration < numberOfDoubles; iteration++) {
			cout << "Enter a double:\n> ";
			cin >> current;
			if (iteration == 0) {               // If we are on our first loop iteration, set minimum and maximum to the
				minimum = maximum = current;    // value of the current number.  At this point, only one number has been
				                                // entered, so the minimum and maximum will be the same.
			} else {
				if (current < minimum) {        // We have a new smallest value! 
					minimum = current;
				} else if (current > maximum) { // We have a new largest value!
					maximum = current;          
				} else {
					continue;                   // Don't do anything--just go into the next iteration.
				}
			}
		}
		cout << fixed << showpoint << endl;                  // In lines 52 through 54, we present the user with the
		cout << "Smallest Value: " << minimum << endl;       // results.
		cout << "Largest Value : " << maximum << endl;
	} else {  // We hit this line if numberOfDoubles <= 0.  This program cannot accept 0 or negative number of values.
		if (numberOfDoubles == 0) {
			cout << "You entered 0 values.  There is no smallest or largest value." << endl;
		} else {
			cout << "Stop being silly. You cannot enter a negative number of values." << endl;
		}
	}

	return 0;
}