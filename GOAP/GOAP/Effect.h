#pragma once
#include <string>
#include"GameState.h"
#include "PreconditionName.h"

using namespace std;

class Effect
{
	PreconditionName name;
	void(*addRessource)(GameState* const gs);

public:
	Effect();
	Effect(PreconditionName n, void(*a)(GameState* const gs));
	~Effect();
		
	void ProcessAction(GameState* const gs)const;
	const PreconditionName GetName()const { return name; }
};