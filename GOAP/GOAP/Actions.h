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
	const Effect* effect;
	int cost;

public:
	Action();
	Action(string n, int cost = 1);
	~Action();

	void AddPrecondition(const Precondition* const pc);
	void SetEffect(const Effect* const e);

	const vector<const Precondition*> GetPreconditions()const { return preconditions; }
	const Effect* GetEffect()const { return effect; }
};