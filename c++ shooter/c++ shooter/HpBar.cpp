#pragma once
#include "HpBar.h"
#include "GameLoop.h"
#include <SDL.h>
#include "Player.h"
extern GameLoop* gameLoop;
extern Player* player;

HpBar::HpBar()
{
}

HpBar::~HpBar()
{
}

void HpBar::draw()
{
	//creating the background
	SDL_Rect background = { 0,32,5*32,25 };
	//drawing the color and rect through the main renderer
	SDL_SetRenderDrawColor(gameLoop->renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(gameLoop->renderer, &background);
	//setting the width for the player hp bar and setting incrments
	float unitFactor = (float)(5 * 32) / player->maxHp;
	int hpWidth = player->currentHp * unitFactor;
	//drawning the player hp bar through the main renderer
	SDL_Rect healthBar = { 0,32,hpWidth,25 };
	SDL_SetRenderDrawColor(gameLoop->renderer, 184, 238, 0, 255);
	SDL_RenderFillRect(gameLoop->renderer, &healthBar);
}
