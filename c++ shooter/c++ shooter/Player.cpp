#include "Player.h"
#include "TextureManager.h"
#include "Sphere.h"
#include <vector>

extern GameLoop* gameLoop;
extern Score* score;
Player::Player()
{
	//player pos and scale 
	player = TextureManager::LoadTexture("Player.png");
	src.x = 0;
	src.y = 0;
	src.w = 32;
	src.h = 32;
	pos.w = 32;
	pos.h = 32;
	pos.x = 10*32;
	pos.y = 10*32;
	speed = 5;
	rotationAngle = 0.0f;
	hit = false;
	maxHp = 100;
	currentHp = maxHp;

	boundingSphere = new Sphere(pos.x + (pos.w / 2), pos.y + (pos.h / 2), pos.w / 2);
}

Player::~Player()
{
}

void Player::update(int map[20][25])
{
	//used for collions on the map
	int oldX= this->pos.x;
	int oldY = this->pos.y;

	//player moved based on what key is pressed
	if (gameLoop->getKeyDown(SDL_SCANCODE_RIGHT)) {
		this->pos.x += 1 * speed;
	}
	if (gameLoop->getKeyDown(SDL_SCANCODE_LEFT)) {
		this->pos.x -= 1* speed;
	}
	if (gameLoop->getKeyDown(SDL_SCANCODE_UP)) {
		this->pos.y -= 1* speed;
	}
	if (gameLoop->getKeyDown(SDL_SCANCODE_DOWN)) {
		this->pos.y += 1* speed;
	}

	this->boundingSphere->x = pos.x;
	this->boundingSphere->y = pos.y;

	//checking if the player collides with tiles that are set that you cant move through them
	SDL_Rect playerPos = { this->pos.x,this->pos.y,32,32 };
	//goes through my whole map and checks to see if there is any impassible tiles
	for(int i =0;i<20;i++)
	{
		for (int j = 0; j < 25; j++)
		{
			//if the tile value is greater the 0 its an impassible tile
			if (map[i][j] > 0)
			{
				SDL_Rect mapTile = { j * 32,i * 32,32,32 };
				//if col occours players old pos is rest
				if (SDL_HasIntersection(&playerPos, &mapTile)) 
				{
					//3 is set to the chest
					if (map[i][j] == 3) {
						score->scoreValue += 50;
						map[i][j] = 0;
					}

					this->pos.x = oldX;
					this->pos.y = oldY;

					this->boundingSphere->x = pos.x;
					this->boundingSphere->y = pos.y;
				}
			}
		}
	}
	if (hit) {
		currentHp -= 3;
		cout << "current HP: "<<currentHp;
		hit = false;
	}
}

void Player::draw()
{
	//the player is drawn
	TextureManager::Draw(player, src, pos);
}

void Player::clean()
{
	SDL_DestroyTexture(this->player);
}