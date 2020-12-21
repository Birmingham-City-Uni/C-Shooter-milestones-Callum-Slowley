#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "Enemy.h"

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();
	void spawning();
	void update();
	void draw();
private:
	vector<Enemy> enemyArray;
};

