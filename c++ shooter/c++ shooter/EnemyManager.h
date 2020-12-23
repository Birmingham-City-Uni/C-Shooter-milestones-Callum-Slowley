#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "Enemy.h"
#include "BulletManager.h"
#include "AudioManager.h"

class EnemyManager
{
public:
	EnemyManager(BulletManager* bm,AudioManager*am);
	~EnemyManager();
	void spawning();
	void update();
	void draw();
	vector<Enemy> enemyArray;
private:
	BulletManager* bm;
	AudioManager* am;
};

