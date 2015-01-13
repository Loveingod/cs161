/*********************************************************************
** Author:  Marc Clinedinst
** Date:  9 January 2015
** Description: 
*********************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
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

    cout << fixed << showpoint << setprecision(2);
	cout << "This program calculates the total amount of money earned" << endl;
	cout << "from sales of different types of tickets." << endl << endl;;

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

	classATicketSales = classATicketsSold * CLASS_A_TICKET_COST;
	classBTicketSales = classBTicketsSold * CLASS_B_TICKET_COST;
	classCTicketSales = classCTicketsSold * CLASS_C_TICKET_COST;
	totalTicketSales = classATicketSales + classBTicketSales + classCTicketSales;

	cout << endl;
	cout << "----------Ticket Sales---------" << endl;
	cout << "Class A Ticket Sales: $" << classATicketSales << endl;
	cout << "Class B Ticket Sales: $" << classBTicketSales << endl;
	cout << "Class C Ticket Sales: $" << classCTicketSales << endl;
	cout << "Total Ticket Sales:   $" << totalTicketSales << endl;

	return 0;
}