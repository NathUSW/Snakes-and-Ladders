#include "Event.h"

Event::Event(int s, int e)
{
	start = s;
	end = e;
}

int Event::getStart()
{
	return start;
}

int Event::getEnd()
{
	return end;
}