/*********************************************************************
** Author:  Marc Clinedinst
** Date:  22 February 2015
** Description:  This file contains a program which implements a
simple encryption method known as the Caesar Cipher.  The Caesar
Cipher involves shifting all letters in the alphabet by a pre-
determined offset value.  This program asks the user to provide a
phrase to be encrypted and an offset value.  The progrm then encrypts
the phrase using the Caesar cipher and offset value provided by the
user.  After encrypting the phrase, the program then outputs the 
encrypted version of the text.
*********************************************************************/
#include <iostream>

using namespace std;

const int LETTERS_IN_ALPHABET = 26;

/*********************************************************************
					"Helper" Function Prototypes
*********************************************************************/
void displayProgramDescription();
char shiftLetter(char, int);
void encipher(char [], int);

/*********************************************************************
					"Helper" Function Implementations

** Description:  This function prints a description of the program to
the user when the program is first run.
** Parameters:  This function takes no parameters.
*********************************************************************/
void displayProgramDescription() {
	cout << "This program program performs a week encryption of a phrase" << endl;
	cout << "using the Caesar cipher. The user will be asked to enter a" << endl;
	cout << "phrase with a maximum length of 100, as well as an offset." << endl;
	cout << "The program will then output the encrypted phrase." << endl << endl;
}

/*********************************************************************
** Description:  This function performs the most important action in
the program--it shifts a character by an offset as long as the
character is a letter in the alphabet.  Two of the return statements
in this function are somewhat cryptic, but we basically take advantage
of modular arithmetic in this function.  Specifically, we determine
the difference in position between the character passed to the function
first letter of the alphabet, A.  We then add the offset to this value
and find the remainder of this value when divided by the number of
letters in the alphabet.  This value tells us how many letters from
the first letter of the alphabet the new value is; we add this
difference to the position of the first letter, and we have our new
letter.  This is a bit convoluted, but I picked up this technique in
a Coursera course which taught how to make simple video games using
Python; for one of the programs we wrote in that class, we had a space
ship that would "wrap around" to the other side of the screen once it
hit the edge of the screen.  The concept here is the same, so I was
able to use a similar approach.
** Parameters:  This function accepts a char value representing a 
letter of the alphabet that needs to be shifted, and an integer 
representing the number of positions the letter should be shifted.
*********************************************************************/
char shiftLetter(char character, int offset) {
	if ((character >= 'A') && (character <= 'Z')) {
		return static_cast<char>('A' + ((character - 'A') + offset) % LETTERS_IN_ALPHABET);
	}

	if ((character >= 'a') && (character <= 'z')) {
		return static_cast<char>('a' + ((character - 'a') + offset) % LETTERS_IN_ALPHABET);
	}

	return character;		// this return statement will handle non-alphabetical characters, which are not shifted
}

/*********************************************************************
** Description:  This function loops through a C-string and shifts
each letter in the C-string by a given offset.  The function uses the
shiftLetter function described above to accomplish the shift.
** Parameters:  This function accepts a char value representing a 
letter of the alphabet that needs to be shifted, and an integer 
representing the number of positions the letter should be shifted.
*********************************************************************/
void encipher(char message[], int offset) {
	int index = 0;

	while (message[index] != '\0') {					// the phrase may be as long as 100 characters; we loop
		cout << shiftLetter(message[index], offset);    // until we hit the null terminator, indicating the end
		index++;										// of the phrase
	}

	cout << endl;
}

int main() {
	const int SIZE = 101;					// maximum size of phrase
	char phrase[SIZE];						// holds phrase provided by user; maximum size of 100 characters
	int offset;								// how many characters to shift letters

	displayProgramDescription();

	cout << "Enter a phrase (maximum length of 100):\n> ";
	cin.getline(phrase, SIZE);

	cout << endl;
	cout << "You entered :" << endl;
	cout << "\"" << phrase << "\"" << endl << endl;

	cout << "Enter an offset:\n> ";
	cin >> offset;

	cout << endl;
	cout << "Encrypting . . . " << endl;

	cout << endl;
	cout << "Encrypted phrase: " << endl;
	encipher(phrase, offset);					// encrypt and print encrypted phrase

	return 0;
}