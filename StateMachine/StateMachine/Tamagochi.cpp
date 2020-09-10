#include "Tamagochi.h"
#include <iostream>

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
	std::cout << "Je bois\n";
}

void Tamagochi::Eat()
{
	currentHunger += 50;
	std::cout << "Je mange\n";
}

void Tamagochi::Die()
{
	std::cout << "Je suis mort\n";
	isAlive = false;
}