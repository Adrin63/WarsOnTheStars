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
	bool gameplay = true;
	bool executable = true;
	bool login = false;
	bool difficulty = true;
	bool glossary = true;
	bool howToPlay = true;
};

void BackgroundWords(int initialX, int finalX, int Y);

void InitGame();

void DrawGame();