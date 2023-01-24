#include "Game.h"
#include <vector>
#include <algorithm>

Game::Game()
{

}

void Game::startGame()
{
	// Call board constructor
	Board::Board();

	for (int i = 0; i < sizeof(players) / sizeof(Player); i++)
	{
		turn(players[i]);
	}
}

void Game::movePlayer(Player &player, int moves)
{
	Square currentSquare = player.getCurrentSquare();
	std::vector<Square> squares = Board::getSquares();

	for (int i = 0; i < squares.size(); i++)
	{
		if (squares[i].getID() == currentSquare.getID())
		{
			player.setCurrentSquare(squares[i + moves]);
			return;
		}
	}
}

void Game::turn(Player &player)
{
	int roll = Dice::roll();

}