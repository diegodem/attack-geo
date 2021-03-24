#include "GameScene.h"

GameScene::GameScene(SDL_Renderer *renderer)
{
	nextScene = -1;
	rect1 = { -96, 192, 96, 96 };
	rect2 = { -96, 480, 96, 96 };
	rectPlayer = { 96, 336, 96, 96 };
	this->renderer = renderer;
	loadMedia();
	srand(time(NULL));
	spawnTimerStarted = false;
	energy1 = 0;
	energy2 = 0;
	energyPlayer = 1;
	level = 1;

}


void GameScene::update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed)
{
	for (int i = 0; i < keysPressed.size(); i++)
	{
		if (keysPressed[i] == SDLK_UP)
		{
			moveUp();
		}
		else if (keysPressed[i] == SDLK_DOWN)
		{
			moveDown();
		}
	}
	rect1.x = rect1.x - (3 + level) * (int)(125.f * deltaTime.getTime());

	rect2.x = rect2.x - (3 + level) * (int)(125.f * deltaTime.getTime());
	if (rect1.x < 0)
	{
		if (!spawnTimerStarted)
		{
			spawnTimer.start();
			spawnTimerStarted = true;
		}
		else if (spawnTimer.getTime() > 1.f)
		{
			generateFigures();
			spawnTimerStarted = false;
		}

		
	}

	if (checkCollision(&rectPlayer, &rect1))
	{
		if (energyPlayer > energy1)
		{
			energyPlayer++;
			rect1.x = -96;
		}
		else if (energyPlayer < energy1)
		{
			energyPlayer--;
			rect1.x = -96;
		}
	}

	if (checkCollision(&rectPlayer, &rect2))
	{
		if (energyPlayer > energy2)
		{
			energyPlayer++;
			rect2.x = -96;
		}
		else if (energyPlayer < energy2)
		{
			energyPlayer--;
			rect2.x = -96;
		}
	}

	if (energyPlayer == 10)
	{
		level++;
		energyPlayer = 1;
	}
	if (energyPlayer < 1)
	{
		nextScene = (int)SceneList::GAME_OVER_SCENE;
	}
	

}

void GameScene::draw()
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	//SDL_RenderFillRect(renderer, &rect1);
	SDL_RenderCopy(renderer, textureGeo[energy1], NULL, &rect1);
	//SDL_RenderFillRect(renderer, &rect2);
	SDL_RenderCopy(renderer, textureGeo[energy2], NULL, &rect2);

	SDL_RenderCopy(renderer, textureGeo[energyPlayer], NULL, &rectPlayer);
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

void GameScene::generateFigures()
{
	energy1 = rand() % std::min(energyPlayer + 3, 10);
	energy2 = rand() % std::min(energyPlayer + 3, 10);
	rect1.x = 1024;
	rect2.x = 1024;

}

void GameScene::moveUp()
{
	if (rectPlayer.y > 192)
	{
		rectPlayer.y -= 144;
	}
}

void GameScene::moveDown()
{
	if (rectPlayer.y < 480)
	{
		rectPlayer.y += 144;
	}
}

bool GameScene::checkCollision(SDL_Rect *rectA, SDL_Rect *rectB)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = rectA->x;
	rightA = rectA->x + rectA->w;
	topA = rectA->y;
	bottomA = rectA->y + rectA->h;

	leftB = rectB->x;
	rightB = rectB->x + rectB->w;
	topB = rectB->y;
	bottomB = rectB->y + rectB->h;

	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	return true;
}

