#pragma once

class GameState {
	int foodAmount;
	int waterAmount;

public:
	GameState();
	GameState(int f, int w);

	int getFoodAmount() { return foodAmount; }
	int getWaterAmount() { return waterAmount; }

	void setFoodAmount(int f) { foodAmount = f; }
	void setDrinkAmount(int w) { waterAmount = w; }

};


