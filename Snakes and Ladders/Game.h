#pragma once
#include "Board.h"
#include "Dice.h"
#include "Player.h"
#include <vector>

// This is the game class, containing the board, a list of players, and the dice used, alongside methods to play the game, which will be managed by a GameManager class
class Game
{
private:
	std::vector<Player> players;
public:
	Game();
	void turn(Player&);
	void startGame();
	void movePlayer(Player&, int);
	//void checkPositions();
};

