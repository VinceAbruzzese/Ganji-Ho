//--------------------------------
// COMP 472
// Ganji-Ho
// Vince Abruzzese (26448585)
// John Di Girolamo (26202918)
// Methods.h
//--------------------------------

#ifndef HEURISTIC_METHODS_H
#define HEURISTIC_METHODS_H

#include "Board.h"
#include <string>

using namespace std;

int calculate_num_of_moves(Board board, string type);
int calculate_heuristic(Board board);

#endif