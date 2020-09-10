#pragma once
#include<string>
#include<vector>
#include "Pair.h"

using namespace std;

class State
{
	string name;
	vector<std::pair<Transition*, State*>> pairs;
	void(*action)(Tamagochi*, GameState* gs);

public:
	State();
	State(string s, void(*f)(Tamagochi*, GameState*));
	~State();

	void AddTransition(Transition* t, State* s);
	void ProcessAction(Tamagochi* t, GameState* gs);

	vector<std::pair<Transition*, State*>> GetPairs()const { return pairs; };

};