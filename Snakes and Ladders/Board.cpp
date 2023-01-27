#include <vector>
#include "Board.h"
#include "Type.h"

// Constructor called on game start
Board::Board()
{
	squares = std::vector<Square>(25);
	tunnels = std::vector<Tunnel>(7);

	// Tunnel 0 is default tunnel, used to test if a tunnel exists on a square
	// As a cool side effect it means actual tunnels are labelled 1-6

	// Set specific tunnels
	tunnels[1] = Tunnel(squares[13], squares[2], snake);
	tunnels[2] = Tunnel(squares[19], squares[6], snake);
	tunnels[3] = Tunnel(squares[21], squares[3], snake);
	tunnels[4] = Tunnel(squares[4], squares[17], ladder);
	tunnels[5] = Tunnel(squares[7], squares[18], ladder);
	tunnels[6] = Tunnel(squares[15], squares[22], ladder);

	// Set corresponding tunnels in the squares they belong to
	squares[13].setTunnel(tunnels[1]);
	squares[19].setTunnel(tunnels[2]);
	squares[21].setTunnel(tunnels[3]);
	squares[4].setTunnel(tunnels[4]);
	squares[7].setTunnel(tunnels[5]);
	squares[15].setTunnel(tunnels[6]);
}

std::vector<Square>& Board::getSquares()
{
	return squares;
}

std::vector<Tunnel>& Board::getTunnels()
{
	return tunnels;
}