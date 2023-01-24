#include "Player.h"
#include "Board.h"

Player::Player()
{
	// Set player ID based on count, and increment count
	id = count;
	count++;

	// Set player position to first square on the board
	currentSquare = Board::getSquares().front();

	// Set default win status
	winner = false;
}

Square Player::getCurrentSquare()
{
	return currentSquare;
}

void Player::setCurrentSquare(Square x)
{
	currentSquare = x;
}

void Player::win()
{
	bool winner = true;
}