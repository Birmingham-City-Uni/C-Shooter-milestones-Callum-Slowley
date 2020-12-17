#include "Map.h"
#include <SDL_image.h>
#include "TextureManager.h"
#include "Animations.h"

//map data
int level1[20][25] = {
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{2,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,2},
	{2,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,2},
	{2,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,2},
	{2,4,4,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,2},
	{2,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,2},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,2},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{2,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,2},
	{2,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,2},
	{2,4,4,4,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,4,4,4,2},
	{2,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,2},
	{2,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
};
Map::Map()
{
	//textures loaded
	grass = TextureManager::LoadTexture("Grass.png");
	wall = TextureManager::LoadTexture("Wall.png");
	wallTop = TextureManager::LoadTexture("WallTop.png");
	chest = TextureManager::LoadTexture("chest.png");
	waves = Animations::LoadTexture("waves.bmp");

	//animation frame is set to 0, and width set;
	animationFrame = 0;
	framesPerRow = 31;
	//level loaded
	Load(level1);
	//used for pos and scale
	src.x = 0;
	src.y = 0;
	src.w = 32;
	src.h = 32;
	pos.w = 32;
	pos.h = 32;
}

Map::~Map()
{
}

//map being loaded
void Map::Load(int arr[20][25])
{
	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 25; column++) {
			map[row][column] = arr[row][column];
		}
	}
}

void Map::Draw()
{
	//drawing the map using switch cases
	int tile = 0;

	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 25; column++) {
			tile = map[row][column];
			pos.x = column * 32;
			pos.y = row * 32;

			switch (tile) {
			case 0:
				TextureManager::Draw(grass, src, pos);
				break;
			case 1:
				TextureManager::Draw(wall, src, pos);
				break;
			case 2:
				TextureManager::Draw(wallTop, src, pos);
				break;
			case 3:
				TextureManager::Draw(chest, src, pos);
				break;
			case 4:
				Animations::Draw(waves, pos, animationFrame, framesPerRow);
			}
		}
	}
}

void Map::Update()
{
	//update used to set the speed of the animation
	if (SDL_GetTicks() - lastFrame < 50) {
		return;
	}
	lastFrame = SDL_GetTicks();
	animationFrame++;
	if (animationFrame >= 31) {
		animationFrame = 0;
	}
}

