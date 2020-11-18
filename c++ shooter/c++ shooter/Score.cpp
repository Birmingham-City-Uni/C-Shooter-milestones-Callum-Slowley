#include "Score.h"
#include "GameLoop.h"
#include <iostream>

Score::Score(const std::string& fontPath, int fontSize, std::string& scoreValue, const SDL_Color& color)
{
	scoreTexture = loadFont(fontPath, fontSize, scoreValue, color);
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

SDL_Texture* Score::loadFont(const std::string& fontPath, int fontSize, std::string& scoreValue, const SDL_Color& color)
{
	TTF_Font* font = TTF_OpenFont(fontPath.c_str(), fontSize);
	if (!font) {
		std::cerr << "font failed to load \n";
	}
	auto scoreSurface = TTF_RenderText_Solid(font, scoreValue.c_str(), color);
	if (!scoreSurface) {
		std::cerr << " failed to create a surface \n";
	}
	auto scoreTexture = SDL_CreateTextureFromSurface(GameLoop::renderer, scoreSurface);
	if (!scoreTexture) {
		std::cerr << " failed to create a texture \n";
	}
	SDL_FreeSurface(scoreSurface);
	return scoreTexture;
}
