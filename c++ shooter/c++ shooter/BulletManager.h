#pragma once

//sdl header files
#include <SDL.h>
#include <SDL_image.h>
//vector for managing array of bullets (Similar to arraylist in c#)
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
#include "TextureManager.h"
#include "Player.h"
#include "Sphere.h"

#define PI 3.14159265

using namespace std;

struct Bullet {
	float x, y, rotation, distance;
	Sphere* boundingSphere;
};

class BulletManager {
public:

	void init(SDL_Texture* bullet) {
		//load the texture for the lazer
		bulletTexture = bullet;
	}

	void processInput(bool* keyDown,float playerAngle, float playerx, float playery) {
		if (keyDown[SDL_SCANCODE_SPACE]) {
			if ((SDL_GetTicks() - lastShot) > SHOOT_TIMER_MS) {
				std::cout << "bullet shot"; // used for testing 
				bullets.push_back(Bullet{ playerx,playery,playerAngle, 0.0f });
				lastShot = SDL_GetTicks();
			}
		}
	}

	void update() {
		for (auto& b : bullets) {
			b.x += sin(b.rotation * PI / 180.0f) * BULLET_VELOCITY;
			b.y -= cos(b.rotation * PI / 180.0f) * BULLET_VELOCITY;
			b.distance += BULLET_VELOCITY;
		}
		//remove bullet after they have travelled approx 1000 pixels
		auto remove = std::remove_if(bullets.begin(), bullets.end(), [](const Bullet& b) { return b.distance > 1000; });
		bullets.erase(remove, bullets.end());


	}

	void draw(SDL_Renderer* renderer) {
		SDL_Point center = { 5, 5 };
		for (auto& b : bullets) {
			SDL_Rect dest = { b.x, b.y, 10, 10 };
			SDL_RenderCopyEx(renderer, bulletTexture, 0, &dest, b.rotation, &center, SDL_FLIP_NONE);
		}
	}

	void clean() {
		SDL_DestroyTexture(this->bulletTexture);
	}

	vector<Bullet> bullets;
private:
	SDL_Texture* bulletTexture;


	//time limit between shots
	const int SHOOT_TIMER_MS = 300;
	//numer of pixels travelled per frame
	const int BULLET_VELOCITY = 15;
	unsigned int lastShot = 0;
};