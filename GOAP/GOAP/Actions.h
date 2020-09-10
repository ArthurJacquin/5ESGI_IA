#pragma once
#include <string>
#include <vector>

using namespace std;

class Action
{
	string name;
	vector<string> preconditions;
	string effets;

public:
	Action();
	Action(string n);
	~Action();

	void AddPrecondition(string pc);
	void AddEffect(string e);

};