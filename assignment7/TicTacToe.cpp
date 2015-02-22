#include <iostream>
#include <cctype>
#include "Board.hpp"
#include "TicTacToe.hpp"

using namespace std;

/*********************************************************************
				"Helper" Function Prototypes
*********************************************************************/
char getFirstPlayer();
void displayProgramDescription();

/*********************************************************************
			TicTacToe Class Method Implementations

** Description:  This is the default constructor, which creates a
TicTacToe game object.  This object consists of an empty three by
three board and initial player being set as 'X'.

function creates a TicTacToe game object, with an
empty board and 'X' as the initial player.  
** Parameters:  This function takes no parameters.
*********************************************************************/
TicTacToe::TicTacToe() {
	Board board;
	player = 'x';
}

/*********************************************************************
** Description:  This is another constructor, which is used when a
character representing the first player is passed to the constructor.
This function creates an empty three by three board, and sets the
first player to a programmer-provided character value.
** Parameters:  This function accepts a character value representing
the current player.
*********************************************************************/
TicTacToe::TicTacToe(char p) {
	Board board;
	player = p;
}

/*********************************************************************
** Description:  This function controls the flow of a TicTacToe game.
Specifically, it keeps track of the current player and makes moves
for the current player as long as neither of the players has won and
the game has not reached a draw.  When a player has won or a draw has
been reached, the game announces the winner or the draw state.
** Parameters:  This function accepts no parameters.
*********************************************************************/
void TicTacToe::play() {
	char player;											// represents current player
	int x, y;												// x and y coordinates for player move

	displayProgramDescription();							// displays helpful program description to user

	player = getFirstPlayer();								// gets character value for current player

	while (board.gameState() == IN_PROGRESS) {		// this loop repeats until the game state changes from being in
		cout << endl;								// progress to a player winning or the draw state being reached
		board.print();
		do {														// this loop repeats until a valid move is made by
			cout << endl;											// the player; once a valid move has been made, the
			cout << "Player " << player << " make your move:\n> ";	// move is recorded
			cin >> x >> y;
		} while (!board.makeMove(x, y, player));
		if (player == 'X') {										// this if/else statement switches to the next 
			player = 'O';											// player after a valid move has been made
		} else {
			player = 'X';
		}
	}

	cout << endl;		
	board.print();				// print final version of board before announcing game result
	cout << endl;

	if (board.gameState() == X_WINS) {					// this block of code announces the final game state--
		cout << "Player X wins!" << endl;				// either X or O wins, or the game results in a draw
	} else if (board.gameState() == O_WINS) {
		cout << "Player O wins!" << endl;
	} else {
		cout << "Draw!" << endl;
	}
}


/*********************************************************************
					"Helper" Function Definitions

** Description:  This function displays a description of the program
to the user, so that the user understands the purpose of the program.
** Parameters:  This function takes no parameters.
*********************************************************************/
void displayProgramDescription() {
	cout << "Welcome to Tic-Tac-Toe! Below, you will be prompted to enter" << endl;
	cout << "which player will go first (X or O), and then players will take" << endl;
	cout << "turns placing their game pieces on the three-by-three grid. The" << endl;
	cout << "first player to get three in a row wins! Otherwise, there will" << endl;
	cout << "be a draw. Have fun!" << endl << endl;
}

/*********************************************************************
					"Helper" Function Definitions

** Description:  This function gets and verifies a character value
representing the first player of a game of TicTacToe.  Valid
responses from the user include X, x, O, and o.  This function keeps
looping until one of these values is entered by the user.  Once such
a value is intered, the function returns this value to the part of
the program that called it.
** Parameters:  This function takes no parameters and returns a char
value representing the first player of a game of TicTacToe.
*********************************************************************/
char getFirstPlayer() {
	char player;

	do {
		cout << "Which player should go first, X or O?\n> ";
		cin >> player;
		cin.ignore();
		if ((toupper(player) != 'X') && (toupper(player) != 'O')) {
			cout << "Error:  player must be X or O." << endl << endl;
		}
	} while ((toupper(player) != 'X') && (toupper(player) != 'O'));

	return toupper(player);
}

int main() {
	TicTacToe game;				// create TicTacToe game object
	game.play();				// play game

	return 0;
}