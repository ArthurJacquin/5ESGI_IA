#pragma once
#include "Goap.h"
#include <Windows.h>


int main()
{
	int chickenAmount;
	int eggsAmount;
	int fieldAmount;
	int wheatAmount;
	int flourAmount;
	int nutAmount;

	//User Setup
	std::cout << "Pancakes !!!" << std::endl << std::endl;
	cout << "Let's set some parameters !" << endl;
	std::cout << "Chicken amount ?" << std::endl;
	cin >> chickenAmount;
	std::cout << "Eggs amount ?" << std::endl;
	cin >> eggsAmount;
	std::cout << "Field amount ?" << std::endl;
	cin >> fieldAmount;
	std::cout << "Wheat amount ?" << std::endl;
	cin >> wheatAmount;
	std::cout << "Flour amount ?" << std::endl;
	cin >> flourAmount;
	std::cout << "Nut amount ?" << std::endl;
	cin >> nutAmount;


	//Objects creation
	GameState gs(chickenAmount, eggsAmount, fieldAmount, wheatAmount, flourAmount, nutAmount);
	GoapSolver goap;

	goap.CreateSolver();

	//The game
	while (gs.GetPancakeAmount() < 10)
	{
		std::cout << std::endl;
		std::cout << "----------------------------" << std::endl;
		std::cout << "----------Pancake " << gs.GetPancakeAmount() + 1 << "---------" << std::endl;
		std::cout << "----------------------------" << std::endl;

		//Goap do his job
		goap.Solve(&gs);
		goap.ExecuteActions(&gs);

		Sleep(1000);
	}

	return 0;
}