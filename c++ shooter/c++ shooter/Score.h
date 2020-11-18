#pragma once
#include <SDL_ttf.h>
#include <SDL.h>
#include <string>

class Score {
public:
	Score(const std::string& fontPath, int fontSize, std::string& scoreValue, const SDL_Color& color);

	void draw(int x, int y)const;
	void clear();

	static SDL_Texture* loadFont(const std::string& fontPath, int fontSize, std::string& scoreValue, const SDL_Color& color);
private:
	SDL_Texture* scoreTexture = nullptr;
	SDL_Rect scoreRect;
};