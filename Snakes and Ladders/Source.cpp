#include <iostream>

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

enum Type { blank, snakeHead, snakeTail, ladderHead, ladderTail };

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
	void setTail(Position* tailPos)
	{
		tail = tailPos;
	}
};




void CreateBoard()

int main()
{
	Position positions[25];




	return 0;
}
