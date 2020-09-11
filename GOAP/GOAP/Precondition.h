#pragma once
#include <string>
#include "GameState.h"
#include "PreconditionName.h"

using namespace std;

class Precondition
{
	PreconditionName name;
	const bool(*condition)(const GameState* const);

public :
	Precondition();
	Precondition(PreconditionName name, const bool(*f)(const GameState* const));
	~Precondition();

	bool Process(const GameState* const gs) const;
	const PreconditionName GetName()const { return name; };
};