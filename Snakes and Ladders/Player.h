#include "Square.h"
class Square;
class Tunnel;

class Player
{
private:
	static int count;
	int id;
	Square currentSquare;
	bool winner;
public:
	Player();

	// Allow specific position modification, for example using tunnels, or getting current position information
	Square getCurrentSquare();
	void setCurrentSquare(Square);
	
	void win();
};
