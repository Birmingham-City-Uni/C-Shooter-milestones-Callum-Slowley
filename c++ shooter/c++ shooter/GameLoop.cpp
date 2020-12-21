#include "GameLoop.h"
#include "Map.h"
#include "Player.h"
#include "Score.h"
#include "EnemyManager.h"
#include "WaveManager.h"
#include <iostream>
#include <SDL_ttf.h>

SDL_Renderer* GameLoop::renderer = nullptr;
Map* map;
Player* player;
Score* score;
EnemyManager* em;
WaveManager* wm;


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
	if (TTF_Init()==-1) {
		std::cerr << "Could not initalise SDL.ttf: " << SDL_GetError();
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
	
	string scoreVal = "Score: ";
	score = new Score( 30,GameLoop::renderer);
	map = new Map();
	player = new Player();
	em = new EnemyManager();
	wm = new WaveManager();
	wm->em = em;
	bm = new BulletManager();
	//done with the player icon so its easier to see for now
	bm->init(TextureManager::LoadTexture("Player.png"));
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
	float angle = player->getAngle();
	bm->processInput(keyDown, angle, player->getX(), player->getY());
	return true;
}

void GameLoop::update()
{
	map->Update();
	player->update(map->map);
	em->update();
	wm->Update();
	score->update();
	bm->update();
	SDL_RenderClear(GameLoop::renderer);
}

void GameLoop::draw()
{
	SDL_RenderClear(GameLoop::renderer);
	map->Draw();
	player->draw();
	em->draw();
	score->draw(20,20);
	bm->draw(GameLoop::renderer);
	SDL_RenderPresent(GameLoop::renderer);
	SDL_Delay(16);
}

void GameLoop::clean() {
	player->clean();
	score->clear();
	bm->clean();
}
