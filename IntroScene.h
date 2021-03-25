#pragma once
#include "Scene.h"

class IntroScene : public Scene
{
public:
	IntroScene() = default;
	IntroScene(SDL_Renderer *renderer);
	bool loadMedia() override;
	void update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed) override;
	void draw() override;
	void close() override;
private:
	SDL_Texture *backgroundTexture = NULL;
};