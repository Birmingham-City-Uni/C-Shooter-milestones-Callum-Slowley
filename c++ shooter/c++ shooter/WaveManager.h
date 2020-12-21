#pragma once
#include "EnemyManager.h"
class WaveManager
{
public:
	WaveManager();
	~WaveManager();
	void Update();
	EnemyManager* em;

private:
	int currentWave = 0;
	int spawnTimes = 1000;
	int timeSinceLastSpawn = 0;
	bool nextWave;
};
