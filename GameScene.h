#pragma once
#include "Scene.h"

class GameScene : public Scene
{
public:
	GameScene() = default;
	GameScene(SDL_Renderer *renderer);
	bool loadMedia() override;
	void update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed) override;
	void draw() override;
private:
	SDL_Rect rect1;
	SDL_Rect rect2;
	SDL_Texture *textureGeo[1] = { 0 };
};