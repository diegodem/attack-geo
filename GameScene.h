#pragma once
#include "Scene.h"
#include <time.h>

class GameScene : public Scene
{
public:
	GameScene() = default;
	GameScene(SDL_Renderer *renderer);
	bool loadMedia() override;
	void update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed) override;
	void draw() override;
	void generateFigures();
	void moveUp();
	void moveDown();
	static bool checkCollision(SDL_Rect *rectA, SDL_Rect *rectB);
private:
	SDL_Rect rect1;
	SDL_Rect rect2;
	SDL_Rect rectPlayer;
	SDL_Texture *textureGeo[10] = { 0 };
	int energyPlayer;
	int energy1;
	int energy2;
	Timer spawnTimer;
	bool spawnTimerStarted;
	int level;
};