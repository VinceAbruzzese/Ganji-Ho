/*
We certify that this submission is the original work of the group
and meets with the Faculty's Expectations of Originality
*/

//--------------------------------
// COMP 472
// Ganji-Ho
// Vince Abruzzese (26448585)
// John Di Girolamo (26202918)
// Driver.cpp
//--------------------------------

#include <iostream>
#include <vector>
#include "MainMethods.h"
#include "Board.h"

using namespace std;

int main()
{
	Board board;

	welcome_message();
	option_menu(board);

	cout << endl;
	system("PAUSE");
	return 0;
}