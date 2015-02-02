/*********************************************************************
** Author:  Marc Clinedinst
** Date:  1 February 2015
** Description:  This file contains the DiceCup class specification. 
The DiceCup simulates a cup of dice, which can be "rolled"  to produce
a random value.  Users of the DiceCup class can specify the number of
dice within the cup, as well as the number of faces on each die. 
This file contains the names of the member variables and member 
functions for the DiceCup class.  This file does not contain any of the 
definitions for the member function, as these will be defined 
separately in the DiceCup.cpp file which will use this specification.
*********************************************************************/
#ifndef DICECUP_HPP
#define DICECUP_HPP

class DiceCup {
	private:
		int numDice;				// the number of dice in the cup
		int numFaces;				// the number of faces each die has

	public:
		DiceCup();					// default constructor which creates a cup with a single coin
		DiceCup(int, int);			// used to create DiceCup with specific amount of dice with specified faces
		void setNumDice(int);		// used to specify number of dice in cup
		void setNumFaces(int);		// used to specify number of faces on each die
		int rollDice();				// used to simulate a roll of the dice
};
#endif