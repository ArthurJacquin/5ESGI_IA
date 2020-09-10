#include "Tamagochi.h"
#include <iostream>

Tamagochi::Tamagochi(std::string s)
{
	name = s;
	maxHunger = 100;
	maxThirst = 100;
	currentHunger = 0;
	currentThirst = 0;
	isAlive = true;
}

void Tamagochi::Drink(GameState* gs)
{
	int amount = 20;
	currentThirst -= amount;
	gs->setDrinkAmount(gs->getWaterAmount() - amount);
	std::cout << "-> " << name << " boit\n";
}

void Tamagochi::Eat(GameState* gs)
{
	int amount = 50;
	currentHunger -= amount;
	gs->setFoodAmount(gs->getFoodAmount() - amount);
	std::cout << "-> " << name << " mange\n";
}

void Tamagochi::Die()
{
	std::cout << "->  " << name << " est mort(e)\n";
	isAlive = false;
}

void Tamagochi::UpdateStats()
{
	if (currentThirst < maxThirst)
		currentThirst += 5;
	
	if(currentHunger < maxHunger)
		currentHunger += 5;
}

void Tamagochi::DisplayStats()
{
	std::cout << "Stats :" << std::endl;
	//std::cout << "Hunger : " << currentHunger << std::endl; 
	std::cout << "Thirst : " << currentThirst << std::endl;
	std::cout << std::endl;
}
