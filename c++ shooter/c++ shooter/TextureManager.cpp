#include "TextureManager.h"
#include <SDL_image.h>

SDL_Texture* TextureManager::LoadTexture(const char* filename, SDL_Renderer* render)
{
    SDL_Surface* surface = IMG_Load(filename);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(render, surface);
    SDL_FreeSurface(surface);
    return texture;
}
