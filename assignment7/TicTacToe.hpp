/*********************************************************************
** Author:  Marc Clinedinst
** Date:  22 February 2015
** Description:  This file contains the the TicTacToe class 
specification.  Specifically, this file contains the private member
variables and public member functions that make up a game of TicTacToe.
Such a game object has a board and a current player; it also has both
a default constructor and a constructor that accepts a value
representing the current player.  Finally, it has a function which
handles the main actions of playing the game.
*********************************************************************/
#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

class TicTacToe {
	private:
		Board board;			// a three by three playing board; each space is intially empty
		char player;			// represents the current player who needs to make a move

	public:
		TicTacToe();			// creates a three by three board and makes first player X
		TicTacToe(char);		// creates a three by three board and uses passed value to determine first player
		void play();			// controls the gameplay
};

#endif