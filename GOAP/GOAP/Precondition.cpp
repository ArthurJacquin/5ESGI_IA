#include "Precondition.h"

Precondition::Precondition()
{
    name = "";
    condition = [](GameState* gs) { return true; };
}

Precondition::Precondition(string n, bool(*f)(GameState*))
    :name(n), condition(f)
{
}

Precondition::~Precondition()
{
}

bool Precondition::Process(GameState* gs) const
{
    return condition(gs);
}
