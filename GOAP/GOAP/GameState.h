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

	void CookPancake(int n);
	void AddMixedEggs(int n);
	void AddMixedFlour(int n);
	void AddMixedNut(int n);
	void CollectEggs(int n);
	void AddChicken(int n);
	void BuyEggs(int n);
	void GrindFlour(int n);
	void HarvestWheat(int n);
	void AddField(int n);
	void BuyFlour(int n);
	void BuyNut(int n);
};