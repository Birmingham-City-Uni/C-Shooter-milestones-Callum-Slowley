#include "Score.h"
#include "GameLoop.h"
#include <iostream>

Score::Score(const std::string& fontPath, int fontSize, std::string& scoreValue, const SDL_Color& color, SDL_Renderer* renderer)
{
	TTF_Init();
	scoreTexture = loadFont(fontPath, fontSize, scoreValue, color, renderer);
	SDL_QueryTexture(scoreTexture, nullptr, nullptr, &scoreRect.w, &scoreRect.h);
}

void Score::draw(int x, int y) const
{
	SDL_RenderCopy(GameLoop::renderer, scoreTexture, nullptr, &scoreRect);
}

void Score::clear()
{
	SDL_DestroyTexture(scoreTexture);
}

SDL_Texture* Score::loadFont(const std::string& fontPath, int fontSize, std::string& scoreValue, const SDL_Color& color, SDL_Renderer* renderer)
{
	TTF_Font* font = TTF_OpenFont(fontPath.c_str(), fontSize);
	if (!font) {
		std::cerr << "font failed to load: " <<  SDL_GetError() << "\n";
	}
	auto scoreSurface = TTF_RenderText_Solid(font, scoreValue.c_str(), color);
	if (!scoreSurface) {
		std::cerr << " failed to create a surface" << SDL_GetError() << "\n";
	}
	auto scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
	if (!scoreTexture) {
		std::cerr << " failed to create a texture: "<< SDL_GetError() << "\n";
	}
	SDL_FreeSurface(scoreSurface);
	return scoreTexture;
}
