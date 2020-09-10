#pragma once

class GameState
{
	int eggsAmount;
	int flourAmount;
	int nutAmount;
	int chickenAmount;
	int wheatAmount;
	int pancakeAmount;

public:
	GameState();
	GameState(int eggsAmount, int flourAmount, int nutAmount, int chickenAmount, int wheatAmount);

	const int GetEggsAmount()const { return eggsAmount; }
	const int GetFlourAmount()const { return flourAmount; }
	const int GetNutAmount()const { return nutAmount; }
	const int GetChickenAmount()const { return chickenAmount; }
	const int GetWheatAmount()const { return wheatAmount; }
	const int GetPancakeAmount()const { return pancakeAmount; }

	void AddEggs(int n) { eggsAmount += n; }
	void AddFlour(int n) { flourAmount += n; }
	void AddNut(int n) { nutAmount += n; }
	void AddChicken(int n) { chickenAmount += n; }
	void AddWheat(int n) { wheatAmount += n; }
	void AddPancake(int n) { pancakeAmount += n; }
};