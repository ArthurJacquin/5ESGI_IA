#include "GameState.h"
#include <cstdlib>

GameState::GameState()
	:eggsAmount(rand() % 6), flourAmount(rand() % 6), nutAmount(rand() % 6), chickenAmount(rand() % 6), wheatAmount(rand() % 6), pancakeAmount(0)
{
}

GameState::GameState(int eggs, int flour, int nut, int chicken, int wheat)
	:eggsAmount(eggs), flourAmount(flour), nutAmount(nut), chickenAmount(chicken), wheatAmount(wheat), pancakeAmount(0)
{
}
