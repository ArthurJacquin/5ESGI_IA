#include "GameState.h"

GameState::GameState()
{
	foodAmount = 100;
	waterAmount = 100;
}

GameState::GameState(int f, int w)
{
	foodAmount = f;
	waterAmount = w;
}
