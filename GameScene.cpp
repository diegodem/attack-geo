#include "GameScene.h"

GameScene::GameScene(SDL_Renderer *renderer)
{
	nextScene = -1;
	rect1 = { 928, 192, 96, 96 };
	rect2 = { 928, 480, 96, 96 };
	this->renderer = renderer;
}


void GameScene::update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed)
{
	rect1.x = rect1.x - 4 * (int)(125.f * deltaTime.getTime());

	rect2.x = rect2.x - 4 * (int)(125.f * deltaTime.getTime());

	printf("%f\n", deltaTime.getTime());
}

void GameScene::draw()
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, &rect1);
	SDL_RenderFillRect(renderer, &rect2);
	SDL_RenderPresent(renderer);
}

bool GameScene::loadMedia()
{
	bool success = true;

	textureGeo[0] = loadTexture("Sprites/triangle.png");
	if (textureGeo[0] == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	return true;
}

