#pragma once
#include"State.h"

class StateMachine
{
	State* currentState;

public:
	StateMachine();
	StateMachine(State initialState);
	~StateMachine(); //Faire tous les delete

	void CreateStateMachine();
	void ProcessState();
	void ChangeState();

	State* GetCurrentState() const;
};