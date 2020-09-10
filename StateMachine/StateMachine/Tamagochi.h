#pragma once
#include <string>
#include "GameState.h"

class Tamagochi
{
	std::string name;

	int currentHunger;
	int currentThirst;
	bool isAlive;

public:
	Tamagochi(std::string s);
	~Tamagochi() {};

	void Drink(GameState* const gs);
	void Eat(GameState* const gs);
	void Die();

	bool IsAlive()const { return isAlive; }
	const int GetCurrentHunger()const { return currentHunger; }
	const int GetCurrentThirst()const { return currentThirst; }

	void UpdateStats();
	void DisplayStats()const;
};