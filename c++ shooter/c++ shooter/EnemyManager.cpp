
#include "EnemyManager.h"
#include "Enemy.h"
#include "WaveManager.h"
#include "Map.h"
#include "BulletManager.h"
#include <windows.h> 
#include<iostream>
#include <SDL_audio.h>

extern Map* map;
extern WaveManager* wm;
extern Player* player;
extern Score* score;


EnemyManager::EnemyManager(BulletManager* newbm,AudioManager*em)
{
	bm = newbm;
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

		if (enemyArray[i].boundingSphere->CollisionWithSphere(*player->boundingSphere)) {
			cout << "collison with player ";
			player->hit= true;

		}
	}
	auto remove = std::remove_if(enemyArray.begin(), enemyArray.end(), [](const Enemy& e)
		{ 
			
			return e.boundingSphere->CollisionWithSphere(*player->boundingSphere); 
		});

	enemyArray.erase(remove, enemyArray.end());
	for (int i = 0; i < bm->bullets.size(); i++) {
		for (int j = 0; j < enemyArray.size(); j++) {
			SDL_Rect bulletRect = { bm->bullets[i].x,bm->bullets[i].y,10,10 };
			SDL_Rect enemyRect = { enemyArray[j].pos.x,enemyArray[j].pos.y,32,32 };
			SDL_Rect nullRect;
			if (SDL_IntersectRect(&bulletRect, &enemyRect, &nullRect)) {;
				bm->bullets[i].distance = 1000;
				int enenmyX = enemyArray[j].pos.x;
				enemyArray[j].pos.x = 0xCCCCCCCC; //checked later
				score->scoreValue += 10;
				PlaySound(TEXT("Hit.wav"), NULL, SND_ASYNC);
				//spliting the enermy if they can split;
				if (enemyArray[j].canSplit) {

					std::cout << "SPLIT" << endl;
					//done twice so the enermy splits in 2

					// new enemy is created its x and y values are set then added to the vector array
					Enemy split1;
					split1.pos.x = enenmyX + 32;
					//used to keep in bounds
					if (split1.pos.x > 12 * 32) {
						split1.pos.x = 12 * 32;
					}
					split1.pos.y = enemyArray[j].pos.y;
					//push_back adds an new item to the end of the vector
					enemyArray.push_back(split1);

					// new enemy is created its x and y values are set then added to the vector array
					Enemy split2;
					split2.pos.x = enenmyX - 32;
					split2.pos.y = enemyArray[j].pos.y;
					//used to keep in bounds
					if (split2.pos.x < 6 * 32) {
						split2.pos.x = 6 * 32;
					}
					//push_back adds an new item to the end of the vector
					enemyArray.push_back(split2);

				}
			}
		}
	}
	auto eRemove = std::remove_if(enemyArray.begin(), enemyArray.end(), [](const Enemy& e) {return e.pos.x == 0xCCCCCCCC; });
	enemyArray.erase(eRemove, enemyArray.end());

}

void EnemyManager::draw()
{
	//itterating through all elements in the array so that they all draw to the screen
	for (int i=0; i < enemyArray.size(); i++)
	{
		enemyArray[i].draw();
	}
}
