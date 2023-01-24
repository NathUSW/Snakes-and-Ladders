#include "Dice.h"
#include <random>

int Dice::roll()
{
	return roll(1, 6);
}

int Dice::roll(int min, int max)
{
	int number = rand() % (max - min + 1) + min;
	return number;
}