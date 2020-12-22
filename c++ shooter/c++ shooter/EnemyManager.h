#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "Enemy.h"
#include "BulletManager.h"

class EnemyManager
{
public:
	EnemyManager( );
	~EnemyManager();
	void spawning();
	void update(vector<Bullet> bullets);
	void draw();
	vector<Enemy> enemyArray;
private:

};

