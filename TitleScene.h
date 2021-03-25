#pragma once
#include <vector>
#include "Scene.h"

class TitleScene : public Scene
{
public:
	TitleScene() = default;
	TitleScene(SDL_Renderer *renderer);
	bool loadMedia() override;
	void update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed) override;
	void draw() override;
private:
	SDL_Texture *backgroundTexture = NULL;
};