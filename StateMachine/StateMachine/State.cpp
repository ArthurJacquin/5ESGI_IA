#include "State.h"

State::State()
{
    name = "Bien";
    pairs.reserve(2);
}

State::State(string s, void(*f)())
{
    name = s;
    pairs.reserve(2);

}

State::~State()
{
    int N = pairs.size();
    for (size_t i = 0; i < N; ++i)
    {
        delete pairs[i].endState;
        delete pairs[i].transition;
    }
}

void State::AddTransition(Transition* t, State* s)
{
    Pair p(t, s);
    pairs.push_back(p);
}

void State::ProcessAction()
{
    action();
}
