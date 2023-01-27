#pragma once
#include "Square.h"

class Square;
class Player;

class Tunnel
{
private:
	Square head;
	Square tail;
	bool snakeOrLadder; // Using enum for readability, but functionally a boolean

public:
	// Default constructor
	Tunnel();
	// Specified constructor
	Tunnel(Square, Square, bool);
	Square getHead();
	Square getTail();
	bool checkType();
};

