#pragma once
struct Vector2D
{
	float X = 0;
	float Y = 0;

	//Constructor por defecto
	Vector2D() {}


	//Constructor
	Vector2D(float x, float y)
	{
		X = x;
		Y = y;
	}
};

struct Game
{
	int W, H;
	bool gameplay = false;
	bool executable = false;
};
