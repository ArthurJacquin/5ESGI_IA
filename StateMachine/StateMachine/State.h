#pragma once
#include<string>
#include<vector>
#include "Pair.h"

using namespace std;

class State
{
	string name;
	vector<Pair> pairs;
	void(*action)();

public:
	State();
	State(string s, void(*f)());
	~State();

	void AddTransition(Transition* t, State* s);
	void ProcessAction();

	vector<Pair> GetPairs()const { return pairs; };

};