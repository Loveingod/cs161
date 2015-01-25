/*********************************************************************
** Author:  Marc Clinedinst
** Date:  14 January 2015
** Description:  This program calculates the monthly payment, 
the amount paid back, and the interest paid on a loan when given the
original loan amount, the monthly interest payment, and the number
of monthly payments payments.  Since we have not yet covered the
programming constructs required to deal with invalid input (i.e.
conditional statements and looping constructs), this program will 
not validate inputs by the end user.  Because of this, certain input
values--for instance, negative numbers for any of the input values--
may cause unexpected behavior.  Although these sorts of behaviors
may occur in the program, they have been addressed in both the
design document and the reflection document that goes along with
this assignment.
*********************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	double loanAmount,
		   monthlyInterestRate,
		   monthlyPayment,
		   amountPaidBack,
		   interestPaid;
	int numPayments;				// I chose an integer data type for this particular variable, because in my
	                                // experience, my auto lender is not happy when I make fractions of a payment. :(


	/*
		The lines that follow below are mostly self-documenting but the long and short
		of it is that we're collecting the loan amount, monthly interest rate, and
		number of payments so that we can determine the monthly interest payment.
	*/
	cout << "This program calculates the monthly payments of a loan when given" << endl;
	cout << "the amount of the loan, the number of payments, and the monthly" << endl;
	cout << "interest rate." << endl << endl;

	cout << "Enter the loan amount:\n> ";
	cin >> loanAmount;

	cout << "Enter the monthly interest rate as a decimal:\n> ";
	cin >> monthlyInterestRate;

	cout << "Enter the number of payments:\n> ";
	cin >> numPayments;	

	/*
		The line that immediately  follows uses the formula provided in the project 
		description to determine the monthly payment for the loan, given the loan amount,
		monthly interest rate, and number of payments.  The line itself is pretty long 
		(and admittedly longer than) I would like, but I wanted to use descriptive 
		variable names. Because of this, amountPaidBack and interestPaid are self-
		documeneting.
	*/
	monthlyPayment = (monthlyInterestRate * pow(1 + monthlyInterestRate, numPayments)) / (pow(1 + monthlyInterestRate, numPayments) - 1) * loanAmount;
	amountPaidBack = monthlyPayment * numPayments;
	interestPaid = amountPaidBack - loanAmount;

	/*
		Below, we make use of the fixed, showpoint, and setprecision assets from the
		iomanip file to output data with two decimal points.  We also ensure that 
		all of the data is properly aligned.
	*/
	cout << fixed << showpoint << setprecision(2);
	cout << endl;
	cout << "---------------Loan Details---------------" << endl;
	cout << "Loan Amount               : $" << loanAmount << endl;
	cout << "Monthly Interest Rate     :  " << (monthlyInterestRate * 100) << "%" << endl;
	cout << "Monthly Payment           : $" << monthlyPayment << endl;
	cout << "Amount Paid Back          : $" << amountPaidBack << endl;
	cout << "Interest Paid             : $" << interestPaid << endl;

	return 0;
}