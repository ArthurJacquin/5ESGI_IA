#include "State.h"

State::State()
{
    name = "Bien";
    transitions.reserve(2);
}

State::State(string s)
{
    name = s;
    transitions.reserve(2);
}

void State::AddTransition(Transition t, const State s)
{
    t.SetEndState(s);
    transitions.push_back(t);
}
