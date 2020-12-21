#include "WaveManager.h"

WaveManager::WaveManager()
{
}

WaveManager::~WaveManager()
{
}

void WaveManager::Update()
{
	if ((SDL_GetTicks() - timeSinceLastSpawn) > spawnTimes)
	{
		currentWave++;
		for (int i = 0; i < currentWave; i++) {
			em->spawning();
		}
		timeSinceLastSpawn = SDL_GetTicks();
	}
}
