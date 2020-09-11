#include "Effect.h"

Effect::Effect()
{
	name = "";
	addRessource = [](GameState* gs) {};
}

Effect::Effect(string n, void(*a)(GameState* const gs))
	:name(n), addRessource(a)
{
}

Effect::~Effect()
{
}

void Effect::ProcessAction(GameState* const gs)const
{
	addRessource(gs);
}
