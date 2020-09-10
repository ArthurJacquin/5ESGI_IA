#pragma once
#include"State.h"
#include "Tamagochi.h"
#include "GameState.h"

class StateMachine
{
	State* currentState;
	Tamagochi* tamagochi;
	GameState* gameState;

public:
	StateMachine();
	StateMachine(Tamagochi* tama, GameState* gameState, State* initialState);
	~StateMachine();

	void CreateStateMachine();
	void ProcessState();
	void ChangeState(State* s);

	State* GetCurrentState() const { return currentState; }
};