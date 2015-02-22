/*********************************************************************
** Author:  Marc Clinedinst
** Date:  22 February 2015
** Description:  This file contains the implementation details for
the Board class.  Specifically, it contains definitions of all of the
public member functions.  These functions create a board object,
make a move on the board, return the current state of the game, and
print the state of the board.
*********************************************************************/
#include <iostream>
#include "Board.hpp"

using namespace std;

/*********************************************************************
			Shopping Cart Class Method Implementations

** Description:  This is the default constructor for the Board class. It
populates a three by three array with the null terminator--'\0'--for
each element of the array.
** Parameters:  This function takes no parameters.
*********************************************************************/
Board::Board() {
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			grid[row][column] = '\0';
		}
	}
}

/*********************************************************************
			Shopping Cart Class Method Implementations

** Description:  This function makes a move in a game of TicTacToe.
More specifically, the function accepts the x and y coordinates of a
move in TicTacToe and verifies that the move is valid (i.e. that the 
space is not already occupied).  If the space is empty, the function 
places the game piece and returns true.  Otherwise, the function
returns false.
** Parameters:  This function accepts the x and y coordinates for a
move in the game of TicTacToe.  It returns true or false, indicating
whether or not the move was valid.
*********************************************************************/
bool Board::makeMove(int x, int y, char player) {
	bool moveMade = false;

	if (((x >= 0) && (x <= 2)) && ((y >= 0) && (y <= 2))) {		
		if (grid[x][y] == '\0') {
			grid[x][y] = player;
			moveMade = true;
		} else {
			cout << "Error: That square is already taken." << endl;
		}
	} else {
		cout << "Error: Invalid coordinates." << endl;
	}

	return moveMade;
}

/*********************************************************************
** Description:  This function checks the current state of the board
and returns whether the game has been won, whether a draw has been
reached, or whether the game is in progress.  Each of these conditions
will be described in further detail below.
** Parameters:  This function takes no parameters.
*********************************************************************/
GameState Board::gameState() {
	/*
		Looks for winning condition of following pattern:
		###
		...
		...

	*/
	if ((grid[0][0] != '\0') && ((grid[0][0] == grid[0][1]) && (grid[0][1] == grid[0][2]))) {
		if (grid[0][0] == 'X') {
			return X_WINS;
		} else {
			return O_WINS;
		}
	/*
		Looks for winning condition of following pattern:
		...
		###
		...

	*/
	} else if ((grid[1][0] != '\0') && ((grid[1][0] == grid[1][1]) && (grid[1][1] == grid[1][2]))) {
		if (grid[1][0] == 'X') {
			return X_WINS;
		} else {
			return O_WINS;
		}
	/*
		Looks for winning condition of following pattern:
		...
		...
		###

	*/
	} else if ((grid[2][0] != '\0') && ((grid[2][0] == grid[2][1]) && (grid[2][1] == grid[2][2]))) {
		if (grid[2][0] == 'X') {
			return X_WINS;
		} else {
			return O_WINS;
		}
	/*
		Looks for winning condition of following pattern:
		#..
		#..
		#..

	*/
	}  else if ((grid[0][0] != '\0') && ((grid[0][0] == grid[1][0]) && (grid[1][0] == grid[2][0]))) {
		if (grid[1][0] == 'X') {
			return X_WINS;
		} else {
			return O_WINS;
		}
	/*
		Looks for winning condition of following pattern:
		.#.
		.#.
		.#.

	*/
	} else if ((grid[0][1] != '\0') && ((grid[0][1] == grid[1][1]) && (grid[1][1] == grid[2][1]))) {
		if (grid[0][1] == 'X') {
			return X_WINS;
		} else {
			return O_WINS;
		}
	/*
		Looks for winning condition of following pattern:
		..#
		..#
		..#

	*/
	} else if ((grid[0][2] != '\0') && ((grid[0][2] == grid[1][2]) && (grid[1][2] == grid[2][2]))) {
		if (grid[0][2] == 'X') {
			return X_WINS;
		} else {
			return O_WINS;
		}
	/*
		Looks for winning condition of following pattern:
		#..
		.#.
		..#

	*/
	} else if ((grid[0][0] != '\0') && ((grid[0][0] == grid[1][1]) && (grid[1][1] == grid[2][2]))) {
		if (grid[0][0] == 'X') {
			return X_WINS;
		} else {
			return O_WINS;
		}
	/*
		Looks for winning condition of following pattern:
		..#
		.#.
		#..

	*/
	} else if ((grid[2][0] != '\0') && ((grid[2][0] == grid[1][1]) && (grid[1][1] == grid[0][2]))) {
		if (grid[2][0] == 'X') {
			return X_WINS;
		} else {
			return O_WINS;
		}
	} else {
		for (int row = 0; row < 3; row++) {						// checks to see that there are still
			for (int column = 0; column < 3; column++) {		// empty squares; if so, game still in
				if (grid[row][column] == '\0') {				// progress
					return IN_PROGRESS;
				}
			}
		}
		return DRAW;											// all squares filled with no winner--draw
	}
}

void Board::print() {
	cout << "  0 1 2" << endl;									// prints out current version of board, with
	for (int row = 0; row < 3; row++) {							// game pieces filled in for the game's current
		cout << row << " ";										// state
		for (int column = 0; column < 3; column++) {
			if (grid[row][column] == '\0') {
				cout << ". ";
			} else {
				cout << grid[row][column] << " ";
			}
		}
		cout << endl;
	}
}