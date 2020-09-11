#include <iostream>
#include "Tamagochi.h"
#include "DisplayDrawing.h"
#include "ConstValues.h"

Tamagochi::Tamagochi(std::string s)
{
	name = s;
	currentHunger = 0;
	currentThirst = 0;
	currentTiredness = 0;
	isAlive = true;
}

void Tamagochi::Drink(GameState* const gs)
{
	currentThirst -= ConstValues::thirstDecrementFromWater;
	gs->setDrinkAmount(gs->getWaterAmount() - ConstValues::thirstDecrementFromWater);
	drawing::eatOrDrinkDog();
	std::cout << "-> " << name << " boit\n";
}

void Tamagochi::Eat(GameState* const gs)
{
	currentHunger -= ConstValues::hungerDecrementFromFood;
	gs->setFoodAmount(gs->getFoodAmount() - ConstValues::hungerDecrementFromFood);
	drawing::eatOrDrinkDog();
	std::cout << "-> " << name << " mange\n";
}

void Tamagochi::Sleep(GameState* const gs)
{
	currentTiredness -= ConstValues::tiredDecrementFromMusic;
	//gs->setMusicVolume(gs->getMusicVolume() - ConstValues::tiredDecrementFromMusic);
	drawing::sleepingDog();
	std::cout << "-> " << name << " dort\n";
}

void Tamagochi::StopMusic(GameState* const gs)
{
	gs->setMusicVolume(0);
	std::cout << name << " a stop la musique ! \n";
}

void Tamagochi::Debug(GameState* const gs)
{
	std::cout << "tired" << std::endl;
}

void Tamagochi::Die()
{
	drawing::deadDog();
	std::cout << "->  " << name << " est mort(e)\n";
	isAlive = false;
}

void Tamagochi::UpdateStats()
{
	if (currentThirst < ConstValues::maxThirst)
		currentThirst += ConstValues::thirstIncrement;
	
	if(currentHunger < ConstValues::maxHunger)
		currentHunger += ConstValues::hungerIncrement;

	if (currentTiredness < ConstValues::maxTiredness)
		currentTiredness += ConstValues::tiredIncrement;
}

void Tamagochi::DisplayStats()const
{
	std::cout << "Stats :" << std::endl;
	std::cout << "Hunger : " << currentHunger << std::endl; 
	std::cout << "Thirst : " << currentThirst << std::endl;
	std::cout << "Tiredness : " << currentTiredness << std::endl;
	std::cout << std::endl;
}
