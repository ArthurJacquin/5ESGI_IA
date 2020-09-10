#pragma once

static struct ConstValues
{
	static const int maxHunger = 100;
	static const int maxThirst = 100;
	static const int hungerThreshold = 50;
	static const int thirstThreshold = 50;
	static const int hungerIncrement = 4;
	static const int thirstIncrement = 6;
	static const int hungerDecrementFromFood = 30;
	static const int thirstDecrementFromWater = 20;
};