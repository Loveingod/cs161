/*********************************************************************
** Author:  Marc Clinedinst
** Date:  14 January 2015
** Description:  This program calculates the total sales generated
from the sales of three different types of tickets sold for a
baseball game.  Morespecifically, there are three different types of
tickets, each of which carries a different price:  Class A ($15),
Class B ($12), and Class C ($9).  The program asks the end user
to input the number of each type of ticket sold.  The program
then calculates the sales generated from each type of ticket as well
as the total sales from all tickets.  Finally, the program outputs
each of the sales values to the user in currency format.
*********************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	/*
		The cost of each type of ticket will not change during a single
		program run, so we declare these as constants.  This way, if
		the cost for a particular ticket changes, we need only change it
		in a single place.
	*/
	const double CLASS_A_TICKET_COST = 15.00,
				 CLASS_B_TICKET_COST = 12.00,
				 CLASS_C_TICKET_COST =  9.00;
	int classATicketsSold,
	    classBTicketsSold,
	    classCTicketsSold;
	double classATicketSales,
		   classBTicketSales,
		   classCTicketSales,
		   totalTicketSales;

	cout << "This program calculates the total amount of money earned" << endl;
	cout << "from sales of different types of tickets for a baseball" << endl;
	cout << "game." << endl << endl;;

    cout << fixed << showpoint << setprecision(2);  // This will cause numbers to be in currency format.
	cout << "The prices for each type of ticket is listed below:" << endl;
	cout << "Class A Tickets: $" << CLASS_A_TICKET_COST << " per ticket" << endl;
	cout << "Class B Tickets: $" << CLASS_B_TICKET_COST << " per ticket" << endl; 
	cout << "Class C Tickets: $" << CLASS_C_TICKET_COST << " per ticket" << endl;
	cout << endl;

	cout << "Enter the number of Class A Tickets purchased:\n> ";
	cin >> classATicketsSold;
	cout << "Enter the number of Class B Tickets purchased:\n> ";
	cin >> classBTicketsSold;
	cout << "Enter the number of Class C Tickets purchased:\n> ";
	cin >> classCTicketsSold;

	/*
		Below, we compute the sales for each type of ticket, as well as the total sales
		generated for all ticket types.
	*/
	classATicketSales = classATicketsSold * CLASS_A_TICKET_COST;
	classBTicketSales = classBTicketsSold * CLASS_B_TICKET_COST;
	classCTicketSales = classCTicketsSold * CLASS_C_TICKET_COST;
	totalTicketSales = classATicketSales + classBTicketSales + classCTicketSales;

	/*
		Below, we output the sales for each type of ticket and the total sales for all
		ticket types.  The currency formatting caries over from the use of fixed,
		showpoint, and setprecision above.
	*/
	cout << endl;
	cout << "----------Ticket Sales---------" << endl;
	cout << "Class A Ticket Sales: $" << classATicketSales << endl;
	cout << "Class B Ticket Sales: $" << classBTicketSales << endl;
	cout << "Class C Ticket Sales: $" << classCTicketSales << endl;
	cout << "Total Ticket Sales:   $" << totalTicketSales << endl;

	return 0;
}