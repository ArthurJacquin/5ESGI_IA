#include "Transition.h"

Transition::Transition()
{
    condition = [](Tamagochi* t, GameState* gs) { return true; };
}

Transition::Transition(bool(*f)(Tamagochi*, GameState*))
    :condition(f)
{
}

Transition::~Transition()
{
}

bool Transition::Process(Tamagochi* t, GameState* gs) const
{
    return condition(t, gs);
}
