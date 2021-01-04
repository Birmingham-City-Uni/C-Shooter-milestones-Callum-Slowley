#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Sphere.h"
#include "GameLoop.h"

class Enemy {
public:
	Enemy();
	~Enemy();
	void init();
	void update(int map[20][25]);
	void draw();
	void clean();
	//temp
	bool ypos;
	SDL_Rect pos;
	Sphere* boundingSphere;
	bool canSplit;

private:
	SDL_Texture* enemyTexture;
	SDL_Rect src;
	int speed;
	int maxHealth;
	int currentHealth;
};