#pragma once
#include <string>
#include <vector>

using namespace std;

class Action
{
	string name;
	vector<string> preconditions;
	string effect;
	int cost;

public:
	Action();
	Action(string n, int cost = 1);
	~Action();

	void AddPrecondition(string pc);
	void SetEffect(string e);

	vector<string> GetPreconditions()const { return preconditions; }
	string GetEffect()const { return effect; }
};