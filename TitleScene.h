#pragma once
#include <vector>
#include "Scene.h"

class TitleScene : public Scene
{
public:
	TitleScene();
	bool loadMedia() override;
	void update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed) override;
	void draw(SDL_Renderer *renderer) override;
};