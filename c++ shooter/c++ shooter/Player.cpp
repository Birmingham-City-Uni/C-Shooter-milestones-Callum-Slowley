#include "Player.h"
#include "TextureManager.h"

extern GameLoop* gameLoop;


Player::Player()
{
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
	
}

Player::~Player()
{
}

void Player::update()
{
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
	TextureManager::Draw(player, src, pos);
}

void Player::clean()
{
	SDL_DestroyTexture(this->player);
}