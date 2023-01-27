#pragma once
#include "Player.h"
#include "Tunnel.h"

class Player;
class Tunnel;

class Square
{
private:
	// Count of squares, used to set ID
	static int count;
	// ID of square to use in for loops for identification
	int id;
	Player player;
	Tunnel tunnel;
public:
	int getID();
	Player getPlayer();
	Tunnel getTunnel();
	void setTunnel(Tunnel);
};

