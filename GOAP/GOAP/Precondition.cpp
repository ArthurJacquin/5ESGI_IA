#include "Precondition.h"

Precondition::Precondition()
{
    name = PreconditionName::GetPancake;
    condition = [](const GameState* const gs)->const bool { return true; };
}

Precondition::Precondition(PreconditionName n, const bool(*f)(const GameState* const))
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
