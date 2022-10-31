#include <iostream>

using namespace std;

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
	}
};



int RollDice();

int main()
{

}

int RollDice()
{

}