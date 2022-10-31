#include <iostream>
#include <map>

using namespace std;

enum Type { blank, eventHead, eventTail };

class Position
{
private:
	Type type;
	int tailPosition; // null if not of type EventSquare
public:
	Type getType()
	{
		return type;
	}
	void setType(Type t)
	{
		type = t;
	}
	int getTail()
	{
		return tailPosition;
	}
	void setTail(int tailPos)
	{
		tailPosition = tailPos;
	}
};

class Player
{
private:
	Position position;
public:
	void setPosition(Position pos)
	{
		position = pos;
	}
	Position getPosition()
	{
		return position;
	}
};

// GLOBAL VARIABLES
Position positions[25];

void CreateBoard()
{
	/*
	
	This is a map of the squares containing a snake or a ladder, hereafter known as "event squares"
	Each head of a snake or ladder has a corresponding end location, defined as an int and used to identify the position that the player should move to.
	Every number is shifted down by one, to account for arrays beginning at 0.
	
	*/

	map<int, int> eventSquares;

	// SNAKES
	eventSquares[13] = 2;
	eventSquares[19] = 6;
	eventSquares[24] = 3;

	// LADDERS
	eventSquares[4] = 17;
	eventSquares[7] = 18;
	eventSquares[15] = 22;

	for (int i = 0; i < sizeof(positions) / sizeof(Position); i++)
	{
		if (eventSquares[i])
		{
			positions[i].setType(eventHead);
			cout << "Position " << i << " is an eventHead" << endl;
			positions[i].setTail(eventSquares[i]);
			positions[positions[i].getTail()].setType(eventTail);
		}
	}
};

int main()
{
	CreateBoard();

	int currentPos = 0;
	for (Position position : positions)
	{
		cout << ++currentPos << " " << position.getType() << " " << position.getTail() << endl;
	}

	return 0;
};
