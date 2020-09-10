#include "Transition.h"

Transition::Transition()
{
    test = [] { return true; };
    endState = new State("Default");
}

Transition::Transition(std::function<bool()> f, State* end)
    :test(f), endState(end)
{
}

bool Transition::Process() const
{
    return test();
}
