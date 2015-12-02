#include "MainMethods.h"
#include <iostream>
#include "UserMethods.h"
#include "AIMethods.h"

using namespace std;

void welcome_message()
{
	cout << "--------------------------------------------------------------------" << endl;
	cout << "- Welcome to Ganji-Ho!                                             -" << endl;
	cout << "--------------------------------------------------------------------" << endl;
	cout << "- Rules:                                                           -" << endl;
	cout << "- 1. Players take turns placing tokens on the board.               -" << endl;
	cout << "- 2. The player must place 2 tokens in consecutive cells per turn. -" << endl;
	cout << "- 3. The first player must place their tokens vertically.          -" << endl;
	cout << "- 4. The second player must place their tokens horizontally.       -" << endl;
	cout << "- 5. The player to run out of moves first loses!                   -" << endl;
	cout << "--------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "Good luck and have fun!" << endl;
	cout << endl;
	system("PAUSE");
	system("CLS");
}

void option_menu(Board board)
{
	int input;

	cout << "--------------------------------------" << endl;
	cout << "(1) 2 Player Game" << endl;
	cout << "(2) Player vs. AI" << endl;
	cout << "(3) AI vs. Player" << endl;
	cout << "--------------------------------------" << endl;
	cout << "Please select one of the options above: ";
	cin >> input;

	system("CLS");
	if (input == 1)
	{
		human_game(board);
	}
	else if (input == 2)
	{
		AI_game(board, 1);
	}
	else
	{
		AI_game(board, 0);
	}
}