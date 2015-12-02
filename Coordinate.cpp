#include <iostream>
#include "Coordinate.h"

using namespace std;

//constructor

Coordinate::Coordinate()
{
	minimax_value = 0;
	x = -1;
	y = -1;
	value = AVAILABLE;
}

//copy constructor

Coordinate::Coordinate(Coordinate &copy)
{
	minimax_value = copy.getMinimax();
	x = copy.getX();
	y = copy.getY();
	value = copy.getValue();
}

//accessors

int Coordinate::getX()
{
	return x;
}

int Coordinate::getY()
{
	return y;
}

char Coordinate::getValue()
{
	return value;
}

int Coordinate::getMinimax()
{
	return minimax_value;
}

//mutators

void Coordinate::setX(int x)
{
	this->x = x;
}

void Coordinate::setY(int y)
{
	this->y = y;
}

void Coordinate::setValue(char value)
{
	this->value = value;
}

void Coordinate::setMinimax(int minimax_value)
{
	this->minimax_value = minimax_value;
}

//free functions

Coordinate string_to_coordinate(char* coordinate)
{
	Coordinate temp;

	if (strlen(coordinate) == 2) //board size less than 10
	{
		char temp_x[1];
		memset(temp_x, 0, 1);
		memcpy(temp_x, &coordinate[1], 1);
		temp.setX(atoi(temp_x) - 1);
	}
	else //board size greater than 10
	{
		char temp_x[2];
		memset(temp_x, 0, 2);
		memcpy(temp_x, &coordinate[1], 2);
		temp.setX(atoi(temp_x) - 1);
	}

	coordinate[0] = toupper(coordinate[0]);

	temp.setY(coordinate[0] - 65);

	return temp;
}