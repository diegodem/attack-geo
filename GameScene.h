#pragma once
#include "Scene.h"
#include "Shape.h"
#include <time.h>

class GameScene : public Scene
{
public:
	GameScene() = default;
	GameScene(SDL_Renderer *renderer);
	bool loadMedia() override;
	void update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed) override;
	void draw() override;
	void generateFigure(int position);
	void moveUp();
	void moveDown();
	static bool checkCollision(SDL_Rect *rectA, SDL_Rect *rectB);
private:
	SDL_Rect rectPlayer;
	SDL_Texture *textureGeo[10] = { 0 };
	int energyPlayer;
	int level;
	Shape shapes[3];
	TTF_Font *generalFont = NULL;
	SDL_Rect levelRect;
	std::string levelStr;
	SDL_Color color;
	SDL_Surface *surfaceLevel = NULL;
	SDL_Texture *textureLevel = NULL;
	Mix_Chunk *changeSound = NULL;
	Mix_Chunk *hurtSound = NULL;
	Mix_Chunk *growSound = NULL;
	Mix_Chunk *levelUpSound = NULL;
};