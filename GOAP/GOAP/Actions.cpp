#include "Actions.h"

Action::Action()
{
	name = "Default";
	preconditions.reserve(0);
	effects.reserve(0);
	cost = 1;
}

Action::Action(string n, int cost)
	:name(n), cost(cost)
{
	preconditions.reserve(0);
	effects.reserve(0);
}

Action::~Action()
{
}

void Action::AddPrecondition(const Precondition* const pc)
{
	preconditions.push_back(pc);
}

void Action::SetEffect(vector<const Effect*> e)
{
	effects = e;
}
