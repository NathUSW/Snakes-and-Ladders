#include <vector>
#include "Board.h"

// Constructor called on game start
Board::Board()
{
	squares = std::vector<Square>(25);
}

std::vector<Square>& Board::getSquares()
{
	return squares;
}

std::vector<Tunnel>& Board::getTunnels()
{
	return tunnels;
}