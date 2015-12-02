#include "ValidityMethods.h"
#include <iostream>
#include <cmath>

using namespace std;

//Check if the first move is valid. To be valid the spot chosen and one of the neighbour values must be available
bool valid_move(Board board, Coordinate current_value)
{
	Coordinate** temp = board.getBoard();

	bool isFree = temp[current_value.getY()][current_value.getX()].getValue() != AVAILABLE,
		 inBounds = current_value.getX() < 0 || current_value.getX() > BOARD_SIZE - 1 || current_value.getY() < 0 || current_value.getY() > BOARD_SIZE - 1,
		 solo = false,
		 isOnEdge = false;

	if (isFree || inBounds) //check that current spot is free and in bounds
		return false;	

	if (board.getPlayerTurn() == 1) 
	{
		solo = temp[current_value.getY()][current_value.getX() + 1].getValue() != AVAILABLE;
		isOnEdge = current_value.getX() == 0 && temp[current_value.getY()][1].getValue() != AVAILABLE || current_value.getX() == BOARD_SIZE - 1 && temp[current_value.getY()][BOARD_SIZE - 2].getValue() != AVAILABLE;
	}
	else
	{		
		solo = temp[current_value.getY() + 1][current_value.getX()].getValue() != AVAILABLE;
		isOnEdge = current_value.getY() == 0 && temp[1][current_value.getX()].getValue() != AVAILABLE || current_value.getY() == BOARD_SIZE - 1 && temp[BOARD_SIZE - 2][current_value.getX()].getValue() != AVAILABLE;
	}

	if (solo || isOnEdge)
			return false; //check that one of left or right is open

	return true;
}

bool game_over(Board board)
{
	Coordinate** temp = board.getBoard();

	if (board.getPlayerTurn() == 1)
	{
		for (int i = 0; i < BOARD_SIZE; ++i)
		{
			for (int j = 0; j < BOARD_SIZE - 1; ++j)
			{
				if (temp[i][j].getValue() == AVAILABLE && temp[i][j + 1].getValue() == AVAILABLE)
					return false;
			}
		}
		return true;
	}
	else
	{
		for (int i = 0; i < BOARD_SIZE - 1; ++i)
		{
			for (int j = 0; j < BOARD_SIZE; ++j)
			{
				if (temp[i][j].getValue() == AVAILABLE && temp[i + 1][j].getValue() == AVAILABLE)
					return false;
			}
		}
		return true;
	}
}
