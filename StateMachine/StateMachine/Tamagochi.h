#pragma once
#include <string>
#include "GameState.h"

class Tamagochi
{
	std::string name;

	unsigned int currentHunger;
	unsigned int currentThirst;
	unsigned int currentTiredness;
	bool isAlive;

public:
	Tamagochi(std::string s);
	~Tamagochi() {};

	void Drink(GameState* const gs);
	void Eat(GameState* const gs);
	void Sleep(GameState* const gs);
	void StopMusic(GameState* const gs);
	void Debug(GameState* const gs);
	void Die();

	bool IsAlive()const { return isAlive; }
	const unsigned int GetCurrentHunger()const { return currentHunger; }
	const unsigned int GetCurrentThirst()const { return currentThirst; }
	const unsigned int GetCurrentTiredness() const { return currentTiredness; }

	void UpdateStats();
	void DisplayStats()const;
};