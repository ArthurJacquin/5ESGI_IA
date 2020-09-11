#pragma once
#include <string>
#include"GameState.h"

using namespace std;

class Effect
{
	string name;
	void(*addRessource)(GameState* const gs);

public:
	Effect();
	Effect(string n, void(*a)(GameState* const gs));
	~Effect();
		
	void ProcessAction(GameState* const gs)const;
	const string GetName()const { return name; }
};