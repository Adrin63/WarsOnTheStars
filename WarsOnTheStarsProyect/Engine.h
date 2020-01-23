#pragma once
#include <iostream>
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
	bool login = true;
	bool difficulty = false;
	bool glossary = false;
	bool howToPlay = false;
};

void BackgroundWords(int initialX, int finalX, int Y);

void InitGame();

void DrawGame();

void Colisions(std::string tag1, std::string tag2);