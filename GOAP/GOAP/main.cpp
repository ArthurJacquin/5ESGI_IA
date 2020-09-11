#pragma once
#include "Goap.h"
#include <Windows.h>


int main()
{
	GameState gs;
	GoapSolver goap;

	goap.CreateSolver();

	while (gs.GetPancakeAmount() < 10)
	{
		std::cout << std::endl;
		std::cout << "----------------------------" << std::endl;
		std::cout << "----------Pancake " << gs.GetPancakeAmount() << "---------" << std::endl;
		std::cout << "----------------------------" << std::endl;

		goap.Solve(&gs);

		goap.ExecuteActions(&gs);

		Sleep(1000);
	}

	return 0;
}