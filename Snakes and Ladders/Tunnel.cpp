#include "Tunnel.h"
#include "Board.h"

// Default constructor
Tunnel::Tunnel()
{
	head = Board::getSquares()[0];
	tail = Board::getSquares()[0];
	snakeOrLadder = false;
}

// Specified constructor
Tunnel::Tunnel(Square h, Square t, bool sorl)
{
	head = h;
	tail = t;
	snakeOrLadder = sorl;
}

Square Tunnel::getHead()
{
	return head;
}

Square Tunnel::getTail()
{
	return tail;
}

bool Tunnel::checkType()
{
	return snakeOrLadder;
}