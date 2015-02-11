/*********************************************************************
** Author:  Marc Clinedinst
** Date:  15 February 2015
** Description:  This file contains the Supplies class specification. 
The Supplies class represents an inventory of parts needed to produce
certain products.  This class specification provides the names of the 
private member variables as well as the public member functions 
associated with the class.  Together, the variables and functions 
represent the data associated with a LineSegment and the types of 
actions that can be performed with this data type.
*********************************************************************/
#ifndef SUPPLIES_HPP
#define SUPPLIES_HPP

class Supplies {
	private:
		int numThingamajigs;
		int numWatchamacallits;
		int numFramistats;
	public:
		Supplies();
		Supplies(int, int, int);
		void setNumThingamajigs(int);
		void setNumWatchamacallits(int);
		void setNumFramistats(int);
		void printPartsOrder();
		void produceThing1(int);
		void produceThing2(int);
};

#endif