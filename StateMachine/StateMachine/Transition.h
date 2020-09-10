#pragma once
#include<functional>
#include "Tamagochi.h"
#include "GameState.h"

class Transition
{
	bool(*condition)(Tamagochi*, GameState*);

public:
	Transition();
	Transition(bool(*f)(Tamagochi*, GameState*));
	~Transition();

	bool Process(Tamagochi* t, GameState* gs) const;
};