#pragma once
#include"State.h"
#include "Tamagochi.h"
#include "GameState.h"

class StateMachine
{
	const State* currentState;
	Tamagochi* tamagochi;
	GameState* gameState;

public:
	StateMachine();
	StateMachine(Tamagochi* const tama, GameState* const gameState, const State* initialState);
	~StateMachine();

	void CreateStateMachine();
	void ProcessState();
	void ChangeState(const State* s, GameState* const gs);

	const State* GetCurrentState() const { return currentState; }
};