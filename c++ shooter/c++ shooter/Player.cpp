#include "Player.h"
#include "TextureManager.h"

extern GameLoop* gameLoop;


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
}

Player::~Player()
{
}

void Player::update()
{
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