#pragma once
#include<string>
#include<vector>
#include "Transition.h"

using namespace std;

class State
{
	string name;
	vector<Transition*> transitions;

public:
	State();
	State(string s);

	void AddTransition(Transition* t, State* s);
	
	vector<Transition*> GetTransition()const { return transitions; };
};