#pragma once
#include "Transition.h"
#include "State.h"

class State;
struct Pair
{
	Transition* transition;
	State* endState;

	Pair(Transition* t, State* s) :transition(t), endState(s) {}
	~Pair() {
		delete transition;
		delete endState;
	}
};