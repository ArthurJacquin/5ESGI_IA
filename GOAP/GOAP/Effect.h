#pragma once
#include <string>
#include"GameState.h"

using namespace std;

class Effect
{
	string name;
	void(*addRessource)(GameState* gs);

public:
	Effect();
	Effect(string n, void(*a)(GameState* gs));
	~Effect();
		
	void ProcessAction(GameState* gs);
};