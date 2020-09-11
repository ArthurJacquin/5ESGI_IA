#include "GameState.h"
#include <cstdlib>

GameState::GameState()
	:eggsAmount(0), flourAmount(0), nutAmount(0), chickenAmount(4), fieldAmount(4), wheatAmount(0),
	mixedEggsAmount(0), mixedFlourAmount(0), mixedNutAmount(0), pancakeAmount(0)
{
}

GameState::GameState(int chicken, int eggs, int fieldAmount, int wheat, int flour, int nut)
	:eggsAmount(eggs), flourAmount(flour), nutAmount(nut), chickenAmount(chicken), fieldAmount(fieldAmount), wheatAmount(wheat), mixedEggsAmount(0), mixedFlourAmount(0), mixedNutAmount(0), pancakeAmount(0)
{
}

void GameState::CookPancake(int n)
{
	mixedEggsAmount -= n;
	mixedFlourAmount -= n;
	mixedNutAmount -= n;
	pancakeAmount += n;
	
	std::cout << "Cooking Pancake :" << std::endl;
	std::cout << "-" << n << " Mixed Egg" << std::endl;
	std::cout << "-" << n << " Mixed Flour" << std::endl;
	std::cout << "-" << n << " Mixed Nut" << std::endl;
	std::cout << "+" << n << " Pancake" << std::endl; 
	std::cout << "----------------------------------------------------" << std::endl << std::endl;
}

void GameState::AddMixedEggs(int n)
{
	eggsAmount -= n;
	mixedEggsAmount += n;

	std::cout << "Mix Eggs :" << std::endl;
	std::cout << "-" << n << " Egg" << std::endl;
	std::cout << "+" << n << " Mixed Egg" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl << std::endl;
}

void GameState::AddMixedFlour(int n)
{
	flourAmount -= n;
	mixedFlourAmount += n;

	std::cout << "Mix Flour :" << std::endl;
	std::cout << "-" << n << " Flour" << std::endl;
	std::cout << "+" << n << " Mixed Flour" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl << std::endl;
}

void GameState::AddMixedNut(int n)
{
	nutAmount -= n;
	mixedNutAmount += n;

	std::cout << "Mix Nut :" << std::endl;
	std::cout << "-" << n << " Nut" << std::endl;
	std::cout << "+" << n << " Mixed Nut" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl << std::endl;
}

void GameState::CollectEggs(int n)
{
	chickenAmount -= n;
	eggsAmount += n;

	std::cout << "Collect Eggs :" << std::endl;
	std::cout << "-" << n << " Chicken" << std::endl;
	std::cout << "+" << n << " Egg" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl << std::endl;
}

void GameState::AddChicken(int n)
{
	chickenAmount += n;
	std::cout << "+" << n << " Chicken" << std::endl;
}

void GameState::BuyEggs(int n)
{
	eggsAmount += n;

	std::cout << "Buy Eggs :" << std::endl;
	std::cout << "+" << n << " Egg" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl << std::endl;
}

void GameState::GrindFlour(int n)
{
	wheatAmount -= n;
	flourAmount += n;

	std::cout << "Grind Flour :" << std::endl;
	std::cout << "-" << n << " Wheat" << std::endl;
	std::cout << "+" << n << " Flour" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl << std::endl;
}

void GameState::HarvestWheat(int n)
{
	fieldAmount -= n;
	wheatAmount += n;

	std::cout << "Harvest Wheat :" << std::endl;
	std::cout << "-" << n << " Field" << std::endl;
	std::cout << "+" << n << " Wheat" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl << std::endl;
}

void GameState::AddField(int n)
{
	fieldAmount += n;

	std::cout << "+" << n << " Field" << std::endl;
}

void GameState::BuyFlour(int n)
{
	flourAmount += n;

	std::cout << "Buy Flour :" << std::endl;
	std::cout << "+" << n << " Flour" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl << std::endl;
}

void GameState::BuyNut(int n)
{
	nutAmount += n;

	std::cout << "Buy Nut :" << std::endl;
	std::cout << "+" << n << " Nut" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl << std::endl;
}

