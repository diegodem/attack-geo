#pragma once
#include <SDL.h>
#include <vector>
#include "SceneList.h"
#include "Timer.h"

class Scene
{
public:
	virtual bool loadMedia();
	virtual void update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed);
	virtual void draw(SDL_Renderer *renderer);
	int getNextScene();
protected:
	int nextScene;
};