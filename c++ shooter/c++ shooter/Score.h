#pragma once
#include <SDL_ttf.h>
#include <SDL.h>
#include <string>

class Score {
public:
	Score( int fontSize, SDL_Renderer* renderer);

	void update();
	void draw(int x, int y)const;
	void clear();

	static SDL_Texture* loadFont( int fontSize, std::string& scoreValue, SDL_Renderer* renderer);
private:
	int fontSize;
	SDL_Renderer* renderer;
	SDL_Texture* scoreTexture = nullptr;
	SDL_Rect scoreRect;
	int scoreValue;
	std::string scoreText;
};