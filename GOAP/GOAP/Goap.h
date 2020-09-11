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
	void Solve(GameState gs)const;
	void ExecuteActions(GameState* const gs)const;
	vector<Action*> SolveTree(const Action* const head)const;
	vector<Action*> GetActionsResolvingPrecondition(const Precondition* const p)const;
};