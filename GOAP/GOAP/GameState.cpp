#include "GameState.h"
#include <cstdlib>

GameState::GameState()
	:eggsAmount(0), flourAmount(0), nutAmount(0), chickenAmount(4), fieldAmount(4), wheatAmount(0),
	mixedEggsAmount(0), mixedFlourAmount(0), mixedNutAmount(0), pancakeAmount(0)
{
}

GameState::GameState(int eggs, int flour, int nut, int chicken, int fieldAmount, int wheat)
	:eggsAmount(eggs), flourAmount(flour), nutAmount(nut), chickenAmount(chicken), fieldAmount(fieldAmount), wheatAmount(wheat), mixedEggsAmount(0), mixedFlourAmount(0), mixedNutAmount(0), pancakeAmount(0)
{
}