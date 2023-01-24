#pragma once
#include <vector>
#include "Square.h"
#include "Tunnel.h"

// This class contains information about the board the game is played on
static class Board
{
private:
	// Array of all squares on the board
	static std::vector<Square> squares;

	// Array of the snakes and ladders, referred to as "tunnels"
	static std::vector<Tunnel> tunnels;
public:
	Board();
	// Return reference to arrays of squares
	static std::vector<Square>& getSquares();

	// Return reference to arrays of tunnels
	static std::vector<Tunnel>& getTunnels();
};