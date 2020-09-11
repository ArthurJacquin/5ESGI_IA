#pragma once
#include "Actions.h"

class GoapSolver
{
	const Action* goalAction;
	vector<const Action*> allActions;
	vector<vector<const Action*>> bestPaths;

public:
	GoapSolver();
	GoapSolver(const Action* const goal);
	~GoapSolver();

	void CreateSolver();
	void Solve(GameState* gs); //Pas const car modifie bestPaths
	void ExecuteActions(GameState* const gs); //Pas const car modifie bestPaths
	void SolveTree(const Action* const head, vector<const Action*> path, int pathCost, vector<const Action*>& bestPath, int& bestCost, const GameState* const gs); //Pas const car modifie bestPaths
	vector<const Action*> GetActionsResolvingPrecondition(const Precondition* const p)const;
};