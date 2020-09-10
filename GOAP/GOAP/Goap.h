#pragma once
#include "Actions.h"

class GoapSolver
{
	vector<Action*> allActions;
	Action* goalAction;

public:
	GoapSolver();
	GoapSolver(Action* goal);
	~GoapSolver();

	void CreateSolver();
	void Solve();
};