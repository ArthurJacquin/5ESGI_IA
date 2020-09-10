#pragma once
#include<string>
#include<vector>
#include "Transition.h"

using namespace std;

class State
{
	string name;
	vector<std::pair<const Transition* const, const State* const>> pairs;
	void(*action)(Tamagochi* const, GameState* const);

public:
	State();
	State(string s, void(*f)(Tamagochi* const, GameState* const));
	~State();

	void AddTransition(const Transition* const t, const State* const s);
	void ProcessAction(Tamagochi* const t, GameState* const gs)const;

	const vector<std::pair<const Transition* const, const State* const>> GetPairs()const { return pairs; };
};