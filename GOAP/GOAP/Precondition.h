#pragma once
#include <string>
#include "GameState.h"

using namespace std;

class Precondition
{
	string name;
	const bool(*condition)(const GameState* const);

public :
	Precondition();
	Precondition(string name, const bool(*f)(const GameState* const));
	~Precondition();

	bool Process(const GameState* const gs) const;
	const string GetName()const { return name; };
};