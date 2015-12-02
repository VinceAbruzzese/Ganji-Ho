//--------------------------------
// COMP 472
// Ganji-Ho
// Vince Abruzzese (26448585)
// John Di Girolamo (26202918)
// AIMethods.h
//--------------------------------

#ifndef AI_METHODS_H
#define AI_METHODS_H

#include "Board.h"

namespace
{
	int AI_PLAYER;
	int const DEPTH = 3;
}

//AI methods
void AI_turn(Board &board);
void AI_game(Board &board, int ai_turn);
void display_AI_move(Coordinate first, Coordinate second);

void display_heuristic_values(int(&h_values)[BOARD_SIZE][BOARD_SIZE]);

Coordinate minimax(Board &board, int depth, int alpha, int beta, bool maximizingPlayer);

#endif