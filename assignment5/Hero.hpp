/*********************************************************************
** Author:  Marc Clinedinst
** Date:  1 February 2015
** Description:  This file contains the Hero class specification. A 
Hero represents the main character of an action adventure game, or a
role playing game.  The Hero will have player stats like hit points,
strength, speed, and money.  This class will also have mutator
functions for getting and setting these values.  There will also
be a function that allows the Hero to take damage. This file does 
not contain any of the definitions for the member function, as these 
will be defined separately in the Box.cpp file which will use this 
specification.
*********************************************************************/
#ifndef HERO_HPP
#define HERO_HPP

class Hero {
	private:
		int strength;
		int hitPoints;
		int speed;
		int money;

	public:
		Hero();
		Hero(int, int, int, int);
		void setStrength(int);
		int getStrength();
		void setHitPoints(int);
		int getHitPoints();
		void setSpeed(int);
		int getSpeed();
		void setMoney(int);
		int getMoney();
		bool takeDamage(int);
};

#endif