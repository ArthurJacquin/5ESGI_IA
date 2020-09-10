#include "GameState.h"

using namespace std;

void changeWater(GameState* gs, int w)
{
	gs->setWaterAmount(w);
}

void changeFood(GameState* gs, int f)
{
	gs->setFoodAmount(f);
}