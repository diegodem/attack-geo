#pragma once
#include <SDL.h>
#include <stdlib.h>
#include <algorithm>
#include "Timer.h"

class Shape
{
public:
	Shape() = default;
	Shape(int playerEnergy, int position);
	SDL_Rect *getRect();
	int getEnergy();
	Timer getSpawnTimer();
	float getSpawnTime();
	float spawnTime;
	void spawned();
private:
	SDL_Rect rect;
	int energy;
	Timer spawnTimer;
	bool spawnTimerStarted;
};