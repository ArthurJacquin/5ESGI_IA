#include "Tamagochi.h"
#include <iostream>
#include "DisplayDrawing.h"

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
	drawing::eatOrDrinkDog();
	std::cout << "-> " << name << " boit\n";
}

void Tamagochi::Eat(GameState* gs)
{
	int amount = 30;
	currentHunger -= amount;
	gs->setFoodAmount(gs->getFoodAmount() - amount);
	drawing::eatOrDrinkDog();
	std::cout << "-> " << name << " mange\n";
}

void Tamagochi::Die()
{
	drawing::deadDog();
	std::cout << "->  " << name << " est mort(e)\n";
	isAlive = false;
}

void Tamagochi::UpdateStats()
{
	if (currentThirst < maxThirst)
		currentThirst += 5;
	
	if(currentHunger < maxHunger)
		currentHunger += 2;
}

void Tamagochi::DisplayStats()
{
	std::cout << "Stats :" << std::endl;
	std::cout << "Hunger : " << currentHunger << std::endl; 
	std::cout << "Thirst : " << currentThirst << std::endl;
	std::cout << std::endl;
}
