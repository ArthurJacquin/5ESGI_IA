#include "GameState.h"
#include <iostream>

GameState::GameState()
{
	foodAmount = 100;
	waterAmount = 100;

	hungerThreshold = 50;
	thirstThreshold = 50;
}

GameState::GameState(int f, int w)
{
	foodAmount = f;
	waterAmount = w;

	hungerThreshold = 50;
	thirstThreshold = 50;
}

void GameState::DisplayResources()
{
	std::cout << "Resources :" << std::endl;
	std::cout << "Food : " << foodAmount << std::endl;
	std::cout << "Water : " << waterAmount << std::endl;
	std::cout << std::endl;
}
