#pragma once

class GameState {
	int foodAmount;
	int waterAmount;
	int musicVolume;

public:
	GameState();
	GameState(int f, int w, int v = 0);

	const int getFoodAmount()const { return foodAmount; }
	const int getWaterAmount()const { return waterAmount; }
	const int getMusicVolume()const { return musicVolume; }

	void setFoodAmount(const int f) { foodAmount = f; }
	void setDrinkAmount(const int w) { waterAmount = w; }
	void setMusicVolume(const int v) { musicVolume = v; }

	void DisplayResources()const;
};


