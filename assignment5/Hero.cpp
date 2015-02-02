/*********************************************************************
** Author:  Marc Clinedinst
** Date:  1 February 2015
** Description:  This program simulates a battle between the user of
the program and an RPG Hero.  The user is asked to provide the
following attributes for the Hero:
		* strength
		* hit points
		* speed
		* money
The program then allows the user to enter amounts of damage taken by
the Hero until the Hero is dead.
*********************************************************************/
#include <iostream>
#include "Hero.hpp"

using namespace std;

/*********************************************************************
					"Helper" Function Prototypes
*********************************************************************/
void displayProgramDescription();						// shows description of program to user at beginning of program
int getUserInput(string inputDescription);				// general function for getting and validating input

/*********************************************************************
					Hero Class Method Implementations

** Description:  This default constructor is used when no values are
provided as arguments to the constructor.  It sets the values of all
private member variables to 1.
** Parameters:  This constructor takes  no parameters.
*********************************************************************/
Hero::Hero() {
	setStrength(1);
	setHitPoints(1);
	setSpeed(1);
	setMoney(1);
}

/*********************************************************************
** Description:  This constructor is used when values for strength,
hit points, speed, and money are provided by the programmer when creating
a new Hero object.  This function uses the setStrength, setHitPoints,
setSpeed, and setMoney methods to set the values for the private 
member variables using the correct values.
** Parameters:  This constructor takes integer values representing the
strength, hit points, speed, and money of a Hero.
*********************************************************************/
Hero::Hero(int str, int hp, int sp, int gold) {
	setStrength(str);
	setHitPoints(hp);
	setSpeed(sp);
	setMoney(gold);
}

/*********************************************************************
** Description:  This method sets the value of strength, so long as
the argument provided is non-negative.  If the value is negative, an
error message is displayed and strength is set to 0.
** Parameters: This method takes an integer value representing the
strength of the Hero.
*********************************************************************/
void Hero::setStrength(int str) {
	if (str < 0) {
		cout << "Strength must be non-negative.  Defaulting to 0." << endl;
		strength = 0;
	} else {
		strength = str;
	}
}

/*********************************************************************
** Description:  This method returns the amount of strength the Hero
has.
** Parameters: This method takes no arguments.
*********************************************************************/
int Hero::getStrength() {
	return strength;
}

/*********************************************************************
** Description:  This method sets the value of hitPoints, so long as
the argument provided is non-negative.  If the value is negative, an
error message is displayed and hitPoints is set to 0.
** Parameters: This method takes an integer value representing the
hitPoints of the Hero.
*********************************************************************/
void Hero::setHitPoints(int hp) {
	if (hp < 0) {
		cout << "Hit points must be non-negative. Defaulting to 0." << endl;
		hitPoints = 0;
	} else {
		hitPoints = hp;
	}
}

/*********************************************************************
** Description:  This method returns the amount of hit points the Hero
has.
** Parameters: This method takes no arguments.
*********************************************************************/
int Hero::getHitPoints() {
	return hitPoints;
}

/*********************************************************************
** Description:  This method sets the value of speed, so long as
the argument provided is non-negative.  If the value is negative, an
error message is displayed and speed is set to 0.
** Parameters: This method takes an integer value representing the
speed of the Hero.
*********************************************************************/
void Hero::setSpeed(int sp) {
	if (sp < 0) {
		cout << "Speed must be non-negative. Defaulting to 0." << endl;
		speed = 0;
	} else{
		speed = sp;
	}
}

/*********************************************************************
** Description:  This method returns the amount of speed the Hero has.
** Parameters: This method takes no arguments.
*********************************************************************/
int Hero::getSpeed() {
	return speed;
}

/*********************************************************************
** Description:  This method sets the value of money, so long as
the argument provided is non-negative.  If the value is negative, an
error message is displayed and speed is set to 0.
** Parameters: This method takes an integer value representing the
speed of the Hero.
*********************************************************************/
void Hero::setMoney(int gold) {
	if (gold < 0) {
		cout << "Money must be non-negative. Defaulting to 0." << endl;
		money = 0;
	} else {
		money = gold;
	}
}

/*********************************************************************
** Description:  This method returns the amount of money the Hero has.
** Parameters: This method takes no arguments.
*********************************************************************/
int Hero::getMoney() {
	return money;
}

/*********************************************************************
** Description:  This method takes an integer value representing the
amount of damage the Hero takes from an attack and subtracts that
amount from the Hero's current health.  The method then indicates
whether the hero's health is greater than 0 (i.e., whether the hero
is still alive).
** Parameters: This method takes an integer value representing the
damage done to a Hero.
*********************************************************************/
bool Hero::takeDamage(int damage) {
	setHitPoints(hitPoints - damage);
	return hitPoints > 0;
}

/*********************************************************************
					"Helper" Function Implementations

** Description:  This function prints a description of the program to
the user when the program is first run.
** Parameters:  This function takes no parameters.
*********************************************************************/
void displayProgramDescription() {
	cout << "This program simulates a battle between the user" << endl;
	cout << "and an action adventure hero.  The program will" << endl;
	cout << "prompt the user to enter stats for the user. The" << endl;
	cout << "program then allows the user damage the hero until" << endl;
	cout << "the hero is dead." << endl << endl;
	cout << "Enter the values for the hero below." << endl;
}

/*********************************************************************
** Description:  This function generalizes the process of collecting
and validating input in the program.  All values colllected as input
must non-negative.  This function takes a description of the input, asks
the user for that input, validates the input, and then returns the
input once a valid input has been given.
** Parameters:  This function takes a string description of the 
required input.  It returns a validated integer value.
*********************************************************************/
int getUserInput(string inputDescription) {
	int value;
	do {
		cout << endl;
		cout << "Enter " << inputDescription << " as an integer:\n> ";
		cin >> value;
		if (value < 0) {
			cout << "Error:  value must be greater than 0." << endl << endl;;
		}
	} while (value < 0);
	return value;
}

/*********************************************************************
** Description:  This function outputs the strength, hit points,
speed, and money of a hero.  It uses the public member functions
getStrength, getHitPoints, getSpeed, and getMoney to accomplish
this.
** Parameters:  This function takes a Hero object.
*********************************************************************/
void showHeroStats(Hero hero) {
	cout << "Hero Strength  : " << hero.getStrength() << endl;
	cout << "Hero Hit Points: " << hero.getHitPoints() << endl;
	cout << "Hero Speed     : " << hero.getSpeed() << endl;
	cout << "Hero Money     : " << hero.getMoney() << endl;
}

int main() {
	Hero hero;

	displayProgramDescription();

	hero.setStrength(getUserInput("strength"));
	hero.setHitPoints(getUserInput("hit points"));
	hero.setSpeed(getUserInput("speed"));
	hero.setMoney(getUserInput("money"));

	while (hero.getHitPoints() > 0) {
		cout << endl;
		showHeroStats(hero);

		if (hero.takeDamage(getUserInput("damage"))) {
			cout << "You hit the hero! His new stats are below." << endl << endl;
		} else {
			cout << "You killed the hero!" << endl << endl;
		}
	}

	cout << "Hero's final stats: " << endl << endl;
	showHeroStats(hero);

	return 0;
}