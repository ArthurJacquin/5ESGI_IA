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
	GameState(const int chickenAmount, const int eggsAmount, const int fieldAmount, const int wheatAmount, const int flourAmount, const int nutAmount);

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

	void CookPancake(const int n);
	void AddMixedEggs(const int n);
	void AddMixedFlour(const int n);
	void AddMixedNut(const int n);
	void CollectEggs(const int n);
	void AddChicken(const int n);
	void BuyEggs(const int n);
	void GrindFlour(const int n);
	void HarvestWheat(const int n);
	void AddField(const int n);
	void BuyFlour(const int n);
	void BuyNut(const int n);
};