#pragma once
class Event
{
private:
	int start;
	int end;
public:
	Event(int, int);
	int getStart(), getEnd();
};

