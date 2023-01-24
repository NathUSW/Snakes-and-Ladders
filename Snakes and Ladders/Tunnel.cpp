#include "Tunnel.h"

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