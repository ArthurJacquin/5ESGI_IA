#include "Tamagochi.h"

Tamagochi::Tamagochi()
{
	maxHunger = 100;
	maxThirst = 100;
	currentHunger = 0;
	currentThirst = 0;
	isAlive = true;
}

void Tamagochi::Drink()
{
	currentThirst += 20;
}

void Tamagochi::Eat()
{
	currentHunger += 50;
}

void Tamagochi::Die()
{
	isAlive = false;
}