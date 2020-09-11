#include "Actions.h"

Action::Action()
{
	name = "Default";
	preconditions.reserve(0);
	effect = nullptr;
	cost = 1;
}

Action::Action(string n, int cost)
	:name(n), cost(cost)
{
	preconditions.reserve(4);
	effect = nullptr;
}

Action::~Action()
{
}

void Action::AddPrecondition(const Precondition* const pc)
{
	preconditions.push_back(pc);
}

void Action::SetEffect(const Effect* const e)
{
	effect = e;
}
