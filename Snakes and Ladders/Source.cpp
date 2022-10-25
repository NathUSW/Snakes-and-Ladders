#include <iostream>
#include <map>

using namespace std;

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

enum Type { blank, eventHead, eventTail };

class Position
{
private:
	Type type;
	Position* tail;
public:
	Type getType()
	{
		return type;
	}
	void setType(Type t)
	{
		type = t;
	}
	void setTail(Position* tailPos)
	{
		tail = tailPos;
	}
};





// GLOBAL VARIABLES
Position positions[25];
map<int, int> eventSquares = {

	// SNAKES
	{14, 3},
	{20, 7},
	{25, 4},

	// LADDERS
	{5, 18},
	{8, 19},
	{16, 23}
};

void CreateBoard()
{
	for (int i = 0; i < sizeof(positions) / sizeof(Position); i++)
	{
		if (eventSquares.count(i + 1))
		{
			positions[i].setType(eventHead);
			positions[i].setTail(&positions[eventSquares.find(i)->second - 1]);
		}
	}
}

int main()
{
	CreateBoard();



	return 0;
}
