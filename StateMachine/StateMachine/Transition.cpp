#include "Transition.h"

Transition::Transition()
{
    //TODO
}

Transition::Transition(std::function<bool()> f, State end)
    :test(f), endState(end)
{
}

bool Transition::Process() const
{
    return test();
}
