#include "Actions.h"

Action::Action()
{
	name = "Default";
	preconditions.reserve(0);
	effect = "";
	cost = 1;
}

Action::Action(string n, int cost)
	:name(n), cost(cost)
{
	preconditions.reserve(4);
	effect = "";
}

Action::~Action()
{
}

void Action::AddPrecondition(string pc)
{
	preconditions.push_back(pc);
}

void Action::SetEffect(string e)
{
	effect = e;
}
