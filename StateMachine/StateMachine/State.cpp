#include "State.h"

State::State()
{
    name = "Bien";
    pairs.reserve(2);
}

State::State(string s, void(*f)(Tamagochi*, GameState* gs))
{
    name = s;
    pairs.reserve(2);
    action = f;
}

State::~State()
{
}

void State::AddTransition(Transition* t, State* s)
{
    std::pair< Transition*, State*> p = make_pair(t, s);
    pairs.push_back(p);
}

void State::ProcessAction(Tamagochi* t, GameState* gs)
{
    action(t, gs);
}
