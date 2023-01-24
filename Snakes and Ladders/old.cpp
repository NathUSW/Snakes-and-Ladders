#include <iostream>
#include "Event.h"
#include "Game.h"

using namespace std;

// GLOBAL VARIABLES - TO BE REMOVED
bool playerWon = false;
int winningPlayer;


Event events[6] =
{
	// Snakes
	Event(14,3),
	Event(20,7),
	Event(22,4),

	// Ladders
	Event(5,18),
	Event(8,19),
	Event(16,23)
};

// Prototypes
int RandomRange(int, int);
int RollDice();
void Turn(Player&, int);

int main()
{
	// Seed random number generator
	srand(static_cast<unsigned int>(time(NULL)));
	rand(); // Visual Studio bug fix

	// Get total players in game, up to a maximum of four
	int totalPlayers;
	cout << "How many players are playing?" << endl;
	cin >> totalPlayers;

	// Clear cin buffer to prevent overloads
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	// Create list of players
	Player players[4];

	// Create list of snakes and ladders, and set values accordingly

	// While nobody has won the game
	while (!playerWon)
	{
		// Loop through the array of players
		for (int i = 0; i < sizeof(players) / sizeof(Player); i++)
		{
			// Simulate a player rolling the dice, and move the player on the board accordingly
			Turn(players[i], i);

			// Check if a player has won, record the winning player, and exit the loop
			if (playerWon)
			{
				winningPlayer = i;
				break;
			}
		}
	}

	// When a player has won, print out who won
	cout << "Player " << winningPlayer << " won the game!" << endl;

	return 0;
}

void Turn(Player& player, int ID)
{
	int dice = RollDice();
	cout << "Player " << ID << " rolled the dice and scored " << dice << endl;
	int current = player.getCurrentSquare();

	if (current + dice > 25)
	{
		// Do nothing, the player cannot move
		cout << "Player " << ID << " can't move" << endl;
		return;
	}
	else if (current + dice == 25)
	{
		// Player has reached the final square, win the game
		player.win();
		playerWon = true;
	}
	else
	{
		current += dice;
		// Increment the player's position on the board by the number on the dice
		player.setCurrentSquare(current);
		cout << "Player " << ID << " moved to square " << player.getCurrentSquare() << endl;
	}

	for (int i = 0; i < sizeof(events) / sizeof(Event); i++)
	{
		if (current == events[i].getStart())
		{
			if (events[i].getEnd() > current)
				cout << "Player " << ID << " landed on a ladder!" << endl;
			else
				cout << "Player " << ID << " landed on a snake!" << endl;
			player.setCurrentSquare(events[i].getEnd());
			cout << "Player " << ID << " moved to square " << player.getCurrentSquare() << endl;
		}
	}
}

int RollDice()
{
	return RandomRange(1, 6);
}

int RandomRange(int min, int max)
{
	int x = rand() % (max - min + 1) + min;
	return x;
}