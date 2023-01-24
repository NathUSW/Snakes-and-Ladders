#pragma once
#include "Square.h"

class Tunnel
{
private:
	Square head;
	Square tail;
	bool snakeOrLadder; // Using enum for readability, but functionally a boolean

public:
	Square getHead();
	Square getTail();
	bool checkType();
};

