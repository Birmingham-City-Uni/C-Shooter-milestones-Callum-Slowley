#include "WaveManager.h"

WaveManager::WaveManager()
{
}

WaveManager::~WaveManager()
{
}

void WaveManager::Update()
{
	if ((SDL_GetTicks() - timeSinceLastSpawn) > spawnTimes && nextWave)
	{
		currentWave++;
		for (int i = 0; i < currentWave; i++) {
			em->spawning();
			nextWave = false;
		}
		timeSinceLastSpawn = SDL_GetTicks();
	}
}
