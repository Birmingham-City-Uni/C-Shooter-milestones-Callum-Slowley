#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "GameLoop.h"

class Animations {
public:
	static SDL_Texture* LoadTexture(const char* filename);
	static void Draw(SDL_Texture* texture, SDL_Rect pos,int animationFrame, int framesPerRow);

};