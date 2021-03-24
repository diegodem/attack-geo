#pragma once
#include "Scene.h"

class GameOverScene : public Scene
{
public:
	GameOverScene() = default;
	GameOverScene(SDL_Renderer * renderer);
	void update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed) override;
	void draw() override;
};