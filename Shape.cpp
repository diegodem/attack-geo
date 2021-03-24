#include "Shape.h"

Shape::Shape(int playerEnergy, int position)
{
	energy = rand() % std::min(playerEnergy + 3, 10);
	rect = { 100000, 192 + position * 144, 96, 96 };
	spawnTimerStarted = false;
	spawnTimer.start();
	spawnTime = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 2.f));
}

SDL_Rect *Shape::getRect()
{
	return &rect;
}

int Shape::getEnergy()
{
	return energy;
}

Timer Shape::getSpawnTimer()
{
	return spawnTimer;
}

float Shape::getSpawnTime()
{
	return spawnTime;
}

void Shape::spawned()
{
	spawnTime = 200.f;
}