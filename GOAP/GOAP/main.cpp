#pragma once
#include "Goap.h"


int main()
{
	GameState gs;
	GoapSolver goap;

	goap.CreateSolver();

	while (gs.GetPancakeAmount() < 10)
	{
		goap.Solve(&gs);

		goap.ExecuteActions(&gs);
	}

	return 0;
}