#include "GameLoop.h"
#include "Map.h"
#include "Player.h"
#include <iostream>

SDL_Renderer* GameLoop::renderer = nullptr;
Map* map;
Player* player;

GameLoop::GameLoop() {
	window = nullptr;
	//renderer = nullptr;
	for (int i = 0; i < 512; i++) {
		keyDown[i] = false;
	}
}

bool GameLoop::init() {

	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "Could not initialise SDL: " << SDL_GetError();
		return false;
	}
	window = SDL_CreateWindow(
		"C++ Shooter",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		800, 640,
		SDL_WINDOW_SHOWN
	);

	if (!window) {
		std::cerr << "Could not create a window through SDL: " << SDL_GetError();
		return false;
	}

	//creates the renderer
	GameLoop::renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!GameLoop::renderer) {
		std::cout << "Error creating renderer:" << SDL_GetError() << std::endl;
		return false;
	}

	for (int i = 0; i < 512; i++) {
		keyDown[i] = false;
	}

	map = new Map();
	player = new Player();
	//bm = new BulletManager(player);
	//bm->init();
	return true;
}

bool GameLoop::processInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.scancode < 512) {
				keyDown[e.key.keysym.scancode] = true;
			}
		}
		else if (e.type == SDL_KEYUP) {
			if (e.key.keysym.scancode < 512) {
				keyDown[e.key.keysym.scancode] = false;
			}
		}
	}
	//bm->processInput(keyDown);
	return true;
}

void GameLoop::update()
{
	player->update();
	//bm->update();
	SDL_RenderClear(GameLoop::renderer);
}

void GameLoop::draw()
{
	SDL_RenderClear(GameLoop::renderer);
	map->Draw();
	player->draw();
	//bm->draw();
	SDL_RenderPresent(GameLoop::renderer);
	SDL_Delay(16);
}

void GameLoop::clean() {
	player->clean();
	//bm->clean();
}
