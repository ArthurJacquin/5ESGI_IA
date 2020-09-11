#include "Effect.h"

Effect::Effect()
{
	name = PreconditionName::GetPancake;
	addRessource = [](GameState* gs) {};
}

Effect::Effect(PreconditionName n, void(*a)(GameState* const gs))
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
