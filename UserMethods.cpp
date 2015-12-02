#include "UserMethods.h"
#include <iostream>
#include "ValidityMethods.h"
#include "HeuristicMethods.h"

using namespace std;

char* human_turn(Board &board)
{
	char *coordinate = new char[2];

	cout << "\nPlease enter your first coordinate: ";
	cin >> coordinate;				//Get Coordinate

	bool validMove = valid_move(board, string_to_coordinate(coordinate));
	
	while ((strlen(coordinate) < 1 && strlen(coordinate) > 4) || !validMove)		//If input is not 2 or 3 characters
	{
		//check that proper length is inserted 

		cout << "Your string input is invalid!" << endl;

		cout << "\nPlease enter your first coordinate: ";
		cin >> coordinate;

		validMove = valid_move(board, string_to_coordinate(coordinate));
	}
	board.executeMove(string_to_coordinate(coordinate));
	system("CLS");
	board.displayBoard();
	return coordinate;
}

void human_game(Board &board)
{
	board.displayBoard();

	//Game loop: while not game_over
	while (!game_over(board))
	{
		cout << "\nPlayer " << board.getPlayerTurn() + 1 << "\'s turn. ";

		if (board.getPlayerTurn() == 0)
			cout << "You have " << calculate_num_of_moves(board, "max") << " available moves!" << endl;
		else
			cout << "You have " << calculate_num_of_moves(board, "min") << " available moves!" << endl;

		human_turn(board);
		board.changePlayerTurn();
	}

	system("CLS");
	
	board.changePlayerTurn();
	cout << "\nPlayer " << board.getPlayerTurn() + 1 << " wins!" << endl;
}