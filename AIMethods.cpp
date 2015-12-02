#include "AIMethods.h"
#include "HeuristicMethods.h"
#include <iostream>
#include "UserMethods.h"
#include "ValidityMethods.h"
#include <algorithm>
#include <ctime>

using namespace std;

void AI_turn(Board &board)
{
	int alpha = std::numeric_limits<int>::min();
	int beta = std::numeric_limits<int>::max();

	std::clock_t begin_time = std::clock();
	Coordinate best_move = minimax(board, DEPTH, alpha, beta, board.getPlayerTurn());
	double time_taken = float(clock() - begin_time) / CLOCKS_PER_SEC;
	Coordinate second = Coordinate(best_move);
	
	if (board.getPlayerTurn() == 1)
	{
		int x = second.getX();
		second.setX(x + 1);
	}
	else
	{
		int y = second.getY();
		second.setY(y + 1);
	}
	board.executeMove(best_move);

	system("CLS");
	board.displayBoard();

	display_AI_move(best_move, second);
	std::cout << "Time taken: " << time_taken;

	cout << endl << endl;
}

void display_AI_move(Coordinate first, Coordinate second)
{
	cout << "\nAI Input:" << endl;
	cout << "-----------" << endl;
	cout << "x1: " << first.getX() + 1;
	cout << " y1: " << first.getY() + 1;
	cout << "\nx2: " << second.getX() + 1;
	cout << " y2: " << second.getY() + 1 << endl;
}

void display_heuristic_values(int(&h_values)[BOARD_SIZE][BOARD_SIZE])
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
		{
			int val = h_values[i][j];

			if (val > -100 && val < 100)
			{
				cout << val << "  ";
			}
			else
			{
				cout << "." << "  ";
			}
		}

		cout << endl;
	}
}

Coordinate minimax(Board &board, int depth, int alpha, int beta, bool maximizingPlayer)
{
	//make a copy of the board
	Board copy = Board(board);
	Coordinate** tempBoard = copy.getBoard();

	//keep track of best value
	Coordinate best;

	if (depth == 0 || game_over(copy))
	{
		best.setMinimax(calculate_heuristic(copy));
		return best;
	}
	//max
	if (maximizingPlayer)
	{
		best.setMinimax(std::numeric_limits<int>::min());
		for (int i = 0; i < BOARD_SIZE; ++i)
		{
			for (int j = 0; j < BOARD_SIZE - 1; ++j)
			{
				if (tempBoard[i][j].getValue() == AVAILABLE && tempBoard[i][j + 1].getValue() == AVAILABLE) //check if valid
				{
					//test how good this move is
					tempBoard[i][j].setValue(PLAYER_TWO);
					tempBoard[i][j + 1].setValue(PLAYER_TWO);
					Coordinate temp = minimax(copy, depth - 1, alpha, beta, false);

					if (temp.getMinimax() > best.getMinimax())
					{
						best = Coordinate(temp);
						best.setX(j);
						best.setY(i);
					}
					tempBoard[i][j].setValue(AVAILABLE);
					tempBoard[i][j + 1].setValue(AVAILABLE);
					//remove the move
					
					alpha = max(alpha, best.getMinimax());
					if (beta <= alpha)
						break;
				}
			}
		}
		return best;
	}
	//min
	else
	{
		best.setMinimax(std::numeric_limits<int>::max());
		for (int i = 0; i < BOARD_SIZE; ++i)
		{
			for (int j = 0; j < BOARD_SIZE - 1; ++j)
			{
				if (tempBoard[j][i].getValue() == AVAILABLE && tempBoard[j + 1][i].getValue() == AVAILABLE) //check if valid
				{
					//test how good this move is
					tempBoard[j][i].setValue(PLAYER_ONE);
					tempBoard[j + 1][i].setValue(PLAYER_ONE);
					Coordinate temp = minimax(copy, depth - 1, alpha, beta, true);

					if (temp.getMinimax() < best.getMinimax())
					{
						best = Coordinate(temp);
						best.setX(i);
						best.setY(j);
					}
					tempBoard[j][i].setValue(AVAILABLE);
					tempBoard[j + 1][i].setValue(AVAILABLE);
					//remove the move

					beta = min(beta, best.getMinimax());
					if (beta <= alpha)
						break;
				}
			}
		}
		return best;
	}
}

void AI_game(Board &board, int ai_turn)
{
	AI_PLAYER = ai_turn;
	
	board.displayBoard();

	while (!game_over(board))
	{
		if (board.getPlayerTurn() != AI_PLAYER)
		{
			cout << "You have " << calculate_num_of_moves(board, "min") << " available moves!" << endl;
			cout << "The AI has " << calculate_num_of_moves(board, "max") << " available moves!" << endl;
			human_turn(board);
		}
		else
			AI_turn(board);

		board.changePlayerTurn();
	}

	if (board.getPlayerTurn() != AI_PLAYER) //if its your turn at this point, you lose
		cout << "\nAI Wins!" << endl;
	else
		cout << "\nYou win the game!" << endl;
}