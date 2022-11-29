#include "Player.h"

Player::Player()
{
	currentSquare = 1;
	winner = false;
}

int Player::getCurrentSquare()
{
	return currentSquare;
}

void Player::setCurrentSquare(int x)
{
	currentSquare = x;
}

void Player::win()
{
	bool winner = true;
}