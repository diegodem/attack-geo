#include "GameOverScene.h"

GameOverScene::GameOverScene(SDL_Renderer *renderer)
{
	nextScene = -1;
	this->renderer = renderer;
}

void GameOverScene::update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed)
{
	for (int i = 0; i < keysPressed.size(); i++)
	{
		if (keysPressed[i] == SDLK_SPACE)
		{
			nextScene = (int)SceneList::GAME_SCENE;
		}
	}
}

void GameOverScene::draw()
{
	SDL_SetRenderDrawColor(renderer, 0x88, 0x88, 0x88, 0xFF);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}