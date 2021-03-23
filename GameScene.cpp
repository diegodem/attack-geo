#include "GameScene.h"

GameScene::GameScene(SDL_Renderer *renderer)
{
	nextScene = -1;
	rect1 = { 928, 192, 96, 96 };
	rect2 = { 928, 480, 96, 96 };
	this->renderer = renderer;
	loadMedia();

}


void GameScene::update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed)
{
	rect1.x = rect1.x - 4 * (int)(125.f * deltaTime.getTime());

	rect2.x = rect2.x - 4 * (int)(125.f * deltaTime.getTime());

}

void GameScene::draw()
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	//SDL_RenderFillRect(renderer, &rect1);
	SDL_RenderCopy(renderer, textureGeo[0], NULL, &rect1);
	//SDL_RenderFillRect(renderer, &rect2);
	SDL_RenderCopy(renderer, textureGeo[1], NULL, &rect2);
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

	textureGeo[1] = loadTexture("Sprites/square.png");
	if (textureGeo[1] == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}

	textureGeo[2] = loadTexture("Sprites/pentagon.png");
	if (textureGeo[2] == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}

	textureGeo[3] = loadTexture("Sprites/hexagon.png");
	if (textureGeo[3] == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}

	textureGeo[4] = loadTexture("Sprites/heptagon.png");
	if (textureGeo[4] == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}

	textureGeo[5] = loadTexture("Sprites/octogon.png");
	if (textureGeo[5] == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}

	textureGeo[6] = loadTexture("Sprites/eneagon.png");
	if (textureGeo[6] == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}

	textureGeo[7] = loadTexture("Sprites/decagon.png");
	if (textureGeo[7] == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}

	textureGeo[8] = loadTexture("Sprites/hendecagon.png");
	if (textureGeo[8] == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}

	textureGeo[9] = loadTexture("Sprites/dodecagon.png");
	if (textureGeo[9] == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	return true;
}

