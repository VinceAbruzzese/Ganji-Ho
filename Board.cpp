#include "Board.h"
#include <iostream>

using namespace std;

//default constructor
Board::Board()
{
	board_display = new Coordinate*[BOARD_SIZE];

	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		board_display[i] = new Coordinate[BOARD_SIZE];

		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			board_display[i][j].setValue(AVAILABLE);
			board_display[i][j].setX(j);
			board_display[i][j].setY(i);
		}
	}
	//player 1 starts
	player_turn = 0;
}

//copy constructor
Board::Board(Board &copy)
{
	Coordinate** temp = copy.getBoard();

	board_display = new Coordinate*[BOARD_SIZE];

	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		board_display[i] = new Coordinate[BOARD_SIZE];

		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			board_display[i][j].setValue(temp[i][j].getValue());
			board_display[i][j].setX(j);
			board_display[i][j].setY(i);
		}
	}
	player_turn = copy.getPlayerTurn();
}

//destructor
Board::~Board()
{
	for (int i = 0; i < BOARD_SIZE; ++i)
		delete [] board_display[i];
	
	delete [] board_display;
}

//accessors
Coordinate** Board::getBoard()
{
	return board_display;
}

int Board::getPlayerTurn()
{
	return player_turn;
}

void Board::setPlayerTurn(int player_turn)
{
	this->player_turn = player_turn;
}

//board methods
void Board::displayBoard()
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		cout << "  " << (i + 1);
	}

	cout << endl;

	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		char row = 65 + i;

		cout << row << " ";

		for (int j = 0; j < BOARD_SIZE; j++)
			cout << board_display[i][j].getValue() << "  ";
		cout << endl;
	}
}

void Board::executeMove(Coordinate move)
{
	//at this point, the coordinate is valid

	if (player_turn == 0)
	{
		board_display[move.getY()][move.getX()].setValue(PLAYER_ONE);
		board_display[move.getY() + 1][move.getX()].setValue(PLAYER_ONE);
	}
	else
	{
		board_display[move.getY()][move.getX()].setValue(PLAYER_TWO);
		board_display[move.getY()][move.getX() + 1].setValue(PLAYER_TWO);
	}
}

//other
void Board::changePlayerTurn()
{
	player_turn = (player_turn + 1) % 2;
}