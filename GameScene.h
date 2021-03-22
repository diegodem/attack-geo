#pragma once
#include "Scene.h"

class GameScene : public Scene
{
public:
	GameScene();
	bool loadMedia() override;
	void update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed) override;
	void draw(SDL_Renderer *renderer) override;
};