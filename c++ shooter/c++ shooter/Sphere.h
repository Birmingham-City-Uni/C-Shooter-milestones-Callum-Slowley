#pragma once
#include <vector>

//Sphere used to check collisons between the players and the enermys;
class Sphere
{
public:
	Sphere(int x, int y, int radius) : x(x), y(y), radius(radius) {};
	bool CollisionWithSphere(Sphere& s)
	{
		int diffX = s.x > x ? s.x - x : x - s.x;
		int diffY = s.y > x ? s.y - y : y - s.y;
		int vectorLength = sqrt(diffX * diffX + diffY * diffY);
		return vectorLength < (radius + s.radius);
		return false;
	}

	int x, y, radius;
};