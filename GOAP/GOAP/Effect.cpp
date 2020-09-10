#include "Effect.h"

Effect::Effect()
{
	name = "";
	addRessource = [](GameState* gs) {};
}

Effect::Effect(string n, void(*a)(GameState* gs))
	:name(n), addRessource(a)
{
}

Effect::~Effect()
{
}

void Effect::ProcessAction(GameState* gs)
{
	addRessource(gs);
}
