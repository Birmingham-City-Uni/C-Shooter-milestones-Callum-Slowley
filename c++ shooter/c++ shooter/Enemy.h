#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "GameLoop.h"

class Enemy {
public:
	Enemy();
	~Enemy();
	void init();
	void update(int map[20][25]);
	void draw();
	void clean();

private:
	SDL_Texture* enemyTexture;
	SDL_Rect src;
	SDL_Rect pos;
	int speed;
	int maxHealth;
	int currentHealth;
	bool canSplit;
};