#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "GameLoop.h"
#include "Score.h"
#include "Sphere.h"

class Player {
public:
	Player();
	~Player();
	void init();
	void update(int map[20][25]);
	void draw();
	void clean();
	float getAngle() const {
		return rotationAngle;
	}
	float getX() {
		return pos.x;
	}
	float getY() {
		return pos.y;
	}

private:
	SDL_Texture* player;
	SDL_Rect src;
	SDL_Rect pos;
	int speed;
	float rotationAngle;
	Sphere* boundingSphere;

};