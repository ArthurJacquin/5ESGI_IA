#pragma once
#include<functional>
#include "State.h"

class Transition
{
	std::function<bool()> test;
	State endState;

public:
	Transition();
	Transition(std::function<bool()> f, State end);

	bool Process() const;

	State GetEndState()const { return endState; }

	void SetEndState(State s) { endState = s; }
};
