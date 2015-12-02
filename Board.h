//--------------------------------
// COMP 472
// Ganji-Ho
// Vince Abruzzese (26448585)
// John Di Girolamo (26202918)
// Board.h
//--------------------------------

#ifndef BOARD_H
#define BOARD_H

#include "Coordinate.h"

class Board
{
public:

	//constructors & destructor
	Board();
	Board(Board &copy);
	virtual ~Board();

	//accessors
	Coordinate** getBoard();
	int getPlayerTurn();

	//mutators
	void setPlayerTurn(int player_turn);

	//board methods
	void displayBoard();
	void executeMove(Coordinate move);

	//other
	void changePlayerTurn();

private:
	Coordinate** board_display;
	int player_turn;
};

#endif