#include "Square.h"

Square::Square()
{
	id = count;
	count++;
}

int Square::getID()
{
	return id;
}

Player Square::getPlayer()
{
	return player;
}

Tunnel Square::getTunnel()
{
	return tunnel;
}

void Square::setTunnel(Tunnel t)
{
	tunnel = t;
}