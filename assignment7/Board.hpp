/*********************************************************************
** Author:  Marc Clinedinst
** Date:  22 February 2015
** Description:  This file contains the Board class specification. A
Board object represents a three by three board that is used to play
TicTacToe.  Players take turns placing their game piece--either an
X or an O--on the board.  The first player to get three in a row wins
the game; if no player gets three in a row before all spaces have been
occupied, then the game is considered a draw.  The Board class
contains an array representing the board itself, as well as functions
for making a move, returning the current state of the game, and for 
printing the board to the user.
*********************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

enum GameState {X_WINS, O_WINS, DRAW, IN_PROGRESS};			// used to indicate whether a player has won the game,
															// whether a draw has been reached, or if game is in
															// progress

class Board {
	private:
		char grid[3][3];									// stores current state of game on 3x3 board

	public:
		Board();											// default constructor--creates empty board
		bool makeMove(int, int, char);						// makes move as long as space is not occupied
		GameState gameState();								// indicates current state of game to players
		void print();										// prints board with current movies to user
};

#endif