#include "EnemyManager.h"
#include "Enemy.h"
#include "WaveManager.h"
#include "Map.h"
extern Map* map;
extern WaveManager* wm;

EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::spawning()
{
	// new enemy is created its x and y values are set then added to the vector array
	Enemy newEnemy;
	newEnemy.pos.x = rand() % (12 * 32)+(6*32) ;
	newEnemy.pos.y = 64;
	//push_back adds an new item to the end of the vector
	enemyArray.push_back(newEnemy);
}

void EnemyManager::update()
{
	//used to check if the array is empty if it is it stops the whole function
	if (enemyArray.size() == 0) 
	{
		wm->nextWave = true;
		return;
	}
	//itterating through all elements in the array so that they all update
	for (int i=0; i < enemyArray.size(); i++)
	{
		enemyArray[i].update(map->map);
	}

}

void EnemyManager::draw()
{
	//itterating through all elements in the array so that they all draw to the screen
	for (int i=0; i < enemyArray.size(); i++)
	{
		enemyArray[i].draw();
	}
}
