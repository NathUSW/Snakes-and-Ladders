#include <iostream>
#include <random>

using namespace std;

// GLOBAL VARIABLES - TO BE REMOVED
bool playerWon = false;
int winningPlayer;

// Implement player class with information stored about current position on the board, and whether the player is the winner, alongside corresponding getter and setter methods
class Player
{
private:
	int currentSquare = 1;
	bool winner = false;

public:
	int getCurrentSquare()
	{
		return currentSquare;
	}
	void setCurrentSquare(int x)
	{
		currentSquare = x;
	}
	void win()
	{
		bool winner = true;
		playerWon = true;
	}
};


// Prototypes
int RandomRange(int, int);
int RollDice();
void Turn(Player &player);


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

	// While nobody has won the game
	while (!playerWon)
	{
		// Loop through the array of players
		for (int i = 0; i < sizeof(players) / sizeof(Player); i++)
		{
			// Simulate a player rolling the dice, and move the player on the board accordingly
			Turn(players[i]);

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

void Turn(Player &player)
{
	int dice = RollDice();
	cout << dice << endl;

	if (player.getCurrentSquare() + dice > 25)
	{
		// Do nothing, the player cannot move
		return;
	}
	else if (player.getCurrentSquare() + dice == 25)
	{
		// Player has reached the final square, win the game
		player.win();
	}
	else
	{
		// Increment the player's position on the board by the number on the dice
		player.setCurrentSquare(player.getCurrentSquare() + dice);
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