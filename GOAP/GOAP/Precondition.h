#pragma once
#include <string>
#include "GameState.h"

using namespace std;

class Precondition
{
	string name;
	bool(*condition)(GameState*);

public :
	Precondition();
	Precondition(string name, bool(*f)(GameState*));
	~Precondition();

	bool Process(GameState* gs) const;
};