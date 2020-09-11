#pragma once

static struct ConstValues
{
	//max value of tamagochi stat
	static const int maxHunger = 100;
	static const int maxThirst = 100;
	static const int maxTiredness = 100;

	//threshold from which action are launch
	static const int hungerThreshold = 60;
	static const int thirstThreshold = 40;
	static const int tiredThreshold = 60;

	//tamagochi stats increment in gameplay loop
	static const int hungerIncrement = 4;
	static const int thirstIncrement = 6;
	static const int tiredIncrement = 2;

	//resources decrement in gameplay loop
	static const int hungerDecrementFromFood = 50;
	static const int thirstDecrementFromWater = 30;
	static const int tiredDecrementFromMusic = 55;
};