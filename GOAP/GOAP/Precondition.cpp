#include "Precondition.h"

Precondition::Precondition()
{
    name = "";
    condition = [](const GameState* const gs)->const bool { return true; };
}

Precondition::Precondition(string n, const bool(*f)(const GameState* const))
    :name(n), condition(f)
{
}

Precondition::~Precondition()
{
}

bool Precondition::Process(const GameState* const gs) const
{
    return condition(gs);
}
