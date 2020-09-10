#pragma once

class GameState {
	int foodAmount;
	int waterAmount;

public:
	GameState();
	GameState(int f, int w);

	const int getFoodAmount()const { return foodAmount; }
	const int getWaterAmount()const { return waterAmount; }

	void setFoodAmount(const int f) { foodAmount = f; }
	void setDrinkAmount(const int w) { waterAmount = w; }

	void DisplayResources()const;
};


