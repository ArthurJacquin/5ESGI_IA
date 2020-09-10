#pragma once
#include<functional>
#include "Tamagochi.h"
#include "GameState.h"

class Transition
{
	const bool(*condition)(const Tamagochi* const, const GameState* const);

public:
	Transition();
	Transition(const bool(*f)(const Tamagochi* const, const GameState* const));
	~Transition();

	const bool Process(const Tamagochi* const t, const GameState* const gs) const;
};