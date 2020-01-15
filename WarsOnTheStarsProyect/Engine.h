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

struct Disparo
{
	int posX = player.pos.X + 7;
	int posY = player.pos.Y + 1;
	const float speed = 10.f;
};