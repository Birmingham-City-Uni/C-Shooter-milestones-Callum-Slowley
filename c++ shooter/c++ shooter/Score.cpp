#include "Score.h"
#include "GameLoop.h"
#include <iostream>

Score::Score( int newfontSize, SDL_Renderer* newrenderer)
{
	//used in update and loading
	fontSize = newfontSize;
	renderer = newrenderer;
	scoreValue = 0;
	scoreText = "Score: ";
	//Init so text can be displayed
	TTF_Init();
	//font is loaded
	scoreTexture = loadFont(fontSize, scoreText, renderer);
	SDL_QueryTexture(scoreTexture, nullptr, nullptr, &scoreRect.w, &scoreRect.h);
}

void Score::update()
{
	//score is updated over time 
	scoreValue++;
	scoreText = "Score: " +to_string(scoreValue);
	scoreTexture = loadFont(fontSize, scoreText, renderer);
}

void Score::draw(int x, int y) const
{
	//score is drawn
	SDL_RenderCopy(GameLoop::renderer, scoreTexture, nullptr, &scoreRect);
}

void Score::clear()
{
	//removed when not used
	SDL_DestroyTexture(scoreTexture);
}

SDL_Texture* Score::loadFont(int fontSize, std::string& scoreValue,SDL_Renderer* renderer)
{
	//font loaded
	TTF_Font* font = TTF_OpenFont("arial.ttf", fontSize);
	if (!font) {
		std::cerr << "font failed to load: " <<  SDL_GetError() << "\n";
	}
	//creating the surface
	auto scoreSurface = TTF_RenderText_Solid(font, scoreValue.c_str(), { 255,0,0,255 });
	if (!scoreSurface) {
		std::cerr << " failed to create a surface" << SDL_GetError() << "\n";
	}
	//texture created
	auto scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
	if (!scoreTexture) {
		std::cerr << " failed to create a texture: "<< SDL_GetError() << "\n";
	}
	SDL_FreeSurface(scoreSurface);
	return scoreTexture;
}
