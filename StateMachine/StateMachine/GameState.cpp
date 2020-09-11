#include "GameState.h"
#include <iostream>

GameState::GameState()
{
	foodAmount = 100;
	waterAmount = 100;
	musicVolume = 100;
}

GameState::GameState(int f, int w, int v)
{
	foodAmount = f;
	waterAmount = w;
	musicVolume = v;
}

void GameState::DisplayResources()const
{
	std::cout << "Resources :" << std::endl;
	std::cout << "Food : " << foodAmount << std::endl;
	std::cout << "Water : " << waterAmount << std::endl;
	std::cout << "Music volume : " << musicVolume << std::endl;
	std::cout << std::endl;
}
