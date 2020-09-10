#pragma once
#include <string>
#include "GameState.h"

class Tamagochi
{
	std::string name;

	float maxHunger;
	float maxThirst;

	float currentHunger;
	float currentThirst;
	bool isAlive;

public:
	Tamagochi(std::string s);
	~Tamagochi() {};

	void Drink(GameState* gs);
	void Eat(GameState* gs);
	void Die();

	bool IsAlive()const { return isAlive; }
	float GetCurrentHunger()const { return currentHunger; }
	float GetCurrentThirst()const { return currentThirst; }

	void UpdateStats();
	void DisplayStats();
};