/*********************************************************************
** Author:  Marc Clinedinst
** Date:  26 January 2015
** Description:  This program prompts the user to enter a word or
phrase and then determines whether the word or phrase is a palindrome.
A palindrome is a word or phrase that is the same forwards as it is 
backwards.  Examples:
		racecar
		able was i ere i saw elba
		12221
This program treats palindromes as case insensitive; if the user
enters "RACEcar" for instance, it will be considered a palindrome,
despite the differences in ASCII codes for lower and uppercase
letters, because the word will be converted to lowercase before
the palindrome determination is made.
*********************************************************************/
#include <iostream>
#include <string>

using namespace std;

string convertToLowerCase(string word);
string reverseWord(string word);
bool isPalindrome(string word);

int main() {
	string word;

	cout << "This program determines whether a word or phrase entered by" << endl;
	cout << "the user is a palindrome.  The program will prompt the user" << endl;
	cout << "to enter a word or a phrase, and then the program will indicate" << endl;
	cout << "whether the word is a palindrome." << endl;

	cout << endl;
	cout << "Enter a word or phrase:\n> ";
	getline(cin, word);

	if (isPalindrome(word)) {													// check if word is a palindrome
		cout << "\"" << word << "\"" << " is a palindrome." << endl;			// and show user the appropriate
	} else {																	// result
		cout << "\"" << word << "\"" << " is not a palindrome." << endl;
	}

	return 0;
}

/*********************************************************************
** Description:  This function converts a word to all lowercase 
letters, making use of the tolower function to convert individual
characters in the word to lowercase.  This function is a "helper"
function function for the isPalindrome function, because it will
be used to ensure that the original and reversed word are both
lowercase so that an accurate comparison can be made.  Since upper-
and lowercase letters have different ASCII codes, we need to have both
words in the same case to test for equality.
** Parameters: This function takes a string parameter named word and \
returns a string value named lower.
*********************************************************************/
string convertToLowerCase(string word) {
	string lower;

	for (int index = 0; index < word.length(); index++) {		// loop through each letter in the word and
		lower += tolower(word[index]);							// convert to lowercase
	}

	return lower;
}

/*********************************************************************
** Description:  This function is another "helper" function for the
isPalindrome function.  To determine whether a word is a palindrome,
we need to compare a word with the reverse of that word.  To assist
with this task, this function reverses a word.  For instance, if the
string "Julius Caesar" were passed to this function, it would return
the string "raseaC suiluJ". 
** Parameters:  This function takes a string parameter named word
and returns a string value named reversed.
*********************************************************************/
string reverseWord(string word) {
	string reverse;

	for (int index = (word.length() - 1); index >= 0; index--) {	// loop through each letter in the word from
		reverse += word[index];										// last to first and build a string of the
	}																// word in reverse order

	return reverse;
}

/*********************************************************************
** Description:  This function is performs the main task of this 
program--determining whether a word is a palindrome.  It convers the
original word to lower case, find the reverse of the word (which is 
also in lowercase) and then compares the words to see if they are the
same.  If so, then the word is a palindrome.  If not, then the word
is not a palindrome.
** Parameters:  This function accepts a string value named word
and returns a boolean value indicating whether or not the word is
a palindrome.
*********************************************************************/
bool isPalindrome(string word) {
	word = convertToLowerCase(word);			// convert original word to all lowercase
	string reverse;

	if (word.length() == 1) {
		return true;
	}

	reverse = reverseWord(word);				// reverse the word; reverse will also be lowercase since
												// it is being reversed from lowercase version of word
	return word == reverse;						// return boolean value indicating if word equals reverse;
}												// that is, indicate if it is a palindrome