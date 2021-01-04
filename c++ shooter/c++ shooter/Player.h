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
	//made public to be accessed by the health bar
	Sphere* boundingSphere;
	bool hit = false;
	int maxHp;
	int currentHp;
	bool dead = false;
	int speed;
private:
	SDL_Texture* player;
	SDL_Rect src;
	SDL_Rect pos;
	float rotationAngle;


};