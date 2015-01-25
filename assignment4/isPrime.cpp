/*********************************************************************
** Author:  Marc Clinedinst
** Date:  25 January 2015
** Description:  This program prompts the user to enter a positive
integer and then determines whether the integer is prime.  The program
provides useful output to the user indicating whether or not the number
is prime.
*********************************************************************/
#include <iostream>

using namespace std;

int getInteger();
bool isPrime(int number);

int main() {
	int number;

	cout << "This program determines whether a number is prime.  The user" << endl;
	cout << "will be prompted to enter a number, and then the program will" << endl;
	cout << "determine whether the number is prime. The program will inform" << endl;
	cout << "the user whether the number is prime or not." << endl;

	number = getInteger();

	if (isPrime(number)) {									// Determine whether the integer is prime or not and
		cout << number << " is prime." << endl;				// display the appropriate output.
	} else {
		cout << number << " is not prime." << endl;
	}

	return 0;
}

/*********************************************************************
** Description:  This function is used to get the integer input from
the user.  This integer is required so that the program can check to
see if the number provided by the user is prime.  This program uses
a simple instance of recursion to restart the function in case the
user provides an invalid input (i.e., a non-positive integer).  Once
the function does have a valid input, it returns this value to the
part of the program that called it.
** Parameters:  This function takes no parameters and returns an
integer value, which is generated from user input.
*********************************************************************/
int getInteger() {
	int number;

	cout << endl;
	cout << "Enter an integer greater than 0:\n> ";
	cin >> number;
	if (number < 1) {
		cout << "Error:  number must be greater than 0." << endl;
		number = getInteger();
	}
	return number;
}

/*********************************************************************
** Description:  This is function determines whether or not a
particular integer is prime.  If the number passed to the function is
less than or equal to 1, then the function returns false.  Otherwise,
the function loops through divisors from 2 to 1 less than that number
to determine if it is evenly divisible by any number except 1 and
itself.  If such a number is found, then the function returns false
because the number is not prime.  If such a divisor is not found,
then the function returns true because the number is prime.
** Parameters:  This function takes an integer parameter and returns
a boolean value indicating whether or not the integer is prime.
*********************************************************************/
bool isPrime(int number) {
	if (number <= 1) {						// Immediately returns false if the function receives a value
		return false;						// less than or equal to 1, because these values do not meet
	}										// the definitin of a prime integer.

	for (int divisor = 2; divisor < number; divisor++) {  // Searches for a divisor for the number other
		if (number % divisor == 0) {					  // than 1 and itself; if found, then the integer
			return false;								  // is not prime.
		}
	}

	return true; 	// Failed to find divisor other than 1 and itself; number is prime.
}