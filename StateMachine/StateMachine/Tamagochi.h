#pragma once
#include <string>
#include "GameState.h"

class Tamagochi
{
	std::string name;

	int maxHunger;
	int maxThirst;

	int currentHunger;
	int currentThirst;
	bool isAlive;

public:
	Tamagochi(std::string s);
	~Tamagochi() {};

	void Drink(GameState* gs);
	void Eat(GameState* gs);
	void Die();

	bool IsAlive()const { return isAlive; }
	const int GetCurrentHunger()const { return currentHunger; }
	const int GetCurrentThirst()const { return currentThirst; }

	const int GetMaxHunger()const { return maxHunger; }
	const int GetMaxThirst()const { return maxThirst; }

	void UpdateStats();
	void DisplayStats();
};