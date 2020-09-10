#include "Transition.h"

Transition::Transition()
{
    condition = [](const Tamagochi* const t, const GameState* const gs)->const bool { return true; };
}

Transition::Transition(const bool(*f)(const Tamagochi* const, const GameState* const))
    :condition(f)
{
}

Transition::~Transition()
{
}

const bool Transition::Process(const Tamagochi* const t, const GameState* const gs) const
{
    return condition(t, gs);
}
