//--------------------------------
// COMP 472
// Ganji-Ho
// Vince Abruzzese (26448585)
// John Di Girolamo (26202918)
// Coordinate.h
//--------------------------------

#ifndef COORDINATE_H
#define COORDINATE_H

int const BOARD_SIZE = 8;
int const MAX_AVAILABLE_MOVES = (BOARD_SIZE - 1) * BOARD_SIZE;
char const AVAILABLE = '.';
char const PLAYER_ONE = 'O';
char const PLAYER_TWO = 'X';

//The Coordinate struct will be used for each entry on the board
class Coordinate
{
public:

	//constructors
	Coordinate();
	Coordinate(Coordinate &copy);
	virtual ~Coordinate(){}

	//accessors
	int getX();
	int getY();
	char getValue();
	int getMinimax();

	//mutators
	void setX(int x);
	void setY(int y);
	void setValue(char value);
	void setMinimax(int minimax_value);

private:
	int x;
	int y;
	char value;
	int minimax_value; //used for minimax search
};

Coordinate string_to_coordinate(char* coordinate);

#endif COORDINATE_H