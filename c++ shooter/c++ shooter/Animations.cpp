#include "Animations.h"

SDL_Texture* Animations::LoadTexture(const char* filename)
{
    SDL_Surface* surface = SDL_LoadBMP(filename);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(GameLoop::renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void Animations::Draw(SDL_Texture* texture, SDL_Rect pos,int animationFrame,int framesPerRow)
{
    int animationX = 32 * (animationFrame % framesPerRow);
    int animationY = 32 * (animationFrame / framesPerRow);
    SDL_Rect src = { animationX,animationY,32,32 };
    SDL_RenderCopy(GameLoop::renderer, texture, &src, &pos);
}
