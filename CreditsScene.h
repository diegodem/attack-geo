#pragma once
#include "Scene.h"

class CreditsScene : public Scene
{
public:
	CreditsScene() = default;
	CreditsScene(SDL_Renderer * renderer);
	bool loadMedia() override;
	void update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed) override;
	void draw() override;
private:
	SDL_Texture *backgroundTexture = NULL;
};