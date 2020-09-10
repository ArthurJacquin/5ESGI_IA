#pragma once

class Tamagochi
{
	float maxHunger;
	float maxThirst;

	float currentHunger;
	float currentThirst;
	bool isAlive;

public:
	Tamagochi();

	void Drink();
	void Eat();
	void Die();

	bool IsAlive()const { return isAlive; }
	float GetCurrentHunger()const { return currentHunger; }
	float GetCurrentThirst()const { return currentThirst; }
};