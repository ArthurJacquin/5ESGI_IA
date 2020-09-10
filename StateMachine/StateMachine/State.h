#pragma once
#include<string>
#include<vector>
#include "Pair.h"

using namespace std;

class State
{
	string name;
	vector<Pair> pairs;
	void(*action)(Tamagochi*);

public:
	State();
	State(string s, void(*f)(Tamagochi*));
	~State();

	void AddTransition(Transition* t, State* s);
	void ProcessAction(Tamagochi* t);

	vector<Pair> GetPairs()const { return pairs; };

};