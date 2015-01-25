/*********************************************************************
** Author:  Marc Clinedinst
** Date:  24 January 2015
** Description:  This program reads a file named nums.txt containing 
an arbitrary number of double values separated by whitespace and 
computes the sum of these numbers.  The program then writes the sum
of these numbers to a file named sum.txt.  This program makes use
of both the iostream and fstream files to provide console and file
input and output.  The program also uses the if/else construct to 
make sure that there are no issues opening files. Finally, the
program uses a while loop to read in all of the numbers from the
input file.  Each of these techniques will be described in detail
in the sourc ecode below.
*********************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream inputFile;                 // In lines 21 and 22 we create ifstream and ofstream objects to
	ofstream outputFile;                // use to interact with input and output files
	double number,
		   total = 0;

	inputFile.open("nums.txt");         // Here, we attempt to open the files nums.txt

	cout << "Opening file nums.txt. . ." << endl << endl;

	if (!inputFile) {                   // Make sure that we can open the file.
		cout << "Error opening file nums.txt." << endl << endl;
	} else {
		cout << "Adding values to total." << endl;
		while (inputFile >> number) {                                    // As long as next line exists, read it.
			total += number;                                             // And add it to running total.
		}
		cout << endl;
		cout << "Closing nums.txt . . . " << endl << endl;
		inputFile.close();                                               // We are done with inputFile, so close it.
	}

	outputFile.open("sum.txt");  // Attempt to pen sum.txt

	cout << "Opening sum.txt . . ." << endl << endl;

	if (!outputFile) { // Make sure there are no issues opening sum.txt
		cout << "Error opening sum.txt." << endl << endl;
	} else {
		cout << "Writing result to sum.txt . . ." << endl << endl;               
		outputFile << "The sum of the values is " << total << "." << endl;  // Write result to sum.txt
		outputFile.close();                                                 // Close file since no longer needed.
		cout << "Closing sum.txt . . ." << endl << endl;
		cout << "Open sum.txt in a text editor to see result." << endl;     // Inform user where to read output.
	}

	return 0;
}