#include "Precondition.h"

Precondition::Precondition()
{
    name = PreconditionName::GetPancake;
    condition = [](const GameState* const gs)->const bool { return true; };
}

Precondition::Precondition(const PreconditionName n, const bool(*f)(const GameState* const))
    :name(n), condition(f)
{
}

Precondition::~Precondition()
{
}

const bool Precondition::Process(const GameState* const gs) const
{
    return condition(gs);
}
