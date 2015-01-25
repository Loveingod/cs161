/*********************************************************************
** Author:  Marc Clinedinst
** Date:  25 January 2015
** Description:  This program prompts prompts the user to enter three
integers.  The program then outputs the numbers to the user in the
order in which they were originally entered.  The program then sorts
the integers into ascending order and outputs the integers to the 
user in the sorted order.  This program relies heaily on functions,
particularly those that use reference parameters.
*********************************************************************/
#include <iostream>
#include <string>

using namespace std;

void smallSort(int &num1, int &num2, int &num3);
void swap(int &value1, int &value2);
void showOrder(string description, int num1, int num2, int num3);
void getInts(int &num1, int &num2, int &num3);

int main() {
	int num1,
		num2,
		num3;

	getInts(num1, num2, num3);							// Get and store values for num1, num2, and num3
	showOrder("Original Order:", num1, num2, num3);     // Show current order of num1, num2, and num3
	smallSort(num1, num2, num3);						// Sort values into ascending order
	showOrder("Sorted Order:", num1, num2, num3);		// Show sorted order of num1, num2, and num3

	return 0;
}


/*********************************************************************
** Description:  This function is rather simple.  It merely passes
in three reference parameters, asks the user to input three integers,
and stores the user's input into those reference parameters.  Since
this function uses reference parameters, this will alter the arguments
passed into these parameters.
** Parameters:  This function has three integer reference parameters--
num1, num2 and num3.  Since this is a void function, there is no
return value.  The function updates the arguments passed to it since
it uses reference parameters.
*********************************************************************/
void getInts(int &num1, int &num2, int &num3) {
	cout << "Enter three integers:\n> ";
	cin >> num1 >> num2 >> num3;
}

/*********************************************************************
** Description:  This is a "helper" function that will be put to great
use within the smallSort function.  Specifically, the swap function
takes two reference parameters and swaps the value of arguments passed
to the function.  For instance, if a = 1 and b = 2 and these variables
are passed to the function, then when the function terminates, a = 2
and b = 1.
** Parameters:    
*********************************************************************/
void swap(int &value1, int &value2) {
	int temp = value1;
	value1 = value2;
	value2 = temp;
}

/*********************************************************************
** Description: This is the "meat" of this program.  In other words,
this function performs the main purpose of the program, which is that
of sorting three integers into ascending order.  For example, if the
integers 3, 1, and 2 were passed to this function in this order, they
would be ordered as 1, 2, and 3 by the completion of the function.
This function makes use of the swap function described earlier to
swap the values in two difference reference variables.  
** Parameters:  This function takes three integer reference parameters
--num1, num2, and num3.  Since these are reference parameters, this
function will alter the values of the arguments passed to the function.
Although this is a void function and there is therefore no return
value, this function makes use of the return statement at several
parts to exit the function once the function has determined the
appropriate swaps that need to occur.
*********************************************************************/
void smallSort(int &num1, int &num2, int &num3) {
	int temp;
	if ( (num1 <= num2) && (num2 <= num3) ) {  // If the numbers are already sorted, do nothing.
		return;
	}
	if ( (num1 <= num3) && (num3 <= num2) ) {  // If the numbers are in num1 <= num3 <= num2,
		swap(num2, num3);                      // swap num2 and num3 to get num1 <= num2 <= num3.
		return;
	}
	if ( (num2 <= num1) && (num1 <= num3) ) {  // If the numbers are in num2 <= num1 <= num3,
		swap(num1, num2);                      // swap num1 and num2 to get num1 <= num2 <= num3.
		return;
	}
	if ( (num2 <= num3) && (num3 <= num1) ) {  // If the numbers are in num2 <= num3 <= num1,
		swap(num1, num2);                      // swap num1 and num2 and then num2 and num3
		swap(num2, num3);                      // to get num1 <= num2 <= num3
		return;
	}
	if ( (num3 <= num1) && (num1 <= num2) ) {  // If the numbers are in num3 <= num1 <= num2,
		swap(num1, num3);					   // swap num1 and num3 and then num2 and num3
		swap(num2, num3);                      // to get num1 <= num2 <= num3
		return;
	}
	if ( (num3 <= num2) && (num2 <= num1) ) {   // If the numbers are in num3 <= num2 <= num1,
		swap(num1, num3);                       // swap num1 and num3 to get num1 <= num2 <= num2.
		return;
	}
}

/*********************************************************************
** Description:  This function prints out the current order of the
integers num1, num2, and num3.  There are two separate parts of the 
program where this action needs to occur, so this function assists
with creating a reusable function.
** Parameters:  This function requires a string discription parameter
and three integer parameters--num1, num2, and num3.  The function
then prints out the values in the following order:  num1, num2, num3.
Since this is a void function, there is no return value.
*********************************************************************/
void showOrder(string description, int num1, int num2, int num3) {
	cout << endl;
	cout << description << endl;
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;
}