#include "State.h"

State::State()
{
    name = "";
    pairs.reserve(0);
}

State::State(string s, void(*f)(Tamagochi* const, GameState* const))
{
    name = s;
    pairs.reserve(2);
    action = f;
}

State::~State()
{
}

void State::AddTransition(const Transition* const t, const State* const s)
{
    std::pair< const Transition* const, const State* const> p = make_pair(t, s);
    pairs.push_back(p);
}

void State::ProcessAction(Tamagochi* const t, GameState* const gs)const
{
    action(t, gs);
}
