#pragma once
#include <iostream>

class GameState
{
	int eggsAmount;
	int flourAmount;
	int nutAmount;
	int chickenAmount;
	int wheatAmount;
	int pancakeAmount;
	int mixedEggsAmount;
	int mixedFlourAmount;
	int mixedNutAmount;
	int fieldAmount;

public:
	GameState();
	GameState(int eggsAmount, int flourAmount, int nutAmount, int chickenAmount, int fieldAmount, int wheatAmount);

	const int GetEggsAmount()const { return eggsAmount; }
	const int GetFlourAmount()const { return flourAmount; }
	const int GetNutAmount()const { return nutAmount; }
	const int GetChickenAmount()const { return chickenAmount; }
	const int GetWheatAmount()const { return wheatAmount; }
	const int GetPancakeAmount()const { return pancakeAmount; }
	const int GetMixedEggsAmount()const { return mixedEggsAmount; }
	const int GetMixedFlourAmount()const { return mixedFlourAmount; }
	const int GetMixedNutAmount()const { return mixedNutAmount; }
	const int GetFieldAmount()const { return fieldAmount; }

	void AddEggs(int n) { eggsAmount += n; --chickenAmount; }
	void AddFlour(int n) { flourAmount += n; }
	void AddNut(int n) { nutAmount += n; }
	void AddChicken(int n) { chickenAmount += n; }
	void AddWheat(int n) { wheatAmount += n; --fieldAmount; }
	void AddPancake(int n) { std::cout << "Pancake !!!" << std::endl;  pancakeAmount += n; }
	void AddMixedEggs(int n) { mixedEggsAmount += n; }
	void AddMixedFlour(int n) { mixedFlourAmount += n; }
	void AddMixedNut(int n) { mixedNutAmount += n; }
	void AddField(int n) { fieldAmount += n; }

};