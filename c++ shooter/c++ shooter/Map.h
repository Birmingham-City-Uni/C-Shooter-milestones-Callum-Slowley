#pragma once
#include <SDL.h>

class Map {
public:
	//map constructor and destructor
	Map();
	~Map();

	//methods to load and draw the map
	void Load(int arr[20][25]);
	void Draw();
	
	//map size
	int map[20][25];

private:
	//setting up varibles to use in the map scripts
	SDL_Rect src;
	SDL_Rect pos;
	SDL_Texture* grass;
	SDL_Texture* wall;
	SDL_Texture* wallTop;
	SDL_Texture* chest;
};