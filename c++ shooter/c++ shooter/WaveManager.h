#pragma once
#include "EnemyManager.h"
class WaveManager
{
public:
	WaveManager();
	~WaveManager();
	void Update();
	EnemyManager* em;
	//placed in public to be used by the enermy manager
	//set to false to test if the update is working
	bool nextWave = false;

private:
	int currentWave = 0;
	int spawnTimes = 1000;
	int timeSinceLastSpawn = 0;
};
