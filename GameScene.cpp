#include "GameScene.h"

GameScene::GameScene()
{
	nextScene = -1;
}
bool GameScene::loadMedia()
{
	return true;
}

void GameScene::update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed)
{

}

void GameScene::draw(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}