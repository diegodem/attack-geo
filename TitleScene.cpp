#include "TitleScene.h"

TitleScene::TitleScene()
{
	nextScene = -1;
}

bool TitleScene::loadMedia()
{
	return true;
}

void TitleScene::update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed)
{
	for (int i = 0; i < keysPressed.size(); i++)
	{
		if (keysPressed[i] == SDLK_SPACE)
		{
			nextScene = (int)SceneList::GAME_SCENE;
		}
	}
}

void TitleScene::draw(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0x88, 0x88, 0x88, 0xFF);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}