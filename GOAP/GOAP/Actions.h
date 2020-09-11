#pragma once
#include <string>
#include <vector>
#include "Effect.h"
#include "Precondition.h"

using namespace std;

class Action
{
	string name;
	vector<const Precondition*> preconditions;
	vector<const Effect*> effects;
	int cost;

public:
	Action();
	Action(string n, int cost = 1);
	~Action();

	void AddPrecondition(const Precondition* const pc);
	void SetEffect(vector<const Effect*> e);

	const vector<const Precondition*> GetPreconditions()const { return preconditions; }
	const vector<const Effect*> GetEffect()const { return effects; }
	const int GetCost() const { return cost; }
};