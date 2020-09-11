#pragma once
#include "Actions.h"

class GoapSolver
{
	const Action* goalAction;
	vector<Action*> allActions;
	vector<vector<const Action*>> bestPaths;

public:
	GoapSolver();
	GoapSolver(Action* goal);
	~GoapSolver();

	void CreateSolver();
	void Solve(GameState* gs);
	void ExecuteActions(GameState* const gs)const;
	void SolveTree(const Action* const head, vector<const Action*> path, int pathCost, vector<const Action*>& bestPath, int& bestCost, const GameState* const gs);
	vector<const Action*> GetActionsResolvingPrecondition(const Precondition* const p)const;
};