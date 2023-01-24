#pragma once
#include "Board.h"
#include "Dice.h"
#include "Player.h"

// This is the game class, containing the board, a list of players, and the dice used, alongside methods to play the game, which will be managed by a GameManager class

enum Type
{
	snake,
	ladder
};

class Game
{
private:
	Player players[];
public:
	Game();
	void turn(Player&);
	void startGame();
	void movePlayer(Player&, int);
};

