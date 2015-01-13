/*********************************************************************
** Author:  Marc Clinedinst
** Date:  9 January 2015
** Description:   
*********************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	double loanAmount,
		   monthlyInterestRate,
		   numPayments,
		   monthlyPayment,
		   amountPaidBack,
		   interestPaid;

	cout << "This program calculates the monthly payments of a loan when given" << endl;
	cout << "the amount of the loan, the number of payments, and the monthly" << endl;
	cout << "interest rate." << endl << endl;

	cout << "Enter the loan amount:\n> ";
	cin >> loanAmount;

	cout << "Enter the monthly interest rate as a decimal:\n> ";
	cin >> monthlyInterestRate;

	cout << "Enter the number of payments:\n> ";
	cin >> numPayments;	

	monthlyPayment = (monthlyInterestRate * pow(1 + monthlyInterestRate, numPayments)) / (pow(1 + monthlyInterestRate, numPayments) - 1) * loanAmount;
	amountPaidBack = monthlyPayment * numPayments;
	interestPaid = amountPaidBack - loanAmount;

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