#include "TextureManager.h"
#include <SDL_image.h>

SDL_Texture* TextureManager::LoadTexture(const char* filename)
{
    SDL_Surface* surface = IMG_Load(filename);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(GameLoop::renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect pos)
{
    SDL_RenderCopy(GameLoop::renderer, texture, &src, &pos);
}
