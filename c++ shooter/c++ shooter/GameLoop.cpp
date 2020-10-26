#include "GameLoop.h"

GameLoop::GameLoop() {

	window = nullptr;
	renderer = nullptr;
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
		1280, 768,
		SDL_WINDOW_SHOWN
	);

	if (!window) {
		std::cerr << "Could not create a window through SDL: " << SDL_GetError();
		return false;
	}

	//creates the renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		std::cout << "Error creating renderer:" << SDL_GetError() << std::endl;
		return false;
	}

	for (int i = 0; i < 512; i++) {
		keyDown[i] = false;
	}

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
	return true;
}
void GameLoop::update()
{
	SDL_RenderClear(renderer);
}

void GameLoop::draw()
{
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(16);
}

void GameLoop::clean() {

}
