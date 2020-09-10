#pragma once

class GameState {
	int foodAmount;
	int waterAmount;

	int hungerThreshold;
	int thirstThreshold;

public:
	GameState();
	GameState(int f, int w);

	int getFoodAmount()const { return foodAmount; }
	int getWaterAmount()const { return waterAmount; }
	int GetHungerThreshold()const { return hungerThreshold; }
	int GetThirstThreshold()const { return thirstThreshold; }

	void setFoodAmount(int f) { foodAmount = f; }
	void setDrinkAmount(int w) { waterAmount = w; }

};


