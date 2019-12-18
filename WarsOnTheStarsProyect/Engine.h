#pragma once

struct Vector2D
{
	int X = 0;
	int Y = 0;

	Vector2D() {}

	Vector2D(float x, float y)
	{
		X = x;
		Y = y;
	}
};

struct Game
{
	int W = 200, H = 50;
	bool gameOver = false;
};