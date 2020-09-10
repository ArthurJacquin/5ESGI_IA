#include "GameState.h"

GameState::GameState()
{
	foodAmount = 100;
	waterAmount = 100;

	hungerThreshold = 50;
	thirstThreshold = 60;
}

GameState::GameState(int f, int w)
{
	foodAmount = f;
	waterAmount = w;

	hungerThreshold = 50;
	thirstThreshold = 60;
}
