/*********************************************************************
** Author:  Marc Clinedinst
** Date:  24 January 2015
** Description:  This program is a number guessing game.  At the
beginning of the program, we generate a random number between 1 and
100 inclusive.  We then prompt the user to guess the value of the
random number.  If the user guesses a value higher than the random
number, then the program indicates that their guess is too high. 
Likewise, if the guess is too low, the program indicates that the
user needs to lower their guess.  In either case, the user is asked
to provide a new guess until they guess correctly.  The program keeps
a running total of the number of gueses it takes the user to guess
correctly and then presents this information to the user.
*********************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	unsigned seed = time(0);   // Lines 16 and 17 set up the necessary infrastructure to help ensure that each run of
	srand(seed);               // program generate a different random number.  time(0) returns the system's current
	                           // time so that different seeds will be created.

	int secretNumber = rand() % 100 + 1,		// This creates a random number between 1 and 100 inclusive.
		guess = -100,  // We set the initial value of guess to -100 to ensure we enter the loop once. 
		               // I made this decision because I personally prefer the syntax of while loops over do while
		               // loops, but either could have been used here.
		numberOfGuesses = 0;

	cout << "This is a number guessing game!  I am thinking of a number" << endl;
	cout << "between 1 and 100 inclusive.  You have as many guesses as" << endl;
	cout << "you would like to guess the number.  I'll tell you how" << endl;
	cout << "many guesses it took once you have guessed correctly." << endl;
	cout << "Go!" << endl << endl;

	while (guess != secretNumber) {                                     // Loop until the user guesses correctly.
		cout << "Enter guess #" << (numberOfGuesses + 1) << ":\n> ";
		cin >> guess;
		if (guess > secretNumber) {                                     // Inform the user that their guess is too high.
			cout << "Too high.  Try again." << endl;
		} else if (guess < secretNumber) {                              // Inform the user that their guess is too low.
			cout << "Too low.  Try again." << endl;
		} else {                                                        // Inform the user that they have guessed correctly.
			cout << "Correct!  Great job!" << endl;
		}
		numberOfGuesses++;                                              // Keep track of number of guesses after each
	}                                                                   // iteration.

	cout << "It took you " << numberOfGuesses << " guess"               // Here, we let the user know how many guesses
	     << (numberOfGuesses == 1 ? "" : "es")                          // it took to guess correctly.  We use the 
		 << " to guess the secret number " << secretNumber << endl;     // conditional operator to properly format
																		// the word "guess" vs. "guesses" in case
	return 0;															// the user guesses correctly on the first try
}                                                                       