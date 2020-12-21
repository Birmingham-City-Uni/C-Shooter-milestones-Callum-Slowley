#include "Enemy.h"

Enemy::Enemy()
{
	//enemy pos and scale 
	enemyTexture = TextureManager::LoadTexture("Enemy.png");
	src.x = 0;
	src.y = 0;
	src.w = 32;
	src.h = 32;
	pos.w = 32;
	pos.h = 32;
	speed = 2;
	ypos = true;
}

Enemy::~Enemy()
{
}


void Enemy::update(int map[20][25])
{
	//used for collions on the map
	int oldX = this->pos.x;
	int oldY = this->pos.y;
	if (ypos==true) {
		pos.y += speed;
	}
	if (ypos==false) {
		pos.y -= speed;
	}

	if (pos.y >= 18 * 32) {
		ypos = false;
	}
	if (pos.y <= 64) {
		ypos = true;
	}

	//checking if the Enemy collides with tiles that are set that you cant move through them
	SDL_Rect enemyPos = { this->pos.x,this->pos.y,32,32 };
	//goes through my whole map and checks to see if there is any impassible tiles
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			//if the tile value is greater the 0 its an impassible tile
			if (map[i][j] > 0)
			{
				SDL_Rect mapTile = { j * 32,i * 32,32,32 };
				//if col occours Enemy old pos is rest
				if (SDL_HasIntersection(&enemyPos, &mapTile))
				{
					this->pos.x = oldX;
					this->pos.y = oldY;
				}
			}
		}
	}
}

void Enemy::draw()
{
	//the Enemy is drawn
	TextureManager::Draw(enemyTexture, src, pos);
}

void Enemy::clean()
{
	SDL_DestroyTexture(this->enemyTexture);
}
