#include "HeuristicMethods.h"

int calculate_num_of_moves(Board board, string type)
{
	int heuristic_value = MAX_AVAILABLE_MOVES;
	Coordinate** temp = board.getBoard();

	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE - 1; ++j)
		{
			if ((type == "max" && (temp[i][j].getValue() != AVAILABLE || temp[i][j + 1].getValue() != AVAILABLE)) //calculate if max
			 || (type == "min" && (temp[j][i].getValue() != AVAILABLE || temp[j + 1][i].getValue() != AVAILABLE))) //calculate if min
				--heuristic_value; //if one of the spots is unavailable, decrement
		}
	}
	return heuristic_value;
}

//min-max is simply calculated by available moves of max subtracted by available moves for min
int calculate_heuristic(Board board)
{
	return (calculate_num_of_moves(board, "max") - calculate_num_of_moves(board, "min"));
}